# RMQ Problems from Sphere Online Judge
 
 1. https://www.spoj.com/problems/ADATREE/

* Merge-Sort Tree
* Calculating Floor of sorted array

```cpp
void build(int tl=1,int tr=n,int v=1){
	if(tl==tr) t[v] = vector<int>(1,a[tl]);
	else{
		build(tl,tm,v<<1);
		build(tm+1,tr,v<<1|1);
		merge(all(t[v<<1]),all(t[v<<1|1]),back_inserter(t[v]));
	}
}

int query(int l,int r,int h,int tl=1,int tr=n,int v=1){
	if(tl>r || tr<l) return 0;
	if(tl>=l && tr<=r){
		int idx = lower_bound(all(t[v]),h) - t[v].begin();
		if(t[v][idx]==h) return h;
		else if(idx-1>=0) return t[v][idx-1];
		return 0;	
	}
	else{
		return max(query(l,r,h,tl,tm,v<<1),query(l,r,h,tm+1,tr,v<<1|1));
	}
}
```

2. https://www.spoj.com/problems/SEGSQRSS/

* Classic Lazy Propagation 
* Pitfall: operations order messup 
* Range update & Range set together.  

```cpp
struct node{
	ll x1,x2,upd,lazy;
	node(): x1(0),x2(0),upd(0),lazy(0) {} 
};

node t[4*MaxN];

node combine(node a,node b){
	node tmp;
	tmp.x1 = a.x1+b.x1;
	tmp.x2 = a.x2+b.x2;
	return tmp;
}

void pushdown(int v,int tl,int tr){
	if(t[v].upd){
		ll val = t[v].upd;
		t[v<<1].lazy = 0;
 		t[v<<1|1].lazy = 0;
 		t[v<<1].upd = val; 
 		t[v<<1|1].upd = val;
 		t[v<<1].x1 = (tm-tl+1)*val;
 		t[v<<1|1].x1 = (tr-tm)*val;
 		t[v<<1].x2 = (tm-tl+1)*val*val;
 		t[v<<1|1].x2 =(tr-tm)*val*val;
 		t[v].upd=0;
	}
	if(t[v].lazy){
		ll val = t[v].lazy;
 		t[v<<1].x2 += 2*val*t[v<<1].x1 + (tm-tl+1)*val*val; 
 		t[v<<1|1].x2 += 2*val*t[v<<1|1].x1 + (tr-tm)*val*val; 
 		t[v<<1].x1 += (tm-tl+1)*val;
 		t[v<<1|1].x1 += (tr-tm)*val;
 		t[v<<1].lazy += val;
 		t[v<<1|1].lazy += val;
 		t[v].lazy=0;
	}
}

void build(int tl=1,int tr=n,ll v=1){
	if(tl==tr){
		t[v].x1 = a[tl];
		t[v].x2 = a[tl]*a[tl];
		t[v].upd = 0;
		t[v].lazy = 0;
	}
	else{
		build(tl,tm,v<<1);
		build(tm+1,tr,v<<1|1);
		t[v] = combine(t[v<<1],t[v<<1|1]);
	}
}

void update(int type,int l,int r,ll val,int tl=1,int tr=n,int v=1){
	if(tl>r||tr<l) return;
	else if(tl>=l && tr<=r){
		if(type==0){
			t[v].x1 = val*(tr-tl+1);
			t[v].x2 = val*val*(tr-tl+1);
			t[v].upd = val;
			t[v].lazy = 0;
		}
		else{	
			t[v].x2 += (t[v].x1*2*val) + ((tr-tl+1)*val*val); 
			t[v].x1 += val*(tr-tl+1);
			t[v].lazy += val;
		}
	}
	else{
		pushdown(v,tl,tr);
		update(type,l,r,val,tl,tm,v<<1);
		update(type,l,r,val,tm+1,tr,v<<1|1);
		t[v] = combine(t[v<<1],t[v<<1|1]);
	}
}

ll query(int l,int r,int tl=1,int tr=n,ll v=1){
	if(tl>r||tr<l) return 0;
	else if(tl>=l && tr<=r) return t[v].x2;
	pushdown(v,tl,tr);
	ll L = query(l,r,tl,tm,v<<1);
	ll R = query(l,r,tm+1,tr,v<<1|1);
	return L+R;
}

```
 

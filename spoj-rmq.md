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
3. https://www.spoj.com/problems/FREQUENT/

* Classical Idea: Store pref, suff and ans.
* Pitfall: Handle null return segments.
* Nice idea because array is sorted.

```cpp
struct node{
	int maxfq, pref,suff;
	bool emp;
	node(): emp(1),maxfq(0),pref(0),suff(0) {} 
	node(int e): emp(0),maxfq(1),pref(1),suff(1) {} 
};

int n,q;
int a[MaxN];
node t[4*MaxN];

node combine(node lnode,node rnode,int tl,int tr){
	if(lnode.emp) return rnode;
	else if(rnode.emp) return lnode;
	
	node tmp;
	if(a[tm]==a[tm+1]){
		tmp.maxfq = max( {lnode.suff+rnode.pref,lnode.maxfq,rnode.maxfq });
		tmp.pref = (a[tl]==a[tm]) ? lnode.pref+rnode.pref:lnode.pref;
		tmp.suff = (a[tm+1]==a[tr]) ? lnode.suff+rnode.suff:rnode.suff;
		tmp.emp = 0;
		return tmp;
	}
	
	tmp.maxfq = max( {lnode.maxfq,rnode.maxfq} );
	tmp.pref = lnode.pref;
	tmp.suff = rnode.suff;
	tmp.emp = 0;
	return tmp;			
}

void build(int tl=1,int tr=n,int v=1){
	if(tl==tr) t[v] = node(a[tl]);
	else{
		build(tl,tm,v<<1);
		build(tm+1,tr,v<<1|1);		
		t[v] = combine(t[v<<1],t[v<<1|1],tl,tr);
	}
}

node query(int l,int r,int tl=1,int tr=n,int v=1){
	if(tl>r||tr<l) return node();
	else if(tl>=l && tr<=r) return t[v];
	return combine(query(l,r,tl,tm,v<<1),query(l,r,tm+1,tr,v<<1|1),tl,tr); 
}
```

4. https://www.spoj.com/problems/MKTHNUM/

* Merge Sort Tree
* Two Binary Searches
* Binary Search on the values of array to find the kth value in a[l...r]. 
* If #(elements in a[l..r] < a[x]) is k-1 then check for next elements.
* Hint: If kth order statistics in a[l...r] is a[pos], all values in a[pos+1],a[pos+2], in the sorted array a has the above value > (k-1). Tough to understand intially. 

```cpp

int n,m;
int l,r,k;
int a[MaxN];
vector<int> t[4*MaxN];
 
void build(int tl=1,int tr=n,int v=1){
	if(tl==tr){	
		t[v]=vector<int>(1,a[tl]);
		return;
	}
	build(tl,tm,v<<1);
	build(tm+1,tr,v<<1|1);
	merge(all(t[v<<1]),all(t[v<<1|1]),back_inserter(t[v]));
}

int query(int l,int r,int val,int tl=1,int tr=n,int v=1){
	if(tl>r||tr<l) return 0;
	else if(tl>=l && tr<=r) return lower_bound(all(t[v]),val) - t[v].begin();
	return query(l,r,val,tl,tm,v<<1) + query(l,r,val,tm+1,tr,v<<1|1);
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
 
 	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	build();	
	sort(a+1,a+n+1);
	
	while(m--){
		int l,r,k;
		cin >> l >> r >> k;
		int lo=1,hi=n;
		int pos=-1;
		while(lo<=hi){
			int mi=lo+(hi-lo)/2;
			int q = query(l,r,a[mi]); 
		 	if(q>k-1) hi=mi-1;
		 	else{	
		 		pos=mi;
		 		lo=mi+1;
		 	}
		}
		cout << a[pos] << endl;  
	}
	return 0;
}
```

5. https://www.spoj.com/problems/ANDROUND/

* Simple conversion to segment tree
* Pitfall: calculating [l,r] 

```cpp
void build(int tl=1,int tr=n,int v=1){
	if(tl==tr){
		t[v] = (ll) a[tl]; 
	}
	else{
		build(tl,tm,v<<1);
		build(tm+1,tr,v<<1|1);
		t[v] = t[v<<1] & t[v<<1|1];
	}
}

ll query(int l,int r,int tl=1,int tr=n,int v=1){
	if(tl>r||tr<l) return (1ll<<31)-1ll;
	else if(tl>=l && tr<=r) return t[v];
	else return query(l,r,tl,tm,v<<1) & query(l,r,tm+1,tr,v<<1|1);
}

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> tc;
	while(tc--){
		mem(t,0);
		mem(a,0);
		
		cin >> n >> k;
		for(int i=1;i<=n;i++) cin >> a[i];
		

		build();
		for(int i=1;i<=n;i++){
			 // a[1],a[2]......,a[i-1], (a[i]), a[i+1]......a[N-1],a[N]	
			 ll R = (i+k<=n) ? query(i,i+k) : query(i,n) & query(1,(int) min((ll) n, k-(n-i)));
			 ll L = (k<i) ? query(i-k,i) : query(1,i) & query((int) max((ll)n-(k-i*1ll),1ll),n);
			 cout << (L & R) << " "; 
		}
		cout << endl;
	}

	return 0;
}

```

6. https://www.spoj.com/problems/DQUERY/

* Offline Technique: Sort the queries by r values and count distinct elements using FW trick.
* Sorting can be avoided in a clever way. 
* Pitfall: non-return in a int function, although the function was intended to be of void type.

```cpp
int n;
int a[MaxN];
int sol[200005];
int bit[30005];
int last_pos[1000006];
vector<pii> que[30005];
inline void update(int i,int v){ for(;i<MaxN;i+=i&-i) bit[i]+=v;}
inline int sum(int i,int ans=0){ for(;i>0;i-=i&-i) ans+=bit[i]; return ans; } 
//.............................................................................................

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
 
	int m;
	cin >> m;
	for(int i=0;i<m;i++){
		int l,r;
		cin >> l >> r;
		que[r].eb(l,i);
	}
		
	mem(last_pos,0);
	for(int i=1;i<=n;i++){
		if(last_pos[a[i]]) update(last_pos[a[i]],-1);
		
		last_pos[a[i]]=i;
		update(last_pos[a[i]], 1);
		
		for(auto &[l,id]:que[i]) sol[id] =(l==1) ? sum(i):sum(i)-sum(l-1);
 	}
 	
 	for(int id=0;id<m;id++) cout << sol[id] << endl;
	
	return 0;
}
```
7. https://www.spoj.com/problems/MATSUM/
![image](https://user-images.githubusercontent.com/21307343/137428207-20ab8f79-6790-4922-9676-3d72894d7ce1.png)

* Pitfall: Add only the update.
* Easy implementation of 2-D FW tree.

```cpp
int tc,n;
int a[MaxN][MaxN], bit[MaxN][MaxN];

inline void update(int x,int y,int v){
	for(int i=x;i<MaxN;i+=i&-i) 
		for(int j=y;j<MaxN;j+=j&-j)
			bit[i][j]+=v;
}

inline int sum(int x,int y,int ans=0){
	for(int i=x;i>0;i-=i&-i)
		for(int j=y;j>0;j-=j&-j)
			ans+=bit[i][j];
	return ans; 
}

inline int query(int x1,int y1,int x2,int y2){
	int a = sum(x2,y2);
	int b = (x1==1) ? 0: sum(x1-1,y2);
	int c = (y1==1) ? 0: sum(x2,y1-1);
	int d = (x1==1 || y1==1) ? 0: sum(x1-1,y1-1);
	return (int) a-b-c+d;
}
```
8. https://www.spoj.com/problems/GSS5/

![image](https://user-images.githubusercontent.com/21307343/137613594-07072c9d-6b46-4fd2-a562-312aafcaf14d.png)


```cpp
struct node{
	 int sum,pref,suff,bestsum;
	 node(): pref(-inf),suff(-inf),sum(0),bestsum(-inf) {} 
	 node(int v): pref(v),suff(v),sum(v),bestsum(v) {}
};

int a[10005],b[10005];
node t[4*10005];

node combine(node l,node r){
	node tmp;
	tmp.sum  = l.sum + r.sum;
	tmp.pref = max(l.pref,l.sum+r.pref);
	tmp.suff = max(r.suff,l.suff+r.sum);
	tmp.bestsum =  max({l.bestsum,r.bestsum,l.suff+r.pref});
	return tmp;
}

void build(int tl=1,int tr=n,int v=1){
	if(tl==tr) t[v] = node(a[tl]);
	else{
		build(tl,tm,v<<1);
		build(tm+1,tr,v<<1|1);
		t[v] = combine(t[v<<1],t[v<<1|1]);
	}
}

node query(int l,int r,int tl=1,int tr=n,int v=1){
	if(tl>r||tr<l||l>r) return node();
	else if(tl>=l && tr<=r) return t[v];
	return combine(query(l,r,tl,tm,v<<1),query(l,r,tm+1,tr,v<<1|1));
}
//.............................................................................................

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> tc;
	while(tc--){
		mem(a,0);
		mem(b,0);
		mem(t,0);
		cin >> n;
		for(int i=1;i<=n;i++) {
			cin >> a[i];
			b[i]=b[i-1]+a[i];
		}
		build();
	
	cin >> m;
	for(int i=0;i<m;i++){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		int ans=-inf;
		
		if(x2>y1) ans=max(ans,query(x1,y1).suff+query(y1+1,x2-1).sum+query(x2,y2).pref);
		else{
			ans=max(ans,query(x1,x2).suff+query(x2,y2).pref-a[x2]);
			ans=max(ans,query(x2,y1).bestsum);
			ans=max(ans,query(x2,y1).suff+query(y1,y2).pref-a[y1]);
		}
		cout << ans << endl; 
		}
	}
	
	return 0;
}
```

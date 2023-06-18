# Query Algorithms
* Binary Lifting
* Fenwick Tree
* Segment Tree
* Sqrt Decomposition
* Sparse Table

## Binary Lifting
![image](https://user-images.githubusercontent.com/21307343/132557959-e5de0719-db61-405b-9ba2-498f5cd67111.png)

```cpp
    int up[MaxN][LOG+1]; // up[i][j] : 2^j th ancestor of i, root vertex : 0
    void lift(int u){           
          for(auto &v:g[u]){
              up[v][0] = u;
              d[v] = d[u]+1;
              for(int j=1;j<LOG;j++) up[v][j] = up[up[v][j-1]][j-1];
              lift(v);
          }
    }
```

* Finding LCA of two vertex in a binary tree

```cpp
    int lca(int u,int v){
        if(u==v) return u;
        if(d[u]<d[v]) swap(u,v); // d[u] > d[v]
        int k = d[u]-d[v];
        for(int j=0;j<LOG;j++) if(k&(1<<j)) u = up[u][j];
        if(u==v) return u;
        for(int j=LOG;j>=0;j--){
            if(up[u][j]!=up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
```
## Fenwick Tree

* https://cp-algorithms.com/data_structures/fenwick.html </br>
* [Intuition behind update](https://www.youtube.com/watch?v=Ti_U3Q_G7yM&t=2404s) </br>


<li> 1-D BIT tree
    
```cpp
    int query(int i){
        int ans=0;
        for(;i>=0;r=i&(i+1)-1) ans+= bit[i];
        return ans;
    }
    int sum(int l,int r){
        return query(r) - query(l-1);
    }
    int update(int i,int x){
        for(;i<n;i=i|(i+1)) bit[i] += x;
    }
```

1-Based Indexing 
		 
```cpp
	int query(int i){
		int ans = 0;
		for (;i>0;i-=i&-i) ans += fen[i];
		return ans;
	}
	void update(int i,int val){
		for(;i<MAXN;i+=i&-i) fen[i] += val;
	}
			       
	void clean(int i){ // This step is important for multiple test case. You clean only things you touched avoiding TLE
		for(;i<MAXN;i+=i&-i) fen[i]=0;
	}    
```
		   
![image](https://user-images.githubusercontent.com/21307343/132801474-bb611c3d-4daf-478c-8693-95b011a93beb.png)

<li> 2-D BIT tree
    
```cpp
    int query(int x,int y){
        int ans = 0;
        for(int i=x;i>=0;i=i&(i+1)-1)
            for(int j=y;j>=0;j=j&(j+1)-1) ans+=bit[i][j];
        return ans;
    }
    int update(int x,int y,int d){
        for(int i=x;i<n;i=i|(i+1))
            for(int j=y;j<m;j=j|(j+1)) bit[i][j]+=d;
    }
```
* Range update
* Range queries
* Point update
* Point queries
    
<a href="https://www.codecogs.com/eqnedit.php?latex=\\Define\:\:f[0...j]\:\:as\:follows:\\&space;if&space;\:\:j<l:&space;f[0...j]=0\\&space;if&space;\:\:l&space;\leq&space;j&space;\leq&space;r:&space;f[0...j]=x*(j-l&plus;1)=x*j-x*(l-1)\\&space;if&space;\:\:j&space;\geq&space;r:&space;f[0...j]=x*(r-l&plus;1)=0*j-[x*(l-1)-x*r]\\" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\Define\:\:f[0...j]\:\:as\:follows:\\&space;if&space;\:\:j<l:&space;f[0...j]=0\\&space;if&space;\:\:l&space;\leq&space;j&space;\leq&space;r:&space;f[0...j]=x*(j-l&plus;1)=x*j-x*(l-1)\\&space;if&space;\:\:j&space;\geq&space;r:&space;f[0...j]=x*(r-l&plus;1)=0*j-[x*(l-1)-x*r]\\" title="\\Define\:\:f[0...j]\:\:as\:follows:\\ if \:\:j<l: f[0...j]=0\\ if \:\:l \leq j \leq r: f[0...j]=x*(j-l+1)=x*j-x*(l-1)\\ if \:\:j \geq r: f[0...j]=x*(r-l+1)=0*j-[x*(l-1)-x*r]\\" /></a>

</br>
* Trick: Idea from difference array

```cpp
    int point_update(vi b,int i,int x){ 
        for(;i<n;i=i|(i+1)) b[i]+=x; 
    }
    int range_update(int l,int r,int x){
        point_update(b1,l,x);
        point_update(b1,r+1,-x);
        point_update(b2,l,x*(l-1));
        point_update(b2,r+1,-x*r);
    }
    
    int sum(vi b,int i){
        int ans = 0;
        for(;i>=0;i=i&(i+1)-1)
            ans += b[i];
        return ans;
    }
    
    int prefix_sum(int i){
        return sum(b1,i)*i-sum(b2,i);
    }
    
    int range_sum(int l,int r){
        return prefix_sum(r) - prefix_sum(l-1);
    }
```
## Sparse Table

```cpp
    int m[MaxN][LOG]; // m[i][j] : A[i.....i+2^j-1]
    
    void init(){
        mem(m,0);
        logv[1] = 0;
        for(int i=2;i<=n;i++) logv[i] = logv[i/2] + 1;
    }
    
    void build(){
        for(int i=0;i<n;i++) m[i][0] = a[i];
        for(int j=1;j<=logv[n];j++){
            for(int i=0;i+(1<<j)-1<n;i++){
                m[i][j] = min(m[i][j-1],m[i+(1<<(j-1))][j-1]);
            }
        }
    }
    
    int query(int l,int r){
        int j = logv[r-l+1];
        return min(m[l][j],m[r-(1<<j)+1][j]);
    }
    
    void sum(int l,int r){
        for(int i=LOG;i>=0;i--){
            if(1<<i <= r-l+1){
                sum += m[l][i];
                l+=1<<i;
            }
        }
    }
```
## Segment Trees

* a[l...r] : evaluate some function, modify some values, etc
* https://cp-algorithms.com/data_structures/segment_tree.html

![image](https://user-images.githubusercontent.com/21307343/132835234-89902931-0776-4d79-aec6-6b86c3bafd7d.png)

* Standard problem: https://codeforces.com/contest/1567/problem/E

```cpp
struct node{  
	ll v,p,s,l,r,w; 
	node(): v(0),p(0),s(0),l(-1),r(-1),w(0) {}
	node(ll x) : v(1),p(1),s(1),l(x),r(x),w(1) {}
	node(const node &T): v(T.v),p(T.p),s(T.s),l(T.l),r(T.r),w(T.w) {}
};

node t[MaxN*4];

node combine(node lc,node rc){
	if(!lc.w) return node(rc);
	if(!rc.w) return node(lc);
	node res;
	res.w = lc.w+rc.w;
	res.l = lc.l; 
	res.r = rc.r;
	res.v = lc.v + rc.v + ((rc.l >= lc.r)? lc.s*rc.p: 0);
	res.p = (lc.p==lc.w && rc.l >= lc.r)? lc.w+rc.p:lc.p; 
	res.s = (rc.s==rc.w && lc.r <= rc.l)? lc.s+rc.w:rc.s;
	return res;
}

void update(int pos,int x,int v=1,int tl=1,int tr=n){
	if(tl==tr) t[v] = node(x);
	else{	
		int tm = tl+(tr-tl)/2;
		if(pos<=tm) update(pos,x,v<<1,tl,tm);
		else update(pos,x,v<<1|1,tm+1,tr);
		t[v] = combine(t[v<<1],t[v<<1|1]);
	}
}

void build(int v=1,int tl=1,int tr=n){
	if(tl==tr) t[v] = node(a[tl]);
	else{	
		int tm = tl+(tr-tl)/2;
		build(v<<1,tl,tm);
		build(v<<1|1,tm+1,tr);
		t[v] = combine(t[v<<1],t[v<<1|1]);
	}
}

node query(int l,int r,int v=1,int tl=1,int tr=n){
	if(r<tl||tr<l) return node();
	if(l<=tl&&tr<=r) return t[v];
	int tm = tl+(tr-tl)/2;
	return combine(query(l,r,v<<1,tl,tm),query(l,r,v<<1|1,tm+1,tr));
} 

```
### Merge Sort Tree

* In range [l,r], find the smallest number greater than eq to specified number

```cpp
    vi t[4*MaxN];
    void build(int v,int tl,int tr){
        if(tl==tr) t[v] = vi(1,a[tl]);
        else{
            int tm = tl + (tr-tl)/2;
            build(1<<v,tl,tm);
            build((1<<v)+1,tm+1,tr);
            merge(all(t[1<<v]), all((1<<v)+1),back_inserter(t[v]));
        }
    }
    
    int query(int v,int tl,int tr,int l,int r,int x){
         if(l>r) return inf;
         if(l==tl && r==tr){
            auto i = lower_bound(all(t[v]),x);
            if(i!=t[v].end()) return (*i);
            return inf;
         }
         int tm = tl + (tr-tl)/2;
         return min(query(1<<v,tl,tm,l,min(r,tm),x)
                    query((1<<v)+1,tm+1,tr,max(tm+1,l),r,x));
    }
```

#### Lazy Propagation

* [Paval Mavrin lecture](https://www.youtube.com/watch?v=7JmBP-RqzlI&t=2727s)
![image](https://user-images.githubusercontent.com/21307343/132859886-91aa8c4c-6a90-4d52-883b-abce9810c12d.png)

* Set(i,v), Sum(l,r): function has to associative
* How to support range_update(l,r) & get(i)
* range_update(l,r): worst case takes linear
* Use lazy propagation
* <a href="https://www.codecogs.com/eqnedit.php?latex=\\a[i]\:*=&space;v&space;\:\:for\:i\in[l,r]&space;\\&space;*:&space;associative&space;\\&space;(a[i]*x)*y&space;=&space;a[i]*(x*y)&space;\\&space;*:&space;commutative&space;\\&space;a[i]*x*y&space;=&space;a[i]*y*x&space;\\&space;Lazy\:propagation\:is\:needed\:for\:non-commutative\:operator&space;\\&space;Order\:operation\:has\:to\:be\:sorted\:from\:leaf\:to\:root&space;\\" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\a[i]\:*=&space;v&space;\:\:for\:i\in[l,r]&space;\\&space;*:&space;associative&space;\\&space;(a[i]*x)*y&space;=&space;a[i]*(x*y)&space;\\&space;*:&space;commutative&space;\\&space;a[i]*x*y&space;=&space;a[i]*y*x&space;\\&space;Lazy\:propagation\:is\:needed\:for\:non-commutative\:operator&space;\\&space;Order\:operation\:has\:to\:be\:sorted\:from\:leaf\:to\:root&space;\\" title="\\a[i]\:*= v \:\:for\:i\in[l,r] \\ *: associative \\ (a[i]*x)*y = a[i]*(x*y) \\ *: commutative \\ a[i]*x*y = a[i]*y*x \\ Lazy\:propagation\:is\:needed\:for\:non-commutative\:operator \\ Order\:operation\:has\:to\:be\:sorted\:from\:leaf\:to\:root \\" /></a>

```cpp
    void push(int v){
        t[1<<v] *= lazy[v];
        lazy[1<<v] *= lazy[v];
        t[(1<<v)+1] *= lazy[v];
        lazy[(1<<v)+1] *= lazy[v];
        lazy[v] = 0;
    }
    void range_update(int v,int tl,int tr,int l,int r,int x){
           if(l>r) return;
           if(l==tl && tr==r){
                t[v] *= x;
                lazy[v] *= x;
           }
           else{
                push(v);
                int tm = tl+(tr-tl)/2;
                range_update(1<<v,tl,tm,l,min(r,tm),x);
                range_update((1<<v)+1,tm+1,tr,max(l,tm+1),r,x);
                t[v] = max(t[1<<v],t[(1<<v)+1]);
           }
    }
    int query(int v,int tl,int tr,int l,int r){
           if(l>r) return -inf;
           if(l<=tl && tr<=r) return t[v];
           push(v);
           int tm = tl+(tr-tl)/2;
           return max(query(1<<v,tl,tm,l,min(r,tm)),
                      query((1<<v)+1,tm+1,tr,max(l,tm+1),r));
    }
```

### 2-D Segment Tree

```cpp
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m-1);
}

int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
         + sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y(vx, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
         + sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = new_val;
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx*2, lx, mx, x, y, new_val);
        else
            update_x(vx*2+1, mx+1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
}

```

### Get the nearest element from a given element in a range 

```cpp
int get_first(int v, int lv, int rv, int l, int r, int x) {
    if(lv > r || rv < l) return -1;
    if(l <= lv && rv <= r) {
        if(t[v] <= x) return -1;
        while(lv != rv) {
            int mid = lv + (rv-lv)/2;
            if(t[2*v] > x) {
                v = 2*v;
                rv = mid;
            }else {
                v = 2*v+1;
                lv = mid+1;
            }
        }
        return lv;
    }

    int mid = lv + (rv-lv)/2;
    int rs = get_first(2*v, lv, mid, l, r, x);
    if(rs != -1) return rs;
    return get_first(2*v+1, mid+1, rv, l ,r, x);
```

## Sqrt Decomposition

```cpp
int a[MaxN], b[SqrtN];

void init(){
    blk_sz = sqrt(n);
    mem(a,0);
    mem(b,0);
}

void build(){
    int j=-1;
    for(int i=0;i<n;i++){
        if(i%blk_sz==0) j++;
        b[j]+=a[i];
    }
}

int query(int l,int r){
    int ans = 0;
    while(l<r && l%blk_sz) ans+=a[l++];
    while(l+blk_sz<=r){
        ans+=b[l/blk_sz];
        l+=blk_sz;
    }
    while(l<=r) ans+=a[l++];
    return ans;
}

void update(int i,int x){
    int j = i/blk_sz;
    b[j]+=x-a[i];
    a[i]=x;
}

```


# Problems: 

<li> Count Inversions
    
```cpp
    int MaxN = *max_element(all(a));
    int bit[MaxN];
    mem(bit,0);
    
    for(int i=n-1;i>=0;i--){
        ans += range_query(bit,a[i]-1);
        point_update(bit,arr[i],1);
    }
```

<li> Classic Problem on Lazy Propagation: 446C - DZY Loves Fibonacci Numbers, https://codeforces.com/contest/446/problem/C
	
```cpp
int n,m;
ll fib[MaxN], a[MaxN], t[4*MaxN];
ll lazy[4*MaxN][2];  

void build(int v=1,int tl=1,int tr=n){
	if(tl==tr) t[v] = a[tl];
	else{
		build(v<<1,tl,tm);
		build(v<<1|1,tm+1,tr);
		t[v] = add(t[v<<1],t[v<<1|1]);
	}
}

inline int calc(int n,int c1,int c2){ return add(mul(fib[n-2],c1),mul(fib[n-1],c2)); }

void merge(int v,int tl,int tr,int c1,int c2){
	int nx = tr-tl+1;
	lazy[v][0] = add(lazy[v][0],c1);
	lazy[v][1] = add(lazy[v][1],c2);
	int z =  sub( calc(nx+2,c1,c2), c2 ); 
	t[v] = add(t[v],z);
}

void push(int v,int tl,int tr){
	merge(v<<1,tl,tm,lazy[v][0],lazy[v][1]);
	merge(v<<1|1,tm+1,tr,calc(tm+2-tl,lazy[v][0],lazy[v][1]),calc(tm+3-tl,lazy[v][0],lazy[v][1]));
	lazy[v][0] = lazy[v][1] = 0; 
}

void update(int l,int r,int v=1,int tl=1,int tr=n){
	if(l>tr||r<tl) return;
	if(l<=tl&&tr<=r) merge(v,tl,tr,fib[tl-l+1],fib[tl-l+2]);
	else{
		push(v,tl,tr);
		update(l,r,v<<1,tl,tm);
		update(l,r,v<<1|1,tm+1,tr);
		t[v] = add(t[v<<1],t[v<<1|1]);
	}
}

int query(int l,int r,int v=1,int tl=1,int tr=n){
	if(l>tr||r<tl) return 0;
	if(l<=tl&&tr<=r) return t[v];
	push(v,tl,tr);
	return add(query(l,r,v<<1,tl,tm),query(l,r,v<<1|1,tm+1,tr));
}
```

* Fenwick Tree + Sorting    https://atcoder.jp/contests/abc186/tasks/abc186_f
								    
```cpp
int bit[MaxN];
int H,W,M;
int by_row[MaxN], by_col[MaxN];
ll ans=0;

struct{
	int x,y;
} p[MaxN];

int query(int i){
	int ans=0;
	for(;i>0;i-=i&-i) ans+=bit[i];
	return ans;
}
void update(int i,int x){
	for(;i<MaxN;i+=i&-i) bit[i]+=x;
}

//.............................................................................................

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> H >> W >> M;
	for(int i=0;i<M;i++) cin >> p[i].x >> p[i].y;
	
	for(int i=1;i<MaxN;i++) by_row[i] = W+1, by_col[i] = H+1;
	
	for(auto &[x,y]: p){
		chmin(by_row[x],y);  chmin(by_col[y],x);
	}
	
	vector<pii> a;
	
	for(int i=1;i<by_col[1];i++) { 
		ans+=by_row[i]-1;	
	}
	
	for(int i=1;i<by_row[1];i++) { 
		ans+=by_col[i]-1;
		a.eb(mp(by_col[i]-1,i));	
	}
	
	sort(all(a));
	
	int i=1;
	for(auto &[hlim,c]: a){
		while(i<=hlim && i<by_col[1]) update(by_row[i++],1);
		ans-=query(W+1)-query(c-1);
	}
	cout << ans << endl;
	
	return 0;
}								    
```
								    
Sorting + Fenwick Tree + Order Statistics https://codeforces.com/contest/459/problem/D
	
```cpp
	int bit[MaxN];
 
int query(int i){
	int ans=0;
	for(;i>0;i-=i&-i) ans+=bit[i]; 
	return ans;
}
 
void update(int i,int x){
	for(;i<MaxN;i+=i&-i) bit[i]+=x;
}
 
//.............................................................................................
int n;
int a[MaxN],cnt[MaxN],L[MaxN],R[MaxN];
vector<pii> v;
ll ans = 0;
 
//.............................................................................................
 
int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i=0;i<n;i++) { 
		cin >> a[i];
		v.eb({a[i],i});	
	}
	sort(all(v));
	
	int g=1;
	a[v[0].se] = g;
	for(int i=1;i<n;i++){
		if(v[i].fi==v[i-1].fi) a[v[i].se] = g;
		else a[v[i].se] = ++g;
	}
	
	for(int i=0;i<n;i++) L[i] = ++cnt[a[i]]; 
	mem(cnt,0);
	
	for(int i=n-1;i>=0;i--){
		ans += query(L[i]-1);
		R[i] = ++cnt[a[i]];
		update(R[i],1);
	}	
	
	cout << ans << endl;
	
	return 0;
}
```

	
* Sereja & Brackets https://codeforces.com/problemset/problem/380/C

`Idea: Consider a optimal bracket subsequence. If we remove any balanced substring from it, optimality remains intact. Argue with { = +, } = -1`

* Coordinate Compression on Ranges + Lazy Seg Tree  spoj.com/problems/POSTERS/
	
```cpp
	int tc,n,g=1;
vector<pair<int,pair<int,bool>>> cv; // value, idx, l/r
vector<pii> q;
int t[4*MaxN],lazy[4*MaxN];
 
void propagate(int v){	
	if(lazy[v]){
		t[v<<1] = lazy[v<<1] = t[v<<1|1] = lazy[v<<1|1] = lazy[v];
	}
	lazy[v]=0;
}
 
void update(int l,int r,int color,int tl=1,int tr=n,int v=1){
	if(tl>r||tr<l) return;
	if(tl>=l&&tr<=r) t[v]=lazy[v]=color;
	else{	
		propagate(v);
		update(l,r,color,tl,tm,v<<1);
		update(l,r,color,tm+1,tr,v<<1|1);
	}
}
 
int query(int pos,int tl=1,int tr=n,int v=1){
	if(tl==tr) return t[v];
	else{
		propagate(v);
		if(pos<=tm) return query(pos,tl,tm,v<<1);
		else return query(pos,tm+1,tr,v<<1|1);
	} 
}	
 
//.............................................................................................
 
int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> tc;
	while(tc--){
		
		cin >> n;
		mem(t,0); mem(lazy,0); 
		cv.clear();
		q.clear();
		g=1;
		
		for(int i=0;i<n;i++){
			int l,r;
			cin >> l >> r;
			q.eb({l,r});
			cv.eb(mp(l,mp(i,0))); 
			cv.eb(mp(r,mp(i,1)));			
		}
		sort(all(cv));
		if(cv[0].se.se==0) q[cv[0].se.fi].fi = g;  
		
		// coordinate compression
		for(int i=1;i<sz(cv);i++){
			if(cv[i].fi==cv[i-1].fi){
				if(cv[i].se.se==0) q[cv[i].se.fi].fi = g;
				else q[cv[i].se.fi].se = g;
			}
			else{
				if(cv[i].se.se==0) q[cv[i].se.fi].fi = ++g;
				else q[cv[i].se.fi].se = ++g;
			}
		}
		
		n=g;
		
		int cnt=0;
		for(auto [l,r]: q) update(l,r,++cnt);
		
		set<int> ans;
		for(int i=1;i<MaxN;i++){
			int color = query(i);
			if(color) ans.insert(color);
		}  
		
		cout << sz(ans) << endl;
				
	}
	
	return 0;
}
```

### Classical Fenwick Application like a Dynamic Programming
		
`Find the number of monotonically increasing subsequences with k elements in them.`
```cpp
inline void update(int i,int k,ll delta){
	for(;i<100005;i+=i&-i){
		bit[i][k]+=(ll) delta;
	}
}

inline ll query(int i,int k){
	ll ans=0;
	for(;i>0;i-=i&-i){
		ans+=(ll) bit[i][k];
	}
	return ans;
}
//.............................................................................................

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> K;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<=n;i++){
		int ele = a[i];
		for(int k=1;k<=K+1;k++){
			if(k==1) update(ele,1,1); 
			else update(ele,k,query(ele-1,k-1));
		}
	}
	
	cout << query(100003,K+1) << endl;
	
	return 0;
}
```
	
### Classical Seg Tree + Bit manipulation + Lazy Propagation https://codeforces.com/contest/242/problem/E
	
<li> Major Pitfalls: Do not forget to pushdown in the query function for lazy propagation code 
	
```cpp
void build(int bit,int tl=1,int tr=n,int v=1){
	if(tl==tr) { 
		 t[v][bit] = (a[tl] & (1<<bit)) ? 1 : 0;
		}
	else{
		build(bit,tl,tm,v<<1);
		build(bit,tm+1,tr,v<<1|1);
		t[v][bit] = t[v<<1][bit] + t[v<<1|1][bit]; 
	}
}

void pushdown(int v,int bit,int tl,int m,int tr){
	if(lazy[v][bit]){
		t[v<<1][bit] = (m-tl+1)-t[v<<1][bit];
		t[v<<1|1][bit] = (tr-m)-t[v<<1|1][bit];
		lazy[v<<1][bit] ^=1;
		lazy[v<<1|1][bit] ^=1;
		lazy[v][bit] = 0;		 
	}
}

void update(int bit,int l,int r,int tl=1,int tr=n,int v=1){
	if(tl>r || tr<l) return;
	if(tl>=l && tr<=r){
		t[v][bit] = (tr-tl+1)-t[v][bit];
		lazy[v][bit] ^= 1; 
		return;
	}
	pushdown(v,bit,tl,tm,tr);
	update(bit,l,r,tl,tm,v<<1);
	update(bit,l,r,tm+1,tr,v<<1|1);	
	t[v][bit] = t[v<<1][bit] + t[v<<1|1][bit];
}

int query(int bit,int l,int r,int tl=1,int tr=n,int v=1){
	if(tl>r || tr<l) return 0;
	if(tl>=l&&tr<=r) return t[v][bit];
	pushdown(v,bit,tl,tm,tr);
	return query(bit,l,r,tl,tm,v<<1) + query(bit,l,r,tm+1,tr,v<<1|1);
}
```

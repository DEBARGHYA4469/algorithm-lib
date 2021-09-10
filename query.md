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
                m[i][j] = min(m[i][j-1],m[i+(1<<(j-1))][j-1])
            }
        }
    }
    
    void query(int l,int r){
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

```cpp
    // find max sum subsegment inside a segment
    struct node{
        int sum,pref,suff,ans;
    };
    
    node combine(data l,data r){
        node res;
        res.sum = l.sum+r.sum;
        res.pref = max(l.pref,l.sum+r.pref);
        res.suff = max(r.suff,r.sum+l.suff);
        res.ans =  max({l.ans,r.ans,l.suff+r.pref});
        return res;
    }
    
    node create_node(int val){
        node res;
        res.sum = val;
        res.pref = res.suff = res.ans = max(0,val);
        return res;
    }
    
    void build(int v,int tl,int tr){
        if(tl==tr) t[v] = create_node(a[tl]);
        else{
            int tm = tl + (tr-tl)/2;
            build(1<<v,tl,tm);
            build((1<<v)+1,tm+1,tr);
            t[v] = combine(t[1<<v],t[(1<<v)+1]);
        }
    }
    
    void point_update(int v,int tl,int tr,int i,int x){
        if(tl==tr) t[v] = create_node(x);
        else{
            int tm = tl + (tr-tl)/2;
            if(i<=tm) point_update(1<<v,tl,tm,i,x);
            else point_update((1<<v)+1,tm+1,tr,i,x);
            t[v] = combine(t[1<<v],t[(1<<v)+1]);
        }
    }
    
    node query(int v,int tl,int tr,int l,int r){
        if(l>r) return create_node(0);
        if(l==tl && tr==r) return t[v];
        int tm = tl+(tr-tl)/2;
        return combine(query(1<<v,tl,tm,l,min(r,tm)),
                       query((1<<v)+1,tm+1,tr,max(l,tm+1),r));
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

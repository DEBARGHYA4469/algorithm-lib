# Query Algorithms
* Binary Lifting
* Fenwick Tree
* Segment Tree
* Sqrt Decomposition
* Sparse Table
* MOs algorithm 

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

![Drawing-99 sketchpad](https://user-images.githubusercontent.com/21307343/132831259-5e4f62ee-2a06-49c5-96fc-9e4c5c44976c.png)

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



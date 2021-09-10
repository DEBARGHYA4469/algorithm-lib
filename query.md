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

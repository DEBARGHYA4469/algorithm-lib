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

# Graphs

### Cyclicity in a undirected graph

```cpp
    
    void dfs(int u,int p=-1){
        vis[u] = 1;
        for(auto v:g[u]){
          if(v==p) continue;
          else if(vis[v]){
              cycle_end = u;
              cycle_start = v;
              return 1;
          }
          par[v]=u;
          if(dfs(v,p[v])) return 1;
        }
        return 0;
    }
  
    vi find_cycle(){
        vis.assign(n,0);
        par.assign(n,-1);
        cycle_start = -1;
        
        for(int v=0;v<n;v++)
          if(!vis[v] && dfs(v)) break;
        
        if(cycle_start==-1) cout << "Acyclic" << endl;
        else{
            vi cycle;
            cycle.eb(cycle_start);
            for(int v=cycle_end;v!=cycle_start;v=p[v]) cycle.eb(v);
            cycle.eb(cycle_start);
            reverse(all(cycle));
            return cycle;
        }
    }
```

### Cyclicity in Directed Graphs

```cpp
      vi color,par;
      
      bool dfs(int u){
          color[u] = 1;  // GRAY
          for(auto v:g[u]){
              if(color[v]==0){ // WHITE
                  p[v] = u;
                  if(dfs(u)) return 1;
              }
              else if(color[u]==1){
                  cycle_end = u;
                  cycle_start = v;
                  return 1;
              }
          }
          color[u] = 2; // BLACK
          return 0;
      }
```

### DSU: Union Find

```cpp
    int par[1000], rank[1000];
    
    int root(int u){
            if(par[u]==u) return u;
            return par[u] = root(par[u]);
    }
    
    void Union(int u,int v){
      int r1 = root(u), r2 = root(v);
      if(rank[r1]>rank[r2]) par[r2] = r1;
      else if(rank[r1]<rank[r2]) par[r1] = r2;
      else par[r2] = r1, rank[r1]++;
    }
    
```

`Trick 1: If edge deletion, reverse the operations and use union-find` </br> </br>
`Trick 2: If a vertex is connected to other vertex by two independent type of edges, what is the number of vertex which are connected 
to it by road and not by rails, say, mp1[root_roads[u]]-mp2[root_roads[u],root_rails[u]]` </br> </br>

## Articulation Point
![image](https://user-images.githubusercontent.com/21307343/132128610-75200a76-b2b6-44d2-a36e-c25588c1f964.png)

```cpp
      void dfs(int u,int p=-1){
            int branch = 0;
            low[u] = disc[u] = ++timer;
            for(auto v:g[u]){
                if(v==p) continue;
                else if(disc[v]) low[u] = min(low[u],disc[v]);
                else{
                    branch++;
                    dfs(v,u);
                    if(low[v]>=disc[u]) ap[u] = 1;
                    low[u] = min(low[u],low[v]);
                }
            }
            if(p==-1 && branch>1) ap[u] = 1;
      }
```

## Bridges

```cpp
    void dfs(int u,int p=-1){
          low[u] = disc[u] = ++timer;
          for(auto v:g[u]){
              if(v==p) continue;
              else if(disc[v]) low[u] = min(low[u],disc[v]);
              else{
                  dfs(v,u);
                  if(low[v]>disc[u]) bridges.eb(mp(u,v));
                  low[u] = min(low[u],low[v]);
              }
          }
    }
```

## Transitive Closure

`For undirected graph, use DSU` </br>
`For directed graph, use Floyd Warshall/DFS` </br>

## BFS on a complement graph if the graph is sparse

```cpp
      vi d(n+1,-1);
      queue<int> q;
      set<int> undisc;
      
      q.push(s);
      d[s]=0;
      for(int i=0;i<=n;i++) if(i!=s) undisc.insert(i);
      
      while(!q.empty()){
          int u = q.front();
          q.pop();
          set<int> temp;
          for(auto &v:undisc){
              if(g[u].find(v)==g[u].end()){
                  d[v] = d[u] + 1;
                  q.push(v);
              }
              else temp.insert(v);
          }
          undisc = temp;
      }
```

## Topological Sort

DFS method 

```cpp
    stack<int> s;
    void dfs(int u){
        vis[u] = 1;
        for(auto &v:g[u]){
            if(!vis[v]) dfs(v);
        }
        s.push(u);
    }
```

# Graphs

### Table of contents

[Cyclicity in undirected graph](#a)

[Cyclicity in directed graph, coloring technique](#b)

[All simple cycles in a undirected graph, w/o composite cycles](#c)

[All tricks using union-find algorithm](#d)

[Tarjan's algorithm to find articulation points, bridges](#e)

[Finding transitive closure of a graph using Floyd Warshall](#g)

[BFS on complement graph if the graph is sparse](#h)

[All topological ordering](#i)

[Kahn's algorithm for topological ordering](#j)

[Maximal/Minimal Topological ordering](#k)

[Floyd Warshall for finding shortest paths](#l)

[Minimum Spanning Tree, Prim vs Kruskal](#m)

[Dijkstra's shortest path algoritm for non-negative edges](#o)

[Use Bellman Ford for negative edge weights](#p)

[Detect negative cycle using Bellman Ford](#q)

[Find shortest cycle using BFS and edge deletion](#q1)

[0/1 BFS Trick](#r)

[Strongly connected component aka SCC](#s)

[Kosaraju's algorithm for condensed SCC](#t)

### Cyclicity in a undirected graph

<a name="a"/>

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

<a name="b"/>

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

### All simple cycles in a undirected graph

<a name="c"/>

<img width="615" alt="image" src="https://user-images.githubusercontent.com/21307343/185361935-5d501484-7283-462b-9642-b64a17a34389.png">

Think in terms of DFS Tree! This algorithm does not work for composite cycles.

```cpp
int parent[N], who[N], color[N];
int cycle = 0;

void dfs(int u,int p=-1){
    if(color[u]==2) return;
    if(color[u]==1){
        cycle++;
        int curr = p;
        who[cur] = cycle;
        while(curr!=u){
            cur = parent[cur];
            who[cur] = cycle;
        }
        return;
    }
    parent[u] = p; 
    color[u] = 1;
    
    for(int v:g[u]){
        if(v==p) continue;
        dfs(v,u);
    }
    color[u] = 2;
}
```

### DSU: Union Find

<a name="d"/>

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

## Tarjan's Articulation Point

<a name="e"/>

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

## Tarjan's Bridges Algorithm

<a name="f"/>

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

<a name="g"/>

`For undirected graph, use DSU` </br>
`For directed graph, use Floyd Warshall/DFS` </br>

## BFS on a complement graph if the graph is sparse

<a name="h"/>

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

<a name="i"/>

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
    
    
    void all_topo(int mask){
         bool flag = true;
         for(int u=0;u<V;u++){
                if(!in[u] && !(mask&(1<<u))){
                    for(auto v:g[u]) in[v]--;
                    
                    res.eb(u);
                    mask^= 1<<u;
                    alltopo(mask);
                    
                    mask^= 1<<u;
                    res.erase(res.end()-1);
                    for(auto v:g[u]) in[v]++;
                    flag = false;
                }
         }
         if(flag)
         for(int i=0;i<sz(res);i++) cout << res[i] << " ";
         cout << endl;
    }
```

#### Kahn's Algorithm

<a name="j"/>

```cpp
    void topo_sort(){
        vi in(V,0);
        for(int u=0;u<V;u++){
            for(auto v:g[u]) in[v]++;
        }
        
        queue<int> q;
        for(int u=0;u<V;u++) if(!in[u]) q.push(u);
        int cnt = 0;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout << u << " " ;
            
            for(auto v:g[u]) if(--in[v]==0) q.push(v);
            cnt++;
        }
        assert(cnt==V);
    } 
```

<a name="k"/>

`Min Topological Ordering: Topological Sorting is lexicographically smallest, idea: normal Kahn, in[], pick lex smallest vertex everytime`

`Min Topological Labelling: Topological labelling is lexicographically smallest, idea: reverse Kahn, out[], pick lex largest vertex everytime and place it in the front`

#### Floyd Warshall

<a name="l"/>

```cpp
void floyd(){
        for(int k=0;k<V;k++){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    chmin(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
}
```
## Minimum Spanning Tree

<a name="m"/>

```cpp
    // Prim: idea, Among all the reachable vertex choose the cheapest one.
    using minheap = priority_queue<pii,vector<pii>,greater<pii>>;
    ll prim(int u){
        minheap q;
        ll ans = 0;
        q.push(mp(0,u));
        
        while(!q.empty()){
            pii u = q.top();
            q.pop();
            if(vis[u.se]) continue;
            ans+=u.fi;
            vis[u.se]=1;
            for(auto &v:g[u.se]){
                if(!vis[v.fi]) q.push(mp(v.se,v.fi));
            }
        }
        return ans;
    }
```

<a name="n"/>

```cpp
    // kruskal: idea, Among all edges which can be added choose the one min val
    
    void kruskal(){
        sort(all(e));
        ll ans = 0ll;
        for(int i=0;i<sz(e);i++){
            int u = e[i].se.fi;
            int v = e[i].se.se;
            int ru,rv;
            ru = root(u);
            rv = root(v);
            if(ru!=rv){
                ans+= e[i].fi;
                Union(u,v);
            }
        }
        cout << ans << endl;
    }
```

`Some-times if dependency of some edge is given, then you can use edges as vertices for MST/dijkstra` </br></br>
`Very important dijkstra trick: Dijkstra can be used as dynamic programming strategy where the substructure is implicit` </br></br>

https://atcoder.jp/contests/abc164/tasks/abc164_e

### Dijkstra

<a name="o"/>

```cpp
    void dijkstra(int u){
        for(int i=0;i<N;i++) d[i] = inf;
        d[u] = 0;
        
        priority_queue<pii,vector<pii>,greater<pii>> q;
        q.push({0,u});
        
        while(!q.empty()){
            pii u = q.top();
            q.pop();
            if(d[u.se]!=u.fi) continue;
            
            for(auto &v:g[u.se]) if(chmin(d[v.se],d[u.se]+v.fi)) q.push(mp(d[v.se],v.se));
        }
    }
```

### Bellman ford

<a name="p"/>

```cpp
    void bellman(int u){
        for(int i=0;i<N;i++) d[i] = inf;
        d[u] = 0;
        
        while(1){
            bool opt = 0;
            for(int i=0;i<m;i++){
                auto [w,a,b] = e[i]; // tuple
                if(d[a]+w < d[b]){
                    d[b] = max(-inf,d[a]+w);
                    p[b] = a , opt = 1;
                }
            }
            if(!opt) break;
        }
    }
```

### Detect Negative Cycle

<a name="q"/>

```cpp
    bool bellman(int u){
        for(int i=0;i<N;i++) d[i] = inf;
        d[u] = 0;
        
        bool opt = 0;
        for(int i=1;i<=N;i++)
            opt = 0;
            for(int i=0;i<m;i++){
                auto [w,a,b] = e[i]; // tuple
                if(chmin(d[b],d[a]+w)) p[b] = a , opt = 1;
            }
        }
        if(opt) return 1;
        return 0;
     }
```

### Find shortest cycle using BFS and edge deletion

https://codeforces.com/contest/1817/problem/B

<a name="q1"/>

```cpp
bool bfs(int a, int b){
		
	queue<int> q; 
	q.push(a); 
	vi parent(n+3,-1); 
	vector<bool> vis(n+3,0);
	parent[a] = -1;
	vis[a] = true;
	
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		
		// check if the shortest cycle is formed. 
		
		if(u==b){
		
			fish.clear();
			unordered_set<int> cycle;
			cycle.insert(b); 
			fish.eb(a,b);
			while(u!=a){
				fish.eb(u,parent[u]);
				u = parent[u];
				cycle.insert(u);
			}
			
			int c=0;
			for(int f: g[a]){
				if(cycle.find(f) == cycle.end()){
					c++;
					fish.eb(f,a);
				}
				if(c==2){					
					return true;
				}
			}
			return false;
		}
		
		for(int v: g[u]){
			if((u==a && v==b) || (v==a && u==b)) continue; // delete this edge 
			if(v==parent[u]) continue; 			
			
			if(!vis[v]){
				vis[v] = true;
				parent[v] = u;
				q.push(v);
			}
		}
	}
	
	return false;
}
 
```

### 0/1 BFS

<a name="r"/>

```cpp
    void bfs_01(int s){
        for(int i=0;i<N;i++) d[i] = inf;
        d[s] = 0;
        deque<int> q;
        q.push_front(s);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto &[v,w]:g[u]){
                if(chmin(d[v],d[u]+w)){
                    if(w==0) q.push_front(v);
                    else q.push_back(v);
                }
            }
        }
    }
```
Problems: https://codeforces.com/contest/1063/problem/B [Nice]

### Strongly Connected Components

<a name="s"/>

![image](https://user-images.githubusercontent.com/21307343/132205089-151c6cab-f372-4e52-94b0-ec2c09166a4d.png)

```cpp

    vi g[MaxN],gr[MaxN];
    vb vis[MaxN];
    stack<int> s;
    vi component;
    
    void dfs1(int u){
        vis[u] = 1;
        for(auto v:g[u]) if(!vis[v]) dfs1(u);
        s.push(u);
    }
    
    void dfs2(int u){
        vis[u]=1;
        component.eb(u);
        for(auto &v:gr[u]) if(!vis[v]) dfs2(u);
    }
    
    void kosaraju(){
        vis.assign(MaxN,0);
        for(int i=0;i<n;i++) if(!vis[i]) dfs1(i);
        vis.assign(MaxN,0);
        
        while(!s.empty()){
            int u = s.top();
            s.pop();
            if(!vis[u]) dfs2(u);
            // .....got the component.....
            component.clear();
        }
    }
```

## Condensed SCC

<a name="t"/>

```cpp
    vi g_scc[MaxN], root[MaxN];
    vi A;
    void build(){
        while(!s.empty()){
            int u = s.top();
            s.pop();
            if(!vis[u]) dfs2(u);
            int r = component.front();
            for(auto v:component) root[v] = r; 
            A.eb(r);
            component.clear();
        }

        for(int u=0;u<n;u++){
            for(auto &v:g[u]){
                int r1 = root[u], r2 = root[v];
                if(r1!=r2) g_scc[r1].eb(r2); // building compressed scc
            }
        }
    }
```

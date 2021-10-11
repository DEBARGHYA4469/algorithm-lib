# Euler Tour Technique

https://usaco.guide/gold/tree-euler?lang=cpp

```cpp	
	int clk = 0;
	int in[MaxN],out[MaxN];
	
	void dfs(int u,int p=-1){
		in[u]=++clk;
		for(int v:g[u]){
			if(v!=p) dfs(v,u);
		}
		out[u]=clk;
	}
```

* size of subtree rooted at ith vertex in out[i]-in[i]+1.
* all subtree of ith root lies btw {in[i],....,out[i]}
* Once the tree is flattened you can use range query techniques.

### Query for two vertex in the same path from root

`in[i]: in-time in dfs traversal, out[i]: out-time in dfs traversal.`</br> 
`Vertices are on same path if in[i] < in[j] & out[i]>out[j].` 

Propagating Tree: https://codeforces.com/contest/384/problem/E

<li> Idea: To answer subtree queries, always good to convert tree/acyclic graph to a continuous sequence.
<li> [ 1,2,3,4,5,6,7,8,9,.......,MAX ] : clk timings
<li> map in[v] & out[v] to the clk times
<li> any subtree vertex u of vertex v has clk time btw in[v] to out[v].
<li> Perform any range update on the subtrees using a fenwick tree & difference array technique.
  
  
```cpp
  	for(int i=0;i<m;i++){
		int type,x,val;
		cin >> type;
		if(type==1){
			cin >> x >> val;
			update(in[x],val*sgn[x]);
			update(out[x]+1,-1*val*sgn[x]);
		}
		else{
			cin >> x;
			cout << a[x]*1ll+ (ll) sum(in[x])*sgn[x] << endl;
		}
	}  
```
 

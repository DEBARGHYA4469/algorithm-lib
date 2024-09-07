# DSU
### Rank Optimized DSU, needed where you cannot use path compression 

```cpp
struct DSU {
	vector <int> par, size_, rnk;
	int biggest; 
	DSU (int n) : par (n+1), size_(n+1, 1), rnk(n+1,1), biggest(1) { 
		for (int i=0;i<=n;i++) { 
			par[i] = i;
		}			
	}
	int root (int u) {
		if (par[u] == u) return u; 
		return root (par[u]);
	}
	
 
	void unite (int u, int v){
		int ru = root (u) , rv = root(v); 
		if (ru == rv) return; 
		if (rnk[ru] > rnk[rv]) swap (ru, rv); 
		// join ru to rv 
		size_[rv] += size_[ru];
		rnk[v] = max (rnk[v], rnk[u] + 1); 
		par[ru] = rv; 
		chmax (biggest, size_[rv]); 
	}
	int totalSize (int u) {
		return size_[root(u)]; 
	} 
};
```
# Small To Large Trick / Merger Sets

Problem: https://codeforces.com/contest/1620/problem/E

```cpp
	const int XMAX=5e5+5; 
	vector<int> pos[XMAX];
 
	int j=0;
	for(int i=0;i<q;i++){
		int t,x,y;
		cin >> t;
		if(t==1){
			cin >> x;
			pos[x].eb(j++);
		}
		else{
			cin >> x >> y;
			if(x!=y){
				if(sz(pos[x])>sz(pos[y])) pos[x].swap(pos[y]);
				for(int k:pos[x]) pos[y].eb(k);
				pos[x].clear();
			}
		}
	}
 
	vector<int> ans(j);
	for(int x=0;x<XMAX;x++){
		for(int y:pos[x]) ans[y]=x;
	}
```

Concept: Each value get merged from small to large set, increasing set size by atleast twice the size of small set. So max log N copying

Sample Problem: https://codeforces.com/contest/685/problem/B [Nice Idea]


# Lazy Propagation in Disjoint Sets 

In some problem you will be given to perform some operation on a set and later merge two sets. Operation performed on a set needs to be percolated down before merging two sets. This can be avoided by lazily updating the child while merging. 
Say root_u is merging to root_v while merging update value[root_u] -= value[root_v]. Later when you accumulate the results any operation done on set V won't affect root U. 

Example: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C

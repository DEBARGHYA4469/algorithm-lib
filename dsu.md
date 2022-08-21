# DSU

```cpp
int par[10000],rnk[10000];
int compsize[10000];
int max_size=0;
 
int root(int u){
	if(par[u]==u) return u;
    return par[u] = root(par[u]);
}
 
void unite(int u,int v){
	int r1 = root(u), r2 = root(v);
	if(r1==r2) return;
    if(rnk[r1]>rnk[r2]){
    	par[r2] = r1;
    	compsize[r1]+=compsize[r2];
    	compsize[r2]=0;
    	chmax(max_size,compsize[r1]);
    }
    else if(rnk[r1]<rnk[r2]){
    	par[r1] = r2;
   		compsize[r2]+=compsize[r1];
   		compsize[r1]=0;
   		chmax(max_size,compsize[r2]);
    }
    else{
    	par[r2] = r1, rnk[r1]++;
    	compsize[r1]+=compsize[r2];
    	compsize[r2]=0;
    	chmax(max_size,compsize[r1]);
    }
}
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

### Finding centeroid of a tree with cutting the tree

```cpp
// dead[] : contains list of vertices that is cut 

vi ans;

void dfs1(int u=1, int p=-1){
  nos[u] = 1;
  for(int v: g[u]){
    if(v!=p && !dead[v]){
        dfs1(v,u);
        nos[u] += nos[v];
    }
  }
}

void dfs2(int u=1,int p=-1){
  bool any = false;
  for(int v:g[u]){
    if(v!=p && !dead[v]){
      dfs2(v,u);
      if(nos[v]>n/2) any = true;
    }
  }
  if(n-sz[u] <= n/2 && !any) ans.eb(u);
}

void centeroid(int u){
    dfs1();
    dfs2();
}

```

### Finding centeroid of any subtree

Trick: Choose vertex 'v' which has subtree size > n/2 and least among those. Claim: 'v' has to be centeroid.
Proof: ancestor subtree contains < n/2 as total sum = n. Now if any child subtree has size > n/2 it means that should have replaced 'v' as its size < size(v). 
So contradiction!


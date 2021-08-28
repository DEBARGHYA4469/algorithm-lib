## DP on Trees

### Problem-1 

`Choose a subset of nodes such that no two nodes are adjacent and sum of coins is maximum`</br>

Inclusion-Exclusion DP: </br>

```cpp
#define incl first 
#define excl second

pii dp[MaxN][2];
void dfs(int u,int p=-1){
    int s1=0,s2=0;
    for(auto v:g[u]){
        if(v==p) continue;
        dfs(v,u);
        s1+=dp[v].excl;
        s2+=max(dp[v].incl,dp[v].excl);
    }
    dp[u] = mp(c[u]+s1,s2);
}
```


### Problem-2  

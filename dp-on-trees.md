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

`Find number of subtrees of a tree` </br>

<a href="url"><img src="https://user-images.githubusercontent.com/21307343/131239434-0da29956-a16b-4240-9e4b-b4ba99fc9a04.png" align="left" height="200" width="300" ></a>

</br></br>
<a href="https://www.codecogs.com/eqnedit.php?latex=\\Root\:the\:tree\:at\:u\\&space;f_u&space;=&space;\&hash;subtrees\:incl\:u,\:g_u=\&hash;subtrees\:excl\:u\\&space;f_u&space;=&space;\prod(1&plus;f_{c_i})\:\:\:\:\:&space;g_u=\sum&space;f_{c_i}&plus;\sum&space;g_{c_i}\\&space;Ans&space;=&space;f_{u}&plus;g_{u}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\Root\:the\:tree\:at\:u\\&space;f_u&space;=&space;\&hash;subtrees\:incl\:u,\:g_u=\&hash;subtrees\:excl\:u\\&space;f_u&space;=&space;\prod(1&plus;f_{c_i})\:\:\:\:\:&space;g_u=\sum&space;f_{c_i}&plus;\sum&space;g_{c_i}\\&space;Ans&space;=&space;f_{u}&plus;g_{u}" title="\\Root\:the\:tree\:at\:u\\ f_u = \#subtrees\:incl\:u,\:g_u=\#subtrees\:excl\:u\\ f_u = \prod(1+f_{c_i})\:\:\:\:\: g_u=\sum f_{c_i}+\sum g_{c_i}\\ Ans = f_{u}+g_{u}" /></a>
</br></br></br></br>


`Find number of subtrees of a trees of size k` </br>

`Idea: Same as before, we maintain a 2-state dp`

<a href="https://www.codecogs.com/eqnedit.php?latex=\\Root\:the\:tree\:at\:u\\&space;f_{u,k}&space;=&space;\&hash;subtrees\:incl\:u\:\:with\:k\:nodes,\:g_{u,k}=\&hash;subtrees\:excl\:u\:with\:k\:nodes\\&space;f_{u,k}&space;=&space;dp(m,k-1)\:\:\:\:\:&space;g_{u,k}=\sum&space;f_{c_i,k}&plus;\sum&space;g_{c_i,k}\\&space;dp[i][j]:\&hash;subtrees\:with\:j\:nodes\:and\:child\:[1...i]\\&space;dp[i][j]=dp[i-1][j-k]*f_{c_i,k}\\&space;Ans&space;=&space;f_{u,k}&plus;g_{u,k}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\Root\:the\:tree\:at\:u\\&space;f_{u,k}&space;=&space;\&hash;subtrees\:incl\:u\:\:with\:k\:nodes,\:g_{u,k}=\&hash;subtrees\:excl\:u\:with\:k\:nodes\\&space;f_{u,k}&space;=&space;dp(m,k-1)\:\:\:\:\:&space;g_{u,k}=\sum&space;f_{c_i,k}&plus;\sum&space;g_{c_i,k}\\&space;dp[i][j]:\&hash;subtrees\:with\:j\:nodes\:and\:child\:[1...i]\\&space;dp[i][j]=dp[i-1][j-k]*f_{c_i,k}\\&space;Ans&space;=&space;f_{u,k}&plus;g_{u,k}" title="\\Root\:the\:tree\:at\:u\\ f_{u,k} = \#subtrees\:incl\:u\:\:with\:k\:nodes,\:g_{u,k}=\#subtrees\:excl\:u\:with\:k\:nodes\\ f_{u,k} = dp(m,k-1)\:\:\:\:\: g_{u,k}=\sum f_{c_i,k}+\sum g_{c_i,k}\\ dp[i][j]:\#subtrees\:with\:j\:nodes\:and\:child\:[1...i]\\ dp[i][j]=dp[i-1][j-k]*f_{c_i,k}\\ Ans = f_{u,k}+g_{u,k}" /></a>

### Problem-3
`Tree Matching: A matching is a set of edges where each node is an endpoint of at most one edge. What is the maximum number of edges in a matching?`</br></br>

`Trick: prefix & suffix array precomputation`

```cpp
       int dp[MaxN][2];
       // dp[u][0]: max matching excl vertex u, dp[u][1]: max matching incl vertex u
       
       void solve(int u,int p=-1){
               int leaf=0;
               vector<int> pref,suff;
               for(auto &v:g[u]){
                       if(v!=p){
                              solve(v,u);
                               pref.eb(max(dp[v][0],dp[v][1]));
                       }
                       leaf++;
               }
               if(leaf==1) return;
               
               suff = pref;
               
               for(int i=1;i<leaf;i++){
                       pref[i] += pref[i-1];
                       suff[leaf-i-2]+=suff[leaf-i-1];
               }
               
               dp[u][0] = suff[0];
               
               int cn = 0;
               for(auto &v:g[u]){
                        if(v!=p){
                               int l =  cn==0 ? 0: pref[cn-1];
                               int r =  cn==leaf-1 ? 0: suff[cn+1];
                               dp[u][1] = max(dp[u][1],l+dp[v][0]+r)
                               cn++;
                        }
               }
       }
```


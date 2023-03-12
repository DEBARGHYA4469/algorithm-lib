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
### Tree Distance I

`Given a acyclic graph find the farthest node from each node`

```cpp
       // up_max: max height upwards(to par)
       void solve(int u,int p=-1,int up_max){
            vi pref,suff;
            for(auto &v:g[u]){
                if(v==p) continue;
                pref.eb(d[v]);
            }
            
            suff = pref;
            for(int i=1;i<sz(pref);i++) { 
                    pref[i] = max(pref[i-1],pref[i]);
                    suff[m-i-1] = max(suff[m-i-1],suff[m-i]);
            }
            if(!pref.empty())  ans[u] = 1+max(pref.back(),up_max);
            else ans[u] = 1+up_max;
                 
            int cn=0;
            for(auto &v:g[u]){
                    if(v==p) continue;
                    int l=cn==0? -inf:pref[cn-1];
                    int r=cn==m? -inf:suff[cn+1]; 
                    solve(v,u,1+max({l,r,up_max}));
                    cn++;
            }
            
       }
       
```
### Tree Distance II

`Find the sum of distances of tree nodes to a given node` </br>
`Trick: Solve-UP and Solve-DOWN technique`

```cpp
     ll f[MaxN],sz[MaxN]; // f[u]: sum from the nodes in subtree rooted at u
     void solve_down(int u,int p=-1){
            for(auto &v:g[u]){
                if(v==p) continue;
                solve_down(v,p);
                sz[u]+=sz[v];
                f[u]+=f[v]+sz[v];
            }
            sz[u]++;
     } 
     
     void solve_up(int u,int p=-1,int partial_ans){
            ans[u] = p!=-1 ? f[u] + partial_ans + N - sz[u];
            for(auto &v:g[u]){
                if(v==p) continue;
                solve_up(v,u,ans[u]-(sz[v]+f[v]));
            }
     }
```

### In-Out Dp on Trees

`Idea: Calculate in[v] values of node by rooting the trees and looking in subtrees, out[v] is the value by looking at the parent and ignoring the subtree, using in+out you can view the whole tree standing at a node, note that out[0]=in[0] if the tree is rooted at 0.`


### Max Product of non-intersecting path in a tree
![image](https://user-images.githubusercontent.com/21307343/132102913-09671330-93f0-4e5d-a0ea-783e9d3dbd21.png)

<a href="https://www.codecogs.com/eqnedit.php?latex=\\Rooted-Tree\:at\:u_0&space;\\Let\:{\color{Red}&space;out}\:denote\:info\:passed\:from\:parent\:to\:vertex\:{\color{Blue}u}&space;\\When\:detaching\:p-u,&space;S_1:&space;parent\:set|\:\:S_2:child\:set&space;\\ans&space;=&space;max(h[x]&plus;h[y],dia[x])*out[p].dia&space;\\Constructing\:{\color{Magenta}&space;out[p].dia}\:for\:u\::\\&space;{\color{DarkOrange}&space;out[u].dia}&space;=&space;max(h[x_v/v]&plus;h[y_v/v],dia[x_v/v],out[p].dist&plus;h[x_v/v]\\&space;{\color{DarkBlue}&space;out[u].dist}=&space;max(out[p].dist,out[p].h)&plus;1\\&space;{\color{DarkGreen}&space;out[u].h}&space;=&space;max\:h[x_v/u]" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\Rooted-Tree\:at\:u_0&space;\\Let\:{\color{Red}&space;out}\:denote\:info\:passed\:from\:parent\:to\:vertex\:{\color{Blue}u}&space;\\When\:detaching\:p-u,&space;S_1:&space;parent\:set|\:\:S_2:child\:set&space;\\ans&space;=&space;max(h[x]&plus;h[y],dia[x])*out[p].dia&space;\\Constructing\:{\color{Magenta}&space;out[p].dia}\:for\:u\::\\&space;{\color{DarkOrange}&space;out[u].dia}&space;=&space;max(h[x_v/v]&plus;h[y_v/v],dia[x_v/v],out[p].dist&plus;h[x_v/v]\\&space;{\color{DarkBlue}&space;out[u].dist}=&space;max(out[p].dist,out[p].h)&plus;1\\&space;{\color{DarkGreen}&space;out[u].h}&space;=&space;max\:h[x_v/u]" title="\\Rooted-Tree\:at\:u_0 \\Let\:{\color{Red} out}\:denote\:info\:passed\:from\:parent\:to\:vertex\:{\color{Blue}u} \\When\:detaching\:p-u, S_1: parent\:set|\:\:S_2:child\:set \\ans = max(h[x]+h[y],dia[x])*out[p].dia \\Constructing\:{\color{Magenta} out[p].dia}\:for\:u\::\\ {\color{DarkOrange} out[u].dia} = max(h[x_v/v]+h[y_v/v],dia[x_v/v],out[p].dist+h[x_v/v]\\ {\color{DarkBlue} out[u].dist}= max(out[p].dist,out[p].h)+1\\ {\color{DarkGreen} out[u].h} = max\:h[x_v/u]" /></a>


* Nice Example of In-Out DP Technique: Atcoder DP Contest: Subtree

```cpp
int N,M;
vi g[100006];

ll dp1[100006]; 
void dfs1(int u=1,int p=-1){
	dp1[u] = 1;
	for(int v: g[u]){
		if(v!=p){
			dfs1(v, u);
			dp1[u] *= (1+dp1[v]);
			dp1[u] %= M; 
		}
	}
}

ll ans[100006];
void dfs2(int u=1,int p=-1,ll par=0){
	ans[u] = (dp1[u] * (1+par)) % M;

	int c = 0;
	vector<ll> tmp;
	tmp.eb(1);

	for(int v: g[u]){
		if(v!=p){
			c++;
			tmp.eb(1+dp1[v]);
		}
	}

	vector<ll> pref(c+5, 1), suff(c+5, 1);
	pref[1] = tmp[1], suff[c] = tmp[c];

	for(int i=1; i<c; i++){
		pref[i+1] = (pref[i]*tmp[i+1]) % M;
		suff[c-i] = (suff[c-i+1]*tmp[c-i]) % M;
	}

	int z = 1;
	for(int v: g[u]){
		if(v!=p){
			ll L, R;
			L = pref[z-1];
			R = suff[z+1];
			ll down = (((L*R)%M)*(1+par)) % M;
			dfs2(v, u, down); 
			z++;
		}
	}
}
 
int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for(int i=0; i<N-1; i++){
		int x, y; cin >> x >> y;
		g[x].eb(y);
		g[y].eb(x);
	}

	dfs1();
	dfs2();

	for(int i=1; i<=N; i++) cout << ans[i] << endl;
	 
	return 0;
}
```

Practise Problems: https://codeforces.com/contest/109/problem/C https://codeforces.com/problemset/problem/337/D

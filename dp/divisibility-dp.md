### Divisibility Problems:
1. Given a large number, check if a subsequence is divisible by 8.

`Construct dp[i][j]: 1 if subsequence of n[0...i] is j modulo 8`

```cpp
    bool dp[100][10];
    pair<int,int> p[100][10];
    
    using nop = mp(-1,-1);
    
    d[0][n[0]-'0'] = 1;
    p[0][n[0]-'0'] = nop;
    for(int i=1;i<sz(n);i++){
        int d = n[i]-'0';
        dp[i][d%8] = 1;
        p[i][d%8] = nop;
        
        for(int j=0;j<8;j++){
            int r = (j*10+d)%8;
            if(chmax(dp[i][r],dp[i-1][j])) p[i][r] = mp(i-1,j);
            if(chmax(dp[i][j],dp[i-1][j])) p[i][j] = mp(i-1,j);
        }   
    }
    
    // constructing the solution
    string ans="";
    for(int i=0;i<n;i++){
        if(dp[i][0]){
            int u=i,v=0;
            while(p[u][v]!=nop){
                if(v!=p[u][v].se) ans = ans + n[u];
                tie(u,v) = p[u][v]; 
            }
            ans = ans + n[u];
            cout << ans << endl;
            return 0;
        }
    }
 ```
 
 2. No of subsequences that are divisible by x

```cpp
      int dp[MaxN][x];
      for(int i=0;i<sz(n);i++){
            int d = n[i]-'0';
            dp[i][d%x]++;
            for(int j=0;j<x;j++) dp[i][j]+=dp[i-1][j], dp[i][(j*10+d)%x]+=dp[i-1][j];
      }
```

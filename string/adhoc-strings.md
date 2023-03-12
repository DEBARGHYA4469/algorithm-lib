#### Minimum Palindromic Cuts: 

`Given a string s = BABABCBADCD, minimum palindromic cut: BAB|ABCBA|DCD`
</br>
```cpp
      int pal[N+1][N+1];
      int solve(string &s){
            for(int k=1;k<=N;k++){
                  for(int i=0,j=i+k-1;i<N;i++,j++){
                       if(k==1) pal[i][j] = 1;
                       else if(k==2) pal[i][j] = s[i]==s[j];
                       else{
                            pal[i][j] = pal[i+1][j-1] && s[i]==s[j];
                       }
                  }
            }
            
            int cut[N+1];
            for(int i=0;i<N;i++){
                cut[i] = inf;
                if(pal[0][i]) chmin(cut[i],1);
                for(int j=0;j<=i;j++){
                      if(pal[j][i]) chmin(cut[i],cut[j]+1);
                }
            }
            return cut[N-1];
      }
```

#### Scatter Palindromes:

`Given a string of size N, how many substrings can be rearranged into a palindrome?`</br></br>
```cpp
    int a[N+1]; 
    a[0] = 1<<(s[0]-'a');
    for(int i=1;i<N;i++) a[i] = a[i-1] ^ (s[i]-'a');
    int ans=0;    
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
             int mask = i==0 ? a[j] : a[j] ^ a[i-1];
             if(!mask^(mask-1)) ans++;
        }
    }
    cout << ans << endl;
```

#### Distinct Subsequences

`Given a string of size N, how many distinct subsequence are there of the string?`</br></br>

`Formal Proof:`

```cpp
      int dp[n];
      dp[0] = 2;
      for(int i=1;i<n;i++){
            dp[i]=dp[i-1]*2;
            int c = s[i]-'a';
            if(prev[c]!=-1) dp[i]-=dp[prev[c]-1];
            prev[c] = i;
      }
```

Distinct Subsequence of particular length:

```cpp
      dp[i][j]: #distinct subsequence of length j considering till ith element.
      dp[i][j] = dp[i-1][j]+dp[i-1][j-1]-dp[prev[c]-1][j-1];
```

#### Don't Be a Subsequence

`Idea: Use prev or next function, Always look at the starting or last characters in subsequence based problems to find any optimal structure.`

```cpp
      dp[i] = dp[prev[i][c]-1] + 1; // using prev function
      dp[i] = dp[nxt[i][c]+1] + 1; // using next function
      
      For lexicographical order, you have to use the next function
```

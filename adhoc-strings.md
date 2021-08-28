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

`Classical Trick:`</br></br>

```
            Let s = c0 c1 c2 c3 ....ck...cj....cn
            
            dp[j]: #distinct subsequences considering till jth character
            Consider what are included in dp[j]:
            
            All subsequences from dp[j-1], (trivial!!)
            Add cj to all subsequences from dp[j-1] to(possibly!) get a new subsequence.
            But this may result in duplicate subsequences.
            Currently dp[j-1]*2: S = (A:{t1,t2,t3,...,tm}) + (B:{t1,t2,t3,...,tm}|sj)
            Remove all duplicates from B that are already present in A(all unique element).
            
            Claim: All & only subsequences from k (sk=sj and k is closest to j for all such j) are getting duplicated.             
            Proof: Finding A intersection B:  Let sk=sj=s
                   all {Set [k-1]}|s are included in A & B
```

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

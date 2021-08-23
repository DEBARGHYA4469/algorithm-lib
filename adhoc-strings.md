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

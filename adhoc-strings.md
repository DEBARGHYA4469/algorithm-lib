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

Consider the string <a href="https://www.codecogs.com/eqnedit.php?latex=\\s=s_1s_2....s_j....s_k....s_{n}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?s=s_1s_2....s_j....s_k....s_{n}" title="s=s_1s_2....s_j....s_k....s_{n}" /></a> wher s[j]=s[k]=s' & j is closest to k.</br>

Denote:</br>
Tk = set of distinct subsequences till kth index.</br>
Pk = set of subsequences obtained by concatenating s' with Tk elements. </br>

Clearly:
<li> Elements of Pk are distinct, or Tk are not!
<li> <a href="https://www.codecogs.com/eqnedit.php?latex=T_k&space;=&space;T_{k-1}&space;\bigcup&space;P_k" target="_blank"><img src="https://latex.codecogs.com/gif.latex?T_k&space;=&space;T_{k-1}&space;\bigcup&space;P_k" title="T_k = T_{k-1} \bigcup P_k" /></a>
<li><a href="https://www.codecogs.com/eqnedit.php?latex=T_k&space;=&space;T_{k-1}&space;&plus;&space;P_k&space;-&space;T_{k-1}&space;\bigcap&space;P_{k}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?T_k&space;=&space;T_{k-1}&space;&plus;&space;P_k&space;-&space;T_{k-1}&space;\bigcap&space;P_{k}" title="T_k = T_{k-1} + P_k - T_{k-1} \bigcap P_{k}" /></a>
<li><a href="https://www.codecogs.com/eqnedit.php?latex=T_{k-1}&space;\bigcap&space;P_k=T_j&space;\bigcap&space;P_k" target="_blank"><img src="https://latex.codecogs.com/gif.latex?T_{k-1}&space;\bigcap&space;P_k=T_j&space;\bigcap&space;P_k" title="T_{k-1} \bigcap P_k=T_j \bigcap P_k" /></a>  as all elements in Pk end with s'
<li><a href="https://www.codecogs.com/eqnedit.php?latex=T_j&space;\bigcap&space;P_k=(T_{j-1}\bigcup&space;P_j)\bigcap&space;P_k" target="_blank"><img src="https://latex.codecogs.com/gif.latex?T_j&space;\bigcap&space;P_k=(T_{j-1}\bigcup&space;P_j)\bigcap&space;P_k" title="T_j \bigcap P_k=(T_{j-1}\bigcup P_j)\bigcap P_k" /></a> </br>

Lemma: Any element that ends with s' belongs to P(j) and never in T(j-1)-P(j) </br></br>
So, <a href="https://www.codecogs.com/eqnedit.php?latex=T_j&space;\bigcap&space;P_k=P_j\bigcap&space;P_k" target="_blank"><img src="https://latex.codecogs.com/gif.latex?T_j&space;\bigcap&space;P_k=P_j\bigcap&space;P_k" title="T_j \bigcap P_k=P_j\bigcap P_k" /></a> </br> and <a href="https://www.codecogs.com/eqnedit.php?latex=T_{j-1}\subset&space;T_{k-1}&space;\implies&space;P_j\subset&space;P_k\" target="_blank"><img src="https://latex.codecogs.com/gif.latex?T_{j-1}\subset&space;T_{k-1}&space;\implies&space;P_j\subset&space;P_k\" title="T_{j-1}\subset T_{k-1} \implies P_j\subset P_k\" /></a> </br>

<a href="https://www.codecogs.com/eqnedit.php?latex=f_k&space;=&space;\eta(T_{k-1})&plus;\eta(P_{k})&space;-&space;\eta(T_{k-1}\bigcap&space;P_k)&space;=&space;2f_{k-1}-\eta(P_j)=2f_{k-1}-f_{j-1}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f_k&space;=&space;\eta(T_{k-1})&plus;\eta(P_{k})&space;-&space;\eta(T_{k-1}\bigcap&space;P_k)&space;=&space;2f_{k-1}-\eta(P_j)=2f_{k-1}-f_{j-1}" title="f_k = \eta(T_{k-1})+\eta(P_{k}) - \eta(T_{k-1}\bigcap P_k) = 2f_{k-1}-\eta(P_j)=2f_{k-1}-f_{j-1}" /></a>


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

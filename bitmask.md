## Bitmasking

`Used to solve problems that are exponential in time and memory and having low constraints.`
</br></br>
`Assignment Problem` </br></br>
There are N person & N tasks, each task alloted to a single person, Cost matrix given, for ith person to do the jth task. Find the min cost. </br>

```cpp
    f(k,mask): person 1...k-1 has been assigned a task now upto the kth person and the state of the assigned task is mask
    int x = _builtin_popcount(mask);
    answer(k+1,mask|(1<<i)) = min(answer(k,mask|(1<<i),ans(mask)+cost[x][i]))
    or, quite simply,
    chmin(dp[mask|(1<<i)],dp[mask]+c[#setbits(mask)][i]);
```

### Held-Karp for TSP

`Find the minimum distance to travel all vertex from a given node(say 0) and get back to it`

```cpp
    int ALL = (1<<n)-1;
    int dp[n+5][ALL+5];
    int tsp(int mask,int pos){
         if(mask==ALL) return d[pos][0];
         if(dp[pos][mask]!=-1) return dp[pos][mask];
         int ans = inf;
         for(city=0;city<n;city++){
            if(mask&(1<<city)==0){
                  chmin(ans, d[pos][city]+tsp(mask|(1<<city),city));
            }
         }
         return ans;
    }
```

### Bitmask over Primes

Prime Mask: 

```cpp
    void init(){
            int p[100];
            mem(p,1);
            vi parr;
            p[0]=p[1]=0;
            for(int i=2;i<100;i++){
                if(!p[i]) continue;
                else parr.eb(i);
                for(int j=2;i*j<100;j++){
                    p[i*j]=0;
                }
            }
            
            for(int i=0;i<sz(parr);i++) 
                for(int j=1;j<60;j++)
                    if(j%parr[i]==0) primeMask[j] |= 1<<i;
     }
```

#### Properties:

<li> GCD of numbers = primeMask[i] & primeMask[j]
<li> LCM of numbers = primeMask[i] | primeMask[j]
<li> Prime Divisors = (1<<ith prime) & primesMask[i]==0 ? 
<li> Divisors = Iterating over submasks
    
#### Submask Enumeration

```cpp
    void submask(int m){
        for(int i=m;i;i=(i-1)&m){
                // to do
        }
    }
```

### Profile DP
    
https://cp-algorithms.com/dynamic_programming/profile-dynamics.html

`Find no of ways to fill NxM matrix with 2x1 dominoes`
    
```cpp
    
    void calc(int x=0;int y=0;int mask,int next_mask){
        if(x==n) return;
        if(y>=m) 
            dp[x+1][next_mask] += dp[x][mask];
        else{
               if(mask & (1<<y)) 
                    calc(x,y+1,mask,next_mask);
                else{
                        calc(x,y+1,mask,next_mask|(1<<y));
                        if(y+1<m && !(mask & (1<<(y+1))) 
                               calc(x,y+2,mask,next_mask);
                }
        }
    }
    
    ll dp[n+1][1<<m];
    dp[0][0] = 1;
    for(int x=0;x<n;x++)
        for(int mask=0;mask<(1<<m);mask++)
            calc(x,0,mask,0);
    
    cout << dp[n][0];
    
```
    

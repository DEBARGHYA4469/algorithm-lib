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
<li> Divisors = Iterating over submasks

GCD Set-Cover. Eg. https://codeforces.com/problemset/problem/510/D

Say you have a number a[i]. You want to know the set cover with min cost and gcd = 1. 

* a[i] ~ 10^9 will have max 10 prime numbers. Create a mask of this prime numbers [0000000000].
* mask[i] is on if there is a set such that number is not divisible by prime[i].
* Ans is the cost of [1111111111].
* For each mask we will foreward calculate next masks by OR'ing the current mask.
* Fact: Number of distinct GCDs of a set of numbers is small!   

    
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
Weighted Subset Sum: 

https://codeforces.com/problemset/problem/1552/D

- If you are required to check if a weighted sum of a subset is equal to a given number.
- One way to go about is to do a knapsack if the maximum weight is less than some A. dp[i][A] -> dp[i+1][A'], A' can be negative. Complexity : O(N * MAX A)
- Alternatively, if you know the weights are less than some small number (say <= b = 4). Represent all masks from 1 through 4 << N. And calculate sum of the subsets as per mask representation. Say 0 : w1, 1 : w2, 2 : w3, 3 : w4.  Complexity: (4^N * N)
- Recursively, solve (idx, mask_base_4).

 
    

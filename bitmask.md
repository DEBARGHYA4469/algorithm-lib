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

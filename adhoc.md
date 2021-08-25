### Kadane's Like Solutions

**Max Subarray problem**: Keep a running variable called `max_ending_here` </br>

```cpp
max_ending_here = max(a[i],max_ending_here+a[i]);
max_so_far = max(max_so_far,max_ending_here);
```
**Max Product Subarray**: </br>

```cpp
max_ending_here = max(a[i],a[i]*(a[i]>=0)? max_ending_here:min_ending_here);
min_ending_here = min(a[i],a[i]*(a[i]>=0)? min_ending_here:max_ending_here); 
max_so_far = max(max_so_far,max_ending_here);
```

### Buy and Sell Share
Given, share prices for some days, [p1,p2,...,pN], transaction of second share starts after first sells; 
#### Variant-1
`You can transact only one share: solution: max(ans,a[i]-min_so_far);`
#### Variant-2
`You can transact atmost 2 share: solution: max(ans,u[i]+v[i]),`</br>
`where u[i]: max value of 1-share from left, v[i]: max value of 1-share from right`
#### Variant-3
`You can transact atmost k shares: solution: ` </br>
`dp[i][k] = max(dp[i][k-1],dp[j][k-1] + a[i]-a[j]), j<i`</br></br>
DP optimization: dp[j][k-1] + a[i]-a[j] = a[i] - (a[j]-dp[j][k-1]); 
#### Variant-4
`You can transact any number of shares: solution: solution: sum(local maxima-previous_minima)`</br>

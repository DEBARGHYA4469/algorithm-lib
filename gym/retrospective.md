### https://codeforces.com/contest/1509/problem/C

The Sports Festival -> Level: 1800

Topic:  Range DP + Exchange Argument

* Observed: All same valued elements stays together. Started thinking in terms of exchange arguments with (values, frequency) orders. Stuck on that. 
* Found no other greedy idea. Gave up. 
* Observed: One of the extreme values should end at the last. So problem reduces to subproblem with array size one less. 
* Did not think in recursive way, so missed DP idea. 

### https://codeforces.com/contest/1801/problem/C
The Music Festival -> Level: 1900

Topic: DP + Exchange Argument

* Observed: Only prefix maximum for a album matters. So look into the compressed arrays with prefix maximas. 
* [x1,x2,x3], [y1,y2], [z1,z2,z3,z4,z5,z6.z7]
* Missed Observation: Consider the optimal solution, s1..., s2...., s3....,s4....
* if s2.back > s3.back => s3 contributes 0 to the coolness. 
* So remove s3 does not affect results. So we can assume the contribution is coming from the sorted sequence. Exchange argument. Exchange till we get the sorted sequence.   
* Now apply dp on the sorted sequence of tracks. 
* dp[i] : max coolness considering all the tracks from 1...n.
* dp[i] = (size of track - j) + dp[l] + 1. for l, such that maximum value from 1...l < j
* Better use the dp[i]: max coolness such that maximum so far is i.       

### https://codeforces.com/problemset/problem/346/B
Lucky Common Subseuqence
Topics: DP + KMP 

Given two strings a, b, c. Find LCS of string a and b which does not contain c.  

* Initial Observations:  
 
      Define dp[i][j][k] : maximum lucky subsequence considering a[0...i], b[0...j] such that it has suffix of length k matching prefix of c. 
      Answer = dp[n-1][m-1][k] for all k. 
      What are the transitions? 
            - if s[i] != s[j] :
                  dp[i][j][k] = max (dp[i-1][j][k], dp[i][j-1][k]); 
            - if s[i] == s[j] :
                  dp[i][j][k] = dp[i-1][j-1][k-1] + 1
                  
            *** This transition is wrong as values dp[i-1][j-1][k'] for k' > k can also contribute to dp[i][j][k]
            *** How to find those transitions? 
            *** Brute Force requires N^4 calculations. TLE 

Use KMP. 

```cpp
For each i 
  For each j 
     For each k
        p = k 
        while(p && s[i] != virus[p+1]) p = pi[p-1]; 
        if(s[i]==virus[p+1]) change w <- f(k) 
```

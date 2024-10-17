## Catalan Number 

Interesting way to form patterns with balances 

In problems involving two entities say Right(R), Up(U) and a constraint that #R >= #U. What are the number of sequences with balance K and total M entities. 

Since balance = K. 

#R = x 
#U = M - x

(M - x) - x = K 
x = M - K / 2

#R = (M - K) / 2
#U = (M + K) / 2;

```
Let ways[i][j] be number of ways to arrange the R and U such that at end balance is j 

Perform a forward DP calculation ...

ways[i + 1][j + 1] += ways[i][j]
ways[i + 1][j - 1] += ways[i][j] 
```

Example:

https://codeforces.com/contest/2025/problem/E 

### Reflection Technique

https://codeforces.com/contest/26/problem/D

Given you already have a extra balance of R say k, what is the number of ways to get final string with x R and y U such that U <= R. 

Way to solve this is through reflection about a point. 

Consider and set [R ...k times ... R R U U U U ...U R ..U] ..[] say this is where the balance breaks. 
Now let x be number of Us in it. 
Number of R's in it = (x - 1 - k). 

Reflect first half of the sequence. 
Number of Us = (x - 1 - k), Rs = x. 

Total Us = m - x + (x - 1 - k) = m - 1 - k 
Total Rs = n - (x - 1 - k) + x = n + 1 + k 

Total Combinations = C(n + m, m - 1 - k), these are all bad combinations. 
Good combinations = C(n + m, n) - C(n + m, m - 1 - k). 
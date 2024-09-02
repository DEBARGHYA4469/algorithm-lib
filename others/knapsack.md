## Variants of Knapsack Problems

Resources: 

1. https://codeforces.com/blog/entry/59606 : Tutorial: Knapsack, Subset Sum and the max,+ Convolution
2. https://codeforces.com/blog/entry/59606 : Tutorial: Optimized solution for Knapsack problem
3. https://codeforces.com/blog/entry/88660 : Knapsack the tutorial
4. https://codeforces.com/blog/entry/49812 : Decide if a number equals the sum of some submultiset of positive integers


Problems: https://codeforces.com/problemset/problem/1132/E

BITSET optimization (32 factor optimization) 

```cpp
      for (int i=0;i<n;i++){
          for (int x=0; (1<<x) <= m[i]; x++){
              dp |= dp << (a[i] * (1<<x));
              m[i] -= 1<<x;
          }
          dp |= dp << a[i] * m[i];  
      }
```

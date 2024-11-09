1. If there are any kind of structural pattern to the optimal solution. Use DP to find that by transitioning between structures.
      * Kadanes-based problem: https://codeforces.com/contest/1155/problem/D
      * Use Kadanes after modifying the array: https://codeforces.com/contest/1197/problem/D 

2. InLine DP https://atcoder.jp/contests/abc372/tasks/abc372_f
Say you have a dp transition dp [i][k] = dp[i - 1][k - 1] + some extra transitions. If N is large you don't have to calculate i -> i + 1 for each k.
You can just shift the array / deque by 1 in O(1) and only work on the extra transition. Same goes when dp[i][k] = dp[i - u][k - 1]. 

3. DP optimzation using difference array technique. If some dp state changes by range sum under constraint, you can store the transitions lazily inside a difference array.
https://codeforces.com/contest/2025/problem/D

4. DP on ranges optimization with multiset. Say dp[j] = max (dp[j], dp[i] + something). You can maintain a multiset of candidate dp[i] values and store the R ranges in a array of vectors. When you reach that right border erase the min element. In that way you can get minimum so far allowed value.
https://codeforces.com/contest/2024/problem/D

5. Dijkstra DP optimizations. 

6. DP optimization for N^2 dp state space where total space is limited by N. 
Let dp[i][j] say total j states are <= N. 
You can do something like dp[i].resize(h_i);
https://codeforces.com/contest/2030/problem/E

6. Contribution technique + DP 
Say you are given to calculate something over all subsquence. 
You get the structure [..+ j +..]
Ans += ways[j] * j 
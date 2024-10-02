1. If there are any kind of structural pattern to the optimal solution. Use DP to find that by transitioning between structures.
      * Kadanes-based problem: https://codeforces.com/contest/1155/problem/D
      * Use Kadanes after modifying the array: https://codeforces.com/contest/1197/problem/D 

2. InLine DP https://atcoder.jp/contests/abc372/tasks/abc372_f
Say you have a dp transition dp [i][k] = dp[i - 1][k - 1] + some extra transitions. If N is large you don't have to calculate i -> i + 1 for each k.
You can just shift the array / deque by 1 in O(1) and only work on the extra transition. Same goes when dp[i][k] = dp[i - u][k - 1]. 

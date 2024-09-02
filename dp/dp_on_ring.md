## DP on Rings 

In some problems the states when they end have a constraint with the initial state. These problems are formulated speacially in a circular ring, hence the name DP on rings. 

Take the example of a regular problem, given a N, find how many ways to colour N beads in a row with M colours such that there are no consecutive beads with the same colour. 

```
dp[i][x] : denote the number of ways to color first i beads with ith bead having color x

Transitions: 
	dp[i][x] := Sum_k (1...M \ {x}) dp[i-1][k]
	Final Answer := Sum_X (1...M) dp[N][X] 
```

Consider the same problem but now in a circular ring! Now there is an additional constraints that Nth ring is now consecutive.


```
dp[i][x][k]: denote number of ways to color first i beads such that ith bead is of color x and 1st bead of color k

Transitions: 
	dp[i][x][k] := for a particular k, dp[i][x][k] := Sum (1...M) dp[i-1][X\{x}][k]
	Final Answer := Sum (1...K) Sum (1...X) dp[N][X\K][K]`

You can simplify this further by just considering the following states: 

```
	dp[i][f]: number of ways to color ith bead if first and ith bead are of same color if f = true, false otherwise. 
	Transitions --- 
	dp[i][true] := (m-1) * dp[i-1][false] 
	dp[i][false] := (m-2) * dp[i-1][false] + (m-1) * dp[i-1][true]
```

Problem: https://atcoder.jp/contests/abc307/tasks/abc307_e


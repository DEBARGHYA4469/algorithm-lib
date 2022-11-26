
### Substring and Subsequence Problem 


Type of problem:

In problems where two strings are given and some tasks based on the subsequence/substring of the two strings. Tasks can be to check existence or no of such occurrence etc. 

General Idea: Can be solved with O(N^2) DP. How? 

Maintain a array dp[i][j] corresponding to s[0…i] & t[0…j]. 

If the problem involves substring, then dp[i][j] denote answer when substring <b>ends</b> at i. Why? To maintain continuity of the characters. 

If the problem involves subsequence, then dp[i][j] denote answer when subsequence is <b> bounded </b> by s[0…i]. 

Problems to Practice: 

* [Substring and Subsequence](https://codeforces.com/contest/163/problem/A)


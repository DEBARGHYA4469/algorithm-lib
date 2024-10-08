## Permutations and Transpositions

Ref: https://codeforces.com/blog/entry/111187 (nor's blog) 

Def: Permutation is a shuffle of range [1, N], in other word, permutation is a bijection on a set.

## Inversion 

Inversion is pair (i,j), i < j such that p[i] > p[j]. Inversion count of an array if the number of inversion in the array. 

* Adjacent swaps changes inversion count by 1. (trivial)
* Non-adjacent swaps flips inversion count. (Proof: follows from cycle decomposition)


## Cycle Decomposition 

Every permutation is composed of cycles. Proof? 

- Consider a permutation [p1, p2, p3, ...., pN].
- ith element goes to p[i] th position, p[i]th element goes to p[p[i]] position and so on!
- Positions are limited so some kth position will repeat in the traversal. Let say it is not the start position.
- By bijection, p^-1[a[k]] = p^-1[a[l]]. so a[k-1] = a[l-1], which contradicts the minimality.
- So it forms a cycle. 
 

Each permutation can be decomposed into disjoint cycles. E.g. [23154] = (123)(45) 

- Permutations form functional graphs. Every vertex has a out degree.
- How to find the vertex v which is reached if you travel k times along the permutation graph from a vertex u?
- Use Binary Lifting!

 Problems: 
 
 1. CSES Planet Queries I https://cses.fi/problemset/task/1750
 2. CSES Planet Queries II https://cses.fi/problemset/task/1160

## Transpositions

- Swaps in an array are called transpositions.
- Swapping two elements in a cycle, breaks the cycle into two.
- Swapping two elements from two different cycles merge the cycles.

Problem: Lucky Permutation https://codeforces.com/contest/1768/problem/D

Hint: Cycle decomposition! 

Number of transpositions required to sort an array? 

- Each transposition can reduce a cycle size by 1. Finally it has n cycles. So minimum number of transpositions is n - cycles.

## Parity of Transpositions

- Transpositions flip parity.
- All even sized cycles have odd parity.
- All odd sized cycles have even parity.
- Parity add up module 2 over composition of cycles.
- Parity of permutation is odd if number of even sized cycles is odd.
- Parity of permutation is even if number of even sized cycles is even.
- Odd number of swaps means odd parity of permutations.

## Inversion

- Inverse of a cycle [c1 c2 c3 ... ck] is its reverse [ck ... c3 c2 c1].
- Inverse of a composition ab is b^-1 a^-1

## Involution

- a = c1 ...cm. Then, a^k = [c1^k, ..., cm^k].
- id = a^2. So, c^k = id.
- If k = 2, cycles can be 1 or 2 sized.
- If k = 6 cycles can be 1, 2, 3, 6, factors of k!

## Power of a permutation

- kth power of a cycle corresponds to mapping to it kth next neighbour.
- If the length of the cycle is c. c^k is composed of say g length cycles. (symmetry)
- i + gk = i (mod c)
- gk = 0 (mod c)
- What is the least g? g = c/gcd(k,c)
- Number of g length cycles = c/g = gcd(k,c).

## Order of a permutation 

- Order of a permutation is defined as the least k such that a^k is identity.
- A cycle of length L requires, a^L permutations to resolve into identity permutation.
- If a permutation can be decomposed into cycles, minimum k to resolve it into identity permutation is LCM of all cycle lengths.

## Square Root of a permutation 

- Define q^2 = p. Given p find q.
- Decompose into cycles. cycles can multiple independently. 
- All odd cycles have a square root. Construct!
- Two Even Cycles of same length can be combined to form a square.
- In other words every square permutation has even cycles of a certain size in pairs.
- Once you have the pairs you can form q1 * q2 = p'. p'^2 decompose into q1 and q2. Construct!

Square Root of a permutation : https://codeforces.com/contest/612/problem/E

## Counting number of permutations with inversion count k 

This problem can be solved with dynamic programming in N*K time.  </br>
Consider dp[N][K]. This denotes number of permutations with N distinct elements and K inversion count.  </br>
- Transition : dp[N][K]
- Sum { dp[N-1][1], dp[N-1][2], dp[N-1][3], dp[N-1][4], ..., dp[N-1][K-1] } </br>
- Sum { dp[N-1][J] } where K <= J + N-1 or J <= K - N + 1

Construction : 

- Consider a permutation P[1 2 3 4 ...N-1] with J inversion counts.
- Now you want to achieve K inversion count where increase = K - J.
- To the end of the array add an element which is smaller than K - J elements. Number could be fractional.
- ReMap the array to P[1...N] according to the order of the elements.
- New permutation is unique with K inversion count and can only be obtained from (N,J) uniquely.

```cpp
	ll N, K; 
	cin >> N >> K;	
	
	dp[1][0] = 1;
	for (ll j=1;j<=K;j++) dp[1][j] = dp[1][j-1]; 
	for (ll i=2;i<=N;i++){
		for (ll inversions = 0; inversions <= K; inversions++){
			ll mn = max (0LL, inversions - i + 1); 
			ll mx = inversions;
			if (mn == 0) dp[i][inversions] = dp[i-1][mx];
			else dp[i][inversions] = (dp[i-1][mx] - dp[i-1][mn-1] + mod) % mod; 
			if (inversions) dp[i][inversions] = (mod + dp[i][inversions] + dp[i][inversions-1]) % mod;
		}
	}
	
	if (!K) cout << 1 << endl;
	else cout << (mod + dp[N][K] - dp[N][K-1]) % mod;
```











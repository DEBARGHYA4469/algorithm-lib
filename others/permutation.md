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
  












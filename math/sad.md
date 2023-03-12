### Sum of Absolute Differences (SAD)

Here, I am going to discuss an interesting concept which I believe is general concept and can be used in other problems with such requirements. I learnt this while solving codechef problem SUBARRAYGAME

https://www.codechef.com/problems/SUBARRAYGAME

Basic problem: Given an array with distinct integers. Alice and Bob takes turns to remove subarrays from it such that SAD always remains same. What is the optimal strategy to win the game? 
One who cannot make a move loses.


Idea: 

**Observation - 1 (Easy to check and prove!)**

* Given an array {a[0], a[1], a[2], ..., a[N-1]}. If you remove elements, SAD decreases or remains same, conversely if you add elements, SAD increases or remains same. 

**Observation - 2 (Hard!)**

* If you remove a subarray {a[l], a[l+1], ..., a[r]}, SAD remains same iff {a[l-1], a[l], a[l+1],...,a[r], a[r+1]} is a sorted sequence. 

Proof:	
- You cannot remove prefix or suffix due to observation-1. It will always decrease SAD. 
- If the sequence, {a[l-1],a[l],a[l+1],...,a[r],a[r+1]} is sorted, it easy to see, SAD remains same = |a[r+1]-a[l-1]| 
- What happens if the sequence is not sorted? 
- Without loss of generality, assume a[l-1] < a[r+1] 
- There exists k', l<=k'<=r, a[k'-1] > a[k'], take smallest such k' (say k)
- Now, the sequence looks like {a[l-1] < a[l] < a[l+1] < ....< a[k-1] > a[k] <> ......a[r] <> a[r+1]}
- SAD(before operation) = a[k-1] - a[l-1] + a[k-1] - a[k]  + SAD(a[k]....a[r+1]) 
- SAD(before operation) > 2a[k-1] - a[l-1] - a[k] + |a[r+1]-a[k]| 
- SAD(after operation) = a[r+1] - a[l-1]. It can be proven that SAD(after operation) < SAD(before operation).
- Removing such subarrays does not work 

**Observation - 3(Medium)**
	
- Given an array {3,4,1,6,2,7,5,10,12,14,9,19}. 
- Find all such sequences from which you can extract subarrays
- In this case: {3,4}, {4,1}, {1,6}, {6,2}, {2,7}, {7,5}, {5,10,12,14}, {14,9}, {9,19}
- Notice each pile is independent and correspond to a NIM game of size pile-size - 2. (Hard observation!)
- Grundy State of the game = XOR(piles[i]-2) for all i. 


### Min and Max  XOR Value Pair

3. https://www.geeksforgeeks.org/maximum-xor-of-two-numbers-in-an-array/
4. https://www.geeksforgeeks.org/minimum-xor-value-pair/

### Some ideas for solving structures with 0 or 1 values

1. https://codeforces.com/contest/1546/problem/D 



Problem: You are given an array of 0s and 1s. Any 1 can jump over another 1 if the next spot is available. How many different arrangements can be possible? 

Solution: </br>

a. Idea 1: Os and 1s are identical. Take advantage of that fact in transformation. (Very interesting idea!) </br></br>
        Claim: All 11 pairs are always together as a entity.</br> </br>
        Proof: </br>
                ......1a 1b 1c.... </br>
                can be rearranged as </br>
                ......1c 1a 1b....</br>
                ......1c    1b 1a </br>
                can be rearranged as </br>
                ......1c    1a 1b </br>
                
(1a 1b) is always are pair. 
       
b. Given any arrangement, 10000(11)10001101, however you change the state the ones remain paired. 
Continuing the same logic, pair all the 1s possible. Eg. 10000(11)1000(11)01. So it is effectively only the pairs that move. 

c. So let there be x number of pairs. "xxx1xxx" same as "xx1xxxx". So only 0 are real separators.
                
                
                
### Some interesting properties of arrays

Problems:

* Given an array of integers [a1, a2, a3, a4....aN] and sum of array elements in even. If 2*maxm > sum of the elements of the array. Then there exists an interesting matching such that no two elements from an array elements match.
* Give them indices 1,2,3,4.....N.  
* Match i -> i + s/2. 
* Proof: if i matches j and j-i < s/2. s/2 < s/2. Contradiction. 

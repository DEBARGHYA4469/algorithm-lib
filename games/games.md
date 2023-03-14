## Games on graphs 

Each vertex is either winning or losing. A winning vertex has a outgoing edge to a losing vertex and a losing vertex has all outgoing edges to winning vertex. 

How to solve? 

- Consider the reversed graph
- If winning to undefined edge, mark it losing only if all outgoing edge in the original graph are winning 
- If losing to undefined edge, mark it winning.

O(m) solution 

## Single Pile Game 


You are given a pile of N coins, you can take {1,2,4} coins from it. What is the optimal strategy? 

From **Sprague-Grundy** theorem, grundy number for any state = mex of grundy number of all the next positions in the game. 
So, 

  - g(0) = 0
  - g(1) = 1
  - g(2) = 2 
  - g(3) = mex(g(2), g(1)) = 0 
  - g(4) = mex(g(0),g(2),g(3)) = 1 
  - g(5) = 2 

So all g(3x) are losing positions, rest are winning!


#### Why MEX? [Magic!]

- Sprague-grundy theorem says, single N-coins NIM game = single g(N)-coins NIM game. 
- Say the game also has increments but finite! 
- So you are in state N, and let k = g(N)
- So the possible next steps are {0,1,2,3...k-1,_,k+9,k+17,etc}
- If Alice makes any move to k+d, Bob can reverse the move back to k, as k+d has k as it's outgoing state. 
- So {0,1,2,..,k-1}. So it is like k-NIM game. (Inductively!)  

source : https://math.stackexchange.com/questions/2187465/why-mex-operation-in-grundy-number-calculation

## NIM 

- You have N piles of coins. A = {a1, a2, a3, a4....,aN}
- Winning Strategy:
- XOR(A) = 0. Losing, else Wining
- If XOR(A) != 0, Alice can make to 0 and Bob will always change it to some non-zero.

**Problems:**

1. https://www.codechef.com/START79B/problems/SPLITORDEC

Solution: 
 
* Consider 1 pile with x coins. 
* g(0) = 0 
* g(1) = 1
* g(2) = mex(1, xor(g(1), g(1))) = 2
* g(3) = mex(g(2), xor(g(1), g(2))) = 0
* g(4) = mex(g(3), xor(g(3),g(1)), xor(g(2),g(2))) = 2 
* g(5) = mex(g(4), xor(g(1),g(4)), xor(g(2),g(3)) = 0 
* g(6) = 2 


Prove: g(2k) = 2, g(2k+1) = 0 for k>2. Induction 

2. https://www.codechef.com/problems/TWONIM

There are n piles of stone, you can remove any pile, but you lose if opponent gets a pile with XOR = 0. 

Solution: 
  
    *   N = 0 : Winning State 
    *   N = 1:  Losing State
    *   N = 2:  Wining State
    *   N = 3:  Losing if XOR != 0 
    *   N = 4:  Winning. And if XOR != 0 you can make next player play XOR != 0. 
    
    
    Easy induction: 
         N is even, player wins! 
         N is odd, player wins only if XOR = 0. 
 
 







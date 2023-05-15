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
 
 3. https://www.codechef.com/COOK42/problems/GAMEAAM

Problem: There are n piles of pair of numbers. In one turn, pick a pile and decrease larger by some multiple of smaller. Who wins? 

Solution: 

Let's solve for one-pile then Sprague Grundy. 

* For one pile: What is the grundy value for (a,b)?
* Assume : a > b.

Strategy : 1

Construct the Grundy Table

a/b | #1 | #2 | #3 | #4 | #5 | #6 | #7 | #8 | #9 | #10 | #11
--- | --- | --- | --- |--- |--- |--- |--- |--- |--- |--- |---
1 | 0 |  |  |   |  |   |   |   |   |   |  
2 | 1 | 0  |  |   |  |   |   |   |   |   |  
3 | 2 | 0 | 0 |   |  |   |   |   |   |   |  
4 | 3 | 1 | 0 | 0 |  |   |   |   |   |   |  
5 | 4 | 1 | 1 | 0 | 0 |   |   |   |   |   |  
6 | 5 | 2 | 1 | 0 |  | 0  |   |   |   |   |  
7 | 6 | 2 | 1 | 1 |  |   | 0  |   |   |   |  
8 | 7 | 3 | 2 | 1 |  |   |   | 0  |   |   |  
9 | 8 | 3 | 2 | 1 |  |   |   |   | 0  |   |  
10 | 9 | 4 | 2 | 2 |  |   |   |   |   | 0  |  
11 | 10 | 4 | 3 |   |  |   |   |   |   |   |  
12 | 11 | 5 | 3 |   |  |   |   |   |   |   |  
13 | 12 | 5 | 3 |   |  |   |   |   |   |   |  

* From the pattern we see no clear pattern emerging. Now think if can derive the table on the fly? 
* Let SG(a % b, b) = x. 
* (a,b) transitions to (a-b,b),(a-2b,b),(a-3b,b),(a-4b,b),(a-5b,b),(a-6b,b)...(a%b, b)
* No of such transitions = floor a/b = K 
* SG Values are of form: {x, 0, 1, 2, 3, 4,...,x-1, x+1, x+2, x+3...}
* If K <= x, MEX = K-1, Else MEX = k.
* How does this help? We can piggy-back on Euclid's algorithm complexity log(min(a,b))[Fib complexity]     


 ## Strategize the game backward 
 
  Problem: Alice and Bob are playing a game in turns. There are N piles with varying number of coins. Game ends when exactly two piles are empty. Player who cannot make a move loses. Who wins if they play optimally?  
  
  https://www.codechef.com/JULY221B/problems/GAMEOFPILES2 (Hard) </br>
  **Related Puzzle**: https://www.geeksforgeeks.org/puzzle-20-5-pirates-and-100-gold-coins/
 
   Let's consider first the simple version of the game. Where player who first empties a pile wins. 
   
   Strategy:
   
        If there is a one, it's a instant win for first player (Alice!)
        None of the players will expose any 1 to the other opponent. So, losing position is [2,2,2,2,2,2,2].
        # moves required to reach to this losing position = S - (2*N). 
        So if S is odd, second player loses. 
        
   Now consider our version of the game: 
        
   Strategy:
         
        Case: 1 
                [There are at least two ones. ex. {1,1,2,2,3,4,5,6.....}]
                None of the players can touch any ones. So they play on the other values. 
                Till they are reduced after which they cannot touch them as it results in instant loss. So, the forced losition position [1,1,1,1,1,1,1]
                # moves required to reach this losing position = S - N 
                So, if (S-N) is odd, second player loses. 
                
        Case: 2
              There is exactly 1 one. ex. [1,2,2,3,3,4....]
              Alice makes the first move. He can take the one. In that case problem reduces to game 1, where second player wins if S' is even. So Alice is the second
              player, so (S-1) has to be even, S has to odd. 
              S is odd, Alice wins! 
              
              Consider S is even. 
              Case 2a: There is not two value. So Alice takes one value from any other element. 
                       Array now looks like [1,2,2,2,3,4...]. Note: It has exactly 1 one. And S' is odd. So second player (Alice) always loses. 
              Case 2b: There is a two value. So Alice takes one from it and the array now becomes [1,1,2,2,3,4....]. Now this is Case: 1
                       Second player(Alice) wins when (S-1-N) is even, i.e (S-N) is odd, otherwise, Bob wins! 
                       
         Case: 3 
              There are no ones. ex. [2,2,2,2,3,3,4,4,5....]
          
              Observation: 
              
  
                  If first pile empties after odd moves, then Bob starts the game on (S-odd) sum. And Alice loses if S-odd is odd => S = even
                  If first pile empties after even moves, then Alice starts the game on (S-even) sum. And Bob loses if S-even is odd => S = odd. or 
                  Alice loses if S is even.

                  Either way if S is even Alice loses else Bob loses. 
              
              
        
       
       





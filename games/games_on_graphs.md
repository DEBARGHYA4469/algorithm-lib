## Tree Tag 
https://codeforces.com/problemset/problem/1404/B

Idea: 

![image](https://github.com/DEBARGHYA4469/algorithm-lib/assets/21307343/bc8dc998-fdb0-469e-9cae-5487755b4c45)


1. Start checking linear graphs!
2. If V(A) >= Dist (A,B). Alice wins in first turn. (Straightforeward)
3. Assume V(A) < Dist(A,B). Bob does not move unless Alice reaches atleast V(A) distance from him, upon which if he has the ability to jump, 2 V(A) + 1, he is saved. But does he have the room?
4. Checking the room for Alice's jump is *tricky*.
    - All sorts of trees will have different structure!
    - Check diameter of the tree [Hard observation!]
5. If V(A) >= Diameter/2. Alice has a winning strategy. How?
    -  Let C be the center of the tree. So radius of the tree is atleast floor (Diamter/2).
    -  If 2*V(A) >= Diameter, V(A) >= radius. So in first turn Alice can take the center. Bob wherever goes distance from C will be less than Diamter/2. Alice can catch in next turn.
6. Assume, 2*V(A) < Diameter.
    - If 2 V(A) >= V(B), Alice has a win! Alice will shrink the subtree size for Bob by moving one step at a time towards Bob. Alice cannot move past Bob as it would require > 2 V(A) jump. 
    - Otherwise, Bob has a win.
    - Strategy:
        * Consider the center of the diameter.
        * Connect the line from Alice and Bob to the center.
          -  If Alice (IMP: *after jumping*) and Bob are on the same side of the center (assume Alice is not at the center), there is a room for Bob at least V(A) + 1 on other side the center.
          -  If Alice and Bob are on different sides of the center. Bob moves to the farther end of the line maintaining distance at least V(A) + 1.
          -  If Alice landed exactly at the center of the diamter. Then by negation of second case, there is a line with distance atleast V(A) + 1, and Alice is it distance max V(A) from Bob. So Bob can jump over.

  So basically Bob has to play leap frog with Alice. 

  ## Pigeon-Holing 

  Problem: https://codeforces.com/problemset/problem/1436/D?mobile=true

  Claim: Let r[v] = subtree children / no of leaves in the subtree. Bandit can catch r citizen where **[r]** is the max r[v] if both parties play optimally. [.] : ceil value 
  
  Proof: 

    1. A. Bandit has a strategy to catch at least **r** citizens. 
    2. B. Citizens have a strategy to restrict each leaves with <= **r** citizen. 


A. Bandit heads towards the vertex with **r** ratio and then goes to the subtree with max r value. 

* Max r will always be >= r.
* Assume all subtrees have ratio < r.
* s[i]  < r * n[i]  for all i's.
* Sum (s[i]) < r* Sum (n[i])
* Contradiction : s[v] / n[i] = r.

  ![image](https://github.com/DEBARGHYA4469/algorithm-lib/assets/21307343/569fa77f-4dcf-47a5-a31c-d6fb07740f79)
  
B.  Ref to the diagram above. 

* a[v] + s[1] + s[2] + ... s[m] <= r * (n[1] + ... + n[m]), since r[v] <= **r**
* p[i] + s[i] <= [r] * n[i]
* What is the max p[i] citizens can afford?
      - p[i]_max = [r] * n[i] - s[i].
* Is it possible to arrange themselves in this way?
* Sum of all p[i]_max >= a[v].
* That means, [r] * (n[1] + n[2] + ... + n[m]) - (s[1] + ... + s[m]) >= a[v]
* [r] * (n[1] + n[2] + ...+n[m]) >= a[v] + (s[1] + ...+ s[m]), which is true.

So optimal answer is **r**   














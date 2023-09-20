## Tree Tag 
https://codeforces.com/problemset/problem/1404/B

Idea: 

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

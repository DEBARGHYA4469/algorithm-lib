Notes for some of the non-trivial DP State Transition

[P1. Arena]  

There are n heroes in an arena. In 1 round each of the players inflict 1 unit damage on all other players. Players whos health goes below 1 are eliminated. Round continues. 
How many possible initial arrangement of healths are there such that there is no clear winner?  1 <= Health  <= x

State Transitions: 

* Game goes like n heros -> (n-e1) heros -> (n-e1-e2) heros -> .... -> 0 heros. And at no point there can be 1 hero standing. 
* If we know f(n-e1) can we derive f(n)?
* f(n) = choose e1 heros out of n heros * choices of their initial health * f(n-e1).
* If any of the e1 are selected to be eliminated in round r with initial health h, there cannot be same initial arrangement such that r gets eliminated in later than r round or previous r rounds.
* In other words, two equivalent arrangements (e1, e2, ... ).
* How to find choice of their initial health?
* We need for each round, total health spent so far = y. MAX = MIN(x, spent + (n-1)). MIN = spent + 1.
* So for each state we also need to store the spent health.
* f(n, spent) = choose e1 heros out of n heros * choices of their initial health * f(n-e1, spent + (n-1)).




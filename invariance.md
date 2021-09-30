#### Proving greedy approaches [Invariance+Extremal Principle] 

### Problem: 1  https://codeforces.com/contest/1579/problem/D

<li> Coming up with optimal solution is ez, proving it is hard. Here goes my proof. </br>
<li> <a href="https://www.codecogs.com/eqnedit.php?latex=S&space;=&space;{a_1,a_2,a_3,...,a_N}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?S&space;=&space;{a_1,a_2,a_3,...,a_N}" title="S = {a_1,a_2,a_3,...,a_N}" /></a>
<li> Case 1: If S = sum of all elements, and S/2 <= max. element. We can show that max #operations is (S-max. element). </br>
<li> Argue by showing that max element can pair with max S-max. element. Rest all can be paired fullest. We can't do better!! </br>
<li> Case 2: If S/2 > max. element we show that we can follow a process as goes below:  </br>
<li> Choose a max element from the set, and reduce it by any(random other) element from the set till it is not maximum. </br>
  Then change max element and continue. </br>
<li> Let any configuration be (S,max. ele). We only change when max. (max. ele-t) >= a[x], the new configuration is (S-2t,a[x]). </br>
<li> Invariance is: S/2 > max. ele, in the new configuration, (S-2t)/2 = (S/2-t) > max. ele-t >= a[x], hence (S-2t,a[x]) maintains invariance. </br>
<li> Only thing remaining to see is that with such a invariance condition, we can always get an operation. Hence a[x] goes to 0. </br>
<li> Ans = S/2

**A more intuitive proof for case 2**. Assume that sum of the remaining element is more than the maximum element. We claim that we can always bring down the sum of the remaining element down to the maximum element and then we are done(trivial!). Only configuration which can't be reduced is [0,0,0,0,0,x], we can't bring it down to max means x>max. which is not possible

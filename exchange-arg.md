## Exchange Argument

The basic idea behind exchange arguments is given an **optimal structure** can you convert it to a **sorted optimal structure**
based on some heuristics such that the optimality still holds.</br>

**Benifit**: For problem where we need to find the optimal structure we need to look for all permutations, we can look at the sorted 
structure and claim that each of the substructure in the sorted structure will be optimal so studying it is worth it.
Hence it reduces the time to linear.

This is the heart of many greedy and dp algorithms.

### Problem-1 (Boxes)
There are n boxes with weight wi and strength si. If one box can be placed over the other only if its weight is no greater than the strength of the bottom box.
What is the maximum possible no of boxes in the tower.

![aa](https://user-images.githubusercontent.com/21307343/131247711-a4bbdcc3-0071-4345-acbc-61b485d4ccd4.png)

Given an arrangement, under what circumstance it is always good to swap to boxes.
Let F be the force(wt) that the top of both arrangement can sustain. More the F better right!

<a href="https://www.codecogs.com/eqnedit.php?latex=\\Case:1\\&space;F&space;<&space;S_a,\:&space;F&plus;W_a<S_b&space;\implies&space;F<min(S_a,S_b-W_a)&space;\\Case:2\\&space;F&space;<&space;S_b,\:&space;F&plus;W_b<S_a&space;\implies&space;F<min(S_b,S_a-W_b)&space;\\if\:(S_a-W_b)&space;>&space;(S_b-W_a)&space;\\&space;\\F_{max}^1&space;<&space;F_{max}^2.&space;\:\:\:Proof:&space;Fix\:\:F_2\\&space;Choosing\:\:Case-II\:is\:\:optimal.&space;\\Exchange\:\:if\:\:S_a&plus;W_a&space;>&space;S_b&plus;W_b" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\Case:1\\&space;F&space;<&space;S_a,\:&space;F&plus;W_a<S_b&space;\implies&space;F<min(S_a,S_b-W_a)&space;\\Case:2\\&space;F&space;<&space;S_b,\:&space;F&plus;W_b<S_a&space;\implies&space;F<min(S_b,S_a-W_b)&space;\\if\:(S_a-W_b)&space;>&space;(S_b-W_a)&space;\\&space;\\F_{max}^1&space;<&space;F_{max}^2.&space;\:\:\:Proof:&space;Fix\:\:F_2\\&space;Choosing\:\:Case-II\:is\:\:optimal.&space;\\Exchange\:\:if\:\:S_a&plus;W_a&space;>&space;S_b&plus;W_b" title="\\Case:1\\ F < S_a,\: F+W_a<S_b \implies F<min(S_a,S_b-W_a) \\Case:2\\ F < S_b,\: F+W_b<S_a \implies F<min(S_b,S_a-W_b) \\if\:(S_a-W_b) > (S_b-W_a) \\ \\F_{max}^1 < F_{max}^2. \:\:\:Proof: Fix\:\:F_2\\ Choosing\:\:Case-II\:is\:\:optimal. \\Exchange\:\:if\:\:S_a+W_a > S_b+W_b" /></a>

### Problem-2  (Hero)

Hero has to fight some monsters. Fighting with each monster takes d[m] health and after monster dies, hero gets back a[m] 
health in the form of a potion. What is the min health to start the fight?

**Observation:**
<li> Lets call monsters whose d[i] > a[i] as bad others as good.
<li> Always good to exchange a good monster with a bad one if bad occurs early. If he started with H health, to fight good
one he will need d[good] and to fight bad one he has H-d[good]+a[good]=H+t(t>0). In the other case if he starts with H health, 
he fights bad one with H(less) and good with H-d[bad]+a[bad]=H-t. Both cases he loses. So good to exchange.
<li> Among the good ones, consider if a good monster A appears before a good monster B. 
<a href="https://www.codecogs.com/eqnedit.php?latex=\\H_1&space;>&space;max(d_A,d_B&plus;d_A-\alpha_A),\:\:\:d_A-\alpha_A<0&space;\\H_2&space;>&space;max(d_B,d_A&plus;d_B-\alpha_B),\:\:\:d_B-\alpha_B<0&space;\\if\:\:d_B<d_A:&space;H_{1,min}=d_A,&space;H_{2,min}&space;<&space;H_{1,min}.\:\:Exchange!!" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\H_1&space;>&space;max(d_A,d_B&plus;d_A-\alpha_A),\:\:\:d_A-\alpha_A<0&space;\\H_2&space;>&space;max(d_B,d_A&plus;d_B-\alpha_B),\:\:\:d_B-\alpha_B<0&space;\\if\:\:d_B<d_A:&space;H_{1,min}=d_A,&space;H_{2,min}&space;<&space;H_{1,min}.\:\:Exchange!!" title="\\H_1 > max(d_A,d_B+d_A-\alpha_A),\:\:\:d_A-\alpha_A<0 \\H_2 > max(d_B,d_A+d_B-\alpha_B),\:\:\:d_B-\alpha_B<0 \\if\:\:d_B<d_A: H_{1,min}=d_A, H_{2,min} < H_{1,min}.\:\:Exchange!!" /></a>
<li> Among the bad ones, consider if a bad monster A appears before a bad monster B. 
<a href="https://www.codecogs.com/eqnedit.php?latex=\\H_1&space;>&space;max(d_A,d_B&plus;d_A-\alpha_A),\:\:\:d_A-\alpha_A>0&space;\\H_2&space;>&space;max(d_B,d_A&plus;d_B-\alpha_B),\:\:\:d_B-\alpha_B>0&space;\\if\:\:d_B<d_A:&space;H_{2,min}=&space;d_A&plus;d_B-\alpha_B\\&space;Exchange\:\:if\:d_B&plus;d_A-\alpha_A>d_A&plus;d_B-\alpha_B&space;\implies&space;\alpha_B>\alpha_A\\&space;if\:\:d_B>d_A:&space;H_{1,min}=&space;d_B&plus;d_A-\alpha_A\\&space;Exchange\:\:if\:d_B&plus;d_A-\alpha_A>d_A&plus;d_B-\alpha_B&space;\implies&space;\alpha_B>\alpha_A\\&space;So,\:exchange\:if\:\:&space;\alpha_B&space;>&space;\alpha_A" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\H_1&space;>&space;max(d_A,d_B&plus;d_A-\alpha_A),\:\:\:d_A-\alpha_A>0&space;\\H_2&space;>&space;max(d_B,d_A&plus;d_B-\alpha_B),\:\:\:d_B-\alpha_B>0&space;\\if\:\:d_B<d_A:&space;H_{2,min}=&space;d_A&plus;d_B-\alpha_B\\&space;Exchange\:\:if\:d_B&plus;d_A-\alpha_A>d_A&plus;d_B-\alpha_B&space;\implies&space;\alpha_B>\alpha_A\\&space;if\:\:d_B>d_A:&space;H_{1,min}=&space;d_B&plus;d_A-\alpha_A\\&space;Exchange\:\:if\:d_B&plus;d_A-\alpha_A>d_A&plus;d_B-\alpha_B&space;\implies&space;\alpha_B>\alpha_A\\&space;So,\:exchange\:if\:\:&space;\alpha_B&space;>&space;\alpha_A" title="\\H_1 > max(d_A,d_B+d_A-\alpha_A),\:\:\:d_A-\alpha_A>0 \\H_2 > max(d_B,d_A+d_B-\alpha_B),\:\:\:d_B-\alpha_B>0 \\if\:\:d_B<d_A: H_{2,min}= d_A+d_B-\alpha_B\\ Exchange\:\:if\:d_B+d_A-\alpha_A>d_A+d_B-\alpha_B \implies \alpha_B>\alpha_A\\ if\:\:d_B>d_A: H_{1,min}= d_B+d_A-\alpha_A\\ Exchange\:\:if\:d_B+d_A-\alpha_A>d_A+d_B-\alpha_B \implies \alpha_B>\alpha_A\\ So,\:exchange\:if\:\: \alpha_B > \alpha_A" /></a>
 
```cpp
  void comparator(Monster &m1,Monster &m2){
        if(m1 is good && m2 is good){
              return m1.damage < m2.damage;
        }
        else if(m1 is good && m2 is bad){
              return 1;
        }
        else if(m1 is bad && m2 is good){
              return 0;
        }
        else if(m1 is bad && m2 is bad){
              return m1.health > m2.health;
        }
  }
```

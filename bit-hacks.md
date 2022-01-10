## Bit Operations

If A,B are two bitmasking sets: 
<li> Set union: A|B
<li> Set intersection: A&B
<li> Set negation: ALL_BITS^A
<li> Set off last element of the set: A = A&(A-1)
  
Built-in function </br>
  
Count Set bits of a number : __builtin_popcount(), __builtin_popcountll()

##### Errichto's Lecture
1. Consider this problem: There are N≤5000 workers. Each worker is available during some days of this month (which has 30 days). For each worker, you are given a set of numbers, each from interval [1,30], representing his/her availability. You need to assign an important project to two workers but they will be able to work on the project only when they are both available. Find two workers that are best for the job — maximize the number of days when both these workers are available.
</br></br>
For two workers w1 and w2, intersection is `mask[w1] & mask[w2]`. Time Complexity = O(N^2) </br>
What if the workers are working for D days. Then mask size will be D and int size = 2^D which only ll can hold. Beyond that you need to partition the bits.
Partioning is ugly.</br>

Nice solution : **BITSETS**

<li>bitset<365> v;
<li>v.count(): hamming weight

https://en.cppreference.com/w/cpp/utility/bitset
  
**Sum-Xor property**</br></br>
  <a href="https://www.codecogs.com/eqnedit.php?latex=\\A&space;&plus;&space;B&space;=&space;A|B&space;&plus;&space;A\&B\\&space;A&plus;B=A\oplus&space;B&space;&plus;&space;2(A\&B)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\A&space;&plus;&space;B&space;=&space;A|B&space;&plus;&space;A\&B\\&space;A&plus;B=A\oplus&space;B&space;&plus;&space;2(A\&B)" title="\\A + B = A|B + A\&B\\ A+B=A\oplus B + 2(A\&B)" /></a>
  
  #### Greedy Bitwise
  
  For problems related to maximising or minimization some bitwise SUM/PRODUCT, go bitwise from MSB TO LSB greedily.

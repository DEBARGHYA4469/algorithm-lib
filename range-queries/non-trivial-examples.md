Some non-trivial ideas for RMQs and RSQs 

1. https://codeforces.com/contest/220/problem/B

Problem: Given an array and a range [l...r]. How many integers x is in the range such that frequency of x is x? 

Let's say you are in index r. The difference array for any integer x to queries ending at r will look like below: 

..................x(x+2)..x(x+1)..x(x).....x......x(2)......x(1)..................r </br>
.................... 0.............-1 ............1..............................................r

Updates: 

    - 0 -> 1 for xth index = +1 
    - 1 -> -1 for x+1th index = -2 
    - -1 -> 0 for x+2th index = +1 
    
Use fenwick tree or segment tree for the updates. Sum of the difference arrays l...r will give the answer for l...r. 

##### Table of Contents  
[Custom Ceil Function](#a)
[Lazy Caterer](#b) 
[Chinese Remainder Theorem](#c) 
[Derangement](#d) 
[Chicken Mcnugget Theorem](#e) 
[Erdos Szekeres Theorem](#f) 
[Cyclicity](#g)
[Parity of Permutation](#h) 
[Rank in Arbitrarty Bases](#i) 
[Floyd Cycle](#j) 
[Manhattern Trick](#k) 
[Subsequence to Subarray Transformation Trick](#l)
[Complexity of Euclid's dvision Lemma](#o)
[Difference Array, Sort, Repeat](#p)
[Hockey Stick Identity](#q)
[Catalan Number](#r)
[Stirling Number of Second Kind](#s)
[Stars and Bars](#t)

# Custom Ceil function

```cpp
    inline int ceildiv(int a,int b){
          if(a==0) return 0;
          else return (a-1)/b+1;
    }
```

# Lazy Caterer

`F[N] = F[N-1] + N`

Intuitive explaination: You can assume some lines N already existing. </br>
![image](https://user-images.githubusercontent.com/21307343/131888317-c7031dcf-2d97-461a-9f0c-a2e184f85cb9.png)
</br>
Any line intersecting at two points cuts that plane into two halves. To get max cutting we need to cut all the existing lines.</br>
Consider a line far away(pink) which intersects with all the lines N(all diverging and sorted by slopes increasing). So maximum cuts increases by (N-1) + 2(open spaces) i.e `F[N+1] = F[N] + N+1`. Hence this is optimal proven. </br>

Now coming to cake cutting problem, since this construction exists, we can zoom(scale in) out everything and fit in the cake geometry. 

# Chinese Remainder Theorem


If Alice has x number of apples such that she can divide the apples in mi groups with ri remaining, for some i's. What is the minimum no of apples she posses?</br>

<a href="https://www.codecogs.com/eqnedit.php?latex=\\x&space;=&space;r_1&space;(mod\:\:m_1)\\&space;x&space;=&space;r_2&space;(mod\:\:m_2)\\&space;x&space;=&space;r_3&space;(mod\:\:m_3)\\&space;\\&space;What\:is\:the\:min\:x?" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\x&space;=&space;r_1&space;(mod\:\:m_1)\\&space;x&space;=&space;r_2&space;(mod\:\:m_2)\\&space;x&space;=&space;r_3&space;(mod\:\:m_3)\\&space;\\&space;What\:is\:the\:min\:x?" title="\\x = r_1 (mod\:\:m_1)\\ x = r_2 (mod\:\:m_2)\\ x = r_3 (mod\:\:m_3)\\ \\ What\:is\:the\:min\:x?" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=\\&space;Garner's\:\:Algorithm&space;\\&space;a&space;=&space;x_1&space;&plus;&space;x_2m_1&plus;x_3m_1m_2&plus;x_4m_1m_2m_3&plus;...&plus;x_Nm_1m_2m_3...m_{N-1}&space;\\let\:\:y_1=x_1,&space;y_2&space;=&space;x_1&space;&plus;&space;x_2m_1,&space;y_3&space;=&space;x_1&space;&plus;&space;x_2m_1&plus;x_3m_1m_2,...&space;\\&space;x_1&space;=&space;r_1&space;\\&space;x_2&space;=&space;(r_2-x_1)m_1^{-1}&space;\\&space;x_N&space;=&space;(r_N-y_{N-1})(m_1m_2...m_{N-1})^{-1}\:(mod\:\:m_N)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\&space;Garner's\:\:Algorithm&space;\\&space;a&space;=&space;x_1&space;&plus;&space;x_2m_1&plus;x_3m_1m_2&plus;x_4m_1m_2m_3&plus;...&plus;x_Nm_1m_2m_3...m_{N-1}&space;\\let\:\:y_1=x_1,&space;y_2&space;=&space;x_1&space;&plus;&space;x_2m_1,&space;y_3&space;=&space;x_1&space;&plus;&space;x_2m_1&plus;x_3m_1m_2,...&space;\\&space;x_1&space;=&space;r_1&space;\\&space;x_2&space;=&space;(r_2-x_1)m_1^{-1}&space;\\&space;x_N&space;=&space;(r_N-y_{N-1})(m_1m_2...m_{N-1})^{-1}\:(mod\:\:m_N)" title="\\ Garner's\:\:Algorithm \\ a = x_1 + x_2m_1+x_3m_1m_2+x_4m_1m_2m_3+...+x_Nm_1m_2m_3...m_{N-1} \\let\:\:y_1=x_1, y_2 = x_1 + x_2m_1, y_3 = x_1 + x_2m_1+x_3m_1m_2,... \\ x_1 = r_1 \\ x_2 = (r_2-x_1)m_1^{-1} \\ x_N = (r_N-y_{N-1})(m_1m_2...m_{N-1})^{-1}\:(mod\:\:m_N)" /></a>

Proof: https://cp-algorithms.com/algebra/chinese-remainder-theorem.html

`How to calculate modulo inverse mod some coprime number?`</br>

```cpp
inline ll mod(ll x,ll m){ return (x%m+m)%m; }

ll extgcd(ll a,ll b,ll &x,ll &y){
      if(b==0){
          x=1ll;
          y=0ll;
          return a;
      }
      ll x1,y1;
      ll g = extgcd(b,a%b,x1,y1);
      x = y1;
      y = x1 - y1*(a/b);
      return g;
}

inline ll inv(ll a,ll m){
            ll x,y;
            ll g = extgcd(a,m,x,y); 
            assert(g==1);
            return mod(x,m);
    }

inline ll crt(ll r[],ll m[]){
		ll y[10],p[10];
		y[0] = r[0]; p[0] = 1;
		
		for(int k=1;k<N;k++){
				p[k] = p[k-1]*m[k-1];
				ll q = inv(p[k],m[k]);
				y[k] = mod(y[k-1]+(r[k]-y[k-1])*q*p[k],p[k]*m[k]);
			}
		return y[N-1];
}
```

# Derangement

Solving permutation with fixed points k or more: N! - Sum{D(N,k)} k = 0...K-1 https://en.wikipedia.org/wiki/Rencontres_numbers and calcuate.

<li> D[N] =  (N-1)(D[N-1]+D[N-2])

# Chicken McNugget Theorem

Ref : https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem
https://brilliant.org/wiki/postage-stamp-problem-chicken-mcnugget-theorem/
 
If there are two number a,b which are relatively prime, the greatest number which can be represented using a & b is (a-1)(b-1)+1.

Also exactly half of them 1 to ab - a -b is representable and half is not. 
And if the numbers are not coprime just divide by gcd (a,b). pattern will be multiple of gcds. 
Also exactly one of (k, ab-a-b-k) is representable.
 
# Erdos Szekeres Theorem

	
If there are ab+1 elements in a sequence then there always exits a monotonic increasing subsequence or decreasing subsequence of length a. </br>
Hint : (x[i],y[i]) Consider at each point #monotonic increasing sequence vs #monotonic decreasing sequence.
 

* Given a sequence of some numbers find what is the min size of the sequence so that it has increasing/decreasing sequence of length k. 
let a[i],b[i] be longest increasing/decreasing subsequence till i including x[i]. Then claim that no two tuple exists (a[i],b[i]) & (a[j],b[j]) s.t a[i]=a[j] and b[i]=b[j]. So total distinct tuples: (k-1)x(k-1), we need a sequence of (k-1)x(k-1)+1

# Cyclicity

https://codeforces.com/contest/1367/problem/E

![image](https://user-images.githubusercontent.com/21307343/142450332-ebf17b94-a154-4307-afef-b31d9a364158.png)


# Parity of Permutation:

<li> https://www.geeksforgeeks.org/number-of-transpositions-in-a-permutation/
<li> https://www.geeksforgeeks.org/even-and-odd-permutations-and-their-theorems/

Idea: Parity of permutation does not change after doing three cycle swaps. So if starts with parity=0, you can reach sorted permutation as parity of permutation=parity of inversion count.</br>

Proof:</br> 
    * [abc] after 3 cycle sort is [bca].
    * [abc]--->[bac]---->[bca]. Parity=+(1+1)%2=0
    * Each adjacent swaps changes inversion count by 1.
    
* Problem: https://codeforces.com/contest/1585/problem/D

# Rank in Arbitrary Bises


Lets say the wts of the groups be given as:   (w8|w7|w6|w5|w4|w3|w2|w1|w0)

What is the representation of the rank=x element?
rank is calulated from 1 but we calculate from 0, so x=x-1.

* Horner-type representation: 
Rep(x)= x8*(w7*w6*....*w0)+x7*(w6.....w0)+x6*(w5.....w0)+x5*(w4.....w0)+...+x0*1

How to get the vector <x8,x7,....x0>?

**Algorithm:** 

x0 = x % w0 ---> x/=w0
x1 = x % w1 ---> x/=w1.... and so on!

# Floyd Cycle

![image](https://user-images.githubusercontent.com/21307343/151416181-5eea8fa1-905b-4511-9132-3d96ff92bc38.png)


# Manhatten Trick

Also called 45 degree rotation trick, given any Manhatten metric convert it to Chebyshev metric.
|x| = max(x,-x) </br>
dist(x1,x2) = |x1-x2|+|y1-y2| = max(x1-x2,x2-x1) + max(y1-y2,y2-y1) = **max(x1+y1-x2-y2,x1-y1-x2+y2,-x1+y1+x2-y2,-x1-y1+x2+y2)**

Given a specific point, to find closest or farthest distance from it:

> ans= max(dist(x0, x)) = max(max(x0+y0-x-y,x0-y0-x+y,-x0+y0+x-y,-x0-y0+x+y))) = max(x0+y0-min(x+y),x0-y0-min(x-y),-x0+y0+max(x-y),-x0-y0+max(x,y))

Practice problems: 
> https://codeforces.com/contest/1979/problem/E


# Subsequence -> Subarray (Pref Sum)


Given a signed (+/-) operation in subsequence, it can be converted to contiguous operation in prefix sum array and prove it is a bijection. Operation in pref sum world is tractable and easier to solve. Cool transformation trick. 

Eg. https://codeforces.com/problemset/problem/1775/E

# Complexity of Euclid's Division Lemma


* Start with gcd(a,b).
* After one step, (a%b, b)
* After second step, (b%(a%b), a%b)
* Initial Sum = a + b
* Final Sum = (a%b) + (b%(a%b)) = c + d
* c + bk = a => a > c + b
* d + ck = b => b > d + c
* a + b > c + d + d + b
* a + b > c + d + d + c 
* a + b > 2 (d+c)
* d + c < (a+b)/2 
* After two rounds of the algorithm sum of a+b halves. So logarithm time 

Another cute way of looking at the complexity: 

* Consider a = Fibo[N], b = Fibo[N-1]
* Worst Case when a = Fibo(N), b = Fibo(N-1) and  the algorithm goes like:
* (f(n), f(n-1)) -> (f(n)-f(n-1), f(n-1)) -> (f(n-1), f(n-2)) ----> 1 
* f(n) = phi ^ n : Bennet's formula
* n = log(f(n)) or n = log(min(a,b)) 

* Trivia: GCD(Fibo(N), Fibo(N-1)) = Fibo(GCD(N,N-1)) = Fibo(1) = 1 Proof: 
* https://www.cut-the-knot.org/arithmetic/algebra/FibonacciGCD.shtml

# Difference Array, Sort, Repeat


This is cool complexity trick I learnt while solving https://codeforces.com/contest/1707/problem/B.

Claim: After some iteration, non-zero elements will perish! Let's say after k operations on the array, there will be m non-zero element. 

Proof:
* [1,1,1,1,1,1] <- [1,2,3,4,5,6..] <- [1,3,6,10,15,21] <- [1,4,10,20,35..] and so on.
* After k times inverting, the largest element is at least m * (m+1) * (m+2) * (m+3) * ....(m+k-1) / k! = Choose(m + k - 1, k) 

https://en.wikipedia.org/wiki/Tetrahedral_number

* That means the largest number should be at least m^k/k^k ~ (m/k) ^ k.
* Given any sequence of n numbers, it will rapidly reduce the number of non-zero elements.
* Take k = log A, gives m = log A.
* Complexity : O(nlogn * log A).
* Based on limits of n and A bound can further be reduced to O(nlogA).

Other ideas here: 

(Imp) Idea : BITWISE proofs (ref: [aryanc403](https://discuss.codechef.com/t/array-ops-editorial/100450/5)):

* Consider MSB of all numbers. Call it M1.
* After 1st iteration at most one element can have M1 turned on!. Say x1. 
* After 2nd iteration at most two element can have M2 turned on!. x1, x2. All other numbers M2 will be turned off.
* After 3rd iteration at most three element can have M3 turned on!. x1, x2, x3. All other will have M3 turned off. 
* Let the numbers of iteration K be log A.
* So after log A iterations, at most log A elements have at least 1 bit turned off, rest of the elements will be 0.
* Hence after log A iteration, log A non-zero element remains!

# Prime and Perfect Squares 

Main Idea : Even powers of primes in a number neutralize in the whole process among themselves. Consider only prime factors ^ (power % 2) for the problems. 

# Hockey Stick Identity 

C(r,r) + C(r+1,r) + C(r+2,r) + C(r+3,r) + ... + C(N,r)  = C(N+1,r+1) 

# Catalan Number 

Catalan (N, K) = INV(binpow (N+1)) * Choose (2 * N, N) 

Catalan number comes up in problems involving producer and consumer, say a consumer can only come when there is a producer. Like counting bracket balancing sequences, ants going up to the matrix top without crossing diagonal etc.

For more review dp/catalan.md file. 

Example: 
https://www.codechef.com/problems/CNTISFN343

# Stirling Number of Second Kind 

Number of ways of distributing N distinguishable objects into K indistinguishable bins. 

Nth item can be kept as a singleton or not. 

Transition:  ```F(N, K) = F(N - 1, K - 1) + K * F(N - 1, K - 1)```

# Stars and Bars Method 

Many combinatorial problem can be reduced to stars and bars method. 
Consider the problem where you need to find number of combinations of k elements in an array such that no two elements are adjacent. 

Well, try to see the structure. 

......x....x....x.x..x.......x.x....

It is like there should be at least one dots between two crosses. 
Consider r[1] + r[2] + ... + r[k+1] = N - K where, r[1] >= 0, r[k + 1] >= 0 and other 
r[i] >= 1. Can you reduce this to a stars and bars problems? 

Sum ... r[i] = N - K - (K - 1)
Sum ... r[i] = N - 2K + 1, where r[i] >= 0. 

Number of possibilities = C (N - 2K + 1 + K, K) = C(N - K + 1, K). 
Topics

1. Largest Rectangle in a Histogram
2. Intermediate Value trick
3. Job Sequencing
4. A Binary Search trick
5. Frequency of a element in a range
6. Upperbound and Lowerbound on tuples
7. Change of slope trick
8. Linear Transformation trick
9. Median Problems

### Largest Rectange in a Histogram

A = {H1, H2, H3,...,HN-1,HN}. 

```cpp

      void solve(vector<int> &H){
            H.eb(0);
            int n = sz(H);
            stack<int> s;
            s.push(H[0]);
            int i=0;
            while(i<n){
                  if(s.empty() or H[s.top()]<=H[i]) s.push(i++);
                  else{
                        int y = s.top();
                        s.pop();
                        int height = H[y];
                        int width = s.empty() ? i : i-s.top()-1;
                        ans = max(ans, height*width);
                  }
            }
      }
```

### Intermediate Value Property:
Take max and min and increase that. Check the distance between two consecutive points. Observe the interval
eg. https://codeforces.com/contest/1695/submission/164965524

### Job Sequencing  
https://www.geeksforgeeks.org/job-sequencing-problem/ (Nice. nlogn solution using Max Heap)

### Nice Binary Search Trick:

Problem : Given a matrix whose elements are taken as a combination from a array i.e M[i][j] = a[i] op a[j]. How do you find max sum taking m elements from the matrix? 

Solution Idea: Lets fix, min pair sum in the final list i.e a[i] + a[j] and maximize over it using Binary Search s.t total such element >= m (monotonic function). So now we got mid <= a[i] + a[j] for all i,j present in the optimal list. Observe (mid + 1) cannot deliver >= m elements. So we should take all elements greater than (m+1) and fill the remaining with pair sum = mid. Why does this work? 

With pair sum = mid, observe [p1, p2, p3, p4, ..... pH] where H>=m elements.
With pair sum = mid + 1, observe [q1, q2, q3, ....qJ] where J < m elements.

Also set Q is suffix of set P. So all extra elements cannot be mid + 1, as max sum element is J. But we can greedily say there are (m-J) elements with pair_sum = mid from the set P. 

### Find frequency of any element in a given range 

Given any array [a[1], a[2], a[3], a[4], ....a[N]], an element val and a given range [l...r]. What is the frequency of val in [l..r]?

Ans : Create a array of vectors g[val] -> vector<int> {}. Now frequency(l,r,val) = upper_bound(all(g[val]),r) - lower_bound(all(g[val]),l).

### Find how many elements are there between l and r in an array 

Ans : lower_bound (r+1) - lower_bound (l) 

### Upperbound and Lowerbound on Tuples

For type = pair<int, pair<int,int>> 

vector<type> a;

UB = upper_bound(all(a), mp(target, mp(INF, INF)));

LB = lower_bound(all(a), mp(target, mp(-INF, -INF))); 

1. First Element > target : UB == a.end() ? ABSENT: (*UB), idx = UB-a.begin();  
2. First Element >= target : LB == a.end() ? ABSENT : (*LB), idx = LB-a.begin();
3. Last Element <= target : UB != a.begin() ? *(--UB): ABSENT

Problems:
      - https://codeforces.com/problemset/problem/1852/A (Ntaris's set, Nice Idea with backward simulation)

### Change of slope trick 

For problems, where there are multiple linear graphs with varying slope and your result is a sum of all such graphs, say ans = g1(x) + g2(x) + ... + gm(x). 
If you need to iterate across n points and find the value of the function at n points, brute force approach is calculate for each point, value of each function, so total complexity is O(n*m). 

You can optimize this by observing that ans[i] has correlation with ans[i-1] in terms of how slopes changes. In general if the functions are perfectly linear, you could store m_total = m_1 + m_2 + m_3 + m_4 ... m_N. In each iteration i you can just increase the value by m_total. 

Now if the slopes for each of g_i changes at some point, mark the "inflection" points and how the slope changes. When you are at the inflection point change the value accordingly. In general to achieve this store two maps:

- change_of_slope[p] (at point p)
- slope[p] (current slope)
- val [p] = val [p-1] + slope [p]
- slope[p+1] = slope [p] + change_of_slope[p].

Ex. https://atcoder.jp/contests/abc268/tasks/abc268_e

### Linear Transformation trick

Some problems become more tractable if you just change the origin, or perform a linear transformation.

* Average trick:
   - Lets say a in a graph it is asked to max/min the average of the path weights. 
     i.e (w[1] + w[2] + w[3] ... + w[k])/k 
   - You can consider S*k = w[1] + w[2] + .... + w[k] 
   - (w[1] - S) + (w[2] - S) + ... + (w[k] - S) = 0.
   - Transform each edge weight w[i] -> w[i] - S. Find if a path with sum = zero exist. 
* Other cases:       
   - Say you are given, a process where you are to replace every x in the array {x} with y,z such that y + z = x + k.
   - You could just tranform x -> x' s.t x' = x + d so that the constant vanishes. 
   - In this example d = -k. In doing so, problem simplifies to replace x' with y',z' s.t y'+z' = x'. 

Ex. https://codeforces.com/contest/1909/problem/D 

### Median Problems 

For problems where you need to replace a segment of an array with its median, it is sometimes good to transform the array into boolean form. 
Consider any element x. If at last you need x in the array then all elements less than x are sort of equivalent and all elements more than x are equivalent. Also after transforming the array into 0s and 1s (elements >= x), array can be further compressed. 010 can be compressed to 0 without affecting 0, 1 count. So finally what remains is a snake pattern 0101010101 which is irreducible.

https://www.codechef.com/problems/OPME
 

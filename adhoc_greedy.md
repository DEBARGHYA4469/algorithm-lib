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



### Good Adhoc Problems:

- https://codeforces.com/contest/1582/problem/D [Nice Observation]
- https://codeforces.com/problemset/problem/343/C [Greedy+Binary Search]
- https://leetcode.com/problems/maximum-building-height/ (Greedy Stays Ahead!)
- https://www.geeksforgeeks.org/minimum-increment-decrement-to-make-array-elements-equal/



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



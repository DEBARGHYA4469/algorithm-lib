Largest Rectange in a Histogram

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


https://leetcode.com/problems/maximum-building-height/ (Greedy Stays Ahead!)

https://www.geeksforgeeks.org/minimum-increment-decrement-to-make-array-elements-equal/

Good Adhoc Problems:
* https://codeforces.com/contest/1582/problem/D [Nice Observation]
* https://codeforces.com/problemset/problem/343/C [Greedy+Binary Search]


Intermediate Value Prop: Take max and min and increase that. Check the distance between two consecutive points. Observe the interval
eg. https://codeforces.com/contest/1695/submission/164965524

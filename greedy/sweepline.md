
* Pair with minimum Euclidean Distance 
Idea: https://codeforces.com/blog/entry/58747

```cpp
ll closestPair(vector<pair<int,int>> pts){
  int n = pts.size();
  sort(pts.begin(),pts.end()); // sort by x coordinate
  set<pair<int,int>> s; // sort by y coordinate
  
  ll ans = 1e18;
  
  int last=0;
  for(int i=0;i<n;i++){
    int d = ceil(sqrt(ans));
    while(pts[i].fi-pts[last].fi>=d){
      s.erase({pts[last].se,pts[last].fi});
      last+=1;
    }
    auto y_start = s.lb({pts[i].se-d,pts[i].fi});
    auto y_end = s.ub({pts[i].se+d,pts[i].fi});
    
    for(auto j=y_start;j!=y_end;++j){
        int dx = pts[i].fi - j->se;
        int dy = pts[i].se - j->fi;
        ans = min(ans,1ll*dx*dx+1ll*dy*dy));
    }
    s.insert({pts[i].se,pts[i].fi});
}
```

* Klee algorithm

Given starting and ending positions of segments on a line, the task is to take the union of all given segments and find length covered by these segments.

```cpp
    int union_segments(const vector<pair<int,int>> &A){
          vector<pair<int,int>> p;
          for(int i=0;i<sz(A);i++){
              p.eb(mp(A[i].fi,-1));
              p.eb(mp(A[i].se,1));
          }
          
          sort(all(p));
          int ans=0;
          
          int run=0;
          for(int i=0;i<2*n;i++){
              if(run) ans = p[i].fi - p[i-1].fi;
              if(p[i].se==-1) run++;
              else run--;
          }
          return (int)ans;
    }
```

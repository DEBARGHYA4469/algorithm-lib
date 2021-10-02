## Coordinate Compression

* Technique 1 

```cpp
    vector<pair<int,int>> A; // A: original ranges
    vector<int> points;
    for(auto [s,e]:A){ 
        points.eb(s);
        points.eb(e);    
    }
    sort(all(points));
    points.erase(unique(all(points)),points.end());
    
    map<int,int> coord;
    
    for(int i=0;i<sz(points);i++) coord[points[i]]=i;
    
    sort(all(A));
    for(auto [s,e]:A){
        int comp_s = coord[s], comp_e = coord[e];
    }
```

* Technique 2 

` Counter way: but this is a little tedious`

eg. https://codeforces.com/contest/102/submission/130560359

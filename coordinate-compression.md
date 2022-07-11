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


* Major Pitfall: lets say there are three segments, [1, 2] , [2, 10] , [10, 100]. Now if you use plain compression you get [1, 2], [2, 3], [3, 4]. So [2, 3] sort of becomes redundant as it is not covering any distinct integer points. Hence always consider one up/ one down each coordinate. like include l-1, r+1 in the compression algorithm.  

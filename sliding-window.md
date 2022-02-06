
Resource : https://usaco.guide/gold/sliding-window?lang=cpp

### Template Code for sliding window 

eg.https://codeforces.com/contest/1611/problem/F [variable-sized window]

https://codeforces.com/contest/514/problem/D [Very Good Example]

How to apply sliding window generically? 

```cpp
    for(int l=0,r;l<n;l++){ // left boundary of the sliding window
        r = max(r, l-1);
        while(r+1 < n){
            // check if the boundary is extendible
            if extendible? 
                modify window 
                r++;
            else 
                break;
        }
        
        if(chmax(max_length, r-l+1)){
            // record answer from window
        }
        
        // modify window to delete left boundary to proceed to the next. 
    }
```

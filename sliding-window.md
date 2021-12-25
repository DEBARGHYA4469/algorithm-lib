
Resource : https://usaco.guide/gold/sliding-window?lang=cpp

### Template Code for sliding window 

eg.https://codeforces.com/contest/1611/problem/F [variable-sized window]

```cpp
    int r=-1;
    ll window=0;
    for(int l=0;l<N;l++){
        while(r+1<n && window+a[r+1]>=0) window+=a[++r];
        chmax(ans,r-l+1);
        window-=a[l];
    }
```

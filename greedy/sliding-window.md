
Resource : https://usaco.guide/gold/sliding-window?lang=cpp

### Template Code for sliding window 

eg.https://codeforces.com/contest/1611/problem/F [variable-sized window]

https://codeforces.com/contest/514/problem/D [Very Good Example]

How to apply sliding window generically? 

```cpp
    for(int l=0,r=-1;l<n;l++){ // left boundary of the sliding window
        r = max(r, l-1);
        while(r+1 < n){
            // check if the boundary is extendible
            // temporarily modify the window
	    if extendible? 
                modify window 
                r++;
            else 
		rollback window 
                break;
        }
        
        if(chmax(max_length, r-l+1)){
            // record answer from window
        }
        
        // modify window to delete left boundary to proceed to the next. 
    }
```

* Interesting Technique 
* eg. https://codeforces.com/contest/367/problem/B
Building a subarray element in a running fashion and comparing it with another array


```cpp
void addwindow(int v){
	int &tmp = freq[v];
	if(!tmp) zeros--;
	tmp--;
	if(!tmp) zeros++;
}

void subwindow(int v){
	int &tmp = freq[v];
	if(!tmp) zeros--;
	tmp++;
	if(!tmp) zeros++;
}
```

https://codeforces.com/problemset/problem/6/E [Nice]

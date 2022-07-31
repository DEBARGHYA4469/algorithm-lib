# Ternery-Search

![image](https://user-images.githubusercontent.com/21307343/142763401-0d3203ac-3e72-4e29-a04f-a4ee820de117.png)

[Tutorial on Tof](https://codeforces.com/blog/entry/60702)

#### To Do Problems

* https://codeforces.com/contest/1359/problem/C
* https://www.spoj.com/problems/KOPC12A/
* https://codeforces.com/problemset/problem/439/D
* https://codeforces.com/problemset/problem/578/C
* https://codeforces.com/problemset/problem/185/B
* https://codeforces.com/problemset/problem/939/E
* https://codeforces.com/problemset/problem/865/B
* https://codeforces.com/problemset/problem/250/D
* https://codeforces.com/problemset/problem/1355/E [Analytical/ Ternery Search]
* https://codeforces.com/contest/626/problem/E


[Restoration Distance] 	

```cpp

int main(){
		
		std::ios::sync_with_stdio(false);
		cin.tie(0);
		
		int n,a,r,m;
		cin >> n >> a >> r >> m;
		int h[n];
		ll pref[n];
		for(int i=0;i<n;i++) cin >> h[i];
 
		sort(h,h+n);;
		for(int i=0;i<n;i++){
			if(!i) pref[i]=h[i];
			else pref[i]=pref[i-1]+(ll)h[i];
		}
 
		auto check=[&](ll H)->ll{
			int idx=upper_bound(h,h+n,H)-h;
			ll na=idx? H*idx-pref[idx-1]:0;
			ll nr=idx? pref[n-1]-pref[idx-1]-H*(n-idx):pref[n-1]-H*n;
			if(na<nr) return na*min(a+r,m)+(nr-na)*r;
			return nr*min(a+r,m)+(na-nr)*a;
		};
 
	 	ll lo=0,hi=1e9,ans=(ll)1e19;
	 	while(lo<hi){
	 		ll mid=lo+(hi-lo)/2;
	 		ll u=check(mid), v=check(mid+1);
	 		if(u<v){
	 			chmin(ans,u);
	 			hi=mid-1;
	 		}
	 		else{
	 			chmin(ans,v);
	 			lo=mid+1;
	 		}
	 	}
 
	 	cout << ans << endl;
 
		return 0;
}

```


### Alternate Technique for ternery search for finding global minima, or any local minima

a[] = {a1, a2, a3, ... , aN}

a[0] = a[N+1] = inf

```cpp
      int lo = 1 , hi = N;
      while(lo<=hi){
            int mid = (lo + hi) / 2;
	    if(a[mid] < a[mid+1]){
		if(a[mid] < a[mid-1]){
			answer = mid;
			break;
		}
		hi = mid - 1;
	    }
	    else lo = mid + 1;
      }
```

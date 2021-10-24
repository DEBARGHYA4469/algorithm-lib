## Mathematics

https://cses.fi/problemset/task/2417 [No. of Coprime Pairs] </br>

`Idea: Inclusion+Exclusion + Bitmasking`

```cpp
#include<bits/stdc++.h>
#define MaxN 1000006
#define eb emplace_back
#define sz(a) a.size()

using namespace std;

typedef long long int ll;

int lp[MaxN],cnt[MaxN];
vector<int> p;

void sieve(){
	vector<int> p;
	for(int i=2;i<=MaxN;i++){
     		 if(!lp[i]){ 
        		lp[i]=i; 
        		p.eb(i); 
      		 }
        	for(int j=0;j<(int)sz(p) && p[j]<=lp[i] && i*p[j]<=MaxN;j++){
              		lp[i*p[j]] = p[j];      
         	 }	
	 }
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];

	ll total = (ll)n*(ll)(n-1)/2ll;
	
	sieve();

	ll noncp=0ll;

	for(int i=0;i<n;i++){
		vector<int> fac;
		while(a[i]>1){
			int u = lp[a[i]];
			fac.eb(u);
			while(a[i]%u==0) a[i]/=u;
		}
		int mz = fac.size();
		for(int mask=1;mask<(1<<mz);mask++){
			int v=1;
			int sign=-1;
			for(int j=0;j<mz;j++){
				if(mask&(1<<j)){
					v*=fac[j];
					sign*=-1;
				}
			}
			noncp += sign*cnt[v];
			cnt[v]++;		
		}		
	}

	cout << total-noncp << endl;

	return 0;
}
```
 
https://cses.fi/problemset/task/1723 : [No. of Paths in a Graph, Matrix Exponentiation] https://cp-algorithms.com/graph/fixed_length_paths.html </br> 
https://cses.fi/problemset/task/2210 </br>
https://cses.fi/problemset/task/2209 </br>
https://cses.fi/problemset/task/2187 </br>
https://cses.fi/problemset/task/2064 </br>
https://cses.fi/problemset/task/1716 </br>

## Geometry

https://cses.fi/problemset/task/2189
https://cses.fi/problemset/task/2190
https://cses.fi/problemset/task/2191
https://cses.fi/problemset/task/2192
https://cses.fi/problemset/task/2193
https://cses.fi/problemset/task/2194
https://cses.fi/problemset/task/2195

# MiTM

https://codeforces.com/blog/entry/95571

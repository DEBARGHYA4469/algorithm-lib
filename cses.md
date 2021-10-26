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
 
https://cses.fi/problemset/task/1723 : [Paths in a Graph, Matrix Exponentiation] https://cp-algorithms.com/graph/fixed_length_paths.html </br> 
https://cses.fi/problemset/task/2209 : [Burnside Lemma] https://www.geeksforgeeks.org/orbit-counting-theorem-or-burnsides-lemma/ </br>

Burnside Lemma: https://www.youtube.com/watch?v=D0d9bYZ_qDY [3b1b style]


# MiTM [Meet In The Middle]

https://codeforces.com/blog/entry/95571

* Subset Sum

Given a set of n integers where n <= 40. Each of them is at most 10^12, determine the maximum sum subset having sum less than or equal S where S <= 10^18.

```cpp
ll X[2000005],Y[2000005];
void calcsubarray(ll a[], ll x[], int n, int c)
{
    for (int i=0; i<(1<<n); i++)
    {
        ll s = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                s += a[j+c];
        x[i] = s;
    }
}
 
ll solveSubsetSum(ll a[], int n, ll S)
{
    calcsubarray(a, X, n/2, 0);
    calcsubarray(a, Y, n-n/2, n/2);
 
    int size_X = 1<<(n/2);
    int size_Y = 1<<(n-n/2);

    sort(Y, Y+size_Y);
    ll max = 0;
    
    for (int i=0; i<size_X; i++)
    {
        if (X[i] <= S)
            int p = lower_bound(Y, Y+size_Y, S-X[i]) - Y;
            if (p == size_Y || Y[p] != (S-X[i]))
                p--;
            if ((Y[p]+X[i]) > max)
                max = Y[p]+X[i];
        }
    }
    return max;
}
```

* 4-SUM 

```cpp	
	set<int> pairs;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int missing = target-a[i]-a[j];
			if(pairs.count(missing)){
				found = true;
				return;
			}
		}
		for(int k=0;k<i;k++){
			pairs.insert(a[i]+a[k]);
		}
	}
```
## Catalan Numbers 
[Tutorial] Catalan Numbers and Catalan Convolution  https://codeforces.com/blog/entry/87585

`Idea: Catalan Convolution: Think in Dyck Path way!!`

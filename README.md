# CP Starter Pack

[Compile: ](https://codeforces.com/blog/entry/79024?locale=ru) `g++ -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2 -fsanitize=address,undefined -std=c++17` 

<details>
	<summary> My programming template </summary>	
<br>
	
```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

#define eb emplace_back
#define fi first 
#define se second 
#define mp make_pair
#define mt make_tuple
#define tm ((tl+tr)>>1)
#define INF (1<<62)
#define endl "\n"
#define mem(v,w) memset(v,w,sizeof(v))
#define sz(v) v.size()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define si stack<int>
#define vvi vector<vector<int>>
#define setbits(v) __builtin_popcount(v)
#define setbitsll(v) __builtin_popcountll(v)
#define MaxN 500005
#define UFMAX 1
#define LOG 17
#define nth_element(s,n) *(s.find_by_order(n-1)) 
#define count_smaller(s,n) s.order_of_key(n)  
#define raffle_draw(l,r) uniform_int_distribution<int>(l,r)(prng)
#define log(...) cerr << __LINE__ << ": "; logger(#__VA_ARGS__,__VA_ARGS__)

using namespace std;
using namespace __gnu_pbds;

template<typename ...Args>
void logger(string vars, Args&&... values){
	cerr << "[";
	cerr << vars << "] = ";
	string delimeter = "";
	cerr << "[";
		(..., (cerr <<  delimeter << values, delimeter=","));
	cerr << "]\n";
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //pbds

template <class T>
void remove_duplicates(vector<T> &v){
	sort(all(v));
	v.erase(unique(all(v)),v.end());
}

template <class T,class U> bool chmin(T &x, U y){ if(x>y){ x=y; return true; } return false; }
template <class T,class U> bool chmax(T &x, U y){ if(x<y){ x=y; return true; } return false; }

mt19937 prng(chrono::steady_clock::now().time_since_epoch().count()); // mersenne twister
const long double pi = acos(-1.0);
const int mod = 1e9+7;


inline ll ceildiv(ll a,ll b){
	if(a==0) return 0;
	else return (a-1)/b+1;
}	

template<class T> void output_vector(const vector<T> v){
	for(T k:v) cerr << k << " ";
	cerr << endl;
}

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
```
	
</details>

---

<details>
	<summary> Combinatorics Template </summary>
<br>
	
```cpp
inline int mul(int x,int y){    ll z = 1ll; z=z*x*y;   z%=mod; return (int)z; }
inline int add(int x,int y){    ll z = 0ll; z=z+x+y;   z%=mod; return (int)z; }
inline int sub(int x,int y){    ll z=0ll;   z=x+mod-y; z%=mod; return (int)z; }

inline int binpow(int x,int y){

    ll z = 1ll;
    while(y){
        if(y&1) z=mul(z,x);
        x = mul(x,x);
        y>>=1;
    }
    return (int)z;
}

inline int inv(int x){ return binpow(x,mod-2); }

const int N = 400004;
int fac[N], rfac[N];
void fasetup(){
	fac[0] = rfac[0] = 1;
	for(int i=1;i<N;i++) fac[i] = mul(fac[i-1],i);
	rfac[N-1] = inv(fac[N-1]);
	for(int i=N-2;i>0;i--) rfac[i] = mul(rfac[i+1], i+1);
} 

int choose(int n,int r){
	assert(n>=r);
	return mul(fac[n], mul(rfac[r],rfac[n-r])); 
}
```
</details>
	
---
 
<details> 
	<summary>Number Theory Template</summary>
<br>
	
```cpp
// Use Wheel factorization for large PMax
const int PMax = 1e5+5;
int lp[PMax];
void sieve(){ 
	
	vector<int> prime;

	for(int i=2;i<=PMax;i++){
  		if(!lp[i]){ 
    		lp[i]=i; 
    		prime.eb(i); 
  		}
  		for(int j=0;j<(int)sz(prime) && prime[j]<=lp[i] && i*prime[j]<=PMax;j++){
    		lp[i*prime[j]] = prime[j];      
  		}
	}

}

vector<int> factor(int num){

	vector<int> f;
	while(num!=1){
		f.eb(lp[num]);

		int tmp = lp[num];
		while(num>0 && num % tmp==0) num /= tmp;
	}
	return f;
}

vector<int> divisors(int num,const vector<int> lp){

	vector<int> d={1};
	while(num>1){
		int spf=lp[num];
		int m=0;
		while(num%spf==0) num/=spf,m++;

		int dz = (int)sz(d);
		int pw = spf;

		for(int i=0;i<m;i++){
			for(int k=0;k<dz;k++){
				d.eb(d[k]*pw);
			}
			pw*=spf;
		}

	}
	return d;
}
```
	
</details>
	
---

<details>
	<summary> Disjoint Set template </summary>
	
<br> 
	
```cpp
int par[UFMAX],rnk[UFMAX];
int compsize[UFMAX];
int max_comp_size=0;

// SET UFMAX
void initdsu(int n){
	for(int i=1;i<=n;i++){
		par[i] = i;
		rnk[i] = 1;
		compsize[i]=1;
	}
	max_comp_size=0;
}

int root(int u){
	if(par[u]==u) return u;
	return par[u]=root(par[u]);
}

void unite(int u,int v){

	int r1 = root(u), r2 = root(v);
	if(r1==r2) return;
    if(rnk[r1]>rnk[r2]){
    	par[r2] = r1;
    	compsize[r1]+=compsize[r2];
    	compsize[r2]=0;
    	chmax(max_comp_size,compsize[r1]);
    }
    else if(rnk[r1]<rnk[r2]){
    	par[r1] = r2;
   		compsize[r2]+=compsize[r1];
   		compsize[r1]=0;
   		chmax(max_comp_size,compsize[r2]);
    }
    else{
    	par[r2] = r1, rnk[r1]++;
    	compsize[r1]+=compsize[r2];
    	compsize[r2]=0;
    	chmax(max_comp_size,compsize[r1]);
    }
}
```
			      
</details>

---
	

### Useful Notes

<details>
	<summary> Mathematical ideas and some important theorems for CP</summary>

<br>
	
[Custom Ceil Function](math/math.md#a)

[Lazy Caterer](math/math.md#b) 

[Chinese Remainder Theorem](math/math.md#c) 

[Derangement](math/math.md#d) 

[Chicken Mcnugget Theorem](math/math.md#e) 

[Erdos Szekeres Theorem](math/math.md#f) 

[Cyclicity](math/math.md#g)

[Parity of Permutation](math/math.md#h) 

[Rank in Arbitrarty Bases](math/math.md#i) 

[Floyd Cycle](math/math.md#j) 

[Manhattern Trick](math/math.md#k) 

[Subsequence to Subarray Transformation Trick](math/math.md#l)

[Effect of subarray on SAD](math/sad.md)

[How to solve diophantine equations](math/diophantine.md#a)

[Gaussian Elimination in GF(2), Max XOR Subsequence](math/gaussian-elimination.md)

[Euclid extended division algorithm for LCM/GCD](math/gcd-lcm.md)

[Catalan Number, Dyck Path](math/combinatorics.md#a)

[Inclusion Exclusion Principle](math/combinatorics.md#b)

[Minimum Excludent aka MEX](math/mex.md)

</details>

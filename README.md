# cp template

```cpp
#define GCC target ("avx2")
#define GCC optimization("O3")
#define GCC optimization("unroll-loops")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

#define log(...) cerr << __LINE__ << ": "; logger(#__VA_ARGS__,__VA_ARGS__)
#define eb push_back
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
#define vvi vector<vector<int>>
#define setbits(v) __builtin_popcount(v)
#define setbitsll(v) __builtin_popcountll(v)
#define MaxN 500005
#define LOG 17
#define nth_element(s,n) *(s.find_by_order(n-1)) 
#define count_smaller(s,n) s.order_of_key(n)  

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

const int mod = 1e9+7;

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


//.............................................................................................


//.............................................................................................

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	return 0;
}
```

#include <bits/stdc++.h>

#define eb emplace_back
#define fi first 
#define se second 
#define mp make_pair
#define endl "\n"
#define mem(v) memset(v,-1,sizeof(v))
#define memz(v) memset(v,0,sizeof(v))
#define sz(v) v.size()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define log(...) cerr << __LINE__ << ": "; logger(#__VA_ARGS__,__VA_ARGS__)

// .........................define MACROS..........................................................

#define MAXN 500005
#define CHAR 27

using namespace std;
using namespace std::chrono;

template<typename ...Args>
void logger(string vars, Args&&... values){
	cerr << "[";
		cerr << vars << "] = ";
		string delimeter = "";
		cerr << "[";
			(..., (cerr <<  delimeter << values, delimeter=","));
		cerr << "]\n";
}

// .......................templates, typedefs & constants..........................................
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;

template <class T,class U> bool chmin(T &x, U y){ if(x>y){ x=y; return true; } return false; }
template <class T,class U> bool chmax(T &x, U y){ if(x<y){ x=y; return true; } return false; }

const int mod = 1e9+7;
const ll inf = 1ll<<62;

// .......................MAIN FUNCTION FOR CP.....................................................

void main_cp(){
	return;
}

int main(){
	
	auto clk_start = high_resolution_clock::now();
	
	std::ios::sync_with_stdio(false);
    cin.tie(0);
	
	main_cp();
	
	auto clk_end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(clk_end-clk_start);
	cerr << "\nTotal time:" << duration.count() << " ms" << endl;  
	return 0;
}


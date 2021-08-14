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


struct Trie{
	bool v;
	Trie *p;
	map<char,Trie *> m;
	Trie(Trie *p=NULL) :p(p), v(false), m() {} 
};

bool search(Trie *u, string &s){
	for(int i=0;i<sz(s);i++){
			if(u->m.find(s[i])==u->m.end()) return 0;
			u = u->m[s[i]];
	}
	return (u->v)? 1:0;
}

void insert(Trie *u,string &s){
	for(int i=0;i<sz(s);i++){
			if(u->m.find(s[i])==u->m.end()) u->m[s[i]] = new Trie(u);
			u = u->m[s[i]];
	}
	u->v=1;
}

void remove(Trie *u,string &s){
	int i;
	for(i=0;i<sz(s);i++){
			if(u->m.find(s[i])==u->m.end()) return;
			u=u->m[s[i]];
	}
	u->v=0;
	while(u->p!=NULL){
			if(sz(u->m)|u->v) return;
			u=u->p;
			u->m.erase(s[--i]);
	}
}

void main_cpp(){
	
	string a[8] = {"app","application","ape","applicant","cat","dog","dome","cation"}; 
	string b[8] = {"apes","applications","caat","ball","do","d","cations","appli"};
	string c[4]= {"app","cat","dog","cation"};
	
	Trie *u = new Trie();
	for(int i=0;i<8;i++)  insert(u,a[i]);
	for(int i=0;i<4;i++)  remove(u,c[i]);
	for(int i=0;i<8;i++)  cout << a[i] << " " << search(u,a[i]) << endl;
	for(int i=0;i<8;i++) cout << b[i] << " " << search(u,b[i]) << endl;
		
	return;
}

// .......................MAIN FUNCTION FOR CP.....................................................

int main(){
	
	auto clk_start = high_resolution_clock::now();
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	main_cpp();
	
	auto clk_end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(clk_end-clk_start);
	cerr << "\nTotal time:" << duration.count() << " ms" << endl;  
	return 0;
}


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

#define MAXN 10
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

int k=0;
int nxt[MAXN][CHAR];
int vis[MAXN],p[MAXN],cnt[MAXN]; 

void insert(string &s){
	int u=0;
	for(int i=0,j=s[0]-'a';i<sz(s);j=s[++i]-'a'){
		if(nxt[u][j]==-1) nxt[u][j] = ++k, cnt[u]++;
		p[nxt[u][j]]=u;
		u=nxt[u][j];
	}
	vis[u]=1;
}

void remove(string &s){
	int u=0,i,j;
	for(i=0,j=s[0]-'a';i<sz(s);u=nxt[u][j], j=s[++i]-'a') if(nxt[u][j]==-1) return;
	vis[u]=0;
	while(p[u]!=-1){
		if(cnt[u]|vis[u]) return;
		int v=u;
		u=p[u];
		p[v]=-1;
		nxt[u][s[--i]-'a']=-1; 
	}
}

bool search(string &s){
	int u=0;
	for(int i=0,j=s[0]-'a';i<sz(s);u=nxt[u][j], j=s[++i]-'a')
		if(nxt[u][j]==-1) return 0;
	return vis[u]; 
}

void main_cpp(){
	mem(nxt);
	mem(p);

	string a[8] = {"app","application","ape","applicant","cat","dog","dome","cation"}; 
	string b[8] = {"apes","applications","caat","ball","do","d","cations","appli"};
	string c[4]= {"app","cat","dog","cation"};
	
	for(int i=0;i<8;i++)  insert(a[i]);
	for(int i=0;i<4;i++)  remove(c[i]);
	for(int i=0;i<8;i++)  cout << a[i] << " " << search(a[i]) << endl;
	for(int i=0;i<8;i++) cout << b[i] << " " << search(b[i]) << endl;

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


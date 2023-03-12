 https://codeforces.com/problemset/problem/514/C
 ```cpp
 const int P=239017, mx=1e9+7, my=1e9+9;

inline int add(int a,int b,int mod){ return (int)((a*1ll+b)%mod); }
inline int sub(int a,int b,int mod){ return (int)((a*1ll+mod-b)%mod); }
inline int mul(int a,int b,int mod){ return (int)((a*1ll*b)%mod); }

struct Rollhsh{
    int x,y;
    Rollhsh() = default;
    Rollhsh(int _x):x(_x),y(_x) {}
    Rollhsh(int _x,int _y):x(_x),y(_y) {}
    inline Rollhsh operator+(const Rollhsh &h) const { return Rollhsh(add(x,h.x,mx),add(y,h.y,my));}         
    inline Rollhsh operator*(const Rollhsh &h) const { return Rollhsh(mul(x,h.x,mx),mul(y,h.y,my));}
    inline Rollhsh operator-(const Rollhsh &h) const { return Rollhsh(sub(x,h.x,mx),sub(y,h.y,my));}
    inline bool operator==(const Rollhsh &h) const { return x==h.x && y==h.y; } 
};

Rollhsh p[900'005],h[900'005];

// get the full hsh of the string 
void init(const string &s){
    int n = sz(s);
    h[0] = s[0];
    p[0] = 1;
    for(int i=1;i<n;i++){
        h[i] = h[i-1]*P + s[i];
        p[i] = p[i-1]*P;
    }  
}

// get the hsh of a substring
Rollhsh hsh(int l,int r){ 
    if(l==0) return h[r];
    return h[r]-h[l-1]*p[r-l+1];
}

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m; cin >> n >> m;	
 	
 	Rollhsh H;
 	set<pii> dict;
 
 	for(int i=0;i<n;i++){
 		string s; cin >> s;
 		int len = sz(s);
 		init(s);
 		Rollhsh tmp = hsh(0,len-1);
 		dict.insert(mp(tmp.x,tmp.y));
 	}

 	for(int i=0;i<m;i++){
 		string q; cin >> q;
 		bool ok = false;
 		
 		init(q);
 		int k = sz(q);
		Rollhsh tmp=hsh(0,k-1);

 		for(int j=0;j<k;j++){
 			string x,y;
 			
 			Rollhsh xh,yh;
 			if(q[j]=='a'){
 				xh = tmp - p[k-1-j]*q[j] + p[k-1-j]*'b';
 				yh = tmp - p[k-1-j]*q[j] + p[k-1-j]*'c';	
 			}

 			else if(q[j]=='b'){
 				xh = tmp - p[k-1-j]*q[j] + p[k-1-j]*'a';
 				yh = tmp - p[k-1-j]*q[j] + p[k-1-j]*'c';	
 			}
 			
 			else if(q[j]=='c'){
	 			xh = tmp - p[k-1-j]*q[j] + p[k-1-j]*'a';
 				yh = tmp - p[k-1-j]*q[j] + p[k-1-j]*'b';
 			}
 		
 			if(dict.count(mp(xh.x,xh.y)) || dict.count(mp(yh.x,yh.y))){
 				ok = true;
 			}
 		}
 		if(ok) cout << "YES" << endl;
 		else cout << "NO" << endl; 
 	}

	return 0;
}
 ```

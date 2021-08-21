## Rolling Hashes


Foreward Hash:

<a href="https://www.codecogs.com/eqnedit.php?latex=\\Let\:s&space;=&space;s_0s_1s_2....s_{n-1}\\&space;H(s)=s_0&plus;s_1p_1&plus;...&plus;s_{n-1}p_{n-1}=\sum_{i=0}^{n-1}&space;s_ip_i\\&space;H(s[i...j])=p^{-i}(H[s[0...j]]-H[s[0...i-1]])" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\Let\:s&space;=&space;s_0s_1s_2....s_{n-1}\\&space;H(s)=s_0&plus;s_1p_1&plus;...&plus;s_{n-1}p_{n-1}=\sum_{i=0}^{n-1}&space;s_ip_i\\&space;H(s[i...j])=p^{-i}(H[s[0...j]]-H[s[0...i-1]])" title="\\Let\:s = s_0s_1s_2....s_{n-1}\\ H(s)=s_0+s_1p_1+...+s_{n-1}p_{n-1}=\sum_{i=0}^{n-1} s_ip_i\\ H(s[i...j])=p^{-i}(H[s[0...j]]-H[s[0...i-1]])" /></a>

Drawbacks of foreward hashing: more computation required for calculating inverse.

Backward Hash: 

<a href="https://www.codecogs.com/eqnedit.php?latex=\\H(s)=s_0p_{n-1}&plus;s_1p_{n-2}&plus;...&plus;s_{n-2}p&plus;s_{n-1}=\sum_{i=0}^{n-1}&space;s_ip_{n-i-1}\\&space;H(s[0...j])=s_{0}p_{j}&plus;s_{1}p_{j-1}&plus;s_2p_{j-2}&plus;..&plus;s_{i-1}p_{j-i&plus;1}&plus;s_ip_{j-i}&space;&plus;..s_{j-1}p&plus;s_j\\&space;H(s[0...i-1])=s_0p_{i-1}&plus;s_1p_{i-2}&plus;....&plus;s_{i-1}\\&space;H(s[i...j])=&space;s_ip_{j-i}&plus;....&plus;s_j&space;=&space;H(s[0...j])-H(s[0...i-1])p_{j-i&plus;1}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\H(s)=s_0p_{n-1}&plus;s_1p_{n-2}&plus;...&plus;s_{n-2}p&plus;s_{n-1}=\sum_{i=0}^{n-1}&space;s_ip_{n-i-1}\\&space;H(s[0...j])=s_{0}p_{j}&plus;s_{1}p_{j-1}&plus;s_2p_{j-2}&plus;..&plus;s_{i-1}p_{j-i&plus;1}&plus;s_ip_{j-i}&space;&plus;..s_{j-1}p&plus;s_j\\&space;H(s[0...i-1])=s_0p_{i-1}&plus;s_1p_{i-2}&plus;....&plus;s_{i-1}\\&space;H(s[i...j])=&space;s_ip_{j-i}&plus;....&plus;s_j&space;=&space;H(s[0...j])-H(s[0...i-1])p_{j-i&plus;1}" title="\\H(s)=s_0p_{n-1}+s_1p_{n-2}+...+s_{n-2}p+s_{n-1}=\sum_{i=0}^{n-1} s_ip_{n-i-1}\\ H(s[0...j])=s_{0}p_{j}+s_{1}p_{j-1}+s_2p_{j-2}+..+s_{i-1}p_{j-i+1}+s_ip_{j-i} +..s_{j-1}p+s_j\\ H(s[0...i-1])=s_0p_{i-1}+s_1p_{i-2}+....+s_{i-1}\\ H(s[i...j])= s_ip_{j-i}+....+s_j = H(s[0...j])-H(s[0...i-1])p_{j-i+1}" /></a>

#### Implementation (Double Hashing to avoid anti-hash test)

```cpp
const int mod = 1e9+7;
const int P=239017, mx=1e9+7, my=1e9+9;

inline int add(int a,int b){ return (int)((a*1ll+b)%mod); }
inline int sub(int a,int b){ return (int)((a*1ll+mod-b)%mod); }
inline int mul(int a,int b){ return (int)((a*1ll*b)%mod); }

struct rollhash{
    int x,y;
    rollhash() = default;
    rollhash(int _x):x(_x),y(_y) {}
    rollhash(int _x,int _y):x(_x),y(_y) {}
    inline rollhash operator+(const int &c) const { return rollhash(add(x,c),add(y,c));}         
    inline rollhash operator*(const int &c) const { return rollhash(mul(x,c),mul(y,c));}
    inline rollhash operator-(const int &c) const { return rollhash(sub(x,c),sub(y,c));}
    inline bool operator==(const rollhash &h) const { return x==h.x && y==h.y; } 
};

int p[MaxN];
rollhash h[MaxN];

// get the full hash of the string 
void init(const string &s){
    int n = sz(s);
    h[0] = rollhash(s[0]);
    p[0] = 1;
    for(int i=1;i<n;i++){
        h[i] = h[i-1]*P + s[i];
        p[i] = p[i-1]*P;
    }  
}

// get the hash of a substring
rollhash hash(int l,int r){ 
    if(l==0) return h[r];
    return h[r]-h[l-1]*p[r-l-1];
}

```


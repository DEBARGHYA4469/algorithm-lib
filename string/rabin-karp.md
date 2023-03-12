## Rolling Hashes


Foreward Hash:

<a href="https://www.codecogs.com/eqnedit.php?latex=\\Let\:s&space;=&space;s_0s_1s_2....s_{n-1}\\&space;H(s)=s_0&plus;s_1p_1&plus;...&plus;s_{n-1}p_{n-1}=\sum_{i=0}^{n-1}&space;s_ip_i\\&space;H(s[i...j])=p^{-i}(H[s[0...j]]-H[s[0...i-1]])" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\Let\:s&space;=&space;s_0s_1s_2....s_{n-1}\\&space;H(s)=s_0&plus;s_1p_1&plus;...&plus;s_{n-1}p_{n-1}=\sum_{i=0}^{n-1}&space;s_ip_i\\&space;H(s[i...j])=p^{-i}(H[s[0...j]]-H[s[0...i-1]])" title="\\Let\:s = s_0s_1s_2....s_{n-1}\\ H(s)=s_0+s_1p_1+...+s_{n-1}p_{n-1}=\sum_{i=0}^{n-1} s_ip_i\\ H(s[i...j])=p^{-i}(H[s[0...j]]-H[s[0...i-1]])" /></a>

Drawbacks of foreward hashing: more computation required for calculating inverse.

Backward Hash: 

<a href="https://www.codecogs.com/eqnedit.php?latex=\\H(s)=s_0p_{n-1}&plus;s_1p_{n-2}&plus;...&plus;s_{n-2}p&plus;s_{n-1}=\sum_{i=0}^{n-1}&space;s_ip_{n-i-1}\\&space;H(s[0...j])=s_{0}p_{j}&plus;s_{1}p_{j-1}&plus;s_2p_{j-2}&plus;..&plus;s_{i-1}p_{j-i&plus;1}&plus;s_ip_{j-i}&space;&plus;..s_{j-1}p&plus;s_j\\&space;H(s[0...i-1])=s_0p_{i-1}&plus;s_1p_{i-2}&plus;....&plus;s_{i-1}\\&space;H(s[i...j])=&space;s_ip_{j-i}&plus;....&plus;s_j&space;=&space;H(s[0...j])-H(s[0...i-1])p_{j-i&plus;1}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\H(s)=s_0p_{n-1}&plus;s_1p_{n-2}&plus;...&plus;s_{n-2}p&plus;s_{n-1}=\sum_{i=0}^{n-1}&space;s_ip_{n-i-1}\\&space;H(s[0...j])=s_{0}p_{j}&plus;s_{1}p_{j-1}&plus;s_2p_{j-2}&plus;..&plus;s_{i-1}p_{j-i&plus;1}&plus;s_ip_{j-i}&space;&plus;..s_{j-1}p&plus;s_j\\&space;H(s[0...i-1])=s_0p_{i-1}&plus;s_1p_{i-2}&plus;....&plus;s_{i-1}\\&space;H(s[i...j])=&space;s_ip_{j-i}&plus;....&plus;s_j&space;=&space;H(s[0...j])-H(s[0...i-1])p_{j-i&plus;1}" title="\\H(s)=s_0p_{n-1}+s_1p_{n-2}+...+s_{n-2}p+s_{n-1}=\sum_{i=0}^{n-1} s_ip_{n-i-1}\\ H(s[0...j])=s_{0}p_{j}+s_{1}p_{j-1}+s_2p_{j-2}+..+s_{i-1}p_{j-i+1}+s_ip_{j-i} +..s_{j-1}p+s_j\\ H(s[0...i-1])=s_0p_{i-1}+s_1p_{i-2}+....+s_{i-1}\\ H(s[i...j])= s_ip_{j-i}+....+s_j = H(s[0...j])-H(s[0...i-1])p_{j-i+1}" /></a>

### Beware of negative numbers, Use Padding with large numbers to shift everything to positive side

#### Implementation (Double Hashing to avoid anti-hash test)

```cpp
const int P=239017, mx=1e9+7, my=1e9+9;

inline int add(int a,int b,int mod){ return (int)((a*1ll+b)%mod); }
inline int sub(int a,int b,int mod){ return (int)((a*1ll+mod-b)%mod); }
inline int mul(int a,int b,int mod){ return (int)((a*1ll*b)%mod); }

struct Rollhash{
    int x,y;
    Rollhash() = default;
    Rollhash(int _x):x(_x),y(_x) {}
    Rollhash(int _x,int _y):x(_x),y(_y) {}
    inline Rollhash operator+(const Rollhash &h) const { return Rollhash(add(x,h.x,mx),add(y,h.y,my));}         
    inline Rollhash operator*(const Rollhash &h) const { return Rollhash(mul(x,h.x,mx),mul(y,h.y,my));}
    inline Rollhash operator-(const Rollhash &h) const { return Rollhash(sub(x,h.x,mx),sub(y,h.y,my));}
    inline bool operator==(const Rollhash &h) const { return x==h.x && y==h.y; } 
};

Rollhash p[MaxN],h[MaxN];

// get the full hash of the string 
void init(const string &s){
    int n = sz(s);
    h[0] = s[0];
    p[0] = 1;
    for(int i=1;i<n;i++){
        h[i] = h[i-1]*P + s[i];
        p[i] = p[i-1]*P;
    }  
}

// get the hash of a substring
Rollhash hash(int l,int r){ 
    if(l==0) return h[r];
    return h[r]-h[l-1]*p[r-l+1];
}

```

Fast Implementation Trick (High probability of WA with Single Hash)

```cpp
int h[MaxN], p[MaxN];

h[0] = t[0];
p[0] = 0;
for(int i=1;i<sz(t);i++){
    p[i] = mul(p[i-1],P);
    h[i] = add(h[i-1],mul(s[i],p[i])); 
}

bool compare(pii x,pii y){
    int u = mul(sub(h[x.r],h[x.l-1]),p[y.l]);
    int v = mul(sub(h[y.r],h[y.l-1]),p[x.l]);
    return u==v;
}
```
#### Problems
1. Finding lexicographically minimal shift of a string of length n in O(nlog(n)). </br>

<a href="https://www.codecogs.com/eqnedit.php?latex=\\s&space;=&space;s_{0}s_{1}s_{2}s_{3}...s_{n-1}\\&space;\\Shift\\&space;s_{0}s_{1}s_{2}s_{3}...s_{n-1}\\&space;s_{1}s_{2}s_{3}s_{4}...s_{0}\\&space;s_{2}s_{3}s_{4}s_{5}...s_{1}\\&space;s_{3}s_{4}s_{5}s_{6}...s_{2}\\" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\s&space;=&space;s_{0}s_{1}s_{2}s_{3}...s_{n-1}\\&space;\\Shift\\&space;s_{0}s_{1}s_{2}s_{3}...s_{n-1}\\&space;s_{1}s_{2}s_{3}s_{4}...s_{0}\\&space;s_{2}s_{3}s_{4}s_{5}...s_{1}\\&space;s_{3}s_{4}s_{5}s_{6}...s_{2}\\" title="\\s = s_{0}s_{1}s_{2}s_{3}...s_{n-1}\\ \\Shift\\ s_{0}s_{1}s_{2}s_{3}...s_{n-1}\\ s_{1}s_{2}s_{3}s_{4}...s_{0}\\ s_{2}s_{3}s_{4}s_{5}...s_{1}\\ s_{3}s_{4}s_{5}s_{6}...s_{2}\\" /></a>

Naive Approach : n-shifted strings, each string has n chars, comparing takes O(n). So worst O(n*n) 
</br>

`Hashing Approach: Compare strings in log(N)`</br>
`Idea: Binary Search on the Prefix of the string to check equality`

```cpp
    int h[N+1];
    s+=s;
    init(s);
    vector<int> pos;
    for(int i=0;i<N;i++) pos.eb(i);
    int x = *min_element(all(pos),[&](const int i,const int j){
            int lo=1, hi=N;
            bool ok = false;
            while(lo<=hi){
                 int mid = lo + (hi-lo)/2;
                 if(hash(i,i+mid-1)==hash(j,j+mid-1)) lo = mid+1;
                 else{
                    hi = mid-1;
                    if(s[i+mid-1] < s[j+mid-1]) ok = true;
                    else ok = false;
                 }
            }
    });
```

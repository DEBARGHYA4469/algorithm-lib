## Combinatorics

```cpp
#define MaxN = 10005;
const int mod = 1e9+7;
int f[MaxN],rf[MaxN];

inline int mul(int x,int y){ 
    ll z = 1ll;
    z=z*x*y;
    z%=mod;
    return (int)z;
}

inline int add(int x,int y){
    ll z = 0ll;
    z=z+x+y;
    z%=mod;
    return (int)z;
}
inline int binpow(int x,int y){
    ll z = 1ll;
    while(y){
        if(y&1) z=mul(z,x);
        x = mul(x,x);
        y>>=1;
    }
    return (int)z;
}

inline int inv(int x){
    return binpow(x,mod-2);
}

void init(){
    f[0]=rf[0]=1;
    for(int i=0;i<MaxN;i++){
        f[i] = mul(f[i-1],i);
        rf[i]= mul(rf[i-1]*inv(i));
    }
}
```

### Catalan Number

If G is the set of all good paths (#R >= #U at each step) & B is the set of all bad paths (paths which are not good). Total ways to reach (N,N) is C(2N,N).
All bad paths form a bijection to path reaching (N+1,N-1) by all means R,U. So no of bath paths = 2N!/((N+1)!(N-1)!). No. of good paths = 1/(N+1)*2C(2N,N)
 

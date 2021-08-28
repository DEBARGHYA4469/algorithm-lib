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

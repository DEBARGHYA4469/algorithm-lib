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
<a name="a"/>

If G is the set of all good paths (#R >= #U at each step) & B is the set of all bad paths (paths which are not good). Total ways to reach (N,N) is C(2N,N).
All bad paths form a bijection to path reaching (N+1,N-1) by all means R,U. So no of bath paths = 2N!/((N+1)!(N-1)!). No. of good paths = 1/(N+1)*2C(2N,N)
 
### Inclusion and Exclusion
<a name="b"/>

<a href="https://www.codecogs.com/eqnedit.php?latex=f(A_1\cap&space;A_2&space;\cap&space;A_3&space;...&space;A_N)&space;=&space;[f(A_1)&plus;f(A_2)&plus;f(A_3)....f(A_N)]&space;-&space;[f(A_1&space;\cup&space;A_2)&plus;f(A_2&space;\cup&space;A_3)&plus;f(A_3&space;\cup&space;A_4)...]&space;&plus;&space;[f(A_1&space;\cup&space;A_2&space;\cup&space;A_3)&plus;...]&space;......\pm&space;f(A_1&space;\cup&space;A_2&space;\cup&space;A_3....\cup&space;A_N)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?f(A_1\cap&space;A_2&space;\cap&space;A_3&space;...&space;A_N)&space;=&space;[f(A_1)&plus;f(A_2)&plus;f(A_3)....f(A_N)]&space;-&space;[f(A_1&space;\cup&space;A_2)&plus;f(A_2&space;\cup&space;A_3)&plus;f(A_3&space;\cup&space;A_4)...]&space;&plus;&space;[f(A_1&space;\cup&space;A_2&space;\cup&space;A_3)&plus;...]&space;......\pm&space;f(A_1&space;\cup&space;A_2&space;\cup&space;A_3....\cup&space;A_N)" title="f(A_1\cap A_2 \cap A_3 ... A_N) = [f(A_1)+f(A_2)+f(A_3)....f(A_N)] - [f(A_1 \cup A_2)+f(A_2 \cup A_3)+f(A_3 \cup A_4)...] + [f(A_1 \cup A_2 \cup A_3)+...] ......\pm f(A_1 \cup A_2 \cup A_3....\cup A_N)" /></a>


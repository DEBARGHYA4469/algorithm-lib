# CP Starter Pack

[Compile: ](https://codeforces.com/blog/entry/79024?locale=ru) `g++ -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2 -fsanitize=address,undefined -std=c++17` 



```cpp
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

const int N = 400004;
int fac[N], rfac[N];
void fasetup(){
	fac[0] = rfac[0] = 1;
	for(int i=1;i<N;i++) fac[i] = mul(fac[i-1],i);
	rfac[N-1] = inv(fac[N-1]);
	for(int i=N-2;i>0;i--) rfac[i] = mul(rfac[i+1], i+1);
} 

int choose(int n,int r){
	assert(n>=r);
	return mul(fac[n], mul(rfac[r],rfac[n-r])); 
}
```

### Number Theory Template 

```cpp
// Use Wheel factorization for large PMax
const int PMax = 1e5+5;
int lp[PMax];
void sieve(){ 
	
	vector<int> prime;

	for(int i=2;i<=PMax;i++){
  		if(!lp[i]){ 
    		lp[i]=i; 
    		prime.eb(i); 
  		}
  		for(int j=0;j<(int)sz(prime) && prime[j]<=lp[i] && i*prime[j]<=PMax;j++){
    		lp[i*prime[j]] = prime[j];      
  		}
	}

}

vector<int> factor(int num){

	vector<int> f;
	while(num!=1){
		f.eb(lp[num]);

		int tmp = lp[num];
		while(num>0 && num % tmp==0) num /= tmp;
	}
	return f;
}

vector<int> divisors(int num,const vector<int> lp){

	vector<int> d={1};
	while(num>1){
		int spf=lp[num];
		int m=0;
		while(num%spf==0) num/=spf,m++;

		int dz = (int)sz(d);
		int pw = spf;

		for(int i=0;i<m;i++){
			for(int k=0;k<dz;k++){
				d.eb(d[k]*pw);
			}
			pw*=spf;
		}

	}
	return d;
}
```

### Union-Find Template 
```cpp
int par[UFMAX],rnk[UFMAX];
int compsize[UFMAX];
int max_comp_size=0;

// SET UFMAX
void initdsu(int n){
	for(int i=1;i<=n;i++){
		par[i] = i;
		rnk[i] = 1;
		compsize[i]=1;
	}
	max_comp_size=0;
}

int root(int u){
	if(par[u]==u) return u;
	return par[u]=root(par[u]);
}

void unite(int u,int v){

	int r1 = root(u), r2 = root(v);
	if(r1==r2) return;
    if(rnk[r1]>rnk[r2]){
    	par[r2] = r1;
    	compsize[r1]+=compsize[r2];
    	compsize[r2]=0;
    	chmax(max_comp_size,compsize[r1]);
    }
    else if(rnk[r1]<rnk[r2]){
    	par[r1] = r2;
   		compsize[r2]+=compsize[r1];
   		compsize[r1]=0;
   		chmax(max_comp_size,compsize[r2]);
    }
    else{
    	par[r2] = r1, rnk[r1]++;
    	compsize[r1]+=compsize[r2];
    	compsize[r2]=0;
    	chmax(max_comp_size,compsize[r1]);
    }
}
```

##### Table of Contents  
[Custom Ceil Function](/math.md#a)

[Lazy Caterer](#b) 

[Chinese Remainder Theorem](#c) 

[Derangement](#d) 

[Chicken Mcnugget Theorem](#e) 

[Erdos Szekeres Theorem](#f) 

[Cyclicity](#g)

[Parity of Permutation](#h) 

[Rank in Arbitrarty Bases](#i) 

[Floyd Cycle](#j) 

[Manhattern Trick](#k) 

[Subsequence to Subarray Transformation Trick](#l)

[Effect of subarray on SAD](#m) 
## Headers

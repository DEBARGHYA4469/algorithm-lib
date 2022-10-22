## Sieve of Eratosthenes

```cpp
vector<bool> p(MaxN,1);
p[0] = p[1] = 0;
for(int i=2;i*i<MaxN;i++){
      if(p[i]){
          for(int j=i*i;j<MaxN;j+=i) p[j] = 0;
      }
}
```

```
	auto sieve=[&]()->vector<int>{
		vector<int> p;
		for(int i=2;i<=1000;i++){
      		if(!lp[i]){ 
        		lp[i]=i; 
        		p.eb(i); 
      		}
      		for(int j=0;j<(int)sz(p) && p[j]<=lp[i] && i*p[j]<=1000;j++){
        		lp[i*p[j]] = p[j];      
      		}
		}
		return p;
	}
```
`Time : O(Nlog log(N))`

Sieve of Eratosthenes having Linear Time Complexity </br>

`i = lp[i]*x, lp[i] : minimum prime factor of i`
</br></br>
<a href="https://www.codecogs.com/eqnedit.php?latex=\\x&space;=&space;2^23^35\\&space;5&space;\rightarrow&space;3^15\rightarrow&space;3^25\rightarrow&space;3^35\rightarrow&space;2^13^35\rightarrow&space;2^23^35" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\x&space;=&space;2^23^35\\&space;5&space;\rightarrow&space;3^15\rightarrow&space;3^25\rightarrow&space;3^35\rightarrow&space;2^13^35\rightarrow&space;2^23^35" title="\\x = 2^23^35\\ 5 \rightarrow 3^15\rightarrow 3^25\rightarrow 3^35\rightarrow 2^13^35\rightarrow 2^23^35" /></a>

Harmonic Lemma: 1 + 1/2 + 1/3  + .... 1/n ~ log(n)

```cpp
 void sieve(){
	
	vector<int> p;
	for(int i=2;i<=MaxN;i++){
      		if(!lp[i]){ 
        		lp[i]=i; 
        		p.eb(i); 
      		}
      		for(int j=0;j<(int)sz(p) && p[j]<=lp[i] && i*p[j]<=MaxN;j++){
        		lp[i*p[j]] = p[j];      
      		}
	}
}

```

#### Prime Factorization: 

```cpp
    vector<int> factor(int x){
           vector<int> f;
           while(x!=1){
                f.eb(lp[x]);
                x = x/lp[x];
           }
            return f;
    }
```

**Sum of all factors of a number** </br>
<a href="https://www.codecogs.com/eqnedit.php?latex=\sum_{x|n}x&space;=&space;\prod_{prime\:p^\alpha|n}&space;\frac{p^{\alpha&plus;1}-1}{p-1}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\sum_{x|n}x&space;=&space;\prod_{prime\:p^\alpha|n}&space;\frac{p^{\alpha&plus;1}-1}{p-1}" title="\sum_{x|n}x = \prod_{prime\:p^\alpha|n} \frac{p^{\alpha+1}-1}{p-1}" /></a>

Sum function is multiplicative!

</br>

**Highest power of a prime that divides n!** </br>
<a href="https://www.codecogs.com/eqnedit.php?latex=\sum_{i=1}&space;\lfloor{\frac{n}{p^i}}&space;\rfloor" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\sum_{i=1}&space;\lfloor{\frac{n}{p^i}}&space;\rfloor" title="\sum_{i=1} \lfloor{\frac{n}{p^i}} \rfloor" /></a>

</br>

### Problems:

1. Given an array a = [a0,a1,...,aN-1]. Find  max GCD of pair of integers.</br>
`Idea: Sieve of eratothenes, scanning all integers from max to 1 and checking possible gcds.`

```cpp
    int solve(vector<int> A){
          int hi = *max_element(all(A));
          vector<int> fq(hi+1,0); 
          for(int i=0;i<sz(A);i++) fq[A[i]]++; 
          
          for(int i=hi;i>0;i--){
                if(fq[i]>=2) return i;
                for(int j=i,k=0;j<=hi;j+=i){
                    if(fq[j]) k++; //(a=3i,b=7i)
                    if(k>=2) return i;
                }
          }
    }
```
`Time : Dirichlet's divisor problem: unsolved time complexity`


### Prime Factorization Queries for large integers

* Prime Sieve + Wheel Factorization https://cp-algorithms.com/algebra/factorization.html

```cpp
void init(){
	for(int i=2;i<=MaxN;i++){
      		if(!lp[i]){ 
        		lp[i]=i; 
       			p.eb(i); 
      		}
      		for(int j=0;j<(int)sz(p) && p[j]<=lp[i] && i*p[j]<=MaxN;j++){
        	      	lp[i*p[j]] = p[j];      
      		}
	}
}

pair<ll,ll> factor(ll n) {
    ll even=0,odd=0;
    for (ll d : p) {
        if (d*d > n)
            break;
        while (n%d == 0) {
            if(d==2) even++;
            else odd++;
            n /= d;
        }
    }
    if (n>1 && n%2==1) odd++;
    else if(n>1 && n%2==0) even++;
    return mp(even,odd);
}
```
# All Divisors:
```cpp
void sieve(){
	for(int i=2;i<=MaxN;i++){
      		if(!lp[i]){ 
        		lp[i]=i; 
       			p[idx++]=i; 
      		}
      		for(int j=0;j<idx && p[j]<=lp[i] && i*p[j]<=MaxN;j++){
        	      	lp[i*p[j]] = p[j];      
      		}
	}
}

vi divisors(int num){
	vi d={1};
	while(num>1){
		int spf=lp[num];
		int m=0;
		while(num%spf==0) num/=spf,m++;
		int dz=(int)sz(d);
		int pw=spf;
		for(int i=0;i<m;i++){
			for(int k=0;k<dz;k++) d.eb(d[k]*pw);
			pw*=spf;
		}
	}
	return d;
}```

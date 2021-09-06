#### Custom Ceil function

```cpp
    inline int ceildiv(int a,int b){
          if(a==0) return 0;
          else return (a-1)/b+1;
    }
```

#### Lazy Caterer

`F[N] = F[N-1] + N`

Intuitive explaination: You can assume some lines N already existing. </br>
![image](https://user-images.githubusercontent.com/21307343/131888317-c7031dcf-2d97-461a-9f0c-a2e184f85cb9.png)
</br>
Any line intersecting at two points cuts that plane into two halves. To get max cutting we need to cut all the existing lines.</br>
Consider a line far away(pink) which intersects with all the lines N(all diverging and sorted by slopes increasing). So maximum cuts increases by (N-1) + 2(open spaces) i.e `F[N+1] = F[N] + N+1`. Hence this is optimal proven. </br>

Now coming to cake cutting problem, since this construction exists, we can zoom(scale in) out everything and fit in the cake geometry. 

#### Chinese Remainder Theorem

If Alice has x number of apples such that she can divide the apples in mi groups with ri remaining, for some i's. What is the minimum no of apples she posses?</br>

<a href="https://www.codecogs.com/eqnedit.php?latex=\\x&space;=&space;r_1&space;(mod\:\:m_1)\\&space;x&space;=&space;r_2&space;(mod\:\:m_2)\\&space;x&space;=&space;r_3&space;(mod\:\:m_3)\\&space;\\&space;What\:is\:the\:min\:x?" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\x&space;=&space;r_1&space;(mod\:\:m_1)\\&space;x&space;=&space;r_2&space;(mod\:\:m_2)\\&space;x&space;=&space;r_3&space;(mod\:\:m_3)\\&space;\\&space;What\:is\:the\:min\:x?" title="\\x = r_1 (mod\:\:m_1)\\ x = r_2 (mod\:\:m_2)\\ x = r_3 (mod\:\:m_3)\\ \\ What\:is\:the\:min\:x?" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=\\&space;Garner's\:\:Algorithm&space;\\&space;a&space;=&space;x_1&space;&plus;&space;x_2m_1&plus;x_3m_1m_2&plus;x_4m_1m_2m_3&plus;...&plus;x_Nm_1m_2m_3...m_{N-1}&space;\\let\:\:y_1=x_1,&space;y_2&space;=&space;x_1&space;&plus;&space;x_2m_1,&space;y_3&space;=&space;x_1&space;&plus;&space;x_2m_1&plus;x_3m_1m_2,...&space;\\&space;x_1&space;=&space;r_1&space;\\&space;x_2&space;=&space;(r_2-x_1)m_1^{-1}&space;\\&space;x_N&space;=&space;(r_N-y_{N-1})(m_1m_2...m_{N-1})^{-1}\:(mod\:\:m_N)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\&space;Garner's\:\:Algorithm&space;\\&space;a&space;=&space;x_1&space;&plus;&space;x_2m_1&plus;x_3m_1m_2&plus;x_4m_1m_2m_3&plus;...&plus;x_Nm_1m_2m_3...m_{N-1}&space;\\let\:\:y_1=x_1,&space;y_2&space;=&space;x_1&space;&plus;&space;x_2m_1,&space;y_3&space;=&space;x_1&space;&plus;&space;x_2m_1&plus;x_3m_1m_2,...&space;\\&space;x_1&space;=&space;r_1&space;\\&space;x_2&space;=&space;(r_2-x_1)m_1^{-1}&space;\\&space;x_N&space;=&space;(r_N-y_{N-1})(m_1m_2...m_{N-1})^{-1}\:(mod\:\:m_N)" title="\\ Garner's\:\:Algorithm \\ a = x_1 + x_2m_1+x_3m_1m_2+x_4m_1m_2m_3+...+x_Nm_1m_2m_3...m_{N-1} \\let\:\:y_1=x_1, y_2 = x_1 + x_2m_1, y_3 = x_1 + x_2m_1+x_3m_1m_2,... \\ x_1 = r_1 \\ x_2 = (r_2-x_1)m_1^{-1} \\ x_N = (r_N-y_{N-1})(m_1m_2...m_{N-1})^{-1}\:(mod\:\:m_N)" /></a>

`How to calculate modulo inverse mod some coprime number?`</br>

```cpp
inline ll mod(ll x,ll m){ return (x%m+m)%m; }

ll extgcd(ll a,ll b,ll &x,ll &y){
      if(b==0){
          x=1ll;
          y=0ll;
          return a;
      }
      ll x1,y1;
      ll g = extgcd(b,a%b,x1,y1);
      x = y1;
      y = x1 - y1*(a/b);
      return g;
}

inline ll inv(ll a,ll m){
            ll x,y;
            ll g = extgcd(a,m,x,y); 
            assert(g==1);
            return mod(x,m);
    }

inline ll crt(ll r[],ll m[]){
		ll y[10],p[10];
		y[0] = r[0]; p[0] = 1;
		
		for(int k=1;k<N;k++){
				p[k] = p[k-1]*m[k-1];
				ll q = inv(p[k],m[k]);
				y[k] = mod(y[k-1]+(r[k]-y[k-1])*q*p[k],p[k]*m[k]);
			}
		return y[N-1];
}
```

### Derangement
Solving permutation with fixed points k or more: N! - Sum{D(N,k)} k = 0...K-1 https://en.wikipedia.org/wiki/Rencontres_numbers and calcuate.

<li> D[N] =  (N-1)(D[N-1]+D[N-2])

### Chicken McNugget Theorem
	
If there are two number a,b which are relatively prime, the greatest number which can be represented using a & b is (a-1)(b-1)+1.
	
### Erdos Szekeres Theorem
	
If there are ab+1 elements in a sequence then there always exits a monotonic increasing subsequence or decreasing subsequence of length a.
 

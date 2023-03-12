## Gaussian Elimination in GF2[2]: Finding Basis

* More info on Gaussian Elimination technique in GF[2]: https://codeforces.com/blog/entry/68953
* Finding basis vectors for xor.

```cpp
ll basis[32];
int basis_size=0;

void insert_vector(ll v){
	for(int bit=0; bit<32; bit++){
		ll msk = 1ll << bit;
		if(v & msk){
			if(!basis[bit]){
				basis[bit] = v;
				++basis_size;
				return;
			}
			v ^= basis[bit];
		}
	}
}
```

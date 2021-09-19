## Gaussian Elimination in GF2[2]: Finding Basis

* More info on Gaussian Elimination technique in GF[2]: https://codeforces.com/blog/entry/68953
* Finding basis vectors for xor.

```cpp

int basis[LOG];
int sz;

void insertVector(int mask) {
	for (int i = 0; i < LOG_A; i++) {
		if ((mask & 1 << i) == 0) continue;
		if (!basis[i]) {
			basis[i] = mask;
			++sz;
			return;
		}
		mask ^= basis[i];
	}
}
```

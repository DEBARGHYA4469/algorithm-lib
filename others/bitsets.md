# Bitset Magic 

A bitset is an array of bools but each boolean value is not stored in a separate byte. Each boolean value takes 1-bit space.

1. Why is bool 1 byte/8 bits?

Ans : C++ data type must be addressable. Pointer cannot point to a individual bit. Byte addressing is an architectural choice. 

2. Is vector<bool> a STL container?

Ans : No, because it takes 1 bit space for bool. In exchange for the optimization it does not offer all the capabilities of standard stl.

BITSET operations

1. bitset<SIZE> v("1111");
2. v.any() : check if any bit is set.
3. v.all(): check if all bits are set.
4. v.test(idx): returns value at given idx.
5. v.set(idx): sets value at given idx.
6. v.reset(idx): unsets value at given idx.
7. v.count(): count number of set bits.
8. v.flip(idx): flips the value at given idx.
9. v.to_string()
10. v.to_ulong()

BITSET supports all boolean operations. 

DP optimization using Bitset: 

Example 1: https://atcoder.jp/contests/abc147/tasks/abc147_e

```cpp
const int N = 85; 
int H,W;
int a[N][N], b[N][N], c[N][N]; 
bitset<4*N*N> dp[N][N]; 
 
int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
 
	cin >> H >> W;
	for (int i=0;i<H;i++) for (int j=0;j<W;++j) cin >> a[i][j];
	for (int i=0;i<H;i++) for (int j=0;j<W;++j) {
		cin >> b[i][j];
		c[i][j] = a[i][j] - b[i][j];
	}
	
	int offset = 2*N*N; 
	dp[0][0].set(c[0][0] + offset);
	dp[0][0].set(-c[0][0] + offset);
	
	//cout << dp[0][0] << endl; 
 
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			if(i) {
				dp[i][j] |= dp[i-1][j] << abs(c[i][j]);
				dp[i][j] |= dp[i-1][j] >> abs(c[i][j]);	
			}
			if(j){
				dp[i][j] |= dp[i][j-1] >> abs(c[i][j]); 
				dp[i][j] |= dp[i][j-1] << abs(c[i][j]); 
			}
		}
	}
	
	int Ans = 1e9;
	for (int i=0; i<4*N*N;i++){
		if(dp[H-1][W-1].test(i)) chmin(Ans, abs(i-offset));
	}
	  	
	cout << Ans << endl;
	
	return 0;
}
```
* Overflows bits are ignored in bitsets. If the value of sum is small, you can create a bitset of any collection of subsets, x | y << p for y[p] == 1. 


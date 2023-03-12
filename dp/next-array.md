# Next Array Technique 

It is used in many bitwise subarray/subsequence problems like OR, AND. 

One Example: https://codeforces.com/contest/243/problem/A

```cpp
int n;
int a[100006];
int nex[100006][21]; // nex[i][j] : next pos from i such that jth bit is set
bool vis[(1<<21)+5];

// vepifanov solution

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];

	for(int bit = 0; bit < 21; bit++){	
		
		int last = n;

		for(int i=n-1;i>=0;i--){
			
			if(((1 << bit) & a[i])) last = i;

			nex[i][bit] = last;

		}

	}

	for(int l=0;l<n;l++){
		int r = l;
		int val = 0;
		while(r < n){
			val |= a[r];
			vis[val] = 1;

			int r0 = n;

			for(int bit = 0; bit < 21; bit++){
				if(!((1 << bit) & val)){
					chmin(r0, nex[r][bit]);
				}
			}

			r = r0; // jump till new found
		}
	}

	int ans = 0;

	for(int m = 0; m < (1 << 20); m++){
		if(vis[m]) ans++;
	}	

	cout << ans << endl;

	return 0;
}
```

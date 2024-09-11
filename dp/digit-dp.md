## Digit-DP


#### Sum of all digits 

- Find the sum of digits of all numbers from a to b. 

```cpp
ll dp[20][2][180]
int solve(string &n,int idx=0,int tight=1,int sum=0){
    if(idx==sz(n)) return sum;
    if(dp[idx][tight][sum]!=-1) return dp[idx][tight][sum];
    
    int lo = 0;
    int hi = tight? n[idx]-'0':9;
    ll ans = 0;
    for(int i=lo;i<=hi;i++){
          ans+=solve(n,idx+1,tight&&(hi==i),sum+i);    
    }
    return dp[idx][tight][sum] = ans;
}

int query(string a,string b){ // return sum of digits of numbers from a to b
      return solve(b) - solve(a);
}
```
####  Magic Numbers

- find the number of integers between a and b such that digit d is contained only and only in even places and the integers are multiples of m. 

```cpp
ll dp[DIG][m][2][2];
ll solve(int idx,int r=0,bool tightl=1,bool tightr=1){
      if(idx==n) return r==0;
      if(dp[idx][r][tightl][tightr]) return dp[idx][r][tightl][tightr];
      
      int lo = tightl ? a[idx]-'0':0;
      int hi = tightr ? b[idx]-'0':9;
      
      ll cnt=0;
      for(int i=lo;i<=hi;i++){
          if(idx%2==0 && i==d) continue;
          if(idx%2==1 && i!=d) continue;
          int newr = (r*10+i)%m;
          cnt=add(cnt,solve(idx+1,newr,tightl&&i==lo,tightr&&i==hi));
      }
      return dp[idx][r][tightl][tightr]=cnt;
}
```

#### LCM Trick :  Logan and DIGIT IMMUNE numbers

- A Digit-Immune number is a number which is not divisible by any of its digits.
- A digit-immune number will be called an odd-digit-immune number if it contains only odd digits i.e [3,5,7,9]
- Find the number of Odd-Digit-Immune Number.
- How to check for the divisibility?
- Divisiblity of 5 := last digit must be 5.
- Divisibility check of [3, 7, 9] := maintain a mask of all the odd digits seen in the number.
- Finally check against the number if it is divisible by any of its digit.
- number = LCM(3,7,9) * K + r.
- To check divisibility of 3, 7, 9 it is enough to check against r. 

```cpp
const int LCM = 63;
int ALLMASK = 1<<4;
ll dp[DIG][2][LCM+1][ALLMASK+1];
ll solve(int idx,bool tight,int r,int mask,int prev){
    if(idx==n){
        for(int d=0;d<4;d++){
            int di = d*2+3;
            if(di!=5 && mask&(1<<d) && rem%di==0) return 0;
            if(di==5 && prev==5) return 0;
        }
        return 1;
    }
    if(dp[idx][tight][r][mask]!=-1) return dp[idx][tight][r][mask];
    
    int lo = tight && a[idx]<'3' ? 10:3;
    int hi = tight ? a[idx]-'0':9;
    ll cnt=0;
    if(mask==0) cnt+=solve(idx+1,0,r,0,0);
        
    for(int di=lo;di<=hi;di+=2){
        int d=(di-3)/2;
        int newr = (r*10+di)%LCM;
        int newtight = tight&&(di==hi);
        cnt+= solve(idx+1,newtight,newr,mask|(1<<d),d);
    }
    return dp[idx][tight][r][mask]=cnt;
}
```

#### Digit-DP on Pair of Integers \ HR: Count Pairs: Used

- Determine number of pairs (x,y) s.t 0<=x<y<=n, S(x) < S(y). 
- Trick for pair-digit-dp is to maintain dp[curr_idx][i>L][i<R][j>L][j<R]
- You require to brute force two states at once and maintain two tightness values.

```cpp
    int del = 250*9;
    ll dp[255][del*2+5][2][2];
    void solve(int idx,bool tightx,bool tighty,int diff=del){
        if(dp[idx][tightx][tighty][diff]!=-1) return dp[idx][tightx][tighty][diff];
        if(idx==m) return diff>del;
        
        int xlo = 0;
        int xhi = tightx ? a[idx]-'0':9;
        
        ll cnt=0;
        for(int i=xlo;i<=xhi;i++){
            int ylo = 0;
            int yhi = tighty ? i:9;
            
            for(int j=ylo;j<=yhi;j++){
                cnt = add(cnt,solve(idx+1,tightx && i==xhi,tighty && j==yhi,diff+i-j));
            }
        }
        return dp[idx][tightx][tighty][diff] = cnt;
    }
    
```


#### Count Pairs in [l,r] \ Daniel and Spring Cleaning

- To count pairs in (x, y), [l, r] employ the age old prefix sum technique.

```
    a+b=a^b => a&b=0 from sum-xor property
    query(L,R): # pairs(a,b) s.t a in [0,L] and b in [0,R] and a&b=0.
    ans(L,R) = query(L,R) - query(R,L-1) - query(L,R-1) + query(L-1,L-1);
```

#### Count Pairs such that a + b <= N \ https://atcoder.jp/contests/arc066/tasks/arc066_b

- Observe : a + b = a | b + a & b, a | b = a ^ b + a & b.
- x := a or b, y := a & b.
- u = x + y
- v = x - y
- From a given x, y, u and v can be uniquely determined.
- Constraint u <= N.
- x + y <= N and x-bit >= y-bit
- given x,y a, b can be determined.
- Checking x + y <= N can be hard.
- Technique is to go from lsb -> msb and if its is some lesser bit followed by all equal then <= N.
- Switch between ok and nok does the trick. 

```
// dp [bit][CARRY][GREATER];
const int MAX_BIT = 60;  
long long dp [65][2][2]; 
long long solve (const vector<bool> &A, int idx, bool carry, bool ok){
	if (dp[idx][carry][ok] != -1) return dp[idx][carry][ok];
	if (idx == MAX_BIT) return (carry == 0) && !ok;
	long long ans = 0; 
        for (int x = 0; x <= 1; x++){
		for (int y = 0; y <= x; y++){
			int sum = (x + y + carry) % 2; 
			int ncarry = (x + y + carry) / 2; 
			int nbit = A[idx];
			int nok = ok; 
		        if (sum > nbit) nok = 1; 
			if (sum < nbit) nok = 0; 
			ans = (ans + solve (A, idx + 1, ncarry, nok)) % mod;  	
		}
	}
	return dp[idx][carry][ok] = ans; 	
}
```




## Digit-DP


#### Problem-1
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
####  D. Magic Numbers
`If number of digits of a & b are same = n`
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

### LCM Trick :  Logan and DIGIT IMMUNE numbers

`A Digit-Immune number is a number which is not divisible by any of its digits.`
`A digit-immune number will be called an odd-digit-immune number if it contains only odd digits.`

`LCM Trick: Check divisibility ` </br></br></br>
<a href="https://www.codecogs.com/eqnedit.php?latex=\\LCM&space;=&space;LCM(a1,a2,a3,...am)\\&space;a&space;\equiv&space;r&space;(mod\:LCM)&space;\implies&space;a&space;=&space;LCM*k&plus;r\\&space;a\:mod\:a_i&space;\equiv&space;(LCM*k&plus;r)\:mod\:a_i&space;=&space;r\:mod\:a_i" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\LCM&space;=&space;LCM(a1,a2,a3,...am)\\&space;a&space;\equiv&space;r&space;(mod\:LCM)&space;\implies&space;a&space;=&space;LCM*k&plus;r\\&space;a\:mod\:a_i&space;\equiv&space;(LCM*k&plus;r)\:mod\:a_i&space;=&space;r\:mod\:a_i" title="\\LCM = LCM(a1,a2,a3,...am)\\ a \equiv r (mod\:LCM) \implies a = LCM*k+r\\ a\:mod\:a_i \equiv (LCM*k+r)\:mod\:a_i = r\:mod\:a_i" /></a>

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

## Digit-DP on Pair of Integers

### HR: Count Pairs: Used

`Determine number of pairs (x,y) s.t 0<=x<y<=n, S(x) < S(y).`</br>

`Trick for pair-digit-dp is to maintain dp[curr_idx][i>L][i<R][j>L][j<R]` </br>

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


#### F. Daniel and Spring Cleaning

```
    a+b=a^b => a&b=0 from sum-xor property
    query(L,R): # pairs(a,b) s.t a in [0,L] and b in [0,R] and a&b=0.
    ans(L,R) = query(L,R) - query(R,L-1) - query(L,R-1) + query(L-1,L-1);
```

## Trie / Prefix Tree / Digital Tree

* Min Xor can be found by taking xor of neighbouring elements in a sorted list
* Max/ Min Xor can be better/ efficiently found using Trie

**Array Implementation**

```cpp
int node=0;
int nxt[MaxN*LOG+5][CHARLIM];
int p[MaxN], cnt[MaxN], leaf[MaxN], br[MaxN];

void insert(string &s){
    int u=0;
    for(int i=0;i<sz(s);i++){
        int j = s[i]-'a';
        if(nxt[u][j]==-1) { 
            nxt[u][j] = ++node;
            br[u]++;
        }
        p[nxt[u][j]] = u;
        u = nxt[u][j];
        cnt[u]++;
    }
    leaf[u]=1;
}

void delete(string &s){
    int u=0,i;
    for(i=0;i<sz(s);i++){
        int j = s[i]-'a';
        if(nxt[u][j]==-1) return;
        u=nxt[u][j];
    }
    leaf[u]=0;
    while(p[u]!=-1){
        int j = s[--i]-'a';
        if(leaf[u]|br[u]) break;
   
        int v = p[u];
        cnt[u]--;
        p[u] = -1;
        nxt[u][j] = -1;
        u = v;
    }
    while(p[u]!=-1){
        cnt[u]--;
        u = p[u];
    }
}

bool search(string &s){
     int u = 0;
     for(int i=0;i<sz(s);i++){
          int j = s[i]-'a';
          if(nxt[u][j]==-1) return 0;
     }
     return leaf[u];
}

```
**Pointer + Map Implementation**

```cpp
struct Trie{
    bool leaf;
    Trie *p;
    map<char,Trie*> child;
    Trie(Trie *p=NULL) :p(p), leaf(0), child() {} 
};

bool search(Trie *u, string &s){
    for(int i=0;i<sz(s);i++){
        if(u->child.find(s[i])==u->child.end()) return 0;
        u = u->child[s[i]];
    }
    return u->leaf;
}

void insert(Trie *u, string &s){f
    for(int i=0;i<sz(s);i++){
        if(u->child.find(s[i])==u->child.end()) u->child[s[i]] = new Trie(u);
        u = u->child[s[i]];
        }
    u->leaf=1;
}

void delete(Trie *u, string &s){
	int i;
	for(i=0;i<sz(s);i++){
			  if(u->child.find(s[i])==u->child.end()) return;
			  u=u->child[s[i]];
	}
	u->leaf=0;
	while(u->p!=NULL){
			if(sz(u->child)|u->leaf) return;
			u=u->p;
			u->child.erase(s[--i]);
	}
}
```

**Bit-Prefix Tree**

Problem : A[10] = {a1, a2, a3, a4, a5, a6,..., aN}. Find the no of subarrays with XOR < k.

Idea:  Insert the prefix xors, when adding a new prefix xor anaylse the trie & find the max xor subarray by comparing against other prefixes. xor[l...r] = prefixor[r] ^ prefixor[l-1]. Start from MSB and choose ~bit from trie if possible. 

```cpp
const int LOG = 19;
int node = 0;
int n,k;
ll ans = 0ll;
int nxt[MaxN*LOG+5][2], cnt[MaxN]; 

void insert(int a){
    int u=0;
    for(int i=0;i<LOG;i++){
        int mask = 1 << (LOG-i-1);
        int j= a & mask ? 1:0;
        if(nxt[u][j]==-1) nxt[u][j]=++node;
        u = nxt[u][j];
        cnt[u]++;
    }
}

void query(int a){
    int u=0;
    for(int i=0;i<LOG;i++){
        int mask = 1 << (LOG-i-1);
        int abit= a & mask ? 1:0;    
        int kbit= k & mask ? 1:0;
        
        if(kbit==0){
            if(nxt[u][abit]!=-1) u=nxt[u][abit];
            else return;
        }
        else{
            if(nxt[u][abit]!=-1){
                ans += cnt[nxt[u][abit]];
            }
            if(nxt[u][abit^1]!=-1) u = nxt[u][abit^1];
            else return;
        }
   }
}

ll solve(int a[MaxN]){
      int b[MaxN];
      for(int i=1;i<=n;i++){
          b[i] = b[i-1] ^ a[i-1];
          insert(b[i]);
          query(b[i]);
          if(b[i]<k) ans++;
          ans--; 
      }
      return ans;
}
```
#### Max XOR Subsequence
`Idea: Gaussian Elimination in GF(2)`
</br>
`Intuition behind GE: `
</br>
</br>
<a href="https://www.codecogs.com/eqnedit.php?latex=\\S&space;=&space;{a_1,a_2,a_3.....a_N}\\&space;Under\:\bigoplus&space;\:operation,&space;we\:see\:that\:&space;\\S'=&space;{a_1\oplus&space;a_k,&space;a_2&space;\oplus&space;a_k,&space;....a_k,a_{k&plus;1},...a_{N-1},a_N}.\\&space;S&space;\:&space;and&space;\:&space;S'&space;\:are\:&space;equivalent\:&space;sets." target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\S&space;=&space;{a_1,a_2,a_3.....a_N}\\&space;Under\:\bigoplus&space;\:operation,&space;we\:see\:that\:&space;\\S'=&space;{a_1\oplus&space;a_k,&space;a_2&space;\oplus&space;a_k,&space;....a_k,a_{k&plus;1},...a_{N-1},a_N}.\\&space;S&space;\:&space;and&space;\:&space;S'&space;\:are\:&space;equivalent\:&space;sets." title="\\S = {a_1,a_2,a_3.....a_N}\\ Under\:\bigoplus \:operation, we\:see\:that\: \\S'= {a_1\oplus a_k, a_2 \oplus a_k, ....a_k,a_{k+1},...a_{N-1},a_N}.\\ S \: and \: S' \:are\: equivalent\: sets." /></a>
</br>
</br>
To extrapolate the idea: 
</br>
</br>
In first traversal, transform S to a set where only one element has MSB bit on others off. That makes the element **fixed** in the set S'. Next, do the same thing for the next bit, make another element's MSB-1 bit on and rest 0. Now two elements are **fixed** and we have to work on the remaining transformed set S''.Next select one more element, and so on. Crux of this idea is that when working with new bits, it cannot alter the state of the previous bits.
</br>
`Same idea can be extended to solve xor subset with a specified value as the equivalence still holds.`

```cpp	
	int a[MaxN];
	int solve(){
		for(int i=0;i<32;i++){
			int mask = 1<<(32-i-1);
			pii v = mp(i,-1*inf);
			for(int j=i;j<n;j++){
				if((a[j]&mask) && a[j]>v.se)
					v = mp(j,a[j]);
			}
			if(v.se==-1*inf) continue;
			swap(a[i],a[v.fi]);
			
			for(int j=0;j<n;j++){
				if(j!=v.fi && a[j]&mask) a[j]^=a[v.fi];
			}
		}
		int ans=0;
		for(int i=0;i<n;i++) ans^=a[i];
		return ans;
	}
```
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

**Games on Trie**

Problem: Two players Alice, Bob play in turns to create a valid dictionary(given) word, one who cannot loses the game. In each round, players play in turns to insert one character. Winner of the game is the winner of the last round. Given list of valid words, who wins, if both plays optimally.

Idea: </br>
&nbsp;&nbsp;&nbsp;&nbsp; win[i] : player when reaches this state, either has a forced win(1)/ gets forced loss(0) = OR(~win[next states])
</br>
&nbsp;&nbsp;&nbsp;&nbsp; lose[i] :  player when reaches this state, either has a forced loss(1)/ gets forced win(0) = OR(~lose[next states])
</br>
Imp note: **If a player can force win/lose in a state, he might choose not to win/lose in that state but if a player does not have a forced win/loss then he definitely loses/wins in that state** </br>

![Drawing-77 sketchpad](https://user-images.githubusercontent.com/21307343/129959336-69a862ac-ff68-4e80-a749-ebeb40f34d02.png)

```cpp
void dfs(int u){
	if(!br[u]) win[u]=0,lose[u]=1;
	else{
		bool can_win=0, can_lose=0;
		for(int i=0;i<26;i++){
			int v=nxt[u][i];
			if(v!=-1){
				dfs(v);
				can_win|=!win[v];
				can_lose|=!lose[v];
			} 
		}
		win[u] = can_win;
		lose[u] = can_lose;
	}
}

void solve(){
	for(int i=0;i<n;i++) insert(dict[i]);
	dfs(0);
	if(win[0] && lose[0]) cout << "Alice" << endl;
	else if(win[0] && !lose[0]) cout << (k&1)? "Alice" : "Bob" << endl;
	else cout << "Bob" << endl;
}
```

* Nice Problem on Binary Trie & MEX: https://codeforces.com/problemset/problem/842/D

![image](https://user-images.githubusercontent.com/21307343/141613520-df3d499e-6d58-46a0-93ef-966e7deb57f3.png)

* https://codeforces.com/contest/1554/problem/C [Implicit Binary Trie+MEX+XOR]

Binary Spider: Excellent Example of using 0/1 TRIE: https://codeforces.com/contest/1625/submission/142741971

## Trie / Prefix Tree / Digital Tree

Array Implementation

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
Pointer + Map Implementation

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

Bit-Prefix Tree 

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

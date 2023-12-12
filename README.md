# CP Hack Tools

[Compile: ](https://codeforces.com/blog/entry/79024?locale=ru) `g++ -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2 -fsanitize=address,undefined -std=c++17` 

<details markdown="1"> 
<summary>My Programming Template
</summary>

```cpp
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

#define eb emplace_back
#define fi first 
#define se second 
#define mp make_pair
#define mt make_tuple
#define tm ((tl+tr)>>1)
#define INF (1<<62)
#define endl "\n"
#define mem(v,w) memset(v,w,sizeof(v))
#define sz(v) v.size()
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define si stack<int>
#define vvi vector<vector<int>>
#define setbits(v) __builtin_popcount(v)
#define setbitsll(v) __builtin_popcountll(v)
#define nth_element(s,n) *(s.find_by_order(n-1)) 
#define count_smaller(s,n) s.order_of_key(n)  
#define raffle_draw(l,r) uniform_int_distribution<int>(l,r)(prng)
#define log(...) cerr << __LINE__ << ": "; logger(#__VA_ARGS__,__VA_ARGS__)

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //pbds

template <class T,class U> bool chmin(T &x, U y){ if(x>y){ x=y; return true; } return false; }
template <class T,class U> bool chmax(T &x, U y){ if(x<y){ x=y; return true; } return false; }

mt19937 prng(chrono::steady_clock::now().time_since_epoch().count()); // mersenne twister
const long double pi = acos(-1.0);
const int mod = 1e9+7;

/* logging utitlies */
template<typename ...Args>
void logger(string vars, Args&&... values){
	cerr << "[";
	cerr << vars << "] = ";
	string delimeter = "";
	cerr << "[";
		(..., (cerr <<  delimeter << values, delimeter=","));
	cerr << "]\n";
}

/* i/o stream utilities */
ostream& operator <<(ostream& out, pair<int,int> const& v){
    out << v.fi << "," << v.se; 
    return out; 
}

template<typename T>
ostream& operator <<(ostream& out, const vector<T>& v){
    for (const T& x: v) out << x << " "; 
    return out; 
}

template<typename T, typename S>
ostream& operator <<(ostream& out, const map<T,S>& v){
    for (auto& x: v) out << x.fi << "-->" << x.se; 
    return out; 
}

template<typename T>
ostream& operator <<(ostream& out, const set<T>& v){
    for (auto& x: v) cout << x << " ";
    return out;
}

template<typename T>
ostream& operator <<(ostream& out, const multiset<T>& v){
    for (auto& x: v) cout << x << " ";
    return out;
}

/* adhoc utilities */  
inline ll ceil_divide(ll a,ll b){   return (a+b-1)/b; }	

template <class T>
void remove_duplicates(vector<T> &v){ sort(all(v)); v.erase(unique(all(v)),v.end());}

string to_binary(ll v){
    if(!v) return "0";
    string s="";
    while (v>0){
        s += static_cast<char>(v%2 + '0');
        v/=2;
    }
    reverse(all(s));
    return s; 
    
}

const int MAXSV = 1000000;
bool _vis[MAXSV]; 
int _lpf[MAXSV]; // lowest prime factor, set MAXSV =   
void sieve_with_lpf(){
    for (int i=2;i<MAXSV;i+=2) _lpf[i] = 2; 
    for (ll i=3;i<MAXSV;i+=2) {
        if (!_vis[i]){
            _lpf[i] = i;
            for (ll j=i;(i*j)<MAXSV;j+=2){ 
                if (!_vis[i*j]){
                    _vis[i*j] = true; 
                    _lpf[i*j] = i;
                }
            }
        }
    }    
}

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	return 0;
}
```

</details>



<details markdown="1">
<summary>Stress Test PY Template
</summary>

```py
import filecmp
import os
import random
import sys
import subprocess

my_solution = sys.argv[1]
test_solution = sys.argv[2]

my_solution_exe = my_solution.split(".cpp")[0]
test_solution_exe = test_solution.split(".cpp")[0]

input_file = "in.txt"
my_solution_out = "out1.txt"
test_solution_out = "out2.txt"

def generate_input_file():
    '''
            Write code here to generate the input file
            Tips:
                1. Use random.randint(l,r) : to generate random number between l...r
                2. Perm = list(range(1,n)) random.shuffle(Perm) : to generate a randome permutation
        '''
def test_case(i):
    generate_input_file()
    os.system(f"./{my_solution_exe} < {input_file} > {my_solution_out}")
    os.system(f"./{test_solution_exe} < {input_file} > {test_solution_out}")

    with open(my_solution_out, "r") as f:
        a = f.readline()
        a.rstrip()

    with open(test_solution_out, "r") as f:
        b = f.readline()
        b.rstrip()

    if a == b:
        print(f"Test {i} passed.")
    else:
        print("ERROR, match out1.txt and out2.txt.")
        sys.exit(0)

def run_commands(cmd):
    print(cmd)
    try:
        cmd = cmd.split(" ")
        subprocess.run(cmd, check=True)
    except subprocess.CalledProcessError as e:
        print ("Error:", e)

def compile_command(cpp_file):
    compilation_flags = "-Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2 -fsanitize=address,undefined -std=c++17"
    exe_name = cpp_file.split(".cpp")[0]
    return f"g++ {compilation_flags} {exe_name} {cpp_file}"

if __name__ == '__main__':

    run_commands(compile_command(my_solution))
    run_commands(compile_command(test_solution))

    for i in range(1,10000):
        test_case(i)


```
</details>

---

<details markdown="1">
<summary>Combinatorics Template
</summary>


```cpp
inline int mul(int x,int y){    ll z = 1ll; z=z*x*y;   z%=mod; return (int)z; }
inline int add(int x,int y){    ll z = 0ll; z=z+x+y;   z%=mod; return (int)z; }
inline int sub(int x,int y){    ll z=0ll;   z=x+mod-y; z%=mod; return (int)z; }

inline int binpow(int x,int y){

    ll z = 1ll;
    while(y){
        if(y&1) z=mul(z,x);
        x = mul(x,x);
        y>>=1;
    }
    return (int)z;
}

inline int inv(int x){ return binpow(x,mod-2); }

const int N = 400004;
int fac[N], rfac[N];
void fasetup(){
	fac[0] = rfac[0] = 1;
	for(int i=1;i<N;i++) fac[i] = mul(fac[i-1],i);
	rfac[N-1] = inv(fac[N-1]);
	for(int i=N-2;i>0;i--) rfac[i] = mul(rfac[i+1], i+1);
} 

int choose(int n,int r){
	assert(n>=r);
	return mul(fac[n], mul(rfac[r],rfac[n-r])); 
}
```

</details>
	
	

 
<details markdown="1"> 
<summary>Number Theory Template
</summary>


```cpp
// Use Wheel factorization for large PMax
const int PMax = 1e5+5;
int lp[PMax];
void sieve(){ 
	
	vector<int> prime;

	for(int i=2;i<=PMax;i++){
  		if(!lp[i]){ 
    		lp[i]=i; 
    		prime.eb(i); 
  		}
  		for(int j=0;j<(int)sz(prime) && prime[j]<=lp[i] && i*prime[j]<=PMax;j++){
    		lp[i*prime[j]] = prime[j];      
  		}
	}

}

vector<int> factor(int num){

	vector<int> f;
	while(num!=1){
		f.eb(lp[num]);

		int tmp = lp[num];
		while(num>0 && num % tmp==0) num /= tmp;
	}
	return f;
}

vector<int> divisors(int num,const vector<int> lp){

	vector<int> d={1};
	while(num>1){
		int spf=lp[num];
		int m=0;
		while(num%spf==0) num/=spf,m++;

		int dz = (int)sz(d);
		int pw = spf;

		for(int i=0;i<m;i++){
			for(int k=0;k<dz;k++){
				d.eb(d[k]*pw);
			}
			pw*=spf;
		}

	}
	return d;
}
```

</details>
	
	

<details markdown="1">
<summary>Disjoint Set Template
</summary>
	
	
```cpp
// DSU with Rank Compression + Path Compression

int par[UFMAX],rnk[UFMAX];
int compsize[UFMAX];
int max_comp_size=0;

// SET UFMAX
void initdsu(int n){
	for(int i=1;i<=n;i++){
		par[i] = i;
		rnk[i] = 1;
		compsize[i]=1;
	}
	max_comp_size=0;
}

int root(int u){
	if(par[u]==u) return u;
	return par[u]=root(par[u]);
}

void unite(int u,int v){

	int r1 = root(u), r2 = root(v);
	if(r1==r2) return;
    if(rnk[r1]>rnk[r2]){
    	par[r2] = r1;
    	compsize[r1]+=compsize[r2];
    	compsize[r2]=0;
    	chmax(max_comp_size,compsize[r1]);
    }
    else if(rnk[r1]<rnk[r2]){
    	par[r1] = r2;
   		compsize[r2]+=compsize[r1];
   		compsize[r1]=0;
   		chmax(max_comp_size,compsize[r2]);
    }
    else{
    	par[r2] = r1, rnk[r1]++;
    	compsize[r1]+=compsize[r2];
    	compsize[r2]=0;
    	chmax(max_comp_size,compsize[r1]);
    }
}
```

```cpp

// DSU w/o Rank Compression and using randomized Union + Path Compression

const int MAXN = 1005;
int par[MAXN], members[MAXN];
 
void init(){
	for (int i=1;i<=n;i++){
		par[i] = i;
		members[i] = 1; 
	}
}
 
int root(int u){
	if(par[u]==u) return u;
	return par[u] = root(par[u]);	
}
 
void unite(int u,int v){
	if(root(u)==root(v)) return;
	if(rand()&1) swap(u,v);
	members[root(v)] += members[root(u)];
	par[root(u)] = v; 
}
```

</details>

<details markdown="1">
<summary> Segment Tree Template
</summary>

```cpp
/* 1-based segment tree template */

const int ST_MAX = 2e5+3;
int _array[ST_MAX];

struct Node{
    // 0. add node variables and constructors 
    ll v,p,s,l,r,w; 
	Node(): v(0),p(0),s(0),l(-1),r(-1),w(0) {}
	Node(ll x) : v(1),p(1),s(1),l(x),r(x),w(1) {}
	Node(const Node &T): v(T.v),p(T.p),s(T.s),l(T.l),r(T.r),w(T.w) {} 
};

int _n; // $ set _n 
class SegmentTree {
    public: 
        Node *_t;
    public:
        
        SegmentTree () {
            _t = new Node[_n*6]; 
        }

        Node combine (Node lc, Node rc){
            Node res;
            /* 1. add your combine code along with empty node  */
            if(!lc.w) return Node(rc);
            if(!rc.w) return Node(lc);
            res.w = lc.w+rc.w;
            res.l = lc.l; 
            res.r = rc.r;
            res.v = lc.v + rc.v + ((rc.l >= lc.r)? lc.s*rc.p: 0);
            res.p = (lc.p==lc.w && rc.l >= lc.r)? lc.w+rc.p:lc.p; 
            res.s = (rc.s==rc.w && lc.r <= rc.l)? lc.s+rc.w:rc.s;
            return res;
        }

        Node query (const int& l, const int& r, int v=1, int tl=1, int tr=_n){
            if (r<tl||l>tr) return Node (); 
            if (tl>=l && tr<=r) return _t[v]; 
            return combine (query(l, r, v<<1, tl, tm), 
                query(l, r, v<<1|1, tm+1, tr));
        }

        void build (int v=1, int tl=1, int tr=_n){
            if (tl==tr) _t[v] = Node(_array[tl]); 
            else {
                build (v<<1, tl, tm);
                build (v<<1|1, tm+1, tr); 
                _t[v] = combine (_t[v<<1], _t[v<<1|1]); 
            }
        }

        // point update 
        void update (const int& pos, const int& val, int v=1, int tl=1, int tr=_n){
            if (tl==tr) _t[v] = Node(val);  
            else {
                if (pos <= tm) update (pos, val, v<<1, tl, tm);
                else update (pos, val, v<<1|1, tm+1, tr); 
                _t[v] = combine (_t[v<<1], _t[v<<1|1]);  
            }
        }
};
```
</details>
---


### Useful Notes

---

<details markdown="1">
<summary>Trees and Graphs
</summary>

---

[Cyclicity in undirected graph](graph/graph.md#a)

[Cyclicity in directed graph, coloring technique](graph/graph.md#b)

[All simple cycles in a undirected graph, w/o composite cycles](graph/graph.md#c)

[All tricks using union-find algorithm](graph/graph.md#d)

[Small to Large Trick, Merger Sets, a DSU trick](graph/dsu.md)

[Tarjan's algorithm to find articulation points, bridges](graph/graph.md#e)

[Finding transitive closure of a graph using Floyd Warshall](graph/graph.md#g)

[BFS on complement graph aka Pie for a Pie trick](graph/graph.md#h)

[All topological ordering](graph/graph.md#i)

[Kahn's algorithm for topological ordering](graph/graph.md#j)

[Maximal/Minimal Topological ordering](graph/graph.md#k)

[Floyd Warshall for finding shortest paths](graph/graph.md#l)

[Minimum Spanning Tree, Prim vs Kruskal](graph/graph.md#m)

[Dijkstra's shortest path algoritm for non-negative edges](graph/graph.md#o)

[Kth shortest path and ghostness in dikjstra's algorithm](graph/graph.md#o1)

[Use Bellman Ford for negative edge weights](graph/graph.md#p)

[Detect negative cycle using Bellman Ford](graph/graph.md#q)

[Shortest Cycle in undirected graph using BFS](graph/graph.md#q1)

[0/1 BFS Trick](graph/graph.md#r)

[Strongly connected component aka SCC](graph/graph.md#s)

[Kosaraju's algorithm for condensed SCC](graph/graph.md#t)

[Finding centeroid a tree, subtree, cut tree](graph/centeroid.md)

[Euler Tour, relation between vertices, propagating tree](graph/euler-tour.md)

[Everything about Trie](graph/trie.md)

[Trie and binary MEX](graph/trie.md)

[Bit prefix Trie and XOR operations](graph/trie.md)

[Games on Trie](graph/trie.md)

</details>

<details markdown="1">
<summary>Mathematical Techniques
</summary>

---
	
[Custom Ceil Function](math/math.md#a)

[Lazy Caterer](math/math.md#b) 

[Chinese Remainder Theorem](math/math.md#c) 

[Derangement](math/math.md#d) 

[Chicken Mcnugget Theorem](math/math.md#e) 

[Erdos Szekeres Theorem](math/math.md#f) 

[Cyclicity](math/math.md#g)

[Parity of Permutation](math/math.md#h) 

[Rank in Arbitrarty Bases](math/math.md#i) 

[Floyd Cycle](math/math.md#j) 

[Manhattern Trick](math/math.md#k) 

[Complexity of Euclid's dvision Lemma](math/math.md#o)

[Subsequence to Subarray Transformation Trick](math/math.md#l)

[Some properties of sum of absolute differences aka SAD](math/sad.md)

[How to solve diophantine equations](math/diophantine.md#a)

[Gaussian Elimination in GF(2), Max XOR Subsequence](math/gaussian-elimination.md)

[Euclid extended division algorithm for LCM/GCD](math/gcd-lcm.md)

[Catalan Number, Dyck Path](math/combinatorics.md#a)

[Inclusion Exclusion Principle](math/combinatorics.md#b)

[Minimum Excludent aka MEX](math/mex.md)

[No. of Co-prime pairs](math/cses.md)

[Meet in the Middle aka MiTM](math/cses.md)

[Generating Functions](math/generating_functions.md)

[Difference Array, Sort, Repeat](math/math.md#p)

</details>

<details markdown="1">
<summary>
Greedy Techniques
</summary>

---

[Minimum Increment Decrement to make array equal](greedy/adhoc_greedy.md)
	
[Largest Area in a Histogram using NGE](greedy/adhoc_greedy.md)

[Intermediate Value Property Trick](greedy/adhoc_greedy.md)

[Job Sequencing Problems](greedy/adhoc_greedy.md)

[A Nice Binary Search Trick](greedy/adhoc_greedy.md)

[Find frequency of element in a given range using upperbound, lowerbound](greedy/adhoc_greedy.md)

[All techniques using exchange arguments, powerful proving technique](greedy/exchange-arg.md)

[Invariance and Extremal Ideas](greedy/invariance.md)

[Generic sliding window algorithm](greedy/sliding-window.md)

[Comparing a subarray with a sliding window technique](greedy/sliding-window.md)

[Find closest pair, minimum euclidean distance](greedy/sweepline.md)

[Klee's algorithm for union of intersecting segments](greedy/sweepline.md)

[Intervals and Schedules](greedy/interval.md)

[UpperBound and LowerBound on Tuples](greedy/adhoc_greedy.md)

[Change of slope trick](greedy/adhoc_greedy.md)

</details>


<details markdown="1">
<summary>Dynamic Programming
</summary>

---

[Max Subarray Sum, Kadane's algorithm](dp/adhoc-dp.md)

[Max Subarray Product](dp/adhoc-dp.md)

[All variants of buy-sell share problems](dp/adhoc-dp.md)

[Bitmasking: Assigment Problem](dp/bitmask.md)

[Bitmasking: Held Karp for TSP like problem](dp/bitmask.md)

[Masking over Primes](dp/bitmask.md)

[Enumerating submasks](dp/bitmask.md)

[Profile DP, DP on broken pipes](dp/bitmask.md)

[All tricks in digit DP problems, including LCM trick, pair of numbers](dp/digit-dp.md)

[Divisibility problems using DP](dp/divisibility.md)

[Everything about IN-OUT dp on tree aka Rerooting technique, Tree Distances, Tree Matching](dp/dp-on-trees.md)

[Inclusion and Exclusion DP](dp/dp-on-trees.md)

[Solving any structural dp problems using kadane's approach](dp/dp_tricks.md)

[Subsequence & Substring comparison of two strings type problems](dp/subsequence_dp.md)

[Everything about Sieve of Eratosthenes, Prime Factorization, Harmonic Lemma](dp/sieve.md)

[Next Element Array technique used in various AND, OR, bitwise problems](dp/next-array.md)

[Matrix Exponentiation Trick](dp/matrixexpo.md)

</details>


<details markdown="1">
<summary>Game Theory
</summary>
	
---

[Games on arbitrary graphs](games/games.md)

[NIM games](games/games.md)

[Sprague Grundy Theorem](games/games.md)

[Converting games to NIM forms using MEX](games/games.md)

[Strategize the game backward, Parity Tricks](games/games.md)

[Tag games on Trees, Graphs](games/games_on_graphs.md)

</details>


<details markdown="1">
<summary>Range Queries
</summary>

---
	
[Binary Lifting, LCA of trees](range-queries/query.md)

[Fenwick Tree, 1D, 2D, difference array trick](range-queries/query.md)

[Sparse Table](range-queries/query.md)

[Segment Tree 1D, 2D, Lazy Propagation](range-queries/query.md)

[Merge Sort Tree](range-queries/query.md)

[Sqrt Decomposition](range-queries/query.md)

[Counting Inversions using Fenwick Tree](range-queries/query.md)

[Order Statistics using Fenwick Tree](range-queries/query.md)

[Classical Fenwick Tree application in DP, Coordinate Compression](range-queries/query.md)

[Segment Tree, Bit manipulation and Lazy propagation](range-queries/query.md)

[Get the nearest element from a given element in a range](range-queries/query.md)

[Ordered Statistics using PBDS](range-queries/ordered_sets.md)

[Interesting RMQ problems from SPOJ](range-queries/spoj-rmq-sprint.md)

[Some non-trivial ideas in RMQ/RSQ](range-queries/non-trivial-examples.md)

[MO's algorithm for RSQs and RMQs](range-queries/mo_query_trick.md)

</details>


<details markdown="1">
<summary>String Algorithms
</summary>

---
	
[Minimum Palindromic Cuts](string/adhoc-strings.md)

[Scatter Palindromes](string/adhoc-strings.md)

[Distinct Subsequences](string/adhoc-strings.md)

[Don't be a Subsequences](string/adhoc-strings.md)

[KMP function, Z algorithm, periodicity of strings](string/kmp.md)

[Polynomial Hashing aka Rolling Hash](string/polyhash.md)

[Rabin Karp, Lexicographically minimal shift, double hashing](string/polyhash.md)

[Fun with Palindromes](string/palindrome.md#fun-with-palindromes)

</details>


<details markdown="1">
<summary>Miscellaneous Stuff
</summary>

---

[K-Majority Voting algorithm aka Boyer-Moore](others/voting.md) 

[Some useful bit hacks, bitsets](others/bit-hacks.md)

[Bitset Magic and DP optimizations](others/bitsets.md)

[Minimum, Maximum XOR values of pair of numbers](others/classical_ideas.md)

[Coordinate Compression](others/coordinate-compression.md)

[Ternary Search for unimodal data](others/ternery-search.md)

[Some non-trivial tricks used in DP and Graphs](gym/weekly-algorithm-sheet)

[Some variants of Knapsack problem](others/knapsack.md)

[All about permutations and transpositions](others/permutation.md)

[CF blog: Collection of little techniques](https://codeforces.com/blog/entry/100910)

</details>

---



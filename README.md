# CP Hack Tools

<details markdown="1"> 
<summary> My Programming Template
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

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	#ifdef _INPUT
	freopen("input.txt", "r", stdin);
	#endif 

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
<summary> Number Theory Template 
</summary>

```cpp
vector<int> p; 
int sieve [MAXN]; 
auto sievef = [&] (int MAXN) -> void {
    sieve[1] = 1;
    for (int i = 2; i < MAXN; i++){
        if (sieve[i]) continue;
        p.emplace_back (i); 
        for (int j = i; j < MAXN; j += i){
            if (!sieve[j]) sieve [j] = i; 
        }
    }
};

auto factor = [&](int n) -> vector<pii> {
    vector<pii> res;
    for (int &x : p){
        if (x * x > n) break;
        else if (n % x) continue;
        res.emplace_back (x, 0); 
        while (n % x == 0) {
            res.back().se++; 
            n /= x; 
        } 
    }
    if (n > 1) res.emplace_back (n, 1); 
    return res; 
};

vi divisors (int n) {
    vi d = {1};
    while (n > 1){
        int m = 0;
        int q = sieve[n];
        while (n % q == 0) { m++; n /= q; }
        int dsize = d.size();
        int pw = q; 
        for (int i = 0;i < m; i++) {
            for (int j = 0; j < dsize; j++) d.emplace_back (d[j] * pw);
            pw *= q;
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
/* Usage: DSU S(n); S.unite (1, 2); S.totalSize(2); */

struct DSU {
	vector <int> par, size_;
	int biggest; 
	DSU (int n) : par (n+1), size_(n+1, 1), biggest(1) { 
		for (int i=0;i<=n;i++) par[i] = i;
	}
	int root (int u) {
		if (par[u] == u) return u; 
		return par[u] = root (par[u]);
	}
	void unite (int u, int v){
		int ru = root(u), rv = root(v); 
		if (ru == rv) return; 
		if (rand() & 1) swap (u, v); 
		size_[rv] += size_[ru];
		par[ru] = rv;
		chmax (biggest, size_[rv]); 	
	}

	int totalSize (int u) {
		return size_[root(u)]; 
	} 
};
```

</details>

<details markdown="1">
<summary> Segment Tree Template
</summary>

```cpp
/* 1-based segment tree template */
// $set : infinite, ST_MAX, Node constructor, combine code


const int ST_MAX = <>;
int _array[ST_MAX];
const int infinite = <>;

struct Node{
    // 0. add node variables and constructors 
    // int node_variables;
	int val;	
	Node () {
		val = infinite; 
	} 
	Node (int val) : val (val) {} 
};

int _n; // $ set _n 
class SegmentTree {
    public:
		
        Node *_t;
    public:
        
        SegmentTree (int n) {
            _n = n;
            _t = new Node[_n*6]; 
        }

        Node combine (Node lc, Node rc){
            Node res;
            /* 1. add your combine code along with empty node  */
			if (lc.val == infinite) return rc; 
			else if (rc.val == infinite) return lc; 
			int va = max (lc.val, rc.val);  
            return Node (va);
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
/* Segment Tree tested*/
```
</details>

<details markdown="1">
<summary> Hashing Template 
</summary>

```cpp
struct HashInt {
	static const int mx=1e9+7, my=1e9+9;
	long long x, y;
	HashInt () = default;
	HashInt (long long x_) : x(x_), y(x_) {}
	HashInt (long long x_, long long y_) : x(x_), y(y_) {}
	HashInt operator + (const HashInt& other) const{
		HashInt tmp; 
		tmp.x = (x + other.x) % mx;
		tmp.y = (y + other.y) % my;
		return tmp;
	}
	HashInt operator - (const HashInt& other) const{
		HashInt tmp; 
		tmp.x = (mx + x - other.x) % mx;
		tmp.y = (my + y - other.y) % my; 		
		return tmp;
	}
	HashInt operator * (const HashInt& other) const{
		HashInt tmp; 
		tmp.x = (x * other.x) % mx;
		tmp.y = (y * other.y) % my; 		
		return tmp;
	}
	bool operator == (const HashInt& other) const{
		return x == other.x && y == other.y;
	}
	operator pair<long long ,long long> () const {
		return make_pair (x, y);
	}
}; 

namespace RollHash{
	const int P=239017, N_ = 9e5+4;
	HashInt p[N_], H[N_];
	<always call init before initializing test cases> 
	void init() { 
		p[0] = 1;
		for (int i=1;i<N_;i++){
			p[i] = p[i-1] * P; 
		}
	}
	void gen_hashes (const string& str){
		int n = str.size();
		H[0] = str[0];
		for (int i=1;i<n;i++){
			H[i] = H[i-1] * P + str[i];
		}
	}
		
	HashInt hasher (int l, int r) { return l ? H[r] - H[l-1] * p[r-l+1] : H[r]; }
};

using namespace RollHash;
```
</details>



<details markdown="1">
<summary> Sliding Window Template 
</summary>

```cpp
for(int l=0,r=-1;l<n;l++){ // left boundary of the sliding window
	r = max(r, l-1);
	while(r+1 < n){
		/* modify the window*/
		if extendible? 
			r++;
		else 
			/* rollback window  */ 
		break;

		if(chmax(max_length, r-l+1)){
			// record answer from window
		}
	}
	// modify window to delete left boundary to proceed to the next, l++ happens
}
```

</details>

<details markdown="1">
<summary> MO Query Template 
</summary>

```cpp
int B; 

struct Query{

	int l, r, idx; 
	pair<int, int> toPair () const {
		int b = l/B; 
		return {b, (b&1)?-r:r};
	}
	bool operator < (const Query& other) {
		return toPair () < other.toPair();
	}
};

long long curr = 0; 
void add (int); 
void remove (int);

void solve_offline (vector<Query> q) {
	sort (all(q));
	int currL = 1, currR = 1;
	add (arr[1]); 	
	for (int Q: q){
		int L,R,idx; 
		while (L < currL) add (arr[--currL]);	
		while (R > currR) add (arr[++currR]);
		while (L > currL) remove (arr[currL++]); 
		while (R < currR) remove (arr[currR--]);
		answer[idx] = curr;
	}
} 
```

</details>


<details markdown="1">
<summary> Ordered Set Template 
</summary>
	
```cpp
	struct RBTree { 
	typedef tree<pii, 
			null_type, 
			less<pii>,
			rb_tree_tag, 
			tree_order_statistics_node_update> ord;
	ord s;
	int _t;
	
	RBTree() {  
		_t = 0;
	}
	void emplace (int x) { s.insert ({x, ++_t});  }
	void erase (int x) { s.erase (s.lower_bound({x, 0})); }
	int less_than (int x) { return s.order_of_key({x, 0}); }
	int less_eq (int x) { return s.order_of_key({x+1, 0}); }
	int find_nth (int n) { 
		if (s.find_by_order(n) == s.end()) return -1;
		return s.find_by_order(n)->first;
	}
};	
```
</details>

<details markdown="1">
<summary> Double Precision Arithmetic
</summary>

```cpp
const double EPS = 1e-9;
bool chequal (double a, double b) {
    return abs (a - b) < EPS; 
}

double L2norm (pair<double, double> a, pair<double, double> b){ 
    return sqrt (pow(a.fi - b.fi, 2) + pow(a.se - b.se, 2)); 
}

cout << setprecision (12) << fixed; 
```

</details>


### Useful Notes

---

<details markdown="1">
<summary>Trees and Graphs (27)
</summary>

---

[1. Cyclicity in undirected graph](graph/graph.md#a)

[2. Cyclicity in directed graph, coloring technique](graph/graph.md#b)

[3. All simple cycles in a undirected graph, w/o composite cycles](graph/graph.md#c)

[4. All tricks using union-find algorithm](graph/graph.md#d)

[5. Small to Large Trick, Merger Sets, a DSU trick](graph/dsu.md)

[6. Tarjan's algorithm to find articulation points, bridges](graph/graph.md#e)

[7. Finding transitive closure of a graph using Floyd Warshall](graph/graph.md#g)

[8. BFS on complement graph aka Pie for a Pie trick](graph/graph.md#h)

[9. All topological ordering](graph/graph.md#i)

[10. Kahn's algorithm for topological ordering](graph/graph.md#j)

[11. Maximal/Minimal Topological ordering](graph/graph.md#k)

[12. Floyd Warshall for finding shortest paths](graph/graph.md#l)

[13. Minimum Spanning Tree, Prim vs Kruskal](graph/graph.md#m)

[14. Dijkstra's shortest path algoritm for non-negative edges](graph/graph.md#o)

[15. Kth shortest path and ghostness in dikjstra's algorithm](graph/graph.md#o1)

[16. Use Bellman Ford for negative edge weights](graph/graph.md#p)

[17. Detect negative cycle using Bellman Ford](graph/graph.md#q)

[18. Shortest Cycle in undirected graph using BFS](graph/graph.md#q1)

[19. 0/1 BFS Trick](graph/graph.md#r)

[20. Strongly connected component aka SCC](graph/graph.md#s)

[21. Kosaraju's algorithm for condensed SCC](graph/graph.md#t)

[22. Finding centeroid a tree, subtree, cut tree](graph/centeroid.md)

[23. Euler Tour, relation between vertices, propagating tree](graph/euler-tour.md)

[24. Everything about Trie](graph/trie.md)

[25. Trie and binary MEX](graph/trie.md)

[26. Bit prefix Trie and XOR operations](graph/trie.md)

[27. Games on Trie](graph/trie.md)

</details>

<details markdown="1">
<summary>Mathematical Techniques (28)
</summary>

---
	
[1. Custom Ceil Function](math/math.md#a)

[2. Lazy Caterer](math/math.md#b) 

[3. Chinese Remainder Theorem](math/math.md#c) 

[4. Derangement](math/math.md#d) 

[5. Chicken Mcnugget Theorem](math/math.md#e) 

[6. Erdos Szekeres Theorem](math/math.md#f) 

[7. Cyclicity](math/math.md#g)

[8. Parity of Permutation](math/math.md#h) 

[9. Rank in Arbitrarty Bases](math/math.md#i) 

[10. Floyd Cycle](math/math.md#j) 

[11. Manhattern Trick](math/math.md#k) 

[12. Complexity of Euclid's dvision Lemma](math/math.md#o)

[13. Subsequence to Subarray Transformation Trick](math/math.md#l)

[14. Some properties of sum of absolute differences aka SAD](math/sad.md)

[15. How to solve diophantine equations](math/diophantine.md#a)

[16. Gaussian Elimination in GF(2), Max XOR Subsequence](math/gaussian-elimination.md)

[17. Euclid extended division algorithm for LCM/GCD](math/gcd-lcm.md)

[18. Catalan Number, Dyck Path](math/combinatorics.md#a)

[19. Inclusion Exclusion Principle](math/combinatorics.md#b)

[20. Prime Factorization, Sieve, Divisors of Large numbers](math/prime-factorization.md)

[21. Minimum Excludent aka MEX](math/mex.md)

[22. No. of Co-prime pairs](math/cses.md)

[23. Meet in the Middle aka MiTM](math/cses.md)

[24. Generating Functions](math/generating_functions.md)

[25. Difference Array, Sort, Repeat](math/math.md#p)

[26. Expected Value Problems](math/expected_value.md)

[27. Hockey Stick Identity](math/math.md#o)

[28. Catalan Number and problems with producer, consumer](math/math.md#o)


</details>

<details markdown="1">
<summary>
Greedy Techniques (20)
</summary>

---

[1. Minimum Increment Decrement to make array equal](greedy/adhoc_greedy.md)
	
[2. Largest Area in a Histogram using NGE](greedy/adhoc_greedy.md)

[3. Intermediate Value Property Trick](greedy/adhoc_greedy.md)

[4. Job Sequencing Problems](greedy/adhoc_greedy.md)

[5. A Nice Binary Search Trick](greedy/adhoc_greedy.md)

[6. Find frequency of element in a given range using upperbound, lowerbound](greedy/adhoc_greedy.md)

[7. All techniques using exchange arguments, powerful proving technique](greedy/exchange-arg.md)

[8. Invariance and Extremal Ideas](greedy/invariance.md)

[9. Generic sliding window algorithm](greedy/sliding-window.md)

[10. Comparing a subarray with a sliding window technique](greedy/sliding-window.md)

[11. Find closest pair, minimum euclidean distance](greedy/sweepline.md)

[12. Klee's algorithm for union of intersecting segments](greedy/sweepline.md)

[13. Intervals and Schedules](greedy/interval.md)

[14. UpperBound and LowerBound on Tuples](greedy/adhoc_greedy.md)

[15. Change of slope trick](greedy/adhoc_greedy.md)

[16. Linear Transformation trick](greedy/adhoc_greedy.md)

[17. Median Trick](greedy/adhoc_greedy.md)

[18. Knapsack with weights from a permutation](greedy/adhoc_greedy.md)

[19. Non-Degenerate Triangles](greedy/adhoc_greedy.md)

[20. Average Trick](greedy/adhoc_greedy.md)


</details>


<details markdown="1">
<summary>Dynamic Programming (18)
</summary>

---

[1. Max Subarray Sum, Kadane's algorithm](dp/adhoc-dp.md)

[2. Max Subarray Product](dp/adhoc-dp.md)

[3. All variants of buy-sell share problems](dp/adhoc-dp.md)

[4. Bitmasking: Assigment Problem](dp/bitmask.md)

[5. Bitmasking: Held Karp for TSP like problem](dp/bitmask.md)

[6. Masking over Primes](dp/bitmask.md)

[7. Enumerating submasks](dp/bitmask.md)

[8. Profile DP, DP on broken pipes](dp/bitmask.md)

[9. All tricks in digit DP problems, including LCM trick, pair of numbers](dp/digit-dp.md)

[10. Divisibility problems using DP](dp/divisibility.md)

[11. Everything about IN-OUT dp on tree aka Rerooting technique, Tree Distances, Tree Matching](dp/dp-on-trees.md)

[12. Inclusion and Exclusion DP](dp/dp-on-trees.md)

[13. Solving any structural dp problems using kadane's approach](dp/dp_tricks.md)

[14. Subsequence & Substring comparison of two strings type problems](dp/subsequence_dp.md)

[15. Everything about Sieve of Eratosthenes, Prime Factorization, Harmonic Lemma](dp/sieve.md)

[16. Next Element Array technique used in various AND, OR, bitwise problems](dp/next-array.md)

[17. Matrix Exponentiation Trick](dp/matrixexpo.md)

[18. DP on Rings](dp/dp_on_ring.md)

</details>


<details markdown="1">
<summary>Game Theory (6)
</summary>
	
---

[1. Games on arbitrary graphs](games/games.md)

[2. NIM games](games/games.md)

[3. Sprague Grundy Theorem](games/games.md)

[4. Converting games to NIM forms using MEX](games/games.md)

[5. Strategize the game backward, Parity Tricks](games/games.md)

[6. Tag games on Trees, Graphs](games/games_on_graphs.md)

</details>


<details markdown="1">
<summary>Range Queries (15)
</summary>

---
	
[1. Binary Lifting, LCA of trees](range-queries/query.md)

[2. Fenwick Tree, 1D, 2D, difference array trick](range-queries/query.md)

[3. Sparse Table](range-queries/query.md)

[4. Segment Tree 1D, 2D, Lazy Propagation](range-queries/query.md)

[5. Merge Sort Tree](range-queries/query.md)

[6. Sqrt Decomposition](range-queries/query.md)

[7. Counting Inversions using Fenwick Tree](range-queries/query.md)

[8. Order Statistics using Fenwick Tree](range-queries/query.md)

[9. Classical Fenwick Tree application in DP, Coordinate Compression](range-queries/query.md)

[10. Segment Tree, Bit manipulation and Lazy propagation](range-queries/query.md)

[11. Get the nearest element from a given element in a range](range-queries/query.md)

[12. Ordered Statistics using PBDS](range-queries/ordered_sets.md)

[13. Interesting RMQ problems from SPOJ](range-queries/spoj-rmq-sprint.md)

[14. Some non-trivial ideas in RMQ/RSQ](range-queries/non-trivial-examples.md)

[15. MO's algorithm for RSQs and RMQs](range-queries/mo_query_trick.md)

</details>


<details markdown="1">
<summary>String Algorithms (8)
</summary>

---
	
[1. Minimum Palindromic Cuts](string/adhoc-strings.md)

[2. Scatter Palindromes](string/adhoc-strings.md)

[3. Distinct Subsequences](string/adhoc-strings.md)

[4. Don't be a Subsequences](string/adhoc-strings.md)

[5. KMP function, Z algorithm, periodicity of strings](string/kmp.md)

[6. Polynomial Hashing aka Rolling Hash](string/polyhash.md)

[7. Rabin Karp, Lexicographically minimal shift, double hashing](string/polyhash.md)

[8. Fun with Palindromes](string/palindrome.md#fun-with-palindromes)

</details>


<details markdown="1">
<summary>Miscellaneous Stuff (11)
</summary>

---

[1. K-Majority Voting algorithm aka Boyer-Moore](others/voting.md) 

[2. Some useful bit hacks, bitsets](others/bit-hacks.md)

[3. Bitset Magic and DP optimizations](others/bitsets.md)

[4. Minimum, Maximum XOR values of pair of numbers](others/classical_ideas.md)

[5. Coordinate Compression](others/coordinate-compression.md)

[6. Ternary Search for unimodal data](others/ternery-search.md)

[7. Some non-trivial tricks used in DP and Graphs](gym/weekly-algorithm-sheet)

[8. Some variants of Knapsack problem](others/knapsack.md)

[9. All about permutations, transpositions and inversion count](others/permutation.md)

[10. CF blog: Collection of little techniques](https://codeforces.com/blog/entry/100910)

[11. Contribution Technique](others/contribution_technique.md)

</details>

---



MO's algorithm for RSQs and RMQs 

Source: http://blog.anudeep2011.com/mos-algorithm/ (#wayback machine)

Problem: Given an array [a1, a2, a3, a4...,aN] and M queries [l,r]. Answer each query in O(M+N) SQRT N.

Trick: Go offline! Reorder the queries in such a way such that we gain the sqrt optimization.

Let us see what happens if we sort by l values. [1,2], [2,N]. So we have to travel 2 to N for next query. Next query we have 3,4. We come back N to 4. So for each query it
takes N. Total MN complexity. This surely does not work. Same goes true for r values. 

Magic: Bucket each query into SQRT N blocks and sort them and then sort according to r values.

Proof of complexity: r pointer moves atmost N times for each bucket. So N * SQRT N complexity. 
l pointer moves at most SQRT N times inside a block. There are M queries. so M * SQRT N complexity!  

Standard Structure: 

```cpp
/*
		MO's algorithm implementation 
*/
 
struct Query{
	int l,r,idx;
};
 
int n,q;
const int N = 3e5+5, Q = 2e5+5, A = 1e6+3;
map<pii,int> idx; 
int a[N], Ans[N]; 
Query queries[Q];
int freq[A];
 
int s = 0;
 
void add(int idx){
	freq[a[idx]]++;
	if(freq[a[idx]]==1) s++; 
}
 
void remove(int idx){
	freq[a[idx]]--;
	if(freq[a[idx]]==0) s--; 
}
 
int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i];
	
	cin >> q;
	for (int i=0;i<q;i++){
		int l,r; cin >> l >> r;
		queries[i].l = l-1;
		queries[i].r = r-1;
		queries[i].idx = i;
	}
	
	int w = (int) sqrt(n); 
	
	sort(queries, queries+q, [&](const Query &a, const Query &b)->bool{
		if(a.l/w!=b.l/w) return a.l/w < b.l/w;
		else{
			return a.r < b.r; 
		}
	});
	
	int currL = 0, currR = -1;
		
	for (int i=0;i<q;i++){
		
		auto query = queries[i];
		
		while(currL > query.l){
			currL--;
			add(currL);
		}
		
		while(currR < query.r){
			currR++;
			add(currR);	
		}
		
		while(currL < query.l){
			remove(currL);
			currL++;
		}
		
		while(currR > query.r){
			remove(currR);
			currR--;
		}
		
	
		Ans[query.idx] = s; 
	}
	
	for(int i=0;i<q;i++) cout << Ans[i] << endl;
	
	return 0;
}
```

#### Alternative sorting order in MO's algorithm 

Canonical version of MO can be improved by sorting even blocks in reverse order of r values.

```cpp
struct Query {
	int l, r, idx;
	
	inline pair<int, int> toPair() const {
		return make_pair(l / block, ((l / block) & 1) ? -r : +r);
	}
};
```

MO's algorithm can be further improved to get O(n SQRT Q) complexity. 

Trick 1: Use a const block size = n / SQRT(Q). Ref: https://codeforces.com/blog/entry/61203?#comment-451304

Trick 2: Use space filling curves like Hilbert curve.  Ref: https://codeforces.com/blog/entry/61203

Practice Problems: 

* Powerful array – CF Div1 D
* DQUERY – SPOJ
* GERALD07 – Codechef
* Tree and Queries – CF Div1 D
* Jeff and Removing Periods – CF Div1 D
* Sherlock and Inversions – Codechef

#### Problems of MO's algorithm

1. https://codeforces.com/contest/617/problem/E

```cpp
int n,m,k; 

int B; 
const int N = 100004;
ll arr[N], Ans[N]; 

struct Query{ 
    int l,r,idx; 
    inline pii toPair() const {
        int block = l/B;
        return mp(block, (block & 1) ? -r : r); 
    }
};

const int A = 1 << 21; 
ll cnt[A];

ll mo_window_answer = 0; 

void add (int val) {
    mo_window_answer += cnt[val xor k]; 
    cnt [val] ++; 
} 

void remove (int val) {
    cnt [val] --;
    mo_window_answer -= cnt[val xor k]; 
}

Query q[N]; 

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
    
	
	cin >> n >> m >> k;
	
	for (int i=1;i<=n;i++) cin >> arr[i]; 
	for (int i=1;i<=n;i++) arr[i] = arr[i] xor arr[i-1]; 
	
	for (int i=0;i<m;i++) {
		int l,r; cin >> l >> r;
		q[i] = { --l,r,i}; 
	}

	B = sqrt(n); 
	
	sort (q, q+m, [&](const Query &x, const Query y)->bool{
		return x.toPair() < y.toPair(); 
	});

	int currL = 1, currR = 1;
	add (arr[1]); 

	for (int i=0;i<m;i++) {
	
		Query tmp = q[i];
		int L = tmp.l, R = tmp.r, index = tmp.idx; 
		
		while (L < currL) add (arr[--currL]);	
		while (R > currR) add (arr[++currR]);
		while (L > currL) remove (arr[currL++]); 
		while (R < currR) remove (arr[currR--]);
		
		Ans [index] = mo_window_answer; 
	}

	for (int i=0;i<m;i++) cout << Ans [i] << endl;

	return 0;
}
```

2. No of inversion count in a range l...r (offline)

```cpp
const int N = 2e5 + 5;
int B; 

struct ${
    int l,r,idx; 
    inline pii toPair() const {
        int bid = l/B; 
        return mp(bid, (bid & 1) ? -r : r); 
    }
} q[N]; 

int n,m; 
int arr[N+3], b[N+3]; 

/* Fenwick for the l...r window */

ll fen[N+3], res[N+3];
void update (int i, int val) { for (;i<N;i+=i&-i) fen[i] += val;  }
ll query (int r) {
    ll ans = 0;
    for (;r>0;r-=r&-r) ans += fen[r];
    return ans; 
}

/* Fenwick for the l...r window */

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i=0;i<n;i++) { 
	    cin >> arr[i]; 
	    b[i] = arr[i]; 
	}
	
	sort (b, b+n);
	int cnt = 0; 
	map<int, int> coord; 
	for (int i=0;i<n;i++){ 
	    int val = b[i]; 
	    coord[val] = ++cnt;
	    while (i+1<n && val == b[i+1]) i++;  
	}
	
	for (int i=0;i<n;i++) {
		arr[i] = coord[arr[i]];
	}
	
	B = sqrt(N); 

	for (int i=0;i<m;i++) {
	    cin >> q[i].l >> q[i].r; 
	    q[i].l--, q[i].r--;
	    q[i].idx = i; 
	}
	
	sort (q, q+m, [&](const $ &x, const $ &y)->bool{
	    return x.toPair() > y.toPair(); 
	});
	
	int currL = 0, currR = -1;
   	
   	long long ans = 0; 
    
	for (int i=0;i<m;i++) {
	    int L,R,idx; 
	    L = q[i].l, R = q[i].r, idx = q[i].idx;  
	    
	    while (L < currL) {
	        int val = arr[currL - 1]; 
	        ans += query(val-1); // smaller than val  
	        update (val, +1);
	        currL--;
	    } 
	    while (R > currR){
	        int val = arr[currR + 1];
	        ans += query(n+1) - query(val); // greater than val
	        update (val, +1); 
	        currR++; 
	    }
	    while (L > currL){
	        int val = arr [currL]; 
	        update (val, -1); 
	        ans -= query(val-1); // smaller than val
	        currL++; 
	    }
	    while (R < currR){
	        int val = arr [currR]; 
	        update (val, -1); 
	        ans -= query(n) - query(val); // greater than val 
	        currR--;
	    }
	    	    
	    res[idx] = ans; 
	}
	
	for (int i=0;i<m;i++) cout << res[i] << endl;
```


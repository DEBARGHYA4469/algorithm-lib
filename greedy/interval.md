# Interval based problems

## Given a set of intervals <[l,r]>, and a target interval X: [L,R]. What is the minimum number of intervals used to cover X?

Idea 1: Jump Game type solution. Constraints: [MAX - MIN] < 10^5, or else use coordinate compression to make MAX-MIN ~ O(N).

Code: 

```cpp
int right[4*N];
for (int i=0;i<N;i++) chmax (right[max(X.L, intervals[i].L)], intervals[i].R);

int max_reach = right[X.L], ladder = max_reach, count = 0; 
bool ok = right[X.L] >= X.L; 
for (int i=X.L+1;i<=X.R;i++){
if (i==ladder+1){
		count++; 
ladder = max_reach; 	
ok &= (i <= ladder);
}
chmax (max_reach, right[i]); 
}

cout << (ok ? count:-1) << endl;  
```

Complexity : O(N) 

Idea 2: eg. Video Stiching problem leetcode. 
	Note: [1, 3]., [4, 5] cannot be stitched. R[i] >= L[i] for stitch. 

	Making it more generic, lets say you have to cover X: [L, R]
 
 ```cpp
sort(all(intervals, [&](const vector<pii> &a, const vector<pii> &b){
	return a.fi != b.fi ? a.fi < b.fi : a.se > b.se; 
}));
int N = sz(intervals), Ans=1, max_reachable, ladder;
int i=0;
for(; intervals[i].fi<=L; i++) chmax (max_reachable, interval[i].se); 
for(;i<N;i++){
	if(ladder>=R) return Ans; 
	if(interval[i].fi > max_reachable) return -1; 
	else{
	if(interval[i].fi>ladder){
		Ans++;
		ladder=max_reachable; 
}
chmax (max_reachable, interval[i].se); 
}
}
if(ladder>=R) return Ans; 
Ladder = max_reachable; 
Return ladder>=R ? ++Ans, -1; 
```

Complexity: O(NlogN)
	
	
## Given a set of intervals <[l,r]>. Merge the intervals into non-overlapping intervals. 

Idea 1: 

	Code: 
```cpp
sort(all(intervals));
Int start,end; 
tie(start, end) = intervals[0];
Int n = sz(intervals);
vector<pii> Ans;  
for (int i=1;i<n;i++){
	if(intervals[i].fi<=end) chmax(end, interval[i].se);
	else{
	Ans.eb(start, end);
tie(start, end) = interval[i]; 
}
}
Ans.eb(start, end); 		
```
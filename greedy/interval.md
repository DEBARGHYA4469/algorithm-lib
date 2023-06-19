# Intervals

### Given a set of intervals <[l,r]>, and a target interval X: [L,R]. What is the minimum number of intervals used to cover X?

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

Simple Implementation

```cpp
int Ans = 0;
int ladder=0, max_reach=0;
sort(all(intervals));
for (int i=0;ladder<T;ladder=max_reachable, ++Ans){
	for(;i<N && interval[i].fi <= ladder;++i) chmax(max_reachable, interval[i].se);
	if(ladder == max_reachable) return -1;
}
``` 
	
### Given a set of intervals <[l,r]>. Merge the intervals into non-overlapping intervals. 

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
# Schedules

### Given a set of jobs [starts at, ends at]. How many maximum jobs can you schedule in a single processor?  


Solution: The first job is always the job with the leftmost "ends at". You can always exchange any other job for this. (Exchange Argument). 
Sort by ends at. Pick a job and move to the next job. If the next job is overlapping skip, else pick that job.  

### Given a set of jobs [starts at, ends at]. Can you schedule the jobs in 2 processors?

Solution: Pick a job within a minimum start time. and run the job in one of the processors. Now pick the next one. If it fits in either select any if not select the one where it fits. If not, it is impossible to schedule.  

### Given a set of jobs [starts at, ends at]. What is the minimum no of processors to schedule all of them? 

Solution: Minimum no of processors is the time where they intersect most. Use +1 for ( and -1 for ). Min no of processors is the maximum value at any time.
Now how to find the schedules? 

- Sort using start time.
- Schedule ith job in any processor where it fits.
- To find any processor where it fits. Store the processors in increasing order of their end time. Select the heap top.  
- If it does not fit, increases processor count by 1. 

Complexity = NlogN 

### Given a set of jobs [time required, due time]. What is the minimum value of maximum lateness max(0, finish time - due time) across all jobs? 

Solution: 

- Consider two jobs one after another a, b.
- If a|b. Lateness = t[a] + t[b] - d[b]
- If b|a Lateness = t[a] + t[b] - d[a].
- If d[b] < d[a]. we should switch to b|a. Exchange argument.
- Hence sort by their due time and schedule one after another.

### Given a set of jobs [starts at, ends at, profit]. Select a subset of non-overlapping jobs to maximize profit. 

Solution:

- Let dp[i] : denote max profit scheduling jobs 1...N
- Transition:
    	- Sort the jobs based on their end-times.
	- If you schedule job i, you can schedule jobs j, end-time[j] < start[i].
   	- Let j be largest such j.
   	- dp[i] = max(dp[i-1], dp[j] + profit[i])
   	- How to find j?
   	- j = *(--upper_bound(v, v+m, start[i]))
 
  Complexity: NlogN

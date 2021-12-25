#### Proving greedy approaches [Invariance+Extremal Principle] 

### Problem: 1  https://codeforces.com/contest/1579/problem/D

<li> Coming up with optimal solution is ez, proving it is hard. Here goes my proof. </br>
<li> <a href="https://www.codecogs.com/eqnedit.php?latex=S&space;=&space;{a_1,a_2,a_3,...,a_N}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?S&space;=&space;{a_1,a_2,a_3,...,a_N}" title="S = {a_1,a_2,a_3,...,a_N}" /></a>
<li> Case 1: If S = sum of all elements, and S/2 <= max. element. We can show that max #operations is (S-max. element). </br>
<li> Argue by showing that max element can pair with max S-max. element. Rest all can be paired fullest. We can't do better!! </br>
<li> Case 2: If S/2 > max. element we show that we can follow a process as goes below:  </br>
<li> Choose a max element from the set, and reduce it by any(random other) element from the set till it is not maximum. </br>
  Then change max element and continue. </br>
<li> Let any configuration be (S,max. ele). We only change when max. (max. ele-t) >= a[x], the new configuration is (S-2t,a[x]). </br>
<li> Invariance is: S/2 > max. ele, in the new configuration, (S-2t)/2 = (S/2-t) > max. ele-t >= a[x], hence (S-2t,a[x]) maintains invariance. </br>
<li> Only thing remaining to see is that with such a invariance condition, we can always get an operation. Hence a[x] goes to 0. </br>
<li> Ans = S/2

**A more intuitive proof for case 2**. Assume that sum of the remaining element is more than the maximum element. We claim that we can always bring down the sum of the remaining element down to the maximum element and then we are done(trivial!). Only configuration which can't be reduced is [0,0,0,0,0,x], we can't bring it down to max means x>max. which is not possible

###  **Problem-2 https://www.codechef.com/problems/SWAPGAME**
  
<li> Consider two elements a and b. a and b will only add to the value if their order gets swapped. 

### Problem-3 **https://codeforces.com/contest/540/problem/E**

Use PBDS/Fenwick Tree + Coordinate Compression 
```cpp
  	cin >> n;
	vector<pair<int,int>> A;
	vector<int> v;
 	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		A.eb(mp(a,b));
		v.eb(a);
		v.eb(b);
	}
	
	sort(all(v));
	v.erase(unique(all(v)),v.end());	// remove the duplicate elements
	
	map<int,int> coor;
	for(int i=0;i<sz(v);i++) coor[v[i]] = i;
	
	vector<int> perm(sz(v));
	iota(all(perm),0);
 	
 	for(int i=0;i<n;i++){
 		int coor_x = coor[A[i].fi], coor_y = coor[A[i].se];
 		int tmp = perm[coor_x];
 		perm[coor_x] = perm[coor_y];
 		perm[coor_y] = tmp;
 	}
 	
 	ll ans=0;
 	for(int i=0;i<sz(v);i++) ans += abs((ll) v[perm[i]]- (ll) v[i])-abs((ll) perm[i]-(ll)i);
	
	ordered_set os;
	for(int i=sz(v)-1;i>=0;i--){
		ans += os.order_of_key(perm[i]); 
		os.insert(perm[i]);
	}
	
	cout << ans << endl; 
  	
```
	
### Problem 4: https://codeforces.com/contest/1593/problem/C

Idea: 
	<li> Claim: If there is a set of mice with their distances from hole sum to R and R < n. We can save all those mices. 
	<li> Greedily to maximize m (#mice), we choose to reduce each distances in a sorted fashion hence selecting from end makes sense.
	<li> Proof: If R >= n then,
	<li> We can't save all mice. Why? Let say we saved m-1 mice in time q. So position of cat = q & position of mth mice= R-q.
	R >=n so, R-q >= n-q. R-q+q >=n. Mice will be chased.
	<li> Consider R < n. Consider leftmost mice be positioned at l. So, R < n => R-(n-l) < l. 
	So when all the other cats reaches the hole, cat is still behind leftmost mice. So can be saved. 
												 
Invariance in the problem: Sum of distances of mice. 

												 
### Problem 5: 

In a round robin tournament, what is the maximum number of wins player ranked k can have? 

<li> Claim 1: In a greedy way let every player ranked i>k loses vs every player j<k. Minimum wins among bottom i teams i>k = C(N-k,2)
<li> Claim 2: No of wins left for top j<=k teams to disribute maintaining the condition= C(K,2). Kth player should win floor(C(K,2)/K) games among them. 
												 
![image](https://user-images.githubusercontent.com/21307343/138549750-d1eb8361-59e2-4cdb-b786-81915a972658.png)

https://codeforces.com/contest/1608/problem/C [Good greedy based problem]
					  
Idea 2: Graph Based. Standard trick: if A[i]->[A[i+1],A[i+2],....] for all i, consider only the edges with consecutive


### Problem 6: 
https://codeforces.com/contest/1615/problem/C 
	
Idea: Whenever there is some weird process going on, think about the bipartiteness, if btw consecutive operations some structure remains intact. Then greedily solve for the varying part.
						

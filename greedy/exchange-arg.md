## Exchange Argument

The basic idea behind exchange arguments is given an **optimal structure** can you convert it to a **sorted optimal structure**
based on some heuristics such that the optimality still holds.</br>

**Benifit**: For problem where we need to find the optimal structure we need to look for all permutations, we can look at the sorted 
structure and claim that each of the substructure in the sorted structure will be optimal so studying it is worth it.
Hence it reduces the time to linear.

This is the heart of many greedy and dp algorithms.

### Problem-1 (Boxes)
There are n boxes with weight wi and strength si. If one box can be placed over the other only if its weight is no greater than the strength of the bottom box.
What is the maximum possible no of boxes in the tower.

![aa](https://user-images.githubusercontent.com/21307343/131247711-a4bbdcc3-0071-4345-acbc-61b485d4ccd4.png)

Given an arrangement, under what circumstance it is always good to swap to boxes.
Let F be the force(wt) that the top of both arrangement can sustain. More the F better right!

<a href="https://www.codecogs.com/eqnedit.php?latex=\\Case:1\\&space;F&space;<&space;S_a,\:&space;F&plus;W_a<S_b&space;\implies&space;F<min(S_a,S_b-W_a)&space;\\Case:2\\&space;F&space;<&space;S_b,\:&space;F&plus;W_b<S_a&space;\implies&space;F<min(S_b,S_a-W_b)&space;\\if\:(S_a-W_b)&space;>&space;(S_b-W_a)&space;\\&space;\\F_{max}^1&space;<&space;F_{max}^2.&space;\:\:\:Proof:&space;Fix\:\:F_2\\&space;Choosing\:\:Case-II\:is\:\:optimal.&space;\\Exchange\:\:if\:\:S_a&plus;W_a&space;>&space;S_b&plus;W_b" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\Case:1\\&space;F&space;<&space;S_a,\:&space;F&plus;W_a<S_b&space;\implies&space;F<min(S_a,S_b-W_a)&space;\\Case:2\\&space;F&space;<&space;S_b,\:&space;F&plus;W_b<S_a&space;\implies&space;F<min(S_b,S_a-W_b)&space;\\if\:(S_a-W_b)&space;>&space;(S_b-W_a)&space;\\&space;\\F_{max}^1&space;<&space;F_{max}^2.&space;\:\:\:Proof:&space;Fix\:\:F_2\\&space;Choosing\:\:Case-II\:is\:\:optimal.&space;\\Exchange\:\:if\:\:S_a&plus;W_a&space;>&space;S_b&plus;W_b" title="\\Case:1\\ F < S_a,\: F+W_a<S_b \implies F<min(S_a,S_b-W_a) \\Case:2\\ F < S_b,\: F+W_b<S_a \implies F<min(S_b,S_a-W_b) \\if\:(S_a-W_b) > (S_b-W_a) \\ \\F_{max}^1 < F_{max}^2. \:\:\:Proof: Fix\:\:F_2\\ Choosing\:\:Case-II\:is\:\:optimal. \\Exchange\:\:if\:\:S_a+W_a > S_b+W_b" /></a>

### Problem-2  (Hero)

Hero has to fight some monsters. Fighting with each monster takes d[m] health and after monster dies, hero gets back a[m] 
health in the form of a potion. What is the min health to start the fight?

**Observation:**
<li> Lets call monsters whose d[i] > a[i] as bad others as good.
<li> Always good to exchange a good monster with a bad one if bad occurs early. If he started with H health, to fight good
one he will need d[good] and to fight bad one he has H-d[good]+a[good]=H+t(t>0). In the other case if he starts with H health, 
he fights bad one with H(less) and good with H-d[bad]+a[bad]=H-t. Both cases he loses. So good to exchange.
<li> Among the good ones, consider if a good monster A appears before a good monster B. 
<a href="https://www.codecogs.com/eqnedit.php?latex=\\H_1&space;>&space;max(d_A,d_B&plus;d_A-\alpha_A),\:\:\:d_A-\alpha_A<0&space;\\H_2&space;>&space;max(d_B,d_A&plus;d_B-\alpha_B),\:\:\:d_B-\alpha_B<0&space;\\if\:\:d_B<d_A:&space;H_{1,min}=d_A,&space;H_{2,min}&space;<&space;H_{1,min}.\:\:Exchange!!" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\H_1&space;>&space;max(d_A,d_B&plus;d_A-\alpha_A),\:\:\:d_A-\alpha_A<0&space;\\H_2&space;>&space;max(d_B,d_A&plus;d_B-\alpha_B),\:\:\:d_B-\alpha_B<0&space;\\if\:\:d_B<d_A:&space;H_{1,min}=d_A,&space;H_{2,min}&space;<&space;H_{1,min}.\:\:Exchange!!" title="\\H_1 > max(d_A,d_B+d_A-\alpha_A),\:\:\:d_A-\alpha_A<0 \\H_2 > max(d_B,d_A+d_B-\alpha_B),\:\:\:d_B-\alpha_B<0 \\if\:\:d_B<d_A: H_{1,min}=d_A, H_{2,min} < H_{1,min}.\:\:Exchange!!" /></a>
<li> Among the bad ones, consider if a bad monster A appears before a bad monster B. 
<a href="https://www.codecogs.com/eqnedit.php?latex=\\H_1&space;>&space;max(d_A,d_B&plus;d_A-\alpha_A),\:\:\:d_A-\alpha_A>0&space;\\H_2&space;>&space;max(d_B,d_A&plus;d_B-\alpha_B),\:\:\:d_B-\alpha_B>0&space;\\if\:\:d_B<d_A:&space;H_{2,min}=&space;d_A&plus;d_B-\alpha_B\\&space;Exchange\:\:if\:d_B&plus;d_A-\alpha_A>d_A&plus;d_B-\alpha_B&space;\implies&space;\alpha_B>\alpha_A\\&space;if\:\:d_B>d_A:&space;H_{1,min}=&space;d_B&plus;d_A-\alpha_A\\&space;Exchange\:\:if\:d_B&plus;d_A-\alpha_A>d_A&plus;d_B-\alpha_B&space;\implies&space;\alpha_B>\alpha_A\\&space;So,\:exchange\:if\:\:&space;\alpha_B&space;>&space;\alpha_A" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\H_1&space;>&space;max(d_A,d_B&plus;d_A-\alpha_A),\:\:\:d_A-\alpha_A>0&space;\\H_2&space;>&space;max(d_B,d_A&plus;d_B-\alpha_B),\:\:\:d_B-\alpha_B>0&space;\\if\:\:d_B<d_A:&space;H_{2,min}=&space;d_A&plus;d_B-\alpha_B\\&space;Exchange\:\:if\:d_B&plus;d_A-\alpha_A>d_A&plus;d_B-\alpha_B&space;\implies&space;\alpha_B>\alpha_A\\&space;if\:\:d_B>d_A:&space;H_{1,min}=&space;d_B&plus;d_A-\alpha_A\\&space;Exchange\:\:if\:d_B&plus;d_A-\alpha_A>d_A&plus;d_B-\alpha_B&space;\implies&space;\alpha_B>\alpha_A\\&space;So,\:exchange\:if\:\:&space;\alpha_B&space;>&space;\alpha_A" title="\\H_1 > max(d_A,d_B+d_A-\alpha_A),\:\:\:d_A-\alpha_A>0 \\H_2 > max(d_B,d_A+d_B-\alpha_B),\:\:\:d_B-\alpha_B>0 \\if\:\:d_B<d_A: H_{2,min}= d_A+d_B-\alpha_B\\ Exchange\:\:if\:d_B+d_A-\alpha_A>d_A+d_B-\alpha_B \implies \alpha_B>\alpha_A\\ if\:\:d_B>d_A: H_{1,min}= d_B+d_A-\alpha_A\\ Exchange\:\:if\:d_B+d_A-\alpha_A>d_A+d_B-\alpha_B \implies \alpha_B>\alpha_A\\ So,\:exchange\:if\:\: \alpha_B > \alpha_A" /></a>
 
```cpp
  void comparator(Monster &m1,Monster &m2){
        if(m1 is good && m2 is good){
              return m1.damage < m2.damage;
        }
        else if(m1 is good && m2 is bad){
              return 1;
        }
        else if(m1 is bad && m2 is good){
              return 0;
        }
        else if(m1 is bad && m2 is bad){
              return m1.health > m2.health;
        }
  }
```

 ### Altruistic Amphibians
 
 A set of frogs have accidentally fallen to the bottom of a large pit. Their only means of escaping the pit is to jump out of it. Each frog i is described by three parameters (li,wi,hi) where li is its leap capacity, wi its weight, and hi its height. The leap capacity specifies how high that frog can jump. If a frog's leap capacity is strictly larger than the depth of the pit, the frog can directly escape the pit. However, these frogs are altruistic. Rather than selfishly saving themselves and leaving the frogs with too limited leap capacity behind, they collectively aim to save as many of them from the pit as possible.

The frogs realize that if a frog A climbs up on the back of frog B before it jumps, the first frog A stands a better chance of escaping the pit: it can escape if hB+lA is strictly larger than the depth of the pit.

Furthermore, if frog B carrying frog A on its back climbs up on the back of frog C, the situation is even better for frog A: it can now escape the pit if hC+hB+lA is strictly larger than the depth of the pit.

The frogs can build even higher piles of frogs this way, the only restriction is that no frog may carry other frogs of weight in total amounting to its own weight or heavier. Once a pile has been used to allow a frog to escape, the frogs in the pile jump back to the bottom of the pit and they can then form a new pile (possibly consisting of a different set of frogs). The question is simply how many frogs can escape the pit assuming they collaborate to maximize this number?
 
 `Quick Idea: Let us suppose a solution exist, say F1, F2, F3, ....., FN where F1 escapes before F2. We can see that W1 < W2. Once we get a sorted domain of solution we can apply other constraints through dp.`  

###  Farm Craft (DP on Trees + Ex. Args) 
                                                                                                                             
You are given a rooted tree with n (n ≤ 105) vertices. You are in the root. Moving along an edge takes 1 minute. You want to visit all vertices and get back to the root as fast as possible, what takes exactly 2·(n - 1) minutes. When we visit vertex v for the first time, the countdown is started there and after av minutes that vertex will be "ready". We want to minimize the moment when all vertices are ready. When will it happen? </br>
 
 `Idea: Exchange two child vertex order if 2s[u]-f[u], s[u]: size of the subtree, f[u]: sol for vertex u.`
 
 ### Camel Train 
 
 https://atcoder.jp/contests/aising2020/tasks/aising2020_e
 
 Idea: 
 
 * Observation I: call all camels red for which l >= r, and all camels blue for which r > l. Claim: all red camels should come before all blue camels. (Exch can optimize further)
 * Observation II: for all red camels, you need to use [job sequencing algorithm](https://www.geeksforgeeks.org/job-sequencing-problem/) in a optimal way, similarly for blue camels. Using Priority Queue/ Max Heap, you can get O(nlogn) solution.
 

```cpp
struct camel{
	int k,l,r, diff;
};

bool operator<(const camel &ref1, const camel &ref2){
	return ref1.diff < ref2.diff;
}

bool operator>(const camel &ref1, const camel &ref2){
	return ref1.diff > ref2.diff;
}

const int N = 200005;
int tc,n;

void print(camel c){
	cout << c.k << "," << c.l << "," << c.r << endl;
}

int main(){
	
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> tc;
	while(tc--){

		cin >> n;
		vector<camel> red, blue;

		for(int i=0;i<n;i++){
			int k,l,r; cin >> k >> l >> r;
			struct camel tmp = {k,l,r,abs(l-r)};  
			if(l>=r) red.eb(tmp);
			else blue.eb(tmp);
		}

		ll ans = 0ll;

		sort(all(red), [&](camel ref1, camel ref2){
			return ref1.k < ref2.k;
		});

		priority_queue<camel> q;
		const int M1 = sz(red);
		int j = M1-1;

		for(int i=M1;i>=1;i--){
			while(j>=0 && red[j].k >= i){
				q.push(red[j--]);
			}
			if(!q.empty()){
				ans += q.top().l;
				q.pop();
			}
		}

		while(!q.empty()){
			ans += q.top().r;
			q.pop();
		}

		sort(all(blue), [&](camel ref1, camel ref2){
			return ref1.k < ref2.k;
		});

		const int M2 = sz(blue);
		j = 0;

		priority_queue<camel> q2;

		while(j<M2 && blue[j].k <= M1) q2.push(blue[j++]);

		for(int i=M1+1;i<=n;i++){

			if(!q2.empty()){
				ans += q2.top().r;
				q2.pop();
			}

			while(j<M2 && blue[j].k <= i){
				q2.push(blue[j++]);
			}
		}

		while(!q2.empty()){
			ans += q2.top().l;
			q2.pop();
		}

		cout << ans << endl;
 
	 
	}

	return 0;
}
```
				   
### Pinkie Pie Eats Patty Cakes
				   
https://codeforces.com/contest/1393/problem/C
				   
In this problem, given a string s, example: AABCCABAB, you have to rearrange the letters in such a way that min distance between any two similar characters is as large as possible
				   
Approach 1: O(n log n log n)

* Binary search on the distance.
* For a fixed distance. Idea is to take the character that is most frequent and has not occured in the last "distance" indices. 
* Why does this logic work? 
* ....solved.....|(a,b) . You have choice now to select a or b, & freq[a] > freq[b].
*  Exchanging (a,b) preserve optimality. How? Take cases 
* So might as well take the most frequent available character & process.
	
Approach 2: O(n)

* Let max frequency be m and it occures p times. 
* Make m-1 bins. 
* Now the smallest bin size should be maximum as possible. 
* Intuition: If you need to maximize the minimum, distribute equally.
* How to ensure nothing in the bin breaks the optimality?
* abc|.....|abc|.....|abc|....|abc|....|abc|....|abc|....|abc|....|abc
* Now, find the largest frequent element. Start putting in bins one by one. If any bins left on the right, start with the next one.
* Observe that the next element will not make a complete round trip once more. so distance remains the size of the smallest bin. 

### Doremy's City Construction
https://codeforces.com/contest/1764/problem/C
	


https://docs.google.com/spreadsheets/d/1hM7PbKN9GULMXMk_Vjf9HlFVROBp85VVwf3F0p4BZ_0/edit#gid=1508691920
Source : progvar.fun

GRAPH ALGORITHMS:			

Basic Implementation																
																			
1	HR Handshake															
2	CF330B - Road Construction															
3	CF574B - Bear and Three Musketeers															
4	CF292B - Network Topology															
5	CF402C - Searching for Graph								New Cpncept : Laman Graph Constructive Algorithm							
6	CF990D - Graph And Its Complement							Nice Construction							
7	CF22C - System Administrator															
9	ABC054 C - One-stroke Path								Simple Rec DFS with Bit masking							
10	ABC061 B - Counting Roads								Very Easy							
11	ABC073 D - joisino's travel								Excellent!! Steiner Tree: Floyd Warshall + BITMASK DFS							
12	ABC110 C - String Transformation							Very Very Nice Constructive Proof(Invariant based.) 							



Tree	Traversal															

1	HR Tree: Preorder Traversal															
2	HR Tree: Postorder Traversal															
3	HR Tree: Inorder Traversal															
4	HR Tree: Level Order Traversal															
5	CF115A - Party															
7	CF1244D - Paint the Tree							Easy DP on Trees							
8	CF61D - Eternal Victory								Easy 							
9	CF34D - Road Map															
10	CF14D - Two Paths								Excellent Example for Rerooting In-Out DP Technique							
11	UVa 12347 Binary Search Tree															
12	CF29D - Ant on the Tree								New Idea : DFS twice. Kinda similar to Morris Traversal							
13	ABC070 D - Transit Tree Path							Good Idea							
14	ABC126 D - Even Relation							Easy coloring proof							
15	ABC146 D - Coloring Edges on Tree						Good coloring problem . V. Easy 							
16	ABC148 F - Playing Tag on Tree							V. Good Optimal Strategy Game							




DFS	Connectivity	Cycle-Finding														

1	CF500A - New Year Transportation						V. Easy							
2	HR Journey to the Moon															
3	CF771A - Bear and Friendship Condition						Clique or Not ?  Complete Graph							
4	CF1263D - Secret Passwords															
5	CF500B - New Year Permutation															
6	CF475B - Strongly Connected City						Easy but Nice Problem							
7	UVa 11690 Money Matters								Easy But Good for practise							
8	CF177C2 - Party									DSU							
11	ABC075 C - Bridge								Bridges & Articulation Points Crystal Clear Concept							
12	ABC126 E - 1 or 2														
13	ABC142 F - Pure									Cool BFS with min Cycle.							
14	ABC157 D - Friend Suggestions							Another Good DSU							
15	ABC049 D - 連結 / Connectivity						      Excellent Trick! Intersection of Union Find Algorithm in O(1)							



5. Depth-First Search (Tutorial on CP Algorithms)																
6. Search for Connected Components in a Graph (Tutorial on CP Algorithms)																
7. Checking a Graph for Acyclicity and Finding a Cycle in O(M) (Tutorial on CP Algorithms)																

BFS	Unweighted SP															

1	HR Breadth First Search: Shortest Reach															
2	HR Snakes and Ladders: The Quickest Way Up															
3	CF1037D - Valid BFS?								One more trick with Sorting Adjacency list							
4	CF601A - The Two Routes								Shortest Cycle in a directed Graph							
5	CF1205B - Shortest Cycle							Very Nice: Shortest Cycle in a undirected graph							
6	CF689B - Mike and Shortcuts															
7	CF543B - Destroying Roads							Good Problem : LCA inspired.							
8	CF877D - Olya and Energy Drinks							Excellent Optimization over Simple BFS. Prune the uncessary queue update.							
9	HR Rust & Murderer								Modified BFS for Complement of Sparse Graph							
10	CF59E - Shortest Path								Excellent BFS Variant: Queueing Vector and its Parent.							
12	ABC132 E - Hopscotch Addict							Easy Variant of BFS							
13	ABC168 D - .. (Double Dots)							Simple Straight-foreward BFS							


Grid-Graphs																

1	CF377A - Maze								Easy Troll Question							
2	HR Count Luck								Easy Question							
3	CF510B - Fox And Two Dots						Straight Foreward							
4	HR KnightL on a Chessboard						Easy?? But is O(1) there?							
5	CF598D - Igor In the Museum						Easy							
6	CF540C - Ice Cave							Easy							
7	CF329B - Biridian Forest															
10	CF585B - Phillip and Trains						V.Good							



BiPartite Graph																

2	CF217A - Ice Skating															
3	CF277A - Learning Languages						Biparitite tranformation trick!!							
4	CF862B - Mahmoud and Ehab and the bipartiteness															
6	CF1012B - Chemical table															
10	CC FILLMTR - Fill The Matrix						Nice Bipartite Concept							
11	ABC131 F - Must Be Rectangular!						Excellent Idea: Variant of Ice-Skating. Walking along the grid....							
12	https://codeforces.com/contest/1594/problem/D				Bipartite, Nice concept. Think as undirected graphs!!							

Topological Sort																

2	CF510C - Fox And Names															
3	CF501C - Misha and Forest															
5	CF825E - Minimal Labels							Very Imp Concept: Minimum Topological Labelling.							
6	CF909E - Coprocessor							Kahn with Exchange Argument							
7	SPOJ- Toposort															



Topological Sorting (Tutorial on CP Algorithms)																


Union-Find									Trick: For pure delete: Reverse and use DSU							

1	HR Merging Communities															
3	CF722C - Destroying Array						Looks like dynamic connectivity but tricked by reverse DSU							
4	CF371D - Vessels															
7	ABC120 D - Decayed Bridges						Reverse DSU Trick!							


Disjoint-Set Union (Tutorial on CP Algorithms)																
Union-Find (Video Lectures from Princeton on Coursera)																


Minimum Spanning Trees																

1	HR Roads and Libraries															
4	CF1245D - Shichikuji and Power Grid					Excellent problem on Prim's algorithm							
7	CF1081D - Maximum Distance						Very Nice Problem on Kruskal Algorithm							
8	CF17B - Hierarchy															
10	ABC065 D - Built?							Dense->Sparse MST Use Kruskal							


Directed Acyclic Graph-SP																

1	CF721C - Journey															
2	HR Kingdom Connectivity							Extremely instructive Graph problem'							
3	CF30C - Shooting Gallery						Nice combo of dp + probabilities. 					
4	CF793D - Presents in Bankopolis						Excellent idea for Interval DP. Hard Problem							
5	ABC139 E - League							Outstanding use of Kahn algorithm with edge-transformed graph							


Shortest Path-Single Source																

1	CF20C - Dijkstra?							Straightforeward							
2	HR Dijkstra: Shortest Reach 2						Straightforeward							
3	CF707B - Bakery								Easy, Think easily, Not a dijkstra							
4	CF449B - Jzzhu and Cities						Modified Dijkstra: finding count of all optimal path leading to a vertex.							
6	CF916C - Jamie and Interesting Graph					Constructive Proof: Easy.							
7	HR Jack goes to Rapture							Modified dijkstras: Exposes the idea of greedy when dist(x) <= dist(y) if |x| < |y|							
8	CC MINWALK - Minimum Cost Walk						Do Dijkstra 3 times							
10	CC REVERSE - Chef and Reversing						Modified Dijkstra							
11	ABC164 E - Two Currencies						Modified Dijkstra: Best Problem to learn the idea behind algorithm. dynamic approach							
12	ABC170 F - Pond Skater							Olga and Energy Drinks with larger constraints. use Map							
13	ABC175 F - Making Palindrome						Dijkstra: How dijkstra can be used to solve optimality problems? Excellent!!!							
14	ARC061 E - すぬけ君の地下鉄旅行 / Snuke's Subway Trip			Tricky 0/1 BFS transformation. Use virtual vertices.							


0/1 BFS																

2	SPOJ KATHTHI - KATHTHI							Easy 0/1 bfs							
4	CF100625J - Jailbreak							Excellent idea. Popular problem							



0-1 BFS (Tutorial on CP Algorithms)																
0-1 BFS [Tutorial] (Codeforces Blog Post)																



Single Source with Negative Weights																

8	CC AVGSHORT - Short in Average						Bellman ford: Standard, but excellent idea!!							
9	ABC061 D - Score Attack							Easy: Only remember that negative cycle has to contain the src and dest vertex							



Shortest Path with All-Pairs																

1	CC ACM14KG3 - Discount on crackers					Easy Floyd Warshall : Transitive Closure!							
2	CF295B - Greg and Graph							Standard when you know FW well.							
4	CF1204C - Anna, Svyatoslav and Maps					Good FW application							
5	CF25C - Roads in Berland						FW like, Can try virtual vertex approach							
7	ABC051 D - Candidates of No Shortest Paths				Easy FW Application							
8	ABC079 D - Wall								Easy FW. FW=BF for dense graph							







DYNAMIC PROGRAMMING			Classic DP								Comments								

1	HR The Maximum Subarray							Kadane's Algorithm, Easy Peasy							
2	UVa 10405 Longest Common Subsequence					Easy DP on Subsequence								
3	UVa 10003 Cutting Sticks						Matrix Chain Multiplication 								
4	SPOJ EDIST - Edit distance						Edit Distance - Easy Implemetation							
5	UVa 357 Let Me Count The Ways						Coin Change Problem - Linear Space Complexity. 						
6	UVa 111 History Grading							LIS is equivalent to LCS, however LIS can be O(nlogn)				 			
7	SPOJ FARIDA - Princess Farida						Inclusion Exclusion DP - Easy Peasy							
8	UVa 10130 SuperSale							Knapsack 0/1 with multiple queries							
9	UVa 562 Dividing coins							Min Sum Partition : Boolean DP 								
10	CF416B - Art Union							Simple DP. Can be space reduced?							
11	UVa 10304 Optimal Binary Search Tree					Nice application of Matrix Chain Multiplication 				 			
12	ABC079 B - Lucas Number							BInary Expo for Linear Recurrences							


Pattern DP																

1	CF455A - Boredom							Dp on the range of the values. 			
2	CF698A - Vacations							Easy DP								
3	CF706C - Hard problem							Easy DP with String Comparisons Use 1 << 62 for INF in LL 				 			
4	CF467C - George and Job							Easy DP with Prefix Sum						
5	SPOJ MIXTURES - Mixtures						Easy Matrix Multiplication DP Trick 							
6	CF5C - Longest Regular Bracket Sequence					DP with Stack, LBS DP				
6.5	HR-Balanced Sequence							Interesting Application of MCP				
7	CF225C - Barcode							Good boolean matrix DP with Precalc				
8	CF711C - Coloring Trees							Nice DP problem Adhoc DP				
9	CF855B - Marvolo Gaunt's Ring						Easy DP 					
10	CF626B - Cards								Constructive Problem : Easy						
11	CF607B - Zuma								Excellent Application of MCP, DP on Range				
12	CF814C - An impassioned circulation of affection			Sliding Window O(N) solution								
13	CF82D - Two out of Three						Very Nice DP problem with Solution Construction, Structure Hyp				 			
14	ABC054 D - Mixing Experiment						Forward and Backward DP examples. Easy								
15	ABC125 D - Flipping Signs						Easy Mathematical Solution Exist								


Dynamic Programming (Tutorial from NOI.PH IOI Training 2018)																




Pre-Caculation	Double DP															

1	CF946D - Timetable							Very Good Problem with Two Precalculated Dp+Prefix Sum				Mar 10				
2	CF75D - Big Maximum Sum							Nice Application of Max Subarray Sum								
3	CF1498- Planar Reflection						Very Very Nice Prefix DP Problem							


Presorting DP																

1	CF864E - Fire								Very Cool Exchange Argument DP 								
2	CODE FESTIVAL 2017 Final						Standard Exchange Argument DP								
3	ABC145 E - All-you-can-eat						Basic Sorting DP							
4	ABC163 E - Active Infants						Excellent Example of EA with MCP						
5	CF101933A - Altruistic Amphibians					Hard DP problem. Hint : MLE in using LONG LONG.					


Solution Construction																

1	CF4D - Mysterious Present							Easy LIS problem 								
2	CF2B - The least round way							Very Tricky Matrix DP Path Problem						
3	HR Password Cracker								Word Break O(ns) solution exist. Iterate from the last greedily. 
4	HR Arithmetic Expressions							Nice DP with Math trick and Soln construction				 			
5	CF82D - Two out of Three							Already done in pattern DP 							
6	CF56D - Changing a String							Levenstein Distance with construction						
8	CF119C - Education Reform							Cool DP state var reduction trick						
10	ABC118 D - Match Matching			 				Very Important DP problem							
11	ARC081 E - Don't Be a Subsequence						Nice Tick with NEXT function						





Digit DP																

1	CF1036C - Classy Numbers							 Loose branches can be calculated in O(1) time.				 				
2	CF204A - Little Elephant and Interval						 Nice Math & loose branch O(1) time yes 				 			
3	CF914C - Travelling Salesman and Special Numbers				 Builtin_popcount Precount DP							
4	CF628D - Magic Numbers							 	 Both Left_Tight & Right_Tight								
9	CC DIGIMU - Logan and DIGIT IMMUNE numbers					 Very Nice Problem with Another LCM trick 				 			
10	CC WORKCHEF - Chef and special numbers						 Nice Problem with Cool LCM trick & Bitmasking				 				
12	HR Count Pairs: Used							 	 Hard : Digit DP on Pairs of Integers. Very Nice!				 			
13	ABC154 E - Almost Everywhere Zero						 Easy Math Digit DP problem							
14	F-Coincidence							 		 Very Imp: DP on Digits for Integer Pairs				 			

DP on Trees																

1	HR Even Tree									 Very Nice Parity Trick							
2	CF580C - Kefa and Park								 Very Easy Bottom Up Tree DP								
3	HR Cut the Tree									 Basic DP on Trees						
4	CF429A - Xor-tree								 Easy Tree with Propagation Tree Concept				 			
5	CF219D - Choosing Capital for Treeland						 Nice Application Rerooting Technique	
6	CF461B - Appleman and Tree							 Hard DP on Trees, Tricky DP structure & cool combine trick			 			
7	HR Kingdom Division								 Very Nice DP on Tree Coloring. Caution: MOD				 			
8	CF814D - An overnight dance in discotheque					 Dp on Trees and Greedy Geometry	
9	CF855C - Helga Hufflepuff's Cup							 Very Tricky DP on Tree with further dp optimization in combine phase				 			
14	HR Fanciful Fruit								 Hard Tree with Math Problem						

			BITMASKING DYNAMIC PROGRAMMING 													


Bitmasking																

1	CF580D - Kefa and Dishes							Easy Bitmasking								
2	SPOJ ASSIGN - Assignments							Hungarian Assigment Problem Variant								
4	CF401D - Roman and Numbers							Iterative Approach								
5	CF895C - Square Subsets							        Tough Implementation of Bitmask over Primes								
6	CF16E - Fish									Very Nice 								
7	CF8C - Looking for Order							Important to Practice								
8	CF417D - Cunning Gena								Very Very Important for Structural DP Ideas								
9	CC WORKCHEF - Chef and special numbers						Nice Problem with Cool LCM trick & Bitmasking								
10	ABC142 E - Get Everything							Easy Iterative Version								
11	CF1245F - Daniel and Spring Cleaning						Digit DP								



Profile DP																

12	UVa 10918 Tri Tiling								Broken Paraquet								




BITMASK DP																
16	Felicity's Big Secret Revealed															
17	HIST2 - Histogram															
22	Little Poney and harmony Chest							Excellent Problem with Submasking & Bitmasking over Primes								



Topics to be Covered : 																

DIFFERENCE ARRAY																

Problems : 																

1	Greg and Array															
2	Karen and Coffee															
3	Little Girl and Maximum Sum															
4	Encrypting Messages															

STRING HASHING																

1	https://codeforces.com/blog/entry/13741															
2	https://codeforces.com/blog/entry/60445															
3	https://codeforces.com/blog/entry/60442															

	Read other blogs for String Hashing Algorithms															

	Rabin Karp															

	https://codeforces.com/blog/entry/88474															
	https://codeforces.com/blog/entry/4710															
	https://codeforces.com/blog/entry/64860															

CHINESE REMAINDER THEOREM	

	https://codeforces.com/blog/entry/61290																										


ADVANCED ALGORITHMIC PROBLEMS																


1	PHONELST	https://www.spoj.com/problems/PHONELST/					Easy Trie Implementation Based									
2	MAXXOR	https://www.hackerrank.com/challenges/maximum-xor/editorial			Classic Max Xor Trie Implementation									
3	MAXXORSUB										Maximum Xor Subarray, Use above trick + storing xor[1....n]									
4	SUBXOR	https://www.spoj.com/problems/SUBXOR/						Bit Trie: Xor subarray less k, wasted time in indexing, stupid bug!!									



RANGE QUERIES																




1	https://codeforces.com/contest/1567/problem/E				2200		Standard implementation based									
2	https://codeforces.com/contest/446/problem/C				2400		Classic Lazy Propagation technique									
3	https://codeforces.com/problemset/problem/474/F				2100		Standard Segment Tree									
4	http://codeforces.com/problemset/problem/369/E				2200		Difference Array trick gives TLE, Used adhoc approach + Fenwick Tree 									
6	https://atcoder.jp/contests/abc185/tasks/abc185_f			1000		Straight-foreward Fenwick Tree									
7	https://atcoder.jp/contests/abc186/tasks/abc186_f			2200		Sorting + Fenwick Tree, Must DO									
8	https://codeforces.com/problemset/problem/380/C				2000		Great Seg Tree: Classical, POC is cool! in github									
9	https://codeforces.com/contest/339/problem/D				1700		Straight-foreward Segment Tree									
10	https://codeforces.com/contest/356/problem/A				1500		Easy Vector, Not really seg tree									
11	https://codeforces.com/contest/459/problem/D				1800		Fenwick + Order Stats + Sorting. Classical + Coordinate Compresison									
12	https://codeforces.com/contest/61/problem/E				1900		Fenwick Tree									
13	https://codeforces.com/contest/292/problem/E				1900		Nice, Lazy Propagation									
14	https://codeforces.com/contest/501/problem/D				2000	 	Very Nice, Factoriadic Concept+PBDS									
17	https://codeforces.com/contest/540/problem/E				2100		Inversion Count + PBDS + Coord Compression									
27	https://codeforces.com/contest/597/problem/C				1900		Classical Dynamic Programming+Fenwick Tree									
29	https://codeforces.com/contest/482/problem/B				1800		TLE using Seg Tree, Very tight limit, Use pure difference array for offline range sum and range query									
30	https://codeforces.com/contest/242/problem/E				2000		Classic Lazy Propagation: Multiple Seg Tree Application + Cool bit trick									
31	https://codeforces.com/contest/383/problem/C				2000		Propagating Tree. V,V,Nice: Euler Tour Technique									
34	https://codeforces.com/contest/629/problem/D				2000		Nice FW+DP, Pitfall: if strictly greater then use custom sorts accordingly. 	Nice FW+DP, Pitfall: if strictly greater then use custom sorts accordingly. 	Nice FW+DP, Pitfall: if strictly greater then use custom sorts accordingly. 							


FENWICK TREES																



39	http://codeforces.com/contest/102/problem/D 				1700		Fenwick Tree+Coordinate Compression+DP									
41	http://codeforces.com/contest/61/problem/E 				1900		Fenwick Tree Idea: Very Classical									
53	https://codeforces.com/contest/1535/problem/D				1900		Cool: Another way of implementation of seg tree in case intermediate node is given									
54	https://www.spoj.com/problems/POSTERS/					1900		Coordinate Compression on Seg Tree + Lazy Propagation, Cool Exercise									


BINARY LIFTING																

57	https://codeforces.com/contest/609/problem/E				2000		V.V.Nice: Binary Lifting + DP + LCA. Excellent Idea									


	



SPOJ Range Query Sprint!!																		

10	https://www.spoj.com/problems/ADATREE/						Merge Sort Tree												
11	https://www.spoj.com/problems/SEGSQRSS/						Lazy Propagation												
15	https://www.spoj.com/problems/FREQUENT/						Classic Combine Segment Tree												
16	https://www.spoj.com/problems/MKTHNUM/						Merge Sort Tree												
19	https://www.spoj.com/problems/ANDROUND/						Seg Tree												
20	https://www.spoj.com/problems/DQUERY/						Interesting Offline Idea for counting distinct in a subsequence												
22	https://www.spoj.com/problems/MATSUM/						Easy implementation of segment tree												
23	https://www.spoj.com/problems/GSS5/						Tough Classical Seg Tree problem												

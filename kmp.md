## Knuth Morris Pratt 

Prefix function: Given a string, p[i] : longest proper prefix which is also suffix of the string s[0...i] 

Efficient Algorithm (Online): 

```cpp
int p[n];

void prefixfunc(string &s){
        
        int n = sz(s);
        
    	for(int i=1; i<n; i++){

		int j = lps[i-1];

		while(j>0 && str[i]!=str[j]) j = lps[j-1];

		if(str[i] == str[j]) lps[i] = j+1;

		else lps[i] = 0;
		
		// log(i, str[i], lps[i]);

	}
}
```
</br>
Analysis of Prefix Function: 
</br>
</br>

**Bound**: 
</br>
</br>
pi[x] <= pi[x-1]+1, else pi[x-1] can be made larger (contradiction).
Each time j is decremented in the while:j loop, it corresponds to some previous(unique) increment of pi. There are max N elements, so maximum iteration of while:j can be N. So complexity is O(N+N) = O(N). About uniqueness of the increment, think like, everytime j uses as pi[x] to decrement j, it exhausts it and no longer can be used, as to be build again uniquely in the upcoming iterations.

**Problems**:
</br>
</br>

1. **Substring Seach**

Given a pattern t and a string s, print occurences of t in s.

```Idea:  Consider x = t#s, x = t1 t2 t3....tN # s1 s2 ....sM```
```For all i, if pi[i] = N, pos = i-2N```

Time : O(N+M)
</br>
</br>

2. **String Periodicity**

Given a string s, and s(i+T) = s(i), for all i. find the fundamental period T.</br>
In other words, s = [a(0)...a(k-1)][a(k).....a(2k-1)]...[a(N-k)....a(N-1)]. 
</br>

```Idea: If u = N - pi[N-1], and u divides N, s[0...u-1] is the compressed periodic string, otherwise no period exists.```

```Periodicity Lemma: If a string has period T1 and T2, then gcd(T1,T2) is also a period of the string!```

## Z-function

```cpp
int z[N];

void z_function(string &s){
    int l=0,r=0;
    for(int i=1;i<n;++i){
        if(i<=r) z[i] = min(r-i-1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) ++z[i];
        if(i+z[i]-1>r) l=i, r=i+z[i]-1;
    }
}
```

1. **String Periodicity**

```period = min i such that: i+z[i]=n```

2. **Min addition at start of a string to make it palindrome**

`Prefix function Trick: Form a string t by concating string s with reverse of s. find the lps of t.  Ans=n-pi(t)`

String Stream : To read a whole line and break it into strings.
</br>
```cpp
string s,t;
getline(cin,s);
stringstream x(s);

while(getline(x,t,' ')){
    cout << t << endl;
}
```

3. **No of substrings of a string which is equal to its prefix**

```cpp
/*Consider at index::i, a[0...i]. Now what is the max length substring ending at i which is a prefix. Ans = pi[i] and the pref is a[0...pi[i]-1].
What is the next such string, a[0....pi[pi[i]-1]-1] and so on. 

But realize the structure here.

Any prefix of length x i.e a[0...x-1] will contribute to pi[x-1], pi[pi[x-1]-1], ......

Use dp to solve this*/

vector<int> cnt(n+1,0);

for(int i=0;i<n;i++) cnt[pi[i]]++;
for(int i=len;i>=0;i--) cnt[pi[i]-1] += cnt[i];
for(int i=1;i<=len;i++) cnt[i]++;
              
```
eg. https://codeforces.com/contest/432/problem/D

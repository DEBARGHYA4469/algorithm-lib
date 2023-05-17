# Fun with Palindromes


#### Problem : 1

Unique Palindromes. https://codeforces.com/contest/1823/problem/D

Idea: Constructive

* What is the maximum number of unique palindrome substrings in a string of length n? 

  - Let current number of palindrome substring for string S be P 
  - Whenever we add a new character x to S, P can increase by 0/1.
  - Suppose P increase by more than 1. P>=2. 
  - We have two new palindromes, both ending at x. 
  - Like ....x..x and ...x....x. One will be shorter one longer.
  - Since shorter one is included as a proper suffix of larger palindrome, it is also included as a prefix. 
  - So shorter one is already found and not a new one! Contradictions. 
  - If P increases by 0/1, it will always be less than N. (Lemma 1) 


* For any c<N, you can always produce palindromicity of c, appending only same char y. Eg. yyyyyyyy. You cannot make a shorter string due to Lemma 1. 
* T = "abcabcabcabcabcabc", this sequence can never produce a non trivial palindrome of size >=2. Kinda a palindrome killer! 
* So as filler of palindromicity 0 you have to use T. 
* Again due to Lemma 1, c[j] - c[j-1] <= x[j] - x[j-1] 
* Compiling all this ideas, construction becomes simple. aaaaaaabcab|dddddcabca|eeeeeeebcabc 

#### Problem : 2

Petr Petya and Palindrome. https://codeforces.com/problemset/problem/1808/D

Idea: Contribution to Answer Trick 

* Given an odd integer k find sum of palindromicity across all substring of s of length of k.
* Palindromicity is minimum number of characters to replace to make the string palindrome. 

Observations

* For odd palindromes characters in indices match with indices of same parity. 
* Separate out all the even and odd indices.
* Instead of finding the good contributions i.e no of replacements. Lets find number of non-replacements. 
* So for non replacements the characters are all same. 
* So take all same characters for a particular parity together.
* [a(3),a(5),a(13),a(15),a(17)]
* For each i. Calculate no of non-replacement (non-contribution to Sum) for all the j < i. 
* Findout the inequalities and solve using ranges method, upperbound and lowerbound. 

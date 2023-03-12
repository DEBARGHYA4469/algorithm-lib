### Majority Element (Boyer-Moore)

Linear time algorithm for finding majority element(element which occurs more than N/2 times) in an array in O(1) space. 

Algorithm: 

```
	i <- 0, votes <- 0, candidate <- -1 
	while(++i<N){
		if votes = 0, candidate = a[i], votes = 1
		else if a[i] == candidate: votes++
		else votes--;	
	} 
```

Why does this work? 

	- If there is a majority element it will pick up(?).
	- Say there are m majority element m > N/2
	- Consider a "voting bag" and a "trash bag". "Voting Bag" contains same elements. 
	- You choose one element from the array, match with voting bag if the element differ, pick one from voting bag and current element dump it to trash bag.
	- If no element in the voting bag, keep it the voting bag. 
	- If same element in voting bag, keep it in the voting bag.

Now what happens? 

	- Let's say majority element is not their in the voting bag, then all of them are in trash. That means there are > N/2 other such elements, which is impossible. 
	- Majority has to be in voting bag!


#### k-Majority Elements
	
	- keep k "voting" bags and "k+1" trash bags. 
	- Say you are given some elements which appear more than > N/k times. Claim: they all will appear in one of the k "voting" bags.
	- If they are in trash bag, there are k element for each of them, so > N/k element so it will be in one of the "voting" bags.
	- Consequenty all of them are in the voting bags.   



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

int n; cin >> n;
int a[n];
for (int i=0;i<n;i++) cin >> a[i];

int w = sqrt(n); 
pii q[m];
for(int j=0;j<m;j++){
    int l,r; cin >> l >> r;
    q[j] = mp(l,r);
}
sort(q,q+m,[&](pii a, pii b)->bool{
      if(a.fi/w != b.fi/w) return a.fi/w < b.fi/w; 
      else a.se < b.se; 
});

int currL = 0, currR = 0, ans = 0; 
for(int i=0;i<m;i++){
    auto &[l,r] = q[i];
    
    while(currL<L){
       // update answer
       currL++;
    }
    
    while(currL>L){
      // update answer 
      currL--;
    }
    
    while(currR<=R){
      // update answer 
      currR++;
    }
    
    while(currR>R+1){
      // update answer 
      currR--;
    }
}

```

Practice Problems: 

* Powerful array – CF Div1 D
* DQUERY – SPOJ
* GERALD07 – Codechef
* Tree and Queries – CF Div1 D
* Jeff and Removing Periods – CF Div1 D
* Sherlock and Inversions – Codechef

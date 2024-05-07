
Sieve | lowest prime factor divisor | Prime Factorize a large number | Divisors 

```cpp
vector<int> p; 
int sieve [MAXN]; 
auto sievef = [&] (int MAXN) -> void {
    sieve[1] = 1;
    for (int i = 2; i < MAXN; i++){
        if (sieve[i]) continue;
        p.emplace_back (i); 
        for (int j = i; j < MAXN; j += i){
            sieve [j] = i; 
        }
    }
};

auto factor = [&](int n) -> vector<pii> {
    vector<pii> res;
    for (int &x : p){
        if (x * x > n) break;
        else if (n % x) continue;
        res.emplace_back (x, 0); 
        while (n % x == 0) {
            res.back().se++; 
            n /= x; 
        } 
    }
    if (n > 1) res.emplace_back (n, 1); 
    return res; 
};

vi divisors (int n) {
    vi d = {1};
    while (n > 1){
        int m = 0;
        int q = sieve[n];
        while (n % q == 0) { m++; n /= q; }
        int dsize = d.size();
        int pw = q; 
        for (int i = 0;i < m; i++) {
            for (int j = 0; j < dsize; j++) d.emplace_back (d[j] * pw);
            pw *= q;
        } 
    }
    return d; 
} 

```


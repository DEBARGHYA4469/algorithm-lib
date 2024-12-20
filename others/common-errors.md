### Some common mistakes in CP 

* Never reference a stack top or queue front. 

Example: 
- auto &[a,b,c] = q.front(); q.pop(); 

Bug: 

```cpp
    stack<int> box; 
    box.push(100);
    int s = 0; 
    auto &x = box.top();
    box.pop();
    s += x; 
    box.push(20);
    s += x; 
    box.push(10);
    s += x; 
    cout << s;
```

* never check using map operator[], instead use map.find always. Note. counts work for map and sets but TLEs in multiset. 

Bug:

case 1: (25x slower)

```cpp
map<int, int> mp; 
for (int i = 1; i <= N; i++) if(mp[i]) { cout << "Hello" << endl; } 

real    0m4.663s
user    0m4.371s
sys     0m0.281s
```

case 2: 

```cpp
map<int, int> mp;
for (int i = 1; i <= N; i++) {
    if (mp.find(i) != mp.end()) {
        cout << "Hello world" << endl;
    }
}

real    0m0.187s
user    0m0.173s
sys     0m0.001s
```

* string concat is costlier one way 

Bug: 

case 1: 3500x slower

```cpp
const int N = 1e6;
string s = ""; 
for (int i = 0; i < N; i++) {
    s = s + 'a';
}

real    0m54.085s
user    0m28.168s
sys     0m25.899s
```

case 2: 

```cpp
const int N = 1e6;
string s = ""; 
for (int i = 0; i < N; i++) {
    s += 'a';
}
real    0m0.015s
user    0m0.000s
sys     0m0.007s
```


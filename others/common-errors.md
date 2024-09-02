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


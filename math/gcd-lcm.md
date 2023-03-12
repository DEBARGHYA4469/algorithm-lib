#### Euclid's Division algorithm
<a href="https://www.codecogs.com/eqnedit.php?latex=gcd(x,y)&space;=&space;gcd(x-y,y)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?gcd(x,y)&space;=&space;gcd(x-y,y)" title="gcd(x,y) = gcd(x-y,y)" /></a>

```cpp
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
```
stl : __gcd(x,y)
</br></br>
`Time Complexity: gcd in worst case requires as much steps as fibonacci sequence` </br>
`It is worst when x=F[n],y=F[n-1]. Time : O(log min(a,b))`

#### Extended Euclid's Algorithm
<a href="https://www.codecogs.com/eqnedit.php?latex=\\ax&space;&plus;&space;by&space;=&space;gcd(a,b)\\&space;\\In&space;\:&space;transition:\\&space;(a,b)&space;\rightarrow&space;(b,a%b)\\&space;bx_{1}&space;&plus;&space;(a%b)y_1=g\\&space;\\We&space;\:want\:to\:find\:(x,y)\:st\:ax&plus;by=g\\&space;g&space;=&space;ay_1&plus;b(x_1-y_1.\lfloor{\frac{a}{b}}\rfloor)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\ax&space;&plus;&space;by&space;=&space;gcd(a,b)\\&space;\\In&space;\:&space;transition:\\&space;(a,b)&space;\rightarrow&space;(b,a%b)\\&space;bx_{1}&space;&plus;&space;(a%b)y_1=g\\&space;\\We&space;\:want\:to\:find\:(x,y)\:st\:ax&plus;by=g\\&space;g&space;=&space;ay_1&plus;b(x_1-y_1.\lfloor{\frac{a}{b}}\rfloor)" title="\\ax + by = gcd(a,b)\\ \\In \: transition:\\ (a,b) \rightarrow (b,a%b)\\ bx_{1} + (a%b)y_1=g\\ \\We \:want\:to\:find\:(x,y)\:st\:ax+by=g\\ g = ay_1+b(x_1-y_1.\lfloor{\frac{a}{b}}\rfloor)" /></a>

```cpp
int extgcd(int a,int b,int &x,int &y){
      if(b==0){
          x=1;
          y=0;
          return a;
      }
      int x1,y1;
      int g = extgcd(b,a%b,x1,y1);
      x = y1;
      y = x1 - y1*(a/b);
      return g;
}
```

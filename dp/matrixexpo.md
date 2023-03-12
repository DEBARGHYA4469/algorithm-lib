### Matrix Exponentiation
Can be used to solve linear recurrences in log time. </br> </br>
<a href="https://www.codecogs.com/eqnedit.php?latex=\\f_n&space;=&space;2f_{n-1}&plus;3f_{n-2}&plus;n^2&plus;8\\\\&space;F_{n-1}&space;=&space;\begin{pmatrix}&space;f_{n-2}&space;\\f_{n-1}&space;\\1&space;\\n&space;\\n^2&space;\end{pmatrix}&space;and\:&space;T_f&space;=&space;\begin{bmatrix}&space;0&space;&&space;1&space;&&space;0&space;&&space;0&space;&&space;0\\&space;3&space;&&space;2&space;&&space;8&space;&&space;0&space;&&space;1\\&space;0&space;&&space;0&space;&&space;1&space;&&space;0&space;&&space;0\\&space;0&space;&&space;0&space;&&space;1&space;&&space;1&space;&&space;0\\&space;0&space;&&space;0&space;&&space;1&space;&&space;2&space;&&space;1&space;\end{bmatrix}&space;\:&space;=>T_{f}F_{n-1}&space;=&space;F_n\\&space;\\So,&space;\:&space;f_n&space;\leftarrow&space;T_f^{n}F_0" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\f_n&space;=&space;2f_{n-1}&plus;3f_{n-2}&plus;n^2&plus;8\\\\&space;F_{n-1}&space;=&space;\begin{pmatrix}&space;f_{n-2}&space;\\f_{n-1}&space;\\1&space;\\n&space;\\n^2&space;\end{pmatrix}&space;and\:&space;T_f&space;=&space;\begin{bmatrix}&space;0&space;&&space;1&space;&&space;0&space;&&space;0&space;&&space;0\\&space;3&space;&&space;2&space;&&space;8&space;&&space;0&space;&&space;1\\&space;0&space;&&space;0&space;&&space;1&space;&&space;0&space;&&space;0\\&space;0&space;&&space;0&space;&&space;1&space;&&space;1&space;&&space;0\\&space;0&space;&&space;0&space;&&space;1&space;&&space;2&space;&&space;1&space;\end{bmatrix}&space;\:&space;=>T_{f}F_{n-1}&space;=&space;F_n\\&space;\\So,&space;\:&space;f_n&space;\leftarrow&space;T_f^{n}F_0" title="\\f_n = 2f_{n-1}+3f_{n-2}+n^2+8\\\\ F_{n-1} = \begin{pmatrix} f_{n-2} \\f_{n-1} \\1 \\n \\n^2 \end{pmatrix} and\: T_f = \begin{bmatrix} 0 & 1 & 0 & 0 & 0\\ 3 & 2 & 8 & 0 & 1\\ 0 & 0 & 1 & 0 & 0\\ 0 & 0 & 1 & 1 & 0\\ 0 & 0 & 1 & 2 & 1 \end{bmatrix} \: =>T_{f}F_{n-1} = F_n\\ \\So, \: f_n \leftarrow T_f^{n}F_0" /></a>

```cpp
typedef vector<vector<int>> vvi;

inline vvi zero(int n){
    vvi z = vector<vector<int>>(n,vector<int>(n,0));
    return z;
}

inline vvi iden(int n){
    vvi z = zero(n);
    for(int i=0;i<n;i++) z[i][i] = 1;
    return z;
}

vvi mul(vvi x,vvi y){
    int n = sz(x);
    vvi z = zero(n);
    for(int r=0;r<n;r++){
         for(int c=0;c<n;c++){
              for(int k=0;k<n;k++){
                  z[r][c]=add(z[r][c],mul(x[r][k],y[k][c]));
              }
         }
    }
    return z;
}

vvi binpow(vvi x,int y){
    vvi z= iden(sz(x));
    while(y){
        if(y&1) z=mul(z,x);
        x = mul(x,x);
        y>>=1;
    }
  return z;
}
```

* Problem-1: </br> </br> ![image](https://user-images.githubusercontent.com/21307343/140632928-50268359-3aa1-4522-ba27-cfbd52f044cd.png)
* ![image](https://user-images.githubusercontent.com/21307343/140633114-fa9c5663-4dc4-4261-8b4f-10f2663f85c0.png)




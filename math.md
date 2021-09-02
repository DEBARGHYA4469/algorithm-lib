#### Custom Ceil function

```cpp
    inline int ceildiv(int a,int b){
          if(a==0) return 0;
          else return (a-1)/b+1;
    }
```

#### Lazy Caterer

`F[N] = F[N-1] + N`

Intuitive explaination: You can assume some lines N already existing. </br>
![image](https://user-images.githubusercontent.com/21307343/131888317-c7031dcf-2d97-461a-9f0c-a2e184f85cb9.png)
</br>
Any line intersecting at two points cuts that plane into two halves. To get max cutting we need to cut all the existing lines.</br>
Consider a line far away(pink) which intersects with all the lines N(all diverging and sorted by slopes increasing). So maximum cuts increases by (N-1) + 2(open spaces) i.e `F[N+1] = F[N] + N+1`. Hence this is optimal proven. </br>

Now coming to cake cutting problem, since this construction exists, we can zoom(scale in) out everything and fit in the cake geometry. 

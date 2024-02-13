# n-皇后问题

$n$−皇后问题是指将 $n$ 个皇后放在 $n×n$ 的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。

[n-皇后问题](https://www.acwing.com/problem/content/845/)

## 逐行搜索

用数组记录每一列和各对角线上是否放置皇后。

```C++
const int N = 10;
bool col[N], dg[N], udg[N];//dg[]为正对角线，udg[]为逆对角线
```

根据坐标 $(x,y)$ 标记对角线：

> $y = f(x)$，$x = 0$ 时 $y$ 的值就是在 $y$ 轴上的截距，$y = 0$ 时 $x$ 的值就是在 $x$ 轴的截距，截距可正可负。  
> 假设取 $y$ 轴的截距来映射。如果 $y = x + b$，当 $x = 0$ 时，$y = b$，那么y轴上的截距 $b = y - x$。如果$y = -x + b$，当 $x = 0$ 时，$y = b$，那么截距就是 $b = y + x$。  
> 根据皇后的坐标 $(x,y)$ 就可以求出此时 $f(x)$ 在 $y$ 轴上的截距。而 $y = x + b$ 时，截距可能为负数，所以对截距 $b$ 加上一个数 $n$ 将其映射到区间 $[0,n]$。这样每次将皇后放置到 $(x,y)$ ，就可以根据坐标 $(x,y)$ 得到一个下标来标记对应的对角线上放置了皇后。

$$
\boxed{
\begin{matrix}
\diagdown & &\\
& \diagdown & \\
&  & \diagdown\\
\end{matrix}
}\\
正对角线
$$

```C++
#include<iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];

//x表示将在第x行放置皇后，前x行的每一行都放置了皇后
void dfs(int x){
    if(x == n){
        for(int i = 0;i < n;i++) puts(g[i]);
        puts("");
    }
 
    for(int y = 0;y < n;y++)
        if(!col[y] && !dg[y + x] && !udg[y - x + n]){
            //标记
            g[x][y] = 'Q';
            col[y] = dg[y + x] && udg[y - x + n] = true;

            dfs(x + 1);//在第x + 1行放置下一个皇后

            //恢复现场
            col[y] = dg[y + x] && udg[y - x + n] = false;
            g[x][y] = '.';
  }
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++) 
            g[i][j] = '.';
    
    dfs(0);
    
    return 0;
}
```

## 逐格搜索

从左上角到右下角一格一格的搜索，每一行从左到右逐格搜索，每当搜索完最后一列后就进行换行。

```C++
#include<iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int s){
    if(y == n) y = 0, x++;//换行
    if(x == n){
        if(s == n){
            for(int i = 0;i < n;i++) puts(g[i]);
            puts("");
        }
  
        return;//若s != n，策略失败，回溯到上一次放置
    }
 
    //不在(x,y)放皇后
    dfs(x, y + 1, s);
 
    //在(x,y)放皇后
    if(!row[x] && !col[y] && !dg[y + x] && !udg[y - x + n]){
        //标记
        g[x][y] = 'Q';
        row[x] = col[y] = dg[y + x] = udg[y - x + n] = true;
  
        dfs(x, y + 1, s + 1);//试探下一个格子
  
        //恢复现场
        row[x] = col[y] = dg[y + x] = udg[y - x + n] = false;
        g[x][y] = '.';
 }
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            g[i][j] = '.';

    dfs(0, 0, 0);
 
    return 0;
}
```

## 策略分析

逐格遍历相较于逐行搜索要低效的多，逐行搜索的策略是一行只放一个皇后，一旦某一行放置一个皇后就在下一行搜索下一个放置的位置。而逐格遍历最低效的场景是在某格放置了一个皇后后，它还会继续搜索它右一格的位置(不换行的情况下)，这种情况显然没有必要搜索，因为这一行已经放置了皇后。
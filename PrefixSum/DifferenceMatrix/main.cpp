#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
using std::cin;
using std::cout;
using std::endl;
const ll N(1e2+5);
int a[N][N],b[N][N];
void insert(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
/*
 insert 函数的作用是将矩形区域内的值增加或减少指定的数量。
 在这段代码中，矩阵 b 是一个累加数组，用于记录矩阵 a 中各个位置的累加和。
 insert 函数通过对累加数组 b 进行适当的增减操作，实现了将某个矩形区域内的元素值增加或减少。
 */
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
    int n, m, q;
    cin  >> n >> m >> q;
    for(int i = 1; i <= n; i++ ){
        for( int j = 1; j <= m; j++ ){
            cin >> a[i][j];
            insert(i,j,i,j,a[i][j]);
        }
    }
    while( q-- ){
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >>y2 >> c;
        insert(x1,y1,x2,y2,c);
    }
    for(int i = 1; i <= n; i++ ){
        for( int j = 1; j <= m; j++ ){
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            cout << b[i][j] <<" ";
        }
        cout << endl;
    }
}

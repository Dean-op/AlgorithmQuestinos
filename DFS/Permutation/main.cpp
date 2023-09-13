//#include <bits/stdc++.h>
//using namespace std;
//#define rep(i,a,b) for(int i=a; i<b; i++)
//const int N(10);
//int n, path[N];
//bool st[N]
//;
//void dfs( int u ){
//    if( u == n ){//u = 0 第一层， u = 1 第二层， u = n最后一层
//        rep(i,0,n) cout << path[i];
//        cout << '\n';
//    }
//    for( int i = 1; i <= n; i++ ){//这个循环是判断数字1~n，为下面判断i是否被使用做循环
//        if( !st[i] ) {
//            path[u] = i;// 如果数字i没有被使用过，就将其加入排列中
//            st[i] = true;// 标记数字i为已使用
//            dfs( u+1 );// 递归调用dfs，继续生成下一个位置的数字
//            st[i] = false;// 恢复数字i的未使用状态，以便尝试其他排列。通过将 st[i] 设置为 false，程序可以在同一层的不同分支中再次使用相同的数字，以生成不同的排列。
//            return;
//        }
//    }
//}
//int main(){
//    std::ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
////**********************************
//    cin >> n;
//    dfs( 0 );
//    return 0;
//}


#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10;
int n,path[N],cut;
bool st[N];
void DFS( int u ){
    if( u == n ){
        for( int i = 0; i < n; i++ )
            cout << path[i];
        cut ++;
        cout << '\n';
        return;
    }
    for( int i = 1; i <= n; i++ ){
        if( !st[i] ){
            path[u] = i;
            st[i] = true;
            DFS( u + 1 );
            st[i] = false;
        }
    }
}
int main(){
    cin >> n;
    DFS(0);
    cout <<'\n' << cut;
    return 0;
}
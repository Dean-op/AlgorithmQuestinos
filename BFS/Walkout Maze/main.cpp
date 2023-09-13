//https://ac.nowcoder.com/acm/problem/14572
//#include <bits/stdc++.h>
//using namespace std;
//#define PII pair<int,int>
//const int N(5e2+5);
//char graph[N][N];
//int d[N][N];//是否访问过，-1未访问，1访问过
//int n,m,S_x,S_y;
//bool BFS( ){
//    int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
//    queue<PII>q;
//    q.push({S_x,S_y});
//    d[S_x][S_y] = 1;
//    while( !q.empty() ){
//        auto t = q.front();
//        q.pop();
//        for( int i = 0; i < 4; i ++ ){
//            int x = t.first + dx[i], y = t.second + dy[i];
//            if( (x >= 0 && x < n && y >= 0 && y < m) && graph[x][y] !='#' && d[x][y] == -1 ){
//                if( graph[x][y] == 'E' ){
//                    memset(graph,'0',sizeof graph);
//                    return true;
//                }
//                d[x][y] = 1;
//                q.push({x,y});
//            }
//        }
//    }
//    memset(graph,'0',sizeof graph);
//    return false;
//}
//int main(){
//    std::ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
////**********************************
//    while(cin >> n >> m){
//        memset(d,-1,sizeof d);
//        for( int i = 0; i < n; i ++ ){
//            for( int j = 0; j < m; j ++ ){
//                cin >> graph[i][j];
//                if( graph[i][j] == 'S' )    S_x = i,S_y = j;
//            }
//        }
//        cout <<( BFS( ) ? "Yes" : "No" ) << '\n';
//    }
//}

//DFS做法
#include<iostream>
#include<cstring>
using namespace std;
const int N(5e2+5);
typedef pair<int,int> PII;
#define arry(A,N,M) A[N][M]
#define endl '\n'
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
int n,m,sx,sy;
char arry(g,N,N);
int arry(vis,N,N);
bool flag;
bool DFS( int sx, int sy ){
    if( arry(g,sx,sy) == 'E' )  flag = true;
    arry(vis,sx,sy) = 1;//源点已走过
    for( int i = 0; i < 4; i++ ){
        int x = sx + dx[i], y = sy + dy[i];
        if( x >=0 && x < n && y >= 0 && y < m && arry(g,x,y) != '#' && arry(vis,x,y) != 1 ){
            arry(vis,x,y) = 1;//
            DFS( x, y );
            arry(vis,x,y) = 0;//回溯，好像不用回溯？
        }
    }
    return flag;
}
int main(){
    while(cin >> n >> m){
        //
        memset(g,'0',sizeof g);
        memset(vis,0,sizeof vis);
        flag = false;
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                cin >> arry(g,i,j);
                if(arry(g,i,j) == 'S')  sx = i, sy = j;
            }
        }
        cout << (DFS(sx,sy) ? "Yes" : "No") << endl;
    }
    return 0;
}
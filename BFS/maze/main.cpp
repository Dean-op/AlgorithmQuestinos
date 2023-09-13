#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;
int n, m;
int graph[N][N]; //记录地图信息
int d[N][N];    //用于存储每个位置到起点的最短距离。

int bfs() {
    queue<PII> q;
    q.push({0,0});  //源点进队

    memset(d, -1, sizeof d);    //初始化各个点到源点的距离为-1,表示未被探索的区域
    d[0][0] = 0;                             //源点到自己的距离为0

    int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};     //向四个方向扩展的坐标数组([上右下左]的顺序)

    while(!q.empty()) {
        auto t = q.front();     //取队头元素,first是源点的行坐标
        q.pop();                //队头元素出队

        for(int i = 0; i < 4; i++) {    //分别向四个方向扩展
            int x = t.first + dx[i], y = t.second + dy[i];  //扩展后的坐标
            //首先(x,y)不能越界, 然后g[x][y] == 0说明可以走(graph[x][y] == 1说明是障碍物)
            //最后是只更新未被访问的点到源点的距离 (要求d[x][y] == -1)
            if( (x >= 0 && x < n && y >= 0 && y < m) && (graph[x][y] == 0 && d[x][y] == -1) ) {
                d[x][y] = d[t.first][t.second] + 1; //更新未被访问的点到源点的距离
                q.push({x,y});                      //(x,y)进队
            }
        }
    }
    return d[n-1][m-1];     //返回右下角元素到源点的距离
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> graph[i][j];     //读入地图信息
    cout << bfs() << endl;
    return 0;
}
/*
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
*/

//#include <iostream>
//#include <cstring>
//#include <queue>
//using namespace std;
//typedef pair<int,int>  PII;
//const int N(2e1);
//int graph[N][N], d[N][N];
//int n,m;
//int dx[4] = {-1,0,1,0 }, dy[4] = {0,1,0,-1 };
//int BFS(  ){
//    queue<PII>q;
//    q.push({0,0});
//    d[0][0] = 0;//源点到自己的距离
//
//    while( !q.empty() ){
//        auto t = q.front();
//        q.pop();
//        for( int i = 0; i < 4; i++ ){
//            int x = t.first + dx[i], y = t.second + dy[i];//遍历源点的四个方向
//            //如果坐标在正确范围内 and 下一个位置不是1(墙)且没被访问过
//            if( (x >= 0 && x < n && y >= 0 && y < m) && (graph[x][y] != 1 && d[x][y] == -1) ){
//                d[x][y] = d[t.first][t.second] + 1;//下一个位置距离源点的距离加1
//                q.push({x,y});//记录下这个位置，下次以这个位置向四个方向扩散
//            }
//        }
//    }
//    return d[n-1][m-1];
//}
//
//int main(){
//    cin >> n >> m;
//    memset(d,-1, sizeof d);//-1表示未被访问过的地方
//    for( int i = 0; i < n; i++ ){
//        for( int j = 0; j < m; j++ ){
//            cin >> graph[i][j];
//        }
//    }
//    cout << BFS() << '\n';
//    return 0;
//}

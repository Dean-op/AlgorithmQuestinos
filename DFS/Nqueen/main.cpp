//洛谷P1219
#include <bits/stdc++.h>
using namespace std;
const int N(2e1+6);
int n,cut;
bool col[N],dg[N],udg[N];
vector<int>ans;
void DFS( int u ){
    if( u == n ){
        if( cut  < 3 ){
            for( auto& num : ans )
                cout << num << ' ';
            cout << '\n';
        }
        cut ++;
        return;
    }
    for( int i = 0; i < n; i++ ){
        if( !col[i] && !dg[u + i] && !udg[n - u + i] ){
            col[i] = dg[u + i] = udg[n - u + i] = true;
            ans.push_back( i + 1 );
            DFS( u + 1 );
            //回溯
            col[i] = dg[u + i] = udg[n - u + i] = false;
            ans.pop_back();
        }
    }
}
int main(){
    cin >> n;
    DFS( 0 );
    cout << cut ;
    return 0;
}




//#include <bits/stdc++.h>
//using namespace std;
//#define rep(i,a,b) for(int i=a; i<b; i++)
//#define RREP(i,a,b) for(int i=a; i>=b; i++)
//const int N(2e1+4);
//int n,cut;
//char g[N][N];
//bool col[N],row[N],dg[N],udg[N];
//void dfs( int x, int y, int s ){
//    if( y == n ){
//        y = 0;
//        x ++;
//    }
//    if( x == n){
//        if( s == n) cut ++;
//        return;
//    }
//    if( !col[y] && !row[x]  && !dg[x+y] && !udg[x-y+n] ){
//            g[x][y] = '*';
//            col[y] = row[x] = dg[x+y] =udg[x-y+n] = true;
//            dfs(x,y+1,s+1);
//            col[y] = row[x] = dg[x+y] =udg[x-y+n] = false;
//            g[x][y] = '.';
//    }
//    dfs(x,y+1,s);
//}
//int main(){
//    std::ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//**********************************
//    cin >> n;
//    rep( i, 0, n ){
//        rep( j, 0, n ){
//            g[i][j] = '.';
//        }
//    }
//    dfs( 0,0,0 );
//    cout << cut << endl;
//}
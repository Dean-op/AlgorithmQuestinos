#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define arry(A,N,M) A[N][M]
#define PII pair<int,int>
#define ll long long
#define endl '\n'
const int N(1e6+5);
int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
ll ans;
void solve(){
    string s; cin >> s;
    int len = s.length();
    for(int i = 0; i < len; i ++ ){
        int c0 = 0, c1 = 0;
        for( int j = i; j < len; j ++ ){
            if( j % 2 == 0 ){
                if( s[j] == '1' ) c1 ++;
                else c0 ++;
            }else{
                if( s[j] == '0' ) c1 ++;
                else c0 ++;
            }
            ans += min(c0,c1);
        }
    }
    cout << ans << endl;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
    int t = 1;
    while( t -- ){
        solve();
    }
    return 0;
}
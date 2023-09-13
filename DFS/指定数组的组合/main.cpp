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

ll n;
int ans,len;

void dfs( int pos, ll x ){
	if( len == pos ){
	 	if( x <= n && x ) ans ++ ;	
	 	return;
	}
	if( !x ) dfs( pos + 1, 0 );
	dfs( pos + 1 , x * 10 + 4 );
	dfs( pos + 1 , x * 10 + 7 );
}
int main(){
	cin >> n;
	len = (int)log10(n) + 1;
	dfs( 0, 0 );
	cout << ans ;
    return 0;
}

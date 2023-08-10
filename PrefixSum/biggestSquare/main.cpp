#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
using std::cin;
using std::cout;
using std::endl;
int max(int a,int b)  { return a > b ? a : b; }
int min(int a,int b)  { return a > b ? b : a; }
const int N(1e2+5);
int a[N][N];
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
	int n,m,ans = -1;
	cin >> n >> m;
	rep(i,1,n+1){
		rep(j,1,m+1){
			cin >> a[i][j];
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	}
	for( int k = min(n,m); k >=1; k-- ){
		for( int i = 1; i <= n-k+1; i++){
			for( int j = 1; j <= m-k+1; j++ ){
				int x2 = i+k-1, y2 = j+k-1;//
				if( k*k == a[x2][y2] - a[i-1][y2] - a[x2][j-1] + a[i-1][j-1] ){
					cout << k;
					return 0;
				}
			}
		}		
	}
	puts("0");
	return 0;
}
 



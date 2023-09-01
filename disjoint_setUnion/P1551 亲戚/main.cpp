#include<iostream>
 using namespace std;
 const int N(1e5+51);
 int pre[N],rnk[N];
 int root( int x ){
 	while( x != pre[x] ) x = pre[x];
 	return x;
 }
 void merge(int x,int y){
 	int x_root = root(x), y_root = root(y);
 	if( rnk[x] > rnk[y] ) swap(x,y);
 	pre[x_root] = y_root;
 	if( rnk[x] == rnk[y] ) rnk[y] ++ ;
 }
 int main(){
 	ios_base::sync_with_stdio(0);
 	cin.tie(0); cout.tie(0);
 	int n,m,p;
 	cin >> n >> m >> p;
 	for( int i = 1; i <= n; i++ ) pre[i] = i;
 	
 	while( m -- ){
 		int x, y; cin >> x >> y;
 		merge(x,y);
	 }
	 while( p -- ){
	 	int x, y; cin >> x >> y;
	 	cout << ( root(x) == root(y) ? "Yes" : "No" ) << '\n';
	 }
 }
/*
#include<iostream>
 using namespace std;
 const int N(1e5+51);
 int pre[N],rnk[N];
 int root( int x ){
 	while( x != pre[x] ) x = pre[x] = pre[pre[x]];//路径压缩，但会破坏树的结构
 	return x;
 }
 void merge(int x,int y){
 	int x_root = root(x), y_root = root(y);
 	if( x_root == y_root ) return;
 	pre[x_root] = y_root;
 }
 int main(){
 	ios_base::sync_with_stdio(0);
 	cin.tie(0); cout.tie(0);
 	int n,m,p;
 	cin >> n >> m >> p;
 	for( int i = 1; i <= n; i++ ) pre[i] = i;
 	
 	while( m -- ){
 		int x, y; cin >> x >> y;
 		merge(x,y);
	 }
	 while( p -- ){
	 	int x, y; cin >> x >> y;
	 	cout << ( root(x) == root(y) ? "Yes" : "No" ) << '\n';
	 }
 }
 */
//P1157
//#include <bits/stdc++.h>
//using namespace std;
//#define rep(i,a,b) for(int i=a; i<b; i++)
//#define RREP(i,a,b) for(int i=a; i>=b; i++)
//#define ll long long
//#define PII pair<int,int>
//const int N(25);
//int n, m; 
//bool vis[N];
//vector<int> ans;
//void DFS( int u ){
//	if( u == m ){
//			for( auto & num : ans )
//			cout << setw(3) << num;
//			cout << '\n';
//		return;
//	}
//	int start = (u == 0) ? 1 : ans[u - 1] + 1;
//	for( int i = start; i <= n; i++ ){
//		if( !vis[i] ){
//			vis[i] = true;
//			ans.push_back(i);
//			DFS( u + 1 );
//			vis[i] = false;
//			ans.pop_back();
//		}
//	}
//}
//int main(){
//    std::ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
////**********************************
//	cin >> n >> m;
//	DFS( 0 );
//	return 0;
//}

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int x[25];
int main(){
	int n, m;
	cin >> n >> m;
	for( int i = m+1; i <= n; i ++ ) x[i] = 1;
	do{
		for( int i = 1;i <= n ;i ++ ){
			if( x[i] == 0 )	cout << setw(3) << i;
		} 
		cout << '\n';
	}while( next_permutation(x+1,x+n+1) );
	return 0;
}

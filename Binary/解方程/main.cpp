//https://ac.nowcoder.com/acm/problem/14416  ½â·½³Ì 
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
int main(){
	int n,x;
	vector<int>a;
	cin >> n >> x;
	while( n-- ){
		int temp; cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	rep( i,0,a.size() ){
		rep( j,0,a.size() ){
			int c = 0 - (a[i]*pow(x,2) + a[j]*x);
			if( binary_search( a.begin(),a.end(),c ) ){
				cout << "YES"; exit(0);
			}
		}
	}
	cout << "NO";
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
typedef pair<int,int> PII;
const ll N(1e5+5);

vector<int>ls,a,s;
vector<PII>add,query;
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//*****************************************

	int n, m;
	cin >> n >>m;
	rep(i,1,n+1){
		int x,c;
		cin >> x >> c;
		add.push_back( make_pair(x,c) );
		ls.push_back(x);
	} 
	rep(i,0,m){
		int l,r;
		cin >> l >> r;
		query.push_back( make_pair(l,r) );
		ls.push_back(l);
		ls.push_back(r);
	}
	
	sort(ls.begin(),ls.end());
	ls.erase( unique(ls.begin(), ls.end()), ls.end() );//去重
	a.resize(ls.size()+1);
	s.resize(ls.size()+1);
	
	for( auto pair : add ){
		auto x = lower_bound( ls.begin(), ls.end(), pair.first );//查询x离散化后对应的编号 
		a[distance(ls.begin()-1,x)] += pair.second;
	}
	for( int i = 1; i <= ls.size(); i++ )
	s[i] = s[i-1] + a[i];
	for( auto pair : query ){
		auto l = lower_bound(ls.begin(),ls.end(),pair.first) , r = lower_bound(ls.begin(),ls.end(),pair.second);
		cout << s[distance(ls.begin()-1,r)] - s[distance(ls.begin()-1,l)-1] << endl;
	}	 
}




//#include <bits/stdc++.h>
//using namespace std;
//#define rep(i,a,b) for(int i=a; i<b; i++)
//#define RREP(i,a,b) for(int i=a; i>=b; i++)
//#define ll long long
//typedef pair<int,int> PII;
//const ll N(1e5+5);
//
//int a[N],s[N];//a存储离散化后的坐标 
//vector<int>ls;//ls存储待离散化之前的x的数值 
//vector<PII>add,query;
//
//int find(  int x ){//3 7
//	int l = 0, r = ls.size()-1;
//	while(l < r){
//		int mid = (l + r) >> 1;
//		if (ls[mid] >= x) r = mid;
//		else l = mid + 1; 
//	}
//	return r + 1;
//}
//int main(){
//    std::ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
////**********************************
//	int n, m;
//	cin >> n >> m;
//
//	for ( int i = 0; i < n; i ++ ){
//		int x , c ;
//		cin >> x >> c;
//		add.push_back(make_pair(x,c));//n个在x处加c的操作
//		ls.push_back(x);
//	}
//	for( int i = 1; i <= m; i++ ){
//		int l,r;
//		cin >> l >> r;
//		query.push_back(make_pair(l,r));
//		ls.push_back(l);ls.push_back(r);
//	}
//	sort(ls.begin(),ls.end());
//	ls.erase( unique(ls.begin(),ls.end()),ls.end() );//去重 
//	for( auto pair : add ){
//		int x = find(pair.first);
//		a[x] += pair.second;
//	} 
//	
//	for( int i = 1; i <= ls.size(); i++ ){
//		s[i] = s[i-1] + a[i];
//	}
//	for( auto pair : query ){
//		int l = find(pair.first), r = find(pair.second);//12  35
//		cout << s[r] - s[l-1] << endl;
//	} 
//  
//}
///*
//3 3
//1 2
//3 6
//7 5
//1 3
//4 6
//7 8
//
//8
//0
//5
//
//*/

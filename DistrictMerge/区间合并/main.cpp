#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
typedef pair<int,int> PII;
const ll N(1e5+5);
void merge_dis( vector<PII>&dis ){
	vector<PII>cut;
	sort( dis.begin(),dis.end() );
	int st = -2e9,ed = -2e9;
	for( auto pair : dis ){
		if( ed < pair.first ){
			if( st != -2e9 )	cut.push_back( make_pair(st,ed) );
			st = pair.first; ed = pair.second;
		}else{
			ed = max(ed,pair.second);
		} 			
	}
	if( st != 2e9 ) cut.push_back( make_pair(st,ed) );//处理最后一个区间 
	dis = cut;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
	int n;
	vector<PII>District; 
	cin >> n;
	rep(i,0,n){
		int l,r;
		cin >> l >> r;
		District.push_back( make_pair(l,r) );
	}
	merge_dis( District );
	cout << District.size();
}

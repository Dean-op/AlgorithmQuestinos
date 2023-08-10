#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
using std::cin;
using std::cout;
using std::endl;
const ll N(1e5+5);
int s[N],a[N];
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> a[i];
		s[a[i]]++;
	}
	int ans = 0;
	for( int i = 0, j = 0; i < n; i++ ){
		while( j <= i && s[a[i]] >1 ){
			s[a[j]]-- ;
			j++;
		}
		ans = std::max(ans,i-j+1);
	}
	cout << ans <<endl;
  
}


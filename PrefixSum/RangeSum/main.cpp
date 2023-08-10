#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
using std::cin;
using std::cout;
using std::endl;
const ll N(1e2+5);
int a[N],b[N];
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
	int n,m;
    cin >> n >> m;
    rep(i,1,n+1){
        cin >> a[i];
        b[i] = a[i] - a[i-1];//init difference array
    }
    while( m-- ){
        int l,r,c;
        cin >> l >> r >> c;
        b[l]+=c; b[r+1]-=c;//*
    }
    rep(i,1,n+1){
        b[i]+=b[i-1];//求前缀和
        cout << b[i] << " ";
    }
}

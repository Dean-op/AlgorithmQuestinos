/*https://www.luogu.com.cn/problem/AT_abc037_c*/
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
using std::cin;
using std::cout;
using std::endl;
const ll N(1e5+5);
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
    ll a[N],s[N],n,k;
    cin >> n >> k;
    for(ll i = 1; i<=n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }

    ll sum = 0;
    for(ll i = 1; i<=n; i++){
        ll l = i, r = i+k-1;
        if (r > n ) break;
        sum+=(s[r] - s[l-1]);
    }
    cout << sum;
    return 0;
}

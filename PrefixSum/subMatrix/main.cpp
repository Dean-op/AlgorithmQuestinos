    #include <bits/stdc++.h>
    #define rep(i,a,b) for(int i=a; i<b; i++)
    #define RREP(i,a,b) for(int i=a; i>=b; i++)
    #define ll long long
    using std::cin;
    using std::cout;
    using std::endl;
    const int N(1e2+5);
    int a[N][N];
    int main(){
        std::ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    //**********************************
        int n,m;
        cin >> n >> m;
        rep(i,1,n+1)
            rep(j,1,m+1){
                cin >> a[i][j];
                a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ( a[x2][y2] - a[x1-1][y2] - a[x2][y1-1] + a[x1-1][y1-1] );
    }
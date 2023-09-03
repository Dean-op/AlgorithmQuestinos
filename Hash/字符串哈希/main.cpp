#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e5+5, P = 131;
ULL h[N], p[N];//分别用于存储字符串的前缀哈希值和幂次。h 用于存储字符串的前缀哈希值，p 用于存储 P 的幂次。 
ULL gethash( int& l, int& r ){//用于计算从位置 l 到位置 r 的子串的哈希值。它通过使用前缀哈希值的差值来实现。
    return h[r] - h[l-1] * p[r-l+1];
}
int main(){
    string str; int n;
    cin >> str >> n;
    p[0] = 1; h[0] = 0;//p的零次幂为1，h[0]表示空串的哈希值 
    for( int i = 1; i<= str.size(); i++ ){
        p[i] = p[i-1] * P;//求出所有P的次幂 
        h[i] = h[i-1] * P + str[i];//字符串哈希前缀和公式 
    }
    int l1,l2,r1,r2;
    while( n-- ){
        cin >> l1 >> r1 >> l2 >> r2;
        if( gethash( l1,r1 ) == gethash( l2,r2 ) ) cout << "Yes" <<'\n';
        else cout << "No" << "\n";
    }
}

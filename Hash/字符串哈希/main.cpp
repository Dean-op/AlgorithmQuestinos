#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e5+5, P = 131;
ULL h[N], p[N];//�ֱ����ڴ洢�ַ�����ǰ׺��ϣֵ���ݴΡ�h ���ڴ洢�ַ�����ǰ׺��ϣֵ��p ���ڴ洢 P ���ݴΡ� 
ULL gethash( int& l, int& r ){//���ڼ����λ�� l ��λ�� r ���Ӵ��Ĺ�ϣֵ����ͨ��ʹ��ǰ׺��ϣֵ�Ĳ�ֵ��ʵ�֡�
    return h[r] - h[l-1] * p[r-l+1];
}
int main(){
    string str; int n;
    cin >> str >> n;
    p[0] = 1; h[0] = 0;//p�������Ϊ1��h[0]��ʾ�մ��Ĺ�ϣֵ 
    for( int i = 1; i<= str.size(); i++ ){
        p[i] = p[i-1] * P;//�������P�Ĵ��� 
        h[i] = h[i-1] * P + str[i];//�ַ�����ϣǰ׺�͹�ʽ 
    }
    int l1,l2,r1,r2;
    while( n-- ){
        cin >> l1 >> r1 >> l2 >> r2;
        if( gethash( l1,r1 ) == gethash( l2,r2 ) ) cout << "Yes" <<'\n';
        else cout << "No" << "\n";
    }
}

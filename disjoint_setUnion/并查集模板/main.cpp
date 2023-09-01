#include <bits/stdc++.h>
using namespace std;
const int N(1e5+5);
int pre[N],rnk[N] ;
/*
�ⲿ�ִ��붨���˺��� root��ʵ����·��ѹ���Ĳ��Ҳ�����
��֮ǰ�Ĵ������ƣ���֮ͬ������·��ѹ���ķ�ʽ��΢��ͬ��
ֻ����һ��ѭ����û�и���ǰ���ڵ㡣������·��ѹ����ʽ��Ȼ��Ч�����ᵼ��������ȿ��ܽϴ�
*/
int root( int x ){
	while( x != pre[x] ) x = pre[x];
	return x;
}
/*���Ⱥϲ�
if (rnk[x] > rnk[y]) swap(x, y)���ⲿ�ִ����� x �� y ���ڼ��ϵ��ȣ������ĸ߶ȵ�һ���Ͻ磩��
���Ƚ�С�ļ��Ϻϲ����Ƚϴ�ļ����Ͽ��Ա������ĸ߶ȹ��ߣ��Ӷ������˽Ϻõ�ƽ�⡣��� x ���ȴ��� y ���ȣ��������ǣ�ȷ�� x ��ʾ�����Ƚ�С�ļ��ϡ�
pre[x] = y���� x ���ڼ��ϵĴ���Ԫ�ص�ǰ���ڵ�����Ϊ y���Ӷ��� x ���ڵļ��Ϻϲ����� y ���ڵļ����ϡ�
if (rnk[x] == rnk[y]) rnk[y]++������ϲ�ǰ x �� y ������ͬ����ô�ڽ� x �ϲ��� y ֮��y ������Ҫ����1��
����Ϊ�˱�������ƽ�⣬����ϲ�������߶ȹ��ߡ�
*/
void merge( int x, int y ){
	x = root(x); y = root(y);
	if( rnk[x] > rnk[y] ) swap(x,y);//��֤rnk[x] <= rnk[y]
	pre[x] = y;
	if( rnk[x] == rnk[y] ) rnk[y]++;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
	int n,m;
	cin >> n >> m;
	rep(i,1,n+1) pre[i] = i;//��ʼ�� 
	while( m-- ){
		int z,x,y;
		cin >> z >> x >> y;
		if( z == 1 ) merge( x, y );
		else cout <<( ( root(x) == root(y) ) ? "Y" : "N" )<< '\n';
	} 
}

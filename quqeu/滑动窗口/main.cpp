//������������Сֵ���ֵ���⣬���͵�˫�˶��� 
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
#define PII pair<int,int>
const int N(1e6);
int a[N],dq[N];
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
	int n , k;//Ԫ�����������ڴ�С
	cin >> n >> k;
	rep ( i, 0, n ) cin >> a[i] ;
	
	int head = 0,tail = -1;//����ͷָ�롢βָ��,βָ��Ҳ������dq���±������ 
	rep ( i, 0, n ) {
		//���´��ڸ��Ƿ�Χ����i = 3��˵, 1 > 0,�������˵�����һλ 
		if( head <= tail && i - k + 1 > dq[head] ) head ++;
		//����������Ԫ��С��(��βԪ�ش�����Ԫ��),����ȥ��βԪ���±꣬Ҳ����ζ�ŵ�����βԪ�� 
		while( head <= tail && a[i] < a[dq[tail]]) tail --;
		
		dq[++tail] = i;
		//��i = 2��k-1Ϊ2����ʱ��ζ�Ŵ�����������Ԫ���ˣ��������СԪ�ؼ��ɣ�\
		֮������a[dq[head]]����Ϊ�����ǵ��������ģ���һ���±�һ������С�� 
		if( i >= k - 1 ) cout << a[dq[head]] << " ";
	}
}
/*
8 3
1 3 -1 -3 5 3 6 7
-1 -3 -3 -3 3 3
*/

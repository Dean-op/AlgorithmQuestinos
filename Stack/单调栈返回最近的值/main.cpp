/*���� n ������������ÿ���������ҵ�����֮ǰ��С�ڵ������ĵ�һ��Ԫ�أ��������������� -1��*/
#include<iostream>
using namespace std;
const int N(1e6+10) ;
int sta[N],Pointer_sta;
int main(){
	int n;
	cin >> n;
	for(  int i = 0; i < n; i++ ){
		int x; cin >> x;
		while( Pointer_sta > 0 && sta[Pointer_sta] >= x ) Pointer_sta -- ;
		if( Pointer_sta ) cout << sta[Pointer_sta] << " ";
		else cout << -1 << " " ;
		sta[++Pointer_sta] = x;
	}
	return 0;
}


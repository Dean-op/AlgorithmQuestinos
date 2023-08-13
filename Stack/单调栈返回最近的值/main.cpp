/*给定 n 个整数，对于每个整数，找到在它之前且小于等于它的第一个元素，如果不存在则输出 -1。*/
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


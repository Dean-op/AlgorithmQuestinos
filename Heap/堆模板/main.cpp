#include<iostream>
#include<algorithm>
using namespace std;
const int N(1e5+5);
int min_heap[N],size;
void down( int i ){
	int temp = i, left_son = 2*i, right_son = 2*i+1;
	
	if( left_son <= size && min_heap[left_son] < min_heap[temp] ) temp = left_son;//�����ڶ��ӽڵ㲢�������С�ڸ��ڵ�
	if( right_son <= size && min_heap[right_son] < min_heap[temp] ) temp = right_son;
	if( temp != i ){//��temo!=iʱ =�� ��/�Ҷ���С�ڸ��ڵ㣬�򽻻����ڵ㣬����ά���������ԭ�����ڵ㣬��ʼ�³�
		swap( min_heap[temp], min_heap[i] );
		down( temp );//���ڽ��������ƻ�����������С�����ʣ����ǵݹ���� down �������Ա�����������С�����ʡ�
	}
	
}
int main(){
	int n,m; cin >> n >> m;
	for( int i = 1; i <= n; i++ ) cin >> min_heap[i];
	size = n;
	
	for( int i = n/2; i >= 0; i-- ) down(i);// �����һ����Ҷ�ӽڵ�(n/2)��ʼ�³���һֱ�³������ڵ�.�ѵ�����Ӧ�ô�1��ʼ�������Ǵ�0��ʼ��
	
	while( m-- ){
		cout << min_heap[1] << '\n';
		min_heap[1] = min_heap[size];
		size-- ;
		down(1);// �Ӹ��ڵ㿪ʼ�³������¹�������
	}
}


//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N(1e5+10);
//int max_heap[N],size;
//void up( int i ){
//	int largest = i,left = 2*i,right = 2*i+1;
//	if( left <= size && max_heap[left] > max_heap[largest] ) largest = left;
//	if( right <= size && max_heap[right] > max_heap[largest] ) largest = right;
//	if( largest != i){
//		swap( max_heap[largest], max_heap[i] );
//		up(largest);
//	}
//}
//int main(){
//	int n,m;
//	cin >> n;
//	cout << "ʵ������:\n";
//	for( int i = 1; i <= n; i++ ) cin >> max_heap[i];
//	size = m = n;
//	for( int i = n/2; i >= 1; i-- ) up(i);//�������� 
//	
//	//�����򡪡�����Ѷ�Ԫ�� 
//	while( m-- ){
//		cout << max_heap[1] << '\n';
//		max_heap[1] = max_heap[size];
//		size--;
//		up(1);
//	}
//	
//}

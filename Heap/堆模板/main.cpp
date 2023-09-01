#include<iostream>
#include<algorithm>
using namespace std;
const int N(1e5+5);
int min_heap[N],size;
void down( int i ){
	int temp = i, left_son = 2*i, right_son = 2*i+1;
	
	if( left_son <= size && min_heap[left_son] < min_heap[temp] ) temp = left_son;//若存在儿子节点并且左儿子小于父节点
	if( right_son <= size && min_heap[right_son] < min_heap[temp] ) temp = right_son;
	if( temp != i ){//若temo!=i时 =》 左/右儿子小于父节点，则交换父节点，接着维护交换后的原本父节点，开始下沉
		swap( min_heap[temp], min_heap[i] );
		down( temp );//由于交换可能破坏了子树的最小堆性质，我们递归调用 down 函数，以保持子树的最小堆性质。
	}
	
}
int main(){
	int n,m; cin >> n >> m;
	for( int i = 1; i <= n; i++ ) cin >> min_heap[i];
	size = n;
	
	for( int i = n/2; i >= 0; i-- ) down(i);// 从最后一个非叶子节点(n/2)开始下沉，一直下沉到根节点.堆的索引应该从1开始，而不是从0开始。
	
	while( m-- ){
		cout << min_heap[1] << '\n';
		min_heap[1] = min_heap[size];
		size-- ;
		down(1);// 从根节点开始下沉，重新构建最大堆
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
//	cout << "实现最大堆:\n";
//	for( int i = 1; i <= n; i++ ) cin >> max_heap[i];
//	size = m = n;
//	for( int i = n/2; i >= 1; i-- ) up(i);//构建最大堆 
//	
//	//堆排序——输出堆顶元素 
//	while( m-- ){
//		cout << max_heap[1] << '\n';
//		max_heap[1] = max_heap[size];
//		size--;
//		up(1);
//	}
//	
//}

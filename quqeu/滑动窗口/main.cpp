//滑动窗口求最小值最大值问题，典型的双端队列 
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
	int n , k;//元素数量、窗口大小
	cin >> n >> k;
	rep ( i, 0, n ) cin >> a[i] ;
	
	int head = 0,tail = -1;//队列头指针、尾指针,尾指针也代表着dq内下标的数量 
	rep ( i, 0, n ) {
		//更新窗口覆盖范围，以i = 3来说, 1 > 0,窗口做端点右移一位 
		if( head <= tail && i - k + 1 > dq[head] ) head ++;
		//如果插入的新元素小于(队尾元素大于新元素),将减去队尾元素下标，也就意味着弹出队尾元素 
		while( head <= tail && a[i] < a[dq[tail]]) tail --;
		
		dq[++tail] = i;
		//当i = 2，k-1为2，此时意味着窗口内有三个元素了，则输出最小元素即可，\
		之所以是a[dq[head]]是因为队列是单调递增的，第一个下标一定是最小的 
		if( i >= k - 1 ) cout << a[dq[head]] << " ";
	}
}
/*
8 3
1 3 -1 -3 5 3 6 7
-1 -3 -3 -3 3 3
*/

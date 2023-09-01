#include <bits/stdc++.h>
using namespace std;
const int N(1e5+5);
int pre[N],rnk[N] ;
/*
这部分代码定义了函数 root，实现了路径压缩的查找操作。
与之前的代码类似，不同之处在于路径压缩的方式稍微不同，
只进行一次循环而没有更新前导节点。这样的路径压缩方式仍然有效，但会导致树的深度可能较大
*/
int root( int x ){
	while( x != pre[x] ) x = pre[x];
	return x;
}
/*按秩合并
if (rnk[x] > rnk[y]) swap(x, y)：这部分代码检查 x 和 y 所在集合的秩（即树的高度的一个上界）。
将秩较小的集合合并到秩较大的集合上可以避免树的高度过高，从而保持了较好的平衡。如果 x 的秩大于 y 的秩，交换它们，确保 x 表示的是秩较小的集合。
pre[x] = y：将 x 所在集合的代表元素的前导节点设置为 y，从而将 x 所在的集合合并到了 y 所在的集合上。
if (rnk[x] == rnk[y]) rnk[y]++：如果合并前 x 和 y 的秩相同，那么在将 x 合并到 y 之后，y 的秩需要增加1。
这是为了保持树的平衡，避免合并后的树高度过高。
*/
void merge( int x, int y ){
	x = root(x); y = root(y);
	if( rnk[x] > rnk[y] ) swap(x,y);//保证rnk[x] <= rnk[y]
	pre[x] = y;
	if( rnk[x] == rnk[y] ) rnk[y]++;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
	int n,m;
	cin >> n >> m;
	rep(i,1,n+1) pre[i] = i;//初始化 
	while( m-- ){
		int z,x,y;
		cin >> z >> x >> y;
		if( z == 1 ) merge( x, y );
		else cout <<( ( root(x) == root(y) ) ? "Y" : "N" )<< '\n';
	} 
}

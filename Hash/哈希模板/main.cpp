
//开放寻址法 
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
#define PII pair<int,int>
const int N(2e5+3),null = 0x3f3f3f3f;
int h[N];
int find( int x ){
	int k = ( x % N + N ) % N;
	/*使用开放寻址法查找元素，通过不断后移 k，直到找到一个空槽位或者找到值等于 x 的槽位。
	如果找到空槽位，则返回空槽位的索引，如果找到值等于 x 的槽位，则返回该槽位的索引*/
	while( h[k] != null && h[k] != x ){
		k++;
		if( k == N ) k = 0;
	}
	return k;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
	string op;
	int n,x;
	cin >> n;
	memset(h,0x3f,sizeof(h));
	while ( n-- ){
		cin >> op >> x;
		int k = find( x );
		if ( op == "i" ) h[k] = x;
		else {
			if( h[k] != null ) puts("Yes");
			else puts("No");
		}
	}
	
}



/*#include<bits/stdc++.h>
using namespace std;
const int N(1e5+3); 
int h[N],e[N],ne[N],index;
void insert( int x ){
	int k = ( x % N + N) % N;//确保哈希值为正数，并且不超过N ，注意不会发生重复哈希值问题，这段代码并没有解决冲突问题 
	e[index] = x;
	ne[index] = h[k];//ne[index]表示下一个节点的位置。h[k]存储的是以k为哈希值的链表的第一个结点的下标 
	h[k] = index++;
}
bool find( int x ){
	int k = ( x % N + N ) % N;
	for( int i = h[k]; i != -1; i = ne[i]){
		if( e[i] == x ) return 1;
	}
	return 0;
} 
int main(){
	int n; cin >> n;
	memset(h, -1, sizeof(int) * N );
	while( n-- ){
		string op;
		int x;
		cin >> op >> x;
		if( op == "i" ) insert( x );
		else{
			if( find(x) ) cout << "Yes" << '\n';
			else cout << "No" << '\n';
		}
	}
} */

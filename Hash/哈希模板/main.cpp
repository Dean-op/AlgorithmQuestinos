
//����Ѱַ�� 
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
	/*ʹ�ÿ���Ѱַ������Ԫ�أ�ͨ�����Ϻ��� k��ֱ���ҵ�һ���ղ�λ�����ҵ�ֵ���� x �Ĳ�λ��
	����ҵ��ղ�λ���򷵻ؿղ�λ������������ҵ�ֵ���� x �Ĳ�λ���򷵻ظò�λ������*/
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
	int k = ( x % N + N) % N;//ȷ����ϣֵΪ���������Ҳ�����N ��ע�ⲻ�ᷢ���ظ���ϣֵ���⣬��δ��벢û�н����ͻ���� 
	e[index] = x;
	ne[index] = h[k];//ne[index]��ʾ��һ���ڵ��λ�á�h[k]�洢������kΪ��ϣֵ������ĵ�һ�������±� 
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

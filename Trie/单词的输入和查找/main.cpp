//��ѯ�ַ������ֵĴ��� 
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
#define PII pair<int,int>
const int N(1e6);
int index;//���ڵ��� 
int cnt[N];//��¼��cnt[p]Ϊ��β���ַ����ĳ��ִ��� 
int son[N][26];//���ӽڵ�son[p][u]�洢�ڵ�p����u�������ߵ����ӽڵ�(�Ǹ����) 
void insert( string& str){
	int p = 0;
	rep( i,0,str.size() ){
		int u = str[i] - 'a';//��ĸӳ��ı������ֱ�ʾ 
		if( !son[p][u] ) son[p][u] = ++index;//��������߲����ڣ����������߲�������Ľڵ��� 
		p = son[p][u];//pָ���µĸ��ڵ� 
	}
	cnt[p]++;//���²������ 
}
int query( string& str ){
	int p = 0;
	rep( i,0,str.size() ){
		int u = str[i] - 'a';
		if( !son[p][u] ) return 0;//��������������ߣ�˵���������⴮�ַ��� 
		p = son[p][u];
	}
	return cnt[p];//
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
	int n;
	cin >> n;
	while( n-- ){
		char op; cin >> op;
		string str; cin >> str;
		if( op == 'I' ) insert( str );//
		else cout << query( str );
	}
}

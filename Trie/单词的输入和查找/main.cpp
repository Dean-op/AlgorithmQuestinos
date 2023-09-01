//查询字符串出现的次数 
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
#define PII pair<int,int>
const int N(1e6);
int index;//给节点编号 
int cnt[N];//记录以cnt[p]为结尾的字符串的出现次数 
int son[N][26];//儿子节点son[p][u]存储节点p沿着u这条边走到的子节点(是个编号) 
void insert( string& str){
	int p = 0;
	rep( i,0,str.size() ){
		int u = str[i] - 'a';//字母映射的边以数字表示 
		if( !son[p][u] ) son[p][u] = ++index;//如果这条边不存在，创建这条边并给到达的节点编号 
		p = son[p][u];//p指向新的根节点 
	}
	cnt[p]++;//更新插入次数 
}
int query( string& str ){
	int p = 0;
	rep( i,0,str.size() ){
		int u = str[i] - 'a';
		if( !son[p][u] ) return 0;//如果不存在这条边，说明不存在这串字符串 
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

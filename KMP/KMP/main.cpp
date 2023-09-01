#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
#define PII pair<int,int>
const int N(1e6);
void getPrefix( string& pattern, vector<int>& prefix ){
	prefix[0] = 0;//prefixTable��һ����Ϊ0 
	int i = 1,len = 0;//��һ��λ���Ѿ�Ϊ0�����Դ�1��ʼ���㣻len�������ǰ��׺ 

	while( i < pattern.size() ){
		if( pattern[i] == pattern[len] ){//�����ͬ������aaΪ�Ӵ�,len��Ϊ1 => prefix[1] = 1 
			len++;
			prefix[i] = len;
			i++;
		}
		else{
			if( len > 0 ) len = prefix[len-1];//�������ͬ�������ǰ��׺����0,len = prefix[len-1] 
			else {//len=0 => ǰ��û�й���ǰ��׺ => prefix[i] = 0���� 
				prefix[i] = len;
				i++;
			}
		}
	}
	//���� prefix �������kmp��ʵ�� 
	for( int i = pattern.size()-1; i > 0; i -- )
	prefix[i] = prefix[i-1];
	prefix[0] = -1;
}
vector<int> kmp( string& text, string& pattern ){
	vector<int>prefix( pattern.size(),0 ),ans;
	getPrefix( pattern, prefix ) ;
	int i = 0, j = 0;//text��pattern���ӵ�һ��Ԫ�ؿ�ʼƥ�� 
	while( i < text.size() ){
		if( text[i] == pattern[j] ){
			i++; j++;
			if( j == pattern.size()-1 && text[i] == pattern[j] ){//��patternƥ�䵽���һ��Ԫ���Һ�text��Ԫ����ͬ���洢�±� 
				ans.push_back( i-j );
				j = prefix[j];//����j��Ŀ���Ǻ����ƥ�� 
			} 
		}
		else{
			j = prefix[j];//�ƶ����prefix�����Բ���Ҫprefix[j-1]����Ҫ�����prefix���� 
			if( j == -1 ){//�������ͬ��j�Ѿ����µ���һ��Ԫ��֮ǰ��λ���ˣ������i��j�����������µĵ�һ����ʼ�Ա� 
				i++; j++;
			} 
		}
	}
	return ans;
}
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
	string text,pattern;
	//text.assign("ababababcdababababcd");
	cin >> text >> pattern;
	vector<int>ans = kmp( text,pattern );
	for( auto& num: ans ){
		cout << num << " " <<endl;
	}
}

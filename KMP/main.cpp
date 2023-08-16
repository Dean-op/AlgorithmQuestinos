#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
#define PII pair<int,int>
const int N(1e6);
void getPrefix( string& pattern, vector<int>& prefix ){
	prefix[0] = 0;//prefixTable第一个必为0 
	int i = 1,len = 0;//第一个位置已经为0，所以从1开始计算；len是最长公共前后缀 

	while( i < pattern.size() ){
		if( pattern[i] == pattern[len] ){//如果相同，想象aa为子串,len就为1 => prefix[1] = 1 
			len++;
			prefix[i] = len;
			i++;
		}
		else{
			if( len > 0 ) len = prefix[len-1];//如果不相同且最长公共前后缀大于0,len = prefix[len-1] 
			else {//len=0 => 前面没有公共前后缀 => prefix[i] = 0即可 
				prefix[i] = len;
				i++;
			}
		}
	}
	//右移 prefix 便与后面kmp的实现 
	for( int i = pattern.size()-1; i > 0; i -- )
	prefix[i] = prefix[i-1];
	prefix[0] = -1;
}
vector<int> kmp( string& text, string& pattern ){
	vector<int>prefix( pattern.size(),0 ),ans;
	getPrefix( pattern, prefix ) ;
	int i = 0, j = 0;//text与pattern都从第一个元素开始匹配 
	while( i < text.size() ){
		if( text[i] == pattern[j] ){
			i++; j++;
			if( j == pattern.size()-1 && text[i] == pattern[j] ){//当pattern匹配到最后一个元素且和text的元素相同，存储下标 
				ans.push_back( i-j );
				j = prefix[j];//更新j，目的是后面的匹配 
			} 
		}
		else{
			j = prefix[j];//移动后的prefix，所以不需要prefix[j-1]，不要与计算prefix混淆 
			if( j == -1 ){//如果不相同且j已经更新到第一个元素之前的位置了，则更新i、j从两个串的新的第一个开始对比 
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

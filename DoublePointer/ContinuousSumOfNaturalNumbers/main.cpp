#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define RREP(i,a,b) for(int i=a; i>=b; i++)
#define ll long long
using std::cin;
using std::cout;
using std::endl;
const ll N(1e9+5);
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
//**********************************
	int M,sum = 3;
	cin >> M;
	for( int i = 1, j = 2; i <= M/2; ){
		if(sum < M){
			j++;
			sum+=j;
		}
		else if( sum == M ){
			cout << i << " " << j << endl;
			sum -= i;
			i++;
		} 
		else{
			sum -= i;
			i++;
		}
	}

  
}


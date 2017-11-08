#include<stdio.h>
#include<stack>

int main(){
	int T;
	int cnt = 0;
	scanf("%d",&T);
	while(T--){
		char s[100001];
		scanf("%s",s);
		std::stack<char> str;
		for( int i = 0; s[i] != 0; ++i ){
			if( str.size() > 0 && str.top() == s[i] ){
				str.pop();
			} else {
				str.push(s[i]);
			}
		}
		if( str.size() == 0 ){
			++cnt;
		}
	}
	printf("%d\n",cnt);
}

#include<stdio.h>
#include<string>
#include<map>

std::map<std::string,int> m;

int main(){
	int N;
	scanf("%d",&N);
	int cnt = 0;
	for( int i = 0; i < N; ++i ){
		char s[21];
		scanf("%s",s);
		std::string str = s;
		if( i-m[s] < m[s]++ ){
			++cnt;
		}
	}
	printf("%d\n",cnt);
	return 0;
}

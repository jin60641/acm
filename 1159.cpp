#include<stdio.h>
#include<vector>

int cnt[26], N;
int main(){
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		char name[50];
		scanf("%s",name);
		++cnt[name[0]-'a'];
	}
	std::vector<char> result;
	for( int i = 0; i < 26; ++i ){
		if( cnt[i] >= 5 ){
			result.push_back('a'+i);
		}
	}
	if( result.size() == 0 ){
		printf("PREDAJA\n");
	} else {
		for( int i = 0; i < result.size(); ++i ){
			printf("%c",result[i]);
		}
	}
	return 0;
}

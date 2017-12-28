#include<stdio.h>

int k[4];
int cnt[100];
int main(){
	for( int i = 1; i <= 3; ++i ){
		scanf("%d",&k[i]);
	}
	for( int i = 1; i <= 3; ++i ){
		++cnt[k[i]];
	}
	if( cnt[4] >= 2 ){
		++cnt[2];
	}
	if( cnt[1] >= 1 || cnt[2] >= 2 || cnt[3] >= 3 ){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}

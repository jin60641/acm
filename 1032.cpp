#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	char s[50][51];
	for( int i = 0; i < N; ++i ){
		scanf("%s",s[i]);
	}
	char flag;
	char result[51];
	int j = 0;
	for( ; s[0][j] != '\0' ; ++j ){
		flag = '\0';
		for( int i = 0; i < N; ++ i ){
			if( flag == '\0' ){
				flag = s[i][j];
				result[j] = flag;
			} else if( flag != s[i][j] ){
				result[j] = '?';
			}
		}
	}
	result[j] = '\0';
	printf("%s\n",result);
}

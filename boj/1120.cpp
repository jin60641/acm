#include<stdio.h>
#include<string.h>
int main(){
	char s1[100], s2[100];
	scanf("%s",&s1);
	scanf("%s",&s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int result = 1000000;
	for( int i = 0; i <= len2-len1; ++i ){
		int cnt = 0;
		for( int j = 0; j < len1; ++j ){
			if(s1[j]!=s2[i+j]){
				++cnt;
			}
		}
		result = cnt<result?cnt:result;
	}
	printf("%d\n",result);
	return 0;
}

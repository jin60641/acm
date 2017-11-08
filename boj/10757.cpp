#include<stdio.h>
#include<string.h>

int result[10010];
char A[10010];
char B[10010];
int main(){
	scanf("%s",A);
	scanf("%s",B);
	int ai = strlen(A)-1;
	int bi = strlen(B)-1;
	int cnt = 0;
	while( ai >= 0 || bi >= 0 ){
		int a = ai>=0?A[ai]-'0':0;
		int b = bi>=0?B[bi]-'0':0;
		result[cnt] += a+b;
		if( result[cnt] >= 10 ){
			result[cnt+1] = result[cnt]/10;
			result[cnt] = result[cnt]%10;
		}
		++cnt;
		--ai;
		--bi;
	}
	for( int i = result[cnt]==0?cnt-1:cnt; i >= 0; --i ){
		printf("%d",result[i]);
	}
	printf("\n");
	return 0;
}

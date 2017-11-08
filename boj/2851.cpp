#include<stdio.h>

int main(){
	int num[10];
	int dp[11];
	for( int i = 0; i < 10; ++i ){
		scanf("%d",&num[i]);
	}
	dp[0] = 0;
	int i = 1;
	for( ; i < 11; ++i ){
		dp[i] = dp[i-1] + num[i-1];
		if( dp[i] >= 100 ){
			break;
		}
	}
	if( i == 11 ){
		printf("%d",dp[10]);
	} else if( dp[i] == 100 ){
		printf("100");
	} else if( dp[i] - 100 <= 100 - dp[i-1] ){
		printf("%d",dp[i]);
	} else {
		printf("%d",dp[i-1]);
	}
	return 0;
}

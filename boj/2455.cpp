#include<stdio.h>

int main(){
	int n = 4;
	int a[4];
	for( int i = 0; i < n; ++i ){
		int A,B;
		scanf("%d %d",&A,&B);
		a[i] = B-A;
	}
	int dp[4];
	dp[0] = a[0];
	int result = a[0];
	for( int i = 1; i < n; ++i ){
		dp[i] = dp[i-1] + a[i];
		if( dp[i] > result ){
			result = dp[i];
		}
	}
	printf("%d\n",result);
	
	return 0;
}

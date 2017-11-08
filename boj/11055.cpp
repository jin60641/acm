#include<stdio.h>
int max(int a, int b){
	return a>b?a:b;
}
int main(){
	int N,a[1000],dp[1000];
	scanf("%d", &N);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
		dp[i] = a[i];
	}
	for( int i = 1; i < N; ++i ){
		for( int j = 0; j < i; ++j ){
			if( a[j] < a[i] ){
				dp[i] = max( dp[i], dp[j]+a[i] );
			}
		}
	}
	int result = 0;
	for( int i = 0; i < N; ++ i){
		result = max( result, dp[i] );
	}
	printf("%d\n",result);
	return 0;
}


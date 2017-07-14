#include<stdio.h>
#include<algorithm>

int main(){
	int N;
	scanf("%d",&N);
	int a[1000];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
	}
	int dp[1000];
	std::sort(a,a+N);
	int sum = a[0];
	dp[0] = a[0];
	for( int i = 1; i < N; ++i ){
		dp[i] = dp[i-1] + a[i];
		sum += dp[i];
	}
	printf("%d\n",sum);
	return 0;
}

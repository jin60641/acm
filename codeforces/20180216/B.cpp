#include<stdio.h>
#include<stdlib.h>

int cnt[10][1000006];
int dp[1000006];
int f(int n){
	int tmp = n;
	int a = 1;
	while( tmp > 0 ){
		if( dp[tmp] ){
			a *= dp[tmp];
			break;
		}
		if( tmp%10 != 0 ){
			a *= tmp%10;
		}
		tmp /= 10;
	}
	dp[n] = a;
	return dp[n];
}

int g(int n){
	if( dp[n] ){
		return dp[n];
	} else {
		int tmp = g(f(n));
		dp[n] = tmp;
		return tmp;
	}
}

int main(){
	int Q, l, r, k;
	scanf("%d",&Q);
	for( int i = 1; i <= 1000000; ++i ) g(i);
	for( int i = 1; i <= 1000000; ++i )
		for( int j = 1; j <= 9; ++j )
			cnt[j][i] = cnt[j][i - 1] + (dp[i] == j ? 1 : 0);
	while(Q--){
		scanf("%d %d %d",&l,&r,&k);
		printf("%d\n", cnt[k][r] - cnt[k][l - 1]);
	}
	return 0;
}

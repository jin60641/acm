#include<stdio.h>
const int INF = 1000*1000+10;
int min(int a, int b){
	return a==0?b:(a<b?a:b);
}
int pow( int a ){
	return a*a;
}
int N,dp[1000];
int main(){
	char s[1001];
	scanf("%d",&N);
	scanf("%s",s);
	for( int i = 0; i < N; ++i ){
		if( dp[i] == INF ){
			continue;
		}
		for( int j = i+1; j < N; ++j ){
			if( ( s[i] == 'B' && s[j] == 'O' ) || ( s[i] == 'O' && s[j] == 'J' ) || ( s[i] == 'J' && s[j] == 'B' ) ){
				dp[j] = min( dp[j], dp[i] + pow(j-i) );
			} else if( dp[j] == 0 ){
				dp[j] = INF;
			}
		}
	}
	if( dp[N-1] != 0 && dp[N-1] != INF ){
		printf("%d\n",dp[N-1]);
	} else {
		printf("-1\n");
	}
	return 0;
}

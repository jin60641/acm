#include<stdio.h>

struct btn{
	int a,b,c,cnt;
};

int main(){
	int T;
	scanf("%d",&T);
	btn dp[20000];
	dp[0].a = 0;
	dp[0].b = 0;
	dp[0].c = 0;
	dp[0].cnt = 0;
	for( int i = 1; i <= T; ++i ){
		dp[i].cnt = 10000;
	}
	for( int i = 0; i < T; ++i ){
		if( dp[i+10].cnt > dp[i].cnt+1 ){
			dp[i+10].cnt = dp[i].cnt+1;
			dp[i+10].a = dp[i].a;
			dp[i+10].b = dp[i].b;
			dp[i+10].c = dp[i].c+1;
		}
		if( dp[i+60].cnt > dp[i].cnt+1 ){
			dp[i+60].cnt = dp[i].cnt+1;
			dp[i+60].a = dp[i].a;
			dp[i+60].b = dp[i].b+1;
			dp[i+60].c = dp[i].c;
		}
		if( dp[i+300].cnt > dp[i].cnt+1 ){
			dp[i+300].cnt = dp[i].cnt+1;
			dp[i+300].a = dp[i].a+1;
			dp[i+300].b = dp[i].b;
			dp[i+300].c = dp[i].c;
		}
	}
	if( dp[T].cnt == 10000 ){
		printf("-1\n");
	} else {
		printf("%d %d %d\n",dp[T].a,dp[T].b,dp[T].c);
	}
	return 0;
}

#include<stdio.h>
int min( int a, int b ){
	return a<b?a:b;
}
int max( int a, int b ){
	return a>b?a:b;
}
struct pair {
	int min, max;
};

int a[1001];
pair dp[1001];
pair get(int l, int r){
	pair ret = { min( dp[l].max, a[r] ), max( dp[l].min, a[r] ) };
	return ret;
}
int main(){
	int N;
	scanf("%d",&N);
	for( int i = 1; i <= N; ++i ){
		scanf("%d",&a[i]);
		dp[i].max = i==1?a[i]:(max( dp[i-1].max, a[i] ));
		dp[i].min = i==1?a[i]:(min( dp[i-1].min, a[i] ));
	}
	/*
	for( int i = 2; i <= N; ++i ){	
		for( int j = 1; j < i; ++j ){
			dp[i] = 
		}
	}
	*/
	while( true ){
		int l, r;
		/*
		scanf("%d",&l);
		printf("%d %d\n",dp[l].min,dp[l].max);
		*/
		scanf("%d %d",&l,&r);
		pair g = get(l,r);
		printf("%d~%d\n",g.min,g.max);
	}
	return 0;
}

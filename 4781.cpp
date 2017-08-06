#include<stdio.h>
#include<vector>

int max( int a, int b ){
	return a>b?a:b;
}

struct s {
	int c,p;
};

int main(){
	while( true ){
		int n,m;
		char a,b;
		scanf("%d %d.%c%c",&n,&m,&a,&b);
		m = m*100 + (a-'0')*10 + b-'0';
		if( n == 0 && m== 0 ){
			return 0;
		}
		std::vector<s> v;
		int dp[10001] = { 0, };
		for( int i = 1; i <= m; ++i ){
			dp[i] = -1;
		}
		for( int i = 1; i <= n; ++i ){
			int c, p;
			scanf("%d %d.%c%c",&c,&p,&a,&b);
			s candy = { c,  p*100 + (a-'0')*10 + b-'0' };
			v.push_back(candy);
		}
		int result = 0;
		for( int i = 0; i < n; ++i ){
			for( int j = 0; j <= m-v[i].p; ++j ){
				if( dp[j] != -1 ){
					dp[j+v[i].p] = max( dp[j] + v[i].c, dp[j+v[i].p] );
					result = max( result, dp[j+v[i].p] );
				}
			}
		}
		printf("%d\n",result);
	}
}

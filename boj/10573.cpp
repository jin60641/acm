#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	long long int sum[81];
	sum[0] = 1;
	sum[1] = 10;
	for( int k = 1; k <= 80; ++k ){
		int N = k;
		long long int dp[10];
		dp[0] = 0;
		for( int i = 1; i <= 9; ++i ){
			dp[i] = 1;
		}
		for( int i = 2; i <= N; ++i ){
			for( int j = 1; j <= 9; ++j ){
				dp[j] += dp[j-1];
			}
		}
		long long int tot = 0;
		for( int i = 0; i <= 9; ++i ){
			tot += dp[i];
		}
		sum[k] = tot;
	}
	while( T-- ){
		char s[81];
		scanf("%s",&s);
		long long int tot = 0;
		int len = 0;
		int flag = 0;
		for( len = 1; s[len] != 0; ++len ){
			if( s[len] < s[len-1] ){
				flag = 1;
				break;
			}
		}
		if( flag == 1 ){
			printf("-1\n");
			continue;
		}
		for( int k = 0; k < len; ++k ){
			int min = (k==0)?1:(s[k-1]-'0');
			int max = (s[k]-'0')-1;
			int N = len-k;
			long long int dp[10];
			for( int i = 1; i <= 9; ++i ){
				if( min <= i && i <= max ){
			   		dp[i] = 1;
				} else {
					dp[i] = 0;
				}
			}
			
			for( int i = 1; i < N; ++i ){
				for( int j = 1; j <= 9; ++j ){
					dp[j] += dp[j-1];
				}
			}
			for( int i = 0; i <= 9; ++i ){
				tot += dp[i];
			}
		}
		for( int i = 0; i < len; ++i ){
			tot += sum[i];
		}
		printf("%lld\n",tot);
	}
	return 0;
}

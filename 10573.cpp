#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	int sum[81];
	sum[0] = 1;
	sum[1] = 10;
	for( int k = 2; k <= 80; ++k ){
	    int N = k;
	    long long int dp[10];
	    for( int i = 0; i <= 9; ++i ){
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
		long long int dp[10];
		for( int i = 0; i <= 9; ++i ){
			dp[i] = 0;
		}
		dp[1] = 1;
		for( int i = 2; i <= s[0]-'0'; ++i ){
			dp[i] += dp[i-1]+1;
		}

		int tmp;
		for( int i = 1; i < len; ++i ){
			tmp = dp[s[i-1]-'0'];
			for( int j = 1; j <= s[i]-'0'; ++j ){
				if( dp[j] == 0 ){
					dp[j] += dp[j-1] + tmp;
				} else {
					dp[j] += dp[j-1];
				}
			}
		}
		for( int i = 0; i <= 9; ++i ){
			printf("%d ",dp[i]);
		}
		printf("\n");
		printf("%d + %d - 1 = %d\n",dp[s[len-1]-'0'],sum[len-1],dp[s[len-1]-'0']+sum[len-1]-1);
	}
	return 0;
}

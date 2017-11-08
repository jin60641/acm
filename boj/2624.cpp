#include<stdio.h>

/*
	T : 지폐의 금액
	k : 동전의 가지 수
	p_i : i번째 동전의 가치
	n_i : i번째 동전의 개수
*/

int main(){
	int T,k,p[101],n[101],dp[10001];
	scanf("%d",&T);
	scanf("%d",&k);
	for( int i = 1; i <= k; ++i ){
		scanf("%d %d",&p[i],&n[i]);
	}

	dp[T] = 1;
	
	for( int i = 1; i <= k; ++i ){
		for( int j = p[i]; j <= T; ++j ){
			if( dp[j] != 0 ){
				for( int k = 1; k <= n[i]; ++k ){
					if( j - k*p[i] < 0 ){
						break;
					}
					dp[j-k*p[i]] += dp[j];
				}
			}
		}
	}
	printf("%d",dp[0]);
}

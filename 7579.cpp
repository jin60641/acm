#include<stdio.h>
int N,M,m[101],c[101];
long long int dp[20000001];

/*
	N : 실행중인 앱의 갯수
	M : 확보해야 하는 메모리
	m_i : i번째 앱이 사용하는 메모리
	c_i : i번째 앱을 비활성화 하는데 필요한 메모리
	dp : i만큼의 메모리를 비활성화 하는데 필요한 메모리
*/

long long int min( long long int a, long long int b ){
	if( a == -1 ){
		return b;
	} else if( b == -1 ){
		return a;
	} else {
		return a<b?a:b;
	}
}

int main(){
    scanf("%d %d",&N,&M);
    for( int i = 1; i <= N; ++i ){
        scanf("%d",&m[i]);
    }
    for( int i = 1; i <= N; ++i ){
        scanf("%d",&c[i]);
    }
	dp[0] = 0;
	for( int i = 1; i <= 20000000; ++i ){
		dp[i] = -1;
	}
	long long int result = 1010000001;
	for( int i = 1; i <= N; ++i ){
		for( int j = M+10000000; j >= 1; --j ){
			if( m[i] <= j && ( dp[j-m[i]] >= 0 ) ){
				dp[j] = min(dp[j], dp[j-m[i]] + c[i]);
				if( j >= M ){
					result = min( result, dp[j] );
				}
			}
		}
	}
	
	printf("%lld",result);
}

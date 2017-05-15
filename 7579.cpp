/*
	N : 실행중인 앱의 갯수
	M : 확보해야 하는 메모리
	m_i : i번째 앱이 사용하는 메모리
	c_i : i번째 앱을 비활성화 하는데 필요한 메모리
	dp : i만큼의 메모리를 비활성화 하는데 필요한 메모리
*/

#include<stdio.h>
int N,M,m[101],c[101];
int dp[10001];

int max( int a, int b ){
	return a>b?a:b;
}

int min( int a, int b ){
	return a<b?a:b;
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
	for( int i = 1; i <= 10000; ++i ){
		dp[i] = -1;
	}
	int result = 10002;
	for( int i = 1; i <= N; ++i ){
		for( int j = 10000; j >= 0; --j ){
			if( dp[j] != -1 ){
				dp[j+c[i]] = max(dp[j+c[i]],dp[j]+m[i]);
				if( dp[j+c[i]] >= M ){
					result = min(j+c[i],result);
				}
			}
		}
	}
	printf("%d\n",result);
}

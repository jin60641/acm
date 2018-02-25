#include<stdio.h>
#include<queue>
#include<vector>
const int max_cost = 50;
const int max_N = 16;
const int INF = max_N * max_cost + 1;

int min(int a, int b){
	return a<b?a:b;
}

int main(){
	int N, P, a[16][16], sum = 0, dp[1<<max_N], result = INF, cnt = 0, bits[16];
	char s[17];
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		bits[i] = 1<<i;
	}
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			scanf("%d",&a[i][j]);
		}
	}
	const int bit = bits[N-1]<<1;
	scanf("%s",s);
	scanf("%d",&P);
	for( int i = 0; i < bit; ++i ){
		dp[i] = INF;
	}
	for( int i = 0; i < N; ++i ){
		if( s[i] == 'Y' ){
			++cnt;
			dp[1<<i] = 0;
		}
	}
	if( cnt == 0 ){
		printf("-1\n");
		return 0;
	} else if( cnt >= P ){
		printf("0\n");
		return 0;
	}
	for( int i = 0; i < bit; ++i ){
		if( dp[i] == INF ){
			continue;
		}
		int bcnt = 0;
		std::vector<int> on;
		std::queue<int> off;
		for( int j = 0; j < N; ++j ){
			if( bits[j] & i ) {
				on.push_back(j);
				++bcnt;
			} else {
				off.push(j);
			}
		}
		if( bcnt >= P ){
			result = min( result, dp[i] );
		}
		while( !off.empty() ){
			int j = off.front();
			off.pop();
			if( s[j] == 'Y' ){
				dp[i+bits[j]] = min( dp[i+bits[j]], dp[i] );
			} else {
				const int size = on.size();
				for( int k = 0; k < size; ++k ){
					dp[i+bits[j]] = min( dp[i+bits[j]], dp[i] + a[on[k]][j] );
				}
			}
		}
	}
	
	printf("%d\n",result);
	return 0;
}

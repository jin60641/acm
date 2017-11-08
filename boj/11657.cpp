#include<stdio.h>
const int INF = 500000001;
int min( int a, int b ){
	return a<b?a:b;
}
struct edge {
	int from, to, weight;
};
edge e[6000];
int main(){
	int N,M,check[501];
	scanf("%d %d",&N,&M);
	check[1] = 0;
	for( int i = 2; i <= N; ++i ){
		check[i] = INF;
	}
	for( int i = 0; i < M; ++i ){
		scanf("%d %d %d",&e[i].from,&e[i].to,&e[i].weight);
	}
	for( int i = 1; i <= N-1; ++i ){
		for( int j = 0; j < M; ++j ){
			if( check[e[j].from] != INF ){
				check[e[j].to] = min( check[e[j].to], check[e[j].from] + e[j].weight );
			}
		}
	}
	for( int i = 0; i < M; ++i ){
		if( check[e[i].from] != INF && ( check[e[i].from] + e[i].weight < check[e[i].to] ) ){
			printf("-1\n");
			return 0;
		}
	}
	for( int i = 2; i <= N; ++i ){
		printf("%d\n",check[i]==INF?-1:check[i]);
	}
	return 0;
}

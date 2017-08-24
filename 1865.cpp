#include<stdio.h>
#include<vector>
const int INF = 2500*10000+1;
struct edge{
	int S,E,T;
};
int min(int a, int b){
	return a<b?a:b;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N,M,W;
		int tmp[251][251];
		for( int i = 1; i <= N; ++i ){
			for( int j = 1; j <= N; ++j ){
				tmp[i][j] = INF;
			}
		}
		scanf("%d %d %d",&N,&M,&W);
		std::vector<edge> v;
		for( int i = 0; i < M; ++i ){
			int S,E,T;
			scanf("%d %d %d",&S,&E,&T);
			tmp[S][E] = min(tmp[S][E],T);
			tmp[E][S] = min(tmp[E][S],T);
		}
		for( int i = 0; i < W; ++i ){
			int S,E,T;
			scanf("%d %d %d",&S,&E,&T);
			tmp[S][E] = min(tmp[S][E],-T);
		}
		for( int i = 1; i <= N; ++i ){
			for( int j = 1; j <= N; ++j ){
				if( tmp[i][j] != INF ){
					edge e = { i, j, tmp[i][j] };
					v.push_back(e);
				}
			}
		}
		int flag = 0;
		for( int i = 1; i <= N; ++i ){
			int dist[251];
			for( int j = 1; j <= N; ++j ){
				dist[j] = INF;
			}
			dist[i] = 0;
			for( int j = 1; j <= N; ++j ){
				for( int k = 0; k < v.size(); ++k ){
					if( dist[v[k].S] != INF && dist[v[k].E] > dist[v[k].S] + v[k].T ){
						if( j == N ){
							flag = 1;
							break;
						}
						dist[v[k].E] = dist[v[k].S] + v[k].T;
					}
				}
				for( int k = 1; k <= 3; ++k ){
					printf("%d ", dist[j]);
				}
				printf("\n");
			}
			if( flag == 1 ){
				break;
			}
		}
		printf("%s",flag==1?"YES":"NO");
	}
}

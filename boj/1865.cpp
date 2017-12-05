#include<stdio.h>
#include<vector>
int INF = 2500*10000+1;
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
        int tmp[501][501];
        scanf("%d %d %d",&N,&M,&W);
        for( int i = 1; i <= N; ++i ){
            for( int j = 1; j <= N; ++j ){
                tmp[i][j] = INF;
            }
        }
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
		int dist[501];
        for( int i = 1; i <= N; ++i ){
            dist[i] = INF;
        }
        dist[1] = 0;
        int flag = 0;
        for( int i = 1; i <= N; ++i ){
            for( int j = 0; j < v.size(); ++j ){
                if( dist[v[j].S] != INF && dist[v[j].E] > dist[v[j].S] + v[j].T ){
                    if( i == N ){
                        flag = 1;
                        break;
                    }
                    dist[v[j].E] = dist[v[j].S] + v[j].T;
                }
            }
        }
        printf("%s\n",flag==1?"YES":"NO");
    }
}


#include<stdio.h>
#include<vector>
#include<queue>
const int INF = 200000000;
int N,M,start,end;
struct pair {
    int n, w;
};
struct edge {
    int to,w;
};
std::vector<edge> v[1001];
std::vector<int> path[1001];
struct cmp {
    bool operator()(pair a, pair b){
        return a.w < b.w;
    }
};
int check[1001];
std::priority_queue<pair,std::vector<pair>,cmp> pq;
int bfs(){
    pair now = pq.top();
    pq.pop();
    if( now.n == end || now.w > check[now.n] ){
        return 0;
    }
    for( int i = 0; i < v[now.n].size(); ++i ){
        edge n = v[now.n][i];
        if( check[n.to] > now.w + n.w ){
            path[n.to].clear();
            path[n.to].assign(path[now.n].begin(),path[now.n].end());
            path[n.to].push_back(n.to);
            check[n.to] = now.w + n.w;
            pair p = { n.to, check[n.to] };
            pq.push(p);
        }
    }
    return 0;
}
int main(){
    scanf("%d %d",&N,&M);
    for( int i = 1; i <= N; ++i ){
        check[i] = INF;
    }
    for( int i = 0; i < M; ++i ){
        int from;
        edge e;
        scanf("%d %d %d",&from,&e.to,&e.w);
        v[from].push_back(e);
    }
    scanf("%d %d",&start,&end);
    check[start] = 0;
    pair s = { start, 0 };
    path[start].push_back(start);
    pq.push(s);
    while( pq.size() > 0 ){
        bfs();
    }
    printf("%d\n%d\n",check[end],path[end].size());
    for( int i = 0; i < path[end].size(); ++i ){
        printf("%d ",path[end][i]);
    }
    printf("\n");
    return 0;
}


#include<stdio.h>
#include<vector>
#include<queue>
const long long int INF = 200000001;
int N,M,first,second,start,end;
struct pair {
    int n;
    long long int w;
};
struct edge {
    int to;
    long long int w;
};
std::vector<edge> v[1001];
struct cmp {
    bool operator()(pair a, pair b){
        return a.w < b.w;
    }
};
long long int check[1001];
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
            check[n.to] = now.w + n.w;
            pair p = { n.to, check[n.to] };
            pq.push(p);
        }
    }
    return 0;
}

void clear(){
    for( int i = 1; i <= N; ++i ){
        check[i] = INF;
    }
    check[start] = 0;
    pair s = { start, 0 };
    pq.push(s);
}

long long int init(int path[4]){
    long long int ret = 0;
    for( int i = 1; i <= 3; ++i ){
        start = path[i-1];
        end = path[i];
        clear();
        while( pq.size() > 0 ){
            bfs();
        }
        if( check[end] == INF ){
            return -1;
        } else {
            ret += check[end];
        }
    }
    return ret;
}
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
    for( int i = 0; i < M; ++i ){
        int from,to;
		long long int w;
        scanf("%d %d %lld",&from,&to,&w);
        edge e1 = { to, w };
        edge e2 = { from, w };
        v[from].push_back(e1);
        v[to].push_back(e2);
    }
    scanf("%d %d",&first,&second);
    int path[4] = { 1, first, second, N };
    long long int result = init(path);
    path[1] = second;
    path[2] = first;
    result = min(result,init(path));
    printf("%lld\n",result);
    return 0;
}



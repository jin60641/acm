#include<stdio.h>
#include<vector>
#include<queue>
int N,M,A,B,K,G;
const int INF = 1000000000;
int result = INF;
struct pair {
	int num;
	int w;
};

struct cmp {
	bool operator()(pair a, pair b){
		return a.w > b.w;
	}
};
std::priority_queue<pair,std::vector<pair>,cmp> pq;

int visit[1000];
struct edge {
	int to, w;
};
int E[1001][1001];
struct time {
	int start,end;
};
time cant[1001][1001];

int find(){
	pair now = pq.top();
	if( now.num == B ){
		result = now.w;
	} else if( visit[now.num] == 0 ){
		visit[now.num] = 1;
		for( int i = 1; i <= N; ++i ){
			if( E[now.num][i] > 0 && visit[i] == 0 ){
				pair next = { i, now.w + E[now.num][i] };
				if( cant[now.num][i].end != 0 && cant[now.num][i].start <= now.w && now.w <= cant[now.num][i].end ){
					next.w = cant[now.num][i].end+1+E[now.num][i];
				}
				pq.push(next);
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d %d",&N,&M);
	scanf("%d %d %d %d",&A,&B,&K,&G);
	int g[1000];
	for( int i = 0; i < G; ++i ){
		scanf("%d",&g[i]);
	}
	for( int i = 0; i < M; ++i ){
		int from,to,w;
		scanf("%d %d %d",&from,&to,&w);
		E[from][to] = w;
		E[to][from] = w;
	}
	int tot = 0;
	for( int i = 0; i < G-1; ++i ){
		time t = { tot, tot + E[g[i]][g[i+1]]-1 };
		cant[g[i]][g[i+1]] = t;
		cant[g[i+1]][g[i]] = t;
		tot += E[g[i]][g[i+1]];
	}
	pair start = { A, K };
	pq.push(start);
	while( pq.size() > 0 && result == INF ){
		find();
		pq.pop();
	}
	printf("%d\n",result-K);
	return 0;
}

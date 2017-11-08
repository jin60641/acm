#include<stdio.h>
#include<vector>
#include<queue>
const int INF = 200000000;
int N = 500,M,start,end;
struct pair {
	int n, w;
};
struct edge {
	int to,w;
};
std::vector<edge> v[500];
std::vector<int> path[500];
struct cmp {
	bool operator()(pair a, pair b){
		return a.w < b.w;
	}
};
int check[500];
int shortest[500][500];
std::priority_queue<pair,std::vector<pair>,cmp> pq;

int dfs(int now){
	for( int i = 0; i < path[now].size(); ++i ){
		if( shortest[path[now][i]][now] == 0 ){
			shortest[path[now][i]][now] = 1;
			dfs(path[now][i]);
		}
	}
	return 0;
}

void clear(){
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			shortest[i][j] = 0;
		}
		check[i] = INF;
		v[i].clear();
		path[i].clear();
	}
}

int bfs(){
	pair now = pq.top();
	pq.pop();
	if( now.w > check[now.n] ){
		return 0;
	} else if( now.n == end ){
		return 0;
	}
	for( int i = 0; i < v[now.n].size(); ++i ){
		edge n = v[now.n][i];
		if( shortest[now.n][n.to] == 1 ){
			continue;
		}
		if( check[n.to] > now.w + n.w ){
			check[n.to] = now.w + n.w;
			pair p = { n.to, check[n.to] };
			path[n.to].clear();
			path[n.to].push_back(now.n);
			pq.push(p);
		} else if( check[n.to] == now.w + n.w ){
			path[n.to].push_back(now.n);
		}
	}
	return 0;
}
int main(){
	while( true ){
		clear();
		scanf("%d %d",&N,&M);
		if( N == 0 && M == 0 ){
			return 0;
		}
		scanf("%d %d",&start,&end);
		for( int i = 0; i < M; ++i ){
			int from;
			edge e;
			scanf("%d %d %d",&from,&e.to,&e.w);
			v[from].push_back(e);
		}
		check[start] = 0;
		pair s = { start, 0 };
		pq.push(s);
		while( pq.size() > 0 ){
			bfs();
		}
		if( check[end] == INF ){
			printf("-1\n");
			continue;
		}
		for( int i = 0; i < N; ++i ){
			check[i] = INF;
		}
		dfs(end);
		check[start] = 0;
		check[end] = INF;
		pq.push(s);
		while( pq.size() > 0 ){
			bfs();
		}
		printf("%d\n",check[end]==INF?-1:check[end]);
	}
}


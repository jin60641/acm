#include<stdio.h>
#include<queue>
#include<vector>
const int MAX_N = 1000, MAX_T = 10000;
const int INF = MAX_T*MAX_N;
int N, M;
struct pair{
	int num, sum;
};
struct edge{
	int from, to, time;
};
struct cmp {
	bool operator()(pair a, pair b){ 
		return a.sum > b.sum;
	}
};
int max( int a, int b ){
	return a>b?a:b;
}
std::priority_queue<pair,std::vector<pair>,cmp> q;
std::vector<edge> E;
std::vector<edge> V[MAX_N+1];
std::vector<int> P[MAX_N+1];
int dist[MAX_N+1];
void f(){
	pair now = q.top();
	q.pop();
	for( int i = V[now.num].size()-1; i >= 0; --i ){
		edge next = V[now.num][i];
		if( next.time + now.sum < dist[next.to]  ){
			dist[next.to] = next.time + now.sum;
			P[next.to].clear();
			P[next.to].assign( P[now.num].begin(), P[now.num].end() );
			P[next.to].push_back(now.num);
			pair p = { next.to, next.time + now.sum };
			q.push(p);
		}
	}
}

void clear(){
	for( int i = 1; i <= N; ++i ){
		dist[i] = INF;
		V[i].clear();
		P[i].clear();
	}
}

int main(){
	scanf("%d %d",&N,&M);
	clear();
	for( int i = 0; i < M; ++i ){	
		edge e1;
		scanf("%d %d %d",&e1.from,&e1.to,&e1.time);
		E.push_back(e1);
		edge e2 = { e1.to, e1.from, e1.time };
		V[e1.from].push_back(e1);
		V[e2.from].push_back(e2);
	}
	pair start = { 1, 0 };
	dist[1] = 0;
	q.push(start);
	while( q.size() > 0 ){
		f();
	}
	std::vector<int> sp;
	sp.assign(P[N].begin(),P[N].end());
	sp.push_back(N);
	int tmp = dist[N];
	int ans = 0;
	for( int i = 1; i < sp.size(); ++i ){
		clear();
		for( int j = 0; j < M; ++j ){
			edge e1 = E[j];
			if( ( e1.from == sp[i] && e1.to == sp[i-1] ) || ( e1.from == sp[i-1] && e1.to == sp[i] ) ){
				continue;
			}
			edge e2 = { e1.to, e1.from, e1.time };
			V[e1.from].push_back(e1);
			V[e2.from].push_back(e2);
		}
		pair start = { 1, 0 };
		dist[1] = 0;
		q.push(start);
		while( q.size() > 0 ){
			f();
		}
		ans = max( ans, dist[N] );
	}
	printf("%d\n",((ans==INF)?(-1):(ans-tmp)));
	return 0;
}

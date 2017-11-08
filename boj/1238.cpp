#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
const int INF = 200000000;
int N,M,X;
struct pair {
	int num, weight;
};
struct edge {
	int from,weight;
};
std::vector<edge> v[1001];
std::vector<edge> v2[1001];
struct cmp {
	bool operator()(pair a, pair b){
		return a.weight < b.weight;
	}
};
int check[1001];
int result[1001];
std::priority_queue<pair,std::vector<pair>,cmp> pq;
int bfs(){
	pair now = pq.top();
	pq.pop();
	if( now.weight > check[now.num] ){
		return 0;
	}
	for( int i = 0; i < v[now.num].size(); ++i ){
		if( check[v[now.num][i].from] > now.weight + v[now.num][i].weight ){
			check[v[now.num][i].from] = now.weight + v[now.num][i].weight;
			pair p = { v[now.num][i].from, check[v[now.num][i].from] };
			pq.push(p);
		}
	}
	return 0;
}
int main(){
	scanf("%d %d %d",&N,&M,&X);
	for( int i = 1; i <= N; ++i ){
		check[i] = INF;
	}
	for( int i = 0; i < M; ++i ){
		int from,to,weight;
		scanf("%d %d %d",&from,&to,&weight);
		edge e1 = { from, weight };
		v[to].push_back(e1);
		edge e2 = { to, weight };
		v2[from].push_back(e2);
	}
	check[X] = 0;
	pair start = { X, 0 };
	pq.push(start);
	while( pq.size() > 0 ){
		bfs();
	}
	for( int i = 1; i <= N; ++i ){
		result[i] = check[i];
		check[i] = INF;
		v[i].clear();
	}
	
	for( int i = 1; i <= N; ++i ){
		v[i].assign(v2[i].begin(),v2[i].end());
	}
	check[X] = 0;
	pq.push(start);
	while( pq.size() > 0 ){
		bfs();
	}
	for( int i = 1; i <= N; ++i ){
		result[i] += check[i];
	}
	std::sort(result+1,result+1+N);
	printf("%d\n",result[N]);
	return 0;
}

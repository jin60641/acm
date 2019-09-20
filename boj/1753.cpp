#include<stdio.h>
#include<vector>
#include<queue>
const int INF = 5000000;
struct pair {
  int n, w;
};

struct edge {
	int to, w;
};
struct cmp {
    bool operator()(pair a, pair b){
        return a.w < b.w;
    }
};
std::priority_queue<pair,std::vector<pair>,cmp> pq;
std::vector<edge> v[20001];
int result[20001];
int bfs(){
	pair now = pq.top();
  if (now.w > result[now.n]) {
    return 0;
  }
	pq.pop();
	for( int i = 0; i < v[now.n].size(); ++i ){
    edge n = v[now.n][i];
		if( result[n.to] > now.w + n.w ){
			result[n.to] = now.w + n.w;
      pair p = { n.to, result[n.to] };
			pq.push(p);
		}
	}
	return 0;
}
int main(){
	int V,E,K;
	scanf("%d %d",&V,&E);
	scanf("%d",&K);
	for( int i = 0; i < E; ++i ){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		edge p = { b, w };
		v[a].push_back(p);
	}
	for( int i = 1; i<= V; ++i ){
		result[i] = INF;
	}
  pair s = { K, 0 };
	pq.push(s);
	result[K] = 0;
	while( pq.size() > 0 ){
		bfs();
	}
	for( int i = 1; i <= V; ++i ){
		if( result[i] == INF ){
			printf("INF\n");
		} else {
			printf("%d\n",result[i]);
		}
	}
	return 0;
}

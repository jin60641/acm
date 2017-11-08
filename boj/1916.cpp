#include<stdio.h>
#include<vector>
#include<queue>
const int INF = 100000001;
struct pair {
	int to, w;
};
std::queue<int> q;
std::vector<pair> v[20001];
int result[20001];
int start,end;
int bfs(){
	int now = q.front();
	if( now == end ){
		q.pop();
		return 0;
	}
	for( int i = 0; i < v[now].size(); ++i ){
		if( result[v[now][i].to] > result[now] + v[now][i].w ){
			result[v[now][i].to] = result[now] + v[now][i].w;
			q.push(v[now][i].to);
		}
	}
	q.pop();
	return 0;
}
int main(){
	int V,E;
	scanf("%d",&V);
	scanf("%d",&E);
	for( int i = 0; i < E; ++i ){
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		pair p = { b, w };
		v[a].push_back(p);
	}
	for( int i = 1; i<= V; ++i ){
		result[i] = INF;
	}
	scanf("%d %d",&start,&end);
	q.push(start);
	result[start] = 0;
	while( q.size() > 0 ){
		bfs();
	}
	if( result[end] == INF ){
		printf("INF\n");
	} else {
		printf("%d\n",result[end]);
	}
	return 0;
}

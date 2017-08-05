#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
const int INF = 500*1000+1;
struct pair {
	int to, w;
};
std::queue<int> q;
std::vector<pair> v[500];
std::vector<int> result;
int check[500];
int start,end,N,M;
int bfs(){
	int now = q.front();
	for( int i = 0; i < v[now].size(); ++i ){
		if( v[now][i].to == end ){
			result.push_back(check[now] + v[now][i].w);
		} else if( check[v[now][i].to] > check[now] + v[now][i].w ){
			check[v[now][i].to] = check[now] + v[now][i].w;
			q.push(v[now][i].to);
		}
	}
	q.pop();
	return 0;
}
int clear(){
	for( int i = 0; i < N; ++i ){
		v[i].clear();
		check[i] = INF;
	}
	return 0;
}
int main(){
	while( true ){
		scanf("%d %d",&N,&M);
		if( N == 0 && M == 0 ){
			break;
		}
		clear();
		scanf("%d %d",&start,&end);
		for( int i = 0; i < M; ++i ){
			int a,b,w;
			scanf("%d %d %d",&a,&b,&w);
			pair p = { b, w };
			v[a].push_back(p);
		}
		q.push(start);
		check[start] = 0;
		while( q.size() > 0 ){
			bfs();
		}
		std::sort(result.begin(),result.end());
		if( result.size() <= 1 ){
			printf("-1\n");
			continue;
		}
		int flag = -1;
		for( int i = 1; i < result.size(); ++i ){
			if( result[i] != result[i-1] ){
				flag = result[i];
				break;
			}
		}
		printf("%d\n",flag);
	}
	return 0;
}

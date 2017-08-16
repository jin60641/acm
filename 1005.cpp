#include<stdio.h>
#include<vector>
int max( int a, int b ){
	return a>b?a:b;
}
std::vector<int> v[1001];
int d[1001];
int check[1001];

int find( int now, int weight ){
	if( v[now].empty() ){
		return weight;
	} else if( check[now] == 0 ){
		int ret = 0;
		for( int i = 0; i < v[now].size(); ++i ){
			ret = max ( ret, find( v[now][i], weight + d[v[now][i]] ) );
		}
		check[now] = ret;
	}
	return check[now];
}

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int N, K;
		scanf("%d %d",&N,&K);
		for( int i = 1; i <= N; ++i ){
			check[i] = 0;
		}
		for( int i = 1; i <= N; ++i ){
			scanf("%d",&d[i]);
		}
		for( int i = 0; i < K; ++i ){
			int a, b;
			scanf("%d %d",&a,&b);
			v[b].push_back(a);
		}
		int W;
		scanf("%d",&W);
		printf("%d\n",find(W,d[W]));
		for( int i = 1; i <= N; ++i ){
			v[i].clear();
		}
	}
	return 0;
}

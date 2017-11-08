#include<stdio.h>
#include<vector>
#include<algorithm>

struct edge {
	int left,right,weight;
};
int g[1001][1001];
std::vector<edge> E;
int cmp( edge a, edge b ){
	return a.weight < b.weight;
}
int check[1001];
int find( int a ){
	if( check[a] == a ){
		return a;
	}
	check[a] = find( check[a] );
	return check[a];
}
int Union( int a, int b ){
	if( find(a) == find(b) ){
		return 0;
	}
	check[find(a)] = check[find(b)];
	return 1;
}

int main(){
	int N,M;
	scanf("%d",&N);
	scanf("%d",&M);
	for( int i = 1; i <= N; ++i ){
		check[i] = i;
	}
	for( int i = 0; i < M; ++i ){
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c );
		g[a][b] = c;
		g[b][a] = c;
		edge e = { a,b,c };
		E.push_back(e);
	}
	std::sort(E.begin(),E.end(),cmp);
	int cnt = 0;
	long long int tot = 0;
	for( int i = 0; i < E.size(); ++i ){
		int a = E[i].left;
		int b = E[i].right;
		int weight = E[i].weight;
		if( Union(a,b) == 1 ){
			tot += weight;
			if( ++cnt == N-1 ){
				break;
			}
		}
	}
	printf("%lld\n",tot);
	return 0;
}

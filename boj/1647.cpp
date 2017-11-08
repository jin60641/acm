#include<stdio.h>
#include<vector>
#include<algorithm>

struct edge {
	int from,to,w;	
};
int cmp( edge a, edge b ){
	return a.w < b.w;
}

int N, M, size[100001], root[100001];
int find(int a){
	if( root[a] == a ){
		return a;
	}
	root[a] = find(root[a]);
	return root[a];
}
int Union(int a, int b){
	int ra = find(a);
	int rb = find(b);
	if( ra == rb || size[ra] + size[rb] == N ){
		return 0;
	}
	size[rb] += size[ra];
	root[ra] = rb;
	return 1;
}
int main(){
	scanf("%d %d",&N,&M);
	for( int i = 1; i <= N; ++i ){
		size[i] = 1;
		root[i] = i;
	}
	std::vector<edge> v(M);
	for( int i = 0; i < M; ++i ){
		scanf("%d %d %d",&v[i].from,&v[i].to,&v[i].w);
	}
	std::sort(v.begin(),v.end(),cmp);
	int result = 0;
	for( int i = 0; i < v.size(); ++i ){
		if( Union(v[i].from,v[i].to) ){
			result += v[i].w;
		}
	}
	printf("%d\n",result);
	return 0;
}

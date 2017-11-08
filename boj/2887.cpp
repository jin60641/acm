#include<stdio.h>
#include<vector>
#include<algorithm>
const int X = 0;
const int Y = 1;
const int Z = 2;
int check[100001];
struct planet {
	int x,y,z;
};
struct pair {
	int number, value;
};
struct edge {
	int l,r,w;
};
std::vector<planet> v;
std::vector<edge> edges;
std::vector<pair> pos[3];
int abs( int a ){
	return a>0?a:-a;
}
int cmp_edge( edge a, edge b ){
	return a.w<b.w;
}
int cmp_pair( pair a, pair b ){
	return a.value<b.value;
}
int find( int a ){
	if( check[a] == a ){
		return a;
	}
	int ra = find(check[a]);
	check[a] = ra;
	return ra;
}
int Union( int a, int b ){
	int ra = find(a);
	int rb = find(b);
	if( ra == rb ){
		return 0;
	}
	check[ra] = rb;
	return 1;
}
int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		check[i] = i;
		int tmp[3];
		for( int j = X; j <= Z; ++j ){
			scanf("%d",&tmp[j]);
		}
		planet e = { tmp[0], tmp[1], tmp[2] };
		v.push_back(e);
		for( int j = X; j <= Z; ++j ){
			pair p = { i, tmp[j] };
			pos[j].push_back(p);
		}
	}
	for( int i = X; i <= Z; ++i ){
		std::sort(pos[i].begin(),pos[i].end(),cmp_pair);
	}

	for( int i = X; i <= Z; ++i ){
		for( int j = 1; j < N; ++j ){
			edge e = { pos[i][j-1].number, pos[i][j].number, abs(pos[i][j-1].value-pos[i][j].value) };
			edges.push_back(e);
		}
	}
	std::sort(edges.begin(),edges.end(),cmp_edge);
	long long int result = 0;
	for( int i = 0; i < edges.size(); ++i ){
		if( Union( edges[i].l, edges[i].r ) == 1 ){
			result += (long long int)edges[i].w;
		}
	}
	printf("%lld\n",result);
	return 0;
}



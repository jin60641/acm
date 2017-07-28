#include<stdio.h>
#include<vector>
#include<algorithm>

struct edge {
	int left,right,weight;
};

std::vector<edge> v;

int cmp( edge a, edge b ){
	return a.weight < b.weight;
}

int check[10001];

int find( long long int a ){
	if( check[a] == a ){
		return a;
	}
	check[a] = find( check[a] );
	return check[a];
}

int Union( int a, long long int b ){
	if( find(a) == find(b) ){
		return 0;
	}
	check[find(a)] = find(b);
	return 1;
}

int main(){
	int V,E;
	scanf("%d",&V);
	scanf("%d",&E);
	for( int i = 1; i <= V; ++i ){
		check[i] = i;
	}
	for( int i = 0; i < E; ++i ){
		int a,b,c;
		scanf("%d %d %d", &a, &b, &c );
		edge e = { a,b,c };
		v.push_back(e);
	}
	std::sort(v.begin(),v.end(),cmp);
	int cnt = 0;
	long long int tot = 0;
	for( int i = 0; i < v.size(); ++i ){
		int a = v[i].left;
		int b = v[i].right;
		int weight = v[i].weight;
		if( Union(a,b) == 1 ){
			tot += weight;
			if( ++cnt == V-1 ){
				break;
			}
		}
	}
	printf("%lld\n",tot);
	return 0;
}

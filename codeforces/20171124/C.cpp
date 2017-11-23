#include<stdio.h>
#include<vector>
int gold[100001];
int root[100001];
int check[100001];
int find( int a ){
	if( root[a] == a ){
		return a;
	}
	root[a] = find(root[a]);
	return root[a];
}

int Union( int a, int b ){
	int ra = find(a), rb = find(b);
	if( ra == rb ){
		return 0;
	}
	if( gold[ra] < gold[rb] ){
		root[rb] = ra;
	} else {
		root[ra] = rb;
	}
	find(a); find(b);
	return 0;
}

int main(){
	int n, m;
	long long int sum = 0;
	scanf("%d %d",&n,&m);
	for( int i = 1; i <= n; ++i ){
		root[i] = i;
		check[i] = 0;
		scanf("%d",&gold[i]);
	}
	for( int i = 1; i <= m; ++i ){
		int a, b;
		scanf("%d %d",&a,&b);
		Union(a,b);
	}
	for( int i = 1; i <= n; ++i ){
		find(i);
	}
	for( int i = 1; i <= n; ++i ){
		if( check[root[i]] == 0 ){
			sum += (long long int)gold[root[i]];
			check[root[i]] = 1;
		}
	}
	printf("%lld\n",sum);
	
	return 0;
}

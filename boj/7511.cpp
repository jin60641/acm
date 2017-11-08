#include<stdio.h>
#include<queue>
int n,k,m;
int check[1000000];
int clear(){
	for( int i = 0; i < n; ++i ){
		check[i] = i;
	}
}
int find(int a){
	if( check[a] == a ){
		return a;
	}
	check[a] = find(check[a]);
	return check[a];
}
int Union(int a, int b){
	if( find(a) == find(b) ){
		return 1;
	}
	check[find(a)] = find(b);
	return 0;
}
int main(){
	int T;
	scanf("%d",&T);
	int t = 0;
	while( ++t <= T ){
		std::queue<int> q;
		scanf("%d",&n);
		scanf("%d",&k);
		clear();
		for( int i = 0; i < k; ++i ){
			int a,b;
			scanf("%d %d",&a,&b);
			Union(a,b);
		}
		scanf("%d",&m);
		for( int i = 0; i < m; ++i ){
			int a,b;
			scanf("%d %d",&a,&b);
			q.push((find(a)==find(b))?1:0);
		}
		printf("Scenario %d:\n",t);
		while( q.size() > 0 ){
			printf("%d\n",q.front() );
			q.pop();
		}
		printf("\n");
	}
}

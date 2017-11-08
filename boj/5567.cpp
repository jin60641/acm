#include<stdio.h>
#include<vector>
#include<queue>

std::vector<int> v[501];
int check[501];
std::queue<int> q;

int main(){
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for( int i = 0; i < m; ++i ){
		int a, b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	check[1] = 1;
	for( int i = 0; i < v[1].size(); ++i ){
		check[v[1][i]] = 1;
		q.push(v[1][i]);
	}
	while( q.size() > 0 ){
		int f = q.front();
		for( int i = 0; i < v[f].size(); ++i ){
			check[v[f][i]] = 1;
		}
		q.pop();
	}
	int cnt = -1;
	for( int i = 1; i <= n; ++i ){
		cnt += check[i];
	}
	printf("%d\n",cnt);
	return 0;
}

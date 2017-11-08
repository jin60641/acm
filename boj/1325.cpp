#include<stdio.h>
#include<vector>
#include<algorithm>

struct pair {
	int num,cnt;
};

std::vector<pair> weight;
std::vector<int> v[10001];

int check[10001];
int tmp = 0;

int max( int a, int b ){
	return a>b?a:b;
}

int find( int now ){
	if( check[now] == tmp ){
		return 0;
	}
	check[now] = tmp;
	if( v[now].size() == 0 ){
		return 1;
	}
	int ret = 1;
	for( int i = 0; i < v[now].size(); ++i ){
		ret += find( v[now][i] );
	}
	return ret;
}

int cmp( pair a, pair b ){
	if( a.cnt == b.cnt ){
		return a.num < b.num;
	} else {
		return a.cnt > b.cnt;
	}
}

int main(){
	int N, M;
	scanf("%d %d",&N,&M);
	for( int i = 0; i < M; ++i ){
		int a, b;
		scanf("%d %d",&a,&b);
		v[b].push_back(a);
	}
	for( int i = 1; i <= N; ++i ){
		tmp = i;
		pair p = { i, find(i) };
		weight.push_back( p );
	}
	std::sort(weight.begin(),weight.end(),cmp);
	int max = weight[0].cnt;
	for( int i = 0; i < weight.size(); ++i ){
		if( max == weight[i].cnt ){
			printf("%d ",weight[i].num);
		} else {
			break;
		}
	}
	printf("\n");
	return 0;
}

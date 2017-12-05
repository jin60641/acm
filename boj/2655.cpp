#include<stdio.h>
#include<algorithm>
#include<vector>
struct block {
	int index, area, height, weight;
};
bool cmp( block a, block b ){
	return a.area>b.area;
};
struct pair {
	int height, last;
};
int main(){
	int N;
	scanf("%d",&N);
	block a[100];
	pair dp[100];
	for( int i = 0; i < N; ++i ){
		scanf("%d %d %d",&a[i].area,&a[i].height,&a[i].weight);
		a[i].index = i+1;
	}
	std::sort(a,a+N,cmp);
	for( int i = 0; i < N; ++i ){
		pair p = { a[i].height, i };
		dp[i] = p;
	}
	for( int i = 1; i < N; ++i ){
		for( int j = 0; j < i; ++j ){
			if( a[i].weight < a[j].weight && dp[i].height < dp[j].height+a[i].height ){
				dp[i].height = dp[j].height+a[i].height;
				dp[i].last = j;
			}
		}
	}
	int max = 0;
	int index;
	for( int i = 0; i < N; ++i ){
		if( max < dp[i].height ){
			max = dp[i].height;
			index = i;
		}
	}
	std::vector<int> result;
	while( index != dp[index].last ){
		result.push_back(a[index].index);
		index = dp[index].last;
	}
	result.push_back(a[index].index);
	printf("%d\n",result.size());
	for( int i = 0; i < result.size(); ++i ){
		printf("%d\n",result[i]);
	}
	return 0;
}

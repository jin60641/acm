#include<stdio.h>
#include<queue>
int m,n;
int a[2][50001];
int cnt[2][50001];

struct pair {
	int type;
	int num;
};

std::queue<pair> q;

int f(){
	pair now = q.front();
	if( ++cnt[!now.type][a[now.type][now.num]] == 1 && --cnt[now.type][a[!now.type][a[now.type][now.num]]] == 0 ){
		pair p = { now.type, a[!now.type][a[now.type][now.num]] };
		q.push(p);
	}
	q.pop();
	return 0;
}

int main(){
	scanf("%d %d",&m,&n);
	for( int i = 1; i <= m; ++i ){
		scanf("%d",&a[0][i]);
		++cnt[1][a[0][i]];
	}
	for( int i = 1; i <= n; ++i ){
		scanf("%d",&a[1][i]);
		if( cnt[1][i] == 0 ){
			pair p = { 1, i };
			q.push(p);
		}
	}
	while( q.size() > 0 ){
		f();
	}
	for( int i = 1; i<= m; ++i ){
		printf("%d",cnt[0][i]>0?0:1);
	}
	printf("\n");
	for( int i = 1; i<= n; ++i ){
		printf("%d",cnt[1][i]>0?0:1);
	}
	printf("\n");
	return 0;
}

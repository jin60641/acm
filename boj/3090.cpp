#include<stdio.h>
#include<vector>
#include<queue>
struct pair {
	int num, m;
};
struct cmp {
	bool operator()( pair a, pair b ){
		return a.m < b.m;
	}
};
std::priority_queue< pair,std::vector<pair>, cmp > pq;
int main(){
	int N,T;
	scanf("%d %d",&N,&T);
	int arr[100000];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&arr[i]);
	}
	pair first = { 0, arr[0]-arr[1] };
	pair last = { N-1, arr[N-1]-arr[N-2] };
	pq.push(first);
	pq.push(last);
	for( int i = 1; i < N-1; ++i ){
		pair p = { i, arr[i]-arr[i-1] + arr[i] - arr[i+1] };
		pq.push(p);
	}
	for( int i = 0; i < T; ++i ){
		pair t = pq.top();
		pq.pop();
		--arr[t.num];
		pair n;
		n.num = t.num;
		if( t.num == 0 ){
			n.m = arr[0]-arr[1];
		} else if( t.num == N-1 ){
			n.m = arr[N-1]-arr[N-2];
		} else {
			n.m = arr[t.num]-arr[t.num-1] + arr[t.num]-arr[t.num+1];
		}
		pq.push(n);
	}
	for( int i = 0; i < N; ++i ){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

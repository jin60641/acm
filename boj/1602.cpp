#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_N 500
#define MAX_D 10000
#define MAX_T 10000
#define INF MAX_N * MAX_D + MAX_T
struct pair {
	int to, d;
};
struct trio {
	int num, sum, max;
	bool operator<(const trio&io) const {
		return sum > io.sum;
	}
};
std::priority_queue<trio> q;
std::vector<pair> v[MAX_N + 1];
int dog[MAX_N + 1];
int sorted[MAX_N + 1];
int result[MAX_N+1][MAX_N+1];

int N, M, Q;
int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
int f(int start) {
	trio now = q.top();
	q.pop();
	for (int i = 0; i < v[now.num].size(); ++i) {
		pair p = v[now.num][i];
		trio next;
		next.num = p.to;
		next.sum = now.sum + p.d;
		next.max = now.max;
		if( dog[next.num] > now.max ){
			break;
		}
		if( next.sum + next.max < result[start][next.num] ){
			result[start][next.num] = next.max + next.sum;
			q.push(next);
		}
	}
	return 0;
}
bool cmp(pair a,pair b){
	return dog[a.to] < dog[b.to];
}

int main() {
	scanf("%d %d %d", &N, &M, &Q);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &dog[i]);
		sorted[i] = dog[i];
	}
	std::sort(sorted+1,sorted+N+1);
	for( int i = 1; i <= N; ++i ){
		for( int j = 1; j <= N; ++j ){
			result[i][j] = INF;
		}
	}
	for (int i = 1; i <= M; ++i) {
		int a, b, d;
		scanf("%d %d %d", &a, &b, &d);
		pair p1;
		p1.to = b;
		p1.d = d;
		v[a].push_back(p1);
		pair p2;
		p2.to = a;
		p2.d = d;
		v[b].push_back(p2);
	}
	for( int i = 1; i <= N; ++i ){
		std::sort(v[i].begin(),v[i].end(),cmp);
	}
	for( int i = 1; i <= N; ++i ){
		for( int j = N; j >= 1; --j ){
			if( sorted[j] < dog[i] ){
				continue;
			}
			trio t;
			t.num = i;
			t.max = sorted[j];
			t.sum = 0;
			q.push(t);
			while (!q.empty()) {
				f(i);
			}
		}
	}
	for (int i = 1; i <= Q; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", (result[a][b]==INF)?-1:result[a][b]);
	}
}


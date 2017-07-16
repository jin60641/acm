#include<stdio.h>
#include<queue>
int alphabet = 52;
int end = 26;
int weight[52][52];
int check[52];
std::queue<int> q;
int path[52];

int reduce(int min){
	int now = end-1;
	while(now > 0){
		weight[path[now]][now] -= min;
		weight[now][path[now]] += min;
		now = path[now];
	}
	return 0;
}

int clear(){
	for( int i = 0; i < alphabet; ++i ){
		path[i] = 0;
		check[i] = 0;
	}
	while( q.size() > 0 ){
		q.pop();
	}
	return 0;
}

int bfs(){
	int now = q.front();
	int min = check[now];
	int flag = 0;
	for( int i = 0; i < alphabet; ++i ){
		int w = weight[q.front()][i];
		if( w >= 1  ){
			int tmp;
			if( now == 0 || min == 0 || w < min ){
				tmp = w;
			} else {
				tmp = min;
			}
			if( check[i] < tmp ){
				q.push(i);
				path[i] = now;
				check[i] = tmp;
				if( i == end-1 ){
					reduce(check[i]);
					break;
				}
			}
		}
	}
	q.pop();
	return 0;
}

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		char a,b;
		int c;
		scanf(" %c %c %d",&a,&b,&c);
		if( a < 97 ){
			a -= 65;
		} else {
			a -= 71;
		}
		if( b < 97 ){
			b -= 65;
		} else {
			b -= 71;
		}
		weight[a][b]=c;
	}
	int sum = 0;
	while( true ){
		check[0] = 1000000;
		q.push(0);
		while( q.size() > 0 && q.front() < alphabet && check[end-1] == 0 ){
			bfs();
		}
		if( check[end-1] == 0 ){
			break;
		}
		sum += check[end-1];
		clear();
	}
	printf("%d\n",sum);
	return 0;
}


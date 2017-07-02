#include<stdio.h>

int alphabet = 52;
int end = 26;
int weight[52][52];
int check[52];
int q[52];
int index = 1;
int path[52];
int N;

int reduce(int min){
	int now = end-1;
	while(now > 0){
		weight[path[now]][now] -= min;
		now = path[now];
	}
	return 0;
}

int clear(){
	for( int i = 0; i < alphabet; ++i ){
		path[i] = 0;
		check[i] = 0;
		q[i] = 0;
	}
	q[0] = 0;
	index = 1;
	return 0;
}

int push(int num){
	q[index++] = num;
	return 0;
}

int bfs(int now){
	int min = check[q[now]];
	for( int i = 0; i < alphabet; ++i ){
		int w = weight[q[now]][i];
		if( w >= 1 && check[i] == 0 ){
			path[i] = q[now];
			push(i);
			if( min == 0 || w < min ){
				check[i] = w;
			} else {
				check[i] = min;
			}
			if( i == end-1 ){
				reduce(check[i]);
				return check[i];
			}
		}
	}
	int result = 0;
	if( now < alphabet && q[now+1] != 0 ){
		result = bfs(now+1);
	}
	return result;
}

int main(){
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
		int result = bfs(0);
		sum += result;
		if( result == 0 ){
			break;
		}
		clear();
	}
	printf("%d\n",sum);
}


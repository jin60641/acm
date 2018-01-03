#include<stdio.h>
#include<queue>
std::queue<int> q;
int N,K,check[361],degree[10];;
void f(){
	int now = q.front();
	q.pop();
	for( int i = 0; i < N; ++i ){
		int up = (now+degree[i])%360;
		int down = now-degree[i]<0?(-now+degree[i])%360:now-degree[i];
		if( !check[up] ){
			check[up] = 1;
			q.push(up);
		}
		if( !check[down] ){
			check[down] = 1;
			q.push(down);
		}
	}
}
int main(){
	scanf("%d %d",&N,&K);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&degree[i]);
	}
	check[0] = 1;
	q.push(0);
	while( !q.empty() ){
		f();
	}
	while( K-- ){
		int k, flag = false;
		scanf("%d",&k);
		for( int i = 1; i <= 360; ++i ){
			if( check[i] == 1 && k%i == 0 ){
				flag = true;
				break;
			}
		}
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}

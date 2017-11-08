#include<stdio.h>
#include<queue>

std::queue<int> q;

int check[10001];
int main(){
	int start,end;
	scanf("%d %d",&start,&end);
	for( int i = 2; i <= end; ++i ){
		if( check[i] == 1 ){
			continue;
		}
		q.push(i);
		for( int j = i*2; j <= end; j += i ){
			check[j] = 1;
		}
	}
	int sum = 0;
	int flag = 0;
	while( q.size() > 0 ){
		int a = q.front();
		if( flag == 0 && a >= start ){
			flag = a;
		}
		if( flag > 0 ){
			sum += a;
		}
		q.pop();
	}
	if( sum == 0 ){
		printf("-1\n");
	} else {
		printf("%d\n%d\n",sum,flag);
	}
	return 0;
}

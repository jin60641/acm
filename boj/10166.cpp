#include<stdio.h>
#include<queue>

std::queue<int> q;

int check[3000];
int main(){
	int start,end;
	scanf("%d %d",&start,&end);
	for( int i = 2; i <= end; ++i ){
		if( check[i] == 1 ){
			continue;
		}
		q.push(i);
		for( int j = i*2; j <= end; j+=i ){
			check[j] = 1;
		}
	}
	while( q.size() > 0 ){
		printf("%d ",q.front());
		q.pop();
	}	
	
	printf("\n");
}

#include<stdio.h>

int arr[1200000];

int main(){
	int N;
	scanf("%d",&N);
	int cnt = N;
	for( int i = 0; i < N; ++i ){
		arr[i] = i+1;
	}
	int front = 0;
	int back = N-1;
	if( cnt == 1 ){
		printf("1\n");
		return 0;
	}
	while( cnt-- > 1 ){
		arr[front++] = 0;
		arr[++back] = arr[front++];
		arr[front] = 0;
	}
	printf("%d\n",arr[back-1]);
	return 0;
}

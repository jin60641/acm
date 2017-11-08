#include<stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	int arr[25] = {};
	arr[0] = 0;
	arr[1] = 1;
	if( N == 0 ){
		printf("0\n");
		return 0;
	} else if( N == 1 ){
		printf("1\n");
		return 0;
	}
	for( int i = 2 ; i <= N; ++i ){
		arr[i] = arr[i-1] + arr[i-2];
	}
	printf("%d\n",arr[N]);
	return 0;
}

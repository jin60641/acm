#include<stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	int arr[2000] = {0,};
	for( int i = 0; i < N; ++i ){
		arr[i] = i+1;
	}
	int index = N;
	for( int i = 0; i < N*2; ++i ){
		printf( "%d ", arr[i] );
		arr[i] = 0;
		arr[index] = arr[i+1];
		arr[i+1] = 0;
		index += 1;
		i+=1;
	}
	return 0;
}

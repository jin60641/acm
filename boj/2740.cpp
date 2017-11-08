#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int main(){
	int N,M,J,K;
	int A[101][101] = {};
	int B[101][101] = {};
	scanf("%d",&N);
	scanf("%d",&M);
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < M; ++j ){
			scanf("%d", &A[i][j] );
		}
	}
	scanf("%d",&J);
	scanf("%d",&K);
	for( int i = 0; i < J; ++i ){
		for( int j = 0; j < K; ++j ){
			scanf("%d", &B[i][j]);
		}
	}
	for( int i = 0; i < N; ++i ){
		for( int k = 0; k < K; ++k ){
			int sum = 0;
			for( int j = 0; j < M; ++j ){
				sum += A[i][j]*B[j][k];
			}
			printf("%d ", sum);
		}
		printf("\n");
	}
	return 0;
}

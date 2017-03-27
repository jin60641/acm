#include<stdio.h>
#include<algorithm>

int main(){
	int N;
	int A[100001];
	int M;
	int B[100001];
	int R[100001];
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&A[i]);
	}
	scanf("%d",&M);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&B[i]);
	}
	int cnt = 0;
	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < M; ++j ){
			if( A[i] == B[j] ){
				R[j] = 1;
				++cnt;
				break;
			}
		}
		if( cnt == M ){
			break;
		}
	}
	for( int i = 0; i < N; ++i ){
		if(R[i] == 1){
			printf("1\n");
		} else {
			printf("0\n");
		}
	}
	
	return 0;
}

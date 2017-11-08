#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int main(){
	int N,J,K;
	long long int B;
	int A[6][6] = {};
	int tmp[6][6] = {};
	int C[6][6] = {};
	int R[6][6] = {};

	int bin[40];
	scanf("%d %lld",&N,&B);

	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			scanf("%d", &A[i][j] );
			R[i][j] = A[i][j];
			C[i][j] = 0;
		}
		C[i][i] = 1;
	}

	int cnt = 0;
	while(B){
		bin[cnt++] = B%2;
		B/=2;
	}

	for( int l = 0; l < cnt; ++l ){
		if( bin[l] == 1 ){
			for( int i = 0; i < N; ++i ){
				for( int k = 0; k < N; ++k ){
					int sum = 0;
					for( int j = 0; j < N; ++j ){
						sum += C[i][j]*R[j][k];
					}
					tmp[i][k] = sum;
				}
			}
			for( int i = 0; i < N; ++i ){
				for( int j = 0; j < N; ++j ){
					C[i][j] = tmp[i][j]%1000;
				}
			}
		}
		
		for( int i = 0; i < N; ++i ){
			for( int k = 0; k < N; ++k ){
				int sum = 0;
				for( int j = 0; j < N; ++j ){
					sum += R[i][j]*R[j][k];
				}
				tmp[i][k] = sum;
			}
		}
		for( int i = 0; i < N; ++i ){
			for( int j = 0; j < N; ++j ){
				R[i][j] = tmp[i][j]%1000;
			}
		}
	}

	for( int i = 0; i < N; ++i ){
		for( int j = 0; j < N; ++j ){
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
	return 0;
}

#include<stdio.h>
int main(){
	int A[1010];
	int N;
	int K;
	scanf("%d %d",&N,&K);
	
	for( int i = 0; i < N; ++i ){
		A[i] = i+1;
	}
	for( int j = 1; j < N; ++j ){
		if(A[j] == 0){
			continue;
		}
		int min = j;
		int Amin = A[min];
		for( int i = min; i < N; i += Amin ){
			if( A[i] == 0 ){
				continue;
			}
			K--;
			if( K == 0 ){
				printf("%d\n",A[i]);
				return 0;
			} else {
				A[i] = 0;
			}
		}	
	}
	return 0;
}


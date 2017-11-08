#include<stdio.h>
#include<algorithm>

int compare(int a, int b){
	return a>b;
}

int main(){
	int N;
	int A[50];
	int B[50];
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		scanf("%d", &A[i]);
	}
	for( int i = 0; i < N; ++i ){
		scanf("%d", &B[i]);
	}
	std::sort(A,A+N);
	std::sort(B,B+N,compare);
	int tot = 0;
	for( int i = 0; i < N; ++i ){
		tot += A[i] * B[i];
	}
	printf("%d\n",tot);
}

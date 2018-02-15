#include<stdio.h>

int main(){
	int N, A, B, a = -1, b = -1, start = 0;
	scanf("%d %d %d",&N, &A, &B);
	for( int i = 0; A*i <= N; ++i ){
		if( !(i?(N-(A*i))%B:N%B) ){
			a = i;
			b = (N-A*i)/B;
			break;
		}
	}
	if( a == -1 ){
		printf("-1\n");
		return 0;
	}
	for( int i = 0; i < a; ++i ){
		for( int j = 2; j <= A; ++j ){
			printf("%d ",j+start);
		}
		printf("%d ",start+1);
		start += A;
	}
	for( int i = 0; i < b; ++i ){
		for( int j = 2; j <= B; ++j ){
			printf("%d ",j+start);
		}
		printf("%d ",start+1);
		start += B;
	}
	return 0;
}

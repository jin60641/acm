#include<stdio.h>


int main(){
	int N;
	int cnt = 0;	
	int A[1010];
	scanf("%d",&N);
	
	for( int i = 0; i < N; ++i ){
		scanf("%d",&A[i]);
	}
	for( int i = 0; i < N; ++i ){
		int a = 0;
		for( int j = 1; j <= A[i]; ++j ){
			if( A[i]%j == 0 ){
				a++;
			}
		}
		if( a == 2 ){
			cnt++;
		}
	}
	printf("%d\n",cnt);
}

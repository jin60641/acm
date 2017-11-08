#include<stdio.h>

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int a[1000];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
	}
	int max = 0;
	for( int i = 0; i < N-2; ++i ){
		for( int j = i+1; j < N-1; ++j ){
			for( int k = j+1; k < N; ++k ){
				int sum = a[i] + a[j] + a[k];
				if( sum > max && sum <= M ){
					max = sum;
				}
			}
		}
	}
	printf("%d\n",max);
	return 0;
}

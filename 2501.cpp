#include<stdio.h>

int main(){
	int N,K;
	scanf("%d %d",&N,&K);	
	int a[10000];
	int b[10000];
	int index = 0;
	int flag = 0;
	for( int i = 1; i*i <= N; ++i ){
		if( N%i == 0 ){
			if( i == N/i ){
				flag = 1;
			}
			a[index] = i;
			b[index] = N/i;
			++index;
		}
	}
	if( K <= index ){
		printf("%d\n",a[K-1]);
	} else if( index*2-K-flag < 0 ){
		printf("0\n");
	} else {
		printf("%d\n",b[index*2-K-flag]);
	}
	return 0;
}

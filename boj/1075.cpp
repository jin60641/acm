#include<stdio.h>

int main(){
	int N,F;
	scanf("%d %d",&N,&F);
	N = N/100*100;
	int i;
	for( i = N; i < N+100; ++i ){
		if( i%F == 0 ){
			break;
		}
	}
	i = i % 100;
	printf("%02d",i);
	return 0;
}

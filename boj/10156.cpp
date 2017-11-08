#include<stdio.h>

int main(){
	int K,N,M;
	scanf("%d %d %d",&K,&N,&M);
	int tmp = K*N-M;
	if( tmp > 0 ){
		printf("%d\n",tmp);
	} else {
		printf("0\n");
	}
	return 0;
}

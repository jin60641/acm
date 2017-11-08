#include<stdio.h>

int min(int a,int b){
	return a<b?a:b;
}

int main(){
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	while( K-- ){
		if( N%2 == 1 || ( N%2 == 0 && N/2 > M ) ){
			--N;
		} else {
			--M;
		}
	}
	printf("%d\n",min(N/2,M));
	return 0;
}

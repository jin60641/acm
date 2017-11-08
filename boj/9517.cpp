#include<stdio.h>

int main(){
	int K;
	int N;
	scanf("%d",&K);
	scanf("%d",&N);
	int now = 0;
	for( int i = 0; i < N; ++i ){
		int T;
		char Z;
		scanf("%d %c",&T,&Z);
		if( now + T >= 210 ){
			break;
		} else if( Z == 'T' ){
			K = (K+1)%8;
		}
		now += T;
	}
	printf("%d\n",K);
	return 0;
}

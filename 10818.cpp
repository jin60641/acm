#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	int max = -1000001;
	int min = 1000001;
	for( int i = 0; i < N; ++i ){
		int a;
		scanf("%d",&a);
		if( a > max ){
			max = a;
		}
		if( a < min ){
			min = a;
		}
	}
	printf("%d %d\n",min,max);
	return 0;
}

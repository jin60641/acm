#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int M,N;
		scanf("%d %d",&M,&N);
		int min = -1;
		int max = -1;
		for( int i = 0; i < N; ++i ){
			int a,b;
			scanf("%d",&a);
			b = M-a;
			if( a > b ){
				int tmp = a;
				a = b;
				b = tmp;
			}
			min = a>min?a:min;
			max = b>max?b:max;
		}
		printf("%d %d\n",min,max);
	}
	return 0;
}

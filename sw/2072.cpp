#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	for( int i = 0; i < n; ++i ){
		int sum = 0;
		for( int j = 0; j < 10; ++j ){
			int a;
			scanf("%d",&a);
			if( a % 2 == 1 ) {
				sum += a;
			}
		}
		printf("#%d %d\n",i+1,sum);
	}
	return 0;
}

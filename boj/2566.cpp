#include<stdio.h>

int main(){
	int x;
	int y;
	int max = 0;
	for( int i = 1; i <= 9; ++i ){
		for( int j = 1; j <= 9; ++j ){
			int a;
			scanf("%d",&a);
			if( a > max ){
				max = a;
				x = j;
				y = i;
			}
		}
	}
	printf("%d\n%d %d\n",max,y,x);
	return 0;
}

#include<stdio.h>

int main(){
	int X;
	scanf("%d",&X);
	int cnt = 0;
	while( X > 0 ){
		int r = X%2;
		if( r == 1 ){
			++cnt;
		}
		X /= 2;
	}
	printf("%d\n",cnt);
	return 0;
}

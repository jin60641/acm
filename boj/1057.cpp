#include<stdio.h>

int main(){
	int N,a,b;
	scanf("%d %d %d",&N,&a,&b);
	--a;
	--b;
	int m = 1;
	int r = 0;
	while( m <= N ){
		++r;
		m*=2;
		if( a/m == b/m ){
			break;
		}
	}
	printf("%d\n",r);
	return 0;
}

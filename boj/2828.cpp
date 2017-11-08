#include<stdio.h>

int main(){
	int N,M,J;
	int x = 1;
	scanf("%d %d",&N,&M);
	scanf("%d",&J);
	int tot = 0;
	for( int i = 0; i < J; ++i ){
		int apple;
		scanf("%d",&apple);
		if( x <= apple && apple <= x+(M-1) ){
			continue;
		} else if( apple < x ){
			tot += x-apple;
			x = apple;
		} else if( apple > x+(M-1) ){
			tot += apple - (x+(M-1));
			x = apple-(M-1);
		}
	}
	printf("%d\n",tot);
}

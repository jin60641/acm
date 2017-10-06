#include<stdio.h>

int main(){
	int R,B,LW;
	scanf("%d %d",&R,&B);
	LW = (R-4)/2;
	for( int W = 1; W <= LW-1; ++W ){
		int L = LW-W;
		if( L*W == B ){
			printf("%d %d\n",L+2,W+2);
			break;
		}
	}
	return 0;
}

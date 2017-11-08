#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x1,y1,r1,x2,y2,r2;
		scanf("%d %d %d %d %d %d", &x1,&y1,&r1, &x2,&y2,&r2 );
		int r = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
		int d = (r1-r2)>=0?(r1-r2)*(r1-r2):(r2-r1)*(r2-r1);
		if( x1 == x2 && y1 == y2 && r1 == r2 ){
			printf("-1\n");
		} else if( r < (r1+r2)*(r1+r2) && r > d ){
			printf("2\n");
		} else if( r == (r1+r2)*(r1+r2) || r == d ){
			printf("1\n");
		}  else if( r > (r1+r2)*(r1+r2) || r < d || ( r == 0 && r1 != r2 ) ){
			printf("0\n");
		}
	}
	return 0;
}

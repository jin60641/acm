#include<stdio.h>

int main(){
	int w,h,x,y,t;
	scanf("%d %d",&w,&h);
	scanf("%d %d",&x,&y);
	scanf("%d",&t);
	int xt = t%(w*2);
	int yt = t%(h*2);
	int dx = 1;
	int dy = 1;
	while( xt-- != 0 ){
		x += dx;
		dx = x==w?-1:(x==0?1:dx);
	}
	while( yt-- != 0 ){
		y += dy;
		dy = y==h?-1:(y==0?1:dy);
	}
	printf("%d %d\n",x,y);
	return 0;
}

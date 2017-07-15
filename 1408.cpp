#include<stdio.h>

int main(){
	int a;
	int b;
	int h,m,s;
	scanf("%d:%d:%d",&h,&m,&s);
	a = h*3600+m*60+s;
	scanf("%d:%d:%d",&h,&m,&s);
	b = h*3600+m*60+s;
	if( a > b ){
		a -= 24*3600;
	}
	h = (b-a)/3600;
	m = ((b-a)%3600)/60;
	s = (b-a)%60;
	printf("%02d:%02d:%02d\n",h,m,s);
	return 0;
}

#include<stdio.h>

int main(){
	int h,m,s;
	int add;
	scanf("%d %d %d",&h,&m,&s);
	scanf("%d",&add);
	s += add;
	m += s/60;
	s = s%60;
	h += m/60;
	m = m%60;
	h = h%24;
	printf("%d %d %d\n",h,m,s);
	return 0;
}

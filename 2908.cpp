#include<stdio.h>

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int tmp = a/100;
	int tmp2 = a%10;
	a -= tmp2;
	a -= tmp*100;
	a += tmp2*100;
	a += tmp;
	tmp = b/100;
	tmp2 = b%10;
	b -= tmp2;
	b -= tmp*100;
	b += tmp2*100;
	b += tmp;
	printf("%d\n",a>b?a:b);
	return 0;
}

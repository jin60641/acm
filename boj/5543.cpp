#include<stdio.h>

int min( int a, int b ){
	return a<b?a:b;
}

int main(){
	int a,b,c,d,e;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	scanf("%d",&e);
	int burger = min( min(a,b),c );
	int drink = min( d, e );
	printf("%d\n",burger+drink-50);
}

#include<stdio.h>

int main(){
	int A,B;
	scanf("%d %d",&A,&B);
	int a = B%10*A;
	int b = B/10%10*A;
	int c = B/100*A;
	int d = a+b*10+c*100+d;
	
	printf("%d\n%d\n%d\n%d\n",a,b,c,d);
	
	return 0;
}

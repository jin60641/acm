#include<stdio.h>

int main(){
	int A,B,C;
	scanf("%d %d",&A,&B);
	scanf("%d",&C);
	int tmp = (A*60 + B + C)%1440;

	printf("%d %d",tmp/60,tmp%60);

	return 0;
}

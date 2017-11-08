#include<stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	a = 1000-a;
	int cnt;
	cnt = a/500;
	a = a%500;
	cnt += a/100;
	a = a%100;
	cnt += a/50;
	a = a%50;
	cnt += a/10;
	a = a%10;
	cnt += a;
	printf("%d\n",cnt);
	return 0;
}

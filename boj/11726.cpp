#include<stdio.h>

int main(){
	int a = 1;
	int b = 1;
	int n;
	scanf("%d",&n);
	for( int i = 0; i < n; ++i ){
		int tmp = a;
		a = b;
		b = (tmp+b)%10007;
	}
	printf("%d",a);
}

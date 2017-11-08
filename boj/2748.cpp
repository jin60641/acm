#include<stdio.h>

int main(){
	long long int a = 0;
	long long int b = 1;
	int n;
	scanf("%d",&n);
	for( int i = 0; i < n; ++i ){
		long long int tmp = a;
		a = b;
		b = tmp+b;
	}
	printf("%lld",a);
}

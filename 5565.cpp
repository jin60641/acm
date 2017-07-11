#include<stdio.h>

int main(){
	int a;
	scanf("%d",&a);
	for( int i = 0; i < 9; ++i ){
		int b;
		scanf("%d",&b);
		a-=b;
	}
	printf("%d\n",a);
}

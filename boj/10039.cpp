#include<stdio.h>

int main(){
	int tot = 0;
	for( int i = 0; i < 5; ++i ){
		int a;
		scanf("%d",&a);
		tot += a>40?a:40;
	}
	printf("%d",tot/5);
}

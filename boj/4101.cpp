#include<stdio.h>

int main(){
	while( true ){
		int a,b;
		scanf("%d %d",&a,&b);
		if( a == 0 && b == 0 ){
			break;
		} else if( a > b ){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}

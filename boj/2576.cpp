#include<stdio.h>

int main(){
	int a[7];
	int tot = 0;
	int min = 1000;
	for( int i = 0; i < 7; ++i ){
		scanf("%d",&a[i]);
		if( a[i]%2 == 1 ){
			tot += a[i];
			if( a[i] < min ){
				min = a[i];
			}
		}
	}
	if( tot == 0 ){
		printf("-1\n");
	} else {
		printf("%d\n%d\n",tot,min);
	}
	
	return 0;
}

#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	if( N%4 == 0 ){
		printf("CY");
	} else if( N%4 == 1 ){
		printf("SK");
	} else if( N%4 == 2 ){
		printf("CY");
	}  else if( N%4 == 3 ){
		printf("SK");
	}
	return 0;
}

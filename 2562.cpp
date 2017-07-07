#include<stdio.h>

int main(){
	int n = 9;
	int a[9];
	int max = -10000;
	int max_index = 0;
	for( int i = 0; i < 9; ++i ){
		scanf("%d",&a[i]);
		if( a[i] > max ){
			max = a[i];
			max_index = i;
		}
	}
	printf("%d\n%d\n",max,max_index+1);
	
}

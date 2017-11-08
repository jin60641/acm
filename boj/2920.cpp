#include<stdio.h>

int main(){
	int a[8];
	int asc = 0, des = 0;
	for( int i = 0; i < 8; ++i ){
		scanf("%d",&a[i]);
		if( a[i] == i+1 ){
			++asc;
		} else if( a[i] == 8-i ){
			++des;
		}
	}
	if( asc == 8 ){
		printf("ascending\n");
	} else if( des == 8 ){
		printf("descending\n");
	} else {
		printf("mixed\n");
	}
	return 0;
}

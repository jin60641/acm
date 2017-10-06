#include<stdio.h>

int main(){
	double a[4],max;
	int cnt = 0;
	for( int i = 0; i < 4; ++i ){
		scanf("%lf",&a[i]);
	}
	max = a[0]/a[2] + a[1]/a[3];
	if( max < a[2]/a[3] + a[0]/a[1] ){
		max = a[2]/a[3] + a[0]/a[1];
		cnt = 1;
	}
	if( max < a[3]/a[1] + a[2]/a[0] ){
		max = a[3]/a[1] + a[2]/a[0];
		cnt = 2;
	}
	if( max < a[1]/a[0] + a[3]/a[2] ){
		cnt = 3;
	}
	printf("%d\n",cnt);
	return 0;
}

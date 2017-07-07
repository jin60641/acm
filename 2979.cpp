#include<stdio.h>

int cnt[101];
int pay[4];
int main(){
	int a[3][2];
	scanf("%d %d %d",&pay[1],&pay[2],&pay[3]);
	pay[2]*=2;
	pay[3]*=3;
	int max = 0;
	for( int i = 0; i < 3; ++i ){
		scanf("%d %d",&a[i][0],&a[i][1]);
		if( a[i][1] > max ){
			max = a[i][1];
		}
	}
	for( int i = 0; i < 3; ++i ){
		for( int j = a[i][0]; j < a[i][1]; ++j ){
			++cnt[j];
		}
	}
	int tot = 0;
	for( int i = 0; i <= max; ++i ){
		tot += pay[cnt[i]];
	}
	printf("%d\n",tot);
}

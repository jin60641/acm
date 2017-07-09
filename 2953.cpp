#include<stdio.h>

int main(){
	int tot[5] = {0,0,0,0,0};
	for( int i = 0; i < 5; ++i ){
		for( int j = 0; j < 4; ++j ){
			int a;
			scanf("%d",&a);
			tot[i] += a;
		}
	}
	int max = 0;
	int max_index;
	for( int i = 0; i < 5; ++i ){
		if( max < tot[i] ){
			max_index = i;
			max = tot[i];
		}
	}
	printf("%d %d\n",max_index+1,max);
}

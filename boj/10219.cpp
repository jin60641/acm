#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int h,w;
		char a[12][12];
		scanf("%d %d",&h,&w);
		for( int i = 0; i < h; ++i ){
			scanf("%s",a[i]);
		}
		for( int i = 0; i < h; ++i ){
			for( int j = w-1; j >= 0; --j ){
				printf("%c",a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int left, right;
		scanf("%d %d",&left,&right);
		int add = 0;
		while( left < right ){
			++add;
			left += add;
			right -= add;
		}
		if( left - right >= add ){
			printf("%d\n",add*2-1);
		} else {
			printf("%d\n",add*2);
		}
	}
	return 0;
}

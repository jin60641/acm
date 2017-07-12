#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int tot,num;
		scanf("%d",&tot);
		scanf("%d",&num);
		for( int i = 0; i < num; ++i ){
			int a,b;
			scanf("%d %d",&a,&b);
			tot += a*b;
		}
		printf("%d\n",tot);
	}
	return 0;
}

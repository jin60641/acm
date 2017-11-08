#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	int w = 2;
	while(N--){
		w = w*2-1;
	}
	printf("%d\n",w*w);
	return 0;
}

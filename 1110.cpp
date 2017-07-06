#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	int tmp = N;
	int cnt = 0;
	do{
		++cnt;
		N = (N/10 + N%10)%10+(N%10)*10;
	}while(tmp!=N);
	printf("%d\n",cnt);
	return 0;
}

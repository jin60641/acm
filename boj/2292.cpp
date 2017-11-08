#include<stdio.h>

int main (){
	int N;
	scanf("%d",&N);
	int cnt = 0;
	int num = 1;
	do {
		num += cnt++*6;
	} while(num < N);
	printf("%d\n",cnt);
	return 0;
}

#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	int sum[1001];
	int tot = 0;
	sum[0] = 0;
	for( int i = 1; i <= N; ++i ){
		tot += i*(i+1);
		sum[i] = sum[i-1] + i;
		tot += sum[i];
	}
	printf("%d\n",tot);
	return 0;
}

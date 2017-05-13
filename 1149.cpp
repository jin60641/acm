#include<stdio.h>

int N;
int arr[1001][3];
int result[1001][3];

int min(int a, int b){
	return a<b?a:b;
}

int main(){
	scanf("%d",&N);
	for( int i = 1; i <= N; ++i ){
		scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
	}
	for(int i = 1; i <= N; ++i ){
		int r = min(result[i-1][1]+arr[i][0],result[i-1][2]+arr[i][0]);
		int g = min(result[i-1][0]+arr[i][1],result[i-1][2]+arr[i][1]);
		int b = min(result[i-1][0]+arr[i][2],result[i-1][1]+arr[i][2]);
		result[i][0] = r;
		result[i][1] = g;
		result[i][2] = b;
	}
	printf("%d\n",min(min(result[N][0],result[N][1]),result[N][2]));
}

#include<stdio.h>

int arr[20];
int main(){
	int N;
	scanf("%d",&N);
	int num = 1;
	for( int i = 0; i < N; ++i ){
		int a;
		scanf("%d",&a);
		for( int j = a; j < N; ++j ){
			if( arr[j] == 0 ){
				arr[j] = num++;
				break;
			}
		}
	}
	for( int i = 0; i < N; ++i ){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

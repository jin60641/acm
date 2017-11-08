#include<stdio.h>

int check[10000];
int main(){
	int N;
	scanf("%d",&N);
	int a[20000];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
	}
	long long int min = 2100000000;
	int result = 10001;
	for( int i = 0; i < N; ++i ){
		if( check[a[i]] ){
			continue;
		}
		check[a[i]] = 1;
		long long int sum = 0;
		for( int j = 0; j < N; ++j ){
			if( a[j] == a[i] ){
				continue;
			}
			int tmp = a[i] - a[j];
			if( tmp < 0 ){
				tmp = -tmp;
			}
			sum += tmp;
		}
		if( min > sum ){
			min = sum;
			result = a[i];
		} else if( min == sum ){
			if( result > a[i] ){
				result = a[i];
			}
		}
	}
	printf("%d\n",result);
}

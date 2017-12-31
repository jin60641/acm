#include<stdio.h>
#include<algorithm>

int main(){
	int k;
	scanf("%d",&k);
	int result[10];
	int num = 10;
	int last = 0;
	char arrow[10];
	for( int i = 1; i <= k; ++i ){
		char c;
		scanf(" %c",&arrow[i]);
	}
	for( int i = 1; i <= k; ++i ){
		char c = arrow[i];
		if( c == '>' ){
			for( int j = i-1; j >= last; --j ){
				result[j] = --num;
			}
			last = i;
			if( i == k ){
				result[i] = --num;
			}
		} else if( i == k ){
			for( int j = i; j >= last; --j ){
				result[j] = --num;
			}
		}
	}
	for( int i = 0; i <= k; ++i ){
		printf("%d",result[i]);
	}
	printf("\n");

	num = k;
	last = k;
	for( int i = k-1; i >= 0; --i ){
		char c = arrow[i+1];
		if( c == '<' ){
			for( int j = i+1; j <= last; ++j ){
				result[j] = num--;
			}
			last = i;
			if( i == 0 ){
				result[0] = num--;
			}
		} else if( i == 0 ){
			for( int j = i; j <= last; ++j ){
				result[j] = num--;
			}
		}
	}
	for( int i = 0; i <= k; ++i ){
		printf("%d",result[i]);
	}
	printf("\n");

	return 0;
}

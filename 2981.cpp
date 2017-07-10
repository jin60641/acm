#include<stdio.h>
#include<algorithm>

int f(int a,int b){
	if( a < b ){
		int tmp = b;
		b = a;
		a = tmp;
	}
	printf("%d %d\n",a,b);
	while( b > 0 ){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int result[1000000];

int main(){
	int N;
	scanf("%d",&N);
	int a[1000];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
	}
	int index = 0;
	int flag = 0;
	while( flag == 0 ){
		int tmp = a[0];
		for( int i = 1; i < N; ++i ){
			tmp = f(tmp,a[i]);
		}
		//if( tmp > 1 ){
			result[index++] = tmp;
		//}
		for( int i = 0; i < N; ++i ){
			a[i] -= tmp;
			if( a[i] < 0 ){
				flag = 1;
				break;
			}
		}
	}
	std::sort(result,result+index);
	for( int i = 0; i < index; ++i ){
		printf("%d ",result[i]);
	}
	printf("\n");
	if( result[0] != 1 ){
		printf("%d ",result[0]);
	}
	for( int i = 1; i < index; ++i ){
		if( result[i] != result[i-1] && result[i] != 0 ){
			printf("%d ",result[i]);
		}
	}
}

#include<stdio.h>
#include<math.h>

int main(){
	int N;
	scanf("%d",&N);
	int tot = 0;
	int max = 0;
	for( int i = 0; i < N; ++i ){
		int a;
		scanf("%d",&a);
		tot += a;
		if( a > max ){
			max = a;
		}
	}
	double a = round((double)tot/(double)max*100/N*100)/100;
	
	round(a);
	printf("%.2f",a);
}

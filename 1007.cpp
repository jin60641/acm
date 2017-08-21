#include<stdio.h>
#include<vector>
#include<math.h>
struct pair {
	double x,y;
};
pair p[20];
int arr[20],T,N;
pair sum;
const double INF = 400000000;
double result;
double min( double a, double b ){
	return a<b?a:b;
}
int f( int cnt, int index ){
	if( index > N ){
		return 0;
	} else if( cnt == N/2 ){
		pair tmp = { -sum.x, -sum.y };
		for( int i = 0; i < cnt; ++i ){
			tmp.x += p[ arr[i] ].x*2;
			tmp.y += p[ arr[i] ].y*2;
		}
		result = min(result,sqrt(tmp.x*tmp.x+tmp.y*tmp.y));
	} else {
		for( int i = index; i < N; ++i ){
			arr[cnt] = i;
			f( cnt+1, i+1 );
		}
	}
}
int main(){
	scanf("%d",&T);
	while( T-- ){
		result = INF;
		sum.x = 0;
		sum.y = 0;
		scanf("%d",&N);
		for( int i = 0; i < N; ++i ){
			scanf("%lf %lf",&p[i].x,&p[i].y);
			sum.x += p[i].x;
			sum.y += p[i].y;
		}
		for( int i = 0; i < N; ++i ){
			arr[0] = i;
			f( 1, i+1 );
		}
		printf("%.6lf\n",result);
	}
}

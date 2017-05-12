#include<stdio.h>
int N,K,a[1000],result[1001];

int f( int cnt, int cost ){
	if( result[cnt] > cost ){
		return -1;
	} else {
		result[cnt] = cost;
	}
	int max = result[cnt];
	for( int i = 0; i < N-cnt; ++i ){
		int c = f( cnt + (i+1), cost + a[i] );
		if( c > max ){
			max = c;
		}
	}
	return max;
}

int main(){
    scanf("%d",&N);
    for( int i = 0; i < N; ++i ){
        scanf("%d",&a[i]);
    }
	int r = f(0,0);
	printf("%d\n",r);
}

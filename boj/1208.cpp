#include<stdio.h>
int arr[40], N, S;
long long int check1[4000001];
long long int check2[4000001];
int f( int now, int end, int sum ){
	if( now > end ){
		return 0;
	}
	int plus = sum + arr[now];
	if( end == (N-1)/2 ){
		++check1[plus<0?(-plus+2000000):plus];
	} else {
		++check2[plus<0?(-plus+2000000):plus];
	}
	f( now+1, end, plus );
	f( now+1, end, sum );
	return 0;
}
int main(){
	scanf("%d %d",&N,&S);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&arr[i]);
	}
	++check1[0];
	++check2[0];
	f(0,(N-1)/2,0);
	f((N-1)/2+1,N-1,0);
	long long int cnt = 0;
	for( int i = 0; i <= 4000000; ++i ){
		int a = i>2000000?-i+2000000:i;
		int b = S-a<0?-(S-a)+2000000:S-a;
		if( check1[i] || check2[b] ){
			cnt += check1[i] * check2[b];
		}
	}
	if( S == 0 ){
		--cnt;
	}
	printf("%lld\n",cnt);
	return 0;
}

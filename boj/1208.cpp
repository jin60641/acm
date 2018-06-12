#include<stdio.h>
int arr[40] = {0}, N = 0, S = 0;
int check1[8000001] = {0};
int check2[8000001] = {0};
int f( int now, int end, int sum ){
	if( now > end ){
		return 0;
	}
	int plus = sum + arr[now];
	if( end == (N-1)/2 ){
		++check1[plus<0?(-plus+4000000):plus];
	} else {
		++check2[plus<0?(-plus+4000000):plus];
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
	for( int i = 0; i <= 8000000; ++i ){
		int a = i>4000000?-i+4000000:i;
		int b = S-a<0?-(S-a)+4000000:S-a;
		if( check1[i] && check2[b] ){
			cnt += (long long int)check1[i] * (long long int)check2[b];
		}
	}
	if( S == 0 ){
		cnt -= 1;
	}
	printf("%lld\n",cnt);
	return 0;
}


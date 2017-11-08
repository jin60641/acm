#include<stdio.h>

const int max = 4000000;
int check[max+10];
int num[max+10];
int dp[max+10];
int cnt = 0;
long long int tot = 0;
int main(){
	int N;
	scanf("%d",&N);
	for( long long int i = 2; i <= N; ++i ){
		if( check[i] == 0 ){
			num[cnt++] = i;
		} else {
			continue;
		}
		for( long long int j = i*i; j <= N; j += i ){
			check[j] = 1;
		}
	}
	int result = 0;
	int left = 0;
	int right = 0;
	while( num[left] <= N && left < cnt && right < cnt ){
		int tmp = tot + num[right];
		if( tmp == N ){
			tot -= num[left++];
			++result;
		} else if( tmp > N ){
			tot -= num[left++];
		} else { // if ( tmp < N ){
			tot += num[right++];
		}
	}
	printf("%d\n",result);
}

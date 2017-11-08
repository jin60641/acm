#include<stdio.h>
int main(){
    long long int N;
    scanf("%lld",&N);
    long long int tot = 0;
    long long int num[10000];
    long long int left = 100001;
    long long int right = 0;
    for( long long int i = 0; i < N; ++i ){
        scanf("%lld",&num[i]);
        if( num[i] > right ){
            right = num[i];
        }
		if( num[i] < left ){
            left = num[i];
        }
        tot += num[i];
    }
    long long int mid;
    long long int M;
    scanf("%lld",&M);
    while( left <= right ){
        long long int sum = 0;
        mid = (left+right)/2;
        for( long long int i = 0; i < N; ++i ){
            if( num[i]-mid >= 0 ){
                sum += num[i]-mid;
            }
        }
		if( tot-sum < M ){
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    printf("%lld\n",left-1);
	return 0;
}


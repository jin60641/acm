#include<stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    long long int tot = 0;
    int num[10000];
    int left = 100001;
    int right = 0;
    for( int i = 0; i < N; ++i ){
        scanf("%d",&num[i]);
        if( num[i] > right ){
            right = num[i];
        }
		if( num[i] < left ){
            left = num[i];
        }
        tot += num[i];
    }
    int mid;
    int M;
    scanf("%d",&M);
	int max = 0;
    while( left <= right ){
        long long int sum = 0;
        mid = (left+right)/2;
        for( int i = 0; i < N; ++i ){
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
    printf("%d\n",left-1);
}


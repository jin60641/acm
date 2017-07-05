#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int N,M,mid,left,right;
	int A[1000001];
	int B[1000001];
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&A[i]);
	}
	sort(A,A+N);

	scanf("%d",&M);
	for( int i = 0; i < M; ++i ){
		scanf("%d",&B[i]);
	}

	for( int i = 0; i < M; ++i ){
		left = 0;
		right = N-1;
		while( left <= right ){
			mid = (left+right)/2;
			if( A[mid] > B[i] ){
				right = mid-1;
			} else if( A[mid] <= B[i] ){
				left = mid+1;
			}
		}
		int ltmp = left-1;
		right = ltmp;
		left = 0;
		while( left <= right ){
			mid = (left+right)/2;
			if( A[mid] >= B[i] ){
				right = mid-1;
			} else if( A[mid] < B[i] ){
				left = mid+1;
			}
		}
		printf("%d ",ltmp-right);
	}
	printf("\n");
	return 0;
}

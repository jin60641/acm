#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int N,M,mid,left,right;
	int A[100001];
	int B[100001];
	int R[100001];
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&A[i]);
	}
	sort(A,A+N);

	scanf("%d",&M);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&B[i]);
	}
	for( int i = 0; i < M; ++i ){
		left = 0;
		right = N-1;
		while(left<=right){
			mid = (left+right)/2;
			if( B[i] == A[mid] ){
				R[i] = 1;
				break;
			} else if( B[i] > A[mid] ){
				left = mid+1;
			} else if( B[i] < A[mid] ){
				right = mid-1;
			}
		}
	}
	for( int i = 0; i < M; ++i ){
		if(R[i] == 1){
			printf("1\n");
		} else {
			printf("0\n");
		}
	}
	return 0;
}

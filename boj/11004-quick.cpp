#include<stdio.h>
#include<stdlib.h>
using namespace std;

int N, K;
int A[5000001];
int result = -1;

int swap(int, int);
int cut(int left,int pivot){
	if( left == pivot ){
		return -1;
	}
	int right = pivot-1;
	int i = left;
	int j = right;
	while( i <= j ){
		if( i == j ){
			if( A[i] > A[pivot] ){
				swap(i,pivot);
				if( K-1 <= i-1 ){
					cut(left,i-1);
				} else if( i+1 <= K-1 ){
					cut(i+1,pivot);
				} else {
					result = A[i];
				}
			} else {
				if( K-1 <= i ){
					cut(left,right);
				} else {
					return -1;
				}
			}
			return 0;
		} else {
			if( A[i] > A[pivot] ){
				if( A[j] < A[pivot] ){
					swap(i,j);
				} else {
					--j;
				}
			} else {
				++i;
			}
		}
	}
}


int swap(int left,int right){
	int tmp = A[left];
	A[left] = A[right];
	A[right] = tmp;
	return 0;
}

int main(){
	scanf("%d %d",&N,&K);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&A[i]);
	}
	cut(0,N-1);
	if( result >= 0 ){
		printf("%d",result);
	} else {
		printf("%d",A[K-1]);
	}
	return 0;
}


#include<stdio.h>
#include<algorithm>


int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int a[1000];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+N);
	int left = 0;
	int right = N-3;
	int sum = 0;
	while(left<=right){
		int mid = (left+right)/2;
		int tmp = a[mid] + a[mid+1] + a[mid+2];
		if( tmp > M ){
			right = mid-1;
		} else {
			sum = tmp;
			left = mid+1;
		}
	}
	printf("%d\n",sum);
	return 0;
}

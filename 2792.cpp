#include<stdio.h>

int max(int a, int b){
	return a>b?a:b;
}

int main(){
	int N, M, m[300001], left = 1, right = 0;
	scanf("%d %d",&N,&M);
	for( int i = 0; i < M; ++i ){
		scanf("%d",&m[i]);
		right = max(m[i],right);
	}
	while( left <= right ){
		int mid = (left+right)/2, cnt = 0;
		for( int i = 0; i < M; ++i ){
			cnt += (m[i]%mid==0)?m[i]/mid:m[i]/mid+1;
		}
		if( cnt > N ){
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	printf("%d\n",left);
	return 0;
}

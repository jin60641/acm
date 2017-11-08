#include<stdio.h>

int A[10000000];
int N, K;

int getMid(int start,int end){
	int mid;
	printf("%lld\n",mid);
	A[mid] = 1;
	if( --K == 0 ){
		return 0;
	}
	getMid(start,mid-1);
	getMid(mid+1,end);
}

int getEmpty(int s, int e){
	int cnt = 0;
	for( int i = s; i < e; ++i ){
		if( A[i] == 0 ){
			cnt++;
		}
	}
	return cnt;
}

int main(){
	int T;
//	freopen("C_input.txt","r",stdin);
//	freopen("C_output.txt","w",stdout);
	scanf("%d", &T);
	for( int i = 0; i < T; ++i ){
		scanf("%lld %lld",&N,&K);
		for( int j = 0; j < N; ++j ){
			A[j] = 0;
		}
		start = 0;
		getMid();
		int Ls = getEmpty(start,mid);
		int Rs = getEmpty(mid+1,N);
		if( Ls > Rs ){
			int tmp = Ls;
			Ls = Rs;
			Rs = Ls;
		}
		printf("Case #%d: %lld %lld\n",i+1,Rs,Ls);
	}
	
	return 0;
}


#include<stdio.h>
#include<algorithm>

int check[3000];

int main(){
	int N, L;
	scanf("%d %d",&N,&L);
	int cnt = 0;
	int a[1000];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+N);
	for( int i = 0; i < N; ++i ){
		if( check[a[i]] == 1 ){
			continue;
		}
		++cnt;
		for( int j = a[i]; j < a[i]+L; ++j ){
			check[j] = 1;
		}
	}
	printf("%d\n",cnt);
	return 0;
}

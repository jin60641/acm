#include<stdio.h>

int main(){
	int n,s,m;
	scanf("%d %d",&n,&s);
	scanf("%d",&m);
	int t[100000];
	int min = 1001;
	for( int i = 0; i < m; ++i ){
		scanf("%d",&t[i]);
		if( t[i] < min ){
			min = t[i];
		}
	}
	if( n-s <= m ){
		printf("%d\n",n-s);
		return 0;
	}

	int r = n-s-m;
	int left = 1;
	int right = min*r;
	while( left <= right ){
		int mid = (left+right)/2;
		int cnt = 0;
		for( int i = 0; i < m; ++i ){
			cnt += mid/t[i];
		}
		if( cnt < r ){
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	int cnt = m;
	for( int i = 0; i < m; ++i ){
		cnt += (left-1)/t[i];
	}
	for( int i = 0; i < m; ++i ){
		if( left%t[i] == 0 ){
			++cnt;
			if( cnt == r+m ){
				printf("%d\n",i+1);
			}
		}
	}
	return 0;
}

#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int N, P;
int need[1000];
int arr[1000][1000];

int start( int serve, int index ){
	if( index == N ){
		return 1;
	}
	for( int i = 0; i < P; ++i ){
		int total = serve*need[index];
		printf("%d %d\n",arr[index][i],total);
		if( arr[index][i] >= total * 0.9 && arr[index][i] <= total * 1.1 ){
			int result = start(serve,index+1);
			if( result == 1 ){
				arr[index][i] = -1;
			}
			return result;
		}
	}
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	for( int i = 0; i < T ; ++i ){
		scanf("%d %d",&N,&P);
		int cnt = 0;
		for( int j = 0; j < N; ++j ){
			scanf("%d",&need[j]);
		}
		for( int j = 0; j < N; ++j ){
			for( int k = 0; k < P; ++k ){
				scanf("%d",&arr[j][k]);
			}
			sort(arr[j],arr[j]+P);
		}
		for( int j = 0; j < P; ++j ){
			int serve = round( ((double)arr[0][j])/((double)need[0]) );
			int total = serve*need[0];
			if( arr[0][j] >= double(total) * 0.9 && arr[0][j] <= double(total) * 1.1 ){
				cnt += start(serve,1);
			} else {
				cnt += start(serve-1,1);
			}
		}
		printf("Case #%d: %d\n",i+1,cnt);
	}
	return 0;
}

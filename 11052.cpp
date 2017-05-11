#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int N;
	map<float, int> m;
	scanf("%d",&N);
	float P[1000];
	for( int i = 0; i < N; ++i ){
		float f;
		scanf("%f",&f);
		P[i] = f/(i+1);
		if( m[P[i]] > 0 ){
			continue;
		}
		m[P[i]] = i+1;
	}
	sort(P,P+N);
	int cnt = N;
	int total = 0;
	for( int i = N-1; i >= 0; --i ) {
		if( cnt >= m[P[i]] ){
			int n = cnt/m[P[i]];
			cnt -= m[P[i]]*n;
			total += P[i]*m[P[i]]*n;
		}
		if( cnt == 0 ){
			break;
		}
	}
	printf("%d\n",total);
	return 0;
}

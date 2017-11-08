#include<stdio.h>
#include<vector>
#include<algorithm>

bool max( double a, double b ){
	return a>b;
}

int main(){
	int N,M,K;
	double Max[101],sum = 0;
	for( int i = 1; i <= N; ++i ){
		Max[i] = -1;
	}
	scanf("%d %d %d",&N,&M,&K);
	std::vector<double> v;
	for( int i = 1; i <= M; ++i ){
		for( int j = 1; j <= N; ++j ){
			int n;
			double m;
			scanf("%d %lf",&n,&m);
			Max[n] = Max[n]>m?Max[n]:m;
		}
	}
	for( int i = 1; i <= N; ++i ){
		v.push_back(Max[i]);
	}
	std::sort(v.begin(),v.end(),max);
	for( int i = 0; i < K; ++i ){
		sum += v[i];
	}
	printf("%.1lf\n",sum);
	return 0;
}

#include<stdio.h>
#include<vector>
int f(int cnt, int from, int to){
	if( cnt <= 1 ){
		printf("%d %d\n",from,to);
		return 0;
	}
	f(cnt-1,from,6-from-to);
	printf("%d %d\n",from,to);
	f(cnt-1,6-from-to,to);
	return 0;
}
int main(){
	int N,tmp;
	scanf("%d",&N);
	std::vector<int> v;
	v.push_back(2);
	tmp = N;
	while( --tmp ){
		int len = v.size();
		for( int i = len-1; i >= 0 ; --i ){
			v[i] *= 2;
			if( v[i] >= 10 ){
				if( i+1 == len ){
					v.push_back(v[i]/10);
				} else {
					v[i+1] += v[i]/10;
				}
				v[i] = v[i]%10;
			}
		}
	}
	for( int i = 0; i < v.size(); ++i ){
		if( v[i] != 0 ){
			if( --v[i] == 0 && i == v.size()-1 ){
				v.pop_back();
			}
			break;
		}
		v[i] = 9;
	}
	for( int i = v.size()-1; i >= 0; --i ){
		printf("%d",v[i]);
	}
	printf("\n");
	if( N <= 20 ){
		f(N,1,3);
	}
	return 0;
}

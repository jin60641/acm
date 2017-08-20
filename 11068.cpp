#include<stdio.h>
#include<vector>

int main(){
	int N;
	scanf("%d",&N);
	while( N-- ){
		int a;
		scanf("%d",&a);
		int flag = 0;
		for( int i = 2; i <= 64; ++i ){
			int tmp = a;
			std::vector<int> v;
			while( tmp != 0 ){
				v.push_back(tmp%i);
				tmp/=i;
			}
			flag = 1;
			for( int j = 0; j < v.size()/2; ++j ){
				if( v[j] != v[v.size()-1-j] ){
					flag = 0;
					break;
				}
			}
			if( flag == 1 ){
				break;
			}
		}
		printf("%d\n",flag);
	}
	return 0;
}

#include<stdio.h>
#include<stack>
#include<vector>

int main(){
	int T;
	scanf("%d",&T);
	while( T-- ){
		int a, sum, multi = 1, flag = 1;
		scanf("%d",&a);
		sum = a;
		std::stack<int> s;
		while( a != 0 ){
			s.push(a%10);
			a/=10;
		}
		while( s.size() > 0 ){
			sum += s.top() * multi;
			multi*=10;
			s.pop();
		}
		std::vector<int> v;
		while( sum != 0 ){
			v.push_back(sum%10);
			sum/=10;
		}
		for( int i = 0; i < v.size()/2; ++i ){
			if( v[i] != v[v.size()-1-i] ){
				flag = 0;
				break;
			}
		}
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}

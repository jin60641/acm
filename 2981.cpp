#include<stdio.h>
#include<algorithm>
#include<stack>

int f(int a,int b){
	if( a < b ){
		int tmp = b;
		b = a;
		a = tmp;
	}
	while( b > 0 ){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int small[1000000];

int main(){
	int N;
	scanf("%d",&N);
	int a[1000];
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
	}
	int tmp = 0;
	for( int i = 1; i < N; ++i ){
		tmp = f(tmp,a[i]-a[i-1]);
	}
	int index = 0;
	std::stack<int> big;
	for( int i = 1; i*i <= tmp; ++i ){
		if( tmp%i == 0 ){
			small[index++] = i;
			big.push(tmp/i);
		}
	}
	for( int i = 1; i < index; ++i ){
		printf("%d ",small[i]);
	}
	--index;
	while( big.size() > 0 ){
		if( small[index] != big.top() ){
			printf("%d ",big.top() );
		}
		big.pop();
	}

	return 0;
}

#include<stdio.h>
#include<stack>
#include<queue>

int main(){
	std::queue<int> q;
	std::stack<int> s;
	std::queue<char> result;
	int n;
	scanf("%d",&n);
	for( int i = 0; i < n; ++i ){
		int a;
		scanf("%d",&a);
		q.push(a);
	}
	s.push(1);
	result.push('+');

	for( int i = 2; i <= n; ++i ){
		if( s.size() > 0 && q.size() > 0 && ( q.front() == s.top() ) ){
			result.push('-');
			q.pop();
			s.pop();
			--i;
		} else {
			result.push('+');
			s.push(i);
		}
	}

	while(s.size() > 0 ){
		if( s.top() == q.front() ){
			result.push('-');
			q.pop();
		}
		s.pop();
	}
	if( q.size() > 0 ){
		printf("NO\n");
	} else {
		while( result.size() > 0 ){
			printf("%c\n",result.front());
			result.pop();
		}
	}
	return 0;
}

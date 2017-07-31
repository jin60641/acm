#include<stdio.h>
#include<stack>
int check[1001];

int main(){
	std::stack<int> s;
	std::stack<int> d;
	int N;
	scanf("%d",&N);
	int tmp[1001];
	for( int i = 1; i <= N; ++i ){
		scanf("%d",&tmp[i]);
	}
	for( int i = N; i >= 1; --i ){
		d.push(tmp[i]);
	}
	int cnt = 0;
	while( ++cnt <= N ){
		if( check[cnt] == 1 ){
			if( s.top() == cnt ){
				check[s.top()] = 2;
				s.pop();
			} else {
				printf("Sad\n");
				return 0;
			}
		} else if( check[cnt] == 0 ){
			while( d.size() > 0 ){
				if( d.top() == cnt ){
					check[d.top()] = 2;
					d.pop();
					break;
				} else {
					check[d.top()] = 1;
					s.push(d.top());
					d.pop();
				}
			}
			if( check[cnt] != 2 ){
				printf("Sad\n");
				return 0;
			}
		}
	}
	printf("Nice\n");
	return 0;
}

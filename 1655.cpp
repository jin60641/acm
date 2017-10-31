#include<stdio.h>
#include<queue>
#include<vector>
std::priority_queue<int> pq;

struct cmp {
	bool operator()(int a, int b){
		return a > b;
	}
};
std::priority_queue<int,std::vector<int>,cmp> big;
std::priority_queue<int> small;


int N;
int main(){
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		int a;
		scanf("%d",&a);
		if( small.size() == 0 && big.size() == 0 ){
			small.push(a);
		} else if( small.size() != 0 && big.size() == 0 ){
			if( small.top() > a ){
				big.push( small.top() );
				small.pop();
				small.push(a);
			} else {
				big.push( a );
			}
		} else {
			if( a <= small.top() ){
				small.push(a);
			} else if( small.top() <= a && a <= big.top() ){
				small.push(a);
			} else if( big.top() <= a ){
				big.push(a);
			}
		}
		if( small.size() > big.size() &&  small.size() - big.size() >= 2 ){
			big.push( small.top() );
			small.pop();
		} else if( big.size() > small.size() && big.size() - small.size() >= 2 ){
			small.push( big.top() );
			big.pop();
		}
		if( big.size() == small.size() ){
			printf("%d\n",small.top());
		} else if( big.size() > small.size() ){
			printf("%d\n",big.top());
		} else if( small.size() > big.size() ){
			printf("%d\n",small.top());
		}
	}
	return 0;
}

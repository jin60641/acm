#include<stdio.h>
#include<list>


int main(){
	int N;
	scanf("%d",&N);
	int a[10];
	std::list<int> l;
	for( int i = 0; i < N; ++i ){
		scanf("%d",&a[i]);
	}
	for( int i = 0; i < N; ++i ){
		if( l.empty() || a[N-i-1] == l.size() ){
			l.push_back(N-i);
		} else if( a[N-i-1] == 0 ){
			l.push_front(N-i);
		} else {
			std::list<int>::iterator it = l.begin();
			for( int j = 0; j < a[N-i-1]; ++j ){
				++it;
			}
			l.insert(it,N-i);
		}
	}
	for( std::list<int>::iterator i = l.begin(); i != l.end(); ++i ){
		printf("%d ",*i);
	}
	printf("\n");
	return 0;
}

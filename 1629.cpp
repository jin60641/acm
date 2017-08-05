#include<stdio.h>
#include<queue>

int main(){
	long long int A,B,C;
	scanf("%lld %lld %lld",&A,&B,&C);
	std::queue<int> s;
	while(B!=0){
		s.push(B%2);
		B/=2;
	}
	long long int tot = 1;
	while( s.size() > 0 ){
		if( s.front() == 1 ){
			tot = (tot*(A))%C;
		}
		A = (A*A)%C;
		s.pop();
	}
	printf("%lld\n",tot%C);
	return 0;
}

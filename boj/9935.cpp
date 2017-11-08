#include<stdio.h>
#include<vector>
using namespace std;
vector< vector<int> > vs;
char s[1000010];
char b[40];
int length;
int size;

int bomb(){
	for( vector< vector<int> >::iterator i = vs.begin(); i != vs.end(); ++i ){
		for( vector<int>::iterator j = i->begin(); j != i->end(); ++j ){
			s[*j] = '\0';
		}
	}
	return 0;
}

int cmp(int start){
	int i = start;
	int correct = 0;
	vector<int> v;
	while( true ){
		if( s[i] == b[correct] ){
			v.push_back(i);
			++correct;
			++i;
		} else if( i != start && s[i] == b[0] ){
			int skip = cmp(i);
			if( skip > 0 ){
				i += skip;
				continue;
			} else {
				i -= skip;
				return -(i-start);
			}
		} else {
			return -(i-start);
		}
		if( correct == size ){
			vs.push_back(v);
			return i-start;
		}
	}
}

int print(){
	int flag = 0;
	for( int i = 0; i < length; ++i ){
		if( s[i] == '\0' ){
			continue;
		} else {
			flag = 1;
			printf("%c",s[i]);
		}
	}
	if( flag == 0 ){
		printf("FRULA");
	}
	printf("\n");
	return 0;
}

int search(){
	for( int i = 0; i < length; ++i ){
		int skip = cmp(i);
		if( s[i] == b[0] ){
			if( skip > 0 ){
				i += (skip-1);
			} else {
				i -= (skip+1);
			}
		}
	}
	return 0;
}

int main(){
	scanf("%s",s);
	scanf("%s",b);
	for( size = 0; b[size] != '\0'; ++size );
	for( length = 0; s[length] != '\0'; ++length );
	search();
	bomb();
	print();
	return 0;
}

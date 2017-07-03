#include<stdio.h>

char s[1000010];
char b[40];
int length;
int size;
int cmp(int start){
	int i = start;
	int correct = 0;
	while( true ){
		if( s[i] == '\0'){
			++i;
			continue;
		}
		if( s[i] == b[correct] ){
			++correct;
			++i;
		} else {
			return 0;
		}
		if( correct == size ){
			return 1;
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

int bomb(int start){
	int i = start;
	int cnt = 0;
	while( i < length ){
		if( s[i] == '\0'){
			++i;
			continue;
		}
		s[i] = '\0';
		++cnt;
		if( cnt == size ){
			return 1;
		}
	}
}

int search(int start,int end){
	int left = -1;
	int right = -1;
	for( int i = start; i < end; ++i ){
		if( s[i] == b[0] && cmp(i) ){
			if( left == -1 ){
				left = i - size - 1;
				if( left < 0 ){
					left = 0;
				}
			}
			right = i + size + 1;
			if( right >= length ){
				right = length - 1;
			}
			bomb(i);
			i += size;
		}
	}
	if( left != -1 ){
		//search(left,right);
		search(0,0);
	}
}

int main(){
	scanf("%s",s);
	scanf("%s",b);
	for( size = 0; b[size] != '\0'; ++size );
	for( length = 0; s[length] != '\0'; ++length );

	int flag = 0;
	search(0,length-1);
	print();
	return 0;
}

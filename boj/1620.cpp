#include<stdio.h>
#include<string.h>
#include<string>
#include<map>

std::map<std::string,int> stoi;
std::map<int,std::string> itos;

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for( int i = 1; i <= N; ++i ){
		char name[21];
		scanf("%s",name);
		std::string str = name;
		stoi[str] = i;
		itos[i] = str;
	}
	for( int i = 0; i < M; ++i ){
		char c[21];
		scanf("%s",c);
		if( '1' <= c[0] && c[0] <= '9' ){
			int tot = 0;
			int multi = 1;
			for( int j = strlen(c)-1; j >= 0; --j ){
				tot += (c[j]-'0')*multi;
				multi *= 10;
			}
			printf("%s\n",itos[tot].c_str());
		} else {
			std::string str = c;
			printf("%d\n",stoi[c]);
		}
	}
	return 0;
}

#include<stdio.h>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>

std::vector<std::string> v[50];
std::map<std::string,int> m;

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		char tmp[51];
		scanf("%s",tmp);
		std::string s = tmp;
		if( m[s] == 1 ){
			continue;
		}
		int len = strlen(tmp);
		m[s] = 1;
		s[len] = '\0';
		v[len-1].push_back(s);
	}
	for( int i = 0; i < 50; ++i ){
		std::sort(v[i].begin(),v[i].end());
		for( int j = 0; j < v[i].size(); ++j ){
			printf("%s\n",v[i][j].c_str());
		}
	}
	return 0;
}

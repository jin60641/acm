#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>

std::vector<std::string> v;

char s[51];
int n;

int cut(int a, int b){
	char tmp[51];
	for( int i = 0; i <= a; ++i ){
		tmp[i] = s[a-i];
	}
	for( int i = a+1; i <= b; ++i ){
		tmp[i] = s[a+1+b-i];
	}
	for( int i = b+1; i <= n-1; ++i ){
		tmp[i] = s[b+1+n-1-i];
	}
	tmp[n] = '\0';
	std::string str = tmp;
	v.push_back(str);
	return 0;
}

int main(){
	scanf("%s",s);
	n = strlen(s);
	for( int i = 0; i <= n-3; ++i ){
		for( int j = i+1; j <= n-2; ++j ){
			cut(i,j);
		}
	}
	std::sort(v.begin(),v.end());
	printf("%s\n",v[0].c_str());
	return 0;
}

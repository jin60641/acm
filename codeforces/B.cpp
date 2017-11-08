#include<stdio.h>

int main(){
	int good[26];
	for( int i = 0; i < 26; ++i ){
		good[i] = 0;
	}
	char goods[27];
	scanf("%s",goods);
	for( int i = 0; goods[i] != '\0'; ++i ){
		good[goods[i]-'a'] = 1;
	}
	char p[100001];
	scanf("%s",p);
	int N;
	int len;
	for( len = 0; p[len] != '\0'; ++len );

	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		char s[100001];
		scanf("%s",s);
		int end = 0;
		for( end = 0; s[end] != '\0'; ++end );
		int index = 0;
		int cnt = 0;
		for( int i = 0; i < len; ++i ){
			if( p[i] == '?' ){
				if( good[s[index]-'a'] == 1 ){
					++cnt;
					++index;
				} else {
					break;
				}
			} else if( p[i] == '*' ){
				if( p[i+1] != '\0' ){
					if( p[i+1] == '?' ){
						int tmp = 0;
						for( ; s[index] != '\0'; ++index ){
							if( good[s[index] - 'a'] == 1 ){
								tmp = 1;
								break;
							}
						}
						if( tmp == 0 ){
							break;
						} else {
							++index;
							++i;
							cnt += 2;
						}
					} else {
						int tmp = 0;
						for( ; s[index] != '\0'; ++index ){
							if( s[index] == p[i+1] ){
								tmp = 1;
								break;
							} else if( good[s[index] - 'a'] == 1 ){
								break;
							}
						}
						if( tmp == 0 ){
							break;
						} else {
							++i;
							++index;
							cnt += 2;
						}
					}
				} else {
					int tmp = 1;
					for( ; s[index] != '\0'; ++index ){
						if( good[s[index] - 'a'] == 1 ){
							tmp = 0;
							break;
						}
					}
					if( tmp == 1 ){
						++cnt;
					}
					break;
				}
			} else {
				if( s[index] == p[i] ){
					++index;
					++cnt;
				} else {
					break;
				}
			}
		}
		if( cnt == len && index == end ){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}

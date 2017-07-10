#include<stdio.h>

int main(){
    char s[101];
    scanf("%s",s);
    int a[26];
    for( int i = 0; i < 26; ++i ){
        a[i] = -1;
    }
    for( int i = 0 ; s[i] != '\0'; ++i ){
        if( a[s[i]-'a'] == -1 ){
            a[s[i]-'a'] = i;
        }
    }
    for( int i = 0; i < 26; ++i ){
        printf("%d ",a[i]);
    }
    return 0;
}


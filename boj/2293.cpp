#include<stdio.h>
int N,K,a[100],result[10001];
int main(){
    scanf("%d %d",&N,&K);
    for( int i = 0; i < N; i++ ){
        scanf("%d",&a[i]);
    }
    result[0] = 1;
    
    for( int i = 0; i < N; i++ ){
        for( int j = 1; j <= K; j++ ){
            if( j >= a[i] )
                result[j] += result[ j - a[i] ];
        }
    }   
    printf("%d",result[K]);
}

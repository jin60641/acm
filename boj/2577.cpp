#include<stdio.h>
int num[10];

int main(){
    long long int A,B,C,tot;
    scanf("%d %d %d",&A,&B,&C);
    tot = A*B*C;
    while( tot != 0 ){
        long long int tmp = tot%(long long int)10;
        tot/=10;
        ++num[tmp];
    }
    for( int i = 0; i < 10; ++i ){
        printf("%d\n",num[i]);
    }
    return 0;
}


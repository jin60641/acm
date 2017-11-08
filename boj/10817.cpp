#include<stdio.h>
#include<algorithm>

int main(){
    int A[3];
    scanf("%d %d %d",&A[0],&A[1],&A[2]);

    std::sort(A,A+3);

    printf("%d",A[1]);

    return 0;
}

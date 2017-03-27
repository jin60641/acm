#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int N; // 입력받을 숫자의 개수
int cnt = 0; // swap 횟수 ( 출력값 )
int A[500001]; // 입력값을 저장할 배열

int *swap(int[], int[], int, int); // 두개의 인접한 정렬된 배열, 앞 배열의 0번위치가 A배열에서 갖는 맨 앞자리, 뒷 배열의 마지막 위치가 A배열에서 갖는 맨 마지막 자리 

int* cut(int left,int right){ // A배열의 left와 right를 받아서 반으로 쪼개고 계속 쪼개다가 크기가 1이면 한칸짜리 배열을 반환. 배열된 반환은 swap함수의 인자로 들어간다
	int mid = (left+right)/2;
	if( left == right ){       // 한칸짜리 배열일 때 
		int *B = (int *)malloc(sizeof(int));    // 그대로 반환
		*B = A[right];
		return B;
	} else {                   // 한칸이 아닐때
		return swap( cut(left,mid), cut(mid+1,right), left, right );  // 재귀적으로 쪼개어 swap호출
	}
}

int* swap(int C[],int D[],int left,int right){
	if( left == right ){ // 1한짜리 배열이면 그대로 반환
		return A+left;
	}
	int mid = (left+right)/2;
	int Csize;
	int Dsize;
	if( right-left == 1 ){ // 2칸짜리 배열이면 두 배열의 길이는 1
		Csize = 1;
		Dsize = 1;
	} else {               // 3칸 이상일 경우에는 두 배열의 길이가 같거나 left가 1 크도록 함
		Csize = mid-left + 1;
		Dsize = right-(mid+1) + 1;
	}

	int *B;
	B = (int *)malloc(sizeof(int)*(Csize+Dsize)); // B는 C와 D를 담을 배열 
	int i = 0;								 //  i와 j는 C와 D의 인덱스
	int j = 0; 								
	int a, b;  								// a와 b는 C[i]와 D[j]의 값
	int jcnt = 0;						// 이미 들어간 D배열 원소의 갯수. icnt는 i와 같기 때문에 필요없다.
	while( i < Csize || j < Dsize ){      // 양쪽다 끝에 도달할 때 까지 loop
		if( j == Dsize ){               // 한쪽만 먼저 도달하면 이렇게 처리
			a = C[i];
			B[i+j] = a;
			++i;
		} else if( i == Csize ){		// 한쪽만 먼저 도달하면 이렇게 처리
			b = D[j];
			B[i+j] = b;
			++j;
		} else {						//양쪽 다 안끝났으면 이렇게 처리
			a = C[i];
			b = D[j];
			if( a < b ){
				B[i+j] = a;
				++i;
			} else if( b < a ){			// 오른쪽이 더 클경우 swap이 발생
				B[i+j] = b;
	//			cnt += (j-jcnt)+(Csize-i);
				cnt += (Csize-i);
				jcnt++;
				++j;
			}
		}
	}
	free(C); free(D); 		// 동적 메모리 할당 해제
	return B;				 // 합친 배열을 반환
}

int main(){
	scanf("%d",&N);
	for( int i = 0; i < N; ++i ){
		scanf("%d",&A[i]);
	}
	cut(0,N-1);
	printf("%d",cnt);
	return 0;
}

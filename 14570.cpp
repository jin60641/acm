#include<stdio.h>
#include<vector>

std::vector<int> leaf[2];

struct node {
	int parent,left,right;
};

node n[200001];

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 1; i <= N; ++i ){
		scanf("%d %d",&n[i].left,&n[i].right);
		if( n[i].left != -1 ){
			n[n[i].left].parent = i;
		}
		if( n[i].right != -1 ){
			n[n[i].right].parent = i;
		}
	}
	
	//좌측 리프노드탐색
	//우측 리프노드탐색
	
	int K;
	scanf("%d",&K);
	//K를 2로 나눈 나머지가 0이면 좌측 리프노드의 사이클에 포함됨
	//K를 2로 나눈 나머지가 1이면 우측 리프노드의 사이클에 포함됨
	//K를 2로 나눈 몫을 사이클의 길이로 나눈 나머지가 n이라면 사이클[n]이 답이됨
	
	return 0;
}

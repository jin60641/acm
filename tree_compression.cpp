#include<stdio.h>
#include<vector>

std::vector<int> v;

struct node {
	int left,right;
};

int weight[200001];
node n[200001];

int update( int now, int w, int parent ){
	if( now == -1 ){
		return 0;
	}
	weight[now] = w;
	if( n[now].left == -1 && n[now].right != -1 ){
		if( n[parent].right == now ){
			n[parent].right = n[now].right;
		} else {
			n[parent].left = n[now].right;
		}
		update(n[now].right,w,parent);
	} else if( n[now].right != -1 && n[now].left == 1 ){
		if( n[parent].left == now ){
			n[parent].left = n[now].left;
		} else {
			n[parent].right = n[now].left;
		}
		update(n[now].left,w,parent);
	} else {
		update(n[now].left,w+1,now);
		update(n[now].right,w+1,now);
	}
	return 0;
}

int print( int now ){
	if( now == -1 ){
		return 0;
	}
	printf("%d <- %d[%d] -> %d\n",n[now].left,now,weight[now],n[now].right);
	print(n[now].left);
	print(n[now].right);
	return 0;
}

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 1; i <= N; ++i ){
		int l,r;
		scanf("%d %d",&l,&r);
		if( l == -1 && r == -1 ){
			v.push_back(i);
		}
		n[i].left = l;
		n[i].right = r;
	}
	update(1,0,0);
	print(1);
	for( int i = 0; i < v.size(); ++i ){
		printf("%d ",v[i]);
	}
	printf("\n");
	//좌측 리프노드탐색
	//우측 리프노드탐색
	
	int K;
	scanf("%d",&K);
	//K를 2로 나눈 나머지가 0이면 좌측 리프노드의 사이클에 포함됨
	//K를 2로 나눈 나머지가 1이면 우측 리프노드의 사이클에 포함됨
	//K를 2로 나눈 몫을 사이클의 길이로 나눈 나머지가 n이라면 사이클[n]이 답이됨
	
	return 0;
}

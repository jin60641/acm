#include<stdio.h>

const int LEFT = 0;
const int RIGHT = 1;
int height = 0;

struct node {
	int parent;
	int type;
	int left; 
	int right; 
	int level;
};

node nodes[10010];
int lefts[10010];
int rights[10010];

int checkLevel( int value, int level ){
	if( value == -1 ){
		return 0;
	}
	if( height < level ){
		height = level;
	}
	nodes[value].level = level;
	rights[level] = level;
	if( lefts[level] == 0 ){
		lefts[level] = level;
	}
	return checkLevel( nodes[value].left, level + 1 ) + checkLevel( nodes[value].right, level+1 ) + 1;
}

int main(){
	int N;
	scanf("%d",&N);
	node vroot = { 0,-1,-1,0 };
	nodes[0] = vroot;
	for( int i = 1; i <= N; ++i ){
		node n = { 0,-1,-1,1 };
		nodes[i] = n;
	}
	
	for( int i = 1; i <= N; ++i ){
		int value,left,right;	
		scanf("%d %d %d",&value,&left,&right);
		nodes[value].left = left;
		nodes[value].right = right;
		nodes[left].parent = value;
		nodes[right].parent = value;
		nodes[left].type = LEFT;
		nodes[right].type = RIGHT;
	}
	
	int root = 0;
	for( int i = 1; i <= N; ++i ){
		if( nodes[i].parent == 0 ){
			root = i;
			break;
		}
	}
	
	printf("root is : %d\n",root);
	printf("root's child is : %d\n",checkLevel(root,1));
	printf("tree's height is : %d\n",height);

	return 0;
}

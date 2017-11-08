#include<stdio.h>

const int LEFT = 0;
const int RIGHT = 1;
int height;			
int keys[2][10010];	

struct node {
	int parent;		
	int type;		
	int left;		
	int right;		
	int level;		
	int child[2];	
	int width;		
};
node nodes[10010];

int check( int value, int level, int way ){		 
	if( value == -1 ){
		return 0;
	}
	height = height<level?level:height;
	nodes[value].level = level;
	int multi;
	if( way == LEFT ){
		nodes[value].child[LEFT] = check( nodes[value].left, level+1, way );
		nodes[value].child[RIGHT] = check( nodes[value].right, level+1, way );
		multi = 1;
	} else if( way == RIGHT ){
		nodes[value].child[RIGHT] = check( nodes[value].right, level+1, way );
		nodes[value].child[LEFT] = check( nodes[value].left, level+1, way );
		multi = -1;
	}
	if( nodes[value].type == LEFT ){
		nodes[value].width = ( nodes[value].child[RIGHT] + 1 ) * multi;
	} else if( nodes[value].type == RIGHT ){
		nodes[value].width = -( nodes[value].child[LEFT] + 1 ) * multi;
	}
	if( keys[way][level] == 0 ){
		keys[way][level] = value;
	} 
	return nodes[value].child[LEFT] + nodes[value].child[RIGHT] + 1;
}

int dp(int value){
	if( nodes[value].left > -1 ){
		nodes[nodes[value].left].width += nodes[value].width;
		dp(nodes[value].left);
	}
	if ( nodes[value].right > -1 ){
		nodes[nodes[value].right].width += nodes[value].width;
		dp(nodes[value].right);
	}
	return 0;
}

int main(){
	int N;
	scanf("%d",&N);
	for( int i = 1; i <= N; ++i ){
		node n = { 0,0,-1,-1,1,0,0,0 };
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
	height = 0;
	check( nodes[root].left, 2, LEFT );
	check( nodes[root].right, 2, RIGHT );
	dp(root);

	int max = 1;
	int max_i = root;
	for( int i = 1; i <= height; ++i ){
		int sum = nodes[keys[LEFT][i]].width + nodes[keys[RIGHT][i]].width;
		if( keys[LEFT][i] > 0 && keys[RIGHT][i] > 0 ){
			++sum;
		}
		if( sum > max ){
			max = sum;
			max_i = i;
		}
	}
	printf("%d %d\n",max_i,max);
	return 0;
}

#include<stdio.h>
#include<string.h>

int arr[21];
int main(){
	int M;
	char command[7][10] = { "add", "remove", "check", "toggle", "all", "empty" };
	scanf("%d", &M);
	for (int i = 0; i < M; ++i){
		char c[10];
		int x;
		scanf("%s %d", c, &x);
		for (int i = 0; i < 6; ++i){
			if (strcmp(command[i], c) == 0){
				switch (i){
					case 0: arr[x] = 1;
						break;
					case 1: arr[x] = 0;
						break;
					case 2: printf("%d\n", arr[x]);
						break;
					case 3: arr[x] = !arr[x];
						break;
					case 4:
						for (int i = 1; i <= 20; ++i){
							arr[i] = 1;
						}
						break;
					case 5:
						for (int i = 1; i <= 20; ++i){
							arr[i] = 0;
						}
						break;
				}		
			}	
		}
	}
}

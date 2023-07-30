/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:07/29 15:00
	Description:走迷宫-bfs
*/
#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int x;
	int y;
	struct Queue *next;
};

int N,M;
int g[100][100];
int v[100][100] = {0};
int x1,y1,x2,y2;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

struct Queue *createQueue(){
	struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
	Q->x = -1;
	Q->y = -1;
	Q->next = NULL;
	return Q;
}

int isEmpty(struct Queue *Q){
    return Q->next == NULL;
}

void enQueue(struct Queue *Q,int x,int y){
	struct Queue *node = (struct Queue *)malloc(sizeof(struct Queue));
	node->x = x;
	node->y = y;
	struct Queue *p = Q;
	while(p->next){
		p = p->next;
	}
	p->next = node;
	node->next = NULL;
}

struct Queue *deQueue(struct Queue *Q){
	struct Queue *node = Q->next;
	Q->next = node->next;
	return node;
}

void bfs(int x,int y){
	struct Queue *Q = createQueue();
	enQueue(Q,x,y);
	while(!isEmpty(Q)){
		struct Queue *node = deQueue(Q);
		x = node->x;
		y = node->y;
		if(x == x2 && y == y2) return;
		int i;
		for(i = 0;i < 4;i++){
			int a = x + dx[i];
			int b = y + dy[i];
			if(a >= 1 && a <= N && b >= 1 && b <= M){
				if(g[a][b] >= 1 && v[a][b] == 0){
					g[a][b] = g[x][y] + 1;
					enQueue(Q,a,b);
					v[a][b] = 1;
				}
			}
		}
	}
}


int main(){
	freopen("input.txt", "r", stdin);
 	scanf("%d %d",&N,&M);
	int i,j;
	for(i = 1;i <= N;i++){
		for(j = 1;j <= M;j++){
			scanf("%d",&g[i][j]);
		}
	}
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	g[x1][y1] = 1;//起点可能在障碍处！
	bfs(x1,y1);
	printf("%d",g[x2][y2] > 1 ? g[x2][y2] - 1 : -1);
	return 0;
}


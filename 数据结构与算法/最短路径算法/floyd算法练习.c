#include<stdio.h>
#include<stdlib.h>
#define INF 32768

typedef struct Graph{
	char *vexs;
	int **arcs;
	int vexNum;
	int arcNum;
}Graph;

Graph *initGraph(int vexNum){
	Graph *G = (Graph *)malloc(sizeof(Graph));
	G->vexs = (char *)malloc(sizeof(char));
	G->arcs = (int **)malloc(sizeof(int *));
	int i;
	for(i = 0;i < vexNum;i++){
		G->arcs[i] = (int *)malloc(sizeof(int));
	}
	G->vexNum = vexNum;
	G->arcNum = 0;
	return G;
}

void createGraph(Graph *G,char *vexs,int *arcs){
	int i,j;
	for(i = 0;i < G->vexNum;i++){
		G->vexs[i] = vexs[i];
	}
	for(i = 0;i < G->vexNum;i++){
		for(j = 0;j < G->vexNum;j++){
			G->arcs[i][j] = *(arcs + i * G->vexNum + j);
			if(G->arcs[i][j] != 0 && G->arcs[i][j] != INF){
				G->arcNum++;
			}
		}
	}
	G->arcNum /= 2;
}

void DFS(Graph *G,int *visited,int index){
 	if(visited[index] == 0){
		printf("v%c ",G->vexs[index]);
		visited[index] = 1;
		int i;
		for(i = 0;i < G->vexNum;i++){
			if(G->arcs[index][i] > 0 && G->arcs[index][i] != INF){
				DFS(G,visited,i);
   			}
		}
 	}
}

void showPath(int vexNum,int *d,int *p){
	int i,j,k = 0;
	int cnt;
	/* path数组来模拟栈 */
	int path[vexNum];
	int size = 0;
	printf("    终点  ");
	for(i = 0;i < vexNum;i++){
		printf("v%d",i + 1);
		for(j = 0;j < vexNum;j++){
			printf("    ");
		}
		printf("    ");
	}
	printf("\n起点\n");
	for(i = 0;i < vexNum;i++){
		printf("v%d        ",i + 1);
		for(j = 0;j < vexNum;j++){
			size = 0;
			k = j;
			//将终点到起点的所有点从后到前依次入栈
			path[size++] = j;//入栈终点
			while(k != i){
				k = *(p + vexNum * i + k);//vi到vk的前驱
				path[size++] = k;//起点也会入栈
			}
			//将栈中的点出栈
			cnt = 0;//控制字符数
			while(size > 1){
				printf("v%d->",path[--size] + 1);
				cnt++;
			}
			printf("v%d",path[0] + 1);
			while(cnt <= vexNum){
				printf("    ");
				cnt++;
			}
		}
		printf("\n\n");
	}
}

void floyd(Graph *G){
    int d[G->vexNum][G->vexNum];//d[i][j]表示从i到j的最短距离
    int p[G->vexNum][G->vexNum];//p[i][j]表示从i到j的最短路径中j的前驱
    int i,j,k;
    //初始化d数组和p数组
    for(i = 0;i < G->vexNum;i++){
		for(j = 0;j < G->vexNum;j++){
			d[i][j] = G->arcs[i][j];
			if(d[i][j] > 0 && d[i][j] != INF){
				p[i][j] = i;
			}
			else
				p[i][j] = -1;
		}
    }
    /* floyd算法 */
    for(i = 0;i < G->vexNum;i++){//遍历中间节点
    	for(j = 0;j < G->vexNum;j++){//遍历起点
    		for(k = 0;k < G->vexNum;k++){//遍历终点
				if(d[j][i] + d[i][k] < d[j][k]){
					d[j][k] = d[j][i] + d[i][k];
					p[j][k] = i;
				}
			}
		}
	}
 	showPath(G->vexNum,(int *)d,(int *)p);
}

int main(){
	Graph *G = initGraph(4);
	/* 规定到自身的最短路径长为0，不可达的路径长为INF */
	int arcs[4][4] = {
		  0,  1,INF,  3,
		  1,  0,  2,  2,
		INF,  2,  0,  8,
		  3,  2,  8,  0
	};
	int visited[4] = {0};
	createGraph(G,"1234",(int *)arcs);
	DFS(G,visited,0);
	putchar('\n');
 	floyd(G);
	return 0;
}


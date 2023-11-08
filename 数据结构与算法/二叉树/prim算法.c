#include<stdio.h>
#include<string.h>
#define INF 0x7fffffff

typedef struct Edge{
    int start;//边的起点
    int weight;//边的权值
}Edge;

/* vex为节点数组，arc为邻接矩阵，index指定某节点索引，表示从该节点生成最小生成树 */
void prim(char *vex,int **arc,int index){//prim算法为加点法
	int vexNum = strlen(vex);//节点数目
	Edge edge[vexNum];//edge[index]记录当前已选节点中到index节点的最小边
    int i,j,dest;
    for(i = 0;i < vexNum;i++){
    	edge[i].start = index;//边的起点都为index节点
		edge[i].weight = arc[index][i];//初始化edge为index节点到各节点的权值
	}
	/*
	for(i = 0;i < vexNum;i++){
		for(j = 0;j < vexNum;j++){
			printf("%10d ",arc[i][j]);
		}
		putchar('\n');
	}
	*/
    for(i = 0;i < vexNum - 1;i++){//将vexNum - 1个点加入到树中
    	//选取当前已选节点到所有节点的最短边
		int min = 0x7fffffff;
        for(dest = 0;dest < vexNum;dest++){//遍历所有以dest为终点的最小边
			if(edge[dest].weight != 0 && edge[dest].weight < min){
				index = dest;
				min = edge[dest].weight;
			}
		}
		printf("%c -> %c %d\n",vex[edge[index].start],vex[index],edge[index].weight);
		printf("edge：");
		
		//index节点加入树中，更新edge数组
		for(dest = 0;dest < vexNum;dest++){
			if(arc[index][dest] < edge[dest].weight){
				edge[dest].start = index;
				edge[dest].weight = arc[index][dest];
			}
			printf("%d ",edge[dest].weight);
		}
        printf("\n\n");
		
	}
}

int main(){
	int arcs[6][6] = {
		  0,  6,  1,  5,INF,INF,
		  6,  0,  5,INF,  3,INF,
		  1,  5,  0,  5,  6,  4,
		  5,INF,  5,  0,INF,  2,
	  	INF,  3,  6,INF,  0,  6,
	  	INF,INF,  4,  2,  6,  0
	};//到自己为0，如果不连通为INF
	int *p[6];
	int i;
	for(i = 0;i < 6;i++)
		p[i] = (int *)arcs[i];
	int **arc= p;
	prim("ABCDEF",arc,0);
	return 0;
}


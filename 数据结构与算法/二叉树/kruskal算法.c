/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date:
	Description:
*/
#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
#define INF 0x7fffffff

typedef struct Edge{
	int start;//起点
	int end;//终点
	int weight;//权值
}Edge;

void kruskal(char *vex,int **arc,int index){
	int vexNum = strlen(vex);//节点数目
	int connect[vexNum];//连通分量
	int i,j,arcNum = 0;
	
	//获取边数
	for(i = 0;i < vexNum;i++){
		for(j = 0;j < vexNum;j++){
			if(arc[i][j] != 0 && arc[i][j] != INF)
				arcNum++;
		}
	}
	
	//初始化连通分量
	for(i = 0;i < vexNum;i++)
		connect[i] = i;//初始化节点的连通分量等于本身
		
	Edge edge[arcNum],t;//边的集合
	int cnt = 0;
	//初始化边
	for(i = 0;i < vexNum;i++){
		for(j = 0;j < vexNum;j++){
   			if(arc[i][j] != 0 && arc[i][j] != INF){
				edge[cnt].start = i;
				edge[cnt].end = j;
				edge[cnt].weight = arc[i][j];
				cnt++;
   			}
		}
	}
	
	/*
	for(i = 0;i < arcNum;i++){
		printf("%c->%c %d\n",vex[edge[i].start],vex[edge[i].end],edge[i].weight);
	}
	*/

	
	//插入排序，对边的集合按从小到大排序
	for(i = 1;i < arcNum;i++){
		t = edge[i];
		for(j = i - 1;j >= 0;j--){
			if(t.weight < edge[j].weight) //向后挪位
				edge[j + 1] = edge[j];
			else break;
		}
		edge[j + 1] = t;
	}
	
	for(i = 0;i < arcNum;i++)
		printf("%d ",edge[i].weight);
	putchar('\n');
	
	//kruskal算法实现最小生成树
	for(i = 0;i < arcNum;i++){
		//获取初始边的起点和终点的连通分量
        int start = connect[edge[i].start];
        int end = connect[edge[i].end];
		if(start != end){ //连通分量不同不形成环
			printf("%c->%c %d\n",vex[edge[i].start],vex[edge[i].end],edge[i].weight);
			//将所有连通分量为end的节点的连通分量更新为vex[start]
			for(j = 0;j < vexNum;j++){
				if(connect[j] == end)
					connect[j] = start;//表示以end节点为连通分量的节点加入到生成树中
			}
		}
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
 	kruskal("ABCDEF",arc,0);
	return 0;
}


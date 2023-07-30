/*
	Name: kruskal算法
	Copyright:劣等生
	Author:劣等生
	Date: 2023/06/23 11:08
	Description:
*/
#include<stdio.h>
#define N 6
#define INF 0x7fffffff
struct edge{
	int start;
	int end;
	int w;
};
int n = N * (N -1)/2;

void sortEdge(struct edge* e){
	int i,j;
	struct edge t;
	for(i = 0;i < n;i++){
		t = e[i];
		for(j = i - 1;j >= 0;j--)
			if(t.w < e[j].w) e[j + 1] = e[j];
				else break;
		e[j + 1] = t;
	}
}

int main(){
	int arc[N][N] = {
		  0,  6,  1,  5,INF,INF,
		  6,  0,  5,INF,  3,INF,
		  1,  5,  0,  5,  6,  4,
		  5,INF,  5,  0,INF,  2,
	  	INF,  3,  6,INF,  0,  6,
	  	INF,INF,  4,  2,  6,  0
	};
	char v[7] = "ABCDEF";
	struct edge e[n];//边
	int cnct[N];//连通分量
	int i,j,index = 0;
	for(i = 0;i < n;i++){
		e[i].start = 0;
		e[i].end = 0;
		e[i].w = INF;
	}
	for(i = 0;i < N;i++){
		cnct[i] = i;
		for(j = i + 1;j < N;j++){
			if(arc[i][j] != INF){
				e[index].start = i;
				e[index].end = j;
				e[index].w = arc[i][j];
				index++;
			}
		}
	}
	sortEdge(&e[0]);
	//kruskal算法
	int start,end;
	for(i = 0;i < n;i++){
		start = cnct[e[i].start];
		end = cnct[e[i].end];
		if(start != end){
			printf("%c->%c weight=%d\n",v[e[i].start],v[e[i].end],e[i].w);
			for(j = 0;j < N;j++)
				if(cnct[j] == end)
					cnct[j] = start;
		}
	}
	return 0;
}


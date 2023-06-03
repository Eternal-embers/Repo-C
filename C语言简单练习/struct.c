#include<stdio.h>
struct Node{
	int data1;
	char data2;
}node[20];
int main(){
	int i,j,k;
	int t1; //用来程序中暂时存放结构体里的data1的数据
	char t2;//用来程序中暂时村饭结构体里的data2的数据
	//我们这里以data1为排序的参考依据，比较data1的大小来确定谁排前面
	for(i = 0;i<20;i++){
		k = i;
		for(j = i;j<20;j++){
			if(node[k].data1 > node[j].data1) k = j;//将结构体数组中data1最小的那个结构体的下标赋给k
		}
		if(k!=i){
			//交换node[k].data1和node[i].data1的值
			t1 = node[k].data1;
			node[k].data1 = node[i].data1;
			node[i].data1 = t1;

			//交换node[k].data2和node[i].data2的值
			t2 = node[k].data2;
			node[k].data2 = node[i].data2;
			node[i].data2 = t2;
		}//每一次将data1最小的结构体排到前面
	}
	return 0;}

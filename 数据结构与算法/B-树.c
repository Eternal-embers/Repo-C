/*
	Name:B-��
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 09/10 19:52
	Description:
*/
#include<stdio.h>
#define KeyType int
#define m 3
typedef struct BTNode{
	int keynum;//�ڵ��йؼ��ֵĸ��������ڵ�Ĵ�С
	struct BTNode *parent;//ָ��˫�׽ڵ�
	KeyType k[m];//�ؼ�������
	struct BTNode *ptr[m];//����ָ������
}BTNode,*BTree;//B-���ڵ��B-��������

typedef struct{
	BTNode *pt;//�ҵ��Ľڵ�
	int i;//1~m���ڽڵ��еĹؼ������
	int tag;//B-���Ĳ��ҽ������
}Result;//B-���Ĳ��ҽ������

Result *createResult(BTNode *pt,int i,int tag){
	Result res = (Result *)malloc(sizeof(Result));
	res->i = i;
	res->pt = p;
	res->tag = tag;
}

Result *SearchBTree(BTree T,KeyType key){
	//��m��B-��T�ϲ��ҹؼ���key�����ؽ��(pt,i,tag)
	//�����ҳɹ���������ֵtag = 1��ָ��ptָ��ڵ��е�i���ؼ��ֵ���key
	//��������ֵtag = 0������key�Ĺؼ���Ӧ������ָ��pt��ֵ�ڵ�ĵ�i���͵�i + 1���ؼ���֮��
	BTNode *p = T;//pָ�����ڵ�
	BTree q = NULL;//qָ��p��˫��
	int found = 0;//�ж��Ƿ���ҵ�key
    int i = 0;
    while(p && !found){
    	i = search(p,key);//��0~keynum�в���i,ʹ��p->k[i] <= key < p->k[i + 1]
    	if(i > 0 && p->k[i] == key) found = 1;//�ҵ��ؼ���
    	else{
    		q = p;
    		p = p->ptr[i];
		}
	}
	return createResult(q,i,found);//���ز��ҽ����������Ҳ��ɹ����ص���key�Ĳ���λ����Ϣ
}
int main(){

	return 0;
}


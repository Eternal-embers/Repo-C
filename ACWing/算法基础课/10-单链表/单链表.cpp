#include<iostream>

using namespace std;

const int N = 100005;

/*
    e[] ����洢�ڵ��ֵ�� n[] ����洢�ڵ��nextָ��
	head Ϊͷ�ڵ��� e[] �� n[]  �е�����
	idx Ϊ��һ��Ҫ����Ľڵ�����
*/
int head, idx;
int e[N], ne[N];

/* ��ʼ�� */
void init(){
	head = -1;
	idx = 0;
}

/* �� x ���뵽ͷ�ڵ� */
void add_to_head(int x){
	e[idx] = x, ne[idx] = head, head = idx++;
}

/* �� x ���뵽�±��� k �Ľڵ���� */
void add(int k, int x){
	e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

/* ���±��� k �Ľڵ����Ľڵ�ɾ�� */
void remove(int k){
	ne[k] = ne[ne[k]];
}

int main(){
	int m;
	cin >> m;
	
	init();

	while(m--){
		int k, x;
		char op;
		cin >> op;
		if(op == 'H'){
			cin >> x;
			add_to_head(x);
		}
		else if(op == 'D'){
			cin >> k;
			if(!k) head = ne[head];
			remove(k - 1);
		}
		else if(op == 'I'){
			cin >> k >> x;
			add(k - 1, x);
		}
	}
	
	for(int i = head;i != -1;i = ne[i])
		cout << e[i] << ' ';
	cout << endl;

	return 0;
}

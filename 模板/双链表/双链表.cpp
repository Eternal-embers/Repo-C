int e[N], l[N], r[N], idx;

//ͷ�ڵ�������0λ�ã�β�ڵ�������1λ��
void init(){
	r[0] = 1, l[1] = 0;
	idx = 2;
}

//��x ���뵽�� k ������Ľڵ�ĺ���
void add(int k, int x){
	e[idx] = x;
	l[idx] = k;
	r[idx] = r[k];
	l[r[k]] = idx;
	r[k] = idx;
	idx++;
}

//�Ƴ��� k ������Ľڵ�
void remove(int k){
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}

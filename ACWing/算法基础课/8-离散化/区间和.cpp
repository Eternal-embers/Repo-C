#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300005;//N = n + 2m

int n,m;
int a[N], s[N];//a�洢�������ϵ�x��sΪa��ǰ׺������

vector<int> alls;//�洢�����漰��������
vector<PII> add, query;//add��¼x��c��query��¼����߽�l��r

//���ֲ������� x ��alls�е�����
int find(int x){
	int l = 0,r = alls.size() - 1;
	while(l < r){
		int mid = l + r >> 1;
		if(alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;
}

vector<int>::iterator unique(vector<int> &a){
	//��һ�������ظ������Դӵڶ�������ʼ
	int j = 1;//���潫��֤���� 0~j �ھ�Ϊ���ظ�����
	for(int i = 1;i < a.size();i++)
		if(a[i] != a[i - 1]) a[j++] = a[i];
		
	return a.begin() + j;
}

int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		int x, c;
		cin >> x >> c;
		add.push_back({x, c});
		alls.push_back(x);
	}
	
	for(int i = 0;i < m;i++){
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});
		
		alls.push_back(l);
		alls.push_back(r);
	}
	
	//�����е�����ȥ��
	sort(alls.begin(),alls.end());
	alls.erase(unique(alls),alls.end());
	
    //������õĸ����������ȫ��洢��a������
    for(PII item: add){
    	int x = find(item.first);
    	a[x] += item.second;
	}
	
	//Ԥ��������λ���ϵ���ǰ׺��
	for(int i = 1;i <= alls.size();i++) s[i] = s[i - 1] + a[i];
	
	//����ѯ��
	for(PII item: query){
		int l = find(item.first), r = find(item.second);
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}

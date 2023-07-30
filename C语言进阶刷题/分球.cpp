/*
	Name:
	Copyright:�ӵ���
	Author:�ӵ���
	Date: 07/23 17:45
	Description: ���Ļ���
*/

#include <stdio.h>

// ��n����ͬ����ֳ�k�ݣ�ÿ�ݲ���Ϊ�յķַ�����
int partition(int n, int k) {
    // �޷���n����ֳ�k�ݣ�����0
    if (n < k) {
        return 0;
    }

    // ֻ��һ�ݣ�ֻ��һ�ַַ�
    if (k == 1) {
        return 1;
    }

    int result = 0;
    int i;

    // ����ÿһ�ݣ�ѡ�����0����n-k+1����
    for (i = 0; i <= n - k + 1; i++) {
        // ��ʣ�µ�������ֳ�k-1��
        result += partition(n - i, k - 1);
    }

    return result;
}

int main() {
    int n = 7; // �������
    int k = 3; // ����

    int result = partition(n, k);

    printf("��%d����ֳ�%d�ݣ�ÿ�ݲ���Ϊ�գ��ķַ�����Ϊ��%d\n", n, k, result);

    return 0;
}

/*
int main(){
 	int n,k;
	scanf("%d %d",&n,&k);
	int ans = C(n-1,k-1) / 2;
	printf("%d",ans);
	return 0;
}
*/

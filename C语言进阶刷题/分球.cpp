/*
	Name:
	Copyright:劣等生
	Author:劣等生
	Date: 07/23 17:45
	Description: 数的划分
*/

#include <stdio.h>

// 将n个相同的球分成k份，每份不能为空的分法数量
int partition(int n, int k) {
    // 无法将n个球分成k份，返回0
    if (n < k) {
        return 0;
    }

    // 只有一份，只有一种分法
    if (k == 1) {
        return 1;
    }

    int result = 0;
    int i;

    // 对于每一份，选择放入0个球到n-k+1个球
    for (i = 0; i <= n - k + 1; i++) {
        // 将剩下的球继续分成k-1份
        result += partition(n - i, k - 1);
    }

    return result;
}

int main() {
    int n = 7; // 球的数量
    int k = 3; // 份数

    int result = partition(n, k);

    printf("将%d个球分成%d份（每份不能为空）的分法数量为：%d\n", n, k, result);

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

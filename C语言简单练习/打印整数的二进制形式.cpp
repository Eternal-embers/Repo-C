#include <stdio.h>

// 打印整数的二进制形式
void printBinary(int num, int bits) {
    // 根据有符号数和无符号数进行类型转换
    unsigned int unsignedNum = (unsigned int) num;

    // 打印二进制形式
    printf("%d 的二进制形式为：", num);
    for (int i = bits - 1; i >= 0; i--) {
        int bit = (unsignedNum >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}



int main() {
    int num;
    int bits;

    printf("请输入一个整数：");
    scanf("%d", &num);

    printf("请输入整数的位数：");
    scanf("%d", &bits);

    printBinary(num, bits);
    return 0;
}

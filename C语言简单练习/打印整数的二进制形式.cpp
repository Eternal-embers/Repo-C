#include <stdio.h>

// ��ӡ�����Ķ�������ʽ
void printBinary(int num, int bits) {
    // �����з��������޷�������������ת��
    unsigned int unsignedNum = (unsigned int) num;

    // ��ӡ��������ʽ
    printf("%d �Ķ�������ʽΪ��", num);
    for (int i = bits - 1; i >= 0; i--) {
        int bit = (unsignedNum >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}



int main() {
    int num;
    int bits;

    printf("������һ��������");
    scanf("%d", &num);

    printf("������������λ����");
    scanf("%d", &bits);

    printBinary(num, bits);
    return 0;
}

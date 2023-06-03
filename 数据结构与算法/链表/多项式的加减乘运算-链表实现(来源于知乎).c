#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode* poly;
struct ListNode{
    int zhi;  //指数
    int xi;   //系数
    poly next;  //指向下一个结点
};

poly Attach(int xi, int zhi, poly p){
    poly temp = malloc(sizeof(poly));
    temp->xi = xi;
    temp->zhi = zhi;
    temp->next = NULL;
    p->next = temp;
    return p->next;
}

poly ReadPoly(){
    poly p = malloc(sizeof(poly));
    poly temp = p;
    int num;
    printf("请输入多项式项数：");
    scanf("%d", &num);
    int x, y,i;
    printf("请输入多项式各项的指数和系数：\n      指数 系数\n");
    for ( i = 0; i < num; i++){
    	printf("第%d项:",i + 1);
        scanf("%d %d", &x, &y);
        temp = Attach(x, y, temp);
    }
    return p->next;
}

void PrintPoly(poly p){
    int flag = 0;

    if (p == NULL) printf("0 0");

    while (p->next != NULL){
        if (flag == 0) flag = 1;
        else {
            printf(" ");
        }
        printf("%d*[X^%d] + ", p->xi, p->zhi);
        p = p->next;
    }
    printf("%d*[X^%d]",p->xi,p->zhi);
    printf("\n");
}

poly add(poly a, poly b){
    poly res, temp;
    res = malloc(sizeof(poly));
    temp = res;

    while (a != NULL && b != NULL){
        if (a->zhi > b->zhi){
            temp = Attach(a->xi, a->zhi, temp);
            a = a->next;
        }else if (a->zhi == b->zhi){
            int xi = a->xi + b->xi;
            if (xi != 0){
                temp = Attach(a->xi + b->xi, a->zhi, temp);
            }
            a = a->next;
            b = b->next;
        }else{
            temp = Attach(b->xi, b->zhi, temp);
            b = b->next;
        }
    }

    if (a != NULL){
        temp->next = a;
    }
    if (b != NULL){
        temp->next = b;
    }

    return res->next;
}

poly mul(poly a, poly b){
    if (a == NULL || b == NULL) return NULL;

    poly res, temp, p1, p2;
    p1 = a;
    p2 = b;
    res = malloc(sizeof(poly));
    temp = res;

    while (p2 != NULL){
        temp = Attach(p1->xi * p2->xi, p1->zhi + p2->zhi, temp);
        p2 = p2->next;
    }
    p1 = p1->next;
    while (p1 != NULL){
        p2 = b;
        temp = res;
        while (p2 != NULL){
            int xi, zhi;
            xi = p1->xi * p2->xi;
            zhi = p1->zhi + p2->zhi;
            while (temp->next != NULL && temp->next->zhi > zhi){
                temp = temp->next;
            }
            if (temp->next != NULL && temp->next->zhi == zhi){
                temp->next->xi += xi;
                if (temp->next->xi == 0){
                    temp->next = temp->next->next;
                }
            }else {
                poly t = malloc(sizeof(poly));
                t->xi = xi;
                t->zhi = zhi;
                t->next = temp->next;
                temp->next = t;
                temp = temp->next;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return res->next;
}

int main(){
    poly a, b, res_add, res_mul;

    a = ReadPoly();
    b = ReadPoly();

    res_mul = mul(a, b);
	printf("多项式相乘结果:\n");
    PrintPoly(res_mul);

	printf("\n");
    res_add = add(a, b);
    printf("多项式相加结果:\n");
    PrintPoly(res_add);

    return 0;
}

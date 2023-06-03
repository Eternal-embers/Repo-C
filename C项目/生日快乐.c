#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define I 20
#define R 340
#define MAX_TIME 99999999

void draw_heart(int);
void draw_wait();
void draw_color();

char color[] = "color ";
int len;
char font_color[] = {"023456789abcde"};
char back_color[] = {"000000000000b"};

int main()
{
    system("mode con cols=80 lines=40 ");
    system("title 向xx致以最美好的祝福!");
    len = strlen(color);
    char data[200][60]={
                        {"曾经答应xx的代码礼物，不知xx是否还记得！\n"},
                        {"虽然我以前给你送过一个代码礼物啦~\n"},
                        {"但是xx肯定说，“我！”\n"},
                        {"“xxx”\n"},
                        {"“很不满意！”\n"},
                        {"那xx就！\n"},
                        // 0-4
                        {"\n3!\n"},
                        {"\n2!\n"},
                        {"\n1!\n"},
                        // 5-7
                        {"祝x生日快乐！祝x生日快乐 ！"},
                        {"\nHappy birthday to xx！\n"},
                        {"Happy birthday my dear xx！\n"},
                        {"有你在的每一天，我都真的很开心！\n"},
                        {"虽然你和我，没办法呆在一块。\n"},
                        {"但是xx的心永远在xx身旁！\n"},
                        {"109~ 109~ 神神奇奇一零九！\n"},
                        {"xx永远不分离呀~\n"},
                        {"这是用 C 语言写的哦！\n"},
                        {"见 C 语言如见xx！\n"},
                        {"源代码给xx奉上！\n"},
                        {"要求：全文背诵！\n"}
                        // 8-18
                    };
    int start = 9, end = 20;

    int sign = 0;
    int i,j;
    long times;
    int wait = 15;
    for(sign = 0; sign < start; sign++){
        printf("\n%s",data[sign]);
        for(i = 0; i < wait; i++){
             draw_color();
            draw_wait();
        }
        if(sign == 5)    wait /= 3;
    }
    int colorsize = 10;
    printf("\n\n\n\n");
    draw_heart(0);
    for(; ; ){
        char cl[20];
        j = 0;
        for(i = j; i < strlen(font_color); i+=2){
            strcpy(cl, color);
            cl[len] = font_color[i];
            cl[len + 1] = '\0';
            system(cl);
            draw_wait();
        }
        j++;
        j %= 2;
        srand((unsigned int)time(NULL));
        int k = rand() % strlen(back_color);
        strcpy(cl, color);
        cl[len] = back_color[k];
        for(i = 0; i < strlen(font_color)/2; i++){
            srand((unsigned int)time(NULL));
            k = rand() % strlen(font_color);
            cl[len + 1] = font_color[k];
            cl[len + 2] = '\0';
            system(cl);
            draw_wait();
        }
        printf("\n%s",data[sign]);
        sign++;
        if(sign > end){
            break;
        }
    }
    while(1){
        draw_heart(1);
        printf("\n\n\n\n");
    }
    return 0;
}

void draw_color(){
    char cl[20];
    srand((unsigned int)time(NULL));
    int k = rand() % strlen(back_color);
    strcpy(cl, color);
    cl[len] = back_color[k];
    srand((unsigned int)time(NULL));
    k = rand() % strlen(font_color);
    cl[len + 1] = font_color[k];
    cl[len + 2] = '\0';
    system(cl);
}

void draw_heart(int wait){
    int i, j, e, a;
    for(i=1,a=I;i<I/2;i++,a--){
        for(j=(int) ( I-sqrt(I*I-(a-i)*(a-i)) );j>0;j--)    printf(" ");
        for(e=1;e<=2*sqrt(I*I-(a-i)*(a-i));e++)    printf("\3");
        for(j=(int)( 2*( I-sqrt(I*I-(a-i)*(a-i)) ) );j>0;j--)    printf(" ");
        for(e=1;e<=2*sqrt(I*I-(a-i)*(a-i));e++)    printf("\3");
        printf("\n");
        if(wait && i % 2){
            draw_color();
            draw_wait();
        }
    }
    for(i=1;i<80;i++){
        if(i==20){
            printf("======祝xxxxxx，二十岁生日快乐。======");
            i+=40;
        }
        printf("\3");
    }
    printf("\n");
    for(i=1;i<=R/2;i++){
        if(i%2||i%3)    continue;
        for(j=(int) ( R-sqrt(R*R-i*i) );j>0;j--)    printf(" ");
        for(e=1;e<=2*( sqrt(R*R-i*i) - (R-2*I) );e++)    printf("\3");
        printf("\n");
        if(wait){
            draw_color();
            draw_wait();
        }
    }
}

void draw_wait(){
    int times;
    for(times=0;times<MAX_TIME;times++);
}

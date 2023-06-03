#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#define I 20
#define R 340
#define N 20
int main()
{
	//system("mode con cols=length lines=width");设置控制台的长和宽
	//system("mode con cp select=437");设置代码页数
	system("mode con cols=160 lines=80 ");
	system("title 向你致以最诚挚的祝福!");
	char data[20][200]={
	{"\t\t迟来的祝福，在此说抱歉！\n\n"},
	{"\t\t祝你，历经山河，依然觉得人生值得;愿你，往后余生，永远长安适如常。\n\n"},
	{"\t\t愿你三冬暖，愿你春不寒，愿你天黑有灯，下雨有伞，愿你一路上，有良人相伴！\n\n"},
	{"\t\t愿你被这个世界温柔以待，躲不过的惊吓都只是一场虚镜，收到的欢喜从无空欢喜！\n\n"},
	{"\t\t愿你的未来纯净明朗，像你此刻可爱的目光。再世间美好的命运中，愿你的命运美好欢畅！\n\n"},
	{"\t\t但愿你的眼睛，只看的到笑容；但愿你流下的每一滴眼泪，都让人感动；但愿你的每一个梦，不会一场空！\n\n"},
	{"\t\t愿你在被打击时，记起你的珍贵，抵抗恶意；愿你在迷茫时，坚信你的珍贵，爱你所爱，行你所行，听你所心，无问西东。\n\n"},
	{"\t\t碎碎念念，岁岁年年，愿你看过落日长河，仍能明亮如初;历尽千帆，仍能保持赤诚。加油，要是坚持不下去了，我会鼓励你的。\n\n"},
	("\t\t有人并肩很好，自己一个人也不要太落寞，每一步脚踏实走好了。生活是给自己过的，不是为了谁才好好生活，所以祝你过上精彩纷呈的人生。\n\n"),
	{"\t\t此处相望不相同，愿逐月华流照卿!\n"},
	{"#"},
	};
	int sign = 1;
	int i,j,e;
	int a;
	//sleep(value);单位s
	//Sleep(value);单位ms
	printf("\n\n\n\n");
	{
	//亮蓝
	system("color 9A"); Sleep(50);
	system("color 9B"); Sleep(50);
	system("color 9C"); Sleep(50);
	system("color 9D"); Sleep(50);
	system("color 9E"); Sleep(50);
	system("color 9F"); Sleep(50);
	printf("\t\t%s\n\t\t\n",data[0]);
	//浅红
	system("color CA"); Sleep(50);
	system("color CB"); Sleep(50);
	system("color CC"); Sleep(50);
	system("color CD"); Sleep(50);
	system("color CE"); Sleep(50);
	system("color CF"); Sleep(50);
	printf("\t\t\t%s\n\t\t\t\n",data[0]);
	//蓝绿
	system("color BA"); Sleep(50);
	system("color BB"); Sleep(50);
	system("color BC"); Sleep(50);
	system("color BD"); Sleep(50);
	system("color BE"); Sleep(50);
	system("color BF"); Sleep(50);
	printf("\t\t\t\t%s\n\t\t\t\t\n",data[0]);
	//浅黄
	system("color EA"); Sleep(50);
	system("color EB"); Sleep(50);
	system("color EC"); Sleep(50);
	system("color ED"); Sleep(50);
	system("color EE"); Sleep(50);
	system("color EF"); Sleep(50);
	printf("\t\t\t\t\t%s\n\t\t\t\t\t\n",data[0]);
	//暗蓝
	system("color 3A"); Sleep(50);
	system("color 3B"); Sleep(50);
	system("color 3C"); Sleep(50);
	system("color 3D"); Sleep(50);
	system("color 3E"); Sleep(50);
	system("color 3F"); Sleep(50);
	printf("\t\t\t\t%s\n\t\t\t\t\n",data[0]);
	//亮白
	system("color FA"); Sleep(50);
	system("color FB"); Sleep(50);
	system("color FC"); Sleep(50);
	system("color FD"); Sleep(50);
	system("color FE"); Sleep(50);
	system("color FF"); Sleep(50);
	printf("\t\t\t%s\n\t\t\t\n",data[0]);
	//亮蓝
	system("color 9A"); Sleep(50);
	system("color 9B"); Sleep(50);
	system("color 9C"); Sleep(50);
	system("color 9D"); Sleep(50);
	system("color 9E"); Sleep(50);
	system("color 9F"); Sleep(50);
	printf("\t\t%s\n\t\t\n",data[0]);
	}
	sleep(2);
	for(i = 0;i<10;i++){
		printf("\n\n\n\t\t\t\t");
		for(j = 0;j<10;j++){
		printf(">>> ");
		Sleep(5);
		}
		system("cls");
	}
	//亮蓝
	system("color 9A");
	system("color 9B");
	system("color 9C");
	system("color 9D");
	system("color 9E");
	system("color 9F");
	//亮白
	system("color FA");
	system("color FB");
	system("color FC");
	system("color FD");
	system("color FE");
	system("color FF");
	//祝福语
	printf("\n\n\n\n");
	while(data[sign][0]!='#'){
	printf("\t\t%s\n\n",data[sign]);
	sign++;
	//亮蓝
	system("color 9A"); Sleep(50);
	system("color 9B"); Sleep(50);
	system("color 9C"); Sleep(50);
	system("color 9D"); Sleep(50);
	system("color 9E"); Sleep(50);
	system("color 9F"); Sleep(50);
	//浅红
	system("color CA"); Sleep(100);
	system("color CB"); Sleep(100);
	system("color CC"); Sleep(100);
	system("color CD"); Sleep(100);
	system("color CE"); Sleep(100);
	system("color CF"); Sleep(100);
	//蓝绿
	system("color BA"); Sleep(80);
	system("color BB"); Sleep(80);
	system("color BC"); Sleep(80);
	system("color BD"); Sleep(80);
	system("color BE"); Sleep(80);
	system("color BF"); Sleep(80);
	//浅黄
	system("color EA"); Sleep(60);
	system("color EB"); Sleep(60);
	system("color EC"); Sleep(60);
	system("color ED"); Sleep(60);
	system("color EE"); Sleep(60);
	system("color EF"); Sleep(60);
	//亮白
	system("color FA"); Sleep(40);
	system("color FB"); Sleep(40);
	system("color FC"); Sleep(40);
	system("color FD"); Sleep(40);
	system("color FE"); Sleep(40);
	system("color FF"); Sleep(40);
	}
	printf("\t\t\t\t送你一个小惊喜\n");
	printf("\t\t\t\t>>>");
	system("color BC");
	system("pause>NULL");
	printf("\n\n\n\t\t");
	while(1){
	for(i=1,a=I;i<I/2;i++,a--){
		for(j=(int) ( I-sqrt(I*I-(a-i)*(a-i)) );j>0;j--)
			printf(" ");
		for(e=1;e<=2*sqrt(I*I-(a-i)*(a-i));e++)
			printf("\3");
		for(j=(int)( 2*( I-sqrt(I*I-(a-i)*(a-i)) ) );j>0;j--)
			printf(" ");
		for(e=1;e<=2*sqrt(I*I-(a-i)*(a-i));e++)
			printf("\3");
		printf("\n\t\t");
		Sleep(10);
	}
	for(i=1;i<80;i++){
		if(i==25){
			printf("======陶佳慧，生日快乐！======");
		i+=30;
		}
	printf("\3");
	}
	printf("\n\t\t");
	for(i=1;i<=R/2;i++){
		if(i%2||i%3) continue;
		for(j=(int) ( R-sqrt(R*R-i*i) );j>0;j--)
			printf(" ");
		for(e=1;e<=2*( sqrt(R*R-i*i) - (R-2*I) );e++){
			printf("\3");
		}
	Sleep(100);
	printf("\n\t\t");
	}
}
}

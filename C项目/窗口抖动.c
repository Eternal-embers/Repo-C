#include <stdio.h>

#include <windows.h>

int main(int argc, char *argv[])

{

RECT rect; //RECT是一个矩形结构体，相当于保存了一个矩形的四条边的坐标

HWND hwnd = NULL,oldhwnd = NULL; //两个窗口句柄

int x,y,width,height; //用来保存窗口横纵坐标和宽度、高度的变量

int i;

for(i=0;i<50;i++)

{

hwnd = GetForegroundWindow(); //一个API函数，获取活动窗口的句柄

if(hwnd!=oldhwnd)

{

GetWindowRect(hwnd,&rect); //获取指定窗口的位置

x = rect.left;

y = rect.top;

width = rect.right - x;

height = rect.bottom - y;

oldhwnd = hwnd; //把刚刚获取的窗口句柄保存起来。

}

MoveWindow(hwnd,x-10,y,width,height,TRUE); //向左移动了10像素，下同

Sleep(5); //暂停5毫秒

MoveWindow(hwnd,x-10,y-10,width,height,TRUE);

Sleep(5);

MoveWindow(hwnd,x,y-10,width,height,TRUE);

Sleep(5);

MoveWindow(hwnd,x,y,width,height,TRUE);

Sleep(5);

}

return 0;

}

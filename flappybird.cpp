#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// 全局变量
int high,width; // 游戏画面大小
int bird_x,bird_y; // 小鸟的坐标// 全局变量

int zhangaiwuY=40;
int zhangaiwuDown,zhangaiwuTop; // 障碍物
int score=0;

void gotoxy(int x,int y)//类似于清屏函数
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void startup()  // 数据初始化
{
	high = 15;
	width = 40;
	bird_x = 0;
	bird_y = width/10;
	zhangaiwuY = 2*width/3;
	zhangaiwuTop = 2*high/3;
	zhangaiwuDown = high/3;
}

void show()  // 显示画面
{
	gotoxy(0,0);  // 清屏	
	int i,j;
	
	for (i=0;i<high;i++)
	{
		for (j=0;j<width;j++)
		{
			if ((i==bird_x) && (j==bird_y))
				printf("@");  //   输出小鸟
			else if(j==zhangaiwuY&&(i<zhangaiwuDown||i>zhangaiwuTop))
				printf("|");
			else
				printf(" ");  //   输出空格
		}
		printf("\n");
	}
	printf("您的得分为：%d",score);
}	

void updateWithoutInput()  // 与用户输入无关的更新
{
	bird_x ++;
	zhangaiwuY--;
	if(bird_x>15)
		{
			printf("游戏失败！！");
			system("pause");
			exit(0); 
		}
	if(bird_y==zhangaiwuY)
		{
			if(bird_x<zhangaiwuDown||bird_x>zhangaiwuTop)
				{
					printf("游戏失败！！");
					system("pause");
					exit(0); 
				}
			else
				score++;
		}
	if (zhangaiwuY==0)  // 再新生成一个障碍物
		{
			zhangaiwuY = width;
			int temp = rand()%int(high*0.8);
			zhangaiwuDown = temp - high/10;
			zhangaiwuTop = temp + high/10;
		}
	
	Sleep(150);
}

void updateWithInput()  // 与用户输入有关的更新
{	
	char input;
	if(kbhit())  // 判断是否有输入
	{
		input = getch();  // 根据用户的不同输入来移动，不必输入回车
		if (input == ' ')  
		{
			bird_x = bird_x - 2;
		}
		
	}
}

int main()
{
	startup();  // 数据初始化	
	while (1)  //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();     // 与用户输入有关的更新
	}
}

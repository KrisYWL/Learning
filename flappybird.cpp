#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// ȫ�ֱ���
int high,width; // ��Ϸ�����С
int bird_x,bird_y; // С�������// ȫ�ֱ���

int zhangaiwuY=40;
int zhangaiwuDown,zhangaiwuTop; // �ϰ���
int score=0;

void gotoxy(int x,int y)//��������������
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void startup()  // ���ݳ�ʼ��
{
	high = 15;
	width = 40;
	bird_x = 0;
	bird_y = width/10;
	zhangaiwuY = 2*width/3;
	zhangaiwuTop = 2*high/3;
	zhangaiwuDown = high/3;
}

void show()  // ��ʾ����
{
	gotoxy(0,0);  // ����	
	int i,j;
	
	for (i=0;i<high;i++)
	{
		for (j=0;j<width;j++)
		{
			if ((i==bird_x) && (j==bird_y))
				printf("@");  //   ���С��
			else if(j==zhangaiwuY&&(i<zhangaiwuDown||i>zhangaiwuTop))
				printf("|");
			else
				printf(" ");  //   ����ո�
		}
		printf("\n");
	}
	printf("���ĵ÷�Ϊ��%d",score);
}	

void updateWithoutInput()  // ���û������޹صĸ���
{
	bird_x ++;
	zhangaiwuY--;
	if(bird_x>15)
		{
			printf("��Ϸʧ�ܣ���");
			system("pause");
			exit(0); 
		}
	if(bird_y==zhangaiwuY)
		{
			if(bird_x<zhangaiwuDown||bird_x>zhangaiwuTop)
				{
					printf("��Ϸʧ�ܣ���");
					system("pause");
					exit(0); 
				}
			else
				score++;
		}
	if (zhangaiwuY==0)  // ��������һ���ϰ���
		{
			zhangaiwuY = width;
			int temp = rand()%int(high*0.8);
			zhangaiwuDown = temp - high/10;
			zhangaiwuTop = temp + high/10;
		}
	
	Sleep(150);
}

void updateWithInput()  // ���û������йصĸ���
{	
	char input;
	if(kbhit())  // �ж��Ƿ�������
	{
		input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
		if (input == ' ')  
		{
			bird_x = bird_x - 2;
		}
		
	}
}

int main()
{
	startup();  // ���ݳ�ʼ��	
	while (1)  //  ��Ϸѭ��ִ��
	{
		show();  // ��ʾ����
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();     // ���û������йصĸ���
	}
}

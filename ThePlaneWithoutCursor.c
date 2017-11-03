#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include <windows.h>

int position_x,position_y;
int high,width;
int bullet_x,bullet_y;
int enemy_x,enemy_y;
int score;

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}

void gotoxy(int x, int y)
{
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(handle,pos);
    return;
}
void starup()
{
	high=20;
	width=30;
	position_x=high/2;
	position_y=width/2;
	bullet_x=0;
	bullet_y=position_y;
	enemy_x=0;
	enemy_y=position_y;
	score=0;
}
void show()
{
	gotoxy(0,0);
	int i,j;
	for(i=0;i<high;i++)
	{
		for(j=0;j<width;j++)
		{
			if((i==position_x)&&(j==position_y))		//show the plane
				printf("*");
			else if((i==bullet_x)&&(j==bullet_y))		//show the bullet
                printf("s");
			else if((i==enemy_x)&&(j==enemy_y))
				printf("@");

			else
				printf(" ");
		}
		printf("\n");
	}
	printf("Your score is:%d",score);
}

void updateWithoutInput()
{
	if(bullet_x>-1)
		bullet_x--;
    static int speed=0;
    if(speed<10)
        speed++;
    if(speed==10)
    {
        enemy_x++;
        speed=0;
    }
    if((bullet_x==enemy_x)&&(bullet_y==enemy_y))
        score++;
    if(enemy_x>high)
    {
        enemy_x=-1;
        enemy_y=rand()%width;
    }
}

void updateWithInput()
{
	char input;
	if(kbhit())
	{
		input=getch();
		if(input=='w')
			position_x--;
		if(input=='s')
			position_x++;
		if(input=='a')
			position_y--;
		if(input=='d')
			position_y++;
		if(input==' ')
		{
			bullet_x=position_x-1;
			bullet_y=position_y;
		}
	}
}

int main()
{
    HideCursor();
	starup();
	while(1)
	{
		show();
		updateWithoutInput();
		updateWithInput();
	}
	return 0;
}

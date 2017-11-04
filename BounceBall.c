#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int high,width;
int ball_x,ball_y;
int ball_vx,ball_vy;
int position_x,position_y;
int ridus;
int left,right;
int score;

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}

void gotoxy(int x, int y) //定位到第y行的第x列
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
	high=15;
	width=30;
	ball_x=0;
	ball_y=width/2;
	ball_vx=1;
	ball_vy=1;
	ridus=5;
	position_x=high-2;
	position_y=width/2;
	left=position_y-ridus;
	right=position_y+ridus;
    score=0;
}
void show()
{
	gotoxy(0,0);
	int i,j;
	for(i=0;i<=high;i++)
	{
		for(j=0;j<=width;j++)
		{
			if((i==ball_x)&&(j==ball_y))		//show the plane
				printf("0");
            else if(j==width)
                printf("|");
            else if(i==high)
                printf("-");
            else if((i==position_x)&&(j>=left)&&(j<=right))
                printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
    printf("Your score is:%d",score);
}

void updateWithoutInput()
{
	ball_x=ball_x+ball_vx;
	ball_y=ball_y+ball_vy;
	if((ball_x==0)||/*(ball_x==high-1)||*/((ball_x==position_x-1)&&((ball_y<=right)&&(ball_y>=left))))
    {
		ball_vx=-ball_vx;
		if((ball_x==position_x-1)&&((ball_y<=right)&&(ball_y>=left)))
            score++;
    }
	if((ball_y==0)||(ball_y==width-1))
		ball_vy=-ball_vy;
    if(ball_x>high)
    {
        score--;

        ball_vx=1;
        ball_vy=1;
        ball_x=0;
        ball_y=width/2;
    }
	Sleep(140);
}

void updateWithInput()
{
    char input;
    if(kbhit())
    {
        input=getch();
        if(input=='a')
        {
            position_y--;
            left=position_y-ridus;
            right=position_y+ridus;
        }
        if(input=='d')
        {
            position_y++;
            left=position_y-ridus;
            right=position_y+ridus;
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

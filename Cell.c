#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

#define High 25
#define Width 50

int cells[High][Width];

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
	int i,j;
	for(i=0;i<High;i++)
	{
		for(j=0;j<Width;j++)
		{
			cells[i][j]=1;
		}
	}
}

void show()
{
	gotoxy(0,0);
	int i,j;
	for(i=0;i<=High;i++)
	{
		for(j=0;j<=Width;j++)
		{
			if(cells[i][j]==1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	Sleep(50);
}

void updateWithoutInput()
{
	int Next[High][Width];
	int Num=0;
    int i;
    int j;

	for(i=1;i<High;i++)
		for(j=1;j<Width;j++)
		{
			Num=cells[i-1][j-1]+cells[i-1][j]+cells[i][j-1]+cells[i+1][j]+cells[i+1][j+1]+cells[i+1][j-1]+cells[i-1][j+1]+cells[i][j+1];
			if(Num==3)
				Next[i][j]=1;
			else if(Num==2)
				Next[i][j]=cells[i][j];
			else
				Next[i][j]=0;
		}

	for(i=1;i<High;i++)
		for(j=1;j<Width;j++)
		{
			cells[i][j]=Next[i][j];
		}

}

void updateWithInput()
{

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



























#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#pragma comment(lib,"Winmm.lib")


IMAGE img_bk,img_bd1,img_bd2,img_bar_up1,img_bar_up2,img_bar_down1,img_bar_down2;
int bird_x;
int bird_y;
int bar_x;
int bar_y;

void startup()
{
	initgraph(350,600);
	loadimage(&img_bk,"D:\\GameWithC\\heida.jpg");
	loadimage(&img_bd1,"D:\\GameWithC\\bird1.jpg");
	loadimage(&img_bd2,"D:\\GameWithC\\bird2.jpg");
	loadimage(&img_bar_up1,"D:\\GameWithC\\bar_up1.gif");
	loadimage(&img_bar_up2,"D:\\GameWithC\\bar_up2.gif");
	loadimage(&img_bar_down1,"D:\\GameWithC\\bar_down1.gif");
	loadimage(&img_bar_down2,"D:\\GameWithC\\bar_down2.gif");
	bird_x=50;
	bird_y=200;
	bar_x=300;
	bar_y=300;
	BeginBatchDraw();
	
	mciSendString("open D:\\GameWithC\\background.mp3 alias bkmusic",NULL,0,NULL);
	mciSendString("play bkmusic repeat",NULL,0,NULL);
}

void show()
{
	putimage(0,0,&img_bk);
	putimage(bar_x,bar_y-700,&img_bar_up1,NOTSRCERASE);
	putimage(bar_x,bar_y-700,&img_bar_up2,SRCINVERT);
	putimage(bar_x,bar_y,&img_bar_down1,NOTSRCERASE);
	putimage(bar_x,bar_y,&img_bar_down2,SRCINVERT);
	putimage(bird_x,bird_y,&img_bd1,NOTSRCERASE);
	putimage(bird_x,bird_y,&img_bd2,SRCINVERT);
	FlushBatchDraw();
	Sleep(50);
}

void updateWithoutInput()
{
	if(bird_y<580)
		bird_y=bird_y+3;
	bar_x=bar_x-5;
	if(bar_x<-125)
	{
		int temp=rand()%500;
		temp=temp+100;
		bar_y=temp;
		bar_x=350;
	}
	if(bird_x>=bar_x-18&&bird_x<=bar_x+50)
		if((bird_y>=bar_y&&bird_y<600)||(bird_y<bar_y-100&&bird_y>0))
		{
			printf("Failed!!");
			system("pause");
			exit(0);
		}
	if(bird_y<20)
	{
		printf("Failed!!");
		system("pause");
		exit(0);
	}
}

void updateWithInput()
{
	char input;
	if(kbhit())
	{
		input=getch();
		if(input==' '&&bird_y>20)
		{
			bird_y=bird_y-40;
			mciSendString("close jpmusic",NULL,0,NULL);
			mciSendString("open D:\\GameWithC\\Jump.mp3 alias jpmusic",NULL,0,NULL);
			mciSendString("play jpmusic",NULL,0,NULL);
		}
	}
}

void gameover()
{
	EndBatchDraw();
	getch();
	closegraph();
	
}

int main()
{
	startup();
	while(1)
	{
		show();
		updateWithoutInput();
		updateWithInput();
	}
	gameover();
	return 0;
}
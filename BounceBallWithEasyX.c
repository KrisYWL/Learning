#include<graphics.h>
#include<conio.h>
#define High 480
#define Width 640

int main()
{
	float ball_x,ball_y;
	float ball_vx,ball_vy;
	float radius;
	
	initgraph(Width,High);
	ball_x=Width/2;
	ball_y=High/2;
	ball_vx=1;
	ball_vy=1;
	radius=20;
	
	while(1)
	{
		if(getch())
			break;
		setcolor(black);
		setfillcolor(black);
		fillcircle(ball_x,ball_y,radius);
		
		ball_x=ball_x+ball_vx;
		ball_y=ball_y+ball_vy;
		
		if((ball_x<=radius)||(ball_x>=Width-radius))
			ball_vx=-ball_vx;
		if((ball_y<=radius)||(ball_y>=High-radius))
			ball_vy=-ball_vy;
		
		setcolor(yellow);
		setfillcolor(green);
		fillcircle(ball_x,ball_y,radius);
		Sleep(3);
		
	}
	closegraph();
	return 0;
}
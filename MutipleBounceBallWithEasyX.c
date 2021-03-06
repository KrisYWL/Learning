#include<graphics.h>
#include<conio.h>
#define High 480
#define Width 640
#define BallNum 5

int main()
{
	float ball_x[BallNum],ball_y[BallNum];
	float ball_vx[BallNum],ball_vy[BallNum];
	float radius;
	int i;
	radius =20;
	
	for(i=0;i<BallNum;i++)
	{
		ball_x[i]=(i+2)*radius*3;
		ball_y[i]=High/2;
		ball_vx[i]=1;
		ball_vy[i]=1;
	}
	initgraph(Width,High);
	BeginBatchDraw();
	
	while(1)
	{
		setcolor(BLACK);
		setfillcolor(BLACK);
		for(i=0;i<BallNum;i++)
			fillcircle(ball_x[i],ball_y[i],radius);
		
		for(i=0;i<BallNum;i++)
		{
			ball_x[i]=ball_x[i]+ball_vx[i];
			ball_y[i]=ball_y[i]+ball_vy[i];
		}

		for(i=0;i<BallNum;i++)
		{
			if((ball_x[i]<=radius)||(ball_x[i]>=Width-radius))
				ball_vx[i]=-ball_vx[i];
			if((ball_y[i]<=radius)||(ball_y[i]>=High-radius))
				ball_vy[i]=-ball_vy[i];
		}
		setcolor(YELLOW);
		setfillcolor(GREEN);
		for(i=0;i<BallNum;i++)
		{
			fillcircle(ball_x[i],ball_y[i],radius);
			
		}
		FlushBatchDraw();
		Sleep(3);
		
	}
	EndBatchDraw();
	closegraph();
	return 0;
}
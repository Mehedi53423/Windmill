#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void wind(float x[7],float y[7]);

void main()
{
	int gd=DETECT,gm;
	float x[7],y[7],maxx,maxy,xw1,yw1,xw2,yw2;
	float theta=30;

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	maxx=getmaxx();
	maxy=getmaxy();

	x[0]=maxx/2;
	y[0]=maxy/2;
	x[1]=y[4]=x[2]=-90;
	y[6]=y[5]=y[1]=60;
	y[2]=35;
	y[3]=-100;
	x[4]=20;
	x[3]=0;
	x[5]=90;
	x[6]=65;

	theta=theta*22/7/180;

	while(kbhit()==0)
	{
		wind(x,y);

		xw1=cos(theta)*x[1]+sin(theta)*y[1];
		yw1=-sin(theta)*x[1]+cos(theta)*y[1];
		xw2=cos(theta)*x[2]+sin(theta)*y[2];
		yw2=-sin(theta)*x[2]+cos(theta)*y[2];

		x[1]=xw1;
		y[1]=yw1;
		x[2]=xw2;
		y[2]=yw2;

		xw1=cos(theta)*x[3]+sin(theta)*y[3];
		yw1=-sin(theta)*x[3]+cos(theta)*y[3];
		xw2=cos(theta)*x[4]+sin(theta)*y[4];
		yw2=-sin(theta)*x[4]+cos(theta)*y[4];

		x[3]=xw1;
		y[3]=yw1;
		x[4]=xw2;
		y[4]=yw2;

		xw1=cos(theta)*x[5]+sin(theta)*y[5];
		yw1=-sin(theta)*x[5]+cos(theta)*y[5];
		xw2=cos(theta)*x[6]+sin(theta)*y[6];
		yw2=-sin(theta)*x[6]+cos(theta)*y[6];

		x[5]=xw1;
		y[5]=yw1;
		x[6]=xw2;
		y[6]=yw2;

		delay(75);
		cleardevice();

	}

	closegraph();
	getch();
}

void wind(float x[7],float y[7])
{
	cleardevice();

	line(x[0],y[0],x[0]-50,y[0]+200);
	line(x[0],y[0],x[0]+50,y[0]+200);
	line(x[0]-60,y[0]+200,x[0]+60,y[0]+200);
	line(x[0],y[0],x[0]+x[1],y[0]-y[1]);
	line(x[0],y[0],x[0]+x[2],y[0]-y[2]);
	line(x[0]+x[1],y[0]-y[1],x[0]+x[2],y[0]-y[2]);
	line(x[0],y[0],x[0]+x[3],y[0]-y[3]);
	line(x[0],y[0],x[0]+x[4],y[0]-y[4]);
	line(x[0]+x[3],y[0]-y[3],x[0]+x[4],y[0]-y[4]);
	line(x[0],y[0],x[0]+x[5],y[0]-y[5]);
	line(x[0],y[0],x[0]+x[6],y[0]-y[6]);
	line(x[0]+x[5],y[0]-y[5],x[0]+x[6],y[0]-y[6]);
}
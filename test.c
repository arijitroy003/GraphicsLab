#include <graphics.h>
#include <stdio.h>
int main()
{
	int gd = DETECT;
	int gm,i;
	int max_x,max_y;
	initgraph(&gd,&gm,"");
	for (i = 20; i < 100; ++i)
	{
		my_(i,i,WHITE);		
	}
	my_(110,300,WHITE);
	getch();
	closegraph();
}
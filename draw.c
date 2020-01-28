#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>

#define crosshair 5
int RES;

void my_putpixel(int x,int y,int colour){
	int i,j;
	for (i = x; i <= x+RES; ++i)
	{
		for (j = y; j <= y+RES; ++j)
		{
			// i=i%639;
			// j=j%479;
			putpixel(i,j,colour);
		}
	}
}

void draw_shooter(int x,int y,int length){
	int i;
	for (i = 1; i < length; ++i)
	{
		my_putpixel(x+i*RES,y,RED);
		my_putpixel(x-i*RES,y,RED);
		my_putpixel(x,y-i*RES,RED);
		my_putpixel(x,y+i*RES,RED);
	}
	my_putpixel(x,y,BLACK);
}

void DDA(int X0, int Y0, int X1, int Y1) 
{ 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    float X = X0; 
    float Y = Y0; 
	int i;
    for(i = 0; i <= steps; i++) 
    { 
        putpixel(X,Y,WHITE);   
        X += Xinc;            
        Y += Yinc;            
        delay(10);          // for animation
    } 
}

int main()
{
	system("clear");
	int gd = DETECT;
	int gm,i,j,k;
	int max_x,max_y;
	int x1,y1,x2,y2;

				printf("Enter Co-ordinate 1 : ");
				scanf("%d %d",&x1,&y1);
				printf("Enter Co-ordinate 2 : ");
				scanf("%d %d",&x2,&y2);

				initgraph(&gd,&gm,"");

				draw_shooter(x1,y1,crosshair);
				draw_shooter(x2,y2,crosshair);
				
				DDA(x1,y1,x2,y2);
				getch();

				closegraph();
    
}
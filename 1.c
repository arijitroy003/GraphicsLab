#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>

#define crosshair 5
int RES=1;

void my_putpixel(int x,int y,int colour){
	int i,j;
	for (i = x; i <= x+RES; ++i)
	{
		for (j = y; j <= y+RES; ++j)
		{
			i=i%639;
			j=j%479;
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
        my_putpixel(X,Y,WHITE);   
        X += Xinc;            
        Y += Yinc;            
        delay(5);          // for animation
    } 
} 

void bresenham(int x1, int y1, int x2, int y2) 
{ 
   int m_new = 2 * (y2 - y1);
   int x,y; 
   int slope_error_new = m_new - (x2 - x1); 
   for (x = x1, y = y1; x <= x2; x++) 
   { 
		my_putpixel(x,y,WHITE);
		delay(5);

		slope_error_new += m_new; 
  
		if (slope_error_new >= 0) { 
        	y++; 
        	slope_error_new  -= 2 * (x2 - x1); 
		} 
   } 
} 

int main()
{
	system("clear");
	int gd = DETECT;
	int gm,i,j,k;
	int max_x,max_y;
	int x1,y1,x2,y2;
	int choice=99;
	int pixel_size;
	while (choice)
	{
		printf("\n1. Set Pixel Size\n2. Animate Cursor\n");
		printf("3. Set two cursor & draw DDA line\n");
		printf("4. Set two cursor & draw Bresenhem line\n");
		printf("5. Draw circle using\n");
		printf("6. Draw circle using\n");
		printf("\n\tEnter your choice :");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				scanf("%d",&RES);
				// #undef RES
				// #define RES pixel_size
				break;
			case 2:
				k=100;
				while(k){
					x1=rand()%639;
					x2=rand()%639;
					y1=rand()%479;
					y2=rand()%479;

					initgraph(&gd,&gm,"");

					draw_shooter(x1,y1,crosshair);
					draw_shooter(x2,y2,crosshair);
					
					DDA(x1,y1,x2,y2);
					k--;
					delay(1000);
					cleardevice();
				}
				delay(10000);
				getch();

				closegraph();
				break;
			case 3: //DDA

				printf("Enter Co-ordinate 1 : ");
				scanf("%d %d",&x1,&y1);
				printf("Enter Co-ordinate 2 : ");
				scanf("%d %d",&x2,&y2);

				initgraph(&gd,&gm,"");

				draw_shooter(x1,y1,crosshair);
				draw_shooter(x2,y2,crosshair);
				
				DDA(x1,y1,x2,y2);
				// delay(5000);
				getch();

				closegraph();
				break;
			case 4: //Bresenhem
				
				printf("Enter Co-ordinate 1 : ");
				scanf("%d %d",&x1,&y1);
				printf("Enter Co-ordinate 2 : ");
				scanf("%d %d",&x2,&y2);

				initgraph(&gd,&gm,"");

				draw_shooter(x1,y1,crosshair);
				draw_shooter(x2,y2,crosshair);
				
				bresenham(x1,y1,x2,y2);
				// delay(5000);
				getch();

				closegraph();
				break;
			default:
				choice=0;
				break;
		}		
	}
	// printf("%d\n",getmaxy());
}
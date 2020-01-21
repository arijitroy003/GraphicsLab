#include <graphics.h>
#include <stdio.h>

#define crosshair 5
#define RES 5


void DDA(int X0, int Y0, int X1, int Y1) 
{ 
    // calculate dx & dy 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    // Put pixel for each step 
    float X = X0; 
    float Y = Y0; 
	int i;
    for(i = 0; i <= steps; i++) 
    { 
        putpixel(X,Y,WHITE);  // put pixel at (X,Y) 
        X += Xinc;           // increment in x at each step 
        Y += Yinc;           // increment in y at each step 
        delay(10);          // for visualization of line- 
                             // generation step by step 
    } 
} 

void my_putpixel(int x,int y,int colour){
	int i,j;
	for (i = x; i <= x+RES; ++i)
	{
		for (j = y; j <= y+RES; ++j)
		{
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



int main()
{
	int gd = DETECT;
	int gm,i,j;
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
	// printf("%d\n",getmaxy());
	delay(10000);
	getch();
	
	closegraph();
}
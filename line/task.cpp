#include "task.h"
#include <iostream>
#include "graphics.h"

using namespace std;

Point arr_p[4];  

Point vPoint;


void getpoint(int width, int height)
{
   setfillstyle (SOLID_FILL, WHITE);
   setcolor(WHITE);
   settextstyle(GOTHIC_FONT,0,1);
   int x,y,r=4;
   for (int i=0, k = 1; i<4; i++, k++) 
{
   while (1) 
   {
      x=mousex();
      y=mousey();
   if (mousebuttons() && y<height - 50 && y > 50) 
      {
      delay(10);
      if (!mousebuttons()) 
       {
       arr_p[i] ={x,y};
       outtextxy(width - 50,0,to_string(x).c_str());
       outtextxy(width - 50,25,to_string(y).c_str());
       outtextxy(width - 50,height-150,to_string(k).c_str());
       fillellipse(x,y,r,r);
       break;
       }
      }
   }
}
}

Point Point_bezie (Point p1, Point p2, Point p3, Point p4, double t)
{
double var1 ,var2 ,var3;

var1 = 1 - t;

var2 = var1 * var1 * var1;
   
var3 = t * t * t;
   
vPoint.x = var2*p1.x + 3*t*var1*var1*p2.x + 3*t*t*var1*p3.x + var3*p4.x;
vPoint.y = var2*p1.y + 3*t*var1*var1*p2.y + 3*t*t*var1*p3.y + var3*p4.y;
   
return vPoint;
}

void bezier()
{
   setcolor(YELLOW);
   moveto(arr_p[0].x,arr_p[0].y);
   for(double t = 0; t <= 1 ; t += 0.001)
  {
   vPoint = Point_bezie (arr_p[0], arr_p[1],arr_p[2] ,arr_p[3], t);
   lineto(vPoint.x, vPoint.y);
  }
}

void chaiykin()
{
   setcolor(RED);
   int N_line=3;
   int P=4;
   int iterat = 7;
   int *x = new int[P];
   int *y = new int[P];
   
   for (int i = 0; i < P;i++)
   {
   x[i]= arr_p[i].x;
   y[i] = arr_p[i].y;
   }
   int  *nx,*ny;
   for (int i=0; i<iterat; i++) 
   {
      nx=new int[2*N_line];
      ny=new int[2*N_line];

      for (int j=0,k=0; k<N_line; j++,k++) 
      {
         nx[j]=x[k]*0.75+x[k+1]*0.25;
         ny[j]=y[k]*0.75+y[k+1]*0.25;
         
         j++;
         
         nx[j]=x[k]*0.25+x[k+1]*0.75;
         ny[j]=y[k]*0.25+y[k+1]*0.75;
      }
      delete []x;
      delete []y;
      x=nx;
      y=ny;
      P=N_line*2;
      N_line=P-1;
    }
    
   moveto(arr_p[0].x,arr_p[0].y);
   lineto(x[0],y[0]);
   for (int i=0; i<N_line; i++)
    {
   moveto(x[i],y[i]);
   lineto(x[i+1],y[i+1]);
    }
   moveto(x[N_line],y[N_line]);
   lineto(arr_p[3].x,arr_p[3].y);
   delete []x;
   delete []y;
}


void save()
{
   int width, height;
   IMAGE *output;

   width  = getmaxx() + 1;
   height = getmaxy() + 1;
   output = createimage(width, height);

   getimage(0, 0, width - 1, height - 1, output);
   saveBMP("output.bmp", output);
   freeimage(output);
}


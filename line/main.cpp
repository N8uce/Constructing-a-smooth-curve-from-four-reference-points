#include "graphics.h"
#include "control.h"
#include "task.h"


int main()
{
   int left = 0, top = 0, width = 800, height = 800;
   initwindow(width,height);
   create_control(CLEAR,   149, 0, "clear.bmp");
   create_control(GDOTS,   0, 0, "gdots.bmp");
   create_control(UP_BAR,   0, 50, "shtorka.bmp");
   create_control(BEZIER,   0, height -50, "bezier.bmp");
   create_control(CHAYIKIN,  200,height -50, "chaiykin.bmp");
   create_control(SAVE,   400, height -50, "save.bmp");
   create_control(EXIT,    600, height -50, "exit.bmp");
   
   while (1)
   {
      while (mousebuttons() != 1);
      switch (select_control())
      {
      case NONE:break;
      case GDOTS:getpoint(width,height);break;
      case CLEAR:setfillstyle (SOLID_FILL, BLACK); 
      bar(left,height-50,width, height- 700);break;
      case BEZIER:bezier();break;
      case CHAYIKIN:chaiykin();break;
      case SAVE:save();break;
      case EXIT:closegraph();return 0;
      }
   }
}
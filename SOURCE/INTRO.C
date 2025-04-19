#include <ALLFUNS.h>

void intro_book(void)
{
    SaveBMP(0,0,1024,768,10);
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        {
            if (mouse_press(0,0,1024,768)==1)
            {
                return;
            }
        }
    }
}

void draw_introbook(int page)
{
    btn_bar_Draw(30,30,500,738);
    btn_bar_Draw(500,30,970,738);
}
#include <common.h>
#include <game.h>
#include<ORDFUNS.h>
#include<WRKMNG.h>
#include<WRKPLC.h>

void wrkmng_add_place(int* fpage1,int*placetemp)
{
    int i,j,k;
    int plcchs[5][4]={
        {200,230,240,260},
        {363,335,403,365},
        {600,260,640,290},
        {770,205,810,235},
        {900,345,940,375}
    };
    //BTN_BAR sure={"确定",0,0,387,675,637,725};
    //BTN_BAR backbtn={"返回",0,0,50,50,150,90};
    Readbmp64k(0,0,"PICTURE\\map.bmp");
    bar(0,625,1023,768,27469);
    //backprt(&backbtn);
    for(i=0;i<=4;i++)
        btn_bar_Draw(plcchs[i][0],plcchs[i][1],plcchs[i][2],plcchs[i][3]);
    //backprt(&backbtn);
    sureprt(0);
    k=0;
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        for(j=0;j<=4;j++)
        {
            if(mouse_press(plcchs[j][0],plcchs[j][1],plcchs[j][2],plcchs[j][3])==1)
            {
                for(i=0;i<=4;i++)btn_bar_Draw(plcchs[i][0],plcchs[i][1],plcchs[i][2],plcchs[i][3]);
                btn_bar_Draw0(plcchs[j][0],plcchs[j][1],plcchs[j][2],plcchs[j][3]);
                sureprt(1);
                k=j+1;
            }
        }
        if(k!=0)
        {
            if(mouse_press(387,675,637,725)==1)
            {
                *placetemp=k;
                *fpage1=1;
                return;
            }
        }
        /*if(mouse_press(backbtn.x1,backbtn.y1,backbtn.x2,backbtn.y2)==1)
        {
            *fpage1=1;
            *placetemp=0;
            return;
        }*/
    }
}
//绘制确定按钮
void sureprt(int i)
{
    if(i==0)
    {
        btn_bar_Draw1(387,675,637,725);
        put_hz24(387,700,"确定",0,"HZK\\HZK24",0);
    }
    if(i==1)
    {
        btn_bar_Draw(387,675,637,725);
        put_hz24(387,700,"完成",0,"HZK\\HZK24",0);
    }
}
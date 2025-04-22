#include<common.h>
#include<ORDFUNS.h>
#include<START.h>
#include<mouse.h>
//开始界面函数
void start(int *fpage)
{
    /*BTN_BAR prjbtn={"项目管理",0,0,312,360,712,400};
    BTN_BAR intrbtn={"说明",0,0,312,454,712,494};
    BTN_BAR quitbtn={"退出",0,0,312,544,712,586};*/
    clrmous(MouseX,MouseY);
    Readbmp64k(0,0,"PICTURE\\WLCMpage.bmp");
    //bar(0,0,1024,768,65535);
    /*画按钮*/
    btn_bar_Draw(312,360,712,400);
    put_hz24(312+140,370-8,"项目管理",0,"HZK\\HZK24",0);
    btn_bar_Draw(312,454,712,494);
    put_hz24(312+160,474-10,"说明",0,"HZK\\HZK24",0);
    btn_bar_Draw(312,544,712,586);
    put_hz24(312+160,565-10,"退出",0,"HZK\\HZK24",0);

    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);

        if(mouse_press(312,544,712,586)==1)
        {
            *fpage=0;
            return;
        }//返回
        if(mouse_press(312,360,712,400)==1)
        {
            *fpage=4;
            return;
        }//进入项目管理
    }

}
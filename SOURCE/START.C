#include<common.h>
#include<ORDFUNS.h>
#include<START.h>
//��ʼ���溯��
void start(int *fpage)
{
    /*BTN_BAR prjbtn={"��Ŀ����",0,0,312,360,712,400};
    BTN_BAR intrbtn={"˵��",0,0,312,454,712,494};
    BTN_BAR quitbtn={"�˳�",0,0,312,544,712,586};*/
    Readbmp64k(0,0,"PICTURE\\WLCMpage.bmp");
    //bar(0,0,1024,768,65535);
    /*����ť*/
    btn_bar_Draw(312,360,712,400);
    put_hz24(312+10,370+3,"��Ŀ����",0,"HZK\\HZK24",0);
    btn_bar_Draw(312,454,712,494);
    put_hz24(312+35,474+3,"˵��",0,"HZK\\HZK24",0);
    btn_bar_Draw(312,544,712,586);
    put_hz24(312+20,565+3,"�˳�",0,"HZK\\HZK24",0);

    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);

        if(mouse_press(312,544,712,586)==1)
        {
            *fpage=0;
            return;
        }//����
        if(mouse_press(312,360,712,400)==1)
        {
            *fpage=4;
            return;
        }//������Ŀ����
    }

}
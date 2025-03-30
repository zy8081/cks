#include<hz.h>
#include<mouse.h>
#include<stdlib.h>
#include<ORDFUNS.h>
#include<WRKMNG.h>
//#include<ALLFUNS.h>
#include<WRKADD.h>
#include<stdio.h>
//选择地点函数
int wrkmng_add_place(int *placetemp)
{
    int i,j,k;
    BTN_BAR plcchs[5]={
        {"奥林匹亚山",0,0,200,230,240,260},
        {"水手大峡谷",0,0,363,335,403,365},
        {"阿拉伯高地",0,0,600,260,640,290},
        {"乌托邦平原",0,0,770,205,810,235},
        {"埃律西昂平原",0,0,900,345,940,375}
    };
    BTN_BAR sure={"确定",0,0,387,675,637,725};
    //BTN_BAR backbtn={"返回",0,0,50,50,150,90};
    clrmous(MouseX,MouseY);
    Readbmp64k(0,0,"C:\\new\\PICTURE\\map.bmp");
    bar(0,625,1023,768,27469);
    //backprt(&backbtn);
    for(i=0;i<=4;i++)btn_bar_Draw(plcchs[i]);
    //backprt(&backbtn);
    sureprt(&sure,0);
    k=0;
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        for(j=0;j<=4;j++)
        {
            if(mouse_press(plcchs[j].x1,plcchs[j].y1,plcchs[j].x2,plcchs[j].y2)==1)
            {
                for(i=0;i<=4;i++)btn_bar_Draw(plcchs[i]);
                btn_bar_Draw0(plcchs[j]);
                sureprt(&sure,1);
                k=j+1;
            }
        }
        if(k!=0)
        {
            if(mouse_press(sure.x1,sure.y1,sure.x2,sure.y2)==1)
            {
                *placetemp=k;
                return 1;

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
void sureprt(BTN_BAR*psure,int i)
{
    if(i==0)
    {
        btn_bar_Draw1(*psure);
        hzplace(psure,32,32);
        put_hz24(psure->xinf,psure->yinf+3,psure->inf,0,"C:\\new\\HZK\\HZK24",0);
    }
    if(i==1)
    {
        btn_bar_Draw(*psure);
        hzplace(psure,32,32);
        put_hz24(psure->xinf,psure->yinf+3,psure->inf,0,"C:\\new\\HZK\\HZK24",0);
    }
}
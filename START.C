#include<SVGA.h>
#include<hz.h>
#include<mouse.h>
#include<stdlib.h>
#include<ORDFUNS.h>
#include<START.h>
//开始界面函数
int start(void)
{
	
    BTN_BAR prjbtn={"项目管理",0,0,312,360,712,400};
    BTN_BAR intrbtn={"说明",0,0,312,454,712,494};
    BTN_BAR quitbtn={"退出",0,0,312,544,712,586};
	
    clrmous(MouseX,MouseY);
	delay(300); 
	cleardevice();
	
    Readbmp64k(0,0,"C:\\new\\PICTURE\\WLCMpage.bmp");
    /*画按钮*/
	
	
    btn_bar_Draw(prjbtn);
    hzplace(&prjbtn,32,32);
    put_hz24(prjbtn.xinf+10,prjbtn.yinf+3,prjbtn.inf,0,"C:\\new\\HZK\\HZK24",0);
    btn_bar_Draw(intrbtn);
    hzplace(&intrbtn,32,32);
    put_hz24(intrbtn.xinf+35,intrbtn.yinf+3,intrbtn.inf,0,"C:\\new\\HZK\\HZK24",0);
    btn_bar_Draw(quitbtn);
    hzplace(&quitbtn,32,32);
    put_hz24(quitbtn.xinf+20,quitbtn.yinf+3,quitbtn.inf,0,"C:\\new\\HZK\\HZK24",0);
   

    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(quitbtn.x1,quitbtn.y1,quitbtn.x2,quitbtn.y2)==1)
        {
            return 1;
        }//返回登录界面
        if(mouse_press(prjbtn.x1,prjbtn.y1,prjbtn.x2,prjbtn.y2)==1)
        {
            return 4;
        }//进入项目管理
    }

}
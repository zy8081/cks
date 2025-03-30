#include<SVGA.h>
#include<hz.h>
#include<mouse.h>
#include<stdlib.h>
#include<ORDFUNS.h>
#include<WRKMNG.h>
//#include<ALLFUNS.h>
#include<WRKADD.h>

int wrkmng_main()//仿照MAIN实现的项目管理换页主程序
{
    int page1=0;
	int fpage=4;
    int i;
    int placetemp=0;
    char*nametemp;
	
	clrmous(MouseX,MouseY); //关键一句
	
        if(nametemp==NULL)
        /*{
            printf("No enough memory");
            getch();
            return;
        }*/
	
    while(fpage!=3)
    {
        switch(page1)
        {
            case 0:
                //free(nametemp);
				
                nametemp=malloc((size_t)11);
                for(i=0;i<=10;i++)nametemp[i]='\0';
                page1=wrkmng_menu();
                break;
            case 1:
            if(nametemp==NULL)
            {
                printf("No enough memory");
                getch();
                return 1;
            }
                page1=wrkmng_add(&placetemp,&nametemp);
                break;
            case 2:
                page1=wrkmng_add_place(&placetemp);
                break;
            case 3:
                fpage=3;
                break;

        }
    }
    return fpage;
}

int wrkmng_menu()//菜单页绘制及基本操作
{
    int form=0;
    BTN_BAR backbtn={"返回",0,0,50,50,150,90};
    BTN_BAR addbtn={"新建项目",0,0,842,110,962,160};
    BTN_BAR openbtn={"打开项目",0,0,842,190,962,240};
    BTN_BAR dltbtn={"删除项目",0,0,842,270,962,320};
    BTN_BAR exchbtn={"换序",0,0,842,350,962,400};
	
    //clrmous(MouseX,MouseY);
	
    delay(100);
    Readbmp64k(0,0,"C:\\new\\PICTURE\\WLCMpage.bmp");
    title1prt();
    menuprt(202,100,802,700);
    btn_bar_Draw(backbtn);
    hzplace(&backbtn,32,32);
    put_hz24(70,56,"返回",0,"C:\\new\\HZK\\HZK24",0);
    addprt(&addbtn);
    openprt(&openbtn,form);
    dltprt(&dltbtn,form);
    exchprt(&exchbtn,form);
    
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(backbtn.x1,backbtn.y1,backbtn.x2,backbtn.y2)==1)
        {
            return 3;
        }
        if(mouse_press(addbtn.x1,addbtn.y1,addbtn.x2,addbtn.y2)==1)
        {
            return 1;
        }
        
    }
}
/*下面皆是画按钮和标题 */
void title1prt()
{
    BTN_BAR title1={"项目管理",0,0,412,35,612,75};
    btn_bar_Draw(title1);
    hzplace(&title1,32,32);
    put_hz24(title1.xinf+10,title1.yinf+3,"项目管理",0,"C:\\new\\HZK\\HZK24",0);
}

void backprt(BTN_BAR* pbackbtn)
{
    btn_bar_Draw(*pbackbtn);
    hzplace(pbackbtn,32,32);
    put_hz24(pbackbtn->xinf+20,pbackbtn->yinf+3,"返回",0,"C:\\new\\HZK\\HZK24",0);
}

void addprt(BTN_BAR* paddbtn)
{
    btn_bar_Draw(*paddbtn);
    hzplace(paddbtn,32,32);
    put_hz24(852,120,"新建项目",0,"C:\\new\\HZK\\HZK24",0);
}

void openprt(BTN_BAR* popenbtn,int form)
{
    if(form==0)
    {
        btn_bar_Draw1(*popenbtn);
        hzplace(popenbtn,32,32);
        put_hz24(popenbtn->xinf,popenbtn->yinf+3,"打开项目",0,"C:\\new\\HZK\\HZK24",0);
    }
    else
    {
        btn_bar_Draw(*popenbtn);
        hzplace(popenbtn,32,32);
        put_hz24(popenbtn->xinf,popenbtn->yinf+3,"打开项目",0,"C:\\new\\HZK\\HZK24",0);        
    }
}

void dltprt(BTN_BAR* pdltbtn,int form)
{
    if(form==0)
    {
        btn_bar_Draw1(*pdltbtn);
        hzplace(pdltbtn,32,32);
        put_hz24(pdltbtn->xinf+30,pdltbtn->yinf+3,"删除项目",0,"C:\\new\\HZK\\HZK24",0);
    }
    else
    {
        btn_bar_Draw(*pdltbtn);
        hzplace(pdltbtn,32,32);
        put_hz24(pdltbtn->xinf+30,pdltbtn->yinf+3,"删除项目",0,"C:\\new\\HZK\\HZK24",0);
    }    
}

void exchprt(BTN_BAR* pexchbtn,int form)
{
    if(form==0)
    {
        btn_bar_Draw1(*pexchbtn);
        hzplace(pexchbtn,32,32);
        put_hz24(pexchbtn->xinf+5,pexchbtn->yinf+3,"换序",0,"C:\\new\\HZK\\HZK24",0);
    }
    else
    {
        btn_bar_Draw(*pexchbtn);
        hzplace(pexchbtn,32,32);
        put_hz24(pexchbtn->xinf+5,pexchbtn->yinf+3,"换序",0,"C:\\new\\HZK\\HZK24",0);
    }
    
}

/*void drawwork(FILEWORK)
{

}*/
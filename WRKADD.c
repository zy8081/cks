#include<hz.h>
#include<mouse.h>
#include<stdlib.h>
#include<ORDFUNS.h>
#include<WRKMNG.h>
#include<WRKADD.h>
#include<stdio.h>
#include<direct.h>

/*新建项目函数部分，fpage1表示项目管理中的页数，
pplacenum为指向地点的指针，pname0为指向项目名称的数组指针*/
int wrkmng_add(int* pplacenum,char*(pname0[]))
{
    int i;
    BTN_BAR backbtn={"返回",0,0,50,50,150,90};
    //BTN_BAR title={"新建项目",0,0,50,50,150,90};
    BTN_BAR place={"选择地点",0,0,240,280,400,330};
    BTN_BAR compbtn={"完成",0,0,442,420,582,480};
    WORKFILE filetemp={"\0",0,"\0"};
    //*pplacenum=0;
    //strcpy(*pname0,"sssss");
    clrmous(MouseX,MouseY);
    Readbmp64k(0,0,"C:\\new\\PICTURE\\WLCMpage.bmp");
    backprt(&backbtn);
    title2prt();
    menuprt(202,100,802,600);
    nameprt(*pname0);
    placeprt(&place,*pplacenum);
    compprt(&compbtn);
    
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(backbtn.x1,backbtn.y1,backbtn.x2,backbtn.y2)==1)
        {
            *pplacenum=0;
            strcpy(*pname0,"\0");
            //*fpage1=0;
            return 0;//重置*pname0的值，
        }
        if(mouse_press(place.x1,place.y1,place.x2,place.y2)==1)
        {
            //*fpage1=2;
            return 2;
        }
        if(mouse_press(400,160,740,210)==1)
        {
            bar(400,160,740,210,0);
            free(*pname0);
            *pname0=malloc((size_t)11);
            Getinfo(403,170,*pname0,10,400,160,740,210);//点击输入框时
            
			delay(200);
			//*fpage1=1;
            //return;
        }

        if(mouse_press(compbtn.x1,compbtn.y1,compbtn.x2,compbtn.y2)==1)
        {//点击完成按钮
            if(strcmp(*pname0,"\0")!=0&&*pplacenum!=0)//当名称和地名都已确定后
            {
                char* filen=malloc((size_t)30);
                char* filen_bas=malloc((size_t)30);
                char* filen_dat=malloc((size_t)30);
                strcpy(filen,"C:\\new\\WORKS\\");
                strcat(filen,*pname0);
                strcpy(filen_bas,filen);
                strcpy(filen_dat,filen);
                strcat(filen_bas,"\\");
                strcat(filen_dat,"\\");
                strcat(filen_bas,*pname0);
                strcat(filen_dat,*pname0);//字符串做出文件夹，.bas和.dat的文件路径
                strcat(filen_bas,".bas");
                strcat(filen_dat,".dat");
                
                if(access(filen,0)==0)//检测是否能打开  该名称的文件夹，若能则表示命名重复
                {
                    put_hz24(260,230,"该名称已重复！",0,"C:\\new\\HZK\\HZK24",0);  
                    for(i=0;i<=1000;i++)
                    {
                        delay(1);
                        mouse_renew(&MouseX,&MouseY,&press);
                    }
                    put_hz24(260,230,"该名称已重复！",27469,"C:\\new\\HZK\\HZK24",0);
                    continue;
                }
                else
                {
                    FILE* bas;
                    FILE *dat;
                    WORKFILE* tempf=malloc(sizeof(WORKFILE));
                    FILE*content=fopen("C:\\new\\WORKS\\CONTENT.txt","rt+");//打开目录
                    strcpy(tempf->name,*pname0);
                    tempf->place=*pplacenum;
                    strcpy(tempf->path_bas,filen_bas);
                    strcpy(tempf->path_dat,filen_dat);
                    mkdir(filen);//创建文件夹
                    if(content==NULL)
                    {
                        fclose(content);
                        return;
                    }

                    else
                    {
                        fseek(content,0,2);
                        fputc((int)'\n',content);
                        fseek(content,0,2);
                        fputs(tempf->path_bas,content);//将文件路径写入目录方便日后操作
                        fclose(content);
                    };
                    bas=fopen(filen_bas,"wb+");
                    dat=fopen(filen_dat,"wb+");
                    fwrite(tempf,sizeof(WORKFILE),1,bas);//创建文件夹并把文件信息写入.bas文件
                    fclose(bas);
                    fclose(dat);
                    free(tempf);
                }

                
                strcpy(*pname0,"\0");
                free(*pname0); 
                free(filen);
                free(filen_bas);
                free(filen_dat);
                *pplacenum=0;
                return 0;
                
            }
            else
            {
                if(strcmp(*pname0,"\0")==0)
                {
                    put_hz24(260,230,"未输入项目名称！",0,"C:\\new\\HZK\\HZK24",0);
                }

                if(*pplacenum==0)
                {
                    put_hz24(260,350,"未选择项目地点！",0,"C:\\new\\HZK\\HZK24",0);
                }
                for(i=0;i<=1000;i++)
                {
                    delay(1);
                    mouse_renew(&MouseX,&MouseY,&press);
                }
                put_hz24(260,230,"未输入项目名称！",27469,"C:\\new\\HZK\\HZK24",0);
                put_hz24(260,350,"未选择项目地点！",27469,"C:\\new\\HZK\\HZK24",0); 
            }
        }
    }
}

void placeprt(BTN_BAR* pplace,int placenum)//选择地点的显示
{
    btn_bar_Draw(*pplace);
    hzplace(pplace,32,32);
    put_hz24(pplace->xinf+44,pplace->yinf+3,pplace->inf,0,"C:\\new\\HZK\\HZK24",0);
    bar(400,280,700,330,0);
    switch(placenum)
    {
        case 0:
            put_hz24(420,290,"点击按钮选择项目地点",65535,"C:\\new\\HZK\\HZK24",0);
            break;
        case OlymMon:
            put_hz24(420,290,"奥林匹斯山",65535,"C:\\new\\HZK\\HZK24",0);
            break;
        case MariVal:
            put_hz24(420,290,"水手大峡谷",65535,"C:\\new\\HZK\\HZK24",0);
            break;
        case ArabTer:
            put_hz24(420,290,"阿拉伯高地",65535,"C:\\new\\HZK\\HZK24",0);
            break;
        case UtopPla:
            put_hz24(420,290,"乌托邦平原",65535,"C:\\new\\HZK\\HZK24",0);
            break;
        case ElysPla:
            put_hz24(420,290,"埃律西昂平原",65535,"C:\\new\\HZK\\HZK24",0);
            break;
    }
}

void nameprt(char* name)//名称显示
{
    BTN_BAR namebtn={"项目名称",0,0,240,160,400,210};
    //strcpy(name,"ssss");
    btn_bar_Draw(namebtn);
    hzplace(&namebtn,32,32);
    put_hz24(namebtn.xinf+30,namebtn.yinf+3,namebtn.inf,0,"C:\\new\\HZK\\HZK24",0);
    bar(400,160,740,210,0);
    if(strcmp(name,"\0")==0)
        put_hz16_asc16_size(410,172,1,1,"点击输入项目名称,10字以内,仅限英文与数字",65535,"C:\\new\\HZK\\hzk16");
    else
        put_hz16_asc16_size(410,172,1,1,name,65535,"C:\\new\\HZK\\hzk16");
}

void compprt(BTN_BAR* pcompbtn)//完成按钮的绘制
{
    btn_bar_Draw(*pcompbtn);
    hzplace(pcompbtn,32,32);
    put_hz24(pcompbtn->xinf+24,pcompbtn->yinf+3,pcompbtn->inf,0,"C:\\new\\HZK\\HZK24",0);
}

void title2prt()//标题绘制
{
    BTN_BAR title1={"新建项目",0,0,412,35,612,75};
    btn_bar_Draw(title1);
    hzplace(&title1,32,32);
    put_hz24(title1.xinf,title1.yinf+3,title1.inf,0,"C:\\new\\HZK\\HZK24",0);
}
    
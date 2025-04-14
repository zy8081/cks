#include<ALLFUNS.h>

void wrkmng_add(int *fpage1,int* pplacenum,char*(pname0[]),char*user)
{
    int i;
    WORKFILE filetemp={"\0",0,"\0","\0",0};
    Readbmp64k(0,0,"C:\\TEST\\PICTURE\\WLCMpage.bmp");
    backprt();
    title2prt();
    menuprt(202,100,802,600);
    nameprt(*pname0);
    placeprt(*pplacenum);
    compprt();
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(50,50,150,90)==1)
        {
            *pplacenum=0;
            strcpy(*pname0,"\0");
            *fpage1=0;
            return;//
        }
        if(mouse_press(240,280,400,330)==1)
        {
            *fpage1=2;
            return;
        }
        if(mouse_press(400,160,740,210)==1)
        {
            clrmous(MouseX,MouseY);
            bar(400,160,740,210,0);
            free(*pname0);
            *pname0=malloc((size_t)20);
            strcmp(*pname0,"\0");
            inputs(403,170,*pname0,8);
        }

        if(mouse_press(442,420,582,480)==1)
        {
            if(strcmp(*pname0,"\0")!=0&&*pplacenum!=0)
            {
                char* filen=malloc((size_t)60);
                char* filen_bas=malloc((size_t)60);
                char* filen_dat=malloc((size_t)60);
                char* filen_his=malloc((size_t)60);
                //strcpy(filen,"C:\\TEST\\WORKS\\");
                
                /*strcpy(filen_bas,filen);
                strcpy(filen_dat,filen);
                strcat(filen_bas,"\\");
                strcat(filen_dat,"\\");
                strcat(filen_bas,*pname0);
                strcat(filen_dat,*pname0);
                strcat(filen_bas,".bas");
                strcat(filen_dat,".dat");*/
                sprintf(filen,"C:\\TEST\\WORKS\\%s\\%s",user,*pname0);
                sprintf(filen_dat,"C:\\TEST\\WORKS\\%s\\%s\\%s.dat",user,*pname0,*pname0);
                sprintf(filen_bas,"C:\\TEST\\WORKS\\%s\\%s\\%s.bas",user,*pname0,*pname0);
                sprintf(filen_his,"C:\\TEST\\WORKS\\%s\\%s\\%s.his",user,*pname0,*pname0);
                if(access(filen,0)==0)//
                {
                    put_hz24(260,230,"命名已重复！！",0,"C:\\TEST\\HZK\\HZK24",0);  
                    for(i=0;i<=1000;i++)
                    {
                        delay(1);
                        mouse_renew(&MouseX,&MouseY,&press);
                    }
                    put_hz24(260,230,"命名已重复！！",27469,"C:\\TEST\\HZK\\HZK24",0);
                    continue;
                }
                else
                {
                    FILE*bas;
                    FILE*dat;
                    char*patht=malloc((size_t)60);
                    WORKFILE* tempf=malloc(sizeof(WORKFILE));
                    FILE*content;
                    sprintf(patht,"C:\\TEST\\WORKS\\%s\\CONTENT.txt",user);
                    content=fopen(patht,"rt+");
                    strcpy(tempf->name,*pname0);
                    tempf->place=*pplacenum;
                    tempf->select=0;
                    strcpy(tempf->path_bas,filen_bas);
                    strcpy(tempf->path_dat,filen_dat);
                    strcpy(tempf->path,filen);
                    mkdir(filen);
                    /*if(content==NULL)
                    {
                        fclose(content);
                        return;
                    }*/

                    
                    fseek(content,-1,2);
                    fputc((int)'\0',content);
                    fseek(content,0,2);
                    fputc((int)'\n',content);
                    fseek(content,0,2);
                    fputs(tempf->path_bas,content);
                    fseek(content,0,2);
                    fputc('#',content);
                    fclose(content);
                    bas=fopen(filen_bas,"wb+");
                    
                    gminfo_init(filen_dat);
                    hiscreate(filen_his);
                    datacreate(filen);
                    //dat=fopen(filen_dat,"wb+");
                    fwrite(tempf,sizeof(WORKFILE),1,bas);
                    fclose(bas);
                    //fclose(dat);
                    free(patht);
                    free(tempf);
                }

                *fpage1=0;
                strcpy(*pname0,"\0");
                free(*pname0); 
                free(filen);
                free(filen_bas);
                free(filen_dat);
                free(filen_his);
                *pplacenum=0;
                return;
                
            }
            else
            {
                if(strcmp(*pname0,"\0")==0)
                {
                    put_hz24(260,230,"未输入项目名称！！",0,"C:\\TEST\\HZK\\HZK24",0);
                }

                if(*pplacenum==0)
                {
                    put_hz24(260,350,"未选择地点！！",0,"C:\\TEST\\HZK\\HZK24",0);
                }
                for(i=0;i<=1000;i++)
                {
                    delay(1);
                    mouse_renew(&MouseX,&MouseY,&press);
                }
                put_hz24(260,230,"未输入项目名称！！",27469,"C:\\TEST\\HZK\\HZK24",0);
                put_hz24(260,350,"未选择地点！！",27469,"C:\\TEST\\HZK\\HZK24",0); 
            }
        }
    }
}

void placeprt(int placenum)
{
    btn_bar_Draw(240,280,400,330);
    put_hz24(240+44,305+3,"选择地点",0,"C:\\TEST\\HZK\\HZK24",0);
    bar(400,280,700,330,0);
    switch(placenum)
    {
        case 0:
            put_hz24(420,290,"点击按钮选择地点",65535,"C:\\TEST\\HZK\\HZK24",0);
            break;
        case OlymMon:
            put_hz24(420,290,"奥林匹斯山",65535,"C:\\TEST\\HZK\\HZK24",0);
            break;
        case MariVal:
            put_hz24(420,290,"水手大峡谷",65535,"C:\\TEST\\HZK\\HZK24",0);
            break;
        case ArabTer:
            put_hz24(420,290,"阿拉伯高地",65535,"C:\\TEST\\HZK\\HZK24",0);
            break;
        case UtopPla:
            put_hz24(420,290,"乌托邦平原",65535,"C:\\TEST\\HZK\\HZK24",0);
            break;
        case ElysPla:
            put_hz24(420,290,"埃律西昂平原",65535,"C:\\TEST\\HZK\\HZK24",0);
            break;
    }
}

void nameprt(char* name)
{
    //BTN_BAR namebtn={"???????",0,0,};
    //strcpy(name,"ssss");
    btn_bar_Draw(240,160,400,210);
    //hzplace(&namebtn,32,32);
    put_hz24(240+30,185+3,"项目名称",0,"C:\\TEST\\HZK\\HZK24",0);
    bar(400,160,740,210,0);
    if(strcmp(name,"\0")==0)
        put_hz16_asc16_size(410,172,1,1,"点击输入项目名称,仅限英文与数字,8字以内",65535,"C:\\TEST\\HZK\\hzk16");
    else
        put_hz16_asc16_size(410,172,1,1,name,65535,"C:\\TEST\\HZK\\hzk16");
}

void compprt()//??????????
{
    btn_bar_Draw(442,420,582,480);
    put_hz24(442+24,450,"完成",0,"C:\\TEST\\HZK\\HZK24",0);
}

void title2prt()//
{
    btn_bar_Draw(412,35,612,75);
    put_hz24(412,55+3,"新建项目",0,"C:\\TEST\\HZK\\HZK24",0);
}

void hiscreate(char* pathhis)
{
    FILE* fhis=fopen(pathhis,"wb+");
    fclose(fhis);
}

void datacreate(char*filen)
{
    int t=0;
    FILE* fpbuild,* fptech,*fpnode;
    FILE* fbuild,*ftech;
    char* pathbuild=malloc((size_t)50);
    char* pathtech=malloc((size_t)50);
    char* pathnode=malloc((size_t)50);
    strcpy(pathbuild,filen);
    strcpy(pathtech,filen);
    strcpy(pathnode,filen);
    strcat(pathbuild,"\\userbld.txt");
    strcat(pathtech,"\\usertec.txt");
    strcat(pathnode,"\\usernode.nod");
    fpbuild=fopen(pathbuild,"wt+");
    fptech=fopen(pathtech,"wt+");
    fpnode=fopen(pathnode,"wb+");
    fbuild=fopen("data\\BUILDING.txt","rt+");
    ftech=fopen("data\\TECH.txt","rt+"); 

    while(fgetc(fbuild)!=EOF)
    {
        fseek(fbuild,-1,1);
        fputc(fgetc(fbuild),fpbuild);
        //fseek(fpbuild,0,1);
        //fseek(fbuild,1,1);
    } 
    while(fgetc(ftech)!=EOF)
    {
        fseek(ftech,-1,1);
        fputc(fgetc(ftech),fptech);
        //fseek(fptech,1,1);
        //fseek(ftech,1,1);
    }  
    fclose(fpbuild);
    fclose(fptech);
    fclose(fbuild);
    fclose(ftech);
    fclose(fpnode);

    node_init(pathnode);

    free(pathbuild);
    free(pathtech);
    free(pathnode);
    
}
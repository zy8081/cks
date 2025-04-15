#include <common.h>
#include <game.h>
#include<ORDFUNS.h>
#include<WRKMNG.h>
#include<WRKPLC.h>
#include<DRAWWORK.h>
#include<WRKADD.h>

void wrkmng_main(int *fpage,char *user,WORKFILE* pwork)
{
    int page1=0;
    int i;
    int placetemp=0;
    char*nametemp;
        //if(nametemp==NULL)
        /*{
            printf("No enough memory");
            getch();
            return;
        }*/
    
    while(*fpage!=0)
    {
        clrmous(MouseX,MouseY);
        switch(page1)
        {
            case 0:
                
                nametemp=malloc((size_t)11);
                for(i=0;i<=10;i++)nametemp[i]='\0';
                //put_asc16_size(0,1,1,1,"opened",10);
                wrkmng_menu(&page1,user,pwork);
                break;
            case 1:
            if(nametemp==NULL)
            {
                printf("No enough memory");
                getch();
                return;
            }
                wrkmng_add(&page1,&placetemp,&nametemp,user);
                break;
            case 2:
                wrkmng_add_place(&page1,&placetemp);
                break;
            case 3:
                *fpage=3;
                break;
            case 4:
                *fpage=5;
                return;

        }
    }
    return;
}

void wrkmng_menu(int *fpage1,char*user,WORKFILE*pwork)
{
    int form=0;
    char test[3];
    int i;
    int sel;
    int workpage=1;
    int n;
    int workpagemax;
    
    //put_hz24(0,0,"计数",0,"C:\\TEST\\HZK\\HZK24",0);
    n=workcount(user);
    //itoa(n,test,10);
    //put_asc16_size(,200,1,1,test,0);
    //put_hz24(0,0,"计数后",0,"C:\\TEST\\HZK\\HZK24",0);
    if(n%4==0&&n!=0)workpagemax=n/4;
    else workpagemax=n/4+1;
    
    Readbmp64k(0,0,"PICTURE\\WLCMpage.bmp");
    
    title1prt();
    menuprt(202,100,802,700);
    btn_bar_Draw(50,50,150,90);
    put_hz24(70,56,"返回",0,"HZK\\HZK24",0);
    addprt();
    openprt(form);
    dltprt(form);
    pageselprt(1,workpagemax);
    drawworkmain(1,n,user);
    
    pageprt(workpage,workpagemax);
    
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(50,50,150,90)==1)
        {
            *fpage1=3;
            //free(path);
            return;
        }
        if(mouse_press(842,110,962,160)==1)
        {
            *fpage1=1;
            //free(path);
            return;
        }
        if(mouse_press(222,638,322,682)==1)
        {
            if(workpage>1)
            {
                clrmous(MouseX,MouseY);
                workpage--;
                menuprt(202,100,802,700);
                pageselprt(workpage,workpagemax);
                drawworkmain(workpage,n,user);
                pageprt(workpage,workpagemax);
            }
        }
        if(mouse_press(682,638,782,682)==1)
        {
            if(workpage<workpagemax)
            {
                clrmous(MouseX,MouseY);
                workpage++;
                menuprt(202,100,802,700);
                pageselprt(workpage,workpagemax);
                drawworkmain(workpage,n,user);
                pageprt(workpage,workpagemax);
            }
        }
        if(form==1&&mouse_press(842,270,962,320)==1)
        {
            wrkdelete(workpage,sel,user);
            n=workcount(user);

            //test();
            *fpage1=0;
            return;
            
        }
        if(form==1&&mouse_press(842,190,962,240)==1)
        {
            char* pathbas=malloc((size_t)50);
            FILE* f;
            worksearch(workpage,sel,&pathbas,user);
            f=fopen(pathbas,"rb");
            fread(pwork,sizeof(WORKFILE),(size_t)1,f);
            fclose(f);
            free(pathbas);
            *fpage1=4;
            put_asc16_size(0,50,1,1,"read",2010);
            return;
            
        }
        for(i=1;i<=4;i++)
        {
            if(mouse_press(222,130+(i-1)*120,782,220+(i-1)*120)==1)
            {
                
                char*path=malloc((size_t)50);
                //put_asc16_size(0,50,1,1,"pressed",2010);
                clrmous(MouseX,MouseY);
                if((workpage-1)*4+i<=n)
                {

                    worksearch(workpage,i,&path,user);
                    //exit(0);
                    sel=i;
                    form=1; 
                    openprt(form);
                    dltprt(form);
                    drawworkmain(workpage,n,user);
                    /*itoa(sel,test,10);*/
                    put_asc16_size(0,450,1,1,path,25545);
                    drawworkbar(path,i,1);
                }
                free(path);       
            }   
        }
    }
}

void title1prt()
{
    btn_bar_Draw(412,35,612,75);
    put_hz24(412+10,55+3,"项目管理",0,"HZK\\HZK24",0);
}

void backprt()
{
    btn_bar_Draw(50,50,150,90);
    put_hz24(50+20,70+3,"返回",0,"HZK\\HZK24",0);
}

void addprt()
{
    btn_bar_Draw(842,110,962,160);
    put_hz24(852,120,"新建项目",0,"HZK\\HZK24",0);
}

void openprt(int form)
{
    if(form==0)
    {
        btn_bar_Draw1(842,190,962,240);
        put_hz24(842,215,"打开项目",0,"HZK\\HZK24",0);
    }
    else
    {
        btn_bar_Draw(842,190,962,240);
        put_hz24(842,215,"打开项目",0,"HZK\\HZK24",0);        
    }
}

void dltprt(int form)
{
    if(form==0)
    {
        btn_bar_Draw1(842,270,962,320);
        put_hz24(842+40,305+3,"删除项目",0,"HZK\\HZK24",0);
    }
    else
    {
        btn_bar_Draw(842,270,962,320);
        put_hz24(842+40,305+3,"删除项目",0,"HZK\\HZK24",0);
    }    
}

void lastprt(int form)
{
    if(form==0)
    {
        btn_bar_Draw1(222,638,322,682);
        put_hz24(222+10,638+10,"上一页",0,"HZK\\HZK24",0);
    }
    else
    {
        btn_bar_Draw(222,638,322,682);
        put_hz24(222+10,638+10,"上一页",0,"HZK\\HZK24",0);
    }
    
}

void nextprt(int form)
{
    if(form==0)
    {
        btn_bar_Draw1(682,638,782,682);
        put_hz24(682+10,638+10,"下一页",0,"HZK\\HZK24",0);
    }
    else
    {
        btn_bar_Draw(682,638,782,682);
        put_hz24(682+10,638+10,"下一页",0,"HZK\\HZK24",0);
    }
}

void pageselprt(int workpage,int n)
{
    if(workpage==1&&n!=1)
    {
        lastprt(0);
        nextprt(1);
    }
    else if(workpage==n&&n!=1)
    {
        lastprt(1);
        nextprt(0);
    }
    else if(n==1)
    {
        lastprt(0);
        nextprt(0);
    }
    else
    {
        lastprt(1);
        nextprt(1);
    }
}

void pageprt(int page,int pagemax)
{
    char*pageshow1=malloc((size_t)3);
    char*pageshow2=malloc((size_t)3);
    itoa(page,pageshow1,10);
    itoa(pagemax,pageshow2,10);
    strcat(pageshow1,"/");
    strcat(pageshow1,pageshow2);
    put_asc16_size(478,642,2,2,pageshow1,0);
    free(pageshow1);
    free(pageshow2);
}

/*void test(void)
{
    int t=workcount(u);
    char m[2];
    itoa(t,m,10);
    put_asc16_size(0,200,1,1,m,10);
}*/


void dltfile(int page,int n,char*user)
{
    int i=0;
    int j;
    char*pathbas=malloc((size_t)50);
    char*pathdat=malloc((size_t)50);
    char*pathhis=malloc((size_t)50);
    char*pathdir=malloc((size_t)50);
    char*pathbld=malloc((size_t)50);
    char*pathtec=malloc((size_t)50);
    char*pathnod=malloc((size_t)50);

    worksearch(page,n,&pathbas,user);
    //put_asc16_size(0,100,1,1,"searched",10);
    put_asc16_size(0,130,1,1,pathbas,10);
    while(1)
    {
        if(pathbas[i]!='.')
        {
            pathdat[i]=pathbas[i];
            pathdir[i]=pathbas[i];
            pathhis[i]=pathbas[i];
            i++;
        }
        else
        {
            j=i;
            pathdat[i]='\0';
            pathhis[i]='\0';
            strcat(pathdat,".dat");
            strcat(pathhis,".his");
            //strcat(pathbas,".bas");
            while(1)
            {
                if(pathdat[i]!='\\')i--;
                else
                {
                    pathdir[i]='\0';
                    break;
                } 
            }
            break;
        }
    }
    strcpy(pathnod,pathdir);
    strcpy(pathbld,pathdir);
    strcpy(pathtec,pathdir);
    strcat(pathbld,"\\USERBLD.txt");
    strcat(pathtec,"\\USERTEC.txt");
    strcat(pathnod,"\\USERNODE.nod");
    remove(pathnod);
    remove(pathdat);
    remove(pathbas);
    remove(pathhis);
    remove(pathbld);
    remove(pathtec);
    rmdir(pathdir);
    free(pathdat);
    free(pathbas);
    free(pathdir);
    free(pathhis);
    free(pathbld);
    free(pathtec);
    free(pathnod);
    //delay(1000);
    return;
}

void wrkdelete(int page,int n,char*user)
{
    int g=(page-1)*4+n;
    int k=0;
    int i=0;
    char test[3];
    char ctemp;
    char*pathbas=malloc((size_t)60);
    char*path=malloc((size_t)60);
    char*patht=malloc((size_t)60);
    //FILE* f =fopen("C:\\TEST\\WORKS\\CONTENT.TXT","rt+");
    FILE* fnew=fopen("WORKS\\temp.txt","wt+");
    //FILE* ft=fopen("C:\\TEST\\WORKS\\test.TXT","wt+");
    FILE* ft;
    FILE* ftbas;
    WORKFILE* temp=malloc(sizeof(WORKFILE));
    sprintf(patht,"WORKS\\%s\\CONTENT.txt",user);
    
    worksearch(page,n,&pathbas,user);
    put_asc16_size(0,200,1,1,pathbas,0);
    ftbas=fopen(pathbas,"rb+");
    ft=fopen(patht,"rt+");
    if(ft==NULL)
    {
        bar(0,200,20,220,100);
        getch();
    }
    fread(temp,sizeof(WORKFILE),1,ftbas);
    btn_bar_Draw1(315,160,712,370);
    put_hz24(320,170,"是否删除",65535,"HZK\\HZK24",0);
    put_hz24_asc32(320,200,temp->name,65535, "HZK\\HZK24");
    btn_bar_Draw(335,250,410,300);
    btn_bar_Draw(617,250,692,300);
    put_hz24(345,260,"是",65535,"HZK\\HZK24",0);
    put_hz24(627,260,"否",65535,"HZK\\HZK24",0);
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(335,250,410,300)==1)break;
        if(mouse_press(617,250,692,300)==1)
        {
            fclose(ft);
            fclose(fnew);
            fclose(ftbas);
            free(patht);
            free(path);
            free(temp);
            free(pathbas);
            remove("WORKS\\temp.txt");
            return;
        }
    }
    
    
    //getch();
    dltfile(page,n,user);
    
    
    while(1)
    {
        ctemp=fgetc(ft);
        if(ctemp=='\n')k++;
        if(k!=g)
            fputc(ctemp,fnew);
        else
        {
            put_asc16_size(0,0,1,1,"DONE",0);
            while(1)
            {
                ctemp=fgetc(ft);
                if(ctemp!='\n'&&ctemp!='#')
                    continue;
                else 
                {
                    fputc(ctemp,fnew);
                    k++;
                    break;
                }
            }
        }
        if(ctemp=='#')
        {
            fputc(ctemp,fnew);
            break;
        }

    }
    rewind(fnew);
    rewind(ft);    
    while(1)
    {
        ctemp=fgetc(fnew);
        fputc(ctemp,ft);
        fseek(fnew,0,1);
        fseek(ft,0,1);
        if(ctemp=='#')break;
    }

    free(temp);
    free(pathbas);
    //fclose(f);
    fclose(fnew);
    fclose(ft);//pageprt(page,)
    free(patht);
    free(path);
    fclose(ftbas);
    return;
}

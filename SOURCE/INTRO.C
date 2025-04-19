#include <ALLFUNS.h>

void intro_book(void)
{
    SaveBMP(0,0,1024,768,10);
    clear_main_all(); 
    clear_right_all();
    bar(0,0,1024,768,0xffff);
    Readbmp64k(0,0,"PICTURE\\login.bmp");
    draw_introbook(1);
    printf_intropage_from_txt(1);
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        
        if (mouse_press(475,710,625,760)==1)
        {
            clrmous(MouseX,MouseY);
            LoadBMP(0,0,1024,768,10);
            return ;
        }
        
    }
}

void draw_introbook(int page)
{
    btn_bar_Draw(100,20,550,700);
    btn_bar_Draw(550,20,1000,700);

    btn_bar_Draw(20,20,100,100);
    bar(25,25,95,95,1000);
    puthz2(25,25,32,32,1,"综述");

    btn_bar_Draw(20,120,100,200);
    bar(25,125,95,195,0xBD32);
    puthz2(25,125,32,32,1,"地图");

    btn_bar_Draw(20,220,100,300);
    bar(25,225,95,295,0xFFAA);
    puthz2(25,225,32,32,1,"资源");

    btn_bar_Draw(20,320,100,400);
    bar(25,325,95,395,0xBBBB);
    puthz2(25,325,32,32,1,"建造");

    btn_bar_Draw(20,420,100,500);
    bar(25,425,95,495,0xFF19);
    puthz2(25,425,32,32,1,"科技");

    btn_bar_Draw(20,520,100,600);
    bar(25,525,95,595,0xBDBD);
    puthz2(25,525,32,32,1,"时间");

    btn_bar_Draw(120,710,220,760);
    puthz2(120,710,32,32,1,"上一页");
    btn_bar_Draw(880,710,980,760);
    puthz2(880,710,32,32,1,"下一页");

    btn_bar_Draw(475,710,625,760);
    puthz2(475,710,32,32,0xA000,"退出说明");
}

//每行13个字（包括标点）,共18行
void printf_intropage_from_txt(int page)
{
    int i,j;
    int line;
    char c;
    char str1[100];
    char str2[10];
    char picpath[50];
    FILE *file=fopen("data\\intro.txt","r");
    if (file==NULL)
    {
        return;
    }
    for (i=0;i<page;i++)
    {
        while((c=fgetc(file))!='#');
    }
    while((c=fgetc(file))!='\n');

    i=0,j=0,line=1;
    while(1)
    {
        c=fgetc(file);
        if (c=='\n')
        {
            str1[i]='\0';
            i=0;
            puthz3(110,20+(line-1)*35,32,32,1,str1);
            line++;
            continue;
        }
        if (c=='$')
        {
            j=0;
            while((c=fgetc(file))!='$')
            {
                str2[j++]=c;
            }
            str2[j]='\0';
            sprintf(picpath,"PICTURE\\intro\\%s.bmp",str2);
            Readbmp64k(110,20+(line-1)*35,picpath);
            while((c=fgetc(file))!='\n')
            {
                str2[j++]=c;
            }
            str2[j]='\0';
            line+=atoi(str2);
            continue;
        }
        if (c=='+')
        {
            while((c=fgetc(file))!='\n')
            {
                str2[j++]=c;
            }
            str2[j]='\0';
            line+=atoi(str2);
            continue;
        }
        if(c=='#')
        {
            break;
        }
        str1[i++]=c;
    }
    sprintf(str1,"第%d页",page);
    put_hz16_asc16_size(110,660,2,2,str1,1000,"HZK\\HZ16");
    
    while((c=fgetc(file))!='\n');
    i=0,j=0,line=1;
    while(1)
    {
        c=fgetc(file);
        if (c=='\n')
        {
            str1[i]='\0';
            i=0;
            puthz3(560,20+(line-1)*35,32,32,1,str1);
            line++;
            continue;
        }
        if (c=='$')
        {
            j=0;
            while((c=fgetc(file))!='$')
            {
                str2[j++]=c;
            }
            str2[j]='\0';
            sprintf(picpath,"PICTURE\\intro\\%s.bmp",str2);
            Readbmp64k(560,20+(line-1)*35,picpath);
            j=0;
            while((c=fgetc(file))!='\n')
            {
                str2[j++]=c;
            }
            str2[j]='\0';
            line+=atoi(str2);
            continue;
        }
        if (c=='+')
        {
            while((c=fgetc(file))!='\n')
            {
                str2[j++]=c;
            }
            str2[j]='\0';
            line+=atoi(str2);
            continue;
        }
        if(c=='#')
        {
            break;
        }
        str1[i++]=c;
    
    }
    sprintf(str1,"第%d页",page+1);
    put_hz16_asc16_size(920,660,2,2,str1,3000,"HZK\\HZ16");

    fclose(file);
}
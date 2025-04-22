#include <ALLFUNS.h>

void intro_book(int page)
{
    int i;
    int newpage=page;
    int oldpage=page;
    int pageindex[6];
    char temp;
    pageindex[0]=1;
    pageindex[1]=7;
    pageindex[2]=11;
    pageindex[3]=15;
    pageindex[4]=23;
    pageindex[5]=1;
    SaveBMP(0,0,1024,768,10);
    clear_main_all(); 
    clear_right_all();
    bar(0,0,1024,768,0xffff);
    Readbmp64k(0,0,"PICTURE\\login.bmp");
    draw_introbook();
    printf_intropage_from_txt(newpage);
    clear_keyboard();
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        temp=renew_bookpage();
        if (newpage!=oldpage)
        {
            clrmous(MouseX,MouseY);
            draw_introbook();
            printf_intropage_from_txt(newpage);
            oldpage=newpage;
        }
        if (mouse_press(475,710,625,760)==1)
        {
            clrmous(MouseX,MouseY);
            LoadBMP(0,0,1024,768,10);
            return ;
        }
        if (mouse_press(120,710,220,760)==1 || temp==1)
        {
            if (newpage>1)
            {
                newpage -=2;
            }
        }
        if (mouse_press(880,710,980,760)==1 || temp==2)
        {
            if (newpage<25)
            {
                newpage +=2;
            }
        }
        for (i=0;i<6;i++)
        {
            if (shuqian_judge_press(i)==1)
            {
                newpage=pageindex[i];
            }
        }
    }
}

void clear_keyboard(void)
{
    while(bioskey(1)!=0)
    {
        bioskey(0);
    }
}
int renew_bookpage(void)
{
    char temp=0;
    if(bioskey(1)!=0)
    {
        temp=bioskey(0);
    }

    if(temp=='d'||temp=='D')
    {
        return 2;
    }

    if(temp=='a'||temp=='A')
    {
        return 1;
    }
    return 0;
}


void draw_introbook(void)
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

    btn_bar_Draw(300,700,400,750);
    bar(305,705,395,745,1000);

    btn_bar_Draw(700,700,800,750);
    bar(705,705,795,745,1000);
}

int shuqian_judge_press(int i)
{
    return mouse_press(20,20+i*100,100,100+i*100);
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
            puthz(110,25+(line-1)*35,str1,32,32,1);
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
            Readbmp64k(110,25+(line-1)*35,picpath);
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
            j=0;
            while((c=fgetc(file))!='\n')
            {
                str2[j++]=c;
            }
            str2[j]='\0';
            line+=atoi(str2);
            continue;
        }
        if (c=='&')
        {
            j=0;
            while((c=fgetc(file))!=' ')
            {
                str2[j++]=c;
            }
            str2[j]='\0';
            fgets(str1,100,file);
            str1[strlen(str1)-1]='\0';
            puthz2(110,25+(line-1)*35,32,32,atoi(str2),str1);
            i=0;
            line++;
            continue;
        }
        if (c=='*')
        {
            j=0;
            while((c=fgetc(file))!=' ')
            {
                str2[j++]=c;
            }
            str2[j]='\0';
            fgets(str1,100,file);
            str1[strlen(str1)-1]='\0';
            puthz2(110,25+(line-1)*35,48,48,atoi(str2),str1);
            i=0;
            line+=2;
            continue;
        }
        if(c=='#')
        {
            break;
        }
        str1[i++]=c;
    }
    sprintf(str1,"第%d页",page);
    put_hz16_asc16_size(310,705,2,2,str1,1,"HZK\\HZ16");
    
    while((c=fgetc(file))!='\n');
    i=0,j=0,line=1;
    while(1)
    {
        c=fgetc(file);
        if (c=='\n')
        {
            str1[i]='\0';
            i=0;
            puthz(560,25+(line-1)*35,str1,32,32,1);
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
            Readbmp64k(560,25+(line-1)*35,picpath);
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
            j=0;
            while((c=fgetc(file))!='\n')
            {
                str2[j++]=c;
            }
            str2[j]='\0';
            line+=atoi(str2);
            continue;
        }
        if (c=='&')
        {
            j=0;
            while((c=fgetc(file))!=' ')
            {
                str2[j++]=c;
            }
            str2[j]='\0';
            fgets(str1,100,file);
            str1[strlen(str1)-1]='\0';
            puthz2(560,25+(line-1)*35,32,32,atoi(str2),str1);
            i=0;
            line++;
            continue;
        }
        if (c=='*')
        {
            j=0;
            while((c=fgetc(file))!=' ')
            {
                str2[j++]=c;
            }
            str2[j]='\0';
            fgets(str1,100,file);
            str1[strlen(str1)-1]='\0';
            puthz2(560,25+(line-1)*35,48,48,atoi(str2),str1);
            i=0;
            line+=2;
            continue;
        }
        if(c=='#')
        {
            break;
        }
        str1[i++]=c;
    
    }
    sprintf(str1,"第%d页",page+1);
    put_hz16_asc16_size(710,705,2,2,str1,1,"HZK\\HZ16");

    fclose(file);
}

#include<ALLFUNS.h>

void eventsc(int (*events)[2])
{
    int cevent;
    clrmous(MouseX,MouseY); 
    cevent=rand()%4;
    switch(cevent)
    {
        case 0:
            break;
        case 1:
        case 2:
            (*events)[0]=rand()%6+1;
            (*events)[1]=0;
            //eventshow(revent);
            break;
        case 3:
            (*events)[0]=rand()%6+1;
            (*events)[1]=rand()%6+1;
            while(1)
            {
                
                (*events)[0]=rand()%6+1;
                (*events)[1]=rand()%6+1;
                if(((*events)[0])!=((*events)[1])) break; 
                 
            }
            //eventshow(revent1);
            //eventshow(revent2);
            break;
    }
    
}

void eventshow(int events[2],struct GameInfo* pgameinfo)
{
    clrmous(MouseX,MouseY);
    SaveBMP(230,0,794,750,0);
    event_rocket(pgameinfo);
    event_warning(pgameinfo);
    switch(events[0])
    {
        case 0:
            break;
        case 1:
            event_scb(pgameinfo);//沙尘暴
            break;
        case 2:
            event_yj(pgameinfo);//跃进
            break;
        case 3:
            event_dz(pgameinfo);//地震
            break;
        case 4:
            event_yq(pgameinfo);//氧气泄露
            break;
        case 5:
            event_sbgz(pgameinfo);//设备设计问题
            break;
        case 6:
            event_yz(pgameinfo);//援助
            break;

    }
    switch(events[1])
    {
        case 0:
            break;
        case 1:
            event_scb(pgameinfo);//沙尘暴
            break;
        case 2:
            event_yj(pgameinfo);//跃进
            break;
        case 3:
            event_dz(pgameinfo);//地震
            break;
        case 4:
            event_yq(pgameinfo);//氧气泄露
            break;
        case 5:
            event_sbgz(pgameinfo);//设备设计问题
            break;
        case 6:
            event_yz(pgameinfo);//援助
            break;

    }

    LoadBMP(230,0,794,750,0);

}

void event_scb(struct GameInfo* pgameinfo)
{
    btn_bar_Draw(250,50,774,740);
    Readbmp64k(277,105,"PICTURE\\scb.bmp");//换贴图
    bar(277,565,747,720,0);

    put_hz24(270,70,"沙尘暴",65535,"HZK\\HZK24",0);
    put_hz24(300,575,"一场令人震撼的沙尘暴正席卷而来",65535,"HZK\\HZK24",0);
    put_hz24(300,605,"掀起的沙尘吞噬了火星的天空",65535,"HZK\\HZK24",0);
    put_hz24(300,635,"漫无边际的昏暗中看不见光明",65535,"HZK\\HZK24",0);
    put_hz24(300,665,"（损害内容）",63776,"HZK\\HZK24",0);
    put_hz24(300,695,"（点击任意处继续）",65535,"HZK\\HZK24",0);

    //pgameinfo->r_info.nanomaterial=-100;
    pgameinfo->r_info.mineral-=100;
    pgameinfo->r_info.energy-=100;
    pgameinfo->r_info.oxygen-=30;
    pgameinfo->r_info.water-=30;
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(0,0,1024,768)==1)break;
    }

    return;
}

void event_yj(struct GameInfo* pgameinfo)
{
    btn_bar_Draw(250,50,774,740);
    Readbmp64k(277,105,"PICTURE\\yj.bmp");//换贴图
    bar(277,565,747,720,0);

    put_hz24(270,70,"技术飞跃",65535,"HZK\\HZK24",0);
    put_hz24(300,575,"是意想不到的偶然，也是历史进程的必然",65535,"HZK\\HZK24",0);
    put_hz24(300,605,"相关技术在意料之外地取得了突破",65535,"HZK\\HZK24",0);
    put_hz24(300,635,"极大地推动了火星家园的建设",65535,"HZK\\HZK24",0);
    put_hz24(300,665,"（增益内容）",63776,"HZK\\HZK24",0);
    put_hz24(300,695,"（点击任意处继续）",65535,"HZK\\HZK24",0);
    pgameinfo->r_info.mineral+=100;
    pgameinfo->r_info.energy+=100;
    pgameinfo->r_info.oxygen+=100;
    pgameinfo->r_info.water+=100;
    pgameinfo->r_info.rarematerial+=100;
    pgameinfo->r_info.nanomaterial+=100;

    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(0,0,1024,768)==1)break;
    }

    return;
}

void event_dz(struct GameInfo* pgameinfo)
{
    btn_bar_Draw(250,50,774,740);
    //bar(277,125,747,595,0);//换贴图
    Readbmp64k(277,105,"PICTURE\\dz.bmp");
    bar(277,565,747,720,0);

    put_hz24(270,70,"地震",65535,"HZK\\HZK24",0);
    put_hz24(300,575,"一阵剧烈的震动打破了这片净土",65535,"HZK\\HZK24",0);
    put_hz24(300,605,"火星板块间的应力在长期积累后终于爆发",65535,"HZK\\HZK24",0);
    put_hz24(300,635,"一场地震席卷了火星基地",65535,"HZK\\HZK24",0);
    put_hz24(300,665,"（损害内容）",63776,"HZK\\HZK24",0);
    put_hz24(300,695,"（点击任意处继续）",65535,"HZK\\HZK24",0);

    pgameinfo->r_info.mineral-=200;
    pgameinfo->r_info.energy-=1000;
    pgameinfo->r_info.oxygen-=20;
    pgameinfo->r_info.water-=70;
    pgameinfo->r_info.rarematerial-=50;
    pgameinfo->r_info.nanomaterial-=60;
    pgameinfo->r_info.food-=60;
    pgameinfo->r_info.fuel-=60;

    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(0,0,1024,768)==1)break;
    }

    return;
}

void event_yq(struct GameInfo* pgameinfo)
{
    btn_bar_Draw(250,50,774,740);
    Readbmp64k(277,105,"PICTURE\\yq.bmp");//换贴图
    bar(277,565,747,720,0);

    put_hz24(270,70,"氧气泄露",65535,"HZK\\HZK24",0);
    put_hz24(300,575,"“没有不透风的墙”",65535,"HZK\\HZK24",0);
    put_hz24(300,605,"遗憾的是火星基地的厚屏障也没有例外",65535,"HZK\\HZK24",0);
    put_hz24(300,635,"由于未知的故障，氧气不断地泄露",65535,"HZK\\HZK24",0);
    put_hz24(300,665,"（损害内容）",63776,"HZK\\HZK24",0);
    put_hz24(300,695,"（点击任意处继续）",65535,"HZK\\HZK24",0);

    pgameinfo->r_info.energy-=100;
    pgameinfo->r_info.oxygen-=500;
    pgameinfo->r_info.rarematerial-=50;
    pgameinfo->r_info.nanomaterial-=50;

    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(0,0,1024,768)==1)break;
    }

    return;
}

void event_sbgz(struct GameInfo* pgameinfo)
{
    btn_bar_Draw(250,50,774,740);
    Readbmp64k(277,105,"PICTURE\\sbgz.bmp");//换贴图
    bar(277,565,747,720,0);

    put_hz24(270,70,"设备故障",65535,"HZK\\HZK24",0);
    put_hz24(300,575,"再精密的设备也会有故障的时候",65535,"HZK\\HZK24",0);
    put_hz24(300,605,"只是在遥远的火星",65535,"C:HZK\\HZK24",0);
    put_hz24(300,635,"从地球远道而来的小问题也略显棘手",65535,"HZK\\HZK24",0);
    put_hz24(300,665,"（损害内容）",63776,"HZK\\HZK24",0);
    put_hz24(300,695,"（点击任意处继续）",65535,"HZK\\HZK24",0);

    pgameinfo->r_info.energy-=100;
    pgameinfo->r_info.rarematerial-=100;
    pgameinfo->r_info.nanomaterial-=100;
    pgameinfo->r_info.fuel-=60;

    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(0,0,1024,768)==1)break;
    }

    return;
}

void event_yz(struct GameInfo* pgameinfo)
{
    btn_bar_Draw(250,50,774,740);
    Readbmp64k(277,105,"PICTURE\\yz.bmp");//换贴图
    bar(277,565,747,720,0);

    pgameinfo->r_info.mineral+=200;
    pgameinfo->r_info.energy+=1000;
    pgameinfo->r_info.oxygen+=200;
    pgameinfo->r_info.water+=200;
    pgameinfo->r_info.rarematerial+=300;
    pgameinfo->r_info.nanomaterial+=300;
    pgameinfo->r_info.food+=300;
    pgameinfo->r_info.fuel+=300;

    put_hz24(270,70,"国际援助",65535,"HZK\\HZK24",0);
    put_hz24(300,575,"来自他国的援助不期而至",65535,"HZK\\HZK24",0);
    put_hz24(300,605,"在这茫茫的赤色沙漠",65535,"HZK\\HZK24",0);
    put_hz24(300,635,"在国籍之前，首先我们同样是人类",65535,"HZK\\HZK24",0);
    put_hz24(300,665,"（增益内容）",63776,"HZK\\HZK24",0);
    put_hz24(300,695,"（点击任意处继续）",65535,"HZK\\HZK24",0);

    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(0,0,1024,768)==1)break;
    }

    return;
}

void event_rocket(struct GameInfo* pgameinfo)
{
    if(pgameinfo->rocket.apply!=-1&&pgameinfo->year==pgameinfo->rocket.year&&pgameinfo->month==pgameinfo->rocket.month)
    {
        btn_bar_Draw(250,50,774,740);
        Readbmp64k(277,105,"PICTURE\\hj.bmp");//换贴图
        bar(277,565,747,720,0);

        put_hz24(270,70,"火箭到达",65535,"HZK\\HZK24",0);
        put_hz24(300,575,"在沸腾的火焰中",65535,"HZK\\HZK24",0);
        put_hz24(300,605,"火箭从空中缓缓降落",65535,"HZK\\HZK24",0);
        put_hz24(300,635,"地球与火星，永远同在",65535,"HZK\\HZK24",0);
        put_hz24(300,665,"（增益内容）",63776,"HZK\\HZK24",0);
        put_hz24(300,695,"（点击任意处继续）",65535,"HZK\\HZK24",0);

        pgameinfo->r_info.nanomaterial+=pgameinfo->rocket.resadd.nanomaterial;
        pgameinfo->r_info.rarematerial+=pgameinfo->rocket.resadd.rarematerial;
        pgameinfo->r_info.oxygen+=pgameinfo->rocket.resadd.oxygen;
        pgameinfo->r_info.water+=pgameinfo->rocket.resadd.water;
        pgameinfo->r_info.food+=pgameinfo->rocket.resadd.food;
        pgameinfo->r_info.energy+=pgameinfo->rocket.resadd.energy;
        pgameinfo->r_info.fuel+=pgameinfo->rocket.resadd.fuel;
        pgameinfo->r_info.mineral+=pgameinfo->rocket.resadd.mineral;

        pgameinfo->people+=pgameinfo->rocket.peopleadd;
        
        rocket_init(&(pgameinfo->rocket));
        while(1)
        {
            mouse_renew(&MouseX,&MouseY,&press);
            if(mouse_press(0,0,1024,768)==1)break;
        }
    }
    
    return;
}

void event_warning(struct GameInfo* pgameinfo)
{
    int t[8]={1,1,1,1,1,1,1,1};
    int ret[8];
    char ts[5];
    int i;
    long int repast[8];
    long int renow[8];
    press =0;
   
    repast[0]=pgameinfo->r_info_t.nanomaterial;
    repast[1]=pgameinfo->r_info_t.rarematerial;
    repast[2]=pgameinfo->r_info_t.oxygen;
    repast[3]=pgameinfo->r_info_t.water;
    repast[4]=pgameinfo->r_info_t.food;
    repast[5]=pgameinfo->r_info_t.energy;
    repast[6]=pgameinfo->r_info_t.fuel;
    repast[7]=pgameinfo->r_info_t.mineral;

    renow[0]=pgameinfo->r_info.nanomaterial;
    renow[1]=pgameinfo->r_info.rarematerial;
    renow[2]=pgameinfo->r_info.oxygen;
    renow[3]=pgameinfo->r_info.water;
    renow[4]=pgameinfo->r_info.food;
    renow[5]=pgameinfo->r_info.energy;
    renow[6]=pgameinfo->r_info.fuel;
    renow[7]=pgameinfo->r_info.mineral;

    for(i=0;i<8;i++)
    {
        t[i]=judge_warning(repast[i],renow[i]);
        ret[i]=repast[i]-renow[i];
    }
    
    for(i=0;i<8;i++)
    {
        if(prt_warning(i,t[i],ret[i])==1)
        {
            press=0;
            while(1)
            {
                mouse_renew(&MouseX,&MouseY,&press);
                if(mouse_press(0,0,1024,768)==1)
                {
                    press=0;
                    clrmous(MouseX,MouseY);
                    pgameinfo->r_info_t=pgameinfo->r_info;
                    break;
                }
            }
        }

    }
    return;
}

int judge_warning(long int  it,long int i)
{
    int t=it-i;
    int x;
    int n;
    if(t>0)
    {   
        x=i/t;
        for(n=0;n<=5;n++)
        {
            if(x>=n&&x<n+1)
                return n+1;
        }
    }
    return 0;
}

int prt_warning(int re,int t,int ret)
{
    char s1[60];
    char s2[60];
    clrmous(MouseX,MouseY);
    if(t>=1&&t<=6)
    {
        clrmous(MouseX,MouseY);
        switch(re)
        {
            case 0:
                sprintf(s1,"上个月消耗了纳米材料%d",ret);
                sprintf(s2,"纳米材料将于%d月后消耗尽",t);
                break;
            case 1:
                sprintf(s1,"上个月消耗了稀有材料%d",ret);
                sprintf(s2,"稀有材料将于%d月后消耗尽",t);
                break;
            case 2:
                sprintf(s1,"上个月消耗了水%d",ret);
                sprintf(s2,"水将于%d月后消耗尽",t);
                break;
            case 3:
                sprintf(s1,"上个月消耗了食物%d",ret);
                sprintf(s2,"食物将于%d月后消耗尽",t);
                break;
            case 4:
                sprintf(s1,"上个月消耗了能源%d",ret);
                sprintf(s2,"能源将于%d月后消耗尽",t);
                break;
            case 5:
                sprintf(s1,"上个月消耗了燃料%d",ret);
                sprintf(s2,"燃料将于%d月后消耗尽",t);
                break;
            case 6:
                sprintf(s1,"上个月消耗了矿物%d",ret);
                sprintf(s2,"矿物将于%d月后消耗尽",t);
                break;
        }
        btn_bar_Draw(250,50,774,740);
        Readbmp64k(277,105,"PICTURE\\dq.bmp");//换贴图
        bar(277,565,747,720,0);
        put_hz24(270,70,"资源预警",65535,"HZK\\HZK24",0);
        put_hz24_asc32(300,575,s1,65535,"HZK\\HZK24");
        put_hz24(300,605,"在这个消耗速度下",65535,"HZK\\HZK24",0);
        put_hz24_asc32(300,635,s2,65535,"HZK\\HZK24");
        if(re>=2&&re<=5)
        {
            put_hz24_asc32(300,665,"该资源耗尽表示该项目失败",63776,"HZK\\HZK24");
        }
        put_hz24(300,695,"（点击任意处继续）",65535,"HZK\\HZK24",0);
        return 1;
    }
    else return 0;
}

//void event_expover(struct GameInfo* pgameinfo)
//{

//}
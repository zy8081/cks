#include<ALLFUNS.h>

void eventsc(int (*events)[2])
{
    time_t t;
    int cevent;
    clrmous(MouseX,MouseY); 
    srand((unsigned) time(&t));
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
    SaveBMP(230,0,794,750,0);
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
    Readbmp64k(277,105,"C:\\TEST\\PICTURE\\scb.bmp");//换贴图
    bar(277,565,747,720,0);

    put_hz24(270,70,"沙尘暴",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,575,"一场令人震撼的沙尘暴正席卷而来",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,605,"掀起的沙尘吞噬了火星的天空",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,635,"漫无边际的昏暗中看不见光明",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,665,"（损害内容）",63776,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,695,"（点击任意处继续）",65535,"C:\\TEST\\HZK\\HZK24",0);

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
    Readbmp64k(277,105,"C:\\TEST\\PICTURE\\yj.bmp");//换贴图
    bar(277,565,747,720,0);

    put_hz24(270,70,"技术飞跃",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,575,"是意想不到的偶然，也是历史进程的必然",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,605,"相关技术在意料之外地取得了突破",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,635,"极大地推动了火星家园的建设",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,665,"（增益内容）",63776,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,695,"（点击任意处继续）",65535,"C:\\TEST\\HZK\\HZK24",0);
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
    btn_bar_Draw(240,50,784,740);
    //bar(277,125,747,595,0);//换贴图
    Readbmp64k(277,105,"C:\\TEST\\PICTURE\\dz.bmp");
    bar(277,565,747,720,0);

    put_hz24(270,70,"地震",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,575,"一阵剧烈的震动打破了这片净土",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,605,"火星板块间的应力在长期积累后终于爆发",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,635,"一场地震席卷了火星基地",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,665,"（损害内容）",63776,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,695,"（点击任意处继续）",65535,"C:\\TEST\\HZK\\HZK24",0);

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
    Readbmp64k(277,105,"C:\\TEST\\PICTURE\\yq.bmp");//换贴图
    bar(277,565,747,720,0);

    put_hz24(270,70,"氧气泄露",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,575,"“没有不透风的墙”",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,605,"遗憾的是火星基地的厚屏障也没有例外",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,635,"由于未知的故障，氧气不断地泄露",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,665,"（损害内容）",63776,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,695,"（点击任意处继续）",65535,"C:\\TEST\\HZK\\HZK24",0);

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
    Readbmp64k(277,105,"C:\\TEST\\PICTURE\\sbgz.bmp");//换贴图
    bar(277,565,747,720,0);

    put_hz24(270,70,"设备故障",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,575,"再精密的设备也会有故障的时候",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,605,"只是在遥远的火星",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,635,"从地球远道而来的小问题也略显棘手",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,665,"（损害内容）",63776,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,695,"（点击任意处继续）",65535,"C:\\TEST\\HZK\\HZK24",0);

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
    Readbmp64k(277,105,"C:\\TEST\\PICTURE\\yz.bmp");//换贴图
    bar(277,565,747,720,0);

    pgameinfo->r_info.mineral+=200;
    pgameinfo->r_info.energy+=1000;
    pgameinfo->r_info.oxygen+=200;
    pgameinfo->r_info.water+=200;
    pgameinfo->r_info.rarematerial+=300;
    pgameinfo->r_info.nanomaterial+=300;
    pgameinfo->r_info.food+=300;
    pgameinfo->r_info.fuel+=300;

    put_hz24(270,70,"国际援助",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,575,"来自他国的援助不期而至",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,605,"在这茫茫的赤色沙漠",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,635,"在国籍之前，首先我们同样是人类",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,665,"（增益内容）",63776,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,695,"（点击任意处继续）",65535,"C:\\TEST\\HZK\\HZK24",0);

    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(0,0,1024,768)==1)break;
    }

    return;
}
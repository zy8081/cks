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
            event_scb(pgameinfo);//ɳ����
            break;
        case 2:
            event_yj(pgameinfo);//Ծ��
            break;
        case 3:
            event_dz(pgameinfo);//����
            break;
        case 4:
            event_yq(pgameinfo);//����й¶
            break;
        case 5:
            event_sbgz(pgameinfo);//�豸�������
            break;
        case 6:
            event_yz(pgameinfo);//Ԯ��
            break;

    }
    switch(events[1])
    {
        case 0:
            break;
        case 1:
            event_scb(pgameinfo);//ɳ����
            break;
        case 2:
            event_yj(pgameinfo);//Ծ��
            break;
        case 3:
            event_dz(pgameinfo);//����
            break;
        case 4:
            event_yq(pgameinfo);//����й¶
            break;
        case 5:
            event_sbgz(pgameinfo);//�豸�������
            break;
        case 6:
            event_yz(pgameinfo);//Ԯ��
            break;

    }

    LoadBMP(230,0,794,750,0);

}

void event_scb(struct GameInfo* pgameinfo)
{
    btn_bar_Draw(250,50,774,740);
    Readbmp64k(277,105,"PICTURE\\scb.bmp");//����ͼ
    bar(277,565,747,720,0);

    put_hz24(270,70,"ɳ����",65535,"HZK\\HZK24",0);
    put_hz24(300,575,"һ�������𺳵�ɳ������ϯ�����",65535,"HZK\\HZK24",0);
    put_hz24(300,605,"�����ɳ�������˻��ǵ����",65535,"HZK\\HZK24",0);
    put_hz24(300,635,"���ޱ߼ʵĻ谵�п���������",65535,"HZK\\HZK24",0);
    put_hz24(300,665,"�������ݣ�",63776,"HZK\\HZK24",0);
    put_hz24(300,695,"��������⴦������",65535,"HZK\\HZK24",0);

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
    Readbmp64k(277,105,"PICTURE\\yj.bmp");//����ͼ
    bar(277,565,747,720,0);

    put_hz24(270,70,"������Ծ",65535,"HZK\\HZK24",0);
    put_hz24(300,575,"�����벻����żȻ��Ҳ����ʷ���̵ı�Ȼ",65535,"HZK\\HZK24",0);
    put_hz24(300,605,"��ؼ���������֮���ȡ����ͻ��",65535,"HZK\\HZK24",0);
    put_hz24(300,635,"������ƶ��˻��Ǽ�԰�Ľ���",65535,"HZK\\HZK24",0);
    put_hz24(300,665,"���������ݣ�",63776,"HZK\\HZK24",0);
    put_hz24(300,695,"��������⴦������",65535,"HZK\\HZK24",0);
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
    //bar(277,125,747,595,0);//����ͼ
    Readbmp64k(277,105,"PICTURE\\dz.bmp");
    bar(277,565,747,720,0);

    put_hz24(270,70,"����",65535,"HZK\\HZK24",0);
    put_hz24(300,575,"һ����ҵ��𶯴�������Ƭ����",65535,"HZK\\HZK24",0);
    put_hz24(300,605,"���ǰ����Ӧ���ڳ��ڻ��ۺ����ڱ���",65535,"HZK\\HZK24",0);
    put_hz24(300,635,"һ������ϯ���˻��ǻ���",65535,"HZK\\HZK24",0);
    put_hz24(300,665,"�������ݣ�",63776,"HZK\\HZK24",0);
    put_hz24(300,695,"��������⴦������",65535,"HZK\\HZK24",0);

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
    Readbmp64k(277,105,"PICTURE\\yq.bmp");//����ͼ
    bar(277,565,747,720,0);

    put_hz24(270,70,"����й¶",65535,"HZK\\HZK24",0);
    put_hz24(300,575,"��û�в�͸���ǽ��",65535,"HZK\\HZK24",0);
    put_hz24(300,605,"�ź����ǻ��ǻ��صĺ�����Ҳû������",65535,"HZK\\HZK24",0);
    put_hz24(300,635,"����δ֪�Ĺ��ϣ��������ϵ�й¶",65535,"HZK\\HZK24",0);
    put_hz24(300,665,"�������ݣ�",63776,"HZK\\HZK24",0);
    put_hz24(300,695,"��������⴦������",65535,"HZK\\HZK24",0);

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
    Readbmp64k(277,105,"PICTURE\\sbgz.bmp");//����ͼ
    bar(277,565,747,720,0);

    put_hz24(270,70,"�豸����",65535,"HZK\\HZK24",0);
    put_hz24(300,575,"�پ��ܵ��豸Ҳ���й��ϵ�ʱ��",65535,"HZK\\HZK24",0);
    put_hz24(300,605,"ֻ����ңԶ�Ļ���",65535,"C:HZK\\HZK24",0);
    put_hz24(300,635,"�ӵ���Զ��������С����Ҳ���Լ���",65535,"HZK\\HZK24",0);
    put_hz24(300,665,"�������ݣ�",63776,"HZK\\HZK24",0);
    put_hz24(300,695,"��������⴦������",65535,"HZK\\HZK24",0);

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
    Readbmp64k(277,105,"PICTURE\\yz.bmp");//����ͼ
    bar(277,565,747,720,0);

    pgameinfo->r_info.mineral+=200;
    pgameinfo->r_info.energy+=1000;
    pgameinfo->r_info.oxygen+=200;
    pgameinfo->r_info.water+=200;
    pgameinfo->r_info.rarematerial+=300;
    pgameinfo->r_info.nanomaterial+=300;
    pgameinfo->r_info.food+=300;
    pgameinfo->r_info.fuel+=300;

    put_hz24(270,70,"����Ԯ��",65535,"HZK\\HZK24",0);
    put_hz24(300,575,"����������Ԯ�����ڶ���",65535,"HZK\\HZK24",0);
    put_hz24(300,605,"����ãã�ĳ�ɫɳĮ",65535,"HZK\\HZK24",0);
    put_hz24(300,635,"�ڹ���֮ǰ����������ͬ��������",65535,"HZK\\HZK24",0);
    put_hz24(300,665,"���������ݣ�",63776,"HZK\\HZK24",0);
    put_hz24(300,695,"��������⴦������",65535,"HZK\\HZK24",0);

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
        Readbmp64k(277,105,"PICTURE\\hj.bmp");//����ͼ
        bar(277,565,747,720,0);

        put_hz24(270,70,"�������",65535,"HZK\\HZK24",0);
        put_hz24(300,575,"�ڷ��ڵĻ�����",65535,"HZK\\HZK24",0);
        put_hz24(300,605,"����ӿ��л�������",65535,"HZK\\HZK24",0);
        put_hz24(300,635,"��������ǣ���Զͬ��",65535,"HZK\\HZK24",0);
        put_hz24(300,665,"���������ݣ�",63776,"HZK\\HZK24",0);
        put_hz24(300,695,"��������⴦������",65535,"HZK\\HZK24",0);

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
                sprintf(s1,"�ϸ������������ײ���%d",ret);
                sprintf(s2,"���ײ��Ͻ���%d�º����ľ�",t);
                break;
            case 1:
                sprintf(s1,"�ϸ���������ϡ�в���%d",ret);
                sprintf(s2,"ϡ�в��Ͻ���%d�º����ľ�",t);
                break;
            case 2:
                sprintf(s1,"�ϸ���������ˮ%d",ret);
                sprintf(s2,"ˮ����%d�º����ľ�",t);
                break;
            case 3:
                sprintf(s1,"�ϸ���������ʳ��%d",ret);
                sprintf(s2,"ʳ�ｫ��%d�º����ľ�",t);
                break;
            case 4:
                sprintf(s1,"�ϸ�����������Դ%d",ret);
                sprintf(s2,"��Դ����%d�º����ľ�",t);
                break;
            case 5:
                sprintf(s1,"�ϸ���������ȼ��%d",ret);
                sprintf(s2,"ȼ�Ͻ���%d�º����ľ�",t);
                break;
            case 6:
                sprintf(s1,"�ϸ��������˿���%d",ret);
                sprintf(s2,"���ｫ��%d�º����ľ�",t);
                break;
        }
        btn_bar_Draw(250,50,774,740);
        Readbmp64k(277,105,"PICTURE\\dq.bmp");//����ͼ
        bar(277,565,747,720,0);
        put_hz24(270,70,"��ԴԤ��",65535,"HZK\\HZK24",0);
        put_hz24_asc32(300,575,s1,65535,"HZK\\HZK24");
        put_hz24(300,605,"����������ٶ���",65535,"HZK\\HZK24",0);
        put_hz24_asc32(300,635,s2,65535,"HZK\\HZK24");
        if(re>=2&&re<=5)
        {
            put_hz24_asc32(300,665,"����Դ�ľ���ʾ����Ŀʧ��",63776,"HZK\\HZK24");
        }
        put_hz24(300,695,"��������⴦������",65535,"HZK\\HZK24",0);
        return 1;
    }
    else return 0;
}

//void event_expover(struct GameInfo* pgameinfo)
//{

//}
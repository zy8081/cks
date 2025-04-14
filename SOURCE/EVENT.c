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
    Readbmp64k(277,105,"C:\\TEST\\PICTURE\\scb.bmp");//����ͼ
    bar(277,565,747,720,0);

    put_hz24(270,70,"ɳ����",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,575,"һ�������𺳵�ɳ������ϯ�����",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,605,"�����ɳ�������˻��ǵ����",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,635,"���ޱ߼ʵĻ谵�п���������",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,665,"�������ݣ�",63776,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,695,"��������⴦������",65535,"C:\\TEST\\HZK\\HZK24",0);

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
    Readbmp64k(277,105,"C:\\TEST\\PICTURE\\yj.bmp");//����ͼ
    bar(277,565,747,720,0);

    put_hz24(270,70,"������Ծ",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,575,"�����벻����żȻ��Ҳ����ʷ���̵ı�Ȼ",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,605,"��ؼ���������֮���ȡ����ͻ��",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,635,"������ƶ��˻��Ǽ�԰�Ľ���",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,665,"���������ݣ�",63776,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,695,"��������⴦������",65535,"C:\\TEST\\HZK\\HZK24",0);
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
    //bar(277,125,747,595,0);//����ͼ
    Readbmp64k(277,105,"C:\\TEST\\PICTURE\\dz.bmp");
    bar(277,565,747,720,0);

    put_hz24(270,70,"����",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,575,"һ����ҵ��𶯴�������Ƭ����",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,605,"���ǰ����Ӧ���ڳ��ڻ��ۺ����ڱ���",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,635,"һ������ϯ���˻��ǻ���",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,665,"�������ݣ�",63776,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,695,"��������⴦������",65535,"C:\\TEST\\HZK\\HZK24",0);

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
    Readbmp64k(277,105,"C:\\TEST\\PICTURE\\yq.bmp");//����ͼ
    bar(277,565,747,720,0);

    put_hz24(270,70,"����й¶",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,575,"��û�в�͸���ǽ��",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,605,"�ź����ǻ��ǻ��صĺ�����Ҳû������",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,635,"����δ֪�Ĺ��ϣ��������ϵ�й¶",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,665,"�������ݣ�",63776,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,695,"��������⴦������",65535,"C:\\TEST\\HZK\\HZK24",0);

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
    Readbmp64k(277,105,"C:\\TEST\\PICTURE\\sbgz.bmp");//����ͼ
    bar(277,565,747,720,0);

    put_hz24(270,70,"�豸����",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,575,"�پ��ܵ��豸Ҳ���й��ϵ�ʱ��",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,605,"ֻ����ңԶ�Ļ���",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,635,"�ӵ���Զ��������С����Ҳ���Լ���",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,665,"�������ݣ�",63776,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,695,"��������⴦������",65535,"C:\\TEST\\HZK\\HZK24",0);

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
    Readbmp64k(277,105,"C:\\TEST\\PICTURE\\yz.bmp");//����ͼ
    bar(277,565,747,720,0);

    pgameinfo->r_info.mineral+=200;
    pgameinfo->r_info.energy+=1000;
    pgameinfo->r_info.oxygen+=200;
    pgameinfo->r_info.water+=200;
    pgameinfo->r_info.rarematerial+=300;
    pgameinfo->r_info.nanomaterial+=300;
    pgameinfo->r_info.food+=300;
    pgameinfo->r_info.fuel+=300;

    put_hz24(270,70,"����Ԯ��",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,575,"����������Ԯ�����ڶ���",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,605,"����ãã�ĳ�ɫɳĮ",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,635,"�ڹ���֮ǰ����������ͬ��������",65535,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,665,"���������ݣ�",63776,"C:\\TEST\\HZK\\HZK24",0);
    put_hz24(300,695,"��������⴦������",65535,"C:\\TEST\\HZK\\HZK24",0);

    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(0,0,1024,768)==1)break;
    }

    return;
}
#include <common.h>
#include <game.h>
#include <fun3_2.h>
#include <fun3.h>
#include <WRKMNG.h>
#include <fun5.h>
#include <fun4.h>
void draw_block(int x,int y,struct MapInfo mi,int form)
{
    int x1=300+x*92;
    int y1=105+y*92;
    int x2=390+x*92;
    int y2=195+y*92;
    line_thick(x1, y1, x2, y1, 2,0);
    line_thick(x2, y1, x2, y2, 2,0);
    line_thick(x1, y2, x2, y2, 2,0);
    line_thick(x1, y1, x1, y2, 2,0);
    switch(form)
    {
        case 0:
            bar(x1+3,y1+3,x2-3,y2-3,65535);
            break;
        case 1:
            bar(x1+3,y1+3,x2-3,y2-3,63488);
            break;
        case 2:
            bar(x1+3,y1+3,x2-3,y2-3,65535);
            break;
    }
    switch(mi.building.id)
    {
        case 0:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"E",1,"HZK\\Hzk24k");
            break;
        case 1:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"1",1,"HZK\\Hzk24k");
            break;
        case 2:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"2",1,"HZK\\Hzk24k");
            break;
        case 3:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"3",1,"HZK\\Hzk24k");
            break;
        case 4:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"4",1,"HZK\\Hzk24k");
            break;
        case 5:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"BUD_5",1,"HZK\\Hzk24k");
            break;
        case 6:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"BUD_6",1,"HZK\\Hzk24k");
            break;
        case 7:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"BUD_7",1,"HZK\\Hzk24k");
            break;
        case 8:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"BUD_8",1,"HZK\\Hzk24k");
            break;
        case 9:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"BUD_9",1,"HZK\\Hzk24k");
            break;
    }
}

void draw_mainmap(struct GameInfo gf,int xsel,int ysel)
{
    int i,j;
    //put_asc16_number_size(300+j*92,105+i*92,2,2,gameinfop->m_info[i][j].building.id,1);
    for(i=0;i<7;i++)
    {
        for(j=0;j<7;j++)
        {
            draw_block(j,i,gf.m_info[ysel+i][xsel+j],0);
        }
    }
}

void draw_buildmap(struct GameInfo gf,int xsel,int ysel)
{
    int i,j;
    //put_asc16_number_size(300+j*92,105+i*92,2,2,gameinfop->m_info[i][j].building.id,1);
    for(i=0;i<7;i++)
    {
        for(j=0;j<7;j++)
        {
            if(gf.m_info[xsel+i][ysel+j].building.id==0)
                draw_block(j,i,gf.m_info[ysel+i][xsel+j],0);
            else
            {
                draw_block(j,i,gf.m_info[ysel+i][xsel+j],1);
                if (gf.m_info[xsel+i][ysel+j].building.bui_time==0)
                {
                    draw_map_building(i,j,gf.m_info[xsel+i][ysel+j].building.id);
                }
                
            }
                
        }
    }
}

int renew_map(int* pxsel,int*pysel)
{
    char temp=0;
    if(bioskey(1)!=0)
    {
        temp=bioskey(0);
    }

    if(temp=='s'||temp=='S')
        if(*pysel+6<14)
        {
            (*pysel)++;
            return 1;
        }

    if(temp=='d'||temp=='D')
        if(*pxsel+6<14)
        {
            (*pxsel)++;
            return 1;
        }

    if(temp=='w'||temp=='W')
        if(*pysel>0)
        {
            (*pysel)--;
            return 1;
        }
    
    if(temp=='a'||temp=='A')
        if(*pxsel>0)
        {
            (*pxsel)--;
            return 1;
        }
    return 0;
}

void draw_minimap(struct GameInfo gf,int xsel,int ysel)
{
    int i,j;
    int x1=4;
    int x2=231;
    int y1=398;
    int y2=627;

    int xl1=5+xsel*15;
    int xl2=5+(xsel+7)*15;
    int yl1=400+ysel*15;
    int yl2=400+(ysel+7)*15;

    line_thick(x1, y1, x2, y1, 2,0);
    line_thick(x2, y1, x2, y2, 2,0);
    line_thick(x1, y2, x2, y2, 2,0);
    line_thick(x1, y1, x1, y2, 2,0);

    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(gf.m_info[i][j].building.id==0)
                bar(j*15+5,i*15+400,(j+1)*15+4,(i+1)*15+400,64526);
            else
                bar(j*15+5,i*15+400,(j+1)*15+4,(i+1)*15+400,38770);
        }
    }
    line_thick(xl1, yl1, xl2, yl1, 1,65535);
    line_thick(xl2, yl1, xl2, yl2, 1,65535);
    line_thick(xl1, yl2, xl2, yl2, 1,65535);
    line_thick(xl1, yl1, xl1, yl2, 1,65535);

}
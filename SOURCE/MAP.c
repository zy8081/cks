#include<ALLFUNS.h>

void map_init(int place,struct GameInfo *pg)
{
    int i,j;

    int temp1[15][15]=
    {
        {py,py,py,py,wd,py,py,py,py,py,py,py,py,py,py},
        {py,py,py,py,py,py,py,py,py,wd,kd,kd,py,py,py},
        {py,py,kd,py,py,py,py,wd,py,py,py,py,py,py,py},
        {py,py,py,py,py,py,py,py,py,py,py,py,py,py,py},
        {py,py,py,py,pd,pd,py,py,py,pd,pd,py,py,pd,pd},
        {py,py,py,py,pd,pd,pd,pd,pd,pd,pd,pd,pd,sd,pd},
        {py,py,py,py,pd,pd,pd,pd,pd,pd,sd,pd,sd,sd,sd},
        {py,py,py,py,pd,pd,pd,pd,pd,sd,sd,sd,sd,sd,sd},
        {py,py,py,py,pd,pd,pd,pd,sd,sd,sd,sd,sd,sd,sd},
        {py,py,py,py,pd,pd,pd,sd,sd,sd,sd,sd,sd,sd,sd},
        {py,py,py,py,pd,pd,pd,sd,sd,sd,sd,sd,sd,sf,sd},
        {py,py,py,py,pd,pd,pd,sd,sd,sd,sd,sf,sf,sf,sf},
        {py,kd,py,py,pd,pd,pd,pd,sd,sd,sf,sf,sf,sf,sf},
        {py,wd,py,py,py,py,pd,pd,sd,sd,sd,sf,sf,sf,sf},
        {py,py,py,py,kd,py,py,pd,sd,sd,sd,sd,sf,sf,sf}
    };

    int temp2[15][15]=
    {
        {py,py,py,py,wd,wd,py,py,py,py,py,sk,sk,sk,sk},
        {py,py,py,wd,wd,wd,py,py,py,wd,sk,sk,sk,sk,sk},
        {py,py,kd,py,wd,wd,wd,wd,py,py,sk,sk,sk,sk,sk},
        {py,py,py,py,py,py,py,py,py,py,py,sk,sk,sk,sk},
        {py,py,py,py,wd,wd,py,wd,wd,kd,kd,sk,sk,sk,sk},
        {py,py,py,py,wd,wd,py,kd,kd,kd,kd,sk,sk,sk,sk},
        {py,py,py,py,py,py,py,py,kd,kd,kd,sk,sk,sk,sk},
        {py,py,py,py,py,py,py,py,wd,kd,wd,sk,sk,sk,sk},
        {py,py,py,py,py,py,py,kd,kd,kd,kd,sk,sk,sk,sk},
        {py,py,py,py,py,py,py,kd,kd,kd,sk,sk,sk,sk,sk},
        {py,py,py,kd,kd,py,py,kd,kd,kd,sk,sk,sk,sk,sk},
        {py,py,py,kd,kd,py,py,py,py,wd,wd,sk,sk,sk,sk},
        {py,kd,py,py,py,py,py,py,py,py,wd,wd,sk,sk,sk},
        {py,wd,wd,py,py,py,py,py,py,py,wd,sk,sk,sk,sk},
        {py,wd,wd,py,kd,py,py,py,py,py,wd,wd,sk,sk,sk}
    };

    int temp3[15][15]=
    {
        {py,py,py,py,py,py,py,py,py,py,py,py,py,py,py},
        {py,wd,wd,wd,py,py,py,py,py,py,py,py,py,py,py},
        {py,kd,kd,py,py,py,pd,pd,pd,pd,pd,pd,pd,pd,pd},
        {py,py,kd,py,py,pd,pd,pd,pd,pd,pd,kd,kd,kd,pd},
        {py,py,py,py,py,py,py,pd,pd,pd,pd,pd,kd,pd,pd},
        {py,py,py,py,py,py,py,pd,pd,pd,pd,pd,pd,pd,pd},
        {py,py,py,py,py,py,py,pd,pd,pd,pd,pd,pd,pd,pd},
        {py,py,py,py,py,py,py,py,pd,pd,pd,pd,pd,pd,pd},
        {py,py,py,py,py,py,py,py,pd,pd,pd,pd,pd,kd,pd},
        {py,py,py,py,py,kd,py,py,pd,pd,pd,pd,kd,kd,pd},
        {py,kd,kd,py,py,kd,py,py,pd,pd,pd,pd,pd,pd,pd},
        {py,kd,kd,py,py,py,py,py,py,pd,pd,pd,pd,pd,pd},
        {py,py,kd,kd,py,py,py,py,pd,pd,pd,pd,pd,pd,pd},
        {py,py,py,py,py,py,py,pd,pd,pd,pd,kd,kd,pd,pd},
        {py,py,py,py,py,py,py,pd,pd,pd,pd,pd,pd,pd,pd}
    };

    int temp4[15][15]=
    {
        {py,py,py,py,py,py,py,py,py,py,wd,py,py,py,py},
        {py,py,py,pd,pd,py,py,py,py,wd,wd,wd,py,py,py},
        {py,py,pd,pd,pd,pd,py,py,py,wd,wd,py,py,py,py},
        {py,py,py,pd,pd,py,py,py,py,py,py,py,kd,kd,py},
        {py,py,py,py,py,py,py,wd,py,py,py,py,py,py,py},
        {py,py,py,py,py,py,wd,wd,py,py,py,py,py,py,py},
        {py,py,py,py,py,py,py,wd,py,py,py,py,py,py,py},
        {py,py,py,py,py,py,py,py,py,py,pd,pd,py,py,py},
        {py,kd,kd,kd,kd,py,py,py,py,pd,pd,pd,py,py,py},
        {py,py,kd,kd,kd,py,py,py,py,py,py,py,py,py,py},
        {py,py,py,py,py,py,py,py,py,py,pd,pd,pd,py,py},
        {py,py,py,py,py,py,py,pd,pd,py,pd,pd,py,py,py},
        {py,py,wd,wd,py,py,py,py,pd,py,py,py,py,wd,wd},
        {py,wd,py,py,py,py,py,py,py,py,py,py,kd,kd,py},
        {py,py,py,py,py,py,py,py,py,py,py,py,py,py,py}
    };

    int temp5[15][15]=
    {
        {py,py,py,py,py,py,py,py,py,py,py,py,py,py,py},
        {py,py,pd,py,py,py,py,py,py,py,py,py,py,py,py},
        {py,py,pd,pd,py,py,py,kd,kd,py,py,py,py,py,py},
        {py,py,py,pd,pd,py,py,py,kd,kd,py,py,py,py,py},
        {py,py,pd,pd,pd,py,py,py,py,py,py,py,py,py,py},
        {py,py,py,pd,py,py,wd,wd,wd,py,py,py,py,py,py},
        {py,py,py,py,py,py,wd,wd,wd,wd,py,py,py,py,py},
        {py,py,py,py,py,py,py,wd,wd,py,py,py,py,py,py},
        {py,py,py,py,py,py,py,py,py,py,py,py,py,pd,pd},
        {py,py,py,wd,wd,py,py,py,py,py,py,py,pd,pd,pd},
        {py,py,py,wd,wd,py,py,py,py,py,py,py,pd,pd,pd},
        {py,py,py,py,py,py,py,kd,py,py,py,py,py,pd,py},
        {py,py,py,py,py,py,kd,kd,kd,py,py,py,py,py,py},
        {py,py,py,py,py,py,py,kd,kd,py,py,py,py,py,py},
        {py,py,py,py,py,py,py,py,py,py,py,py,py,py,py}
    };

    for (i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
		{
			pg->m_info[j][i].building.id=0;
			pg->m_info[j][i].building.bui_time=0;
			pg->m_info[j][i].terrain=0;
		}
	}

    switch(place)
    {
        case OlymMon:
            
            for(i=0;i<15;i++)
            {
                for(j=0;j<15;j++)
                    pg->m_info[j][i].terrain=temp1[j][i];
            }
            break;
        case MariVal:
            
            for(i=0;i<15;i++)
            {
                for(j=0;j<15;j++)
                    pg->m_info[j][i].terrain=temp2[j][i];
            }
            break;
        case ArabTer:
            
            for(i=0;i<15;i++)
            {
                for(j=0;j<15;j++)
                    pg->m_info[j][i].terrain=temp3[j][i];
            }
            break;
        case UtopPla:
            
            for(i=0;i<15;i++)
            {
                for(j=0;j<15;j++)
                    pg->m_info[j][i].terrain=temp4[j][i];
            }
            break;
        case ElysPla:
            
            for(i=0;i<15;i++)
            {
                for(j=0;j<15;j++)
                    pg->m_info[j][i].terrain=temp5[j][i];
            }
            break;

    }
    srand((unsigned)time(NULL));
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
            pg->m_info[j][i].mineral=mine_block_init(place,pg->m_info[j][i].terrain);
    }
}

int mine_block_init(int place,int terrain)
{
    int x;
    float px;
    x=rand()%50;
    px=((float)(x-25))/100.0+1.0;
    switch(place)
    {
        case OlymMon:
            switch(terrain)
            {
                case py:
                    return (int)(200.0*px);
                case pd:
                    return (int)(1000.0*px);
                case sd:
                    return (int)(600.0*px);
                case sf:
                    return (int)(20.0*px);
                case wd:
                    return (int)(150.0*px);
                case kd:
                    return (int)(300.0*px);
                case sk:
                    return (int)(300.0*px);
            }
        case MariVal:
            switch(terrain)
            {
                case py:
                    return (int)(500.0*px);
                case pd:
                    return (int)(300.0*px);
                case sd:
                    return (int)(300.0*px);
                case sf:
                    return (int)(10.0*px);
                case wd:
                    return (int)(2000.0*px);
                case kd:
                    return (int)(3000.0*px);
                case sk:
                    return (int)(3000.0*px);
            }
        case ArabTer:
            switch(terrain)
            {
                case py:
                    return (int)(600.0*px);
                case pd:
                    return (int)(1500.0*px);
                case sd:
                    return (int)(500.0*px);
                case sf:
                    return (int)(10.0*px);
                case wd:
                    return (int)(500.0*px);
                case kd:
                    return (int)(600.0*px);
                case sk:
                    return (int)(10.0*px);
            }      
        case UtopPla:
            switch(terrain)
            {
                case py:
                    return (int)(500.0*px);
                case pd:
                    return (int)(300.0*px);
                case sd:
                    return (int)(400.0*px);
                case sf:
                    return (int)(10.0*px);
                case wd:
                    return (int)(650.0*px);
                case kd:
                    return (int)(500.0*px);
                case sk:
                    return (int)(10.0*px);
            }
        case ElysPla:
            switch(terrain)
            {
                case py:
                    return (int)(400.0*px);
                case pd:
                    return (int)(600.0*px);
                case sd:
                    return (int)(100.0*px);
                case sf:
                    return (int)(10.0*px);
                case wd:
                    return (int)(550.0*px);
                case kd:
                    return (int)(500.0*px);
                case sk:
                    return (int)(10.0*px);
            }
    }
}

void draw_block(int x,int y,struct MapInfo mi,int form)
{
    char cm[10];
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
    switch(mi.terrain)
    {
        case py:
            bar(x1+3,y1+3,x2-3,y2-3,64526);
            break;
        case wd:
            bar(x1+3,y1+3,x2-3,y2-3,64264);
            break;
        case kd:
            bar(x1+3,y1+3,x2-3,y2-3,45316);
            break;
        case sk:
            bar(x1+3,y1+3,x2-3,y2-3,32768);
            break;
        case pd:
            bar(x1+3,y1+3,x2-3,y2-3,64531);
            break;
        case sd:
            bar(x1+3,y1+3,x2-3,y2-3,65244);
            break;
        case sf:
            bar(x1+3,y1+3,x2-3,y2-3,65340);
            break;
    }
    
    itoa(mi.mineral,cm,10);
    put_hz24_asc32((x1+x2)/2-30,(y1+y2)/2,cm,1,"HZK\\Hzk24k");
    
    /*switch(mi.building.id)
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
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"5",1,"HZK\\Hzk24k");
            break;
        case 6:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"6",1,"HZK\\Hzk24k");
            break;
        case 7:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"7",1,"HZK\\Hzk24k");
            break;
        case 8:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"8",1,"HZK\\Hzk24k");
            break;
        case 9:
            put_hz24_asc32((x1+x2)/2,(y1+y2)/2,"9",1,"HZK\\Hzk24k");
            break;
        
    }*/
}

void draw_mainmap(struct GameInfo gf,int xsel,int ysel)
{
    int i,j;
    clrmous(MouseX,MouseY);
    //put_asc16_number_size(300+j*92,105+i*92,2,2,gameinfop->m_info[i][j].building.id,1);
    for(i=0;i<7;i++)
    {
        for(j=0;j<7;j++)
        {
            draw_block(i,j,gf.m_info[xsel+i][ysel+j],0);
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
                draw_block(i,j,gf.m_info[xsel+i][ysel+j],0);
            else
                draw_block(i,j,gf.m_info[xsel+i][ysel+j],1);
        }
    }
}

int renew_map(int* pxsel,int*pysel)
{
    char temp=0;
    //while(bioskey(1))clean=bioskey(0);

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

void cleankey()
{
    char clean;
    while(bioskey(1))clean=bioskey(0);
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
                bar(i*15+5,j*15+400,(i+1)*15+4,(j+1)*15+400,64526);
            else
                bar(i*15+5,j*15+400,(i+1)*15+4,(j+1)*15+400,38770);
        }
    }
    line_thick(xl1, yl1, xl2, yl1, 1,65535);
    line_thick(xl2, yl1, xl2, yl2, 1,65535);
    line_thick(xl1, yl2, xl2, yl2, 1,65535);
    line_thick(xl1, yl1, xl1, yl2, 1,65535);

}
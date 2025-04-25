#include<ALLFUNS.h>

int people_max(struct GameInfo *pg,char *path)
{
    int i,j;
    int count=cal_one_house_population(path);
    int num=0;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(pg->m_info[i][j].building.id==1 && pg->m_info[i][j].building.bui_time==0 && pg->m_info[i][j].building.lock==0)
            {
                num+=count;//每个居住区容纳100人
            }
        }
    }
    num+=50;
    return num;
}

void people_cost(int *data,struct GameInfo *pg)
{
    int i;
    int population=pg->people;
    // if(pg->r_info.water/p-300>=0)
    //     pg->r_info.water-=p*60; 
    // else
    //     pg->r_info.water-=p*30; 
    data[0]=0;
    data[1]=0;
    data[2]=-population;
    data[3]=-population;
    data[4]=-population;
    data[5]=0;
    data[6]=0;
    data[7]=0;
}

int happiness_count(struct GameInfo *pg,char *path)
{
    int i,j,k;
    int combinnation[6];
    int happyadd=0;
    int happyminus=0;
    int peoplemax=people_max(pg,path);
    happyadd+=((pg->r_info.food)/(pg->people)-30)<30?(pg->r_info.food)/(pg->people):30;
    happyadd+=((pg->r_info.water)/(pg->people)-30)<30?(pg->r_info.water)/(pg->people):30;
    happyadd+=((pg->r_info.energy)/(pg->people)-30)<30?(pg->r_info.energy)/(pg->people):30;
    happyadd+=((pg->r_info.oxygen)/(pg->people)-30)<30?(pg->r_info.oxygen)/(pg->people):30;
    
    for (i=0;i<6;i++)
    {
        combinnation[i]=0;
    }
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            k=0;
            if(pg->m_info[i][j].building.id==2 && pg->m_info[i][j].building.bui_time!=0)
            {
                happyadd+=20;
                combinnation[k++]++;
            }
            if(pg->m_info[i][j].building.id==3&& pg->m_info[i][j].building.bui_time!=0)
            {
                happyadd+=25;
                combinnation[k++]++;
            }
            if(pg->m_info[i][j].building.id==4&& pg->m_info[i][j].building.bui_time!=0)
            {
                happyadd+=25;
                combinnation[k++]++;
            }
            if(pg->m_info[i][j].building.id==15&& pg->m_info[i][j].building.bui_time!=0)
            {
                happyadd+=100;
                combinnation[k++]++;
            }
            if(pg->m_info[i][j].building.id==17&& pg->m_info[i][j].building.bui_time!=0)
            {
                happyadd+=100;
                combinnation[k++]++;
            }
            if(pg->m_info[i][j].building.id==18&& pg->m_info[i][j].building.bui_time!=0)
            {
                happyadd+=250;
                combinnation[k++]++;
            }
        }
    }
    for (i=0,j=0;i<6;i++)
    {
        if (combinnation[i]>0)
        {
            j++;
        }
    }
    happyadd=happyadd+(50+j*5)*j;
    calculate_monthly_happybuff(pg,path);
    happyadd=happyadd*(1.0+(double)pg->happiness[1]/100.0);
    // CloseSVGA();
	// printf("%d %d %d %d",happyadd,rate,basic,atoi(str));
	// getchar();
	// exit(0);
    if (pg->people>peoplemax)
    {
        happyminus-=(peoplemax-pg->people)*1;
    }
    if (pg->people<=100)
    {
        happyminus=happyminus-(pg->people)*4;
    }
    else if (pg->people<=200)
    {
        happyminus=happyminus-(pg->people)*3;
    }
    else if (pg->people<=400)
    {
        happyminus=happyminus-(pg->people)*2;
    }
    else if (pg->people<=1000)
    {
        happyminus=happyminus-(pg->people)*1;
    }
    else
    {
        happyminus-=1100;
    }
    
    pg->happiness[0]=happyadd+happyminus;
    //pg->happiness[0]=(int)((float)(htr[0]-200+htr[1]-300+htr[2]-200+htr[3]-300)*(1.0+((float)(pg->happiness[1])/100.0)));
    return pg->happiness[0];
    
}

int happiness_rate_count(struct GameInfo *pg)
{
    int hr;
    int i,j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(pg->m_info[i][j].building.id==2)
            {
                hr+=2;
            }
            if(pg->m_info[i][j].building.id==3)
            {
                hr+=3;
            }
            if(pg->m_info[i][j].building.id==4)
            {
                 hr+=4;
            }
            if(pg->m_info[i][j].building.id==15)
            {
                hr+=10;
            }
            if(pg->m_info[i][j].building.id==17)
            {
                hr+=12;
            }
            if(pg->m_info[i][j].building.id==18)
            {
                hr+=15;
            }
        }
    }
    
    pg->happiness[1]=hr;
    return hr;
}

long int constrc_count(struct GameInfo *pg,char *path)
{
    int i,j;
    long int cblock=0;
    int buff=calculate_monthly_buildpointbuff(path);
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if (pg->m_info[i][j].building.id!=0 && pg->m_info[i][j].building.bui_time==0)
            {
                switch (pg->m_info[i][j].building.id)
                {
                    case 1:
                        cblock+=30;
                        break;
                    case 2:
                        cblock+=50;
                        break;
                    case 3:
                        cblock+=100;
                        break;
                    case 4:
                        cblock+=100;
                        break;
                    case 5:
                        cblock+=10;
                        break;
                    case 6:
                        cblock+=10;
                        break;
                    case 7:
                        cblock+=10;
                        break;
                    case 8:
                        cblock+=10;
                        break;
                    case 9:
                        cblock+=10;
                        break;
                    case 10:
                        cblock+=15;
                        break;
                    case 11:
                        cblock+=10;
                        break;
                    case 12:
                        cblock+=50;
                        break;
                    case 13:
                        cblock+=10;
                        break;
                    case 14:
                        cblock+=10;
                        break;
                    case 15:
                        cblock+=400;
                        break;
                    case 16:
                        cblock+=50;
                        break;
                    case 17:
                        cblock+=300;
                        break;
                    case 18:
                        cblock+=1000;
                        break;
                    case 19:
                        cblock+=10;
                        break;
                    case 20:
                        cblock+=50;
                        break;
                    case 21:
                        cblock+=10;
                        break;
                    case 22:
                        cblock+=10;
                        break;
            
                    default:
                        break;
                }
            }
            
        }
    }
    if (check_techflag_infile(path,1,10))
    {
        cblock+=1000;
    }
    
    
    pg->construction=((double)(cblock))*(buff+100)/100;
    return pg->construction;
}

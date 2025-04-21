#include<ALLFUNS.h>

int people_max(struct GameInfo *pg)
{
    int i,j;
    int count=0;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(pg->m_info[i][j].building.id==1)
                count+=100;//每个居住区容纳100人
        }
    }
    return count;
}

void people_cost(struct GameInfo *pg)
{
    int p=pg->people;
    if(pg->r_info.water/p-300>=0)
        pg->r_info.water-=p*60; 
    else
        pg->r_info.water-=p*30; 
       
    pg->r_info.oxygen-=p*50;
    pg->r_info.water-=p*60;
    pg->r_info.food-=p*50;
    pg->r_info.energy-=p*50;
}

int happiness_count(struct GameInfo *pg)
{
    int i,j;
    int htr[8];
    if(pg->people==0)
    {
        pg->happiness[0]=0;
        return 0;
    }
    else
    {
        htr[0]=(pg->r_info.food)/(pg->people);
        htr[1]=(pg->r_info.water)/(pg->people);
        htr[2]=(pg->r_info.energy)/(pg->people);
        htr[3]=(pg->r_info.oxygen)/(pg->people);
        pg->happiness[0]=(int)((float)(htr[0]-200+htr[1]-300+htr[2]-200+htr[3]-300)*(1.0+((float)(pg->happiness[1])/100.0)));
        return pg->happiness[0];
    } 
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

int constrc_count(struct GameInfo *pg)
{
    int i,j;
    int ct=0;
    int cblock=0;
    int ckind;
    float crate;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(pg->m_info[i][j].building.id!=0)
                cblock++;
        }
    }
    crate=(float)cblock/225.0;
    pg->construction=(int)(100.0*crate);
    return (int)(100.0*crate);
}

//int res_costwarning()
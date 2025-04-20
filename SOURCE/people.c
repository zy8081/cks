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

void people_cost(struct GameInfo *pg)//资源充足输出0，不足输出1，
{
    int p=pg->people;
    pg->r_info.oxygen-=p*50;
    pg->r_info.water-=p*60;
    pg->r_info.food-=p*50;
    pg->r_info.energy-=p*50;
}

int happiness_count(struct GameInfo *pg)
{
    int i,j;
    int ht=0;
    for(i=0;i<=15;i++)
    {
        for(j=0;j<=15;j++)
        {
            if(pg->m_info[i][j].building.id==2)
            {
                ht+=100;
            }
            if(pg->m_info[i][j].building.id==3)
            {
                ht+=150;
            }
            if(pg->m_info[i][j].building.id==3)
            {
                ht+=200;
            }
            if(pg->m_info[i][j].building.id==17)
            {
                ht+=500;
            }
            if(pg->m_info[i][j].building.id==18)
            {
                ht+=600;
            }
        }
    }
}
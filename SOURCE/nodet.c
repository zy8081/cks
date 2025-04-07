#include <common.h>
#include <game.h>
#include <fun3_2.h>
#include <fun3.h>
#include <WRKMNG.h>
#include <fun5.h>
#include <fun4.h>
#include <nodet.h>
//floor务必大于等于1
nodet *create_nodet_list(int floor)
{
    nodet *p=(nodet *)malloc(sizeof(nodet)*floor);
    int i;
    for (i=0;i<floor;i++)
    {
        (p+i)->next=NULL;
    }
    return p;
}

void lastinsert_nodet_list(nodet *p,int floor,int id)
{
    nodet *temp=(nodet *)malloc(sizeof(nodet)*floor);
    nodet *p1=p+floor-1;
    while(p1->next!=NULL)
    {
        p1=p1->next;
    }
    p1->next=temp;
    temp->next=NULL;
    temp->id=id;
}



void free_nodet_list(nodet *p,int floor)
{
    int i;
    nodet *temp1,*temp2;
    for (i=0;i<floor;i++)
    {
        temp1=p+i;
        temp2=temp1->next;
        while(temp1->next!=NULL)
        {
            temp1=temp2;
            temp2=temp1->next;
            free(temp1);
        }
    }
    free(p);
}
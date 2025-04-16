#include <ALLFUNS.h>

tree *create_buildtech_tree(void)
{
    int i;
	tree *p=create_tree(2);
	tree *temp;
    tree *temp1;
    tree *temp2;
    tree *temp3;

    p->id=1;
    for (i=0;i<PARENT_NUM;i++)
	{
		p->parent[i]=NULL;
	}
    get_tech_basic_info(p,p->type,p->id);

    temp=p;
	for (i=2;i<5;i++)
	{
		insert_simple_leaf(temp,2,i,0);
		temp=temp->child[0];
	}

    temp=p;
	insert_simple_leaf(temp,2,5,1);
    temp=temp->child[1];

    temp1=temp;
    insert_simple_leaf(temp1,2,6,0);
    temp1=temp1->child[0];
    insert_simple_leaf(temp1,2,7,0);
    temp1=temp1->child[0];

    temp2=temp;
	insert_simple_leaf(temp2,2,8,1);
    temp2=temp2->child[1];
    insert_simple_leaf(temp2,2,9,1);
    temp2=temp2->child[1];

    temp3=temp;
    insert_simple_leaf(temp3,2,10,2);
    temp3=temp3->child[2];
    insert_simple_leaf(temp3,2,11,2);
    temp3=temp3->child[2];

    insert_simple_leaf(temp1,2,12,0);
    temp=temp1->child[0];
    //temp2->child[1]=temp;
    //temp3->child[2]=temp;
    temp->parent[0]=temp1;
    temp->parent[1]=temp2;
    temp->parent[2]=temp3;

    temp=p;
    for (i=13;i<15;i++)
	{
		insert_simple_leaf(temp,2,i,2);
		temp=temp->child[2];
	}

    return p;
}

int research_buildtech(struct GameInfo *gameinfop)
{
    int page=4;
	int oldflag=gameinfop->gametech[0].research_flag;
	int newflag=gameinfop->gametech[0].research_flag;
	int new_refreshflag=0;
	int old_refreshflag=0;
	int i,j;
	int location[14][2];

    tree* p=create_buildtech_tree();
}
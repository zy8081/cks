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
    temp2->child[1]=temp;
    temp3->child[2]=temp;
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
	int oldflag=gameinfop->gametech[1].research_flag;
	int newflag=gameinfop->gametech[1].research_flag;
	int new_refreshflag=0;
	int old_refreshflag=0;
	int i,j;
	int location[14][2];

    tree* p=create_buildtech_tree();
    for (i=0;i<14;i++)
	{
		id_find_xy_tech(p,i+1,location);
	}

    draw_tech_line(p);
	draw_tech_tree(p);
	draw_tech_tree2(gameinfop,2,location);
	draw_techpoint(gameinfop);
    draw_researching(gameinfop,2);
    while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);

		if (newflag!=oldflag && newflag==1)
		{
			oldflag=newflag;
			clrmous(MouseX,MouseY); 
			draw_tech_tree2(gameinfop,2,location);
			draw_researching(gameinfop,2);
		}

		if (new_refreshflag !=old_refreshflag)
		{
			new_refreshflag=0;
			clrmous(MouseX,MouseY);
			clear_right_all();
			draw_tech_line(p);
			draw_tech_tree(p);
			draw_tech_tree2(gameinfop,2,location);
			draw_researching(gameinfop,2);
		}

		if (judge_press_mainbutton(4,&page))
		{
			break;
		}
        for (i=0;i<14;i++)
		{
			if (mouse_press(location[i][0]-20,location[i][1]-20,location[i][0]+20,location[i][1]+20)==1)
			{
				clrmous(MouseX,MouseY); 
				draw_tech_toast(p,i+1);
				delay(400);
				while(1)
				{
					mouse_renew(&MouseX,&MouseY,&press);
					
					if (mouse_press(300,450,400,500)==1)
					{
						clrmous(MouseX,MouseY); 
						load_tech_toast();
						delay(300);
						mouse_renew(&MouseX,&MouseY,&press);
						break;
					}
					else if(mouse_press(475,450,625,500)==1)
					{
						clrmous(MouseX,MouseY); 
						clear_right_all();
						display_all_intro(p,gameinfop,2,i+1,&newflag);
						newflag=0;
						new_refreshflag=1;
						break;
					}
					else if(mouse_press(700,450,800,500)==1)
					{
						start_research(gameinfop,p,2,i+1,&newflag);
						clrmous(MouseX,MouseY); 
						load_tech_toast();
						delay(300);
						mouse_renew(&MouseX,&MouseY,&press);
						break;
					}
				}
			}
		}
	
    }
	free_buildtree(p);
	return page;
}

void free_buildtree(tree *buildtreep)
{
    int i;
	tree *temp;
    tree *temp1;
    tree *temp2;
    tree *temp3;

	temp=buildtreep;
    temp1=buildtreep->child[0];
	temp2=buildtreep->child[1];
    temp3=buildtreep->child[2];
    free(temp);
	temp=temp1->child[0];
	free(temp1);
	temp1=temp;
	temp=temp1->child[0];
	free(temp1);
	free(temp);

	temp=temp3->child[2];
	free(temp3);
	free(temp);

	temp=temp2;
	temp1=temp->child[0];
	temp2=temp->child[1];
	temp3=temp->child[2];

	free(temp);
	temp=temp1->child[0];
	free(temp1);
	temp1=temp->child[0];
	free(temp1);
	
	temp=temp2->child[1];
	free(temp2);
	free(temp);

	temp=temp3->child[2];
	free(temp3);
	free(temp);
}
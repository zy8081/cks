#include <ALLFUNS.h>

int research_lifetech(struct GameInfo *gameinfop)
{
	int page=4;
	int oldflag=gameinfop->gametech[0].research_flag;
	int newflag=gameinfop->gametech[0].research_flag;
	int new_refreshflag=0;
	int old_refreshflag=0;
	int i,j;
	int location[10][2];
	tree* p=create_lifetech_tree();
	for (i=0;i<10;i++)
	{
		id_find_xy_tech(p,i+1,location);
	}
	draw_tech_line(p);
	draw_tech_tree(p);
	draw_tech_tree2(gameinfop,1,location);
	draw_techpoint(gameinfop);
	
	draw_researching(gameinfop,1);

	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);

		if (newflag!=oldflag)
		{
			oldflag=newflag;
			clrmous(MouseX,MouseY); 
			draw_tech_tree2(gameinfop,1,location);
			draw_researching(gameinfop,1);
		}

		if (new_refreshflag !=old_refreshflag)
		{
			new_refreshflag=0;
			clrmous(MouseX,MouseY); 
			clear_right_all();
			draw_tech_line(p);
			draw_tech_tree(p);
			draw_tech_tree2(gameinfop,1,location);
			newflag=draw_researching(gameinfop,1);
			oldflag=newflag;
		}
		if (newflag==1)
		{
			if(mouse_press(750,700,900,750)==1)
			{
				clrmous(MouseX,MouseY); 
				clear_right_all();
				display_all_intro(p,gameinfop,1,gameinfop->gametech[0].id,&newflag);
				new_refreshflag=1;
			}
			if(mouse_press(300,700,450,750)==1)
			{
				clrmous(MouseX,MouseY); 
				stop_researching(gameinfop,1,&newflag,&new_refreshflag);
			}
		}

		if (judge_press_mainbutton(4,&page))
		{
			break;
		}

		//i´úÖ¸id
		for (i=0;i<10;i++)
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
						display_all_intro(p,gameinfop,1,i+1,&newflag);
						newflag=0;
						new_refreshflag=1;
						break;
					}
					else if(mouse_press(700,450,800,500)==1)
					{
						start_research(gameinfop,p,1,i+1,&newflag);
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

	free_tree(p);
	return page;
}

tree *create_lifetech_tree(void)
{
	int i;
	tree *p=create_tree(1);
	tree *temp;
	p->id=1;
	for (i=0;i<PARENT_NUM;i++)
	{
		p->parent[i]=NULL;
	}
	get_tech_basic_info(p,p->type,p->id);
	temp=p;
	for (i=2;i<5;i++)
	{
		insert_simple_leaf(temp,1,i,0);
		temp=temp->child[0];
	}
	temp=p;
	insert_simple_leaf(temp,1,5,1);
	temp=temp->child[1];
	insert_simple_leaf(temp,1,6,0);
	insert_simple_leaf(temp,1,7,1);
	temp=p;
	for (i=8;i<11;i++)
	{
		insert_simple_leaf(temp,1,i,2);
		temp=temp->child[2];
	}
	return p;
}
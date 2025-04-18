#include<ALLFUNS.h>

int proj_fun5(struct GameInfo* gameinfop,nodebq *p,WORKFILE work,int(*events)[2])
{
	int page=5;
	char *s[3]={"时间流动","模拟日志","保存游戏"};
	int l=65;
	draw_main_toolbotton_activate(866,0xBDBD,"时间","显示");
	
	draw_all_leftbuttons(3,65,s);
	
	//drawmous(MouseX,MouseY);
	
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if(main_toolbotton_mouse_press(1)==1)//now==66防止与下面主栏返回键被点中的情况冲突
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(866,0xBDBD,"时间","显示");
            clear_main_all();
			clear_right_all();
            return 1;
            
        }
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(866,0xBDBD,"时间","显示");
            clear_main_all();
			clear_right_all();
            return 2;

        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(866,0xBDBD,"时间","显示");
            clear_main_all();
			clear_right_all();
            return 3;
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(866,0xBDBD,"时间","显示");
            clear_main_all();
			clear_right_all();
            return 4;
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(866,0xBDBD,"时间","显示");
            clear_main_all();
			clear_right_all();
            return 5;
        }
		
		if (left_toolbotton_mouse_press(1) == 1) //左栏被点中的情况
        {
			
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , l, s[0]);//激活新的
            clear_right_all();
            page=proj_fun5_1(gameinfop,p,events);

            return page;   
		}
		else if (left_toolbotton_mouse_press(2) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , l, s[1]);//激活新的
            clear_right_all();
            //page=build(gameinfop);
            return page;   
		}
		
		else if (left_toolbotton_mouse_press(3) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , l, s[2]);//激活新的
            clear_right_all();
            page = save_gminfo(*gameinfop,work,5);
			save_node(work,*p);
            return page;   
		}
	}
}


int proj_fun5_1(struct GameInfo *gameinfop,nodebq *p,int (*events)[2])
{
	char *text[10];
	clrmous(MouseX,MouseY);
	draw_fun5_1();
	
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if(main_toolbotton_mouse_press(1)==1)//now==66防止与下面主栏返回键被点中的情况冲突
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(866,0xBDBD,"时间","显示");
            clear_main_all();
			clear_right_all();
            return 1;
            
        }
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(866,0xBDBD,"时间","显示");
            clear_main_all();
			clear_right_all();
            return 2;

        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(866,0xBDBD,"时间","显示");
            clear_main_all();
			clear_right_all();
            return 3;
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(866,0xBDBD,"时间","显示");
            clear_main_all();
			clear_right_all();
            return 4;
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(866,0xBDBD,"时间","显示");
            clear_main_all();
			clear_right_all();
            return 5;
        }
		
		if (mouse_press(300,300,390,330)==1)
		{
			int cevent;
			
			gameinfop->month++;
			if(gameinfop->month==13)
			{
				gameinfop->month=1;
				gameinfop->year++;
			}
			clrmous(MouseX,MouseY); 
			clear_right_all();
			clear_time();
			//
			/*srand((unsigned) time(NULL));
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
					break;
            	while(1)
            	{
                
                	(*events)[0]=rand()%6+1;
                	(*events)[1]=rand()%6+1;
                	if(((*events)[0])!=((*events)[1])) break; 
                 
            	}
				
				
				getch();
            	//eventshow(revent1);
            	//eventshow(revent2);
            	break;
			}*/
			eventsc(events);
			
			time_flow(gameinfop,p);
			draw_time(gameinfop);
			break;
		}
	}
	return 5;
}

void draw_fun5_1(void)
{
	puthz(300,300,"下个月", 32,40, 1);
}

void time_flow(struct GameInfo *gameinfop,nodebq *p)
{
	int data[8];
	int i,j;
	nodebq *temp=p;
	calculate_monthly_income(gameinfop,data);
	gameinfop->r_info.nanomaterial+=data[0];
	gameinfop->r_info.rarematerial+=data[1];
	gameinfop->r_info.oxygen+=data[2];
	gameinfop->r_info.water+=data[3];
	gameinfop->r_info.food+=data[4];
	gameinfop->r_info.energy+=data[5];
	gameinfop->r_info.fuel+=data[6];
	gameinfop->r_info.mineral+=data[7];
	
	for (i=0;i<p->i;i++)
	{
		temp=temp->next;
		if (temp==NULL)
		{
			break;
		}
		gameinfop->m_info[temp->i][temp->j].building.bui_time--;
		if (gameinfop->m_info[temp->i][temp->j].building.bui_time==0)
		{
			headremove_nodebq(p);
		}
	}

	
	for (i=0;i<3;i++)
	{
		gameinfop->gametech[i].havepoints += gameinfop->techpoint;
		if (gameinfop->gametech[i].havepoints>=gameinfop->gametech[i].totalpoints)
		{
			gameinfop->gametech[i].research_flag=0;
			change_techflag(gameinfop->gametech[i].type,gameinfop->gametech[i].id);
		}
	}

}



nodes *create_nodes(void)
{
	nodes *p=(nodes *)malloc(sizeof(nodes));
	p->next=NULL;
	return p;
}

void headinsert_nodes(nodes *p,int i,int j)
{
	nodes *temp=(nodes *)malloc(sizeof(nodes));
	temp->next=p->next;
	p->next=temp;
	temp->i=i;
	temp->j=j;
}

void fputdata_nodes(nodes *p,struct GameInfo *gameinfop,FILE *file)
{
	nodes *temp;
	char str[30];
	temp=p->next;
	while (temp!=NULL)
	{
		fprintf(file,itoa(temp->i,str,10));
		fputc(' ',file);
		fprintf(file,itoa(temp->j,str,10));
		fputc(' ',file);
		
		fprintf(file,itoa(gameinfop->m_info[temp->i][temp->j].building.id,str,10));
		fputc(' ',file);
		
		fprintf(file,gameinfop->m_info[temp->i][temp->j].building.name);
		fputc(' ',file);
		
		fprintf(file,gameinfop->m_info[temp->i][temp->j].building.pic_path);
		fputc(' ',file);
		
		fprintf(file,itoa(gameinfop->m_info[temp->i][temp->j].building.res_cost.nanomaterial,str,10));
		fputc(' ',file);
		
		fprintf(file,itoa(gameinfop->m_info[temp->i][temp->j].building.res_cost.rarematerial,str,10));
		fputc(' ',file);
		
		fprintf(file,itoa(gameinfop->m_info[temp->i][temp->j].building.res_add.nanomaterial,str,10));
		fputc(' ',file);
		
		fprintf(file,itoa(gameinfop->m_info[temp->i][temp->j].building.res_add.rarematerial,str,10));
		fputc(' ',file);
		
		fprintf(file,itoa(gameinfop->m_info[temp->i][temp->j].building.res_add.oxygen,str,10));
		fputc(' ',file);
		
		fprintf(file,itoa(gameinfop->m_info[temp->i][temp->j].building.res_add.water,str,10));
		fputc(' ',file);
		
		fprintf(file,itoa(gameinfop->m_info[temp->i][temp->j].building.res_add.food,str,10));
		fputc(' ',file);
		
		fprintf(file,itoa(gameinfop->m_info[temp->i][temp->j].building.res_add.energy,str,10));
		fputc(' ',file);
		
		fprintf(file,itoa(gameinfop->m_info[temp->i][temp->j].building.res_add.fuel,str,10));
		fputc(' ',file);
		
		fprintf(file,itoa(gameinfop->m_info[temp->i][temp->j].building.res_add.mineral,str,10));
		fputc(' ',file);
		
		fprintf(file,itoa(gameinfop->m_info[temp->i][temp->j].building.bui_time,str,10));
		fputc('\n',file);
		
		temp=temp->next;
	}
}

void free_nodes(nodes *p)
{
	nodes *temp;
	while(p!=NULL)
	{
		temp=p->next;
		free(p);
		p=temp;
	}
}
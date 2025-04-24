#include<ALLFUNS.h>

int proj_fun5(struct GameInfo* gameinfop,nodebq *p,WORKFILE* pwork,int(*events)[2])
{
	int page=5;
	char *s[5]={"时间流动","模拟日志","保存游戏","退出游戏","说明文档"};
	int l=65;
	draw_main_toolbotton_activate(866,0xBDBD,"时间","显示");
	
	draw_all_leftbuttons(5,65,s);
	
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
            page=timeflow(gameinfop,p,events,pwork);
			if(page==666)
			{
				event_fail(gameinfop,pwork);
				save_gminfo(gameinfop,pwork,5);
				return 11;
			}
            return page;   
		}
		else if (left_toolbotton_mouse_press(2) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , l, s[1]);//激活新的
            clear_right_all();
            page=log_display(pwork->path);
            return page;   
		}
		
		else if (left_toolbotton_mouse_press(3) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , l, s[2]);//激活新的
            clear_right_all();
            page = save_gminfo(gameinfop,pwork,5);
			save_node(pwork,p);
			file_save(pwork->path);
			file_copy(pwork->path);
			logfile_copy(pwork->path);
            return page;   
		}
		else if (left_toolbotton_mouse_press(4) == 1) //左栏被点中的情况
        {
			//exit(1);
			int restyle;
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , l, s[3]);//激活新的
            clear_right_all();
			restyle=quit();
			if(restyle>100)
			{
				if(restyle%10==1)
				{
					save_gminfo(gameinfop,pwork,5);
					save_node(pwork,p);
					file_save(pwork->path);
					file_copy(pwork->path);
					logfile_copy(pwork->path);
				}
				return (restyle-restyle%10)/10;
			}
			else return restyle;
			
		}
		else if (left_toolbotton_mouse_press(5) == 1) //左栏被点中的情况
        {
			clrmous(MouseX,MouseY);
			intro_book(1);
		}
	}
}

void draw_timeflow_remind(struct GameInfo* gameinfop,nodebq *p,char *path)
{
	char str[40];
	char name[30];
	int i,j,k;
	int month;
	nodebq *temp=p->next;
	char *tech[3]={"民生科技","建造科技","生产科技"};
	puthz2(650,130,32,32,0xA000,"待做项提示：");
	for (i=0,j=0;i<3;i++)
	{
		if (gameinfop->gametech[i].research_flag==0)
		{
			sprintf(str,"%s未进行研究",tech[i]);
			puthz3(650,170+j*50,32,32,0xA000,str);
			j++;
		}
		else
		{
			month=(gameinfop->gametech[i].totalpoints-gameinfop->gametech[i].havepoints)/gameinfop->techpoint+1;
			sprintf(str,"%s研究中：",tech[i]);
			puthz3(650,170+j*50,32,32,1000,str);
			j++;
			// type_id_find_name(gameinfop->gametech[i].type,gameinfop->gametech[i].id,name);
			// sprintf(str,"“%s”",name);
			// puthz3(650,170+j*50,32,32,1000,str);
			// j++;
			sprintf(str,"还需研究%d个月",month);
			put_hz24_asc32(650,170+j*50,str,1000,"HZK\\Hzk24k");
			j++;
		}
	}
	
	if (gameinfop->rocket.apply==-1)
	{
		puthz3(650,170+j*50,32,32,0xA000,"还未申请地球支援火箭");
		j++;
		// sprintf(str,"窗口期在%d年%d月",gameinfop->rocket.year,gameinfop->rocket.month);
		// put_hz24_asc32(650,170+j*50,str,0xA000,"HZK\\Hzk24k");
	}
	else if(gameinfop->rocket.apply==1 ||gameinfop->rocket.apply==2)
	{
		puthz3(650,170+j*50,32,32,1000,"已申请地球支援火箭");
		j++;
		sprintf(str,"支援将在%d年%d月到达",gameinfop->rocket.year,gameinfop->rocket.month);
		put_hz24_asc32(650,170+j*50,str,1000,"HZK\\Hzk24k");
		j++;
	}
	for (i=0,k=0;i<p->i;i++)
	{
		if (temp!=NULL)
		{
			k++;
			temp=temp->next;
		}
		else
		{
			break;
		}
	}
	if (k<p->i)
	{
		j++;
		sprintf(str,"建造队列未满%d/%d",k,p->i);
		put_hz24_asc32(650,170+j*50,str,0xa000,"HZK\\Hzk24k");
	}
	if(k==p->i)
	{
		j++;
		sprintf(str,"建造队列已满%d/%d",k,p->i);
		put_hz24_asc32(650,170+j*50,str,1000,"HZK\\Hzk24k");
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
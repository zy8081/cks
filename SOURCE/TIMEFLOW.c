#include<ALLFUNS.h>
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
	clear_time();
	gameinfop->month++;
	if(gameinfop->month==13)
	{
		gameinfop->month=1;
		gameinfop->year++;
	}
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			
			if(gameinfop->m_info[i][j].building.id==8)
			{
				if(gameinfop->m_info[i][j].mineral>100)
				{
					gameinfop->m_info[i][j].mineral-=100;
					gameinfop->r_info.mineral+=100;
				}
				else
				{
					gameinfop->m_info[i][j].mineral=0;
					gameinfop->r_info.mineral+=0;
				} 
			}
		}
	}
	people_cost(gameinfop);
	
}

void timeflow_more(struct GameInfo *gameinfop,nodebq *p,int n)
{
	int i,j;
	int events[36][2];
	
	int temp[2];
	char t[20];
	int page=1;
	int nx=0;
	int year=gameinfop->year;
	int month=gameinfop->month;
	int tyear=year;
	int tmonth=month;
	int pagemax;
	srand(time(NULL));
	for(i=0;i<36;i++)
	{
		events[i][0]=0;
		events[i][1]=0;
	}
	for(i=0;i<n;i++)
	{
		time_flow(gameinfop,p);
		eventsc(&temp);
		events[i][0]=temp[0];
		events[i][1]=temp[1];
		rocket_data(gameinfop);
		for(j=0;j<2;j++)
		{
			switch(events[i][j])
			{
				case 1:
					scb_data(gameinfop);
					break;
				case 2:
					yj_data(gameinfop);
					break;
				case 3:
					dz_data(gameinfop);
					break;
				case 4:						
					yq_data(gameinfop);
					break;
				case 5:
					sbgz_data(gameinfop);
					break;
				case 6:
					yz_data(gameinfop);
					break;				
			}
		}
	}
		//sprintf(t,"%d,%d,%d,%d,%d,%d",events[0][0],events[0][1],events[1][0],events[1][1],events[2][0],events[2][1]);
		
		for(i=0;i<36;i++)
		{
			if(events[i][0]!=0||events[i][1]!=0||(year==gameinfop->rocket.year&&month==gameinfop->rocket.month))
				nx++;
			month++;
			if(month==13)
			{
				month=1;
				year++;
			}
		}
			
		
		if(nx%5==0)pagemax=nx/5;
		else pagemax=nx/5+1;
		sprintf(t,"%d",nx);
		put_hz24_asc32(0,0,t,0,"HZK//HZK24");
		clrmous(MouseX,MouseY);
		SaveBMP(238,568,1024,768,16);
		menuprt(238,568,1024,768);
		btn_bar_Draw(240,570,290,610);
    	line_thick(240,570,290,610,2,0);
    	line_thick(240,610,290,570,2,0);
		//bar(240,570,290,610,0);
		clear_time();
		draw_time(gameinfop);
		event_prt(gameinfop,events,page,nx,tyear,tmonth);
		while(1)
		{
			mouse_renew(&MouseX,&MouseY,&press);
			if(mouse_press(240,570,290,610)==1)
			{
				return;
			}
			else if(mouse_press(900,720,990,750)==1)
			{
				if(page<pagemax)
				{
					page++;
					event_prt(gameinfop,events,page,nx+1,tyear,tmonth);
				}
			}
			else if(mouse_press(800,720,890,750)==1)
			{
				if(page>1)
				{
					page--;
					event_prt(gameinfop,events,page,nx+1,tyear,tmonth);
				}
			}
		}
	return;
}

void event_prt(struct GameInfo *pg,int (*allevent)[2],int page,int n,int tyear,int tmonth)
{	
	int i=0;
	int j;
	int k=0;
	int pagemax;
	char*e[6]={"沙尘暴","技术突破","地震","氧气泄露","设备故障","国际援助"};
	char cpage[10];
	int range=0;
	if(n%5==0)pagemax=n/5;
	else pagemax=n/5+1;
	clrmous(MouseX,MouseY);
	menuprt(238,568,1024,768);
	put_hz24_asc32(300,570,"期间事件：",65535,"HZK//HZK24");
	btn_bar_Draw(240,570,290,610);
    line_thick(240,570,290,610,2,0);
    line_thick(240,610,290,570,2,0);
	while(i<n&&k<5)
	{
		if(i>(page-1)*5)
		{
			char s[30];
			int range=0;
			sprintf(s,"%d年%d月",tyear,tmonth);
			put_hz24_asc32(238,600+k*30,s,65535,"HZK\\HZK24");
			if(tyear==pg->rocket.year&&tmonth==pg->rocket.month)
			{
				put_hz24_asc32(388+range*120,600+k*30,"火箭到达",65535,"HZK\\HZK24");
				range++;
			}
			if(allevent[i][0]!=0)
			{
				put_hz24_asc32(388+range*120,600+k*30,e[allevent[i][0]-1],65535,"HZK\\HZK24");
				range++;
			}
			if(allevent[i][1]!=0)
			{
				put_hz24_asc32(388+range*120,600+k*30,e[allevent[i][1]-1],65535,"HZK\\HZK24");
				range++;
			}
			k++;
			range=0;
		}
		tmonth++;
		if(tmonth==13)
		{
			tyear++;
			tmonth=1;
		}
		i++;
		

			/*
				if(j<(page-1)*5+1)
				{
					i++;
					tmonth++;
				if(tmonth==13)
				{
					tyear++;
					tmonth=1;
				}
					continue;
				}
				else
				{
					char s[30];
					int range=0;
					sprintf(s,"%d年%d月",tyear,tmonth);
					put_hz24_asc32(238,600+k*30,s,65535,"HZK\\HZK24");
					{
						if(tyear==pg->rocket.year&&tmonth==pg->rocket.month)
						{
							put_hz24_asc32(338+range*120,600+k*30,"火箭到达",65535,"HZK\\HZK24");
							range++;
						}
						if(allevent[i][0]!=0)
						{
							put_hz24_asc32(338+range*120,600+k*30,e[allevent[i][0]-1],65535,"HZK\\HZK24");
							range++;
						}
						if(allevent[i][1]!=0)
						{
							put_hz24_asc32(338+range*120,600+k*30,e[allevent[i][1]-1],65535,"HZK\\HZK24");
							range++;
						}
					}
					break;*/
	}

	sprintf(cpage,"第%d页",page);
	put_hz24_asc32(950,700,cpage,65535,"HZK\\HZK24");
	if(page==1)
	{
		btn_bar_Draw1(800,720,890,750);
		put_hz24_asc32(810,700,"上一页",65535,"HZK\\HZK24");
		if(pagemax>1)
		{
			btn_bar_Draw(900,720,990,750);
			put_hz24_asc32(910,700,"下一页",65535,"HZK\\HZK24");
			btn_bar_Draw1(800,720,890,750);
			put_hz24_asc32(810,700,"上一页",65535,"HZK\\HZK24");
		}
		else
		{
			btn_bar_Draw1(900,720,990,750);
			put_hz24_asc32(910,700,"下一页",65535,"HZK\\HZK24");
			btn_bar_Draw1(800,720,890,750);
			put_hz24_asc32(810,700,"上一页",65535,"HZK\\HZK24");
		}
		
	}
	else if(page==pagemax)
	{
		btn_bar_Draw(800,720,890,750);
		put_hz24_asc32(910,700,"上一页",65535,"HZK\\HZK24");
		btn_bar_Draw1(900,720,990,750);
		put_hz24_asc32(910,700,"下一页",65535,"HZK\\HZK24");
	}
	else
	{
		btn_bar_Draw(800,720,890,750);
		put_hz24_asc32(910,700,"上一页",65535,"HZK\\HZK24");
		btn_bar_Draw(900,720,990,750);
		put_hz24_asc32(910,700,"下一页",65535,"HZK\\HZK24");
	}
	return;		
}


	


int time_warning()//0否1是2退出
{
	clrmous(MouseX,MouseY);
	SaveBMP(277,300,747,620,13);
	menuprt(277,300,747,620,0);
	puthz2(470,310,32,40,53744,"警告");
    
    put_hz24(290,350,"时间流动过快会一次性消耗大量资源",65535,"HZK\\HZK24",0);
	put_hz24(390,380,"可能一次面对过多灾害",65535,"HZK\\HZK24",0);
	put_hz24(420,410,"结果并不可控",65535,"HZK\\HZK24",0);
	put_hz24_asc32(420,450,"是否要继续？",53744,"HZK\\HZK24");

	btn_bar_Draw(430,500,500,538);
    btn_bar_Draw(537,500,607,538);
    put_hz24(445,507,"是",65535,"HZK//HZK24",0);
    put_hz24(560,507,"否",65535,"HZK//HZK24",0);

	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		{
			if(mouse_press(430,500,500,538)==1)
			{
				LoadBMP(277,300,747,620,13);
				press=0;
				delay(300);
				return 1;
			}
			else if(mouse_press(537,500,607,538)==1)
			{
				LoadBMP(277,300,747,620,13);
				press=0;
				delay(300);
				return 0;
			}

		}
	}
    
}

int time_comf(int t)
{
	char ques[30];
	clrmous(MouseX,MouseY);
	SaveBMP(370,293,657,478,15);
	menuprt(370,293,657,478);
	if(t==12)
		put_hz24_asc32(380,298,"是否确定时间流动一年",65535,"HZK//HZK24");
	else
	{
		sprintf(ques,"是否确定时间流动%d个月?",t);
		put_hz24_asc32(380,298,ques,65535,"HZK//HZK24");
	}
	btn_bar_Draw(430,400,500,438);
    btn_bar_Draw(537,400,607,438);
    put_hz24(445,407,"是",65535,"HZK//HZK24",0);
    put_hz24(564,407,"否",65535,"HZK//HZK24",0);
	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if(mouse_press(430,400,500,438)==1)
		{
			clrmous(MouseX,MouseY);
			LoadBMP(370,293,657,478,15);
			press=0;
			delay(300);
			return 1;
		}
		else if(mouse_press(537,400,607,438)==1)
		{
			clrmous(MouseX,MouseY);
			LoadBMP(370,293,657,478,15);
			press=0;
			delay(300);
			return 0;
		}
	}
}

void timeflow_prt()
{
	btn_bar_Draw(250,110,900,210);	
	btn_bar_Draw(250,220,900,320);
	btn_bar_Draw(250,330,900,430);
	btn_bar_Draw(250,440,900,540);
	btn_bar_Draw(250,550,900,650);

	puthz2(270,140,32,40,0,"时间流动一个月");
	puthz2(270,250,32,40,0,"时间流动三个月");
	puthz2(270,360,32,40,0,"时间流动六个月");
	puthz2(270,470,32,40,0,"时间流动一年");
	puthz2(270,580,32,40,0,"自定义流动时间");
}

void test()
{
	return;
}

int timeflow(struct GameInfo*pg, nodebq* p,int (*event)[2],WORKFILE* pw)
{
	int t_flow=0;
	int page=5;
	clrmous(MouseX,MouseY);
	timeflow_prt();
	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if(judge_press_mainbutton(5,&page)==1)
		{
			return page;
		}
		else if(mouse_press(250,110,900,210)==1)
		{
			if(time_comf(1)==1)
			{
				eventsc(event);
				time_flow(pg,p);
				eventshow(*event,pg);
				(*event)[0]=0;
				(*event)[1]=0;
				clear_time();
				draw_time(pg);
				clear_right_all();
				//if(fail_judge(pg)==1)
					//{
						//pg->fail=1;
						//return 666;
					//}
				return 5;
			}
			clear_right_all();
			return 5;
		}
		else if(mouse_press(250,220,900,320)==1)
		{
			if(time_comf(3)==1)
			{
				timeflow_more(pg,p,3);
				//eventshow(*event,gameinfop);
				clear_time();
				draw_time(pg);
				clear_right_all();
				//if(fail_judge(pg)==1)
					//{
						//pg->fail=1;
						//return 666;
					//}
				return 5;
			}
			clear_right_all();
			return 5;
				
		}
		else if(mouse_press(250,320,900,420)==1)
		{
			if(time_comf(6)==1)
			{
				if(time_warning()==1)
				{
					timeflow_more(pg,p,6);
					clear_time();
					draw_time(pg);
				//eventshow(*event,gameinfop);
					clear_right_all();
					//if(fail_judge(pg)==1)
					//{
						//pg->fail=1;
						//return 666;
					//}
					return 5;
				}
			}
			clear_right_all();
			return 5;		
		}
		else if(mouse_press(250,420,900,520)==1)
		{
			if(time_comf(12)==1)
			{
				if(time_warning()==1)
				{
					timeflow_more(pg,p,12);
					clear_time();
					draw_time(pg);
					clear_right_all();
					//eventshow(*event,gameinfop);
					//if(fail_judge(pg)==1)
					//{
						//pg->fail=1;
						//return 666;
					//}
					return 5;
				}
			}
			clear_right_all();
			return 5;
		}
		else if(mouse_press(250,550,900,650)==1)
		{
			int n;
			SaveBMP(317,300,707,520,13);
			
			n=time_set();
			if(n>0)
			{
				if(n>=6)
				{
					if(time_warning()==1)
					{
						LoadBMP(317,300,707,520,13);
						timeflow_more(pg,p,n);
						clear_time();
						draw_time(pg);
						clear_right_all();
						//if(fail_judge(pg)==1)
						//{
							//pg->fail=1;
							//return 666;
						//}
						return 5;
					}
					else 
					{
						clear_right_all();
						return 5;
					}
				}
				else
				{
					timeflow_more(pg,p,n);
					clear_time();
					draw_time(pg);
					clear_right_all();
					//if(fail_judge(pg)==1)
					//{
					//	pg->fail=1;
					//	return 666;
					//}
					return 5;
				}
					
			}
			clear_right_all();
			return 5;
		}
	
	}
}

int time_set()
{
	int renum=-1;
	clrmous(MouseX,MouseY);
	
	menuprt(317,300,707,470,0);
	
	btn_bar_Draw(430,420,500,458);
    btn_bar_Draw(537,420,607,458);
    put_hz24(430,423,"确定",65535,"HZK//HZK24",0);
    put_hz24(545,423,"取消",65535,"HZK//HZK24",0);

	put_hz24_asc32(337,320,"点击输入流动时间(月),最大36",65535,"HZK//HZK24");
	bar(430,360,550,390,0);

	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if(mouse_press(430,360,550,390)==1)
		{
			renum=time_input(430,360,550,390,36,2);
		}
		else if(mouse_press(430,420,500,458)==1)
		{
			if(renum!=-1)
				return renum;
			else
			{
				bar(480,360,520,390,0);
				put_hz24(485,362,"输入非法",65535,"HZK\\HZK24",0);
			}
		}
		else if(mouse_press(537,420,607,458)==1)
			return 0;
	}
}

int time_input(int x1,int y1,int x2,int y2,int max,int n)//-1表示未输入
{
    char*inputnum=malloc((size_t)40);
    int i=0;
    int in=0;
    long unsigned int renum;
    char test[3];
    inputnum[0]='\0';
    bar(x1,y1,x2,y2,0);
    inputs(x1,y1,inputnum,n);
    if(inputnum[0]=='\0')return -1;
    while(inputnum[i]!='\0')
    {
        if(inputnum[i]>='0'&&inputnum[i]<='9')i++;
        else 
        {
            bar(x1,y1,x2,y2,0);
            put_hz24(x1+5,y1+2,"字符非法",65535,"HZK\\HZK24",0);
            free(inputnum);
            return -1;
        }
    }
    while(inputnum[in]!='\0')
    {
        in++;
    }
    if(in==5)
    {
        if(inputnum[0]>='5')
        {
			bar(x1,y1,x2,y2,0);
            put_hz24(x1+5,y1+2,"数字过大",65535,"HZK\\HZK24",0);
            free(inputnum);
            return -1;
        }
        else
        {
            renum=atoi(inputnum);
            if(renum<=max&&atoi(inputnum)>=0)
            {
                free(inputnum);
                return renum;
            }
        
            else
            {
                bar(x1,y1,x2,y2,0);
            	put_hz24(x1+5,y1+2,"数字过大",65535,"HZK\\HZK24",0);
                free(inputnum);
                return -1;
            }
        }
    }
    else if(in>5)
    {
        bar(x1,y1,x2,y2,0);
        put_hz24(x1+5,y1+2,"数字过大",65535,"HZK\\HZK24",0);
        free(inputnum);
        return -1;
	}
    else
    {
        renum=atoi(inputnum);
        if(renum<=max&&atoi(inputnum)>=0)
        {
            free(inputnum);
            return renum;
        }   
        else
        {
            bar(x1,y1,x2,y2,0);
            put_hz24(x1+5,y1+2,"数字过大",65535,"HZK\\HZK24",0);
            free(inputnum);
            return -1;
        }
    }
}
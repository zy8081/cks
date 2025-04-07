#include<ALLFUNS.h>
void project(WORKFILE w,int*page)
{

	char test[4];
	struct GameInfo gameinfo;
	int proj_page=0;
	nodebq *p1=load_node(w);
	int events[2]={0,0};
	int xsel=0;
	int ysel=0;
	//fread(&gameinfo,sizeof(struct GameInfo),1,f);
	load_gminfo(w,&gameinfo);
	clrmous(MouseX,MouseY); 
	delay(100); 
	
	cleardevice();
	
	//itoa(events[0]+events[1]*10,test,10);

	while (1)
	{
		
		switch(proj_page)
		{
			eventshow(events,&gameinfo);

			case 0:
				proj_page=proj_origin(&gameinfo,&xsel,&ysel);
				break;
			case 1:
				proj_page=proj_fun1(&gameinfo,&xsel,&ysel);
				break;
			case 2:
				proj_page=proj_fun2(&gameinfo);
				break;
			case 3:
				proj_page=proj_fun3(&gameinfo,p1,&xsel,&ysel);
				break;
			case 4:
				
				proj_page=proj_fun4(&gameinfo);
				break;
			case 5:
				
				proj_page=proj_fun5(&gameinfo,p1,w,&events);
				eventshow(events,&gameinfo);
				events[0]=0;
				events[1]=0;
				//put_asc16(100,100,test,0);
				break;
		}
	}
	//fclose(f);
	return;
}
int proj_fun1(struct GameInfo* gameinfop,int*pxsel,int*pysel)
{
	int page1=1;
	int flag=0;
	int now=66; 
	int i;
	int l=65;
	char *s[2]={"打开地图","还没想好"};
	draw_main_toolbotton_activate(234,0xBD32,"地图","显示");
	cleankey();
	draw_all_leftbuttons(2,65,s);
	//draw_map(300,105,954,759,7,7,gameinfop);
	draw_mainmap(*gameinfop,*pxsel,*pysel);
	draw_minimap(*gameinfop,*pxsel,*pysel);
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if(flag==1)
		{
			
		}
		//主控键
		if(main_toolbotton_mouse_press(1)==1)//now==66防止与下面主栏返回键被点中的情况冲突
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(234,0xBD32,"地图","显示");
            clear_main_all();
			clear_right_all();
            return 1;
            
        }
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(234,0xBD32,"地图","显示");
            clear_main_all();
			clear_right_all();
            return 2;

        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(234,0xBD32,"地图","显示");
            clear_main_all();
			clear_right_all();
            return 3;
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(234,0xBD32,"地图","显示");
            clear_main_all();
			clear_right_all();
            return 4;
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(234,0xBD32,"地图","显示");
            clear_main_all();
			clear_right_all();
            return 5;
        }
		//左侧键
		for (i=0; i < 2; i++) 
        {
            if (left_toolbotton_mouse_press(i+1) == 1) //左栏被点中的情况
            {
                clrmous(MouseX,MouseY); 
                draw_left_toolbotton(95 + (now)*l, l, s[now]);//还原旧的
                now = i;
                draw_left_toolbotton_activate(95 + i*l, l, s[i]);//激活新的
                clear_right_all();
                
                flag=1;//启用跳转
            
                //draw_which_introduce(i);//选择当前的介绍
                //draw_main_toolbotton_activate(234,0xBD32,"","");
                //draw_arrowbotton(295, 23);//画出返回箭头

                //mouse_on(mouse);
                continue;
            }
		}
		if(renew_map(pxsel,pysel)==1)
		{
			draw_minimap(*gameinfop,*pxsel,*pysel);
			draw_mainmap(*gameinfop,*pxsel,*pysel);
		}

	}
}

int proj_fun2(struct GameInfo* gameinfop)
{
	int page=2;
	int page2=0;
	int now=0;
	int flag=0;
	int l=65;
	int i;
	char *s[2]={"资源统计","资源收支"};
	draw_main_toolbotton_activate(392,0xFFAA,"全局","资源");
	
	
	draw_all_leftbuttons(2,65,s);
	
	//drawmous(MouseX,MouseY);
	
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if(main_toolbotton_mouse_press(1)==1)//now==66防止与下面主栏返回键被点中的情况冲突
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"全局","资源");
            clear_main_all();
			clear_right_all();
            return 1;
            
        }
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"全局","资源");
            clear_main_all();
			clear_right_all();
            return 2;

        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"全局","资源");
            clear_main_all();
			clear_right_all();
            return 3;
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"全局","资源");
            clear_main_all();
			clear_right_all();
            return 4;
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"全局","资源");
            clear_main_all();
			clear_right_all();
            return 5;
        }
		
		if (left_toolbotton_mouse_press(1) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            //clear_main_all();
            draw_left_toolbotton_activate(95 , l, s[0]);//激活新的
            clear_right_all();
            proj_fun2_1(gameinfop);
            continue;
		}
	}
}

void proj_fun2_1(struct GameInfo *gameinfop)
{
	clrmous(MouseX,MouseY); 
	get_all_resourceinfo(gameinfop);
}

void get_all_resourceinfo(struct GameInfo *gameinfop)
{
	char *s[8]={"纳米材料","稀有材料","氧气","淡水","食物","能源","燃料","矿物"};
	long int data1[8];
	int data2[8];
	
	
	char str[30]={'\0'};
	int i,j;
	data1[0]=gameinfop->r_info.nanomaterial;
	data1[1]=gameinfop->r_info.rarematerial;
	data1[2]=gameinfop->r_info.oxygen;
	data1[3]=gameinfop->r_info.water;
	data1[4]=gameinfop->r_info.food;
	data1[5]=gameinfop->r_info.energy;
	data1[6]=gameinfop->r_info.fuel;
	data1[7]=gameinfop->r_info.mineral;
	calculate_monthly_income(gameinfop,data2);

	puthz(240, 110,"资源统计：",48,48,1);
	puthz(600, 110,"资源月收支：",48,48,1);
	for (j=0;j<8;j++)
	{
		i=0;
		while(str[i]!='\0')
		{
			str[i++]='\0';
		}
		sprintf(str,"%s:%d",s[j],data1[j]);
		put_hz24_asc32(260,190+j*55,str,1,"HZK\\Hzk24k");
		
		while(str[i]!='\0')
		{
			str[i++]='\0';
		}
		sprintf(str,"%s:%d",s[j],data2[j]);
		put_hz24_asc32(600,190+j*55,str,1,"HZK\\Hzk24k");
	}
}

void calculate_monthly_income(struct GameInfo *gameinfop,int *data)
{
	int i,j,k;
	int income;
	
	k=0;
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.nanomaterial;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.rarematerial;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.oxygen;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.water;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.food;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.energy;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.fuel;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.mineral;
			}
		}
	}
	data[k]=income;
	k++;
}


int proj_fun3(struct GameInfo *gameinfop,nodebq *p,int*pxsel,int*pysel)
{
	int page=3;
	int flag=0;
	int l=65;
	
	char *s[2]={"新建建筑","建造队列"};
	draw_main_toolbotton_activate(550,0xBBBB,"建造","显示");
	
	draw_all_leftbuttons(2,65,s);
	
	//drawmous(MouseX,MouseY);
	
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if(main_toolbotton_mouse_press(1)==1)//now==66防止与下面主栏返回键被点中的情况冲突
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            return 1;
            
        }
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            return 2;

        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            return 3;
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            return 4;
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
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
            page=build(gameinfop,p,pxsel,pysel);
            return page;   
		}
		else if (left_toolbotton_mouse_press(2) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , l, s[1]);//激活新的
            clear_right_all();
            page=build_queue(gameinfop,p);
            return page;   
		}
	}
}

int build_queue(struct GameInfo *gameinfop,nodebq *p)
{
	int i,j,k;
	int totalpage;
	int len;
	int oldpage=1;
	int newpage=1;
	char str[20]={'\0'};
	int func=0;
	len=calculate_nodebq_len(p);
	totalpage=len/5+1;
	
	draw_left_toolbotton(95+65,65,"更改顺序");
	draw_buildqueue(newpage,gameinfop,p,func);
	
	sprintf(str,"第%d页",newpage);
	put_hz24_asc32(80,500,str,1,"HZK\\Hzk24k");
	sprintf(str,"正在建造%d/%d",calculate_nodebq_len(p)>=p->i?p->i:calculate_nodebq_len(p),p->i);
	put_hz24_asc32(60,400,str,1,"HZK\\Hzk24k");
	bar(75,550,175,600,0x7C00);
	bar(75,650,175,700,0x7C00);
	puthz(75,550,"上一页",32,32,1);
	puthz(75,650,"下一页",32,32,1);
	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if (newpage!=oldpage)
		{
			clear_main_all2(2);
			clear_right_all();
			sprintf(str,"第%d页",newpage);
			put_hz24_asc32(80,500,str,1,"HZK\\Hzk24k");
			bar(75,550,175,600,0x7C00);
			bar(75,650,175,700,0x7C00);
			puthz(75,550,"上一页",32,32,1);
			puthz(75,650,"下一页",32,32,1);
			draw_buildqueue(newpage,gameinfop,p,func);
			oldpage=newpage;
		}
		
		if (func==1)
		{
			for (i=0;i<5;i++)
			{
				if(mouse_press(940,120+(i)*130,1000,230+(i)*130)==1)
				{
					if ((newpage-1)*5+i+1>len)
					{
						continue;
					}
					j=newpage;
					clrmous(MouseX,MouseY); 
					bar(940,120+(i)*130,1000,230+(i)*130,10000);
					bar(75,300,175,350,0x7c00);
					puthz(75,300,"撤销操作",32,32,1);
					while (1)
					{
						mouse_renew(&MouseX,&MouseY,&press);
						if (newpage!=oldpage)
						{
							clear_main_all2(2);
							clear_right_all();
							sprintf(str,"第%d页",newpage);
							put_hz24_asc32(80,500,str,1,"HZK\\Hzk24k");
							bar(75,550,175,600,0x7C00);
							bar(75,650,175,700,0x7C00);
							puthz(75,550,"上一页",32,32,1);
							puthz(75,650,"下一页",32,32,1);
							bar(75,300,175,350,0x7c00);
							puthz(75,300,"撤销操作",32,32,1);
							draw_buildqueue(newpage,gameinfop,p,func);
							if (j==newpage)
							{
								bar(940,120+(i)*130,1000,230+(i)*130,10000);
							}
							oldpage=newpage;
						}
						//撤销
						if (mouse_press(75,300,175,350)==1)
						{
							bar(940,120+(i)*130,1000,230+(i)*130,20000);
							break;
						}
						
						if (mouse_press(75,550,175,600)==1)
						{
							if (newpage==1)
							{
								continue;
							}
							else
							{
								clrmous(MouseX,MouseY); 
								newpage--;
							}
						}
						
						else if (mouse_press(75,650,175,700)==1)
						{
							if (newpage==totalpage)
							{
								continue;
							}
							else
							{
								clrmous(MouseX,MouseY); 
								newpage++;
							}
						}
						
						for (k=0;k<5;k++)
						{
							if(mouse_press(940,120+(k)*130,1000,230+(k)*130)==1)
							{
								if (j==newpage && i==k)
								{
									continue;
								}
								if ((newpage-1)*5+k+1>len)
								{
									continue;
								}
								exchange_nodebq(p,(j-1)*5+i+1,(newpage-1)*5+k+1);
								func=0;
								break;
							}
						}
						if (func==0)
						{
							clrmous(MouseX,MouseY); 
							clear_right_all();
							clear_main_all2(1);
							draw_left_toolbotton(95+65 , 65, "更改顺序");
							sprintf(str,"第%d页",newpage);
							put_hz24_asc32(80,500,str,1,"HZK\\Hzk24k");
							bar(75,550,175,600,0x7C00);
							bar(75,650,175,700,0x7C00);
							puthz(75,550,"上一页",32,32,1);
							puthz(75,650,"下一页",32,32,1);
							draw_buildqueue(newpage,gameinfop,p,func);
							break;
						}
					}
				}
			}
			
		}
		
		
		if(main_toolbotton_mouse_press(1)==1)//now==66防止与下面主栏返回键被点中的情况冲突
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            return 1;
            
        }
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            return 2;

        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            return 3;
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            return 4;
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            return 5;
        }
		
		if (left_toolbotton_mouse_press(1) == 1)
		{
			clrmous(MouseX,MouseY); 
			clear_right_all();
			draw_left_toolbotton(95+65 , 65, "更改顺序");
			func=0;
			draw_buildqueue(newpage,gameinfop,p,func);
		}
		
		if (left_toolbotton_mouse_press(2) == 1)
		{
			clrmous(MouseX,MouseY); 
			clear_right_all();
			draw_left_toolbotton_activate(95+65 , 65, "更改顺序");
			func=1;
			draw_buildqueue(newpage,gameinfop,p,func);
		}
		
		
		if (mouse_press(75,550,175,600)==1)
		{
			if (newpage==1)
			{
				continue;
			}
			else
			{
				clrmous(MouseX,MouseY); 
				newpage--;
			}
		}
		
		
		
		else if (mouse_press(75,650,175,700)==1)
		{
			if (newpage==totalpage)
			{
				continue;
			}
			else
			{
				clrmous(MouseX,MouseY);
				newpage++;
			}
		}
	}
}

void draw_buildqueue(int page,struct GameInfo *gameinfop,nodebq *p,int func)
{
	char str[30]={'\0'};
	int i,j;
	int firstnum=(page-1)*5+1;
	int buildqueue=p->i;
	nodebq *temp;
	p=p->next;
	
	
	
	for (i=0,j=0;i<(page-1)*5;i++,j++)
	{
		if (p==NULL)
		{
			return;
		}
		p=p->next;
	}
	
	temp=p;
	
	
	for (i=0;i<5;i++)
	{
		if (p==NULL)
		{
			return;
		}
		j++;
		
		bar(260,120+(i)*130,940,230+(i)*130,0xBDBD);
		
		sprintf(str,"%s",gameinfop->m_info[p->i][p->j].building.name);
		puthz(270,125+(i)*130,str,32,32,1);
		
		sprintf(str,"还需建造%d个月",gameinfop->m_info[p->i][p->j].building.bui_time);
		put_hz24_asc32(670,200+(i)*130,str,1000,"HZK\\Hzk24k");
		
		sprintf(str,"坐标（%d，%d）",p->i+1,p->j+1);
		put_hz24_asc32(470,125+(i)*130,str,1000,"HZK\\Hzk24k");
		
		if (func==1)
		{
			bar(940,120+(i)*130,1000,230+(i)*130,20000);
		}
		
		if (j<=buildqueue)
		{
			puthz(700,125+(i)*130,"正在建造中",32,32,10000);
		}
		p=p->next;
	}
	
}

int proj_fun4(struct GameInfo* gameinfop)
{
	int page=4;
	char *s[2]={"研究科技","已研究"};
	draw_main_toolbotton_activate(708,0xFF19,"科技","研究");
	
	draw_all_leftbuttons(2,65,s);
	
	//drawmous(MouseX,MouseY);
	
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if(main_toolbotton_mouse_press(1)==1)//now==66防止与下面主栏返回键被点中的情况冲突
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(708,0xFF19,"科技","研究");
            clear_main_all();
			clear_right_all();
            return 1;
            
        }
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(708,0xFF19,"科技","研究");
            clear_main_all();
			clear_right_all();
            return 2;

        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(708,0xFF19,"科技","研究");
            clear_main_all();
			clear_right_all();
            return 3;
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(708,0xFF19,"科技","研究");
            clear_main_all();
			clear_right_all();
            return 4;
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(708,0xFF19,"科技","研究");
            clear_main_all();
			clear_right_all();
            return 5;
        }
		
		if (left_toolbotton_mouse_press(1) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , 65, s[0]);//激活新的
            clear_right_all();
            //page=build(gameinfop,p);
            return page;   
		}
		else if (left_toolbotton_mouse_press(2) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all();
            draw_left_toolbotton_activate(95 , 65, s[1]);//激活新的
            clear_right_all();
            //page=build_queue(gameinfop,p);
            return page;   
		}
	}
}


int proj_origin(struct GameInfo* gameinfop,int *pxsel,int *pysel)
{
	clrmous(MouseX,MouseY);
	draw_pro_origin();
	//draw_map(300,105,954,759,7,7,gameinfop);
	draw_mainmap(*gameinfop,*pxsel,*pysel);
	draw_minimap(*gameinfop,*pxsel,*pysel);
	//drawmous(MouseX,MouseY);
	draw_time(gameinfop);
	cleankey();
	while(1)
    {
		mouse_renew(&MouseX,&MouseY,&press);
        
        if(main_toolbotton_mouse_press(1)==1)
        {
            clrmous(MouseX,MouseY);
			return 1;
        }
		
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY);
            return 2;
        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY);
            return 3;
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY);
            return 4;
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY);
            return 5;
        }
		if(renew_map(pxsel,pysel)==1)
			{
				draw_mainmap(*gameinfop,*pxsel,*pysel);
				draw_minimap(*gameinfop,*pxsel,*pysel);
			}
        delay(15);
    }

}


void draw_map(int x1,int y1,int x2,int y2,int width,int height,struct GameInfo *gameinfop)
{
	int dx=x2-x1;
	int dy=y2-y1;
	int i,j;
	
	//if ((dx-11)%10!=0 || (dy-11)%10!=0)
	//{
	//	return;
	//}
	dx=(dx-(width+1)*3)/width;
	dy=(dy-(height+1)*3)/height;
	
	//bar(x1,y1,x2,y2,0xffff);
	
	for (i=0;i<width+1;i++)
	{
		line(x1+i*(dx+2),y1,x1+i*(dx+2),y2-height-1,1);
		line(x1+1+i*(dx+2),y1,x1+1+i*(dx+2),y2-height-1,1);
		line(x1+2+i*(dx+2),y1,x1+2+i*(dx+2),y2-height-1,1);
	}
	for (i=0;i<height+1;i++)
	{
		line(x1,y1+i*(dy+2),x2-width-1,y1+i*(dy+2),1);
		line(x1,y1+1+i*(dy+2),x2-width-1,y1+1+i*(dy+2),1);
		line(x1,y1+2+i*(dy+2),x2-width-1,y1+2+i*(dy+2),1);
	}
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			//if (gameinfop->m_info[i][j].building.id!=0)
			//{
			put_asc16_number_size(300+j*92,105+i*92,2,2,gameinfop->m_info[i][j].building.id,1);
			//}
		}
	}
}

void draw_map2(int x1,int y1,int x2,int y2,int width,int height,struct GameInfo *gameinfop)
{
	int i,j;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id==0)
			{
				bar(300+j*92,105+i*92,390+j*92,195+i*92,0xA000);
			}
		}
	}
}
int mouse_press_map(int i,int j)
{
	//draw_map(300,105,954,759,7,7);
	return mouse_press(300+i*90,105+j*90,390+i*90,195+j*90);
}
void draw_binfo(void)
{
	bar(0,0,100,768,0xFE00);
	
	bar(20,45,80,79,1);
	put_hz24(26,50,"建造",0xffff,"HZK\\Hzk24k",1);
}

int build(struct GameInfo *gameinfop,nodebq *p,int* pxsel,int* pysel)
{
	int page2=-1;
	clrmous(MouseX,MouseY); 
	
	while(page2<0)
	{
		switch(page2)
		{
			case -1:
				page2=buildlist(1,gameinfop,p,pxsel,pysel);
				break;
			case -2:
				page2=buildlist(2,gameinfop,p,pxsel,pysel);
				break;
			case -3:
				page2=buildlist(3,gameinfop,p,pxsel,pysel);
				break;
			case -4:
				page2=buildlist(4,gameinfop,p,pxsel,pysel);
				break;
			case -5:
				page2=buildlist(5,gameinfop,p,pxsel,pysel);
				break;
		}
	}
	clrmous(MouseX,MouseY);
	delay(10);
	return page2;
}

int buildlist(int x,struct GameInfo *gameinfop,nodebq *p1,int* pxsel,int* pysel)
{
	nodeb *p[3][5];
	nodeb *tempp;
	int pressflag1=0;
	int pressflag2=0;
	int page;
	int i,j,k,d;
	char str[20];
	struct Building building[5];
	int nodeflag[5]={0};
	cleankey();
	for (i=0;i<3;i++)
	{
		for (j=0;j<5;j++)
		{
			p[i][j]=create_nodeb();
		}
	}
	
	
	for (i=0;i<5;i++)
	{
		nodeflag[i]=dlist_building(5*(x-1)+i+1,i+1,p[0][i],p[1][i],p[2][i],gameinfop,&building[i]);
		delay(20);
	}
	
	sprintf(str,"第%d页",x);
	put_hz24_asc32(80,300,str,1,"HZK\\Hzk24k");
	bar(100,400,200,450,0x7C00);
	bar(100,600,200,650,0x7C00);
	puthz(100,400,"上一页",32,32,1);
	puthz(100,600,"下一页",32,32,1);
	
	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if(main_toolbotton_mouse_press(1)==1)//now==66防止与下面主栏返回键被点中的情况冲突
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
			page=1;
			break;    
        }
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            page=2;
			break; 
        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            page=3;
			break; 
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            page=4;
			break; 
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(550,0xBBBB,"建造","显示");
            clear_main_all();
			clear_right_all();
            page=5;
			break; 
        }
		
		if (mouse_press(100,400,200,450)==1)
		{
			if (x==1)
			{
				continue;
			}
			else
			{
				clear_main_all2(1);
				clear_right_all();
				return -(x-1);
			}
		}
		
		else if (mouse_press(100,600,200,650)==1)
		{
			if (x==5)
			{
				continue;
			}
			else
			{
				clear_main_all2(1);
				clear_right_all();
				return -(x+1);
			}
		}
		
		
		//点击建造键
		for (k=0;k<5;k++)
		{
			if (mouse_press(920,120+k*130,1000,230+k*130)==1)
			{
				if (nodeflag[k]==1)
				{
					pressflag1++;
					break;
				}
				tempp=p[0][k]->next;
				pressflag1=0;
				while (tempp!=NULL)
				{
					if (tempp->color==0xF800)
					{
						pressflag1++;
						break;
					}
					tempp=tempp->next;
				}
				if (pressflag1)
				{
					break;
				}
				
				clrmous(MouseX,MouseY);
				bar(0,200,230,700,65535);
				//clear_main_all();
				clear_right_all();
				draw_buildmap(*gameinfop,*pxsel,*pysel);
				draw_minimap(*gameinfop,*pxsel,*pysel);
				//(struct GameInfo gf,int xsel,int ysel)(300,105,954,759,7,7,gameinfop);
				//draw_map(300,105,954,759,7,7,gameinfop);
				for (i=0;i<7;i++)
				{
					for (j=0;j<7;j++)
					{
						if (gameinfop->m_info[i][j].building.id==0)
						{
							//涂色
						}
					}
				}
				pressflag2=0;
				
				while (1)
				{
					mouse_renew(&MouseX,&MouseY,&press);
					if(renew_map(pxsel,pysel)==1)
					{
						draw_buildmap(*gameinfop,*pxsel,*pysel);
						draw_minimap(*gameinfop,*pxsel,*pysel);
					}
					for (i=0;i<7;i++)
					{
						for(j=0;j<7;j++)
						{
							if(mouse_press_map(i,j)==1&&gameinfop->m_info[*pxsel+i][*pysel+j].building.id==0)
							{
								lastinsert_nodebq(p1,*pxsel+i,*pysel+j);
								gameinfop->m_info[*pxsel+i][*pysel+j].building.res_cost.nanomaterial=building[k].res_cost.nanomaterial;
								gameinfop->m_info[*pxsel+i][*pysel+j].building.res_cost.rarematerial=building[k].res_cost.rarematerial;
								
								gameinfop->m_info[*pxsel+i][*pysel+j].building.id=(char)(5*(x-1)+k+1);
								d=0;
								while (building[k].name[d]!='\0')
								{
									gameinfop->m_info[*pxsel+i][*pysel+j].building.name[d]=building[k].name[d];
									d++;
								}
								gameinfop->m_info[*pxsel+i][*pysel+j].building.name[d]='\0';
								
								d=0;
								while (building[k].pic_path[d]!='\0')
								{
									gameinfop->m_info[*pxsel+i][*pysel+j].building.pic_path[d]=building[k].pic_path[d];
									d++;
								}
								gameinfop->m_info[*pxsel+i][*pysel+j].building.pic_path[d]='\0';
								gameinfop->m_info[*pxsel+i][*pysel+j].building.bui_time=building[k].bui_time;
								
								gameinfop->m_info[*pxsel+i][*pysel+j].building.res_add.nanomaterial=building[k].res_add.nanomaterial;
								gameinfop->m_info[*pxsel+i][*pysel+j].building.res_add.rarematerial=building[k].res_add.rarematerial;
								gameinfop->m_info[*pxsel+i][*pysel+j].building.res_add.oxygen=building[k].res_add.oxygen;
								gameinfop->m_info[*pxsel+i][*pysel+j].building.res_add.water=building[k].res_add.water;
								gameinfop->m_info[*pxsel+i][*pysel+j].building.res_add.food=building[k].res_add.food;
								gameinfop->m_info[*pxsel+i][*pysel+j].building.res_add.energy=building[k].res_add.energy;
								gameinfop->m_info[*pxsel+i][*pysel+j].building.res_add.fuel=building[k].res_add.fuel;
								gameinfop->m_info[*pxsel+i][*pysel+j].building.res_add.mineral=building[k].res_add.mineral;
								
								
								gameinfop->r_info.nanomaterial-=building[k].res_cost.nanomaterial;
								gameinfop->r_info.rarematerial-=building[k].res_cost.rarematerial;
								pressflag2++;
							}
						}
					}
					if (pressflag2)
					{
						page=1;
						clrmous(MouseX,MouseY); 
						draw_main_toolbotton(550,0xBBBB,"建造","显示");
						clear_main_all();
						clear_right_all();
						break;
					}
				}
				break;
			}
		}
		if (pressflag2)
		{
				break;
		}
	}	
	for (i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			free_nodeb(p[i][j]);
		}
	}
	return page;
}

int dlist_building(char id,int location,nodeb *p1,nodeb *p2,nodeb *p3,struct GameInfo *gameinfop,struct Building *building)
{
	char str[20]={'\0'};
	int i=0,j=0;
	int flag;
	nodeb *p;
	flag=get_building_info(id,building);
	if(flag)
	{
		return 1;
	}
	
	bar(240,120+(location-1)*130,920,230+(location-1)*130,0xBDBD);
	bar(920,120+(location-1)*130,1000,230+(location-1)*130,0xFE00);
	put_hz24(920,135+(location-1)*130,"建造",1,"HZK\\Hzk24k",0);

	put_hz24(820,170+(location-1)*130,"时长：",1,"HZK\\Hzk24k",0);
	sprintf(str,"%d个月",building->bui_time);
	put_hz24_asc32(820,200+(location-1)*130,str,1000,"HZK\\Hzk24k");
	
	j=0;
	while(str[j]!='\0')
	{
		str[j++]='\0';
	}
	
	p=p1;
	headinsert1_cost_nodeb(p,*building,gameinfop);
	p=p->next;
	while(p!=NULL)
	{
		sprintf(str,"%s:%d",p->name,p->number);
		put_hz24_asc32(460+i*180,125+(location-1)*130,str,p->color,"HZK\\Hzk24k");
		j=0;
		while(str[j]!='\0')
		{
			str[j++]='\0';
		}
		i++;
		p=p->next;
	}
	
	i=0;
	put_hz24(250,160+(location-1)*130,"月收益",1,"HZK\\Hzk24k",0);
	p=p2;
	headinsert1_add_nodeb(p,*building,gameinfop);
	p=p->next;
	while(p!=NULL)
	{
		sprintf(str,"%s:%d",p->name,p->number);
		put_hz16_asc16_size(340+i*90,160+(location-1)*130,1,1,str,p->color,"HZK\\HZ16");
		j=0;
		while(str[j]!='\0')
		{
			str[j++]='\0';
		}
		i++;
		p=p->next;
	}
	
	i=0;
	put_hz24(250,185+(location-1)*130,"月维护",1,"HZK\\Hzk24k",0);
	p=p3;
	headinsert1_maintfee_nodeb(p,*building,gameinfop);
	p=p->next;
	while(p!=NULL)
	{
		sprintf(str,"%s:%d",p->name,p->number);
		put_hz16_asc16_size(340+i*90,185+(location-1)*130,1,1,str,p->color,"HZK\\HZ16");
		j=0;
		while(str[j]!='\0')
		{
			str[j++]='\0';
		}
		i++;
		p=p->next;
	}
	
	
	//sprintf(str,"%d",building.res_cost.nanomaterial);
	puthz(250,125+(location-1)*130,building->name,32,32,1);
	return 0;
	//put_asc16_size(430,135+(location-1)*130,2,2,str,1);
}

int get_building_info(char id,struct Building* building)
{
	int total;
	int i;
	char c;
	char str[20]={'\0'};
	FILE *file=fopen("./data/building.txt","r");
	if (file==NULL)
	{
		printf("open error");
		return 1;
	}
	
	i=0;
	while ((c=fgetc(file))!='\n')
	{
		str[i++]=c;
	}
	str[i]='\0';
	total= atoi(str);
	
	if(total<id)
	{
		fclose(file);
		return 1;
	}
	
	for (i=0;i<id-1;i++)
	{
		while ((c=(fgetc(file)))!='\n');
	}
	
	//id
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->id= (char)(atoi(str));
	
	//name
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		building->name[i++]=c;
	}
	building->name[i]='\0';
	
	//path
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		building->pic_path[i++]=c;
	}
	building->pic_path[i]='\0';
	
	//cost nanomaterial
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->res_cost.nanomaterial= atoi(str);
	
	//cost rarematerial
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->res_cost.rarematerial= atoi(str);
	
	//add nanomaterial
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->res_add.nanomaterial= atoi(str);
	
	//add rarematerial
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->res_add.rarematerial= atoi(str);
	
	//add oxygen
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->res_add.oxygen= atoi(str);
	
	//add water
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->res_add.water= atoi(str);
	
	//add food
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->res_add.food= atoi(str);
	
	//add energy
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->res_add.energy= atoi(str);
	
	//add fuel
	i=0;
	while ((c=fgetc(file))!=' '&&c!='\n'&&c!=EOF)
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->res_add.fuel= atoi(str);
	
	//add mineral
	i=0;
	while ((c=fgetc(file))!=' '&&c!='\n'&&c!=EOF)
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->res_add.mineral= atoi(str);
	
	//bui_time
	i=0;
	while ((c=fgetc(file))!=' '&&c!='\n'&&c!=EOF)
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->bui_time= atoi(str);
	
	fclose(file);
	return 0;
}

//以下为链表操作函数
nodeb* create_nodeb(void)
{
	nodeb *p=(nodeb*)malloc(sizeof(nodeb));
	p->next=NULL;
	return p;
}

//获得建筑建造花费的资源的名字，数值
void headinsert1_cost_nodeb(nodeb *p,struct Building building,struct GameInfo *gameinfop)
{
	nodeb *temp;
	
	if(building.res_cost.nanomaterial>0)
	{
		temp=(nodeb*)malloc(sizeof(nodeb));
		temp->next=p->next;
		p->next=temp;
		strcpy(temp->name,"纳米材料");
		temp->number=building.res_cost.nanomaterial;
		if (gameinfop->r_info.nanomaterial<building.res_cost.nanomaterial)
		{
			temp->color=0xF800;
		}
		else
		{
			temp->color=1;
		}
	}
	if(building.res_cost.rarematerial>0)
	{
		temp=(nodeb*)malloc(sizeof(nodeb));
		temp->next=p->next;
		p->next=temp;
		strcpy(temp->name,"稀有材料");
		temp->number=building.res_cost.rarematerial;
		if (gameinfop->r_info.rarematerial<building.res_cost.rarematerial)
		{
			temp->color=0xF800;
		}
		else
		{
			temp->color=1;
		}
	}
}

void headinsert1_add_nodeb(nodeb *p,struct Building building,struct GameInfo *gameinfop)
{
	nodeb *temp;
	char *s[8]={"纳米材料","稀有材料","氧气","淡水","食物","矿物","燃料","能源"};
	int data[8];
	int i;
	data[0]=building.res_add.nanomaterial;
	data[1]=building.res_add.rarematerial;
	data[2]=building.res_add.oxygen;
	data[3]=building.res_add.water;
	data[4]=building.res_add.food;
	data[5]=building.res_add.mineral;
	data[6]=building.res_add.fuel;
	data[7]=building.res_add.energy;
	
	for (i=0;i<8;i++)
	{
		if (data[i]>0)
		{
			temp=(nodeb*)malloc(sizeof(nodeb));
			temp->next=p->next;
			p->next=temp;
			strcpy(temp->name,s[i]);
			temp->number=data[i];
			temp->color=0x03C0;
		}
	}
}

void headinsert1_maintfee_nodeb(nodeb *p,struct Building building,struct GameInfo *gameinfop)
{
	nodeb *temp;
	char *s[8]={"纳米材料","稀有材料","氧气","淡水","食物","矿物","燃料","能源"};
	int data[8];
	int i;
	data[0]=building.res_add.nanomaterial;
	data[1]=building.res_add.rarematerial;
	data[2]=building.res_add.oxygen;
	data[3]=building.res_add.water;
	data[4]=building.res_add.food;
	data[5]=building.res_add.mineral;
	data[6]=building.res_add.fuel;
	data[7]=building.res_add.energy;
	
	for (i=0;i<8;i++)
	{
		if (data[i]<0)
		{
			temp=(nodeb*)malloc(sizeof(nodeb));
			temp->next=p->next;
			p->next=temp;
			strcpy(temp->name,s[i]);
			temp->number=data[i];
			temp->color=1;
		}
	}
	
}

void free_nodeb(nodeb *p)
{
	nodeb *temp;
	while(p!=NULL)
	{
		temp=p->next;
		free(p);
		p=temp;
	}
}

nodebq* create_nodebq(void)
{
	nodebq *p=(nodebq*)malloc(sizeof(nodebq));
	p->next=NULL;
	p->i=2;
	return p;
}

void lastinsert_nodebq(nodebq *p,int i,int j)
{
	nodebq *temp=(nodebq*)malloc(sizeof(nodebq));
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=temp;
	temp->i=i;
	temp->j=j;
	temp->next=NULL;
}

int calculate_nodebq_len(nodebq *p)
{
	nodebq *temp;
	int i=0;
	temp=p->next;
	while(temp!=NULL)
	{
		temp=temp->next;
		i++;
	}
	return i;
}

void headremove_nodebq(nodebq *p)
{
	nodebq *temp;
	temp=p->next;
	temp=temp->next;
	free(p->next);
	p->next=temp;
}

void exchange_nodebq(nodebq *p,int x1,int x2)
{
	nodebq *p1=p,*p2=p;
	nodebq *temp;
	int i;
	for (i=0;i<x1;i++)
	{
		p1=p1->next;
		if (p1==NULL)
		{
			return;
		}
	}
	for (i=0;i<x2;i++)
	{
		p2=p2->next;
		if (p2==NULL)
		{
			return;
		}
	}
	temp=(nodebq *)malloc(sizeof(nodebq));
	temp->i=p1->i;
	temp->j=p1->j;
	p1->i=p2->i;
	p1->j=p2->j;
	p2->i=temp->i;
	p2->j=temp->j;
	free(temp);
}

void free_nodebq(nodebq *p)
{
	nodebq *temp;
	while(p!=NULL)
	{
		temp=p->next;
		free(p);
		p=temp;
	}
}

//void judge_press_mainbutton(int flag,int *page)
//{
//	char *s1[5]={"地图","全局","建造","科技","时间"};
//	char *s2[5]={"显示","资源","显示","研究","流动"};
//	
//	unsigned int color[5];
//	if(main_toolbotton_mouse_press(1)==1)//now==66防止与下面主栏返回键被点中的情况冲突
//    {
//        clrmous(MouseX,MouseY); 
//        draw_main_toolbotton(550,0xBBBB,s1[flag-1],s2[flag-1]);
//        clear_main_all();
//		clear_right_all();
//		*page=1;
//		break;    
//    }
//    else if(main_toolbotton_mouse_press(2)==1)
//    {
//        clrmous(MouseX,MouseY); 
//        draw_main_toolbotton(550,0xBBBB,s1[flag-1],s2[flag-1]);
//        clear_main_all();	
//		clear_right_all();
//        *page=2;	
//		break; 
//    }
//    else if(main_toolbotton_mouse_press(3)==1)
//    {
//        clrmous(MouseX,MouseY); 
//        draw_main_toolbotton(550,0xBBBB,s1[flag-1],s2[flag-1]);
//        clear_main_all();
//		clear_right_all();
//        page=3;
//		break; 
//    }
//    else if(main_toolbotton_mouse_press(4)==1)
//    {
//        clrmous(MouseX,MouseY); 
//        draw_main_toolbotton(550,0xBBBB,s1[flag-1],s2[flag-1]);
//        clear_main_all();	
//		clear_right_all();
//        page=4;
//		break; 
//    }
//    else if(main_toolbotton_mouse_press(5)==1)
//    {
//        clrmous(MouseX,MouseY); 
//        draw_main_toolbotton(550,0xBBBB,s1[flag-1],s2[flag-1]);
//        clear_main_all();	
//		clear_right_all();
//        page=5;
//		break; 
//    }
//}
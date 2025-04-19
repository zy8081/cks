#include <common.h>
#include <game.h>
#include <fun3_2.h>
#include <fun3.h>
#include <WRKMNG.h>
#include <fun5.h>
#include <fun4.h>
#include <fun4_2.h>
#include <fun1.h>
#include <ORDFUNS.h>
#include <MAP.h>
#include <debug.h>


/*private函数
进入“建造队列”界面
实现机理：
形参p即为储存建造队列的链表，
它和地图上的数据是独立开的
*/
int build_queue(struct GameInfo *gameinfop,nodebq *p)
{
	int i,j,k;
	int a1,b1;
	int a2,b2;
	int totalpage;
	int len;
	int page=3;
	int oldpage=1;
	int newpage=1;
	char str[50]={'\0'};
	int func=0;
	len=calculate_nodebq_len(p);
	totalpage=len/5+1;
	
	draw_left_toolbotton(95+65,65,"更改顺序");
	draw_left_toolbotton(95+65*2,65,"终止建造");
	
	draw_buildqueue(newpage,gameinfop,p,func);
	draw_buildqueue_basic(newpage,p);
	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);

		if (newpage!=oldpage)
		{
			clear_main_all2(3);
			clear_right_all();
			draw_buildqueue_basic(newpage,p);
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
					bar(945,125+(i)*130,995,225+(i)*130,4000);
					btn_bar_Draw(60,350,190,400);
					puthz2(60,350,32,32,0xA000,"撤销操作");
					while (1)
					{
						mouse_renew(&MouseX,&MouseY,&press);
						if (newpage!=oldpage)
						{
							clear_main_all2(3);
							clear_right_all();
							draw_buildqueue_basic(newpage,p);
							btn_bar_Draw(60,350,190,400);
							puthz2(60,350,32,32,0xA000,"撤销操作");
							draw_buildqueue(newpage,gameinfop,p,func);
							if (j==newpage)
							{
								bar(945,125+(i)*130,995,225+(i)*130,4000);
							}
							oldpage=newpage;
						}
						//撤销
						if (mouse_press(75,350,175,400)==1)
						{
							clrmous(MouseX,MouseY);
							bar(945,125+(i)*130,995,225+(i)*130,1000);
							bar(57,347,193,403,0xFFFF);
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
								else if ((newpage-1)*5+k+1>len)
								{
									continue;
								}
								else
								{
									getdata_nodebq(p,(newpage-1)*5+k+1,&a1,&b1);
									getdata_nodebq(p,(j-1)*5+i+1,&a2,&b2);
									
									clrmous(MouseX,MouseY);
									draw_buildqueue_toast();
									puthz2(300,200,32,32,0xA000,"你确定要交换建造顺序吗：");
									sprintf(str,"交换（%d，%d）的“%s”",a1+1,b1+1,gameinfop->m_info[a1][b1].building.name);
									put_hz24_asc32(305,260,str,3000,"HZK\\Hzk24k");
									sprintf(str,"和（%d，%d）的“%s”？",a2+1,b2+1,gameinfop->m_info[a2][b2].building.name);
									put_hz24_asc32(305,300,str,3000,"HZK\\Hzk24k");
									
									while(1)
									{
										mouse_renew(&MouseX,&MouseY,&press);
										if (mouse_press(300,450,400,500)==1)
										{
											clrmous(MouseX,MouseY);
											LoadBMP(290,190,810,510,0);
											break;
										}
										if (mouse_press(700,450,800,500)==1)
										{
											clrmous(MouseX,MouseY); 
											LoadBMP(290,190,810,510,0);
											exchange_nodebq(p,(j-1)*5+i+1,(newpage-1)*5+k+1);
											func=0;
											break;
										}
									}
								}
							}
						}
						if (func==0)
						{
							clrmous(MouseX,MouseY); 
							clear_right_all();
							clear_main_all2(1);
							
							draw_left_toolbotton(95+65 , 65, "更改顺序");
							draw_left_toolbotton(95+65*2 , 65, "终止建造");
							draw_buildqueue_basic(newpage,p);
							draw_buildqueue(newpage,gameinfop,p,func);
							
							break;
						}
						
					}
					break;
				}
			}
			
		}
		if (func==2)
		{
			for (k=0;k<5;k++)
			{
				if(mouse_press(940,120+(k)*130,1000,230+(k)*130)==1)
				{
					if ((newpage-1)*5+k+1>len)
					{
						continue;
					}
					getdata_nodebq(p,(newpage-1)*5+k+1,&i,&j);
					clrmous(MouseX,MouseY);
					draw_buildqueue_toast();
					puthz2(300,200,32,32,0xA000,"你确定要取消建造：");
					sprintf(str,"“%s”吗？",gameinfop->m_info[i][j].building.name);
					puthz2(300,250,32,32,1,str);
					sprintf(str,"其坐标（%d，%d）",i+1,j+1);
					put_hz16_asc16_size(310,300,2,2,str,3000,"HZK\\HZ16");
					puthz2(300,350,32,32,1000,"你将回收建造花费的一半资源");
					while(1)
					{
						mouse_renew(&MouseX,&MouseY,&press);
						if (mouse_press(300,450,400,500)==1)
						{
							clrmous(MouseX,MouseY);
							LoadBMP(290,190,810,510,0);
							break;
						}
						if (mouse_press(700,450,800,500)==1)
						{
							clrmous(MouseX,MouseY); 
							LoadBMP(290,190,810,510,0);
							clear_map_building_data(gameinfop,i,j);
							delete_nodebq(p,(newpage-1)*5+k+1);
							func=0;
							clear_right_all();
							clear_main_all2(1);
							draw_left_toolbotton(95+65 , 65, "更改顺序");
							draw_left_toolbotton(95+65*2 , 65, "终止建造");
							draw_buildqueue_basic(newpage,p);
							draw_buildqueue(newpage,gameinfop,p,func);
							
							break;
						}
					}
					
					
				}
			}
		}
		
		if (judge_press_mainbutton(3,&page))
		{
			return page;
		}
		
		if (left_toolbotton_mouse_press(1) == 1)
		{
			clrmous(MouseX,MouseY); 
			clear_right_all();
			draw_left_toolbotton(95+65 , 65, "更改顺序");
			draw_left_toolbotton(95+65*2 , 65, "终止建造");
			func=0;
			draw_buildqueue(newpage,gameinfop,p,func);
		}
		
		if (left_toolbotton_mouse_press(2) == 1)
		{
			clrmous(MouseX,MouseY); 
			clear_right_all();
			draw_left_toolbotton_activate(95+65 , 65, "更改顺序");
			draw_left_toolbotton(95+65*2 , 65, "终止建造");
			func=1;
			draw_buildqueue(newpage,gameinfop,p,func);
		}
		
		if (left_toolbotton_mouse_press(3) == 1)
		{
			clrmous(MouseX,MouseY); 
			clear_right_all();
			draw_left_toolbotton(95+65 , 65, "更改顺序");
			draw_left_toolbotton_activate(95+65*2 , 65, "终止建造");
			func=2;
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

void draw_buildqueue_toast(void)
{
	SaveBMP(290,190,810,510,0);
	btn_bar_Draw(300,200,800,500);

	btn_bar_Draw(300,450,400,500);
	puthz3(300,450,32,32,1,"取消");

	btn_bar_Draw(700,450,800,500);
	puthz3(700,450,32,32,1,"确定");
}

void draw_buildqueue_basic(int newpage,nodebq *p)
{
	char str[30];
	sprintf(str,"第%d页",newpage);
	put_hz16_asc16_size(55,470,3,3,str,1,"HZK\\HZ16");
	sprintf(str,"正在建造%d/%d",calculate_nodebq_len(p)>=p->i?p->i:calculate_nodebq_len(p),p->i);
	put_hz16_asc16_size(20,420,2,2,str,1000,"HZK\\HZ16");

	btn_bar_Draw(75,550,175,600);
	btn_bar_Draw(75,650,175,700);
	puthz3(75,550,32,32,1,"上一页");
	puthz3(75,650,32,32,1,"下一页");
}

/*private函数
根据页面来draw建造队列对应的建筑
*/
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
		
		btn_bar_Draw(260,120+(i)*130,940,230+(i)*130);
		
		sprintf(str,"%s",gameinfop->m_info[p->i][p->j].building.name);
		puthz2(270,125+(i)*130,32,32,1,str);
		
		sprintf(str,"还需建造%d个月",gameinfop->m_info[p->i][p->j].building.bui_time);
		put_hz16_asc16_size(670,190+(i)*130,2,2,str,1000,"HZK\\HZ16");
		
		sprintf(str,"坐标（%d，%d）",p->i+1,p->j+1);
		put_hz16_asc16_size(530,125+(i)*130,2,2,str,3000,"HZK\\HZ16");
		
		if (func==1)
		{
			btn_bar_Draw(940,120+(i)*130,1000,230+(i)*130);
			bar(945,125+(i)*130,995,225+(i)*130,1000);
		}
		
		else if (func==2)
		{
			btn_bar_Draw(940,120+(i)*130,1000,230+(i)*130);
			bar(945,125+(i)*130,995,225+(i)*130,0xA000);
		}
		
		if (j<=buildqueue)
		{
			puthz2(760,125+(i)*130,32,32,2000,"正在建造中");
		}
		p=p->next;
	}
	
}

/*private函数
nodebq（建造队列链表）链表创建函数
赋予i初值1
nodebq链表只记录 代建造建筑 的地图位置i，j
*/
nodebq* create_nodebq(void)
{
	nodebq *p=(nodebq*)malloc(sizeof(nodebq));
	p->next=NULL;
	p->i=1;
	return p;
}

/*private函数
nodebq（建造队列链表）尾插法
*/
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

/*private函数
nodebq（建造队列链表）计算存储多少个数据节点
*/
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

/*private函数
nodebq（建造队列链表）在头部删除节点
*/
void headremove_nodebq(nodebq *p)
{
	nodebq *temp;
	temp=p->next;
	temp=temp->next;
	free(p->next);
	p->next=temp;
}

/*private函数
nodebq（建造队列链表）交换两个位置的数据
以实现建造队列建造顺序的切换
*/
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

/*private函数
nodebq（建造队列链表）删除对应位值的链表节点
以实现建造队列的删除建筑
*/
void delete_nodebq(nodebq *p,int x)
{
	int i;
	nodebq *temp;
	for (i=0;i<x-1;i++)
	{
		p=p->next;
	}
	temp=p->next;
	temp=temp->next;
	free(p->next);
	p->next=temp;
}

/*private函数
nodebq（建造队列链表）获得链表x位置上存储的建筑位置信息
*/
void getdata_nodebq(nodebq *p,int x,int *i,int *j)
{
	int k;
	for (k=0;k<x;k++)
	{
		p=p->next;
	}
	*i=p->i;
	*j=p->j;
}

/*private函数
nodebq（建造队列链表）free函数
*/
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

/*private函数
删除建造队列（nodebq）的节点时，并未改变地图上已加载的数据，
此函数用以初始化地图相应位置的数据
*/
void clear_map_building_data(struct GameInfo *gameinfop,int i,int j)
{
	char str[30]={'\0'};
	int k=0;
	gameinfop->m_info[i][j].building.id=0;
	while(gameinfop->m_info[i][j].building.name[k]!='\0')
	{
		gameinfop->m_info[i][j].building.name[k++]='\0';
	}
	k=0;
	while(gameinfop->m_info[i][j].building.pic_path[k]!='\0')
	{
		gameinfop->m_info[i][j].building.pic_path[k]='\0';
	}
	gameinfop->m_info[i][j].building.res_cost.nanomaterial=0;
	gameinfop->m_info[i][j].building.res_cost.rarematerial=0;
	
	gameinfop->m_info[i][j].building.res_add.nanomaterial=0;
	gameinfop->m_info[i][j].building.res_add.rarematerial=0;
	gameinfop->m_info[i][j].building.res_add.oxygen=0;
	gameinfop->m_info[i][j].building.res_add.water=0;
	gameinfop->m_info[i][j].building.res_add.food=0;
	gameinfop->m_info[i][j].building.res_add.energy=0;
	gameinfop->m_info[i][j].building.res_add.fuel=0;
	gameinfop->m_info[i][j].building.res_add.mineral=0;
}
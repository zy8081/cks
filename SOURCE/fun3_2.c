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


/*private����
���롰������С�����
ʵ�ֻ���
�β�p��Ϊ���潨����е�����
���͵�ͼ�ϵ������Ƕ�������
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
	
	draw_left_toolbotton(95+65,65,"����˳��");
	draw_left_toolbotton(95+65*2,65,"��ֹ����");
	
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
					puthz2(60,350,32,32,0xA000,"��������");
					while (1)
					{
						mouse_renew(&MouseX,&MouseY,&press);
						if (newpage!=oldpage)
						{
							clear_main_all2(3);
							clear_right_all();
							draw_buildqueue_basic(newpage,p);
							btn_bar_Draw(60,350,190,400);
							puthz2(60,350,32,32,0xA000,"��������");
							draw_buildqueue(newpage,gameinfop,p,func);
							if (j==newpage)
							{
								bar(945,125+(i)*130,995,225+(i)*130,4000);
							}
							oldpage=newpage;
						}
						//����
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
									puthz2(300,200,32,32,0xA000,"��ȷ��Ҫ��������˳����");
									sprintf(str,"������%d��%d���ġ�%s��",a1+1,b1+1,gameinfop->m_info[a1][b1].building.name);
									put_hz24_asc32(305,260,str,3000,"HZK\\Hzk24k");
									sprintf(str,"�ͣ�%d��%d���ġ�%s����",a2+1,b2+1,gameinfop->m_info[a2][b2].building.name);
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
							
							draw_left_toolbotton(95+65 , 65, "����˳��");
							draw_left_toolbotton(95+65*2 , 65, "��ֹ����");
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
					puthz2(300,200,32,32,0xA000,"��ȷ��Ҫȡ�����죺");
					sprintf(str,"��%s����",gameinfop->m_info[i][j].building.name);
					puthz2(300,250,32,32,1,str);
					sprintf(str,"�����꣨%d��%d��",i+1,j+1);
					put_hz16_asc16_size(310,300,2,2,str,3000,"HZK\\HZ16");
					puthz2(300,350,32,32,1000,"�㽫���ս��컨�ѵ�һ����Դ");
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
							draw_left_toolbotton(95+65 , 65, "����˳��");
							draw_left_toolbotton(95+65*2 , 65, "��ֹ����");
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
			draw_left_toolbotton(95+65 , 65, "����˳��");
			draw_left_toolbotton(95+65*2 , 65, "��ֹ����");
			func=0;
			draw_buildqueue(newpage,gameinfop,p,func);
		}
		
		if (left_toolbotton_mouse_press(2) == 1)
		{
			clrmous(MouseX,MouseY); 
			clear_right_all();
			draw_left_toolbotton_activate(95+65 , 65, "����˳��");
			draw_left_toolbotton(95+65*2 , 65, "��ֹ����");
			func=1;
			draw_buildqueue(newpage,gameinfop,p,func);
		}
		
		if (left_toolbotton_mouse_press(3) == 1)
		{
			clrmous(MouseX,MouseY); 
			clear_right_all();
			draw_left_toolbotton(95+65 , 65, "����˳��");
			draw_left_toolbotton_activate(95+65*2 , 65, "��ֹ����");
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
	puthz3(300,450,32,32,1,"ȡ��");

	btn_bar_Draw(700,450,800,500);
	puthz3(700,450,32,32,1,"ȷ��");
}

void draw_buildqueue_basic(int newpage,nodebq *p)
{
	char str[30];
	sprintf(str,"��%dҳ",newpage);
	put_hz16_asc16_size(55,470,3,3,str,1,"HZK\\HZ16");
	sprintf(str,"���ڽ���%d/%d",calculate_nodebq_len(p)>=p->i?p->i:calculate_nodebq_len(p),p->i);
	put_hz16_asc16_size(20,420,2,2,str,1000,"HZK\\HZ16");

	btn_bar_Draw(75,550,175,600);
	btn_bar_Draw(75,650,175,700);
	puthz3(75,550,32,32,1,"��һҳ");
	puthz3(75,650,32,32,1,"��һҳ");
}

/*private����
����ҳ����draw������ж�Ӧ�Ľ���
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
		
		sprintf(str,"���轨��%d����",gameinfop->m_info[p->i][p->j].building.bui_time);
		put_hz16_asc16_size(670,190+(i)*130,2,2,str,1000,"HZK\\HZ16");
		
		sprintf(str,"���꣨%d��%d��",p->i+1,p->j+1);
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
			puthz2(760,125+(i)*130,32,32,2000,"���ڽ�����");
		}
		p=p->next;
	}
	
}

/*private����
nodebq�����������������������
����i��ֵ1
nodebq����ֻ��¼ �����콨�� �ĵ�ͼλ��i��j
*/
nodebq* create_nodebq(void)
{
	nodebq *p=(nodebq*)malloc(sizeof(nodebq));
	p->next=NULL;
	p->i=1;
	return p;
}

/*private����
nodebq�������������β�巨
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

/*private����
nodebq�����������������洢���ٸ����ݽڵ�
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

/*private����
nodebq���������������ͷ��ɾ���ڵ�
*/
void headremove_nodebq(nodebq *p)
{
	nodebq *temp;
	temp=p->next;
	temp=temp->next;
	free(p->next);
	p->next=temp;
}

/*private����
nodebq���������������������λ�õ�����
��ʵ�ֽ�����н���˳����л�
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

/*private����
nodebq�������������ɾ����Ӧλֵ������ڵ�
��ʵ�ֽ�����е�ɾ������
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

/*private����
nodebq��������������������xλ���ϴ洢�Ľ���λ����Ϣ
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

/*private����
nodebq�������������free����
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

/*private����
ɾ��������У�nodebq���Ľڵ�ʱ����δ�ı��ͼ���Ѽ��ص����ݣ�
�˺������Գ�ʼ����ͼ��Ӧλ�õ�����
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
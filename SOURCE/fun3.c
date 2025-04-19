#include <common.h>
#include <game.h>
#include <fun3_2.h>
#include <fun3_3.h>
#include <fun3.h>
#include <WRKMNG.h>
#include <fun5.h>
#include <fun4.h>
#include <fun4_2.h>
#include <fun1.h>
#include <ORDFUNS.h>
#include <MAP.h>
#include <debug.h>

/*
���"������ʾ"������Ľ���
*/
int proj_fun3(struct GameInfo *gameinfop,nodebq *p,int* pxsel,int* pysel)
{
	int page=3;
	char *s[5]={"�½�����","�������","�������","ͣ�ý���","˵����"};
	draw_main_toolbotton_activate(550,0xBBBB,"����","��ʾ");
	
	draw_all_leftbuttons(5,65,s);
	
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if (judge_press_mainbutton(3,&page))
		{
			return page;
		}
		
        if (left_toolbotton_mouse_press(1) == 1) //���������е����
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , 65, s[0]);//�����µ�
            clear_right_all();
            page=build(gameinfop,p,pxsel,pysel);
            return page;
		}
		else if (left_toolbotton_mouse_press(2) == 1) //���������е����
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , 65, s[1]);//�����µ�
            clear_right_all();
            page=build_queue(gameinfop,p);
            return page;
		}
		else if (left_toolbotton_mouse_press(3) == 1) //���������е����
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , 65, s[2]);//�����µ�
            clear_right_all();
            page=demolish_building(gameinfop,pxsel,pysel);
            return page;
		}

		else if (left_toolbotton_mouse_press(4) == 1) //���������е����
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , 65, s[3]);//�����µ�
            clear_right_all();
            page=ban_building(gameinfop,pxsel,pysel);
            return page;
		}
		else if (left_toolbotton_mouse_press(5) == 1) //���������е����
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , 65, s[3]);//�����µ�
            clear_right_all();
            //page=ban_building(gameinfop,pxsel,pysel);
            return page;
		}
	}
}



/*public����
�����ͼ
*/
void draw_map(int x1,int y1,int x2,int y2,int width,int height,struct GameInfo *gameinfop)
{
	int dx=x2-x1;
	int dy=y2-y1;
	int i,j;
	
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

/*public����
����ɫ�Ĵ��ͼ
*/
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
			else if(gameinfop->m_info[i][j].building.id!=0)
			{
				if (gameinfop->m_info[i][j].building.bui_time==0)
				{
					draw_map_building(i,j,atoi(gameinfop->m_info[i][j].building.pic_path));
				}
				else
				{
					puthz2(300+j*92,135+i*92,24,28,0xFA80,"������");
				}
				
			}
		}
	}
	//huge_engineer
}

void draw_map_building(int i,int j,int n)
{
	char path[50];
	sprintf(path,"PICTURE\\build\\%d.bmp",n);
	Readbmp64k(300+j*92,105+i*92,path);
}
/*public����
�����ͼ�ϵĶ�Ӧ�㣬i��Ӧ�У�j��Ӧ��
*/
int mouse_press_map(int i,int j)
{
	//draw_map(300,105,954,759,7,7);
	return mouse_press(300+j*90,105+i*90,390+j*90,195+i*90);
}

/*private����
���뽨���������ĺ���
-1��-5����Ӧ��page
*/
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

/*private����
�βΣ� xΪ��Ӧ��page��p1�ǽ����������ͷ��һ���½������Ͳ�������
������ʵ�ֹ��ܣ����콨������
*/
int buildlist(int x,struct GameInfo *gameinfop,nodebq *p1,int* pxsel,int* pysel)
{
	nodeb *p[3][5];
	nodeb *tempp;
	int pressflag1=0;
	int pressflag2=0;
	int page;
	int i,j,k,d;
	char str[30];
	struct Building building[5];
	int nodeflag[5]={0};
	
	/*p����Ϊnodeb����
	
	*/
	for (i=0;i<3;i++)
	{
		for (j=0;j<5;j++)
		{
			p[i][j]=create_nodeb();
		}
	}
	
	
	for (i=0;i<5;i++)
	{
		nodeflag[i]=dlist_building(x,i+1,p[0][i],p[1][i],p[2][i],gameinfop,&building[i]);
		delay(20);
	}
	//0x7C00
	sprintf(str,"��%dҳ",x);
	put_hz16_asc16_size(50,300,3,3,str,1,"HZK\\HZ16");
	btn_bar_Draw(60,400,160,450);
	puthz2(60,400,32,32,1,"��һҳ");

	btn_bar_Draw(60,500,160,550);
	puthz2(60,500,32,32,1,"��һҳ");
	
	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if (judge_press_mainbutton(3,&page))
		{
			free_nodeb_list(p);
			return page;
		}
		
		if (mouse_press(60,400,160,450)==1)
		{
			if (x==1)
			{
				continue;
			}
			else
			{
				clear_main_all2(1);
				clear_right_all();
				free_nodeb_list(p);
				return -(x-1);
			}
		}
		
		else if (mouse_press(60,500,160,550)==1)
		{
			if (x==5)
			{
				continue;
			}
			else
			{
				clear_main_all2(1);
				clear_right_all();
				free_nodeb_list(p);
				return -(x+1);
			}
		}
		
		
		//��������
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
				clear_main_all2(1);
				clear_right_all();
				btn_bar_Draw(50,250,150,300);
				puthz2(50,250,32,32,1,"����");
				//draw_map2(300,105,954,759,7,7,gameinfop);
				//draw_map(300,105,954,759,7,7,gameinfop);
				draw_buildmap(*gameinfop,*pxsel,*pysel);
				draw_minimap(*gameinfop,*pxsel,*pysel);
				
				pressflag2=0;
				while (1)
				{
					mouse_renew(&MouseX,&MouseY,&press);
					if(renew_map(pxsel,pysel)==1)
					{
						draw_buildmap(*gameinfop,*pxsel,*pysel);
						draw_minimap(*gameinfop,*pxsel,*pysel);
					}
					if (mouse_press(50,250,150,300)==1)
					{
						clrmous(MouseX,MouseY);
						clear_main_all2(1);
						clear_right_all();
						page=3;
						pressflag2++;
						break;
					}
					for (i=0;i<7;i++)
					{
						for(j=0;j<7;j++)
						{
							if(mouse_press_map(i,j)==1&&gameinfop->m_info[*pysel+i][*pxsel+j].building.id==0)
							{
								lastinsert_nodebq(p1,i,j);
								gameinfop->m_info[*pysel+i][*pxsel+j].building.res_cost.nanomaterial=building[k].res_cost.nanomaterial;
								gameinfop->m_info[*pysel+i][*pxsel+j].building.res_cost.rarematerial=building[k].res_cost.rarematerial;
								//char
								gameinfop->m_info[*pysel+i][*pxsel+j].building.id=building[k].id;
								gameinfop->m_info[*pysel+i][*pxsel+j].building.lock=0;
								d=0;
								while (building[k].name[d]!='\0')
								{
									gameinfop->m_info[*pysel+i][*pxsel+j].building.name[d]=building[k].name[d];
									d++;
								}
								gameinfop->m_info[*pysel+i][*pxsel+j].building.name[d]='\0';
								
								d=0;
								while (building[k].pic_path[d]!='\0')
								{
									gameinfop->m_info[*pysel+i][*pxsel+j].building.pic_path[d]=building[k].pic_path[d];
									d++;
								}
								gameinfop->m_info[*pysel+i][*pxsel+j].building.pic_path[d]='\0';
								gameinfop->m_info[*pysel+i][*pxsel+j].building.bui_time=building[k].bui_time;
								
								gameinfop->m_info[*pysel+i][*pxsel+j].building.res_add.nanomaterial=building[k].res_add.nanomaterial;
								gameinfop->m_info[*pysel+i][*pxsel+j].building.res_add.rarematerial=building[k].res_add.rarematerial;
								gameinfop->m_info[*pysel+i][*pxsel+j].building.res_add.oxygen=building[k].res_add.oxygen;
								gameinfop->m_info[*pysel+i][*pxsel+j].building.res_add.water=building[k].res_add.water;
								gameinfop->m_info[*pysel+i][*pxsel+j].building.res_add.food=building[k].res_add.food;
								gameinfop->m_info[*pysel+i][*pxsel+j].building.res_add.energy=building[k].res_add.energy;
								gameinfop->m_info[*pysel+i][*pxsel+j].building.res_add.fuel=building[k].res_add.fuel;
								gameinfop->m_info[*pysel+i][*pxsel+j].building.res_add.mineral=building[k].res_add.mineral;
								
								
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
						draw_main_toolbotton(550,0xBBBB,"����","��ʾ");
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

int dlist_building(int newpage,int location,nodeb *p1,nodeb *p2,nodeb *p3,struct GameInfo *gameinfop,struct Building *building)
{
	char str[30]={'\0'};
	int i=0,j=0;
	int flag;
	nodeb *p;
	flag=get_building_info((newpage-1)*5+location,building);
	if(flag)
	{
		return 1;
	}
	//0xFE00
	btn_bar_Draw(240,120+(location-1)*130,920,230+(location-1)*130);
	btn_bar_Draw(920,120+(location-1)*130,1000,230+(location-1)*130);
	puthz2(920,120+(location-1)*130,32,32,3000,"����");
	sprintf(str,"PICTURE\\build\\%d.bmp",atoi(building->pic_path));
	Readbmp64k(720,145+(location-1)*130,str);

	puthz3(830,150+(location-1)*130,24,24,1000,"ʱ����");
	sprintf(str,"%d����",building->bui_time);
	put_hz24_asc32(830,185+(location-1)*130,str,0xA000,"HZK\\Hzk24k");

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
		put_hz24_asc32(460+i*180,123+(location-1)*130,str,p->color,"HZK\\Hzk24k");
		j=0;
		while(str[j]!='\0')
		{
			str[j++]='\0';
		}
		i++;
		p=p->next;
	}
	
	i=0;
	puthz3(250,165+(location-1)*130,24,24,1,"�����棺");
	p=p2;
	headinsert1_add_nodeb(p,*building,gameinfop);
	p=p->next;
	while(p!=NULL)
	{
		sprintf(str,"%s:%d",p->name,p->number);
		put_hz24_asc32(340+i*110,165+(location-1)*130,str,p->color,"HZK\\Hzk24k");
		j=0;
		while(str[j]!='\0')
		{
			str[j++]='\0';
		}
		i++;
		p=p->next;
	}
	
	i=0;
	puthz3(250,195+(location-1)*130,24,24,1,"��ά����");
	p=p3;
	headinsert1_maintfee_nodeb(p,*building,gameinfop);
	p=p->next;
	while(p!=NULL)
	{
		sprintf(str,"%s:%d",p->name,p->number);
		put_hz24_asc32(340+i*110,195+(location-1)*130,str,p->color,"HZK\\Hzk24k");
		j=0;
		while(str[j]!='\0')
		{
			str[j++]='\0';
		}
		i++;
		p=p->next;
	}
	
	puthz2(250,125+(location-1)*130,32,32,1,building->name);

	return 0;
}

/*private����
�����β�id�����ļ���Ѱ����Ӧλ�ã�����ȡ������Ϣ�浽*building��
��ע�⣬���ڿƼ����ܽ��������ļ��룬���id����˵�id����������˼�����Ƕ�Ӧ������id
��ϸ�ɲο�data�ļ����е�building.txt�ļ�
*/
int get_building_info(int localine,struct Building* building)
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
	
	while ((c=fgetc(file))!='\n');

	i=0;
	while ((c=fgetc(file))!='\n')
	{
		str[i++]=c;
	}
	str[i]='\0';
	total= atoi(str);
	
	if(total<localine)
	{
		fclose(file);
		return 1;
	}
	
	
	
	for (i=0;i<localine-1;i++)
	{
		c=fgetc(file);
		if (c=='#')
		{
			i--;
		}
		while ((c=(fgetc(file)))!='\n')
		{
			if (c=='$')
			{
				fclose(file);
				return 1;
			}
		}

	}
	
	while(1)
	{
		if ((c=(fgetc(file)))!='#')
		{
			fseek(file,-1,SEEK_CUR);
			
			break;
		}
		else
		{
			while ((c=(fgetc(file)))!='\n')
			{
				if (c=='$')
				{
					fclose(file);
					return 1;
				}
			}
		}
	}
	
	//id
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	building->id= atoi(str);
	
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



/*private����
nodeb��������������������������
nodeb����ֻ����ʾ����һ�������Ļ�����Ϣ��������
���磬�ڵ�����½���������Ľ��������Կ����������
����������Ͷ�Ӧ��5��nodeb����
nodebq����ڵ�洢�ľ��ǽ��컨�ѣ������棬��ά���е���ֵ
*/
nodeb* create_nodeb(void)
{
	nodeb *p=(nodeb*)malloc(sizeof(nodeb));
	p->next=NULL;
	return p;
}

/*private����
nodeb����������������ͷ�巨���� ����������ֵ �Ľڵ�
*/
void headinsert1_cost_nodeb(nodeb *p,struct Building building,struct GameInfo *gameinfop)
{
	nodeb *temp;
	
	if(building.res_cost.nanomaterial>0)
	{
		temp=(nodeb*)malloc(sizeof(nodeb));
		temp->next=p->next;
		p->next=temp;
		strcpy(temp->name,"���ײ���");
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
		strcpy(temp->name,"ϡ�в���");
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

/*private����
nodeb����������������ͷ�巨���� ���������� ��ֵ �Ľڵ�
���У���������ֽ����Ϊ��ɫ
*/
void headinsert1_add_nodeb(nodeb *p,struct Building building,struct GameInfo *gameinfop)
{
	nodeb *temp;
	char *s[8]={"���ײ���","ϡ�в���","����","��ˮ","ʳ��","����","ȼ��","��Դ"};
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

/*private����
nodeb����������������ͷ�巨���� ������ά�� ��ֵ �Ľڵ�
*/
void headinsert1_maintfee_nodeb(nodeb *p,struct Building building,struct GameInfo *gameinfop)
{
	nodeb *temp;
	char *s[8]={"���ײ���","ϡ�в���","����","��ˮ","ʳ��","����","ȼ��","��Դ"};
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
			temp->color=0xA000;
		}
	}
	
}

/*private����
nodeb����������������free����
*/
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

void free_nodeb_list(nodeb *p[3][5])
{
	int i,j;
	for (i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			free_nodeb(p[i][j]);
		}
	}
}
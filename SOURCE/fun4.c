#include <common.h>
#include <game.h>
#include <fun3_2.h>
#include <fun3.h>
#include <WRKMNG.h>
#include <fun5.h>
#include <fun4.h>
#include <nodet.h>
#include <ORDFUNS.h>
int proj_fun4(struct GameInfo* gameinfop)
{
	int page=4;
	char *s[3]={"�����Ƽ�","����Ƽ�","�����Ƽ�"};
	draw_main_toolbotton_activate(708,0xFF19,"�Ƽ�","�о�");
	
	draw_all_leftbuttons(3,65,s);
	
	//drawmous(MouseX,MouseY);
	
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if (judge_press_mainbutton(4,&page))
		{
			return page;
		}
		
		if (left_toolbotton_mouse_press(1) == 1) //���������е����
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , 65, s[0]);//�����µ�
            clear_right_all();
            page=research_lifetech(gameinfop);
            return page;   
		}
		else if (left_toolbotton_mouse_press(2) == 1) //���������е����
        {
            clrmous(MouseX,MouseY);
            clear_main_all();
            draw_left_toolbotton_activate(95 , 65, s[1]);//�����µ�
            clear_right_all();
            //page=have_researched(gameinfop);
            return page;   
		}
		else if (left_toolbotton_mouse_press(3) == 1) //���������е����
        {
            clrmous(MouseX,MouseY);
            clear_main_all();
            draw_left_toolbotton_activate(95 , 65, s[2]);//�����µ�
            clear_right_all();
            //page=production_tech(gameinfop);
            return page;  
		}
	}
}

int research_lifetech(struct GameInfo *gameinfop)
{
	int page=4;
	int i;
	int location[10][2];
	tree* p=create_lifetech_tree();
	for (i=0;i<10;i++)
	{
		id_find_xy_lifetech(p,i+1,location);
	}
	draw_lifetech_line(p);
	draw_lifetech_tree(p);
	

	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if (judge_press_mainbutton(4,&page))
		{
			break;
		}
		for (i=0;i<10;i++)
		{
			if (mouse_press(location[i][0]-20,location[i][1]-20,location[i][0]+20,location[i][1]+20)==1)
			{
				clrmous(MouseX,MouseY); 
				draw_lifetech_toast(p,i+1);
				delay(400);
				while(1)
				{
					mouse_renew(&MouseX,&MouseY,&press);
					if (mouse_press(0,0,1024,768)==1)
					{
						clrmous(MouseX,MouseY); 
						load_lifetech_toast();
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

void id_find_xy_lifetech(tree *p,int id,int (*arr)[2])
{
	int i;
	if (p==NULL)
	{
		return;
	}
	if (p->id==id)
	{
		arr[id-1][0]=p->x;
		arr[id-1][1]=p->y;
	}
	for (i=0;i<CHILD_NUM;i++)
	{
		id_find_xy_lifetech(p->child[i],id,arr);
	}
}

void id_find_baseinfo_lifetech(tree *p,tree *temp,int id)
{
	int i;
	if (p==NULL)
	{
		return;
	}
	if (p->id==id)
	{
		temp->id=p->id;
		temp->type=p->type;
		temp->point=p->point;
		temp->parent=p->parent;
		temp->flag=p->flag;
		strcpy(temp->name,p->name);
	}
	for (i=0;i<CHILD_NUM;i++)
	{
		id_find_baseinfo_lifetech(p->child[i],temp,id);
	}
}

void draw_lifetech_tree(tree *p)
{
	int i;
	if (p==NULL)
	{
		return;
	}

	for (i=0;i<CHILD_NUM;i++)
	{
		draw_lifetech_tree(p->child[i]);
	}
	if (p->flag==1)
	{
		bar(p->x-20,p->y-20,p->x+20,p->y+20,1000);
	}
	else
	{
		btn_bar_Draw(p->x-20,p->y-20,p->x+20,p->y+20);
	}
	
}

void draw_lifetech_toast(tree *p,int id)
{
	tree temp;
	char str[30];
	id_find_baseinfo_lifetech(p,&temp,id);
	SaveBMP(300,500,800,700,0);
	btn_bar_Draw(300,500,900,750);
	
	puthz2(300,500,32,32,1,temp.name);

	btn_bar_Draw0(300,650,400,700);
	puthz2(300,650,32,32,1,"ȡ��");

	btn_bar_Draw0(700,650,800,700);
	puthz2(700,650,32,32,1,"�о�");

	if (temp.parent->flag==0)
	{
		puthz2(300,550,32,32,1,"ǰ�ÿƼ�δ����");
	}
	if (temp.flag==0)
	{
		puthz(500,500,"δ�о�",32,32,1);
	}
	sprintf(str,"%d",temp.point);
	put_hz24_asc32(300,600,str,1,"HZK\\HZK24");
}

void load_lifetech_toast(void)
{
	LoadBMP(300,500,800,700,0);
}

void draw_lifetech_line(tree *leaf)
{
	int i;
	if (leaf==NULL)
	{
		return;
	}
	for (i=0;i<CHILD_NUM;i++)
	{
		if (leaf->child[i]!=NULL)
		{
			if (leaf->flag==1)
			{
				line_thick(leaf->x,leaf->y,leaf->child[i]->x,leaf->child[i]->y,4,3000);
			}
			else
			{
				line_thick(leaf->x,leaf->y,leaf->child[i]->x,leaf->child[i]->y,4,1);
			}
		}
	}
	
	for (i=0;i<CHILD_NUM;i++)
	{
		draw_lifetech_line(leaf->child[i]);
	}
}

void traverse_tree_to_nodetlist(tree *p,nodet *pt,int floor)
{
	int i;
	if (p==NULL || p->floor==floor+1)
	{
		return;
	}
	else
	{
		lastinsert_nodet_list(pt,p->floor,p->id);
		for (i=0;i<5;i++)
		{
			traverse_tree_to_nodetlist(p->child[i],pt,floor);
		}
	}
}

void printf_nodet_list(nodet *p,int floor)
{
	int i,j;
	int len;
	int initpos;
	int apart;
	for (i=0;i<floor;i++)
	{
		len=calculate_nodet_len(p+i);
		for (j=0;j<len;j++)
		{
			cal_nodet_list_pos(len,&initpos,&apart);
			btn_bar_Draw1(initpos+j*apart,120+i*60,initpos+20+j*apart,140+i*60);
		}
	}
}

void cal_nodet_list_pos(int num,int *initpos,int *apart)
{
	*apart=(1024-235)/(num+1);
	*initpos=235+(*apart);
}


void draw_leaves(tree *p,int floor)
{
	int i;
	if (p==NULL || p->floor==floor+1)
	{
		return;
	}
	else
	{
		btn_bar_Draw1(600,200+(p->floor-1)*30,620,220+(p->floor-1)*30);
		for (i=0;i<5;i++)
		{
			draw_leaves(p->child[i],floor);
		}
	}
}

/*researchע��˵��
tree p1 p2 p3�ǲ�ͬ�Ƽ�����ָ��
pp1�ǵݹ����δ�о��Ƽ�������
pp2�Ǵ�pp1�������ȡ�ĿƼ�
*/
// int research(struct GameInfo* gameinfop)
// {
// 	int page=4;
// 	int flag1=0;
// 	int i,j;
	
// 	tree* p1=create_techtree1();
// 	tree* p2=create_techtree2();
// 	tree* p3=create_techtree3();
// 	nodet *pp1=create_nodet();
	
// 	nodet *pp2;
	
	
// 	generate_technode(p1,pp1);
// 	generate_technode(p2,pp1);
// 	generate_technode(p3,pp1);
	
// 	pp2=extract_nodet(pp1,3);
	
	
// 	if (gameinfop->gametech.research_flag==1)
// 	{
// 		draw_techlist1(gameinfop);
// 	}
// 	else
// 	{
// 		draw_techlist0(pp2);
// 	}
	
	
	
// 	printf_nodet(pp2);
	
	
	
// 	puthz(20,200,"ÿ�¿��е㣺",24,24,1);
// 	put_asc16_number_size(160,200,2,2,gameinfop->techpoint,1);
	
// 	while(1)
// 	{
// 		mouse_renew(&MouseX,&MouseY,&press);
// 		if(main_toolbotton_mouse_press(1)==1)
//         {
//             clrmous(MouseX,MouseY); 
//             draw_main_toolbotton(708,0xFF19,"�Ƽ�","�о�");
//             clear_main_all();
// 			clear_right_all();
// 			page=1;
//             break;
            
//         }
//         else if(main_toolbotton_mouse_press(2)==1)
//         {
//             clrmous(MouseX,MouseY); 
//             draw_main_toolbotton(708,0xFF19,"�Ƽ�","�о�");
//             clear_main_all();
// 			clear_right_all();
//             page=2;
//             break;

//         }
//         else if(main_toolbotton_mouse_press(3)==1)
//         {
//             clrmous(MouseX,MouseY); 
//             draw_main_toolbotton(708,0xFF19,"�Ƽ�","�о�");
//             clear_main_all();
// 			clear_right_all();
//             page=3;
//             break;
//         }
//         else if(main_toolbotton_mouse_press(4)==1)
//         {
//             clrmous(MouseX,MouseY); 
//             draw_main_toolbotton(708,0xFF19,"�Ƽ�","�о�");
//             clear_main_all();
// 			clear_right_all();
//             page=4;
//             break;
//         }
//         else if(main_toolbotton_mouse_press(5)==1)
//         {
//             clrmous(MouseX,MouseY); 
//             draw_main_toolbotton(708,0xFF19,"�Ƽ�","�о�");
//             clear_main_all();
// 			clear_right_all();
//             page=5;
//             break;
//         }
		
// 		if (gameinfop->gametech.research_flag==0)
// 		{
// 			for(i=0;i<3;i++)
// 			{
// 				if (mouse_press(900,150+(i)*180,1000,310+(i)*180)==1)
// 				{
// 					start_research_tech(pp2,i,gameinfop);
// 					gameinfop->gametech.research_flag=1;
// 					gameinfop->gametech.havepoints=0;
// 					flag1++;
// 					break;
// 				}
// 			}
// 			if (flag1==1)
// 			{
// 				clrmous(MouseX,MouseY); 
// 				draw_main_toolbotton(708,0xFF19,"�Ƽ�","�о�");
// 				clear_main_all();
// 				clear_right_all();
// 				page=4;
// 				break;
// 			}
// 		}
// 	}
	
	
// 	free_tree(p1);
// 	free_tree(p2);
// 	free_tree(p3);
// 	free_nodet(pp2);
// 	free_nodet(pp1);

// 	return page;
// }

// int have_researched(struct GameInfo* gameinfop)
// {
// 	int page=4;
// 	int flag1=0;
// 	int i,j;
// 	int maxpage;
// 	int len;
// 	int oldpage=1,newpage=1;
// 	tree* p1=create_techtree1();
// 	tree* p2=create_techtree2();
// 	tree* p3=create_techtree3();
// 	nodet *pp1=create_nodet();
// 	nodet *temp;
	
	
// 	generate_technode2(p1,pp1);
// 	generate_technode2(p2,pp1);
// 	generate_technode2(p3,pp1);
	
// 	len=calculate_nodet_len(pp1);
// 	maxpage=len/6+1;
	
// 	draw_have_researched(newpage,pp1);
// 	while(1)
// 	{
// 		mouse_renew(&MouseX,&MouseY,&press);
		
// 		if (newpage!=oldpage)
// 		{
// 			clrmous(MouseX,MouseY); 
// 			clear_right_all();
// 			clear_main_all2(1);
// 			draw_have_researched(newpage,pp1);
// 			oldpage=newpage;
// 		}
		
// 		if(main_toolbotton_mouse_press(1)==1)
//         {
//             clrmous(MouseX,MouseY); 
//             draw_main_toolbotton(708,0xFF19,"�Ƽ�","�о�");
//             clear_main_all();
// 			clear_right_all();
// 			page=1;
//             break;
            
//         }
//         else if(main_toolbotton_mouse_press(2)==1)
//         {
//             clrmous(MouseX,MouseY); 
//             draw_main_toolbotton(708,0xFF19,"�Ƽ�","�о�");
//             clear_main_all();
// 			clear_right_all();
//             page=2;
//             break;

//         }
//         else if(main_toolbotton_mouse_press(3)==1)
//         {
//             clrmous(MouseX,MouseY); 
//             draw_main_toolbotton(708,0xFF19,"�Ƽ�","�о�");
//             clear_main_all();
// 			clear_right_all();
//             page=3;
//             break;
//         }
//         else if(main_toolbotton_mouse_press(4)==1)
//         {
//             clrmous(MouseX,MouseY); 
//             draw_main_toolbotton(708,0xFF19,"�Ƽ�","�о�");
//             clear_main_all();
// 			clear_right_all();
//             page=4;
//             break;
//         }
//         else if(main_toolbotton_mouse_press(5)==1)
//         {
//             clrmous(MouseX,MouseY); 
//             draw_main_toolbotton(708,0xFF19,"�Ƽ�","�о�");
//             clear_main_all();
// 			clear_right_all();
//             page=5;
//             break;
//         }
		
// 		if (mouse_press(60,350,180,400)==1)
// 		{
// 			if (newpage>1)
// 			{
// 				newpage--;
// 			}
// 		}
// 		else if (mouse_press(60,420,180,470)==1)
// 		{
// 			if (newpage<maxpage)
// 			{
// 				newpage++;
// 			}
// 		}
		
// 		for (i=(newpage-1)*6+1;i<= ((newpage)*6 <= len ? (newpage)*6 : len) ;i++)
// 		{
// 			if (mouse_press(900,120+(i-((newpage-1)*6)-1)*100,1000,200+(i-((newpage-1)*6)-1)*100)==1)
// 			{
// 				temp=pp1;
// 				for (j=0;j<i;j++)
// 				{
// 					temp=temp->next;
// 				}
// 				clrmous(MouseX,MouseY); 
// 				clear_main_all2(1);
// 				clear_right_all();
// 				page=display_tech_txt(temp->type,temp->id);
// 				oldpage=0;
// 				break;
// 			}
// 		}
// 	}
	
// 	free_tree(p1);
// 	free_tree(p2);
// 	free_tree(p3);
	
// 	free_nodet(pp1);
// 	return page;
// }

void draw_have_researched(int page,nodet *pp1)
{
	int length=calculate_nodet_len(pp1);
	int i;
	int index=(page-1)*6+1;
	char name[50]={'\0'};
	char str[20]={'\0'};
	nodet *temp=pp1;
	for (i=0;i<index;i++)
	{
		temp=temp->next;
	}
	sprintf(str,"%d/%dҳ",page,length/6+1);
	put_hz24_asc32(80,300,str,1,"HZK\\Hzk24k");
	bar(60,350,180,400,0xFE00);
	puthz(60,350,"��һҳ",24,24,1);
	bar(60,420,180,470,0xFE00);
	puthz(60,420,"��һҳ",24,24,1);
	
	for (i=0;i<6;i++)
	{
		if (temp==NULL)
		{
			break;
		}
		bar(250,120+(i)*100,900,200+(i)*100,0xBDBD);
		bar(900,120+(i)*100,1000,200+(i)*100,0xFE00);
		//puthz(900,165+(i)*100,"�о�",32,32,1);
		puthz(900,140+(i)*100,"�鿴˵��",24,24,1);
		//puthz(900,165+(i)*100,"˵��",24,24,1);
		
		//puthz(630,170+(i)*100,"������е㣺",24,24,1);
		put_asc16_number_size(780,170+(i)*100,2,2,temp->point,1);
		//get_tech_name(temp->type,temp->id,name);
		puthz(270,120+(i)*100,name,24,24,1);
		
		//put_asc16_number_size(950,170+(i)*100,2,2,temp->type,1);
		//put_asc16_number_size(1000,170+(i)*100,2,2,temp->id,1);
		
		temp=temp->next;
		//sprintf(str,"%d����",building->bui_time);
		//put_hz24_asc32(820,200+(location-1)*130,str,1000,"HZK\\Hzk24k");
	
	}
}


int display_tech_txt(int type,int id)
{
	int i;
	char *txt[10];
	char name[50]={'\0'};
	char effect[50]={'\0'};

	int line;
	for (i=0;i<10;i++)
	{
		txt[i]=(char *)malloc(100);
	}
	
	line=get_tech_txt(type,id,txt);
	
	
	
	//get_tech_name(type,id,name);
	puthz(250,120,name,48,48,1);
	
	bar(100,300,200,350,0xFF19);
	puthz(100,300,"����",24,24,1);
	
	puthz(250,200,"�Ѽ���Ч����",32,32,1);
	get_tech_effect(type,id,effect);
	put_hz24_asc32(440,200,effect,1,"HZK\\Hzk24k");

	puthz(250,250,"��飺",32,32,1);
	
	for (i=0;i<line;i++)
	{
		puthz(250,290+i*30,txt[i],24,24,1);
	}
	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if (mouse_press(100,300,200,350)==1)
		{
			break;
		}
		
	}

	for (i=0;i<10;i++)
	{
		free(txt[i]);
	}
	return 4;
}

void start_research_tech(nodet *pp2,int i,struct GameInfo *gameinfop)
{
	int j;
	nodet *temp=pp2->next;
	
	for (j=0;j<i;j++)
	{
		temp=temp->next;
	}
	
	gameinfop->gametech.id=temp->id;
	gameinfop->gametech.type=temp->type;
	gameinfop->gametech.totalpoints=temp->point;
	
}


void draw_techlist0(nodet *pp2)
{
	int len=calculate_nodet_len(pp2);
	int i,j;
	char name[50]={'\0'};
	char effect[50]={'\0'};
	nodet *temp=pp2->next;
	for (i=0;i<len;i++)
	{
		bar(250,150+(i)*180,900,310+(i)*180,0xBDBD);
		bar(900,150+(i)*180,1000,310+(i)*180,0xFE00);
		puthz(900,165+(i)*180,"�о�",32,32,1);

		puthz(630,170+(i)*180,"������е㣺",24,24,1);

		puthz(260,200+(i)*180,"Ч����",32,32,1);
		get_tech_effect(temp->type,temp->id,effect);
		put_hz24_asc32(340,200+(i)*180,effect,1,"HZK\\Hzk24k");

		put_asc16_number_size(780,170+(i)*180,2,2,temp->point,1);
		//get_tech_name(temp->type,temp->id,name);
		puthz(270,150+(i)*180,name,48,48,1);
		
		put_asc16_number_size(950,170+(i)*180,2,2,temp->type,1);
		put_asc16_number_size(1000,170+(i)*180,2,2,temp->id,1);
		
		temp=temp->next;
		//sprintf(str,"%d����",building->bui_time);
		//put_hz24_asc32(820,200+(location-1)*130,str,1000,"HZK\\Hzk24k");
	}
}

void draw_techlist1(struct GameInfo *gameinfop)
{
	char str[30]={'\0'};
	char name[50]={'\0'};
	char effect[100]={'\0'};
	char *txt[10];
	int i;
	int line;
	for (i=0;i<10;i++)
	{
		txt[i]=(char *)malloc(100);
	}
	//bar(250,150,900,310,0xBDBD);
	puthz(250,120,"�����о���",48,48,1);
	get_tech_name2(gameinfop,name);
	puthz(480,120,name,48,48,1);
	puthz(250,200,"���е㣺",32,32,1);
	line=get_tech_txt(gameinfop->gametech.type,gameinfop->gametech.id,txt);

	sprintf(str,"%d/%d",gameinfop->gametech.havepoints,gameinfop->gametech.totalpoints);
	put_hz24_asc32(370,205,str,1,"HZK\\Hzk24k");
	
	puthz(250,250,"�о�Ч����",32,32,1);
	get_tech_effect(gameinfop->gametech.type,gameinfop->gametech.id,effect);
	put_hz24_asc32(400,255,effect,1,"HZK\\Hzk24k");
	
	puthz(250,300,"��飺",32,32,1);
	for (i=0;i<line;i++)
	{
		puthz(250,335+i*30,txt[i],24,24,1);
	}
	for (i=0;i<10;i++)
	{
		free(txt[i]);
	}
}

void get_tech_basic_info(tree *p,int type,int id)
{
	FILE *file=fopen("./data/tech.txt","r");
	int i;
	char c;
	char str[30];
	if (file==NULL)
	{
		printf("open file error\n");
		return;
	}
	
	for (i=0;i<type;i++)
	{
		while ((c=fgetc(file))!='#');
	}
	
	while ((c=fgetc(file))!='\n');
	
	for (i=0;i<id-1;i++)
	{
		while ((c=fgetc(file))!='\n');
	}
	
	//����id
	while ((c=fgetc(file))!=' ');

	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	p->floor=atoi(str);

	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	p->flag=atoi(str);

	i=0;
	while ((c=fgetc(file))!=' ')
	{
		p->name[i++]=c;
	}
	p->name[i]='\0';
	
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	p->point=atoi(str);

	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	p->x=atoi(str);

	i=0;
	while ((c=fgetc(file))!='\n')
	{
		str[i++]=c;
	}
	str[i]='\0';
	p->y=atoi(str);

	fclose(file);
}

void get_tech_name2(struct GameInfo *gameinfop,char* name)
{
	FILE *file=fopen("./data/tech.txt","r");
	int type=gameinfop->gametech.type;
	int id=gameinfop->gametech.id;
	int i;
	char c;
	if (file==NULL)
	{
		printf("open file error\n");
		return;
	}
	
	for (i=0;i<type;i++)
	{
		while ((c=fgetc(file))!='#');
	}
	
	while ((c=fgetc(file))!='\n');
	
	for (i=0;i<id-1;i++)
	{
		while ((c=fgetc(file))!='\n');
	}
	
	for (i=0;i<2;i++)
	{
		while ((c=fgetc(file))!=' ');
	}
	
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		name[i++]=c;
	}
	name[i]='\0';
	fclose(file);
}

void get_tech_effect(int type, int id,char *effect)
{
	FILE *file=fopen("./data/tech1.txt","r");
	char c;
	int i;

	if (file==NULL)
	{
		printf("open file error\n");
		return;
	}
	
	for (i=0;i<type;i++)
	{
		while ((c=fgetc(file))!='#');
	}
	while ((c=fgetc(file))!='\n');
	
	for (i=0;i<id;i++)
	{
		while ((c=fgetc(file))!='$');
	}
	while ((c=fgetc(file))!='\n');
	
	fgets(effect,100,file);
	effect[strlen(effect)-1]='\0';
	fclose(file);
}

void change_techflag(int type,int id)
{
	FILE *file1;
	FILE *file2;
	char str[30]={'\0'};
	char c;
	int i,j,k;
	
	file1=fopen("./data/tech.txt","r");
	if (file1==NULL)
	{
		puthz(400,300,"����",32,32,1);
		printf("open error");
		return;
	}
	
	file2=fopen("./data/techt.txt","w");
	if (file2==NULL)
	{
		puthz(400,300,"����",32,32,1);
		printf("open error");
		return;
	}
	
	i=0,j=0,k=0;
	while(1)
	{
		c=fgetc(file1);
		if (k==1)
		{
			fputc('1',file2);
			k++;
			break;
		}
		if (c=='#')
		{
			i++;
		}
		if (i==type)
		{
			if (c=='\n')
			{
				j++;
			}
		}
		if (j==id)
		{
			if (c==' ')
			{
				k++;
			}
		}
		
		fputc(c,file2);
	}
	
	while ((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	remove("./data/tech.txt");
    rename("./data/techt.txt", "./data/tech.txt");
}

int get_tech_txt(int type,int id,char **txt)
{
	FILE *file=fopen("./data/tech2.txt","r");
	char c;
	int i;
	if (file==NULL)
	{
		printf("open file error\n");
		return;
	}
	
	for (i=0;i<type;i++)
	{
		while ((c=fgetc(file))!='#');
	}
	while ((c=fgetc(file))!='\n');
	
	for (i=0;i<id;i++)
	{
		while ((c=fgetc(file))!='$');
	}
	while ((c=fgetc(file))!='\n');
	//exit(0);
	i=0;
	while ((c=fgetc(file))!='$')
	{
		fseek(file,-1,SEEK_CUR);
		fgets(txt[i],100,file);
		txt[i][strlen(txt[i])-1]='\0';
		i++;
	}
	
	fclose(file);
	return i;
}

tree *create_tree(int type)
{
	int i;
	tree *p=(tree*)malloc(sizeof(tree));
	p->type=type;
	for (i=0;i<CHILD_NUM;i++)
	{
		p->child[i]=NULL;
	}
	return p;
}



void insert_simple_leaf(tree *p,int type,int id,int func)
{
	tree *temp;
	int i;
	temp=(tree*)malloc(sizeof(tree));
	temp->id=id;
	temp->type=type;
	get_tech_basic_info(temp,temp->type,temp->id);

	for (i=0;i<CHILD_NUM;i++)
	{
		temp->child[i]=NULL;
	}
	temp->parent=p;
	if (func==0)
	{
		p->child[0]=temp;
	}
	if (func==1)
	{
		p->child[1]=temp;
	}
	if (func==2)
	{
		p->child[2]=temp;
	}

}


tree *create_tree_pp(int id)
{
	int i;
	tree *p=(tree*)malloc(sizeof(tree));
	p->id=id;
	get_techflag(p);
	for (i=0;i<5;i++)
	{
		p->child[i]=NULL;
	}
	return p;
}
void get_techflag(tree *p)
{
	int id=p->id;
	//int type=p->type;
	FILE *file=fopen("./data/tech.txt","r");
	char str[30]={'\0'};
	char c;
	int i;
	
	if (file==NULL)
	{
		puthz(400,300,"����",32,32,1);
		printf("open error");
		return;
	}
	for (i=0;i<id-1;i++)
	{
		while ((c=fgetc(file))!='\n');
	}

	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	p->floor=atoi(str);

	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	p->id=atoi(str);

	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	p->flag=atoi(str);
	fclose(file);
}


void free_tree(tree *p)
{
	int i;
	if (p==NULL)
	{
		return;
	}
	for (i=0;i<CHILD_NUM;i++)
	{
		free_tree(p->child[i]);
	}
	free(p);
}



nodet *create_nodet(void)
{
	nodet *p=(nodet *)malloc(sizeof(nodet));
	p->next=NULL;
	return p;
}

void headinsert_nodet(nodet *p,int type,int id,int point)
{
	nodet *temp=(nodet *)malloc(sizeof(nodet));
	temp->id=id;
	temp->type=type;
	temp->point=point;
	temp->next=p->next;
	p->next=temp;
}

void delete_nodet(nodet *p,int pos)
{
	nodet *temp;
	int i;
	for (i=0;i<pos-1;i++)
	{
		p=p->next;
	}
	temp=p->next;
	temp=temp->next;
	free(p->next);
	p->next=temp;
}

void getinfo_nodet(nodet *p,int x,int *type,int *id,int *point)
{
	int i;
	for (i=0;i<x;i++)
	{
		p=p->next;
	}
	*type=p->type;
	*id=p->id;
	*point=p->point;
}

nodet *extract_nodet(nodet *p1,int num)
{
	int i,j;
	int type,id,point;
	int k;
	nodet *p=create_nodet();
	int len=calculate_nodet_len(p1);
	srand(time(NULL));
	
	for (i=0,j=0;i<num;i++)
	{
		k=rand()%(len-j)+1;
		getinfo_nodet(p1,k,&type,&id,&point);
		delete_nodet(p1,k);
		j++;
		headinsert_nodet(p,type,id,point);
	}
	return p;
}

int calculate_nodet_len(nodet *p)
{
	nodet *temp;
	int i=0;
	temp=p->next;
	while(temp!=NULL)
	{
		temp=temp->next;
		i++;
	}
	return i;
}

void printf_nodet(nodet *p)
{
	int i=0;
	p=p->next;
	while(p!=NULL)
	{
		put_asc16_number_size(10,500+i*50,2,2,p->type,1);
		p=p->next;
		i++;
	}
}

void free_nodet(nodet *p)
{
	nodet *temp;
	while(p!=NULL)
	{
		temp=p->next;
		free(p);
		p=temp;
	}
}

void get_tech_file(nodet *p,char *str)
{
	int len=calculate_nodet_len(p);
	FILE *file=fopen("./data/tech.txt","r");
	
	fclose(file);
}


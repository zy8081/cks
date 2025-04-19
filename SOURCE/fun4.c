#include <common.h>
#include <draw.h>
#include <game.h>
#include <fun3_2.h>
#include <fun3.h>
#include <WRKMNG.h>
#include <fun5.h>
#include <fun4.h>
#include <fun4_1.h>
#include <fun4_2.h>
#include <fun4_3.h>
#include <nodet.h>
#include <ORDFUNS.h>

int proj_fun4(struct GameInfo* gameinfop)
{
	int page=4;
	char *s[3]={"民生科技","建设科技","生产科技"};
	draw_main_toolbotton_activate(708,0xFF19,"科技","研究");
	
	draw_all_leftbuttons(3,65,s);
	
	//drawmous(MouseX,MouseY);
	
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if (judge_press_mainbutton(4,&page))
		{
			return page;
		}
		
		if (left_toolbotton_mouse_press(1) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , 65, s[0]);//激活新的
            clear_right_all();
            page=research_lifetech(gameinfop);
            return page;
		}
		else if (left_toolbotton_mouse_press(2) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all();
            draw_left_toolbotton_activate(95 , 65, s[1]);//激活新的
            clear_right_all();
            page=research_buildtech(gameinfop);
            return page;   
		}
		else if (left_toolbotton_mouse_press(3) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all();
            draw_left_toolbotton_activate(95 , 65, s[2]);//激活新的
            clear_right_all();
            page=research_manutech(gameinfop);
            return page;  
		}
	}
}

void draw_techpoint(struct GameInfo* gameinfop)
{
	puthz2(20,400,32,32,1000,"每月科研点：");
	put_asc16_number_size(60,450,3,3,gameinfop->techpoint,1000);
}

void display_all_intro(tree *p,struct GameInfo* gameinfop,int type,int id,int *newpage)
{
	tree temp;
	char str[80];
	int i;
	int page=4;
	btn_bar_Draw(250,110,1000,740);

	btn_bar_Draw(850,660,1000,740);
	puthz3(860,670,48,48,1,"研究");

	btn_bar_Draw(250,660,400,740);
	puthz3(270,670,48,48,1,"返回");

	puthz2(260,360,32,34,1,"科技介绍：");
	type_id_printf_techtxt(type,id);

	id_findtree_baseinfo_tech(p,&temp,id);
	puthz2(270,120,48,48,1,temp.name);

	type_id_get_tech_effect(type,id,str);

	if (temp.flag==0)
	{
		puthz2(700,120,48,48,0xA000,"（未研究）");

		puthz2(260,220,32,32,3000,"研究效果：");
		put_hz24_asc32(260,270,str,3000,"HZK\\HZK24");
	}
	else
	{
		puthz2(700,120,48,48,2000,"（已研究）");

		puthz2(260,220,32,32,1000,"研究效果：");
		put_hz24_asc32(260,270,str,1000,"HZK\\HZK24");
	}
	sprintf(str,"所需科研点：%d",temp.point);
	put_hz24_asc32(730,240,str,1,"HZK\\HZK24");

	for (i=0;i<PARENT_NUM;i++)
	{
		if (temp.parent[i]==NULL)
		{
			continue;
		}
		else if (temp.parent[i]->flag==0)
		{
			puthz2(690,190,32,32,0xA000,"前置科技未解锁");
			puthz2(860,670,48,48,0xA000,"研究");
			break;
		}
	}


	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);

		if (mouse_press(250,660,400,740)==1)
		{
			break;
		}
		if (judge_press_mainbutton(4,&page))
		{
			break;
		}
		if (mouse_press(850,660,1000,740)==1)
		{
			start_research(gameinfop,p,type,id,newpage);
			break;
		}
	}
}


void id_find_xy_tech(tree *p,int id,int (*arr)[2])
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
		id_find_xy_tech(p->child[i],id,arr);
	}
}

void id_findtree_baseinfo_tech(tree *p,tree *temp,int id)
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
		temp->parent[0]=p->parent[0];
		temp->parent[1]=p->parent[1];
		temp->parent[2]=p->parent[2];

		temp->flag=p->flag;
		strcpy(temp->name,p->name);
	}
	for (i=0;i<CHILD_NUM;i++)
	{
		id_findtree_baseinfo_tech(p->child[i],temp,id);
	}
}

void draw_tech_tree(tree *p)
{
	int i;
	if (p==NULL)
	{
		return;
	}

	for (i=0;i<CHILD_NUM;i++)
	{
		draw_tech_tree(p->child[i]);
	}
	if (p->flag==1)
	{
		btn_bar_Draw(p->x-20,p->y-20,p->x+20,p->y+20);
		bar(p->x-19,p->y-19,p->x+19,p->y+19,1000);
	}
	else
	{
		btn_bar_Draw(p->x-20,p->y-20,p->x+20,p->y+20);
	}
}

void draw_tech_tree2(struct GameInfo* gameinfop,int type,int (*arr)[2])
{
	int id;
	if (gameinfop->gametech[type-1].research_flag==1)
	{
		id=gameinfop->gametech[type-1].id;
		bar(arr[id-1][0]-19,arr[id-1][1]-19,arr[id-1][0]+19,arr[id-1][1]+19,4000);
	}
}

int draw_researching(struct GameInfo *gameinfop,int type)
{
	char str[80];
	tree temp;
	
	if (gameinfop->gametech[type-1].research_flag==0)
	{
		return 0;
	}
	else
	{
		btn_bar_Draw(300,550,900,750);

		type_id_get_tech_effect(type,gameinfop->gametech[type-1].id,str);
		puthz3(310,620,32,32,1000,"研究效果：");
		put_hz24_asc32(470,630,str,1000,"HZK\\HZK24");

		get_tech_basic_info(&temp,type,gameinfop->gametech[type-1].id);
		puthz2(300,550,48,48,1,temp.name);

		btn_bar_Draw(750,700,900,750);
		puthz2(750,700,32,32,1,"查看详细");

		btn_bar_Draw(300,700,450,750);
		puthz2(310,700,32,32,1,"取消研究");

		puthz2(500,700,32,32,3000,"正在研究中");

		sprintf(str,"%d/%d",gameinfop->gametech[type-1].havepoints,gameinfop->gametech[type-1].totalpoints);
		put_hz24_asc32(750,570,str,1000,"HZK\\HZK24");
		return 1;
	}
}

void stop_researching(struct GameInfo *gameinfop,int type,int *newflag,int *new_refreshing)
{
	char str[50];
	char name[50];
	SaveBMP(290,190,810,510,0);
	btn_bar_Draw(300,200,800,500);

	puthz3(300,200,32,32,0xA000,"你确定要取消研究：");
	type_id_find_name(type,gameinfop->gametech[type-1].id,name);
	sprintf(str,"“%s”吗？",name);
	puthz3(300,240,32,32,3000,str);
	puthz2(300,340,32,32,0xA000,"取消研究将会丢失该科技所有的");
	puthz2(300,375,32,32,0xA000,"科研进度！！！");

	btn_bar_Draw(300,450,400,500);
	puthz3(300,450,32,32,1,"取消");

	btn_bar_Draw(700,450,800,500);
	puthz3(700,450,32,32,1,"确定");

	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if (mouse_press(300,450,400,500)==1)
		{
			clrmous(MouseX,MouseY);
			LoadBMP(290,190,810,510,0);
			delay(300);
			mouse_renew(&MouseX,&MouseY,&press);
			break;
		}
		if (mouse_press(700,450,800,500)==1)
		{
			clrmous(MouseX,MouseY);
			LoadBMP(290,190,810,510,0);
			gameinfop->gametech[type-1].research_flag=0;
			*newflag=0;
			*new_refreshing=1;
			delay(300);
			mouse_renew(&MouseX,&MouseY,&press);
			break;
		}
	}
}


void draw_tech_toast(tree *p,int id)
{
	tree temp;
	char str[80];
	int i;
	id_findtree_baseinfo_tech(p,&temp,id);
	SaveBMP(290,190,810,510,0);
	btn_bar_Draw(300,200,800,500);
	
	puthz3(300,200,32,36,1,temp.name);

	btn_bar_Draw(300,450,400,500);
	puthz3(300,450,32,32,1,"取消");

	btn_bar_Draw(700,450,800,500);
	puthz3(700,450,32,32,1,"研究");

	btn_bar_Draw(475,450,625,500);
	puthz3(475,450,32,32,1,"查看详细");
	for (i=0;i<PARENT_NUM;i++)
	{
		if (temp.parent[i]==NULL)
		{
			continue;
		}
		else if (temp.parent[i]->flag==0)
		{
			puthz2(300,260,32,32,0xA000,"前置科技未解锁");
			puthz2(700,450,32,32,0xA000,"研究");
			break;
		}
	}
	
	type_id_get_tech_effect(p->type,id,str);
	if (temp.flag==0)
	{
		puthz2(600,210,32,32,0xA000,"（未研究）");

		
		puthz2(300,320,32,32,3000,"研究效果：");
		put_hz24_asc32(300,360,str,3000,"HZK\\HZK24");
	}
	else
	{
		puthz2(600,210,32,32,2000,"（已研究）");

		puthz2(300,320,32,32,1000,"研究效果：");
		put_hz24_asc32(300,360,str,1000,"HZK\\HZK24");
	}

	sprintf(str,"所需科研点：%d",temp.point);
	put_hz24_asc32(570,260,str,1,"HZK\\HZK24");
}

void load_tech_toast(void)
{
	LoadBMP(290,190,810,510,0);
}

void draw_tech_line(tree *leaf)
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
				line_thick(leaf->x,leaf->y,leaf->child[i]->x,leaf->child[i]->y,4,1000);
			}
			else
			{
				line_thick(leaf->x,leaf->y,leaf->child[i]->x,leaf->child[i]->y,4,1);
			}
		}
	}
	
	for (i=0;i<CHILD_NUM;i++)
	{
		draw_tech_line(leaf->child[i]);
	}
}

void small_tech_remind_toast(char *str)
{
	SaveBMP(390,290,710,560,1);
	btn_bar_Draw(400,300,700,550);
	puthz2(400,300,32,32,1,str);
	delay(1500);
	LoadBMP(390,290,710,560,1);
}

void start_research(struct GameInfo *gameinfop,tree *p,int type,int id,int *newpage)
{
	tree temp;
	char name[30];
	int i;
	id_findtree_baseinfo_tech(p,&temp,id);
	if (gameinfop->gametech[type-1].research_flag ==1)
	{
		small_tech_remind_toast("已有正在研究的科技");
		return;
	}

	for (i=0;i<PARENT_NUM;i++)
	{
		if (temp.parent[i]==NULL)
		{
			continue;
		}
		if (temp.parent[i]->flag==0)
		{
			small_tech_remind_toast("前置科技未解锁");
			return;
		}
	}


	if (temp.flag==1)
	{
		small_tech_remind_toast("该科技已研究过");
		return;
	}
	
	else
	{
		*newpage=1;

		gameinfop->gametech[type-1].research_flag=1;
		gameinfop->gametech[type-1].havepoints=0;
		gameinfop->gametech[type-1].id=id;
		gameinfop->gametech[type-1].type=type;
		gameinfop->gametech[type-1].totalpoints=type_id_find_totalpoint(type,id);

		SaveBMP(390,290,710,560,2);
		btn_bar_Draw(400,300,700,550);
		puthz2(400,300,32,32,1,"成功开始研究：");
		type_id_find_name(type,id,name);
		puthz2(400,340,32,32,1,name);
		delay(1500);
		LoadBMP(390,290,710,560,2);
	}
}

void type_id_find_name(int type,int id,char *name)
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

	for (i=0;i<3;i++)
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

int type_id_find_totalpoint(int type,int id)
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
	
	for (i=0;i<4;i++)
	{
		while ((c=fgetc(file))!=' ');
	}
	
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';


	fclose(file);
	return atoi(str);
}

void type_id_printf_techtxt(int type,int id)
{
	char *intro[10];
	int i,j;
	char c;
	FILE *file;
	file=fopen("data\\tech2.txt","r");
	if (file==NULL)
	{
		exit(0);
	}

	for (i=0;i<10;i++)
	{
		intro[i]=(char *)malloc(50);
	}

	for (i=0;i<type;i++)
	{
		while ((c=fgetc(file))!='#');
	}

	for (i=0;i<id;i++)
	{
		while ((c=fgetc(file))!='$');
	}
	while((c=fgetc(file))!='\n');

	i=0,j=0;
	while((c=fgetc(file))!='$' && c!='#')
	{
		if (c=='\n')
		{
			intro[i++][j]='\0';
			j=0;
			continue;
		}
		intro[i][j++]=c;
	}

	for (j=0;j<i;j++)
	{
		puthz3(260,400+j*40,32,32,1,intro[j]);
	}

	for (j=0;j<10;j++)
	{
		free(intro[j]);
	}
	fclose(file);
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
	
	//跳过id
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


void type_id_get_tech_effect(int type, int id,char *effect)
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
		puthz(400,300,"错误",32,32,1);
		printf("open error");
		return;
	}
	
	file2=fopen("./data/techt.txt","w");
	if (file2==NULL)
	{
		puthz(400,300,"错误",32,32,1);
		printf("open error");
		return;
	}
	
	i=0,j=0,k=0;
	while(1)
	{
		c=fgetc(file1);
		if (k==2)
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
	temp->parent[0]=p;
	temp->parent[1]=NULL;
	temp->parent[2]=NULL;

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

int check_techflag_infile(WORKFILE *w,int type,int id)
{
	FILE *file=fopen("./data/tech.txt","r");
	char c;
	char str[5];
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
	
	for (i=0;i<id-1;i++)
	{
		while ((c=fgetc(file))!='\n');
	}
	while ((c=fgetc(file))!=' ');
	while ((c=fgetc(file))!=' ');
	i=0;
	while ((c=fgetc(file))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	
	fclose(file);
	if (atoi(str)==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
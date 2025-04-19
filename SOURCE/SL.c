#include <common.h>
#include <game.h>
#include <fun3_2.h>
#include<ORDFUNS.h>
#include<WRKMNG.h>
#include<WRKPLC.h>
#include<DRAWWORK.h>
#include<WRKADD.h>
#include<SL.h>

int save_gminfo(struct GameInfo* pgameinfo,WORKFILE work,int repage)
{
	
	FILE *file=fopen(work.path_dat,"wb");
	struct GameInfo* t=malloc(sizeof(struct GameInfo));
	*t=*pgameinfo;
	//strcpy(pathdat,work.path_dat);
	fwrite(t,sizeof(struct GameInfo),(size_t)1,file);
	fclose(file);
	free(t);
	return repage;
}

void load_gminfo(WORKFILE work,struct GameInfo* gameinfop)
{
	FILE *file=fopen(work.path_dat,"rb+");
	struct GameInfo* t=malloc(sizeof(struct GameInfo));
	put_asc16(700,600,work.path_dat,0);
	fread(t,sizeof(struct GameInfo),(size_t)1,file);
	*gameinfop=*t;
	fclose(file);
	free(t);
	return;

}

void gminfo_init(char* datpath,int t)
{
    int i,j;
	//nodebq *p1;
	struct GameInfo* gameinfo;
	
	//struct Resource res_earns;
    FILE* ft=fopen(datpath,"wb+");
	
	gameinfo->r_info.energy=10000;
	gameinfo->r_info.nanomaterial=10000;
	gameinfo->r_info.rarematerial=10000;
	gameinfo->r_info.oxygen=10000;
	gameinfo->r_info.water=10000;
	gameinfo->r_info.food=10000;
	gameinfo->r_info.fuel=10000;
	gameinfo->r_info.mineral=10000;
	
	gameinfo->year=2030;
	gameinfo->month=1;
	gameinfo->techpoint=200;
	gameinfo->gametech[0].research_flag=0;

	gameinfo->r_info_t=gameinfo->r_info;

	gameinfo->people=0;
	gameinfo->happiness[0]=0;
	gameinfo->happiness[1]=0;

	//初始化地图
	for (i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
		{
			gameinfo->m_info[i][j].building.id=0;
			gameinfo->m_info[i][j].building.bui_time=0;
			gameinfo->m_info[i][j].terrain=0;
		}
	}
	map_init(t,gameinfo);
	rocket_init(&(gameinfo->rocket));
	//rewind(ft);
    fwrite(gameinfo,sizeof(struct GameInfo),(size_t)1,ft);
    fclose(ft);
	free(gameinfo);

}

void save_node(WORKFILE work,nodebq* pnode1)
{
	char pathnode[50];
	FILE* fnode;
	nodebq* pnode=pnode1;
	strcpy(pathnode,work.path);
	strcat(pathnode,"\\usernode.nod");
	fnode=fopen(pathnode,"rb+");
	while(pnode!=NULL)
	{
		fwrite(pnode,sizeof(nodebq),(size_t)1,fnode);
		pnode=pnode->next;
	}
	fclose(fnode);
	free(pathnode);
	return;
}

nodebq* load_node(WORKFILE work)
{
	char*pathnode=malloc((size_t)50);
	FILE* fnode;
	nodebq* pnode=create_nodebq();
	nodebq* pnodetemp=pnode;
	strcpy(pathnode,work.path);
	strcat(pathnode,"\\usernode.nod");
	fnode=fopen(pathnode,"rb+");
	while(1)
	{
		fread(pnode,sizeof(nodebq),(size_t)1,fnode);
		if(pnode->next==NULL)break;
		else
		{
			pnode->next=create_nodebq();
			pnode=pnode->next;
		}

	}
	fclose(fnode);
	free(pathnode);
	return pnodetemp;
}

void node_init(char*pathnode)
{
	FILE* f;
	nodebq* pnode=create_nodebq();
	f=fopen(pathnode,"rb+");
	fwrite(pnode,sizeof(nodebq),(size_t)1,f);
	fclose(f);
	//free(paehnode);
	free(pnode);
}

int quit(struct GameInfo *pgameinfo,nodebq *pnode1,WORKFILE work)//返回1表示项目管理，2表示登录，3关闭程序
{
	//exit(1);
	/*int c;
	int page;
	clrmous(MouseX,MouseY);
	quit_prt();
	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if(judge_press_mainbutton(5,&page))
		{
			return page;
		}
		else if(mouse_press(250,110,900,210)==1)
		{
			SaveBMP(330,293,697,478,12);
			c=quit_savejudge(pgameinfo,pnode1,work);
			switch(c)
			{
				case 1:
					save_gminfo(pgameinfo,work,5);
					save_node(work,pnode1);
					LoadBMP(330,293,697,478,12);
					return 11;
				case 2:
					LoadBMP(330,293,697,478,12);
					return 11;
				case 3:
					LoadBMP(330,293,697,478,12);
					break;
			}
		}
		else if(mouse_press(250,220,900,320)==1)
		{
			SaveBMP(330,293,697,478,12);
			c=quit_savejudge(pgameinfo,pnode1,work);
			switch(c)
			{
				case 1:
					save_gminfo(pgameinfo,work,5);
					save_node(work,pnode1);
					LoadBMP(330,293,697,478,12);
					return 12;
				case 2:
					LoadBMP(330,293,697,478,12);
					return 12;
				case 3:
					LoadBMP(330,293,697,478,12);
					break;
			}
		}
		else if(mouse_press(250,330,900,430)==1)
		{
			SaveBMP(330,293,697,478,12);
			c=quit_savejudge(pgameinfo,pnode1,work);
			switch(c)
			{
				case 1:
					save_gminfo(pgameinfo,work,5);
					save_node(work,pnode1);
					LoadBMP(330,293,697,478,12);
					return 13;
				case 2:
					LoadBMP(330,293,697,478,12);
					return 13;
				case 3:
					LoadBMP(330,293,697,478,12);
					break;
			}
		}
	}*/
	
}

void quit_prt()
{
	btn_bar_Draw(250,110,900,210);	
	btn_bar_Draw(250,220,900,320);
	btn_bar_Draw(250,330,900,430);

	puthz2(270,140,32,40,0,"退出至项目管理");
	puthz2(270,250,32,40,0,"退出至登陆");
	puthz2(270,360,32,40,0,"退出程序");
}

int quit_savejudge()
{
	clrmous(MouseX,MouseY);
	menuprt(330,293,697,478);
    put_hz24(340,298,"是否保存上次保存以来的进度",65535,"HZK\\HZK24",0);
    btn_bar_Draw(340,400,430,468);
    btn_bar_Draw(440,400,530,468);
	btn_bar_Draw(540,400,630,468);
    put_hz24(370,427,"是",65535,"HZK\\HZK24",0);
    put_hz24(470,427,"否",65535,"HZK\\HZK24",0);
	put_hz24(555,427,"取消",65535,"HZK\\HZK24",0);
	delay(300);
	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
    	if(mouse_press(340,400,430,468)==1)
    	{
			press=0;
			cleankey();
			delay(300);
			return 1;
    	}
    	if(mouse_press(440,400,530,468)==1)
    	{
        	press=0;
			cleankey();
			delay(300);
			return 2;
    	}
		if(mouse_press(540,400,630,468)==1)
    	{
        	press=0;
			cleankey();
			delay(300);
			return 3;
    	}
	}
}

void close_all()
{
	exit(1);
}

void free_nodebq_all(nodebq*q)
{
	nodebq*t;
	t=q;
	while(1)
	{
		if(q!=NULL)
		{
			t=q->next;
			free(q);
			q=t;
		}
	}
	free(t);
	t=NULL;
}
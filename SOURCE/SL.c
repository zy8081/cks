#include<ALLFUNS.h>

int save_gminfo(struct GameInfo* pgameinfo,WORKFILE* pwork,int repage)
{
	
	FILE *file=fopen(pwork->path_dat,"wb");
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
	struct GameInfo* gameinfo=malloc(sizeof(struct GameInfo));
	//struct Resource res_earns;
    FILE* ft=fopen(datpath,"wb+");
	
	gameinfo->r_info.energy=5000;
	gameinfo->r_info.nanomaterial=2000;
	gameinfo->r_info.rarematerial=500;
	gameinfo->r_info.oxygen=2500;
	gameinfo->r_info.water=2500;
	gameinfo->r_info.food=2500;
	gameinfo->r_info.fuel=500;
	gameinfo->r_info.mineral=0;
	
	gameinfo->year=2030;
	gameinfo->month=1;
	gameinfo->techpoint=100;
	gameinfo->gametech[0].research_flag=0;
	gameinfo->gametech[1].research_flag=0;
	gameinfo->gametech[2].research_flag=0;
	gameinfo->r_info_t=gameinfo->r_info;

	gameinfo->people=30;
	gameinfo->happiness[0]=0;
	gameinfo->happiness[1]=0;
	gameinfo->construction=0;

	gameinfo->fail=0;

	//初始化地图
	for (i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
		{
			gameinfo->m_info[i][j].building.id=0;
			gameinfo->m_info[i][j].building.bui_time=0;
			gameinfo->m_info[i][j].terrain=0;
			gameinfo->m_info[i][j].building.lock=0;
		}
	}
	map_init(t,gameinfo);
	rocket_init(&(gameinfo->rocket));
	//rewind(ft);
    fwrite(gameinfo,sizeof(struct GameInfo),(size_t)1,ft);
    fclose(ft);
	free(gameinfo);

}

// void save_node(WORKFILE* work,nodebq* pnode1)
// {
// 	char pathnode[50];
// 	FILE* fnode;
// 	nodebq* pnode=pnode1;
// 	strcpy(pathnode,work->path);
// 	strcat(pathnode,"\\usernode.nod");
// 	fnode=fopen(pathnode,"wb");
// 	while(pnode!=NULL)
// 	{
// 		fwrite(pnode,sizeof(nodebq),(size_t)1,fnode);
// 		pnode=pnode->next;
// 	}
// 	fclose(fnode);
// 	return;
// }


void save_node(WORKFILE* work, nodebq* head) 
{
    char pathnode[50];
	FILE* fnode;
    // 计算节点数量
    int count = 0;
    nodebq* current = head;
    while (current!=NULL) 
	{
        count++;
        current = current->next;
    }
	strcpy(pathnode,work->path);
	strcat(pathnode,"\\usernode.nod");

    fnode = fopen(pathnode, "wb");
    if (fnode==NULL) 
	{
        return;
    }

    // 写入节点数量
    fwrite(&count, sizeof(int), 1, fnode);

    // 写入数据 (仅i和j)
    current = head;
    while (current!=NULL) 
	{
        fwrite(&current->i, sizeof(int), 1, fnode);
        fwrite(&current->j, sizeof(int), 1, fnode);
        current = current->next;
    }

    fclose(fnode);
}

nodebq* load_node(WORKFILE work) {
    // 1. 安全拼接路径
    char pathnode[50];
	FILE* fnode;
	int count;
	int i;
	nodebq* head = NULL;
    nodebq** current_ptr = &head; // 二级指针简化链表链接
    //snprintf(pathnode, sizeof(pathnode), "%s/usernode.nod", work->path);
	strcpy(pathnode,work.path);
	strcat(pathnode,"\\usernode.nod");
    // 2. 打开文件
    fnode = fopen(pathnode, "rb");
    if (fnode==NULL) 
	{
        // perror("Error loading file");
        // return NULL;
		exit(0);
    }

    // 3. 读取节点数量
    
    if (fread(&count, sizeof(int), 1, fnode) != 1) 
	{
        // fclose(fnode);
        // return NULL;
		exit(0);
    }

    // 4. 重建链表
    

    for (i = 0; i < count; i++)
	{
        // 创建新节点
        nodebq* new_node = (nodebq*)malloc(sizeof(nodebq));
        if (new_node==NULL) 
		{
            // perror("Memory allocation failed");
            // break; // 需清理已分配节点（略）
			exit(0);
        }
        new_node->next = NULL;

        // 读取数据
        if (fread(&new_node->i, sizeof(int), 1, fnode) != 1 ||fread(&new_node->j, sizeof(int), 1, fnode) != 1) 
		{
            free(new_node);
            break; // 文件损坏或读取错误
        }

        // 链接到链表
        *current_ptr = new_node;
        current_ptr = &(new_node->next);
    }

    fclose(fnode);
    return head;
}

// nodebq* load_node(WORKFILE work)
// {
// 	char*pathnode=malloc((size_t)50);
// 	FILE* fnode;
// 	nodebq* pnode=create_nodebq();
// 	nodebq* pnodetemp=pnode;
// 	strcpy(pathnode,work.path);
// 	strcat(pathnode,"\\usernode.nod");
// 	fnode=fopen(pathnode,"rb+");
// 	while(1)
// 	{
// 		fread(pnode,sizeof(nodebq),(size_t)1,fnode);
// 		if(pnode->next==NULL)break;
// 		else
// 		{
// 			pnode->next=create_nodebq();
// 			pnode=pnode->next;
// 		}

// 	}
// 	fclose(fnode);
// 	free(pathnode);
// 	return pnodetemp;
// }

// void node_init(char*pathnode)
// {
// 	FILE* f;
// 	nodebq* pnode=create_nodebq();
// 	f=fopen(pathnode,"rb+");
// 	fwrite(pnode,sizeof(nodebq),(size_t)1,f);
// 	fclose(f);
// 	//free(paehnode);
// 	free(pnode);
// }

void node_init(char* pathnode) 
{
    FILE* f;
	int count=1;
    nodebq* pnode = create_nodebq();
    f = fopen(pathnode, "wb");
	fwrite(&count,sizeof(int), (size_t)1, f);
    fwrite(&(pnode->i), sizeof(int), (size_t)1, f);
    fwrite(&(pnode->j), sizeof(int), (size_t)1, f);

    fclose(f);
    free(pnode);
}

int quit(void)//返回11x表示项目管理，12x表示登录，13x关闭程序
{
	int c;
	int page;
	clrmous(MouseX,MouseY);
	quit_prt();
	while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if(judge_press_mainbutton(5,&page))
		{
			clrmous(MouseX,MouseY);
			return page;
		}
		else if(mouse_press(250,110,900,210)==1)
		{
			clrmous(MouseX,MouseY);
			SaveBMP(330,293,697,478,12);
			c=quit_savejudge();
			switch(c)
			{
				case 1:
					clrmous(MouseX,MouseY);
					LoadBMP(330,293,697,478,12);
					return 111;
				case 2:
					clrmous(MouseX,MouseY);
					LoadBMP(330,293,697,478,12);
					return 112;
				case 3:
					clrmous(MouseX,MouseY);
					LoadBMP(330,293,697,478,12);
					break;
			}
		}
		else if(mouse_press(250,220,900,320)==1)
		{
			clrmous(MouseX,MouseY);
			SaveBMP(330,293,697,478,12);
			c=quit_savejudge();
			switch(c)
			{
				case 1:
					clrmous(MouseX,MouseY);
					LoadBMP(330,293,697,478,12);
					return 121;
				case 2:
					clrmous(MouseX,MouseY);
					LoadBMP(330,293,697,478,12);
					return 122;
				case 3:
					clrmous(MouseX,MouseY);
					LoadBMP(330,293,697,478,12);
					break;
			}
		}
		else if(mouse_press(250,330,900,430)==1)
		{
			clrmous(MouseX,MouseY);
			SaveBMP(330,293,697,478,12);
			c=quit_savejudge();
			switch(c)
			{
				case 1:
					clrmous(MouseX,MouseY);
					LoadBMP(330,293,697,478,12);
					return 131;
				case 2:
					clrmous(MouseX,MouseY);
					LoadBMP(330,293,697,478,12);
					return 132;
				case 3:
					clrmous(MouseX,MouseY);
					LoadBMP(330,293,697,478,12);
					break;
			}
		}
	}
	
}

void quit_prt(void)
{
	clrmous(MouseX,MouseY);
	btn_bar_Draw(250,110,900,210);	
	btn_bar_Draw(250,220,900,320);
	btn_bar_Draw(250,330,900,430);

	puthz2(270,140,32,40,0,"退出至项目管理");
	puthz2(270,250,32,40,0,"退出至登陆");
	puthz2(270,360,32,40,0,"退出程序");
}

int quit_savejudge(void)
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

void close_all(void)
{
	exit(1);
}

// void free_nodebq_all(nodebq*q)
// {
// 	nodebq*t;
// 	t=q;
// 	while(1)
// 	{
// 		if(q!=NULL)
// 		{
// 			t=q->next;
// 			free(q);
// 			q=t;
// 		}
// 	}
// 	free(t);
// 	t=NULL;
// }
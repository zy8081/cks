#include <common.h>
#include <game.h>
#include <fun3_2.h>
#include<ORDFUNS.h>
#include<WRKMNG.h>
#include<WRKPLC.h>
#include<DRAWWORK.h>
#include<WRKADD.h>
#include<SL.h>

int save_gminfo(struct GameInfo *gameinfop,WORKFILE work,int repage)
{
	FILE *file=fopen(work.path_dat,"wb");
	//strcpy(pathdat,work.path_dat);
	fwrite(gameinfop,sizeof(struct GameInfo),(size_t)1,file);
	fclose(file);
	return repage;
}

void load_gminfo(WORKFILE work,struct GameInfo* gameinfop)
{
	FILE *file=fopen(work.path_dat,"rb+");
	fread(gameinfop,sizeof(struct GameInfo),(size_t)1,file);
	fclose(file);
	return;

}

void gminfo_init(char* datpath)
{
    int i,j;
	nodebq *p1;
	struct GameInfo gameinfo;
	struct Resource res_earns;
    FILE* ft=fopen(datpath,"wb+");

	gameinfo.r_info.energy=10000;
	gameinfo.r_info.nanomaterial=10000;
	gameinfo.r_info.rarematerial=10000;
	gameinfo.r_info.oxygen=10000;
	gameinfo.r_info.water=10000;
	gameinfo.r_info.food=10000;
	gameinfo.r_info.fuel=10000;
	gameinfo.r_info.mineral=10000;
	
	gameinfo.year=2030;
	gameinfo.month=1;
	gameinfo.techpoint=200;
	gameinfo.gametech[0].research_flag=0;
	
	//≥ı ºªØµÿÕº
	for (i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
		{
			gameinfo.m_info[i][j].building.id=0;
			gameinfo.m_info[i][j].building.bui_time=0;
			gameinfo.m_info[i][j].terrain=0;
		}
	}

	//rocket_init(&(gameinfo.rocket));

    fwrite(&gameinfo,sizeof(struct GameInfo),(size_t)1,ft);
    fclose(ft);

}

void save_node(WORKFILE work,nodebq node1)
{
	char*pathnode=malloc((size_t)50);
	FILE* fnode;
	nodebq* pnode=&node1;
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
#ifndef __GAME_H
#define __GAME_H
#include<ALLFUNS.h>
struct Resource
{
	int nanomaterial;
	int rarematerial;
	int oxygen;
	int water;
	int food;
	int energy;
	int fuel;
	int mineral;
};

//建造用材主要为nano,rarematerial
//维护费主要为oxygen,water,food,energy,fuel
struct ResAllInfo
{
	long int nanomaterial;
	long int rarematerial;
	long int oxygen;
	long int water;
	long int food;
	long int energy;
	long int fuel;
	long int mineral;
};

struct Building
{
	char id;
	char name[21];
	char pic_path[4];
	struct Resource res_cost;
	struct Resource res_add;
	int bui_time;
};

struct MapInfo
{
	char terrain;
	struct Building building;
};

struct GameInfo
{
	struct MapInfo m_info[15][15];
	struct ResAllInfo r_info;
	int year;
	int month;
};

typedef struct NodeBuilding
{
	struct NodeBuilding *next;
	char name[21];
	int number;
	unsigned int color;
}nodeb;

typedef struct NodeBuildQueue
{
	struct NodeBuildQueue *next;
	int i;
	int j;
}nodebq;


void project(struct workfile w,int*page);
int proj_fun1(struct GameInfo* gameinfop,int*pxsel,int*pysel);
int proj_fun2(struct GameInfo *gameinfo);
void proj_fun2_1(struct GameInfo *gameinfop);
void get_all_resourceinfo(struct GameInfo *gameinfop);
void calculate_monthly_income(struct GameInfo *gameinfop,int *data);
int proj_fun3(struct GameInfo *gameinfop,nodebq *p,int*pxsel,int*pysel);
int build_queue(struct GameInfo *gameinfop,nodebq *p);
void draw_buildqueue(int page,struct GameInfo *gameinfop,nodebq *p,int func);
int proj_fun4(struct GameInfo* gameinfop);

int proj_origin(struct GameInfo* gameinfop,int *pxsel,int *pysel);
void draw_map(int x1,int y1,int x2,int y2,int width,int height,struct GameInfo *gameinfop);
void draw_map2(int x1,int y1,int x2,int y2,int width,int height,struct GameInfo *gameinfop);
void draw_binfo(void);

int build(struct GameInfo *gameinfop,nodebq *p,int* pxsel,int* pysel);
int buildlist(int x,struct GameInfo *gameinfop,nodebq *p,int* pxsel,int* pysel);
int dlist_building(char id,int location,nodeb *p,nodeb *p2,nodeb *p3,struct GameInfo *gameinfop,struct Building *building);
int get_building_info(char id,struct Building* building);


nodeb *create_nodeb(void);
void headinsert1_cost_nodeb(nodeb *p,struct Building building,struct GameInfo *gameinfop);
void headinsert1_add_nodeb(nodeb *p,struct Building building,struct GameInfo *gameinfop);
void headinsert1_maintfee_nodeb(nodeb *p,struct Building building,struct GameInfo *gameinfop);
void free_nodeb(nodeb *p);

nodebq* create_nodebq(void);
void lastinsert_nodebq(nodebq *p,int i,int j);
int calculate_nodebq_len(nodebq *p);
void headremove_nodebq(nodebq *p);
void exchange_nodebq(nodebq *p,int x1,int x2);
void free_nodebq(nodebq *p);
//void judge_press_mainbutton(int flag);

#endif
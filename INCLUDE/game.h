#ifndef __GAME_H
#define __GAME_H

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

//寤洪�犵敤鏉愪富瑕佷负nano,rarematerial
//缁存姢璐逛富瑕佷负oxygen,water,food,energy,fuel
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
	int id;
	char name[21];
	char pic_path[4];
	struct Resource res_cost;
	struct Resource res_add;
	int bui_time;
	int lock;
};

struct MapInfo
{
	int terrain;
	struct Building building;
	int mineral;
	int exp;//0为未勘探，1为已勘探
};

struct technologydata
{
	int research_flag;
	int type;
	int id;
	int havepoints;
	int totalpoints;
};


typedef struct RocketInfo
{
    int apply;//-1为未申请，1为不返程，2为返程
    struct Resource resadd;
    struct Resource resdec;
    int peopleadd;
    int peopledec;
    int year;
    int month;
    int refuelpay;
    int refuel;
    int load;
    int loadmax;
}RKTINFO;

struct GameInfo
{
	RKTINFO rocket;
	struct MapInfo m_info[15][15];
	struct ResAllInfo r_info;
	struct ResAllInfo r_info_t;
	struct technologydata gametech[3];
	int techpoint;
	int year;
	int month;
	int people;
	int happiness[2];//0为具体值，1为百分比
	long int construction;
	int fail;
};

int project(struct workfile w);


void get_all_resourceinfo(struct GameInfo *gameinfop);
void calculate_monthly_income(struct GameInfo *gameinfop,int *data);
void calculate_monthly_outcome(struct GameInfo *gameinfop,int *data);
int proj_origin(struct GameInfo* gameinfop);



int judge_press_mainbutton(int flag,int *page);
void left_button_clear_activate(int n,char *s[]);

#endif
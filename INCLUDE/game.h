#ifndef __GAME_H
#define __GAME_H
#define HUGE_ENG_NUM 10
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
};

struct technologydata
{
	int research_flag;
	int type;
	int id;
	int havepoints;
	int totalpoints;
};

struct hugeengineer
{
	int lock;
	int time;
};

struct GameInfo
{
	struct MapInfo m_info[15][15];
	struct ResAllInfo r_info;
	struct technologydata gametech[3];
	int techpoint;
	int year;
	int month;
    struct hugeengineer huge_engineering[HUGE_ENG_NUM];
};

int project(struct workfile w,int*page);


void get_all_resourceinfo(struct GameInfo *gameinfop);
void calculate_monthly_income(struct GameInfo *gameinfop,int *data);

int proj_origin(struct GameInfo* gameinfop);



int judge_press_mainbutton(int flag,int *page);


#endif
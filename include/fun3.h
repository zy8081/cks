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

int proj_fun3(struct GameInfo *gameinfop,nodebq *p);
int build_queue(struct GameInfo *gameinfop,nodebq *p);
void draw_buildqueue(int page,struct GameInfo *gameinfop,nodebq *p,int func);
void draw_map(int x1,int y1,int x2,int y2,int width,int height,struct GameInfo *gameinfop);
void draw_map2(int x1,int y1,int x2,int y2,int width,int height,struct GameInfo *gameinfop);
void draw_binfo(void);

int build(struct GameInfo *gameinfop,nodebq *p);
int buildlist(int x,struct GameInfo *gameinfop,nodebq *p);
int dlist_building(int id,int location,nodeb *p,nodeb *p2,nodeb *p3,struct GameInfo *gameinfop,struct Building *building);
int get_building_info(int id,struct Building* building);


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
void delete_nodebq(nodebq *p,int x);
void getdata_nodebq(nodebq *p,int x,int *i,int *j);
void free_nodebq(nodebq *p);

void clear_map_building_data(struct GameInfo *gameinfop,int i,int j);
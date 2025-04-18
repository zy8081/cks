typedef struct NodeBuilding
{
	struct NodeBuilding *next;
	char name[21];
	int number;
	unsigned int color;
}nodeb;



int proj_fun3(struct GameInfo *gameinfop,nodebq *p,int* pxsel,int* pysel);

void draw_map(int x1,int y1,int x2,int y2,int width,int height,struct GameInfo *gameinfop);
void draw_map2(int x1,int y1,int x2,int y2,int width,int height,struct GameInfo *gameinfop);
void draw_map_building(int i,int j,int n);
int mouse_press_map(int i,int j);

int build(struct GameInfo *gameinfop,nodebq *p,int* pxsel,int* pysel);
int buildlist(int x,struct GameInfo *gameinfop,nodebq *p,int* pxsel,int* pysel);
int dlist_building(int id,int location,nodeb *p,nodeb *p2,nodeb *p3,struct GameInfo *gameinfop,struct Building *building);
int get_building_info(int id,struct Building* building);


nodeb *create_nodeb(void);
void headinsert1_cost_nodeb(nodeb *p,struct Building building,struct GameInfo *gameinfop);
void headinsert1_add_nodeb(nodeb *p,struct Building building,struct GameInfo *gameinfop);
void headinsert1_maintfee_nodeb(nodeb *p,struct Building building,struct GameInfo *gameinfop);
void free_nodeb(nodeb *p);
void free_nodeb_list(nodeb *p[3][5]);
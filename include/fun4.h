#define CHILD_NUM 3
typedef struct NodeTech
{
	struct NodeTech *next;
	int id;
	int type;
	int point;
}nodet;

typedef struct TreeTechnology
{
	int id;
	int type;
	int flag;
	int point;
	struct TreeTechnology *child[CHILD_NUM];
	struct TreeTechnology *parent;
	char name[20];
	int floor;
	int x;
	int y;
}tree;

int proj_fun4(struct GameInfo* gameinfop);


int research_tech(struct GameInfo *gameinfop);
tree *create_lifetech_tree(void);
void id_find_xy_lifetech(tree *p,int id,int (*arr)[2]);
void id_find_baseinfo_lifetech(tree *p,tree *temp,int id);
void draw_lifetech_tree(tree *p);
void draw_lifetech_toast(tree *p,int id);
void load_lifetech_toast(void);
void draw_lifetech_line(tree *leaf);

void start_research(struct GameInfo *gameinfop,int type,int id);
int get_totalpoint_from_techtxt(int type,int id);

void traverse_tree_to_nodetlist(tree *p,nodet *pt,int floor);
void printf_nodet_list(nodet *p,int floor);
void cal_nodet_list_pos(int num,int *initpos,int *apart);

void draw_leaves(tree *p,int floor);

int research(struct GameInfo* gameinfop);
int have_researched(struct GameInfo* gameinfop);
void draw_have_researched(int page,nodet *pp1);

void draw_techlist0(nodet *pp2);
void draw_techlist1(struct GameInfo *gameinfop);
void get_tech_basic_info(tree *p,int type,int id);
void get_tech_name2(struct GameInfo *gameinfop,char* name);
void get_tech_effect(int type, int id,char *effect);
void change_techflag(int type,int id);
int get_tech_txt(int type,int id,char **txt);
int display_tech_txt(int type,int id);

void start_research_tech(nodet *pp2,int i,struct GameInfo *gameinfop);


tree *create_tree(int type);
void insert_simple_leaf(tree *p,int type,int id,int func);
void get_techflag(tree *p);

tree *create_tree_pp(int id);

void free_tree(tree *p);


nodet *create_nodet(void);
void headinsert_nodet(nodet *p,int type,int id,int point);
void getinfo_nodet(nodet *p,int x,int *type,int *id,int *point);
nodet *extract_nodet(nodet *p1,int num);
int calculate_nodet_len(nodet *p);
void free_nodet(nodet *p);
void get_tech_file(nodet *p,char *str);
void printf_nodet(nodet *p);
void delete_nodet(nodet *p,int pos);


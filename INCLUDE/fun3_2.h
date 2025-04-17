typedef struct NodeBuildQueue
{
	struct NodeBuildQueue *next;
	int i;
	int j;
}nodebq;
int build_queue(struct GameInfo *gameinfop,nodebq *p);
void draw_buildqueue(int page,struct GameInfo *gameinfop,nodebq *p,int func);
nodebq* create_nodebq(void);
void lastinsert_nodebq(nodebq *p,int i,int j);
int calculate_nodebq_len(nodebq *p);
void headremove_nodebq(nodebq *p);
void exchange_nodebq(nodebq *p,int x1,int x2);
void delete_nodebq(nodebq *p,int x);
void getdata_nodebq(nodebq *p,int x,int *i,int *j);
void free_nodebq(nodebq *p);
void clear_map_building_data(struct GameInfo *gameinfop,int i,int j);
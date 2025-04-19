typedef struct Nodesave
{
	struct Nodesave *next;
	int i;
	int j;
}nodes;

int proj_fun5(struct GameInfo* gameinfop,nodebq *p,WORKFILE work,int(*events)[2]);
int proj_fun5_1(struct GameInfo *gameinfop,nodebq *p,int (*events)[2]);
void draw_fun5_1(void);

int save(struct GameInfo *GameInfop,char*pathdat);

nodes *create_nodes(void);
void headinsert_nodes(nodes *p,int i,int j);
void fputdata_nodes(nodes *p,struct GameInfo *GameInfop,FILE *file);
void free_nodes(nodes *p);
void time_flow(struct GameInfo *gameinfop,nodebq *p,int (*event)[2]);

#ifndef FUN5_H 
#define FUN5_H 
typedef struct Nodesave
{
	struct Nodesave *next;
	int i;
	int j;
}nodes;

int proj_fun5(struct GameInfo* gameinfop,nodebq *p,WORKFILE* pwork,int(*events)[2]);
void draw_timeflow_remind(struct GameInfo* gameinfop,nodebq *p,char *path);
int save(struct GameInfo *GameInfop,char*pathdat);
void draw_quit_confirm(void);
nodes *create_nodes(void);
void headinsert_nodes(nodes *p,int i,int j);
void fputdata_nodes(nodes *p,struct GameInfo *GameInfop,FILE *file);
void free_nodes(nodes *p);
#endif
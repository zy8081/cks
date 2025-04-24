#ifndef TIMEFLOW_H
#define TIMEFLOW_H
void time_flow(struct GameInfo *gameinfop,nodebq *p,WORKFILE *workfilep);
void timeflow_more(struct GameInfo *gameinfop,nodebq *p,int n,WORKFILE *workfilep);
//void backprtt();
int time_warning(void);//0·ñ1ÊÇ2ÍË³ö
//void time_save(struct GameInfo *pg,nodebq* p,WORKFILE* pwork);
int time_comf(int t);
void timeflow_prt(void);
int timeflow(struct GameInfo*pg, nodebq* p,int (*event)[2],WORKFILE* pw);
void event_prt(struct GameInfo *pg,int (*allevent)[2],int page,int n,int tyear,int tmonth);
void test();
int time_set(void);
int time_input(int x1,int y1,int x2,int y2,int max,int n);
#endif




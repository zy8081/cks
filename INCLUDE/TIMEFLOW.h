#ifndef __TIMEFLOW_H
#define __TIMEFLOW_H
void time_flow(struct GameInfo *gameinfop,nodebq *p,WORKFILE *workfilep);
void timeflow_more(struct GameInfo *gameinfop,nodebq *p,int n);
//void backprtt();
int time_warning();//0·ñ1ÊÇ2ÍË³ö
//void time_save(struct GameInfo *pg,nodebq* p,WORKFILE* pwork);
int time_comf(int t);
void timeflow_prt();
int timeflow(struct GameInfo*pg, nodebq* p,int (*event)[2],WORKFILE* pw);
void event_prt(struct GameInfo *pg,int (*allevent)[2],int page,int n,int tyear,int tmonth);
void test();
#endif




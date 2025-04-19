#ifndef __SL_H
#define __SL_H
//#include<ALLFUNS.h>

int save_gminfo(struct GameInfo* pgameinfo,WORKFILE work,int repage);
void load_gminfo(WORKFILE work,struct GameInfo* gf);
void gminfo_init(char* pathdat,int t);
void save_node(WORKFILE work,nodebq* pnode1);
nodebq* load_node(WORKFILE work);
void node_init(char*pathnode);
void quit_prt();
int quit(struct GameInfo* pgameinfo,nodebq* pnode1,WORKFILE work);
void quit_prt();
int quit_savejudge();
void close_all();
void free_nodebq_all(nodebq*p);


#endif
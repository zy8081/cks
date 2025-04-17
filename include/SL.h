#ifndef __SL_H
#define __SL_H
//#include<ALLFUNS.h>

int save_gminfo(struct GameInfo *gameinfop,WORKFILE work,int repage);
void load_gminfo(WORKFILE work,struct GameInfo* gf);
void gminfo_init(char* pathdat,int t);
void save_node(WORKFILE work,nodebq node1);
nodebq* load_node(WORKFILE work);
void node_init(char*pathnode);


#endif
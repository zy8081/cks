#ifndef __MAP_H
#define __MAP_H
void draw_block(int x,int y,struct MapInfo* mi,int form);
void draw_mainmap(struct GameInfo *gf,int xsel,int ysel);
void draw_buildmap(struct GameInfo *gf,int xsel,int ysel);
int renew_map(int* xsel,int*ysel);
void cleankey();
void map_init(int place,struct GameInfo *pg);
void expblock(struct GameInfo* pg, int* pxsel,int *pysel,int i,int j);
void map_exp(struct GameInfo* pg, int* pxsel,int *pysel);
void draw_expminimap(struct GameInfo *gf,int xsel,int ysel);
void draw_expmap(struct GameInfo *gf,int xsel,int ysel);
void draw_expblock(struct GameInfo* gf,int xsel,int ysel,int i,int j);

//void mine_exp()

#endif
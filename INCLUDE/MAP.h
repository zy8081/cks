#ifndef MAP_H
#define MAP_H
void draw_block(int x,int y,struct MapInfo* mi,int form);
void draw_mainmap(struct GameInfo *gf,int xsel,int ysel);
void draw_buildmap(struct GameInfo *gf,int xsel,int ysel);
void draw_minimap(struct GameInfo *gf,int xsel,int ysel);
int renew_map(int* xsel,int*ysel);
void cleankey(void);
void map_init(int place,struct GameInfo *pg);
void expblock(struct GameInfo* pg, int* pxsel,int *pysel,int i,int j);
int map_exp(struct GameInfo* pg, int* pxsel,int *pysel);
void draw_expminimap(struct GameInfo *gf,int xsel,int ysel);
void draw_expmap(struct GameInfo *gf,int xsel,int ysel);
void draw_expblock(struct GameInfo* gf,int xsel,int ysel,int i,int j);
void draw_sign(void);
int mine_block_init(int place,int terrain);
void draw_otherblock(int x,int y);
//void mine_exp()

#endif
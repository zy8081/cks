#ifndef __MAP_H
#define __MAP_H
void draw_block(int x,int y,struct MapInfo mi,int form);
void draw_mainmap(struct GameInfo gf,int xsel,int ysel);
void draw_buildmap(struct GameInfo gf,int xsel,int ysel);
int renew_map(int* xsel,int*ysel);
void draw_minimap(struct GameInfo gf,int xsel,int ysel);
#endif
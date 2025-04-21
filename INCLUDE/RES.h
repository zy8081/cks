#ifndef __RES_H
#define __RES_H
int people_max(struct GameInfo *pg,char *path);
void people_cost(int *data,struct GameInfo *pg);
int happiness_count(struct GameInfo *pg);
int happiness_rate_count(struct GameInfo *pg);
int constrc_count(struct GameInfo *pg,char *path);

#endif
#ifndef RES_H
#define RES_H
int people_max(struct GameInfo *pg,char *path);
void people_cost(int *data,struct GameInfo *pg);
int happiness_count(struct GameInfo *pg,char *path);
int happiness_rate_count(struct GameInfo *pg);
long int constrc_count(struct GameInfo *pg,char *path);

#endif
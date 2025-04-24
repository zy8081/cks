//´ò¸ö×Ö
int proj_fun2(struct GameInfo* gameinfop,int *pxsel,int *pysel,WORKFILE *workfilep);
void proj_fun2_1(struct GameInfo *gameinfop,char *path);
void draw_buildpoint_txt(long int construction);
void get_all_resourceinfo(struct GameInfo *gameinfop,char *path);
void resource_warning(struct GameInfo *gameinfop,char *path);
void home_build_situation(struct GameInfo *gameinfop,char *path);
int cal_map_building_num(struct GameInfo *gameinfop);
void draw_peoplenum_txt(struct GameInfo *gameinfop);
int cal_happiness_resbuff(int happy);
int cal_buildpoint_resbuff(struct GameInfo *gameinfop,char *path);
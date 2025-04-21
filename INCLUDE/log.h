void logfile_copy(char *path);
void generate_building_log(struct GameInfo *gameinfop,nodebq *p,int funcflag,char *path);
void generate_tech_log(struct GameInfo *gameinfop,int funcflag,char *path);
int calculate_fileline(char *totalpath);
int log_display(char *path);
void draw_log_one_page(int newpage,char *path);
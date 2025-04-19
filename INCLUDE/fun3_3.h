int demolish_building(struct GameInfo *gameinfop,int *pxsel,int *pysel);
void draw_demolish_confirm(struct GameInfo *gameinfop,int i,int j);
void load_demolish_confirm(void);
int judge_press_demolish_confirm(int pos);
void demolish_on_map(struct GameInfo *gameinfop,int i,int j,int pxsel,int pysel);

int ban_building(struct GameInfo *gameinfop,int *pxsel,int *pysel);
void draw_ban_confirm(struct GameInfo *gameinfop,int i,int j,int pxsel,int pysel,int lock);
void ban_unban_on_map(struct GameInfo *gameinfop,int i,int j,int pxsel,int pysel,int lock);
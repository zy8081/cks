
void draw_closebutton(void);
void draw_page0(void);
void draw_button_fill(int x1,int y1,int x2,int y2,unsigned int color);
void draw_button_frame(int x1,int y1,int x2,int y2,unsigned int color);
void draw_toast(void);
void clear_toast(void);

void draw_left_toolbotton(int y,int length,char*s);
void draw_main_toolbotton(int x,int color,char*s1,char*s2);
void puthz2(int x,int y,int flag,int part,int color,char*s1);
void draw_button1(int x1,int y1,int x2,int y2,int colorf,int colorb);

void draw_pro_origin(void);
int main_toolbotton_mouse_press(int x);
int left_toolbotton_mouse_press(int x);
int build_press(int x);
void draw_left_toolbotton_activate(int y,int length,char*s);
void draw_main_toolbotton_activate(int x,int color,char*s1,char*s2);
void draw_all_leftbuttons(int num,int len,char *s[]);
void clear_main_all(void);
void clear_main_all2(int x);
void clear_right_all(void);

void clear_time(void);
void draw_time(struct GameInfo *gameinfop);

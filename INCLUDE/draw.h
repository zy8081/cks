#ifndef DRAW_H
#define DRAW_H
void draw_closebutton(void);

void draw_button_fill(int x1,int y1,int x2,int y2,unsigned int color);
void draw_button_frame(int x1,int y1,int x2,int y2,unsigned int color);
void draw_toast(void);
void clear_toast(void);
void draw_button1(int x1,int y1,int x2,int y2,int colorf,int colorb);

//主界面按钮画图
void draw_left_toolbotton(int y,int length,char*s);
void draw_main_toolbotton(int x,int color,char*s1,char*s2);
void draw_left_toolbotton_activate2(int y,int length,char*s,int n);
void draw_left_toolbotton_activate(int y,int length,char*s);
void draw_main_toolbotton_activate(int x,int color,char*s1,char*s2);
void draw_all_leftbuttons(int num,int len,char *s[]);
int main_toolbotton_mouse_press(int x);
int left_toolbotton_mouse_press(int x);

void clear_main_all(void);
void clear_main_all2(int x);
void clear_right_all(void);

void draw_pro_origin(void);

void clear_time(void);
void draw_time(struct GameInfo *gameinfop);

void puthz2(int x,int y,int flag,int part,int color,char*s1);
void puthz3(int x,int y,int flag,int part,int color,char*s1);
#endif
extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int press;  

void mouseinit(void);
void MouseSpeed(int x, int y);
void mread(int *mx,int *my,int*mbuttons);
void mouse_renew(int *mx,int *my,int*mbuttons);
void save_bk_mou(int mx,int my);
void clrmous(int mx,int my);
void drawmous(int mx,int my);
int mouse_press(int x1, int y1, int x2, int y2);
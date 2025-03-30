#ifndef ORDFUNS_H
#define ORDFUNS_H

typedef struct btnbar//方形按钮定义
{
    char* inf;  //按钮显示的文字内容
    int xinf;   //文字输入的坐标
    int yinf;

    int x1;     //左上及右下角位置点的坐标
    int y1;
    int x2;
    int y2; 
}BTN_BAR;

void btn_bar_Draw(BTN_BAR b);
void btn_bar_Draw0(BTN_BAR b);//画按钮，无数字为普通，0为选中，1为无法选中
void hzplace(BTN_BAR *pb,int nx,int ny);//确定文字居中放置位置

void show_gb(int x,int y);
void Getinfo(int x1,int y1,char *name,int num,int a1,int b1,int c1,int d1);

#endif
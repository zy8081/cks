//新建项目部分
#ifndef WRKADD_H
#define WRKADD_H

int wrkmng_add(int* pplacenum,char**pname0);//主体函数

void placeprt(BTN_BAR* pplace,int placenum);//绘制选择地点的按钮

void nameprt(char*);//绘制命名部分，尚有缺陷，再次点击无法从起点开始

void compprt(BTN_BAR* pcompbtn);//绘制完成按钮

void title2prt();//绘制标题

int wrkmng_add_place(int* placetemp);//进入选择地点部分

void sureprt(BTN_BAR*psure,int i);//选择地点的确定按钮

#endif
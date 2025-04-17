//新建项目部分
#ifndef WRKADD_H
#define WRKADD_H

void wrkmng_add(int *fpage1,int* pplacenum,char**pname0,char*user);//主体函数

void placeprt(int placenum);//绘制选择地点的按钮

void nameprt(char*);//绘制命名部分，尚有缺陷，再次点击无法从起点开始

void compprt();//绘制完成按钮

void title2prt();//绘制标题

void wrkmng_add_place(int* page1,int* placetemp);//进入选择地点部分

void sureprt(int i);//选择地点的确定按钮

void gameinit(char* datpath);//初始化dat文件

void datacreate(char*filen);

#endif
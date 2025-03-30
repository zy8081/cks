#ifndef WRKMNG_H
#define WRKMNG_H

#include<ORDFUNS.h>
#include<WRKADD.h>

enum landname{OlymMon=1,MariVal,ArabTer,UtopPla,ElysPla};//定义枚举确定项目地点

typedef struct workfile//定义文件
{
    char name[11];//项目名
    int place;//项目地点
    char path_bas[30];//.bas文件储存路径,用于储存基本信息
    char path_dat[30];//.dat文件储存路径，用于储存部署情况等
}WORKFILE;

int wrkmng_main();//仿照MAIN实现项目管理换页
int wrkmng_menu();//项目管理菜单部分
void title1prt();//画标题
void backprt(BTN_BAR* pbackbtn);//画返回按钮
void menu1prt();//画菜单
void addprt(BTN_BAR* paddbtn);//画新建项目按钮
void openprt(BTN_BAR* popenbtn,int form);//画打开项目按钮
void dltprt(BTN_BAR* pdltbtn,int form);//画删除部项目按钮
void exchprt(BTN_BAR* pexchbtn,int form);//画换序按钮

#endif
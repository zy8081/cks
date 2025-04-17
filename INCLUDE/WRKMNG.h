#ifndef WRKMNG_H
#define WRKMNG_H


enum landname{OlymMon=1,MariVal,ArabTer,UtopPla,ElysPla};

typedef struct workfile
{
    char name[20];
    int place;
    char path_bas[50];
    char path_dat[50];
    int select;
    char path_his[50];
    char path[50];
}WORKFILE;

typedef struct timework
{
    struct GameInfo gameinft;
    int event[2];
}  TIMEWORK;

void wrkmng_main(int *fpage,char*user,WORKFILE* pwork);
void wrkmng_menu(int *fpage1,char*user,WORKFILE* pwork);
void title1prt();
void backprt();
void menu1prt();
void addprt();
void openprt(int form);
void dltprt(int form);
void exchprt(int form);
void lastprt(int form);
void nextprt(int form);
void pageselprt(int workpage,int n);
void pageprt(int page,int pagemax);
void test(void);
void wrkdelete(int page,int n,char*user);
void dltfile(int page,int n,char*user);
void hiscreate(char* pathhis);
void wrkopen_path(int page,int n,char*user,char**pdat);
#endif
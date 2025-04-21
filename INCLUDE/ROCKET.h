#ifndef __ROCKET_H
#define __ROCKET_H
/*
typedef struct RocketInfo
{
    int apply;//-1为未申请，1为不返程，2为返程
    struct Resource resadd;
    struct Resource resdec;
    int peopleadd;
    int peopledec;
    int year;
    int month;
    int refuelpay;
    int refuel;
    int load;
    int loadmax;
}RKTINFO;
*/
void rocket_btnprt();
int rocket_press();
int rocket_time(struct GameInfo gf,int* pyear,int* pmonth);
void rocket_a_prt1();
void rocket_a_prt2();
void rocket_a_prt3();
void rocket_a_prtall();
void backprt1();
void yesbtn(int form);
void nobtn(int form);
void blankprt(int x1,int y1,int x2,int y2);
void rocket_a_fun1(RKTINFO* pr,int (*pcom)[3]);
int rocket_input(int x1,int y1,int x2,int y2,int max,int n);
int rocket_pressno();
int rocket_pressyes();
void rocket_ifreturn_draw(int restyle);
int rocket_ifreturn(RKTINFO*pr);
void rocket_a_prt1_p(int form);
void rocket_init(RKTINFO* rkt);
void rocket_apply(RKTINFO* pr,struct GameInfo* pg, int year,int month);
int rocket_max(RKTINFO pr);
int rocket_check1(RKTINFO r);
int rocket_loadcom(struct Resource re,int people,int max);
void rocket_a_fun2(RKTINFO* pr,int (*pcom)[3]);
void rocket_info(struct GameInfo* pg);
void rocket_info_draw(struct GameInfo* gf);
int rocket_check2(RKTINFO r);

#endif
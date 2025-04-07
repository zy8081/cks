#ifndef __ROCKET_H
#define __ROCKET_H

typedef struct RocketInfo
{
    struct ResAllInfo resadd;
    struct ResAllInfo rescost;
    int peopleadd;
    int peopledede;
    int retime;//0Îª·µ³Ì
    int refuel;
    int refuelpay;
}RKTINFO;

void rocket_btnprt();
int rocket_press();
int rocket_time(struct GameInfo gf,int* pyear,int* pmonth);
void rocket_prt1();
void rocket_prt2();
void rocket_prt3();
void rocket_prtall();
void backprt1();
void yesbtn(int form);
void nobtn(int form);
void blankprt(int x1,int y1,int x2,int y2);
void rocket_fun1();
int rocket_input(int x1,int y1,int x2,int y2,int max);
int rocket_pressno();
int rocket_pressyes();
void rocket_ifreturn_draw();
int rocket_ifreturn();

#endif
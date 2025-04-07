#include<ALLFUNS.h>

void rocket_btnprt()
{
    btn_bar_Draw(10,300,200,330);
    put_hz24(15, 302,"火箭申请",0,"C:\\TEST\\HZK\\HZK24",0);   
}

int rocket_press()
{
    if(mouse_press(10,300,200,330)==1)return 1;
    else return 0;
}

int rocket_time(struct GameInfo gf,int *pyear,int*pmonth)
{
    int wyear=2029;
    int wmonth=5;
    char*temp=malloc((size_t)30);
    int dt;
    while(1)
    {
        dt=(wyear-gf.year)*12+(wmonth-gf.month);
        if(dt>=0&&dt<26)
        {    
            break;
        }
        else
        {
            wyear+=2;
            if(wmonth+2<=12)wmonth+=2;
            else
            {
                wmonth=(wmonth+2)%12;

            }
        }
    }
    *pmonth=wmonth;
    *pyear=wyear;
    return dt;
}



void rocket_prt1()
{
    menuprt(60,60,280,600);
    put_hz24(115,75,"火箭信息",65535,"HZK\\HZK24",0);
    
    put_hz24_asc32(80,125,"最大返程人数:10",65535,"HZK\\HZK24");
    put_hz24(100,160,"返程燃料：",65535,"HZK\\HZK24",0);

    put_hz24(100,220,"选择是否返航",65535,"HZK\\HZK24",0);
    yesbtn(0);
    nobtn(0);

    put_hz24(100,325,"输入返程人数",65535,"HZK\\HZK24",0);
    blankprt(120,360,225,395);

    put_hz24(70,430,"输入提供返程燃料",65535,"HZK\\HZK24",0);
    blankprt(120,465,225,500);

    btn_bar_Draw(100,535,225,570);
    put_hz24(140,540,"确定",65535,"HZK\\HZK24",0);

}

void rocket_prt2()
{
    menuprt(350,40,680,755);
    put_hz24(450,55,"货物信息",65535,"HZK\\HZK24",0);
    
    put_hz24(370,90,"货物最大总量：",65535,"HZK\\HZK24",0);
    
    put_hz24(360,145,"纳米材料：",65535,"HZK\\HZK24",0);
    blankprt(480,145,650,180);

    put_hz24(360,215,"稀有材料：",65535,"HZK\\HZK24",0);
    blankprt(480,215,650,250);

    put_hz24(360,285,"氧气：",65535,"HZK\\HZK24",0);
    blankprt(480,285,650,320);

    put_hz24(360,355,"淡水：",65535,"HZK\\HZK24",0);
    blankprt(480,355,650,390);

    put_hz24(360,425,"食物：",65535,"HZK\\HZK24",0);
    blankprt(480,425,650,460);

    put_hz24(360,495,"能源：",65535,"HZK\\HZK24",0);
    blankprt(480,495,650,530);

    put_hz24(360,565,"矿物：",65535,"HZK\\HZK24",0);
    blankprt(480,565,650,600);

    put_hz24(360,635,"人口：",65535,"HZK\\HZK24",0);
    blankprt(480,635,650,670);

    btn_bar_Draw(430,695,570,730);
    put_hz24(460,700,"确定",65535,"HZK\\HZK24",0);

}

void rocket_prt3()
{
    menuprt(740,70,990,350);
    put_hz24(830,75,"总计",65535,"HZK\\HZK24",0);
    
    put_hz24(750,140,"预计到达时间：",65535,"HZK\\HZK24",0);

    put_hz24(750,210,"预支燃料：",65535,"HZK\\HZK24",0);

    btn_bar_Draw(810,280,930,315);
    put_hz24(850,285,"确定",65535,"HZK\\HZK24",0);

}

void rocket_prtall()
{
    backprt1();
    rocket_prt1();
    rocket_prt2();
    rocket_prt3();
}

void backprt1()
{
    btn_bar_Draw(15,15,55,55);
    line_thick(20,20,50,50,2,0);
    line_thick(20,50,50,20,2,0);
}

void yesbtn(int form)
{
    if(form==0)
    {
        btn_bar_Draw(100,255,140,295);
        put_hz24(103,260,"是",65535,"HZK\\HZK24",0);
    }
    else
    {
        btn_bar_Draw0(100,255,140,295);
        put_hz24(103,260,"是",65535,"HZK\\HZK24",0);
    }
}

void nobtn(int form)
{
    if(form==0)
    {
        btn_bar_Draw(170,255,210,295);
        put_hz24(173,260,"否",65535,"HZK\\HZK24",0);
    }
    else
    {
        btn_bar_Draw0(170,255,210,295);
        put_hz24(173,260,"否",65535,"HZK\\HZK24",0);
    }
}

void blankprt(int x1,int y1,int x2,int y2)
{
    bar(x1,y1,x2,y2,0);
}

int rocket_ifreturn()
{
    if(rocket_pressyes()==1)return 1;
    else if(rocket_pressno()==1)return 2;
    else return 0;
}

void rocket_ifreturn_draw()
{
    int restyle=rocket_ifreturn();
    if(restyle==1)
    {
        yesbtn(1);
        nobtn(0);
    }
    if(restyle==2)
    {
        yesbtn(0);
        nobtn(1);
    }

}

int rocket_pressyes()
{
    return mouse_press(100,255,140,295);
}

int rocket_pressno()
{
    return mouse_press(170,255,210,295);
}

int rocket_input(int x1,int y1,int x2,int y2,int max)//-1表示未输入
{
    char*inputnum=malloc((size_t)40);
    int i=0;
    int renum;
    inputs(x1,y1,inputnum);
    while(inputnum[i]!='\0')
    {
        if(inputnum[i]>='0'&&inputnum[i]<='9')i++;
        else 
        {
            put_hz24(800,0,"存在非法字符",65535,"HZK\\HZK24",0);
            free(inputnum);
            return -1;
        }
    }

    renum=atoi(inputnum);
    if(renum<=max)
    {
        free(inputnum);
        return renum;
    }
        
    else
    {
        put_hz24(800,0,"数字过大",65535,"HZK\\HZK24",0);
        free(inputnum);
        return -1;
    }
}

void rocket_fun1()
{
    int peoplenum;
    char*cpeoplenum=malloc((size_t)20);
    rocket_ifreturn_draw();
    if(mouse_press(120,360,225,395)==1)
    {
        bar(120,360,225,395,0);
        peoplenum=rocket_input(120,360,225,395,10);
        if(peoplenum==-1)
        {
            bar(120,360,225,395,0);
            put_hz24_asc32(123,365,"未输入",65535,"HZK\\HZK24");
        }
        
        
    }
    free(cpeoplenum);
}
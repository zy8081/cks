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



void rocket_a_prt1()
{
    menuprt(60,60,280,600);
    put_hz24(115,75,"火箭信息",65535,"HZK\\HZK24",0);
    
    put_hz24_asc32(80,125,"最大返程人数:10",65535,"HZK\\HZK24");
    put_hz24_asc32(80,160,"返程燃料:20000",65535,"HZK\\HZK24");

    put_hz24(100,220,"选择是否返航",65535,"HZK\\HZK24",0);
    yesbtn(0);
    nobtn(0);
    
    bar(70,325,280,500,27469);
    
    btn_bar_Draw(100,535,225,570);
    put_hz24(140,540,"确定",65535,"HZK\\HZK24",0);

}

void rocket_a_prt1_p(int form)
{
    if(form==2)bar(70,325,280,500,27469);
    else 
    {
        put_hz24(100,325,"输入返程人数",65535,"HZK\\HZK24",0);
        blankprt(120,360,225,395);

        put_hz24(70,430,"输入提供返程燃料",65535,"HZK\\HZK24",0);
        blankprt(120,465,225,500);
    }
}

void rocket_a_prt2()
{
    menuprt(350,10,680,755);
    put_hz24(450,15,"货物信息",65535,"HZK\\HZK24",0);
    
    put_hz24(370,50,"货物最大总量：",65535,"HZK\\HZK24",0);
    
    put_hz24(360,115,"纳米材料：",65535,"HZK\\HZK24",0);
    blankprt(480,115+0*60,650,145+0*60);

    put_hz24(360,115+1*60,"稀有材料：",65535,"HZK\\HZK24",0);
    blankprt(480,115+1*60,650,145+1*60);

    put_hz24(360,115+2*60,"氧气：",65535,"HZK\\HZK24",0);
    blankprt(480,115+2*60,650,145+2*60);

    put_hz24(360,115+3*60,"淡水：",65535,"HZK\\HZK24",0);
    blankprt(480,115+3*60,650,145+3*60);

    put_hz24(360,115+4*60,"食物：",65535,"HZK\\HZK24",0);
    blankprt(480,115+4*60,650,145+4*60);

    put_hz24(360,115+5*60,"能源：",65535,"HZK\\HZK24",0);
    blankprt(480,115+5*60,650,145+5*60);

    put_hz24(360,115+6*60,"燃料：",65535,"HZK\\HZK24",0);
    blankprt(480,115+6*60,650,145+6*60);

    put_hz24(360,115+7*60,"矿物：",65535,"HZK\\HZK24",0);
    blankprt(480,115+7*60,650,145+7*60);

    put_hz24(360,115+8*60,"人口：",65535,"HZK\\HZK24",0);
    blankprt(480,115+8*60,650,145+8*60);

    btn_bar_Draw(430,655,570,690);
    put_hz24(460,660,"确定",65535,"HZK\\HZK24",0);

}

void rocket_a_prt3()
{
    menuprt(740,70,990,350);
    put_hz24(830,75,"总计",65535,"HZK\\HZK24",0);
    
    put_hz24(750,140,"预计到达时间：",65535,"HZK\\HZK24",0);

    put_hz24(750,210,"预支燃料：",65535,"HZK\\HZK24",0);

    btn_bar_Draw(810,280,930,315);
    put_hz24(850,285,"确定",65535,"HZK\\HZK24",0);

}

void rocket_a_prtall()
{
    backprt1();
    rocket_a_prt1();
    rocket_a_prt2();
    rocket_a_prt3();
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

int rocket_ifreturn(RKTINFO*pr)
{
    if(rocket_pressyes()==1)
    {
        pr->peopledec=-1;
        pr->refuelpay=-1;
        return 1;
    }
    else if(rocket_pressno()==1)
    {
        pr->peopledec=-1;
        pr->refuelpay=-1;
        return 2;
    }
    else return 0;
}

void rocket_ifreturn_draw(int restyle)
{
    if(restyle==1)
    {
        yesbtn(1);
        nobtn(0);
        return 1;
    }
    if(restyle==2)
    {
        yesbtn(0);
        nobtn(1);
        return 2;
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

int rocket_input(int x1,int y1,int x2,int y2,int max,int n)//-1表示未输入
{
    char*inputnum=malloc((size_t)40);
    int i=0;
    int in=0;
    long unsigned int renum;
    char test[3];
    inputnum[0]='\0';
    inputs(x1,y1,inputnum,n);
    if(inputnum[0]=='\0')return -1;
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
    
    while(inputnum[in]!='\0')
    {
        in++;
    }

    if(in==5)
    {
        if(inputnum[0]>='5')
        {
            put_hz24(800,0,"数字过大",65535,"HZK\\HZK24",0);
            free(inputnum);
            return -1;
        }
        else
        {
            renum=atoi(inputnum);
            if(renum<=max&&atoi(inputnum)>=0)
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
    }

    else if(in>5)
    {
        put_hz24(800,0,"数字过大",65535,"HZK\\HZK24",0);
        free(inputnum);
        return -1;
    }

    else
    {
        renum=atoi(inputnum);
        if(renum<=max&&atoi(inputnum)>=0)
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
}

void rocket_init(RKTINFO* rkt)
{

    rkt->apply=-1;

    rkt->resadd.nanomaterial=-1;
    rkt->resadd.rarematerial=-1;
    rkt->resadd.oxygen=-1;
    rkt->resadd.water=-1;
    rkt->resadd.food=-1;
    rkt->resadd.energy=-1;
    rkt->resadd.fuel=-1;
    rkt->resadd.mineral=-1;

    rkt->resdec.nanomaterial=0;
    rkt->resdec.rarematerial=0;
    rkt->resdec.oxygen=0;
    rkt->resdec.water=0;
    rkt->resdec.food=0;
    rkt->resdec.energy=0;
    rkt->resdec.fuel=0;
    rkt->resdec.mineral=0;

    rkt->peopleadd=-1;
    rkt->peopledec=-1;

    rkt->year=0;
    rkt->month=0;
    rkt->refuelpay=-1;
    rkt->refuel=-1;

    rkt->load=0;
    rkt->loadmax=0;
}

int check_f1(RKTINFO* pr)
{
    if(pr->apply!=-1&&pr->refuelpay!=-1&&pr->peopledec!=-1)
        return 1;
    else return 0;
}

void rocket_a_fun1(RKTINFO* pr)
{
    int peoplenum;
    int payfuelnum;
    int payfuel;
    int retemp=rocket_ifreturn(pr);
    if(retemp!=0)
    {
        pr->apply=retemp;
        rocket_ifreturn_draw(pr->apply);
        rocket_a_prt1_p(pr->apply);
    }
    if(pr->apply==1)
    {
        pr->refuel=20000;
        if(mouse_press(120,360,225,395)==1)
        {
            pr->peopledec=-1;

            clrmous(MouseX,MouseY);
            bar(120,360,225,395,0);
            peoplenum=rocket_input(120,360,225,395,10,1);
            if(peoplenum==-1)
            {
                bar(120,360,225,395,0);
                put_hz24_asc32(123,365,"未输入",65535,"HZK\\HZK24");
            }
            else pr->peopledec=peoplenum;
        }
        if(mouse_press(120,465,225,500)==1)
        {

            pr->refuelpay=-1;
            bar(120,465,225,500,0);
            payfuel=rocket_input(120,465,225,500,20000,4);
            if(payfuel==-1)
            {
                bar(120,465,225,500,00);
                put_hz24_asc32(123,470,"未输入",65535,"HZK\\HZK24");
            }
            else  pr->refuelpay=payfuel;
        }
    } 
    if(pr->apply==2)
    {
        pr->refuel=0;
        pr->refuelpay=0;
        pr->peopledec=0;
    }
    if(mouse_press(100,535,225,570)==1)
    {
        if(check_f1(pr)==1)
        {
            int max=rocket_max(*pr);
            char* cmax=malloc((size_t)20);
            pr->loadmax=max;
            itoa(max,cmax,10);
            bar(0,0,250,30,0);
            put_hz24_asc32(0,0,"成功！",65535,"HZK\\HZK24");
            bar(525,50,680,80,27469);
            put_hz24_asc32(525,50,cmax,65535,"HZK\\HZK24");
            free(cmax);
        }
        else
        {
            bar(520,50,680,80,27469);
            bar(0,0,250,30,0);
            put_hz24_asc32(0,0,"信息不完整!",65535,"HZK\\HZK24");
        }
    }
}

int rocket_max(RKTINFO pr)
{
    int max=0;
    if(pr.apply==1)
    {
        max=10000+pr.refuelpay;
        return max;
    }
    else if(pr.apply==2)
    {
        max=30000;
        return max;
    }
    else return -1;
}

int rocket_loadcom(struct Resource re,int people,int max)//比较载荷与最大容量
{
    unsigned int load=0;
    int temp=0;
    char test[6];
    itoa(re.nanomaterial,test,10);

    while(temp<re.nanomaterial)
    {
        if(load+3<=max)
        {
            temp++;
            load+=3;
        }
        else return -1;
    }

    temp=0;
    while(temp<re.rarematerial)
    {
        if(load+3<=max)
        {
            temp++;
            load+=3;
        }
        else return -1;
    }
    
    temp=0;
    while(temp<re.oxygen)
    {
        if(load+1<=max)
        {
            temp++;
            load+=1;
        }
        else return -1;
    }
    
    temp=0;
    while(temp<re.water)
    {
        if(load+1<=max)
        {
            temp++;
            load+=1;
        }
        else return -1;
    }
    
    temp=0;
    while(temp<re.food)
    {
        if(load+10<=max)
        {
            temp++;
            load+=10;
        }
        else return -1;
    }
   
    temp=0;
    while(temp<re.energy)
    {
        if(load+3<=max)
        {
            temp++;
            load+=3;
        }
        else return -1;
    }
    
    temp=0;
    while(temp<re.fuel)
    {
        if(load+1<=max)
        {
            temp++;
            load+=1;
        }
        else return -1;
    }
    
    temp=0;
    while(temp<re.mineral)
    {
        if(load+10<max)
        {
            temp++;
            load+=10;
        }
        else return -1;
    }
    
    temp=0;
    while(temp<people)
    {
        if(load+1000<=max)
        {
            temp++;
            load+=1000;
        }
        else return -1;
    }
   
    return load;
}



void rocket_a_fun2(RKTINFO* pr)
{
    int i;
    int loadmax=rocket_max(*pr);
    //int pn=-1;
    int num;
    int load;
    //struct Resource temp={-1,-1,-1,-1,-1,-1,-1,-1};
    int remax[9]={30000,30000,30000,30000,30000,30000,30000,30000,10};
    int ren[9]={5,5,5,5,5,5,5,5,2};
    

    for(i=0;i<9;i++)
    {
        if(mouse_press(482,115+i*60,650,145+i*60)==1)
        {
            int num;
            bar(482,115+i*60,650,145+i*60,0);
            num=rocket_input(482,115+i*60,650,145+i*60,remax[i],ren[i]);
            if(num==-1)
            {
                bar(482,115+i*60,650,145+i*60,0);
                put_hz24_asc32(482,118+i*60,"未输入",65535,"HZK\\HZK24");
            }
            else  
            {
                switch(i)
                {
                    case 0:
                        pr->resadd.nanomaterial=num;
                        break;
                    case 1:
                        pr->resadd.rarematerial=num;
                        break;
                    case 2:
                        pr->resadd.oxygen=num;
                        break;
                    case 3:
                        pr->resadd.water=num;
                        break;
                    case 4:
                        pr->resadd.food=num;
                        break;
                    case 5:
                        pr->resadd.energy=num;
                        break;
                    case 6:
                        pr->resadd.fuel=num;
                        break;
                    case 7:
                        pr->resadd.mineral=num;
                        break;
                    case 8:
                        pr->peopleadd=num;
                        break;
                }
            }
    }
    
    }
    if(mouse_press(430,655,570,690)==1)
    {
        if(rocket_check2(*pr)==1)
        {
            if(rocket_loadcom(pr->resadd,pr->peopleadd,pr->loadmax)!=-1)
            {
                char* cload=malloc((size_t)30);
                bar(900,500,1000,525,0);
                pr->load=rocket_loadcom(pr->resadd,pr->peopleadd,pr->loadmax);
                itoa(pr->load,cload,10);
                put_hz24_asc32(900,500,cload,65535,"HZK\\HZK24");
                free(cload);
            }
            else
            {
                bar(900,500,1000,525,0);
                put_hz24_asc32(900,500,"超重",65535,"HZK\\HZK24");
            }
        }
        else
        {
            bar(900,500,1000,525,0);
            put_hz24_asc32(900,500,"请补充数据！",65535,"HZK\\HZK24");
        }
    }
}

int rocket_check1(RKTINFO r)
{
    if(r.apply==1)
        return 1;
    else if(r.apply==2)
    {
        if(r.peopledec!=-1&&r.refuelpay!=-1)return 1;
        else return 0;
    }
    else return 0;
}

int rocket_check2(RKTINFO r)
{
    if(r.resadd.nanomaterial!=-1&&r.resadd.rarematerial!=-1&&r.resadd.oxygen!=-1&&r.resadd.water!=-1&&r.resadd.food!=-1&&r.resadd.energy!=-1&&r.resadd.fuel!=-1&&r.resadd.mineral!=-1&&r.peopleadd!=-1)
        return 1;
    else return 0;
}


void rocket_apply()
{
    RKTINFO r;
    clrmous(MouseX,MouseY);
    rocket_a_prtall();
    rocket_init(&r);
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        rocket_a_fun1(&r);
        if(rocket_check1(r)==0)
        {
            if(mouse_press(350,10,680,755)==1)
            {
                bar(0,0,30,100,0);
                put_hz24(0,0,"请先填写火箭信息",65535,"HZK\\HZK24",0);
            }
        }
        else
            rocket_a_fun2(&r);
        if(mouse_press(15,15,55,55)==1)exit(1);
    }

}
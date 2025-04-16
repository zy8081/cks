#include <common.h>
#include <game.h>
#include <fun3_2.h>
#include <fun3_3.h>
#include <fun3.h>
#include <WRKMNG.h>
#include <fun5.h>
#include <fun4.h>
#include <fun4_2.h>
#include <fun1.h>
#include <ORDFUNS.h>
#include <MAP.h>
#include <debug.h>
//拆除地图上的建筑
int demolish_building(struct GameInfo *gameinfop)
{
    int page=4;
    int i,j,k;
    int confirm_flag;
    draw_map2(300,105,954,759,7,7,gameinfop);
    draw_map(300,105,954,759,7,7,gameinfop);
    while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if (judge_press_mainbutton(3,&page))
        {
            return page;
        }
		
        for (i=0;i<7;i++)
        {
            for(j=0;j<7;j++)
            {
                if(mouse_press_map(i,j)==1&&gameinfop->m_info[i][j].building.id!=0&&gameinfop->m_info[i][j].building.bui_time==0)
                {
                    draw_demolish_confirm(gameinfop,i,j);
                    confirm_flag=0;
                    while(1)
                    {
                        mouse_renew(&MouseX,&MouseY,&press);
                        if (judge_press_demolish_confirm(1)==1)
                        {
                            confirm_flag=1;
                        }
                        else if (judge_press_demolish_confirm(2)==1)
                        {
                            confirm_flag=2;
                        }
                        if (confirm_flag)
                        {
                            clrmous(MouseX,MouseY);
                            load_demolish_confirm();
                            break;
                        }
                    }
                    if (confirm_flag==2)
                    {
                        demolish_on_map(gameinfop,i,j);
                        clear_main_all();
			            clear_right_all();
                        return 1;
                    }
                    
                }
            }
        }
	}
}

void draw_demolish_confirm(struct GameInfo *gameinfop,int i,int j)
{
    SaveBMP(490,290,810,610,0);
    clrmous(MouseX,MouseY);
    btn_bar_Draw(500,300,800,600);
    btn_bar_Draw1(500,500,650,600);
    btn_bar_Draw1(650,500,800,600);
    puthz(500,500,"取消",32,32,1);
    puthz(650,500,"确定",32,32,1);
    puthz(510,310,"你确定要拆除这个建筑吗",24,24,1);
    puthz(510,340,"拆除只会返回部分资源",24,24,1);
}
void load_demolish_confirm(void)
{
    LoadBMP(490,290,810,610,0);
}

int judge_press_demolish_confirm(int pos)
{
    return mouse_press(500+(pos-1)*150,500,650+(pos-1)*150,600);
}

void demolish_on_map(struct GameInfo *gameinfop,int i,int j)
{
    int k;
    gameinfop->m_info[i][j].building.res_cost.nanomaterial=0;
    gameinfop->m_info[i][j].building.res_cost.rarematerial=0;
    gameinfop->m_info[i][j].building.res_cost.oxygen=0;
    gameinfop->m_info[i][j].building.res_cost.water=0;
    gameinfop->m_info[i][j].building.res_cost.food=0;
    gameinfop->m_info[i][j].building.res_cost.energy=0;
    gameinfop->m_info[i][j].building.res_cost.fuel=0;
    gameinfop->m_info[i][j].building.res_cost.mineral=0;

                        
    gameinfop->m_info[i][j].building.id=0;
    gameinfop->m_info[i][j].building.bui_time=0;

    gameinfop->m_info[i][j].building.res_cost.nanomaterial=0;
    gameinfop->m_info[i][j].building.res_cost.rarematerial=0;

    for (k=0;k<strlen(gameinfop->m_info[i][j].building.name);k++)
    {
        gameinfop->m_info[i][j].building.name[k]=0;
    }
    for (k=0;k<strlen(gameinfop->m_info[i][j].building.pic_path);k++)
    {
        gameinfop->m_info[i][j].building.pic_path[k]=0;
    }
}

int ban_building(struct GameInfo *gameinfop)
{
    int page=4;
    int i,j,k;
    int confirm_flag;
    draw_map2(300,105,954,759,7,7,gameinfop);
    draw_map(300,105,954,759,7,7,gameinfop);
    while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if (judge_press_mainbutton(3,&page))
        {
            return page;
        }
		
        for (i=0;i<7;i++)
        {
            for(j=0;j<7;j++)
            {
                if(mouse_press_map(i,j)==1&&gameinfop->m_info[i][j].building.id!=0&&gameinfop->m_info[i][j].building.bui_time==0)
                {
                    if (gameinfop->m_info[i][j].building.lock==0)
                    {
                        draw_ban_confirm(gameinfop,i,j);
                        confirm_flag=0;
                        while(1)
                        {
                            mouse_renew(&MouseX,&MouseY,&press);
                            if (judge_press_demolish_confirm(1)==1)
                            {
                                confirm_flag=1;
                            }
                            else if (judge_press_demolish_confirm(2)==1)
                            {
                                confirm_flag=2;
                            }
                            if (confirm_flag)
                            {
                                clrmous(MouseX,MouseY);
                                load_demolish_confirm();
                                break;
                            }
                        }
                        if (confirm_flag==2)
                        {
                            demolish_on_map(gameinfop,i,j);
                            clear_main_all();
			                clear_right_all();
                            return 1;
                        }
                    }
                    
                    
                }
            }
        }
	}
}

void draw_ban_confirm(struct GameInfo *gameinfop,int i,int j)
{
    char str[30];
    SaveBMP(490,290,810,610,0);
    clrmous(MouseX,MouseY);
    btn_bar_Draw(500,300,800,600);
    btn_bar_Draw1(500,500,650,600);
    btn_bar_Draw1(650,500,800,600);
    puthz(500,500,"取消",32,32,1);
    puthz(650,500,"确定",32,32,1);
    sprintf(str,"禁用：%s",gameinfop->m_info[i][j].building.name);
    puthz(510,310,str,24,24,1);
    puthz(510,340,"你确定要禁用这个建筑吗",24,24,1);
    puthz(510,370,"禁用之后该建筑将无产出",24,24,1);
    puthz(510,400,"也无需维护费",24,24,1);
}
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
int demolish_building(struct GameInfo *gameinfop,int *pxsel,int *pysel)
{
    int page=4;
    int i,j,k;
    int confirm_flag;
    char str[30];
    draw_buildmap(gameinfop,*pxsel,*pysel);
	draw_minimap(gameinfop,*pxsel,*pysel);
    btn_bar_Draw(50,300,150,350);
	puthz2(50,300,32,32,1,"返回");
    while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if (judge_press_mainbutton(3,&page))
        {
            return page;
        }
        if(renew_map(pxsel,pysel)==1)
	    {
			draw_buildmap(gameinfop,*pxsel,*pysel);
			draw_minimap(gameinfop,*pxsel,*pysel);
		}
        if(mouse_press(50,300,150,350)==1)
        {
            clrmous(MouseX,MouseY);
            clear_main_all();
            clear_right_all();
            return 3;
        }
		
        for (i=0;i<7;i++)
        {
            for(j=0;j<7;j++)
            {
                if(mouse_press_map(i,j)==1)
                {
                    if (gameinfop->m_info[i][j].building.id!=0&&gameinfop->m_info[i][j].building.bui_time!=0)
                    {
                        SaveBMP(390,290,810,610,0);
                        clrmous(MouseX,MouseY);
                        btn_bar_Draw(400,300,800,600);
                        sprintf(str,"此地建筑：%s",gameinfop->m_info[i][j].building.name);
                        puthz3(410,310,24,24,1,str);
                        
                        puthz3(410,350,32,32,0xA000,"仍在建造中，无法拆除");
                        puthz3(410,390,32,32,0xA000,"若要停止建造，");
                        
                        puthz3(410,425,32,32,0xA000,"请使用建造队列功能");
                        delay(1500);
                        LoadBMP(390,290,810,610,0);
                    }
                    else if(gameinfop->m_info[i][j].building.id==0)
                    {
                        SaveBMP(390,290,810,610,0);
                        clrmous(MouseX,MouseY);
                        btn_bar_Draw(400,300,800,600);
                        puthz3(410,310,32,32,1,"此地并无建筑");
                        puthz3(410,360,32,32,0xA000,"无法拆除");
                        
                        delay(1500);
                        LoadBMP(390,290,810,610,0);
                    }
                    else
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
                                delay(150);
                                load_demolish_confirm();
                                mouse_renew(&MouseX,&MouseY,&press);
                                break;
                            }
                        }
                        if (confirm_flag==2)
                        {
                            clrmous(MouseX,MouseY);
                            demolish_on_map(gameinfop,i,j,*pxsel,*pysel);
                            clear_main_all();
                            clear_right_all();
                            return 3;
                        }
                    }

                }
                
            }
        }
	}
}

void draw_demolish_confirm(struct GameInfo *gameinfop,int i,int j)
{
    SaveBMP(390,290,810,610,0);
    clrmous(MouseX,MouseY);
    btn_bar_Draw(400,300,800,600);
    btn_bar_Draw(400,550,500,600);
    puthz2(400,550,32,32,1,"取消");
    btn_bar_Draw(700,550,800,600);
    puthz2(700,550,32,32,1,"确定");
    puthz2(410,310,32,32,1,"你确定要拆除这个建筑吗");
    puthz3(410,360,24,24,0xA000,"拆除只会返回百分之二十资源");
}

void load_demolish_confirm(void)
{
    LoadBMP(390,290,810,610,0);
}

int judge_press_demolish_confirm(int pos)
{
    return mouse_press(400+(pos-1)*300,550,500+(pos-1)*300,600);
}

void demolish_on_map(struct GameInfo *gameinfop,int i,int j,int pxsel,int pysel)
{
    int k;
    gameinfop->m_info[i][j].building.res_add.nanomaterial=0;
    gameinfop->m_info[i][j].building.res_add.rarematerial=0;
    gameinfop->m_info[i][j].building.res_add.oxygen=0;
    gameinfop->m_info[i][j].building.res_add.water=0;
    gameinfop->m_info[i][j].building.res_add.food=0;
    gameinfop->m_info[i][j].building.res_add.energy=0;
    gameinfop->m_info[i][j].building.res_add.fuel=0;
    gameinfop->m_info[i][j].building.res_add.mineral=0;

    gameinfop->m_info[i][j].building.lock=0;              
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

int ban_building(struct GameInfo *gameinfop,int *pxsel,int *pysel)
{
    int page=4;
    int i,j,k;
    int confirm_flag;
    char str[30];
    draw_buildmap(gameinfop,*pxsel,*pysel);
	draw_minimap(gameinfop,*pxsel,*pysel);
    btn_bar_Draw(50,300,150,350);
	puthz2(50,300,32,32,1,"返回");
    while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if (judge_press_mainbutton(3,&page))
        {
            return page;
        }
        if(renew_map(pxsel,pysel)==1)
	    {
			draw_buildmap(gameinfop,*pxsel,*pysel);
			draw_minimap(gameinfop,*pxsel,*pysel);
		}
        if(mouse_press(50,300,150,350)==1)
        {
            clrmous(MouseX,MouseY);
            clear_main_all();
            clear_right_all();
            return 3;
        }
		
        for (i=0;i<7;i++)
        {
            for(j=0;j<7;j++)
            {
                if(mouse_press_map(i,j)==1)
                {
                    if (gameinfop->m_info[i][j].building.id==0)
                    {
                        SaveBMP(390,290,810,610,0);
                        clrmous(MouseX,MouseY);
                        btn_bar_Draw(400,300,800,600);
                        puthz3(410,310,24,24,0xA000,"此地啥建筑都没有！");
                        puthz2(410,350,32,32,0xA000,"禁用不了建筑！");
                        
                        delay(1500);
                        LoadBMP(390,290,810,610,0);
                    }
                    else if(gameinfop->m_info[i][j].building.bui_time!=0)
                    {
                        SaveBMP(390,290,810,610,0);
                        clrmous(MouseX,MouseY);
                        btn_bar_Draw(400,300,800,600);
                        puthz3(410,310,24,24,0xA000,"此地建筑仍在建造中！");
                        puthz2(410,350,32,32,0xA000,"禁用不了建筑！");
                        
                        delay(1500);
                        LoadBMP(390,290,810,610,0);
                    }
                    else
                    {
                        if (gameinfop->m_info[i][j].building.lock==0)
                        {
                            draw_ban_confirm(gameinfop,i,j,*pxsel,*pysel,0);
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
                                    delay(150);
                                    load_demolish_confirm();
                                    mouse_renew(&MouseX,&MouseY,&press);
                                    break;
                                }
                            }
                            if (confirm_flag==2)
                            {
                                clrmous(MouseX,MouseY);
                                ban_unban_on_map(gameinfop,i,j,*pxsel,*pysel,0);
                                clear_main_all();
                                clear_right_all();
                                return 3;
                            }
                        }
                        else
                        {
                            draw_ban_confirm(gameinfop,i,j,*pxsel,*pysel,1);
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
                                    delay(150);
                                    load_demolish_confirm();
                                    mouse_renew(&MouseX,&MouseY,&press);
                                    break;
                                }
                            }
                            if (confirm_flag==2)
                            {
                                clrmous(MouseX,MouseY);
                                ban_unban_on_map(gameinfop,i,j,*pxsel,*pysel,1);
                                clear_main_all();
                                clear_right_all();
                                return 3;
                            }
                        }
                    } 
                }
            }
        }
	}
}

void draw_ban_confirm(struct GameInfo *gameinfop,int i,int j,int pxsel,int pysel,int lock)
{
    char str[30];
    SaveBMP(390,290,810,610,0);
    clrmous(MouseX,MouseY);
    btn_bar_Draw(400,300,800,600);
    btn_bar_Draw(400,550,500,600);
    puthz2(400,550,32,32,1,"取消");

    btn_bar_Draw(700,550,800,600);
    puthz2(700,550,32,32,1,"确定");
    if (lock==0)
    {
        sprintf(str,"禁用：%s",gameinfop->m_info[i+pysel][j+pxsel].building.name);
        puthz2(410,310,32,32,0xA000,str);
        puthz3(410,360,24,24,1,"你确定要禁用这个建筑吗");
        puthz3(410,390,24,24,1,"禁用之后该建筑将无产出");
        puthz3(410,420,24,24,1,"也无需维护费");
    }
    else
    {
        sprintf(str,"解禁：%s",gameinfop->m_info[i+pysel][j+pxsel].building.name);
        puthz2(410,310,32,32,1000,str);
        puthz3(410,360,24,24,1,"你要解除禁用这个建筑吗");
        puthz3(410,390,24,24,1,"解除之后该建筑恢复产出");
        puthz3(410,420,24,24,1,"需要维护费用");
    }
}

void ban_unban_on_map(struct GameInfo *gameinfop,int i,int j,int pxsel,int pysel,int lock)
{
    if (lock==0)
    {
        gameinfop->m_info[i+pysel][j+pxsel].building.lock=1;
    }
    else
    {
        gameinfop->m_info[i+pysel][j+pxsel].building.lock=0;
    }   
}
#include <common.h>
#include <game.h>
#include <fun3_2.h>
#include <fun3.h>
#include <WRKMNG.h>
#include <fun5.h>
#include <fun4.h>
#include <fun4_2.h>
#include <fun1.h>
#include <ORDFUNS.h>
#include <MAP.h>
#include <debug.h>
int proj_fun1(struct GameInfo* gameinfop,int*pxsel,int*pysel)
{
	int page=1;
	int i;
	int l=65;
	char *s[2]={"查看建筑","还没想好"};
	draw_main_toolbotton_activate(234,0xBD32,"地图","显示");
	draw_all_leftbuttons(2,65,s);
    //draw_map2(300,105,954,759,7,7,gameinfop);
	//draw_map(300,105,954,759,7,7,gameinfop);
	//debug_map_id(*gameinfop);
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if(judge_press_mainbutton(1,&page))
		{
			return page;
		}
		
		if (left_toolbotton_mouse_press(1) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all(); 
            draw_left_toolbotton_activate(95 , l, s[0]);//激活新的
            clear_right_all();
            page=check_mapbuild(gameinfop,pxsel,pysel);
            return page;   
		}
		// else if (left_toolbotton_mouse_press(2) == 1) //左栏被点中的情况
        // {
        //     clrmous(MouseX,MouseY);
        //     clear_main_all(); 
        //     draw_left_toolbotton_activate(95 , l, s[1]);//激活新的
        //     clear_right_all();
        //     page=build_queue(gameinfop,p);
        //     return page;   
		// }
	}
}

int check_mapbuild(struct GameInfo* gameinfop,int *pxsel,int *pysel)
{
    int page=1;
	int i,j;
	int l=65;
    //draw_map2(300,105,954,759,7,7,gameinfop);
	//draw_map(300,105,954,759,7,7,gameinfop);
    draw_buildmap(*gameinfop,*pxsel,*pysel);
	draw_minimap(*gameinfop,*pxsel,*pysel);
    while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if(judge_press_mainbutton(1,&page))
		{
			return page;
		}
        if(renew_map(pxsel,pysel)==1)
		{
			draw_minimap(*gameinfop,*pxsel,*pysel);
			draw_mainmap(*gameinfop,*pxsel,*pysel);
		}
		
		for (i=0;i<7;i++)
        {
            for (j=0;j<7;j++)
            {
                if(mouse_press_map(i,j)==1)
                {
                    clrmous(MouseX,MouseY);
                    draw_check_mapbuild_toast(gameinfop->m_info[*pysel+i][*pxsel+j].building);
                    while(1)
                    {
                        mouse_renew(&MouseX,&MouseY,&press);
                        if(mouse_press(500,500,800,600)==1)
                        {
                            clrmous(MouseX,MouseY);
                            load_check_mapbuild_toast();
                            
                            break;
                        }
                    }
                    delay(400);
                    mouse_renew(&MouseX,&MouseY,&press);
                    
                }
                
            }
        }
	}
}

void draw_check_mapbuild_toast(struct Building building)
{
    char str[50];
    SaveBMP(490,290,810,610,0);
    clrmous(MouseX,MouseY);
    btn_bar_Draw(500,300,800,600);
    btn_bar_Draw(500,500,650,600);
    btn_bar_Draw(650,500,800,600);
    puthz(500,500,"取消",32,32,1);
    puthz(650,500,"确定",32,32,1);
    if (building.id==0)
    {
        puthz(510,310,"此处并无建筑",24,24,1);
    }

    else if (building.bui_time!=0)
    {
        puthz(510,310,building.name,24,24,1);
        puthz(510,340,"仍在建造中",24,24,1);
    }
    else
    {
        puthz(510,310,building.name,24,24,1);
    }
}

void load_check_mapbuild_toast(void)
{
    LoadBMP(490,290,810,610,0);
}
#include <common.h>
#include <game.h>
#include <fun3_2.h>
#include <fun3.h>
#include <WRKMNG.h>
#include <fun5.h>
#include <fun4.h>
#include <fun2.h>
#include <fun1.h>
#include <SL.h>
#include <MAP.h>
#include <EVENT.h>
#include <ROCKET.h>
/*
项目中心换页控制
*/
int project(struct workfile w)
{
	int proj_page=0;
	char path[20]={'\0'};
	int i,j;
	int events[2]={0,0};
	int xsel=0;
	int ysel=0;
	struct GameInfo gameinfo;
	struct Resource res_earns;
	
	//建筑队列
	nodebq *p1=load_node(w);
	
	gameinfo.r_info.energy=10000;
	gameinfo.r_info.nanomaterial=10000;
	gameinfo.r_info.rarematerial=10000;
	gameinfo.r_info.oxygen=10000;
	gameinfo.r_info.water=10000;
	gameinfo.r_info.food=10000;
	gameinfo.r_info.fuel=10000;
	gameinfo.r_info.mineral=10000;
	
	gameinfo.year=2031;
	gameinfo.month=4;
	gameinfo.techpoint=200;
	gameinfo.gametech[0].research_flag=0;
	
	gameinfo.people=0;
	gameinfo.happiness[0]=0;

	map_init(2,&gameinfo);
	rocket_init(&(gameinfo.rocket));

	load_gminfo(w,&gameinfo);
	/*
	这里预留空间通过文件读取操作访问存档
	
	
	*/
	clrmous(MouseX,MouseY); 
	delay(100); 
	cleardevice();
	
	while (1)
	{
		switch(proj_page)
		{
			case 0:
				proj_page=proj_origin(&gameinfo);
				break;
			case 1:
				proj_page=proj_fun1(&gameinfo,&xsel,&ysel);
				break;
			case 2:
				proj_page=proj_fun2(&gameinfo,&xsel,&ysel);
				break;
			case 3:
				proj_page=proj_fun3(&gameinfo,p1,&xsel,&ysel);
				break;
			case 4:
				proj_page=proj_fun4(&gameinfo);
				break;
			case 5:
				proj_page=proj_fun5(&gameinfo,p1,w,&events);
				bar(0,0,100,30,65535);
				//put_hz24_asc32(0,0,"done2",0,"HZK\\HZK24");
				//getch();
				
				//put_hz24_asc32(0,0,"done3",0,"HZK\\HZK24");
				//getch();
				break;
			//case 11:
				//free_nodebq_all(p1);
				//return 4;
			//case 12:
				//free_nodebq_all(p1);
				//return 1;
			//case 13:
				//ree_nodebq_all(p1);
				//close_all();
		}
	}
	return proj_page;
}

void calculate_monthly_income(struct GameInfo *gameinfop,int *data)
{
	int i,j,k;
	int income;
	
	k=0;
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.nanomaterial;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.rarematerial;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.oxygen;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.water;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.food;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.energy;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.fuel;
			}
		}
	}
	data[k]=income;
	k++;
	
	income=0;
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id>0 && gameinfop->m_info[i][j].building.bui_time==0)
			{
				income+=gameinfop->m_info[i][j].building.res_add.mineral;
			}
		}
	}
	data[k]=income;
	k++;
}








int proj_origin(struct GameInfo* gameinfop)
{
	clrmous(MouseX,MouseY);
	draw_pro_origin();
	//draw_map(300,105,954,759,7,7,gameinfop);
	
	draw_time(gameinfop);
	while(1)
    {
		mouse_renew(&MouseX,&MouseY,&press);
        
        if(main_toolbotton_mouse_press(1)==1)
        {
            clrmous(MouseX,MouseY);
			return 1;
        }
		
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY);
            return 2;
        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY);
            return 3;
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY);
            return 4;
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY);
            return 5;
        }
        delay(15);
    }

}







//void get_techflag_all(tree *p)
//{
//	if (p==NULL)
//	{
//		return;
//	}
//	get_techflag_all(p->leftchild);
//	get_techflag_all(p->rightchild);
//	get_techflag(p);
//}


int judge_press_mainbutton(int flag,int *page)
{
	char *s1[5]={"地图","全局","建造","科技","时间"};
	char *s2[5]={"显示","资源","显示","研究","流动"};
	unsigned color[5]={0xBD32,0xFFAA,0xBBBB,0xFF19,0xBDBD};
	
	if(main_toolbotton_mouse_press(1)==1)//now==66防止与下面主栏返回键被点中的情况冲突
   	{
       	clrmous(MouseX,MouseY); 
       	draw_main_toolbotton(234+(flag-1)*158,color[flag-1],s1[flag-1],s2[flag-1]);
       	clear_main_all();
		clear_right_all();
		*page=1;
		return 1;
   	}
   	else if(main_toolbotton_mouse_press(2)==1)
   	{
       	clrmous(MouseX,MouseY); 
       	draw_main_toolbotton(234+(flag-1)*158,color[flag-1],s1[flag-1],s2[flag-1]);
      	clear_main_all();	
		clear_right_all();
       	*page=2;	
		return 2;
   	}
   	else if(main_toolbotton_mouse_press(3)==1)
   	{
       	clrmous(MouseX,MouseY); 
       	draw_main_toolbotton(234+(flag-1)*158,color[flag-1],s1[flag-1],s2[flag-1]);
       	clear_main_all();
		clear_right_all();
       	*page=3;
		return 3;
   	}
   	else if(main_toolbotton_mouse_press(4)==1)
  	{
       	clrmous(MouseX,MouseY); 
       	draw_main_toolbotton(234+(flag-1)*158,color[flag-1],s1[flag-1],s2[flag-1]);
       	clear_main_all();	
		clear_right_all();
       	*page=4;
		return 4;
   	}
   	else if(main_toolbotton_mouse_press(5)==1)
   	{
       	clrmous(MouseX,MouseY); 
       	draw_main_toolbotton(234+(flag-1)*158,color[flag-1],s1[flag-1],s2[flag-1]);
       	clear_main_all();	
		clear_right_all();
      	*page=5;
		return 5;
   	}
	return 0;
}

void left_button_clear_activate(int n,char *s[])
{
	clrmous(MouseX,MouseY);
    clear_main_all(); 
    draw_left_toolbotton_activate(95 , 65, s[n-1]);//激活新的
    clear_right_all();
}
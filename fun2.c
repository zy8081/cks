#include "common.h"
#include "game.h"
#include "WRKMNG.h"
#include "fun3_2.h"
#include "fun3.h"
#include "fun5.h"
#include "fun4.h"
#include "fun2.h"
#include "SL.h"


int proj_fun2(struct GameInfo* gameinfop)
{
	int page=2;
	int page2=0;
	int now=0;
	int flag=0;
	int l=65;
	int i;
	char *s[2]={"资源统计","资源收支"};
	draw_main_toolbotton_activate(392,0xFFAA,"全局","资源");
	
	
	draw_all_leftbuttons(2,65,s);
	
	//drawmous(MouseX,MouseY);
	
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if(main_toolbotton_mouse_press(1)==1)//now==66防止与下面主栏返回键被点中的情况冲突
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"全局","资源");
            clear_main_all();
			clear_right_all();
            return 1;
            
        }
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"全局","资源");
            clear_main_all();
			clear_right_all();
            return 2;

        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"全局","资源");
            clear_main_all();
			clear_right_all();
            return 3;
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"全局","资源");
            clear_main_all();
			clear_right_all();
            return 4;
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"全局","资源");
            clear_main_all();
			clear_right_all();
            return 5;
        }
		
		if (left_toolbotton_mouse_press(1) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            //clear_main_all();
            draw_left_toolbotton_activate(95 , l, s[0]);//激活新的
            clear_right_all();
            proj_fun2_1(gameinfop);
            continue;
		}
	}
}

void proj_fun2_1(struct GameInfo *gameinfop)
{
	clrmous(MouseX,MouseY); 
	get_all_resourceinfo(gameinfop);
}

void get_all_resourceinfo(struct GameInfo *gameinfop)
{
	char *s[8]={"纳米材料","稀有材料","氧气","淡水","食物","能源","燃料","矿物"};
	long int data1[8];
	int data2[8];
	
	
	char str[30]={'\0'};
	int i,j;
	data1[0]=gameinfop->r_info.nanomaterial;
	data1[1]=gameinfop->r_info.rarematerial;
	data1[2]=gameinfop->r_info.oxygen;
	data1[3]=gameinfop->r_info.water;
	data1[4]=gameinfop->r_info.food;
	data1[5]=gameinfop->r_info.energy;
	data1[6]=gameinfop->r_info.fuel;
	data1[7]=gameinfop->r_info.mineral;
	calculate_monthly_income(gameinfop,data2);

	puthz(240, 110,"资源统计：",48,48,1);
	puthz(600, 110,"资源月收支：",48,48,1);
	for (j=0;j<8;j++)
	{
		i=0;
		while(str[i]!='\0')
		{
			str[i++]='\0';
		}
		sprintf(str,"%s:%d",s[j],data1[j]);
		put_hz24_asc32(260,190+j*55,str,1,"HZK\\Hzk24k");
		
		while(str[i]!='\0')
		{
			str[i++]='\0';
		}
		sprintf(str,"%s:%d",s[j],data2[j]);
		put_hz24_asc32(600,190+j*55,str,1,"HZK\\Hzk24k");
	}
}
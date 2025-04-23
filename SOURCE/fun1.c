#include<ALLFUNS.h>
int proj_fun1(struct GameInfo* gameinfop,int*pxsel,int*pysel)
{
	int page=1;
	int i;
	int l=65;
	char *s[2]={"查看建筑","还没想好"};
	draw_main_toolbotton_activate(234,0xBD32,"地图","显示");
	draw_all_leftbuttons(2,65,s);
	
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
	
    draw_buildmap(gameinfop,*pxsel,*pysel);
	draw_minimap(gameinfop,*pxsel,*pysel);
    while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		
		if(judge_press_mainbutton(1,&page))
		{
			return page;
		}
        if(renew_map(pxsel,pysel)==1)
		{
			draw_minimap(gameinfop,*pxsel,*pysel);
			draw_mainmap(gameinfop,*pxsel,*pysel);
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
                        if(mouse_press(400,650,500,700)==1)
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
    int i=0,j=0;
    char str[50];
    SaveBMP(390,290,810,710,0);
    clrmous(MouseX,MouseY);
    btn_bar_Draw(400,300,800,700);
    btn_bar_Draw(400,650,500,700);
    //btn_bar_Draw(700,650,800,700);
    puthz2(400,650,32,32,1,"取消");
    //puthz2(700,650,32,32,1,"确定");
    if (building.id==0)
    {
        puthz2(410,310,32,32,0xA000,"此处并无建筑！");
    }

    else if (building.bui_time!=0)
    {
        puthz2(410,310,32,32,1,building.name);
        puthz2(410,350,32,32,0xA000,"仍在建造中");
        //put_asc16_number_size(540,370,2,2,building.id,1);
    }
    else
    {
        puthz3(410,310,32,32,1,building.name);
        puthz3(410,440,24,24,0xA000,"维护：");
        puthz3(410,480,24,24,1000,"产出：");
        if (building.res_add.energy<0)
        {
            sprintf(str,"能源%d",building.res_add.energy);
            put_hz24_asc32(490+i*(80),440,str,0xA000,"HZK\\Hzk24k");
            i++;
        }
        if (building.res_add.food<0)
        {
            sprintf(str,"食物%d",building.res_add.food);
            put_hz24_asc32(490+i*(80),440,str,0xA000,"HZK\\Hzk24k");
            i++;
        }
        if (building.res_add.fuel<0)
        {
            sprintf(str,"燃料%d",building.res_add.fuel);
            put_hz24_asc32(490+i*(80),440,str,0xA000,"HZK\\Hzk24k");
            i++;
        }
        if (building.res_add.mineral<0)
        {
            sprintf(str,"矿物%d",building.res_add.mineral);
            put_hz24_asc32(490+i*(80),440,str,0xA000,"HZK\\Hzk24k");
            i++;
        }
        if (building.res_add.nanomaterial<0)
        {
            sprintf(str,"纳米材料%d",building.res_add.nanomaterial);
            put_hz24_asc32(490+i*(80),440,str,0xA000,"HZK\\Hzk24k");
            i++;
        }
        if (building.res_add.oxygen<0)
        {
            sprintf(str,"氧气%d",building.res_add.oxygen);
            put_hz24_asc32(490+i*(80),440,str,0xA000,"HZK\\Hzk24k");
            i++;
        }
        if (building.res_add.rarematerial<0)
        {
            sprintf(str,"稀有材料%d",building.res_add.rarematerial);
            put_hz24_asc32(490+i*(80),440,str,0xA000,"HZK\\Hzk24k");
            i++;
        }
        if (building.res_add.water<0)
        {
            sprintf(str,"淡水%d",building.res_add.water);
            put_hz24_asc32(490+i*(80),440,str,0xA000,"HZK\\Hzk24k");
            i++;
        }



        if (building.res_add.energy>0)
        {
            sprintf(str,"能源%d",building.res_add.energy);
            put_hz24_asc32(490+j*(80),480,str,1000,"HZK\\Hzk24k");
            j++;
        }
        if (building.res_add.food>0)
        {
            sprintf(str,"食物%d",building.res_add.food);
            put_hz24_asc32(490+j*(80),480,str,1000,"HZK\\Hzk24k");
            j++;
        }
        if (building.res_add.fuel>0)
        {
            sprintf(str,"燃料%d",building.res_add.fuel);
            put_hz24_asc32(490+j*(80),480,str,1000,"HZK\\Hzk24k");
            j++;
        }
        if (building.res_add.mineral>0)
        {
            sprintf(str,"矿物%d",building.res_add.mineral);
            put_hz24_asc32(490+j*(80),480,str,1000,"HZK\\Hzk24k");
            j++;
        }
        if (building.res_add.nanomaterial>0)
        {
            sprintf(str,"纳米材料%d",building.res_add.nanomaterial);
            put_hz24_asc32(490+j*(80),480,str,1000,"HZK\\Hzk24k");
            j++;
        }
        if (building.res_add.oxygen>0)
        {
            sprintf(str,"氧气%d",building.res_add.oxygen);
            put_hz24_asc32(490+j*(80),480,str,1000,"HZK\\Hzk24k");
            j++;
        }
        if (building.res_add.rarematerial>0)
        {
            sprintf(str,"稀有材料%d",building.res_add.rarematerial);
            put_hz24_asc32(490+j*(80),480,str,1000,"HZK\\Hzk24k");
            j++;
        }
        if (building.res_add.water>0)
        {
            sprintf(str,"淡水%d",building.res_add.water);
            put_hz24_asc32(490+j*(80),480,str,1000,"HZK\\Hzk24k");
            j++;
        }

        //put_asc16_number_size(510,340,2,2,building.id,1);
    }
}

void load_check_mapbuild_toast(void)
{
    LoadBMP(390,290,810,710,0);
}
#include<ALLFUNS.h>


int proj_fun2(struct GameInfo* gameinfop,int *pxsel,int *pysel,WORKFILE *workfilep)
{
	int page=2;
	int l=65;
	int i;
	char *s[5]={"资源统计","资源预警","火箭信息","矿物勘测","家园概况"};
	draw_main_toolbotton_activate(392,0xFFAA,"全局","资源");
	
	
	draw_all_leftbuttons(5,65,s);
	
	//drawmous(MouseX,MouseY);
	
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if (judge_press_mainbutton(2,&page))
		{
			return page;
		}
		
		if (left_toolbotton_mouse_press(1) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all();
			draw_all_leftbuttons(5,65,s);
            draw_left_toolbotton_activate(95 , l, s[0]);//激活新的
            clear_right_all();
            proj_fun2_1(gameinfop);
            continue;
		}
		if (left_toolbotton_mouse_press(2) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
            clear_main_all();
			draw_all_leftbuttons(5,65,s);
            draw_left_toolbotton_activate2(95 , l, s[1],2);//激活新的
            clear_right_all();
            resource_warning(gameinfop);
            continue;
		}
		if (left_toolbotton_mouse_press(3) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
			clear_main_all();
            draw_left_toolbotton_activate(95 , l, s[2]);//激活新的
            clear_right_all();
            
            return rocket_info(gameinfop);;
		}
		if (left_toolbotton_mouse_press(4) == 1) //左栏被点中的情况
        {
            clrmous(MouseX,MouseY);
			clear_main_all();
            draw_left_toolbotton_activate(95 , l, s[3]);//激活新的
            clear_right_all();
            
			return map_exp(gameinfop,pxsel,pysel);;
		}
		if (left_toolbotton_mouse_press(5) == 1) //左栏被点中的情况
        {
			clrmous(MouseX,MouseY);
            clear_main_all();
			draw_all_leftbuttons(5,65,s);
            draw_left_toolbotton_activate2(95 , l, s[4],5);//激活新的
            clear_right_all();
            home_build_situation(gameinfop,workfilep->path);
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
	int data_in[8];
	int data_out[8];
	int data_cal[8];
	int data_peoplecost[8];
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
	
	calculate_monthly_income(gameinfop,data_in);
	calculate_monthly_outcome(gameinfop,data_out);
	people_cost(data_peoplecost,gameinfop);
	for (i=0;i<8;i++)
	{
		data_cal[i]=data_in[i]+data_out[i]+data_peoplecost[i];
	}
	puthz2(250, 110,48,48,1000,"资源统计：");
	puthz2(620, 130,32,32,1000,"月变化：");
	for (j=0;j<8;j++)
	{
		btn_bar_Draw(250,190+j*70,900,240+j*70);
		sprintf(str,"%s：",s[j]);
		puthz2(260,190+j*70,32,32,0xA000,str);
		sprintf(str,"%ld",data1[j]);
		put_hz16_asc16_size(450,190+j*70,2,2,str,800,"HZK\\HZ16");
		if (data_cal[j]>=0)
		{
			sprintf(str,"%d",data_cal[j]);
			put_hz16_asc16_size(700,190+j*70,2,2,str,1000,"HZK\\HZ16");
		}
		else
		{
			sprintf(str,"%d",data_cal[j]);
			put_hz16_asc16_size(700,190+j*70,2,2,str,0xA000,"HZK\\HZ16");
		}
	}
}

void resource_warning(struct GameInfo *gameinfop)
{
	char *s[8]={"纳米材料","稀有材料","氧气","淡水","食物","能源","燃料","矿物"};
	long int data1[8];
	int data_in[8];
	int data_out[8];
	int data_cal[8];
	int data_peoplecost[8];
	int cal_month;
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

	calculate_monthly_income(gameinfop,data_in);
	calculate_monthly_outcome(gameinfop,data_out);
	people_cost(data_peoplecost,gameinfop);
	for (i=0;i<8;i++)
	{
		data_cal[i]=data_in[i]+data_out[i]+data_peoplecost[i];
	}
	puthz2(250, 110,48,48,0xA000,"资源预警：");

	for (j=0;j<8;j++)
	{
		btn_bar_Draw(250,190+j*70,900,240+j*70);
		sprintf(str,"%s：",s[j]);
		puthz2(260,190+j*70,32,32,0xA000,str);
		if (data_cal[j]>=0)
		{
			puthz3(455,190+j*70,24,24,1000,"该资源很充裕");
			continue;
		}
		cal_month=abs(data1[j]/data_cal[j]);
		if (cal_month>60)
		{
			sprintf(str,"该资源将在%d个月后耗尽",cal_month);
			put_hz16_asc16_size(450,190+j*70,2,2,str,1000,"HZK\\HZ16");
			continue;
		}
		sprintf(str,"该资源将在%d个月后耗尽",cal_month);
		put_hz16_asc16_size(450,190+j*70,2,2,str,0xA000,"HZK\\HZ16");
	}
}

void home_build_situation(struct GameInfo *gameinfop,char *path)
{
	int happy=happiness_count(gameinfop);
	int maxpopulation=people_max(gameinfop,path);
	char str[40];
	int build_count=cal_map_building_num(gameinfop);
	calculate_monthly_happybuff(gameinfop,path);
	
	constrc_count(gameinfop,path);
	
	puthz2(250, 110,48,48,0xFA80,"家园概况");
	puthz3(250, 200,32,32,1000,"人口：");
	sprintf(str,"%d/%d",gameinfop->people,maxpopulation);
	put_hz16_asc16_size(500,200,2,2,str,1,"HZK\\HZ16");

	puthz3(250, 260,32,32,1000,"幸福度：");
	sprintf(str,"%d",happy);
	put_hz16_asc16_size(500,260,2,2,str,1,"HZK\\HZ16");

	puthz3(250, 320,32,32,1000,"家园建设值：");
	sprintf(str,"%d",gameinfop->construction);
	put_hz16_asc16_size(500,320,2,2,str,1,"HZK\\HZ16");

	puthz3(250, 380,32,32,1000,"已建成建筑数量：");
	sprintf(str,"%d",build_count);
	put_hz16_asc16_size(500,380,2,2,str,1,"HZK\\HZ16");

	puthz3(250, 440,32,32,1000,"家园介绍：");
	draw_buildpoint_txt(gameinfop->construction);
}

int cal_map_building_num(struct GameInfo *gameinfop)
{
	int i,j;
	int count=0;
	for (i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
		{
			if (gameinfop->m_info[i][j].building.id!=0&&gameinfop->m_info[i][j].building.bui_time==0)
			{
				count++;
			}
		}
	}
	return count;
}

void draw_buildpoint_txt(long int construction)
{
	if (construction<500)
	{
		puthz3(250, 500,32,32,1,"这只是一个小型火星基地");
	}
	else if (construction<1000)
	{
		puthz3(250, 500,32,32,1,"一个小型的火星家园");
	}
	else if (construction<2000)
	{
		puthz3(250, 500,32,32,1,"火星家园颇具规模");
	}
	else if (construction<3000)
	{
		puthz3(250, 500,32,32,1,"一个中型火星家园");
	}
	else
	{
		puthz3(250, 500,32,32,1,"一个大型的火星家园");
		puthz3(250, 540,32,32,1,"这是人类探索太空历史的奇迹");
	}
}
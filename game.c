#include "common.h"
#include "game.h"
#include "WRKMNG.h"
#include "fun3_2.h"
#include "fun3.h"
#include "fun5.h"
#include "fun4.h"
#include "SL.h"
/*
��Ŀ���Ļ�ҳ����
*/
int project(struct workfile w,int*page)
{
	int proj_page=0;
	char path[20]={'\0'};
	int i,j;
	int events[2]={0,0};
	int xsel=0;
	int ysel=0;
	struct GameInfo gameinfo;
	struct Resource res_earns;
	
	//��������
	nodebq *p1=load_node(w);;
	
	load_gminfo(w,&gameinfo);
	
	gameinfo.r_info.energy=10000;
	gameinfo.r_info.nanomaterial=10000;
	gameinfo.r_info.rarematerial=10000;
	gameinfo.r_info.oxygen=10000;
	gameinfo.r_info.water=10000;
	gameinfo.r_info.food=10000;
	gameinfo.r_info.fuel=10000;
	gameinfo.r_info.mineral=10000;
	
	gameinfo.year=2030;
	gameinfo.month=1;
	gameinfo.techpoint=200;
	gameinfo.gametech.research_flag=0;
	
	// //��ʼ����ͼ
	// for (i=0;i<7;i++)
	// {
	// 	for (j=0;j<7;j++)
	// 	{
	// 		gameinfo.m_info[i][j].building.id=0;
	// 		gameinfo.m_info[i][j].building.bui_time=0;
	// 		gameinfo.m_info[i][j].terrain=0;
	// 	}
	// }
	
	
	/*
	����Ԥ���ռ�ͨ���ļ���ȡ�������ʴ浵
	
	
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
				proj_page=proj_fun2(&gameinfo);
				break;
			case 3:
				proj_page=proj_fun3(&gameinfo,p1,&xsel,&ysel);
				break;
			case 4:
				proj_page=proj_fun4(&gameinfo);
				break;
			case 5:
				proj_page=proj_fun5(&gameinfo,p1,w,&events);
				break;
		}
	}
	return proj_page;
}



int proj_fun2(struct GameInfo* gameinfop)
{
	int page=2;
	int page2=0;
	int now=0;
	int flag=0;
	int l=65;
	int i;
	char *s[2]={"��Դͳ��","��Դ��֧"};
	draw_main_toolbotton_activate(392,0xFFAA,"ȫ��","��Դ");
	
	
	draw_all_leftbuttons(2,65,s);
	
	//drawmous(MouseX,MouseY);
	
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if(main_toolbotton_mouse_press(1)==1)//now==66��ֹ�������������ؼ������е������ͻ
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"ȫ��","��Դ");
            clear_main_all();
			clear_right_all();
            return 1;
            
        }
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"ȫ��","��Դ");
            clear_main_all();
			clear_right_all();
            return 2;

        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"ȫ��","��Դ");
            clear_main_all();
			clear_right_all();
            return 3;
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"ȫ��","��Դ");
            clear_main_all();
			clear_right_all();
            return 4;
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(392,0xFFAA,"ȫ��","��Դ");
            clear_main_all();
			clear_right_all();
            return 5;
        }
		
		if (left_toolbotton_mouse_press(1) == 1) //���������е����
        {
            clrmous(MouseX,MouseY);
            //clear_main_all();
            draw_left_toolbotton_activate(95 , l, s[0]);//�����µ�
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
	char *s[8]={"���ײ���","ϡ�в���","����","��ˮ","ʳ��","��Դ","ȼ��","����"};
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

	puthz(240, 110,"��Դͳ�ƣ�",48,48,1);
	puthz(600, 110,"��Դ����֧��",48,48,1);
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
	char *s1[5]={"��ͼ","ȫ��","����","�Ƽ�","ʱ��"};
	char *s2[5]={"��ʾ","��Դ","��ʾ","�о�","����"};
	unsigned color[5]={0xBD32,0xFFAA,0xBBBB,0xFF19,0xBDBD};
	
	if(main_toolbotton_mouse_press(1)==1)//now==66��ֹ�������������ؼ������е������ͻ
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


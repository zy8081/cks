#include "common.h"
#include "game.h"
#include "fun3.h"
#include "fun5.h"
#include "fun4.h"

/*
��Ŀ���Ļ�ҳ����
*/
int project(void)
{
	int proj_page=0;
	char path[20]={'\0'};
	int i,j;
	//��������
	nodebq *p1;
	struct GameInfo gameinfo;
	struct Resource res_earns;
	srand(time(NULL));
	gameinfo.r_info.energy=1000;
	gameinfo.r_info.nanomaterial=1000;
	gameinfo.r_info.rarematerial=100;
	gameinfo.r_info.oxygen=110;
	gameinfo.r_info.water=120;
	gameinfo.r_info.food=130;
	gameinfo.r_info.fuel=140;
	gameinfo.r_info.mineral=150;
	
	gameinfo.year=2030;
	gameinfo.month=1;
	gameinfo.techpoint=200;
	gameinfo.gametech.research_flag=0;
	
	//��ʼ����ͼ
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			gameinfo.m_info[i][j].building.id=0;
			gameinfo.m_info[i][j].building.bui_time=0;
			gameinfo.m_info[i][j].terrain=0;
		}
	}
	
	for (i=0;i<10;i++)
	{
		gameinfo.huge_engineering[i]=0;
	}
	/*
	����Ԥ���ռ�ͨ���ļ���ȡ�������ʴ浵
	
	
	*/
	
	p1=create_nodebq();
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
				proj_page=proj_fun1(&gameinfo);
				break;
			case 2:
				proj_page=proj_fun2(&gameinfo);
				break;
			case 3:
				proj_page=proj_fun3(&gameinfo,p1);
				break;
			case 4:
				proj_page=proj_fun4(&gameinfo);
				break;
			case 5:
				proj_page=proj_fun5(&gameinfo,p1);
				break;
		}
	}
	return proj_page;
}

int proj_fun1(struct GameInfo* gameinfop)
{
	int page1=1;
	int flag=0;
	int now=66; 
	int i;
	int l=65;
	char *s[2]={"�򿪵�ͼ","��û���"};
	draw_main_toolbotton_activate(234,0xBD32,"��ͼ","��ʾ");
	draw_all_leftbuttons(2,65,s);
	draw_map(300,105,954,759,7,7,gameinfop);
	
	while (1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		if(flag==1)
		{
			
		}
		//���ؼ�
		if(main_toolbotton_mouse_press(1)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(234,0xBD32,"��ͼ","��ʾ");
            clear_main_all();
			clear_right_all();
            return 1;
            
        }
        else if(main_toolbotton_mouse_press(2)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(234,0xBD32,"��ͼ","��ʾ");
            clear_main_all();
			clear_right_all();
            return 2;

        }
        else if(main_toolbotton_mouse_press(3)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(234,0xBD32,"��ͼ","��ʾ");
            clear_main_all();
			clear_right_all();
            return 3;
        }
        else if(main_toolbotton_mouse_press(4)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(234,0xBD32,"��ͼ","��ʾ");
            clear_main_all();
			clear_right_all();
            return 4;
        }
        else if(main_toolbotton_mouse_press(5)==1)
        {
            clrmous(MouseX,MouseY); 
            draw_main_toolbotton(234,0xBD32,"��ͼ","��ʾ");
            clear_main_all();
			clear_right_all();
            return 5;
        }
		//����
		for (i=0; i < 2; i++) 
        {
            if (left_toolbotton_mouse_press(i+1) == 1) //���������е����
            {
                clrmous(MouseX,MouseY); 
                draw_left_toolbotton(95 + (now)*l, l, s[now]);//��ԭ�ɵ�
                now = i;
                draw_left_toolbotton_activate(95 + i*l, l, s[i]);//�����µ�
                clear_right_all();
                
                flag=1;//������ת
            
                //draw_which_introduce(i);//ѡ��ǰ�Ľ���
                //draw_main_toolbotton_activate(234,0xBD32,"","");
                //draw_arrowbotton(295, 23);//�������ؼ�ͷ

                //mouse_on(mouse);
                continue;
            }
		}
	}
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
	draw_map(300,105,954,759,7,7,gameinfop);
	//drawmous(MouseX,MouseY);
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


//void judge_press_mainbutton(int flag,int *page)
//{
//	char *s1[5]={"��ͼ","ȫ��","����","�Ƽ�","ʱ��"};
//	char *s2[5]={"��ʾ","��Դ","��ʾ","�о�","����"};
//	
//	unsigned int color[5];
//	if(main_toolbotton_mouse_press(1)==1)//now==66��ֹ�������������ؼ������е������ͻ
//    {
//        clrmous(MouseX,MouseY); 
//        draw_main_toolbotton(550,0xBBBB,s1[flag-1],s2[flag-1]);
//        clear_main_all();
//		clear_right_all();
//		*page=1;
//		break;    
//    }
//    else if(main_toolbotton_mouse_press(2)==1)
//    {
//        clrmous(MouseX,MouseY); 
//        draw_main_toolbotton(550,0xBBBB,s1[flag-1],s2[flag-1]);
//        clear_main_all();	
//		clear_right_all();
//        *page=2;	
//		break; 
//    }
//    else if(main_toolbotton_mouse_press(3)==1)
//    {
//        clrmous(MouseX,MouseY); 
//        draw_main_toolbotton(550,0xBBBB,s1[flag-1],s2[flag-1]);
//        clear_main_all();
//		clear_right_all();
//        page=3;
//		break; 
//    }
//    else if(main_toolbotton_mouse_press(4)==1)
//    {
//        clrmous(MouseX,MouseY); 
//        draw_main_toolbotton(550,0xBBBB,s1[flag-1],s2[flag-1]);
//        clear_main_all();	
//		clear_right_all();
//        page=4;
//		break; 
//    }
//    else if(main_toolbotton_mouse_press(5)==1)
//    {
//        clrmous(MouseX,MouseY); 
//        draw_main_toolbotton(550,0xBBBB,s1[flag-1],s2[flag-1]);
//        clear_main_all();	
//		clear_right_all();
//        page=5;
//		break; 
//    }
//}
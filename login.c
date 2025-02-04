#include "common.h"
#include "draw.h"
#include "login.h"
#include "input.h"

void draw_login(void)
{
	bar(0,0,1024,768,0x7BEF);
	put_hz32(200,300,"ÕËºÅ",0xffff,"HZK\\Hzk32S",0);
	put_hz32(200,400,"ÃÜÂë",0xffff,"HZK\\HZK32S",0);
	//puthz(288,10,"µÇÂ¼",32,32,WHITE);
	
	//ÕËºÅ°×¿ò
	draw_button_fill(280,300,810,330,0xffff);
	//ÃÜÂë°×¿ò
	draw_button_fill(280,400,810,430,0xffff);
	
	draw_button_fill(250,500,400,550,0x6c00);
	put_hz24(301,513,"µÇÂ¼",0xffff,"HZK\\Hzk24h",1);
	
	put_hz24(420,513,"Î´×¢²áÇëÏÈ×¢²á",0xffff,"HZK\\Hzk24k",1);
	draw_button_fill(624,500,774,550,0x6c00);
	put_hz24(675,513,"×¢²á",0xffff,"HZK\\Hzk24h",1);
	
	
}

void draw_regist(void)
{
	bar(0,0,1024,768,0x7BEF);
	put_hz32(200,300,"ÕËºÅ",0xffff,"HZK\\Hzk32S",0);
	put_hz32(200,400,"ÃÜÂë",0xffff,"HZK\\HZK32S",0);
	//puthz(288,10,"µÇÂ¼",32,32,WHITE);
	
	//ÕËºÅ°×¿ò
	draw_button_fill(280,300,810,330,0xffff);
	//ÃÜÂë°×¿ò
	draw_button_fill(280,400,810,430,0xffff);
	
	draw_button_fill(250,500,400,550,0x6c00);
	put_hz24(301,513,"×¢²á",0xffff,"HZK\\Hzk24h",1);
	
	put_hz24(420,513,"ÒÑµÇÂ¼ÎŞĞè×¢²á",0xffff,"HZK\\Hzk24k",1);
	draw_button_fill(624,500,774,550,0x6c00);
	put_hz24(675,513,"µÇÂ¼",0xffff,"HZK\\Hzk24h",1);
}



int login(void)
{
	int page=1;
	char user[21]={'\0'},password[21]={'\0'};
	
	clrmous(MouseX,MouseY); 
	delay(300); 
	
	cleardevice();
	draw_login();
	
	while(page == 1)
	{ 
		mouse_renew(&MouseX,&MouseY,&press);
		//²âÊÔÓÃ
		if(mouse_press(1024-40, 0, 1024, 0+40) == 1) 
		{ 
			page = 0;
		} 
		
		//Êó±êÔÚÕËºÅ°×¿ò
		else if (mouse_press(280,300,810,330))
		{
			MouseS=2;
			if (mouse_press(280,300,810,330)==1)
			{
				input_vis(280 ,300 ,user);
			}
		}
		
		//Êó±êÔÚÃÜÂë°×¿ò
		else if (mouse_press(280,400,810,430))
		{
			MouseS=2;
			if (mouse_press(280,400,810,430)==1)      //Ô­À´180,230,510,255
			{
				input_vis(280,400 ,password);
			}
		}
		
		//µÇÂ¼¼ü	
		else if (mouse_press(250,500,400,550))
		{
			MouseS=1;
			if (mouse_press(250,500,400,550)==1)
			{
				
				if (judge_login(user,password))
				{
					page=3;
					break;
				}
			}
		}
		
		//×¢²á¼ü
		else if(mouse_press(624,500,774,550))
		{
			MouseS=1;
			if (mouse_press(624,500,774,550)==1)
			{
				page=2;
				break;				
			}
		}
	
		else
		{
			MouseS=1;
		}
		
	} 
	return page;
	
}

int regist(void)
{
	int page=2;
	char user[21]={'\0'},password[21]={'\0'};
	int flag=0;
	clrmous(MouseX,MouseY); 
	delay(300); 
	
	cleardevice();
	draw_regist();
	
	while(page == 2)
	{ 
		mouse_renew(&MouseX,&MouseY,&press);
		//²âÊÔÓÃ
		if(mouse_press(1024-40, 0, 1024, 0+40) == 1) 
		{ 
			page = 0;
		} 
		
		//Êó±êÔÚÕËºÅÇøÓò
		else if (mouse_press(280,300,810,330))
		{
			MouseS=2;
			if (mouse_press(280,300,810,330)==1)
			{
				input_vis(280 ,300 ,user);
			}
		}
		
		else if (mouse_press(280,400,810,430))
		{
			MouseS=2;
			if (mouse_press(280,400,810,430)==1)
			{
				input_vis(280 ,400 ,password);
			}
		}
		
		//"×¢²á"¼ü	
		else if (mouse_press(250,500,400,550))
		{
			MouseS=1;
			if (mouse_press(250,500,400,550)==1)
			{
				if (judge_regist(user,password))
				{
					page=1;
					break;
				}
			}
		}
		
		//"È¥µÇÂ¼"¼ü
		else if(mouse_press(624,500,774,550))
		{
			MouseS=1;
			if (mouse_press(624,500,774,550)==1)
			{
				page=1;
				break;
			}
		}
		//"·µ»Ø"¼ü
		else if(mouse_press(10,80,50,100))
		{
			MouseS=1;
			if (mouse_press(10,80,50,100)==1)
			{
				page=1;
				break;				
			}
		}
		else
		{
			MouseS=1;
		}
		
	} 
	return page;
	
}


int judge_regist(char *user,char *password)
{
	int i;
	char temp[50];
	FILE *file;
	
	if (user[0]=='\0' || password[0]=='\0')
	{
		draw_toast();
		put_hz24(400,300,"ÕËºÅ»òÃÜÂë²»ÄÜÎª¿Õ",0xF800,"HZK\\Hzk24h",0);
		delay(3000);
		clear_toast();
		return 0;
	}
	sprintf(temp,"./users/%s",user);
	file=fopen(temp,"r");
	if (file==NULL)
	{
		file=fopen(temp,"w");
		for (i=0;password[i]!='\0';i++)
		{
			fputc(password[i],file);
		}
		
		fclose(file);
		draw_toast();
		put_hz24(400,300,"×¢²á³É¹¦",0xF800,"HZK\\Hzk24h",0);
		delay(3000);
		clear_toast();
		return 1;
	}
	else
	{
		draw_toast();
		put_hz24(400,300,"ÕËºÅÒÑ´æÔÚ",0xF800,"HZK\\Hzk24h",0);
		delay(3000);
		clear_toast();
		fclose(file);
		return 0;
	}
}

int judge_login(char *user,char *password)
{
	int i;
	char temp[50];
	char c;
	FILE *file;
	sprintf(temp,"./users/%s",user);
	file=fopen(temp,"r");
	if (file==NULL)
	{
		draw_toast();
		put_hz32(400,300,"ÕËºÅ²»´æÔÚ",0xF800,"HZK\\HZK32S",1);
		delay(3000);
		clear_toast();
		fclose(file);
		return 0;
	}
	else
	{
		for (i=0;password[i]!='\0';i++)
		{
			c=fgetc(file);
			if (c!=password[i])
			{
				draw_toast();
				put_hz32(400,300,"ÃÜÂë´íÎó£¡",0xF800,"HZK\\HZK32S",1);
				delay(3000);
				clear_toast();
				fclose(file);
				return 0;
			}
		}
		if ((c=fgetc(file))!=-1)
		{
			draw_toast();
			put_hz32(400,300,"ÃÜÂë´íÎó£¡",0xF800,"HZK\\HZK32S",1);
			delay(3000);
			clear_toast();
			fclose(file);
			return 0;
		}
	}

	fclose(file);
	draw_toast();
	put_hz32(400,300,"µÇÂ½³É¹¦£¡",0xF800,"HZK\\HZK32S",1);
	delay(3000);
	clear_toast();
	return 1;
}
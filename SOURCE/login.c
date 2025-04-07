#include<ALLFUNS.h>

//用于画基本的图形界面（当前画面较为简陋）
//draw_button_fill()函数完全等效于bar，在draw.c
void draw_login(void)
{
	bar(0,0,1024,768,0x7BEF);
	put_hz32(432,200,"用户登录",0xffff,"HZK\\HZK32S",0);
	put_hz48(272,100,"火星家园建设规划系统",0xffff,"HZK\\Hzk48k",0);
	
	put_hz32(200,300,"账号",0xffff,"HZK\\HZK32S",0);
	put_hz32(200,400,"密码",0xffff,"HZK\\HZK32S",0);
	//puthz(288,10,"登录",32,32,WHITE);
	
	//账号白框
	draw_button_fill(280,300,810,330,0xffff);
	//密码白框
	draw_button_fill(280,400,810,430,0xffff);
	
	draw_button_fill(250,500,400,550,0x6c00);
	put_hz24(301,513,"登录",0xffff,"HZK\\Hzk24h",1);
	
	put_hz24(420,513,"未注册请先注册",0xffff,"HZK\\Hzk24k",1);
	draw_button_fill(624,500,774,550,0x6c00);
	put_hz24(663,513,"去注册",0xffff,"HZK\\Hzk24h",1);

}

void draw_regist(void)
{
	bar(0,0,1024,768,0x7BEF);
	put_hz32(432,200,"用户注册",0xffff,"HZK\\HZK32S",0);
	put_hz48(272,100,"火星家园建设规划系统",0xffff,"HZK\\Hzk48k",0);
	put_hz32(200,300,"账号",0xffff,"HZK\\HZK32S",0);
	put_hz32(200,400,"密码",0xffff,"HZK\\HZK32S",0);
	put_hz32(136,500,"确认密码",0xffff,"HZK\\HZK32S",0);
	bar(50,50,150,100,0x6c00);
	put_hz24(76,63,"返回",0xffff,"HZK\\Hzk24h",1);
	
	//账号白框
	draw_button_fill(280,300,810,330,0xffff);
	//密码白框
	draw_button_fill(280,400,810,430,0xffff);
	
	draw_button_fill(280,500,810,530,0xffff);
	
	draw_button_fill(250,600,400,650,0x6c00);
	put_hz24(301,613,"注册",0xffff,"HZK\\Hzk24h",1);
	
	put_hz24(420,613,"已登录无需注册",0xffff,"HZK\\Hzk24k",1);
	draw_button_fill(624,600,774,650,0x6c00);
	put_hz24(663,613,"去登录",0xffff,"HZK\\Hzk24h",1);
}


//此函数调用了input_vis，input_invis函数，出自input.c
//还调用了judge_login函数，在本文件后面
void login(int *page,char**puser)
{
	char user[21]={'\0'},password[21]={'\0'};
	
	

	clrmous(MouseX,MouseY); 
	delay(300); 
	
	cleardevice();
	draw_login();
	
	draw_closebutton();  //该函数出自draw.c，在右上角画一个叉，方便退出程序（调试用）
	rocket_prtall();
	
	while(1)
	{ 
		mouse_renew(&MouseX,&MouseY,&press);
		rocket_fun1();
		//测试用
		if(mouse_press(1024-40, 0, 1024, 0+40) == 1) 
		{ 
			*page = 3;
		} 
		
		//鼠标在账号白框
		if (mouse_press(280,300,810,330))
		{
			MouseS=2;  
			if (mouse_press(280,300,810,330)==1)
			{
				input_vis(280 ,300 ,user);
			}
		}
		
		//鼠标在密码白框
		else if (mouse_press(280,400,810,430))
		{
			MouseS=2;
			if (mouse_press(280,400,810,430)==1)      //原来180,230,510,255
			{
				input_invis(280,400 ,password);
			}
		}
		
		//登录键	
		else if (mouse_press(250,500,400,550))
		{
			MouseS=1;
			if (mouse_press(250,500,400,550)==1)
			{
				
				if (judge_login(user,password))
				{
					*page=0;
					strcpy(*puser,user);
					//bar(100,200,100,200,0);
					//getch();
					return;
				}
			}
		}
		
		//注册键
		else if(mouse_press(624,500,774,550))
		{
			MouseS=1;
			if (mouse_press(624,500,774,550)==1)
			{
				*page=5;
				return;				
			}
		}
	
		else
		{
			MouseS=1;
		}
		
	}

	
}



void regist(int *page)
{
	char user[21]={'\0'},password[21]={'\0'},confirm[21]={'\0'};
	
	clrmous(MouseX,MouseY); 
	delay(100); 
	
	cleardevice();
	draw_regist();
	draw_closebutton();  //该函数出自draw.c，在右上角画一个叉，方便退出程序（调试用）
	puthz(330,307,"请输入四到十个大小写字母或数字",16,20,1000);
	puthz(330,407,"请输入四到二十个大小写字母或数字",16,20,1000);
	while(1)
	{ 
		mouse_renew(&MouseX,&MouseY,&press);
		//测试用
		if(mouse_press(1024-40, 0, 1024, 0+40) == 1) 
		{ 
			*page = 3;
		}
		
		//鼠标在账号区域
		if (mouse_press(280,300,810,330))
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
				input_invis(280 ,400 ,password);
			}
		}
		
		else if (mouse_press(280,500,810,530))
		{
			MouseS=2;
			if (mouse_press(280,500,810,530)==1)
			{
				input_invis(280 ,500 ,confirm);
			}
		}
		
		//"注册"键	
		else if (mouse_press(250,600,400,650))
		{
			MouseS=1;
			if (mouse_press(250,600,400,650)==1)
			{
				if (judge_regist(user,password,confirm))
				{
					*page=4;
					return;
				}
			}
		}
		
		//"去登录"键
		else if(mouse_press(624,600,774,650))
		{
			MouseS=1;
			if (mouse_press(624,600,774,650)==1)
			{
				*page=4;
				return;
			}
		}
		//"返回"键
		else if(mouse_press(10,80,50,100))
		{
			MouseS=1;
			if (mouse_press(10,80,50,100)==1)
			{
				*page=4;
				return;				
			}
		}
		else
		{
			MouseS=1;
		}
		
	} 
}

//本函数调用draw_toast()函数，用于画弹窗，出自draw.c
int judge_regist(char *user,char *password,char *confirm)
{
	int i;
	char* temp1=malloc((size_t)50);
	char* temp2=malloc((size_t)50);
	FILE* uf;
	FILE* file;
	
	if (user[0]=='\0' || password[0]=='\0' || confirm[0]=='\0')
	{
		draw_toast();
		put_hz24(400,300,"账号或密码不能为空",0xF800,"HZK\\Hzk24h",0);
		delay(3000);
		clear_toast();
		return 0;
	}
	sprintf(temp1,"./users/%s",user);
	sprintf(temp2,"./WORKS/%s",user);
	if (access(temp1,0)!=0)
	{
		if (user[3]=='\0')
		{
			draw_toast();
			put_hz24(400,300,"账号过短",0xF800,"HZK\\Hzk24h",0);
			delay(3000);
			clear_toast();
			free(temp1);
			free(temp2);
			return 0;
		}
		if (password[3]=='\0')
		{
			draw_toast();
			put_hz24(400,300,"密码过短",0xF800,"HZK\\Hzk24h",0);
			delay(3000);
			clear_toast();
			free(temp1);
			free(temp2);
			return 0;
		}
		
		if (strcmp(password,confirm)==0)
		{
			
			mkdir(temp1);
			mkdir(temp2);
			sprintf(temp1,"./users/%s/password",user);
			sprintf(temp2,"./WORKS/%s/CONTENT.txt",user);
			file=fopen(temp1,"w");
			uf=fopen(temp2,"wt+");
			fputc('#',uf);
			for (i=0;password[i]!='\0';i++)
			{
				fputc(password[i],file);
			}
		
			fclose(file);
			fclose(uf);
			draw_toast();
			put_hz24(400,300,"注册成功",0xF800,"HZK\\Hzk24h",0);
			delay(3000);
			clear_toast();
			free(temp1);
			free(temp2);
			return 1;
		}
		else 
		{
			draw_toast();
			put_hz24(400,300,"确认密码不一致",0xF800,"HZK\\Hzk24h",0);
			delay(3000);
			clear_toast();
		}
		
	}
	else
	{
		draw_toast();
		put_hz24(400,300,"账号已存在",0xF800,"HZK\\Hzk24h",0);
		delay(3000);
		clear_toast();
		fclose(file);
		free(temp1);
		free(temp2);
		return 0;
	}
}

int judge_login(char *user,char *password)
{
	int i;
	char temp[50];
	char c;
	FILE *file;
	sprintf(temp,"users/%s/password",user);
	file=fopen(temp,"r");
	if (file==NULL)
	{
		draw_toast();
		put_hz32(400,300,"账号不存在",0xF800,"HZK\\HZK32S",1);
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
				put_hz32(400,300,"密码错误！",0xF800,"HZK\\HZK32S",1);
				delay(3000);
				clear_toast();
				fclose(file);
				return 0;
			}
		}
		if ((c=fgetc(file))!=-1)
		{
			draw_toast();
			put_hz32(400,300,"密码错误！",0xF800,"HZK\\HZK32S",1);
			delay(3000);
			clear_toast();
			fclose(file);
			return 0;
		}
	}

	fclose(file);
	draw_toast();
	put_hz32(400,300,"登陆成功！",0xF800,"HZK\\HZK32S",1);
	delay(3000);
	clear_toast();
	return 1;
}
#include <common.h>
#include <draw.h>
#include <input.h>
#include <login.h>
#include <ORDFUNS.h>
//用于画基本的图形界面（当前画面较为简陋）
//draw_button_fill()函数完全等效于bar，在draw.c
void draw_login(void)
{
	Readbmp64k(0,0,"PICTURE\\login.bmp");
	puthz2(432,200,32,36,0xFA80,"用户登录");
	puthz2(272,100,48,52,0xFA80,"火星家园建设规划系统");
	
	puthz2(200,300,32,34,0xFA80,"账号");
	puthz2(200,400,32,34,0xFA80,"密码");
	//账号白框
	draw_button_fill(280,300,810,330,0xffff);
	//密码白框
	draw_button_fill(280,400,810,430,0xffff);
	
	//0x6c00
	draw_button1(250,500,400,550,0x02C0,0x6c00);
	puthz2(301,513,24,24,0x7BEF,"登录");
	
	puthz2(420,513,24,24,0xffff,"未注册请先注册");
	draw_button1(624,500,774,550,0x02C0,0x6c00);
	puthz2(663,513,24,24,0x7BEF,"去注册");

	// draw_button1(624,500,774,550,0x8410,0xC618);
	// puthz2(663,513,24,24,0x7BEF,"去注册");

}

void draw_regist(void)
{
	//bar(0,0,1024,768,0x7BEF);
	Readbmp64k(0,0,"PICTURE\\login.bmp");
	puthz2(432,200,32,36,0xFA80,"用户注册");
	puthz2(272,100,48,52,0xFA80,"火星家园建设规划系统");
	puthz2(200,300,32,34,0xFA80,"账号");
	puthz2(200,400,32,34,0xFA80,"密码");
	puthz2(136,500,32,34,0xFA80,"确认密码");

	draw_button1(50,50,150,100,0x02C0,0x6c00);
	puthz2(76,63,24,24,0x7BEF,"返回");
	
	//账号白框
	draw_button_fill(280,300,810,330,0xffff);
	//密码白框
	draw_button_fill(280,400,810,430,0xffff);
	//确认密码白框
	draw_button_fill(280,500,810,530,0xffff);
	
	draw_button1(250,600,400,650,0x02C0,0x6c00);
	puthz2(301,613,24,24,0x7BEF,"注册");
	
	puthz2(420,613,24,24,0xffff,"已注册无需注册");
	
	draw_button1(624,600,774,650,0x02C0,0x6c00);
	puthz2(663,613,24,24,0x7BEF,"去登录");
}


//此函数调用了input_vis，input_invis函数，出自input.c
//还调用了judge_login函数，在本文件后面
int login(char *puser)
{
	int page=1;
	char user[21]={'\0'},password[21]={'\0'};
	int flag1=0;
	int flag2=0;
	clrmous(MouseX,MouseY); 
	delay(300); 
	
	draw_login();
	
	draw_closebutton();  //该函数出自draw.c，在右上角画一个叉，方便退出程序（调试用）
	
	while(page == 1)
	{ 
		mouse_renew(&MouseX,&MouseY,&press);

		//退出键
		if(mouse_press(1024-40, 0, 1024, 0+40) == 1) 
		{ 
			page = 0;
		} 
		
		//鼠标在账号白框
		if (mouse_press(280,300,810,330))
		{
			MouseS=2;
			if (mouse_press(280,300,810,330)==1)
			{
				input_vis(280 ,300 ,user,0);
			}
		}
		
		//鼠标在密码白框
		else if (mouse_press(280,400,810,430))
		{
			MouseS=2;
			if (mouse_press(280,400,810,430)==1)      //原来180,230,510,255
			{
				input_invis(280,400 ,password,0);
			}
		}
		else
		{
			MouseS=1;
		}
		
		//登录键	
		if (mouse_press(250,500,400,550))
		{
			MouseS=1;
			if (!flag1)
			{
				clrmous(MouseX,MouseY); 
				draw_button1_login_activate(250,500,400,550);
				puthz2(301,513,24,24,0xffff,"登录");
			}
			flag1=1;
			if (mouse_press(250,500,400,550)==1)
			{
				
				if (judge_login(user,password))
				{
					page=3;
					strcpy(puser,user);
					break;
				}
			}
		}
		else
		{
			if (flag1)
			{
				clrmous(MouseX,MouseY); 
				draw_button1(250,500,400,550,0x02C0,0x6c00);
				puthz2(301,513,24,24,0x7BEF,"登录");
				flag1=0;
			}
		}
		
		//注册键
		if(mouse_press(624,500,774,550))
		{
			MouseS=1;
			if (!flag2)
			{
				clrmous(MouseX,MouseY); 
				draw_button1_login_activate(624,500,774,550);
				puthz2(663,513,24,24,0xffff,"去注册");
			}
			flag2=1;
			if (mouse_press(624,500,774,550)==1)
			{
				page=2;
				break;				
			}
		}
	
		else
		{
			if (flag2)
			{
				clrmous(MouseX,MouseY); 
				draw_button1(624,500,774,550,0x02C0,0x6c00);
				puthz2(663,513,24,24,0x7BEF,"去注册");
				flag2=0;
			}
		}
		
	}
	
	return page;
	
}

void draw_button1_login_activate(int x1,int y1,int x2,int y2)
{
	line_thick(x1,y1,x2,y1,3,0x02C0);
    line_thick(x2,y1,x2,y2,3,0x02C0);
    line_thick(x2,y2,x1,y2,3,0x02C0);
    line_thick(x1,y2,x1,y1,3,0x02C0);
    bar(x1+2,y1+2,x2-2,y2-2,0x07E0);
}

void draw_login_toast(void)
{
	SaveBMP(390,290,634,478,0);
    clrmous(MouseX,MouseY);
    btn_bar_Draw(400,300,624,468);
}

int regist(void)
{
	int page=2;
	char user[21]={'\0'},password[21]={'\0'},confirm[21]={'\0'};
	int flag1=0;
	int flag2=0;
	int flag3=0;

	clrmous(MouseX,MouseY); 
	
	draw_regist();
	draw_closebutton();  //该函数出自draw.c，在右上角画一个叉，方便退出程序（调试用）
	puthz(330,307,"请输入四到八个大小写字母或数字",16,20,1000);
	puthz(330,407,"请输入四到二十个大小写字母或数字",16,20,1000);
	while (page == 2)
	{
		mouse_renew(&MouseX,&MouseY,&press);
		//测试用
		if(mouse_press(1024-40, 0, 1024, 0+40) == 1) 
		{ 
			page = 0;
		}
		
		//鼠标在账号区域
		else if (mouse_press(280,300,810,330))
		{
			MouseS=2;
			if (mouse_press(280,300,810,330)==1)
			{
				input_vis(280 ,300 ,user,1);
			}
		}
		
		else if (mouse_press(280,400,810,430))
		{
			MouseS=2;
			if (mouse_press(280,400,810,430)==1)
			{
				input_invis(280 ,400 ,password,1);
			}
		}
		
		else if (mouse_press(280,500,810,530))
		{
			MouseS=2;
			if (mouse_press(280,500,810,530)==1)
			{
				input_invis(280 ,500 ,confirm,0);
			}
		}
		else
		{
			MouseS=1;
		}
		
		//"注册"键	
		if (mouse_press(250,600,400,650))
		{
			MouseS=1;
			if(!flag1)
			{
				clrmous(MouseX,MouseY); 
				draw_button1_login_activate(250,600,400,650);
				puthz2(301,613,24,24,0xffff,"注册");
			}
			flag1=1;
			if (mouse_press(250,600,400,650)==1)
			{
				if (judge_regist(user,password,confirm))
				{
					page=1;
					break;
				}
			}
		}
		else
		{
			if (flag1==1)
			{
				clrmous(MouseX,MouseY); 
				draw_button1(250,600,400,650,0x02C0,0x6c00);
				puthz2(301,613,24,24,0x7BEF,"注册");
				flag1=0;
			}
		}
		//"去登录"键
		if(mouse_press(624,600,774,650))
		{
			MouseS=1;
			if(!flag2)
			{
				clrmous(MouseX,MouseY); 
				draw_button1_login_activate(624,600,774,650);
				puthz2(663,613,24,24,0xffff,"去登录");
			}
			flag2=1;
			if (mouse_press(624,600,774,650)==1)
			{
				page=1;
				break;
			}
		}
		else
		{
			if (flag2==1)
			{
				clrmous(MouseX,MouseY); 
				draw_button1(624,600,774,650,0x02C0,0x6c00);
				puthz2(663,613,24,24,0x7BEF,"去登录");
				flag2=0;
			}
		}
		//"返回"键
		if(mouse_press(50,50,150,100))
		{
			MouseS=1;
			if(!flag3)
			{
				clrmous(MouseX,MouseY); 
				draw_button1_login_activate(50,50,150,100);
				puthz2(76,63,24,24,0xffff,"返回");
			}
			flag3=1;
			if (mouse_press(50,50,150,100)==1)
			{
				page=1;
				break;				
			}
		}
		else
		{
			if (flag3==1)
			{
				clrmous(MouseX,MouseY); 
				draw_button1(50,50,150,100,0x02C0,0x6c00);
				puthz2(76,63,24,24,0x7BEF,"返回");
				flag3=0;
			}
		}
		
	} 
	return page;
}

//本函数调用draw_toast()函数，用于画弹窗，出自draw.c
int judge_regist(char *user,char *password,char *confirm)
{
	int i;
	char temp1[50];
	char temp2[50];

	FILE *file;
	FILE* uf;
	if (user[0]=='\0' || password[0]=='\0' || confirm[0]=='\0')
	{
		draw_login_toast();
		puthz(410,310,"账号或密码不能为空",24,24,0xA000);
		delay(1000);
		LoadBMP(390,290,634,478,0);
		return 0;
	}

	sprintf(temp1,"./users/%s",user);
	sprintf(temp2,"./WORKS/%s",user);
	if (access(temp1,0)!=0)
	{
		if (user[3]=='\0')
		{
			draw_login_toast();
			puthz(410,310,"账号过短",24,24,0xA000);
			delay(1000);
			LoadBMP(390,290,634,478,0);
			return 0;
		}
		if (password[3]=='\0')
		{
			draw_login_toast();
			puthz(410,310,"密码过短",24,24,0xA000);
			delay(1000);
			LoadBMP(390,290,634,478,0);
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
			draw_login_toast();
			puthz(400,300,"注册成功",32,32,0xA000);
			delay(1000);
			LoadBMP(390,290,634,478,0);
			return 1;
		}
		else 
		{
			draw_login_toast();
			puthz(410,310,"确认密码不一致",24,24,0xA000);
			delay(1000);
			LoadBMP(390,290,634,478,0);
			return 0;
		}
		
	}
	else
	{
		draw_login_toast();
		puthz(410,310,"账号已存在",24,24,0xA000);
		delay(1000);
		LoadBMP(390,290,634,478,0);
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
		draw_login_toast();
		puthz(410,310,"账号不存在",24,24,0xA000);
		delay(1000);
		LoadBMP(390,290,634,478,0);
		return 0;
	}
	else
	{
		for (i=0;password[i]!='\0';i++)
		{
			c=fgetc(file);
			if (c!=password[i])
			{
				draw_login_toast();
				puthz(410,310,"密码错误！",24,24,0xA000);
				delay(1000);
				LoadBMP(390,290,634,478,0);
				fclose(file);
				return 0;
			}
		}
		if ((c=fgetc(file))!=-1)
		{
			draw_login_toast();
			puthz(410,310,"密码错误！",24,24,0xA000);
			delay(1000);
			LoadBMP(390,290,634,478,0);
			fclose(file);
			return 0;
		}
	}

	fclose(file);
	draw_login_toast();
	puthz(410,310,"登陆成功！",32,32,0xA000);
	delay(1000);
	LoadBMP(390,290,634,478,0);
	return 1;
}
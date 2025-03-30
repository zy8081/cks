#include "common.h"
#include "draw.h"
#include "login.h"
#include "input.h"

//���ڻ�������ͼ�ν��棨��ǰ�����Ϊ��ª��
//draw_button_fill()������ȫ��Ч��bar����draw.c
void draw_login(void)
{
	bar(0,0,1024,768,0x7BEF);
	put_hz32(432,200,"�û���¼",0xffff,"HZK\\HZK32S",0);
	put_hz48(272,100,"���Ǽ�԰����滮ϵͳ",0xffff,"HZK\\Hzk48k",0);
	
	put_hz32(200,300,"�˺�",0xffff,"HZK\\HZK32S",0);
	put_hz32(200,400,"����",0xffff,"HZK\\HZK32S",0);
	//puthz(288,10,"��¼",32,32,WHITE);
	
	//�˺Ű׿�
	draw_button_fill(280,300,810,330,0xffff);
	//����׿�
	draw_button_fill(280,400,810,430,0xffff);
	
	draw_button_fill(250,500,400,550,0x6c00);
	put_hz24(301,513,"��¼",0xffff,"HZK\\Hzk24h",1);
	
	put_hz24(420,513,"δע������ע��",0xffff,"HZK\\Hzk24k",1);
	draw_button_fill(624,500,774,550,0x6c00);
	put_hz24(663,513,"ȥע��",0xffff,"HZK\\Hzk24h",1);

}

void draw_regist(void)
{
	bar(0,0,1024,768,0x7BEF);
	put_hz32(432,200,"�û�ע��",0xffff,"HZK\\HZK32S",0);
	put_hz48(272,100,"���Ǽ�԰����滮ϵͳ",0xffff,"HZK\\Hzk48k",0);
	put_hz32(200,300,"�˺�",0xffff,"HZK\\HZK32S",0);
	put_hz32(200,400,"����",0xffff,"HZK\\HZK32S",0);
	put_hz32(136,500,"ȷ������",0xffff,"HZK\\HZK32S",0);
	bar(50,50,150,100,0x6c00);
	put_hz24(76,63,"����",0xffff,"HZK\\Hzk24h",1);
	
	//�˺Ű׿�
	draw_button_fill(280,300,810,330,0xffff);
	//����׿�
	draw_button_fill(280,400,810,430,0xffff);
	
	draw_button_fill(280,500,810,530,0xffff);
	
	draw_button_fill(250,600,400,650,0x6c00);
	put_hz24(301,613,"ע��",0xffff,"HZK\\Hzk24h",1);
	
	put_hz24(420,613,"�ѵ�¼����ע��",0xffff,"HZK\\Hzk24k",1);
	draw_button_fill(624,600,774,650,0x6c00);
	put_hz24(663,613,"ȥ��¼",0xffff,"HZK\\Hzk24h",1);
}


//�˺���������input_vis��input_invis����������input.c
//��������judge_login�������ڱ��ļ�����
int login(void)
{
	int page=1;
	char user[21]={'\0'},password[21]={'\0'};
	
	clrmous(MouseX,MouseY); 
	delay(300); 
	
	cleardevice();
	draw_login();
	
	draw_closebutton();  //�ú�������draw.c�������Ͻǻ�һ���棬�����˳����򣨵����ã�
	
	while(page == 1)
	{ 
		mouse_renew(&MouseX,&MouseY,&press);
		//������
		if(mouse_press(1024-40, 0, 1024, 0+40) == 1) 
		{ 
			page = 0;
		} 
		
		//������˺Ű׿�
		else if (mouse_press(280,300,810,330))
		{
			MouseS=2;  
			if (mouse_press(280,300,810,330)==1)
			{
				input_vis(280 ,300 ,user);
			}
		}
		
		//���������׿�
		else if (mouse_press(280,400,810,430))
		{
			MouseS=2;
			if (mouse_press(280,400,810,430)==1)      //ԭ��180,230,510,255
			{
				input_invis(280,400 ,password);
			}
		}
		
		//��¼��	
		else if (mouse_press(250,500,400,550))
		{
			MouseS=1;
			if (mouse_press(250,500,400,550)==1)
			{
				
				if (judge_login(user,password))
				{
					page=5;
					break;
				}
			}
		}
		
		//ע���
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
	char user[21]={'\0'},password[21]={'\0'},confirm[21]={'\0'};
	
	clrmous(MouseX,MouseY); 
	delay(100); 
	
	cleardevice();
	draw_regist();
	draw_closebutton();  //�ú�������draw.c�������Ͻǻ�һ���棬�����˳����򣨵����ã�
	puthz(330,307,"�������ĵ�ʮ����Сд��ĸ������",16,20,1000);
	puthz(330,407,"�������ĵ���ʮ����Сд��ĸ������",16,20,1000);
	while(page == 2)
	{ 
		mouse_renew(&MouseX,&MouseY,&press);
		//������
		if(mouse_press(1024-40, 0, 1024, 0+40) == 1) 
		{ 
			page = 0;
		} 
		
		//������˺�����
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
		
		//"ע��"��	
		else if (mouse_press(250,600,400,650))
		{
			MouseS=1;
			if (mouse_press(250,600,400,650)==1)
			{
				if (judge_regist(user,password,confirm))
				{
					page=1;
					break;
				}
			}
		}
		
		//"ȥ��¼"��
		else if(mouse_press(624,600,774,650))
		{
			MouseS=1;
			if (mouse_press(624,600,774,650)==1)
			{
				page=1;
				break;
			}
		}
		//"����"��
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

//����������draw_toast()���������ڻ�����������draw.c
int judge_regist(char *user,char *password,char *confirm)
{
	int i;
	char temp[50];
	FILE *file;
	
	if (user[0]=='\0' || password[0]=='\0' || confirm[0]=='\0')
	{
		draw_toast();
		put_hz24(400,300,"�˺Ż����벻��Ϊ��",0xF800,"HZK\\Hzk24h",0);
		delay(3000);
		clear_toast();
		return 0;
	}
	sprintf(temp,"./users/%s",user);
	if (access(temp,0)!=0)
	{
		if (user[3]=='\0')
		{
			draw_toast();
			put_hz24(400,300,"�˺Ź���",0xF800,"HZK\\Hzk24h",0);
			delay(3000);
			clear_toast();
			return 0;
		}
		if (password[3]=='\0')
		{
			draw_toast();
			put_hz24(400,300,"�������",0xF800,"HZK\\Hzk24h",0);
			delay(3000);
			clear_toast();
			return 0;
		}
		
		if (strcmp(password,confirm)==0)
		{
			
			mkdir(temp);
			sprintf(temp,"./users/%s/password",user);
			file=fopen(temp,"w");
			for (i=0;password[i]!='\0';i++)
			{
				fputc(password[i],file);
			}
		
			fclose(file);
			draw_toast();
			put_hz24(400,300,"ע��ɹ�",0xF800,"HZK\\Hzk24h",0);
			delay(3000);
			clear_toast();
			return 1;
		}
		else 
		{
			draw_toast();
			put_hz24(400,300,"ȷ�����벻һ��",0xF800,"HZK\\Hzk24h",0);
			delay(3000);
			clear_toast();
		}
		
	}
	else
	{
		draw_toast();
		put_hz24(400,300,"�˺��Ѵ���",0xF800,"HZK\\Hzk24h",0);
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
	sprintf(temp,"users/%s/password",user);
	file=fopen(temp,"r");
	if (file==NULL)
	{
		draw_toast();
		put_hz32(400,300,"�˺Ų�����",0xF800,"HZK\\HZK32S",1);
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
				put_hz32(400,300,"�������",0xF800,"HZK\\HZK32S",1);
				delay(3000);
				clear_toast();
				fclose(file);
				return 0;
			}
		}
		if ((c=fgetc(file))!=-1)
		{
			draw_toast();
			put_hz32(400,300,"�������",0xF800,"HZK\\HZK32S",1);
			delay(3000);
			clear_toast();
			fclose(file);
			return 0;
		}
	}

	fclose(file);
	draw_toast();
	put_hz32(400,300,"��½�ɹ���",0xF800,"HZK\\HZK32S",1);
	delay(3000);
	clear_toast();
	return 1;
}
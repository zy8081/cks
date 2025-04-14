#include <common.h>
#include <draw.h>
#include <input.h>
#include <login.h>
#include <ORDFUNS.h>
//���ڻ�������ͼ�ν��棨��ǰ�����Ϊ��ª��
//draw_button_fill()������ȫ��Ч��bar����draw.c
void draw_login(void)
{
	Readbmp64k(0,0,"PICTURE\\login.bmp");
	puthz2(432,200,32,36,0xFA80,"�û���¼");
	puthz2(272,100,48,52,0xFA80,"���Ǽ�԰����滮ϵͳ");
	
	puthz2(200,300,32,34,0xFA80,"�˺�");
	puthz2(200,400,32,34,0xFA80,"����");
	//�˺Ű׿�
	draw_button_fill(280,300,810,330,0xffff);
	//����׿�
	draw_button_fill(280,400,810,430,0xffff);
	
	//0x6c00
	draw_button1(250,500,400,550,0x02C0,0x6c00);
	puthz2(301,513,24,24,0x7BEF,"��¼");
	
	puthz2(420,513,24,24,0xffff,"δע������ע��");
	draw_button1(624,500,774,550,0x02C0,0x6c00);
	puthz2(663,513,24,24,0x7BEF,"ȥע��");

	// draw_button1(624,500,774,550,0x8410,0xC618);
	// puthz2(663,513,24,24,0x7BEF,"ȥע��");

}

void draw_regist(void)
{
	//bar(0,0,1024,768,0x7BEF);
	Readbmp64k(0,0,"PICTURE\\login.bmp");
	puthz2(432,200,32,36,0xFA80,"�û�ע��");
	puthz2(272,100,48,52,0xFA80,"���Ǽ�԰����滮ϵͳ");
	puthz2(200,300,32,34,0xFA80,"�˺�");
	puthz2(200,400,32,34,0xFA80,"����");
	puthz2(136,500,32,34,0xFA80,"ȷ������");

	draw_button1(50,50,150,100,0x02C0,0x6c00);
	puthz2(76,63,24,24,0x7BEF,"����");
	
	//�˺Ű׿�
	draw_button_fill(280,300,810,330,0xffff);
	//����׿�
	draw_button_fill(280,400,810,430,0xffff);
	//ȷ������׿�
	draw_button_fill(280,500,810,530,0xffff);
	
	draw_button1(250,600,400,650,0x02C0,0x6c00);
	puthz2(301,613,24,24,0x7BEF,"ע��");
	
	puthz2(420,613,24,24,0xffff,"��ע������ע��");
	
	draw_button1(624,600,774,650,0x02C0,0x6c00);
	puthz2(663,613,24,24,0x7BEF,"ȥ��¼");
}


//�˺���������input_vis��input_invis����������input.c
//��������judge_login�������ڱ��ļ�����
int login(char *puser)
{
	int page=1;
	char user[21]={'\0'},password[21]={'\0'};
	int flag1=0;
	int flag2=0;
	clrmous(MouseX,MouseY); 
	delay(300); 
	
	draw_login();
	
	draw_closebutton();  //�ú�������draw.c�������Ͻǻ�һ���棬�����˳����򣨵����ã�
	
	while(page == 1)
	{ 
		mouse_renew(&MouseX,&MouseY,&press);

		//�˳���
		if(mouse_press(1024-40, 0, 1024, 0+40) == 1) 
		{ 
			page = 0;
		} 
		
		//������˺Ű׿�
		if (mouse_press(280,300,810,330))
		{
			MouseS=2;
			if (mouse_press(280,300,810,330)==1)
			{
				input_vis(280 ,300 ,user,0);
			}
		}
		
		//���������׿�
		else if (mouse_press(280,400,810,430))
		{
			MouseS=2;
			if (mouse_press(280,400,810,430)==1)      //ԭ��180,230,510,255
			{
				input_invis(280,400 ,password,0);
			}
		}
		else
		{
			MouseS=1;
		}
		
		//��¼��	
		if (mouse_press(250,500,400,550))
		{
			MouseS=1;
			if (!flag1)
			{
				clrmous(MouseX,MouseY); 
				draw_button1_login_activate(250,500,400,550);
				puthz2(301,513,24,24,0xffff,"��¼");
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
				puthz2(301,513,24,24,0x7BEF,"��¼");
				flag1=0;
			}
		}
		
		//ע���
		if(mouse_press(624,500,774,550))
		{
			MouseS=1;
			if (!flag2)
			{
				clrmous(MouseX,MouseY); 
				draw_button1_login_activate(624,500,774,550);
				puthz2(663,513,24,24,0xffff,"ȥע��");
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
				puthz2(663,513,24,24,0x7BEF,"ȥע��");
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
	draw_closebutton();  //�ú�������draw.c�������Ͻǻ�һ���棬�����˳����򣨵����ã�
	puthz(330,307,"�������ĵ��˸���Сд��ĸ������",16,20,1000);
	puthz(330,407,"�������ĵ���ʮ����Сд��ĸ������",16,20,1000);
	while (page == 2)
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
		
		//"ע��"��	
		if (mouse_press(250,600,400,650))
		{
			MouseS=1;
			if(!flag1)
			{
				clrmous(MouseX,MouseY); 
				draw_button1_login_activate(250,600,400,650);
				puthz2(301,613,24,24,0xffff,"ע��");
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
				puthz2(301,613,24,24,0x7BEF,"ע��");
				flag1=0;
			}
		}
		//"ȥ��¼"��
		if(mouse_press(624,600,774,650))
		{
			MouseS=1;
			if(!flag2)
			{
				clrmous(MouseX,MouseY); 
				draw_button1_login_activate(624,600,774,650);
				puthz2(663,613,24,24,0xffff,"ȥ��¼");
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
				puthz2(663,613,24,24,0x7BEF,"ȥ��¼");
				flag2=0;
			}
		}
		//"����"��
		if(mouse_press(50,50,150,100))
		{
			MouseS=1;
			if(!flag3)
			{
				clrmous(MouseX,MouseY); 
				draw_button1_login_activate(50,50,150,100);
				puthz2(76,63,24,24,0xffff,"����");
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
				puthz2(76,63,24,24,0x7BEF,"����");
				flag3=0;
			}
		}
		
	} 
	return page;
}

//����������draw_toast()���������ڻ�����������draw.c
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
		puthz(410,310,"�˺Ż����벻��Ϊ��",24,24,0xA000);
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
			puthz(410,310,"�˺Ź���",24,24,0xA000);
			delay(1000);
			LoadBMP(390,290,634,478,0);
			return 0;
		}
		if (password[3]=='\0')
		{
			draw_login_toast();
			puthz(410,310,"�������",24,24,0xA000);
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
			puthz(400,300,"ע��ɹ�",32,32,0xA000);
			delay(1000);
			LoadBMP(390,290,634,478,0);
			return 1;
		}
		else 
		{
			draw_login_toast();
			puthz(410,310,"ȷ�����벻һ��",24,24,0xA000);
			delay(1000);
			LoadBMP(390,290,634,478,0);
			return 0;
		}
		
	}
	else
	{
		draw_login_toast();
		puthz(410,310,"�˺��Ѵ���",24,24,0xA000);
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
		puthz(410,310,"�˺Ų�����",24,24,0xA000);
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
				puthz(410,310,"�������",24,24,0xA000);
				delay(1000);
				LoadBMP(390,290,634,478,0);
				fclose(file);
				return 0;
			}
		}
		if ((c=fgetc(file))!=-1)
		{
			draw_login_toast();
			puthz(410,310,"�������",24,24,0xA000);
			delay(1000);
			LoadBMP(390,290,634,478,0);
			fclose(file);
			return 0;
		}
	}

	fclose(file);
	draw_login_toast();
	puthz(410,310,"��½�ɹ���",32,32,0xA000);
	delay(1000);
	LoadBMP(390,290,634,478,0);
	return 1;
}
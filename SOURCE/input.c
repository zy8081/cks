#include <common.h>
#include <draw.h>
#include <input.h>
#include <login.h>
/*登录界面输入函数，输入的字符可见
相关函数调用：draw_toast() 用于画弹窗提示用户，出自draw.c 
pattern:0登录时使用，1注册时使用 
*/
void input_vis(int x ,int y ,char *content,int pattern )   
{
	int i=0;
	char key;
	int temp;
	static flag=0;
	for (i=0;content[i]!='\0';i++);
	clrmous(MouseX,MouseY);
	line_thick(x+10+i*12,y+6,x+10+i*12,y+20,2,0x7C00);

	if (i==0)
	{
		bar(330,307,700,323,0xffff);
	}
	
	
	while (1)
	{
		while (bioskey(1))
		{
			temp=bioskey(0);
		}	
		
		key=bioskey(0);
		if ((key>='A' && key<='Z') || (key>='a' && key<='z') || (key>='0' && key<='9'))
		{
			if (i<=7)
			{
				content[i]=key;
				content[i+1]='\0';
				//光标后移
				line_thick(x+10+i*12,y+6,x+10+i*12,y+20,2,0xffff);
				//画字符
				put_asc16_ch(x+10+i*12,y+6,key,0x7C00);
				line_thick(x+10+(i+1)*12,y+6,x+10+(i+1)*12,y+20,2,0x7C00);   
				
				i++;
			}
			else
			{
				draw_login_toast();
				puthz(410,310,"长度超过八！",24,24,0xA000);
				delay(1000);
				LoadBMP(390,290,634,478,0);
			}
			
			
		}
		//按下退格键
		else if (key==8)
		{
			if(content[0]!='\0')
			{
				content[i-1]='\0';
				line_thick(x+10+i*12,y+6,x+10+i*12,y+20,2,0xffff);
				bar(x+10+(i-1)*12,y+6,x+10+12+(i-1)*12,y+25,0xffff);  
				line_thick(x+10+(i-1)*12,y+6,x+10+(i-1)*12,y+20,2,0x7C00);   
				i--;
			}
		}
		
		else if (key==13)
		{ 
			line_thick(x+10+i*12,y+6,x+10+i*12,y+20,2,0xffff);
			break;
		}
		else
		{
			draw_login_toast();
			puthz(410,310,"请输入数字和字母",24,24,0xA000);
			delay(1000);
			LoadBMP(390,290,634,478,0);
		}			
			
		
	}
	if (pattern==1)
	{
		if (content[0]=='\0')
		{
			puthz(330,307,"请输入四到八个大小写字母或数字",16,20,1000);
		}
		else
		{
			if (strlen(content)<4)
			{
				SaveBMP(830,300,950,335,1);
				puthz(830,300,"账号过短！",24,24,0xA000);
				flag=1;
			}
			else
			{
				if (flag==1)
				{
					LoadBMP(830,300,950,335,1);
					flag=0;
				}
			}
		}	
	}
	

}

//注册输入函数：输入的字符不可见，用*号画出，返回值判断是否输入
void input_invis(int x ,int y ,char *content,int pattern)   
{
	int i=0;
	char key;
	int temp;
	static flag=0;
	for (i=0;content[i]!='\0';i++); 
	clrmous(MouseX,MouseY);
	line_thick(x+10+i*12,y+6,x+10+i*12,y+20,2,0x7C00);
	
	if (i==0 && pattern==1)
	{
		bar(330,407,700,423,0xffff);
	}
	
	while (1)
	{
		while (bioskey(1))
		{
			temp=bioskey(0);
		}	
		
		key=bioskey(0);
		if ((key>='A' && key<='Z') || (key>='a' && key<='z') || (key>='0' && key<='9'))
		{
			if (i<=19)
			{
				content[i]=key;
				content[i+1]='\0';
				if (i==0)
				{
					line_thick(x+10+i*12,y+6,x+10+i*12,y+20,2,0xffff);
					put_asc16_ch(x+10+i*12,y+6,key,0x7C00);
					line_thick(x+10+(i+1)*12,y+6,x+10+(i+1)*12,y+20,2,0x7C00); 
				}
				else
				{
					line_thick(x+10+i*12,y+6,x+10+i*12,y+20,2,0xffff);
					put_asc16_ch(x+10+i*12,y+6,key,0x7C00);
					bar(x+10+(i-1)*12,y+6,x+10+12+(i-1)*12,y+25,0xffff);
					put_asc16_ch(x+10+(i-1)*12,y+6,'*',0x7C00);
					line_thick(x+10+(i+1)*12,y+6,x+10+(i+1)*12,y+20,2,0x7C00);   
				}
				i++;
				
			}
			else
			{
				draw_login_toast();
				puthz(410,310,"长度超过二十！",24,24,0xA000);
				delay(1000);
				LoadBMP(390,290,634,478,0);
			}
		}
		else if (key==8)
		{
			if(content[0]!='\0')
			{
				content[i-1]='\0';
				line_thick(x+10+i*12,y+6,x+10+i*12,y+20,2,0xffff);
				bar(x+10+(i-1)*12,y+6,x+10+12+(i-1)*12,y+25,0xffff);
				line_thick(x+10+(i-1)*12,y+6,x+10+(i-1)*12,y+20,2,0x7C00);   
				i--;
			}
		}
		
		else if (key==13)
		{
			if (content[0]=='\0')
			{
				line_thick(x+10+i*12,y+6,x+10+i*12,y+20,2,0xffff);
				break;
			}
			else
			{
				line_thick(x+10+i*12,y+6,x+10+i*12,y+20,2,0xffff);
				bar(x+10+(i-1)*12,y+6,x+10+12+(i-1)*12,y+25,0xffff);
				put_asc16_ch(x+10+(i-1)*12,y+6,'*',0x7C00);
				break;
			}
			
		}
		else
		{
			draw_login_toast();
			puthz(400,300,"请输入数字和字母",24,24,0xA000);
			delay(1000);
			LoadBMP(390,290,634,478,0);
		}			
			
		
	}
	
	if (pattern==1)
	{
		if (content[0]=='\0')
		{
			puthz(330,407,"请输入四到二十个大小写字母或数字",16,20,1000);
		}
		else 
		{
			if (strlen(content)<4)
			{
				SaveBMP(830,400,950,435,2);
				puthz(830,400,"密码过短！",24,24,0xA000);
				flag=1;
			}
			else
			{
				if (flag==1)
				{
					LoadBMP(830,400,950,435,2);
					flag=0;
				}
			}
		}
	}
	
}
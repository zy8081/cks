#include "common.h"
#include "draw.h"
#include "input.h"

/*��¼�������뺯����������ַ��ɼ�
��غ������ã�draw_toast() ���ڻ�������ʾ�û�������draw.c  */
void input_vis(int x ,int y ,char *content )   
{
	int i=0;
	int temp;
	char key;
	
	for (i=0;content[i]!='\0';i++);
	 
	line(x+10+i*12,y+6,x+10+i*12,y+20,0x7C00);

	clrmous(MouseX,MouseY);
	if (i==0)
	{
		bar(330,307,700,323,0xffff);
	}
	
	bar(830,300,950,335,0x7BEF);
	while (1)
	{
		while (bioskey(1))
		{
			temp=bioskey(0);
		}	
		
		key=bioskey(0);
		if ((key>='A' && key<='Z') || (key>='a' && key<='z') || (key>='0' && key<='9'))
		{
			if (i<=9)
			{
				content[i]=key;
				content[i+1]='\0';
				//������
				line(x+10+i*12,y+6,x+10+i*12,y+20,0xffff);
				//���ַ�
				put_asc16_ch(x+10+i*12,y+6,key,0x7C00);
				line(x+10+(i+1)*12,y+6,x+10+(i+1)*12,y+20,0x7C00);   
				
				i++;
			}
			else
			{
				draw_toast();
				put_hz24(400,300,"���ȳ���ʮ��",0xF800,"HZK\\Hzk24h",0);
				delay(1000);
				clear_toast();  
			}
			
			
		}
		//�����˸��
		else if (key==8)
		{
			if(content[0]!='\0')
			{
				content[i-1]='\0';
				line(x+10+i*12,y+6,x+10+i*12,y+20,0xffff);
				bar(x+10+(i-1)*12,y+6,x+10+12+(i-1)*12,y+25,0xffff);  
				line(x+10+(i-1)*12,y+6,x+10+(i-1)*12,y+20,0x7C00);   
				i--;
			}
		}
		
		else if (key==13)
		{ 
			line(x+10+i*12,y+6,x+10+i*12,y+20,0xffff);
			break;
		}
		else
		{
			draw_toast();
			put_hz24(400,300,"���������ֺ���ĸ",0xF800,"HZK\\Hzk24h",0);
			delay(1000);
			clear_toast();
		}			
			
		
	}
	if (content[0]=='\0')
	{
		puthz(330,307,"�������ĵ�ʮ����Сд��ĸ������",16,20,1000);
	}
	else 
	{
		if (strlen(content)<4)
		{
			puthz(830,300,"�˺Ź��̣�",24,24,0xA000);
		}
	}	
}

//ע�����뺯����������ַ����ɼ�����*�Ż���������ֵ�ж��Ƿ�����
void input_invis(int x ,int y ,char *content)   
{
	int i=0;
	int temp;
	char key;
	
	for (i=0;content[i]!='\0';i++); 
	line(x+10+i*12,y+6,x+10+i*12,y+20,0x7C00);
	clrmous(MouseX,MouseY);
	if (i==0)
	{
		bar(330,407,700,423,0xffff);
	}
	bar(830,400,950,435,0x7BEF);
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
					line(x+10+i*12,y+6,x+10+i*12,y+20,0xffff);
					put_asc16_ch(x+10+i*12,y+6,key,0x7C00);
					line(x+10+(i+1)*12,y+6,x+10+(i+1)*12,y+20,0x7C00); 
				}
				else
				{
					line(x+10+i*12,y+6,x+10+i*12,y+20,0xffff);
					put_asc16_ch(x+10+i*12,y+6,key,0x7C00);
					bar(x+10+(i-1)*12,y+6,x+10+12+(i-1)*12,y+25,0xffff);
					put_asc16_ch(x+10+(i-1)*12,y+6,'*',0x7C00);
					line(x+10+(i+1)*12,y+6,x+10+(i+1)*12,y+20,0x7C00);   
				}
				i++;
				
			}
			else
			{
				draw_toast();
				put_hz24(400,300,"���ȳ�����ʮ��",0xF800,"HZK\\Hzk24h",0);
				delay(2000);
				clear_toast();
			}
		}
		else if (key==8)
		{
			if(content[0]!='\0')
			{
				content[i-1]='\0';
				line(x+10+i*12,y+6,x+10+i*12,y+20,0xffff);
				bar(x+10+(i-1)*12,y+6,x+10+12+(i-1)*12,y+25,0xffff);
				line(x+10+(i-1)*12,y+6,x+10+(i-1)*12,y+20,0x7C00);   
				i--;
			}
		}
		
		else if (key==13)
		{
			if (content[0]=='\0')
			{
				line(x+10+i*12,y+6,x+10+i*12,y+20,0xffff);
				break;
			}
			else
			{
				line(x+10+i*12,y+6,x+10+i*12,y+20,0xffff);
				bar(x+10+(i-1)*12,y+6,x+10+12+(i-1)*12,y+25,0xffff);
				put_asc16_ch(x+10+(i-1)*12,y+6,'*',0x7C00);
				break;
			}
			
		}
		else
		{
			draw_toast();
			put_hz24(400,300,"���������ֺ���ĸ",0xF800,"HZK\\Hzk24h",0);
			delay(2000);
			clear_toast();
		}			
			
		
	}
	
	if (content[0]=='\0')
	{
		puthz(330,407,"�������ĵ�ʮ����Сд��ĸ������",16,20,1000);
	}
	else 
	{
		if (strlen(content)<4)
		{
			puthz(830,400,"������̣�",24,24,0xA000);
		}
		return 0;
	}
}
#include<ALLFUNS.h>

void btn_bar_Draw(int x1,int y1,int x2,int y2)
{
    line_thick(x1,y1,x2,y1,3,0);
    line_thick(x2,y1,x2,y2,3,0);
    line_thick(x2,y2,x1,y2,3,0);
    line_thick(x1,y2,x1,y1,3,0);
    line_thick(x1+3,y1+3,x2-3,y1+3,2,57083);
    line_thick(x2-3,y1+3,x2-3,y2-3,2,57083);
    line_thick(x2-3,y2-3,x1+3,y2-3,2,33808);
    line_thick(x1+3,y2-3,x1+3,y1+3,2,33808);
    bar(x1+5,y1+4,x2-5,y2-5,44373);

}

void btn_bar_Draw0(int x1,int y1,int x2,int y2)
{
    line_thick(x1,y1,x2,y1,3,65535);
    line_thick(x2,y1,x2,y2,3,65535);
    line_thick(x2,y2,x1,y2,3,65535);
    line_thick(x1,y2,x1,y1,3,65535);
    line_thick(x1+3,y1+3,x2-3,y1+3,2,57083);
    line_thick(x2-3,y1+3,x2-3,y2-3,2,57083);
    line_thick(x2-3,y2-3,x1+3,y2-3,2,33808);
    line_thick(x1+3,y2-3,x1+3,y1+3,2,33808);
    bar(x1+5,y1+4,x2-5,y2-5,44373);
}


void btn_bar_Draw1(int x1,int y1,int x2,int y2)
{
    line_thick(x1,y1,x2,y1,3,0);
    line_thick(x2,y1,x2,y2,3,0);
    line_thick(x2,y2,x1,y2,3,0);
    line_thick(x1,y2,x1,y1,3,0);
    bar(x1+2,y1+2,x2-2,y2-2,27469);
}



void menuprt(int x1,int y1,int x2,int y2)
{
    bar(x1,y1,x2,y2,27469);
}

void inputs(int x ,int y ,char *content,int n)     
{
	int i=0;
    int time;
	int temp;
	char key;
	
	//for (i=0;content[i]!='\0';i++);
	 
	line(x+10+i*12,y+6,x+10+i*12,y+20,65535);

	clrmous(MouseX,MouseY);
	
	while (1)
	{
        line(x+10+i*12,y+6,x+10+i*12,y+20,65535);
		while (bioskey(1))
		{
			temp=bioskey(0);
		}	
		
		key=bioskey(0);
		if ((key>='A' && key<='Z') || (key>='a' && key<='z') || (key>='0' && key<='9'))
		{
			if (i<=n)
			{
				content[i]=key;
				content[i+1]='\0';
				//光标后移
				line(x+10+i*12,y+6,x+10+i*12,y+20,0);
				//画字符
				put_asc16_ch(x+10+i*12,y+6,key,65535);
				line(x+10+(i+1)*12,y+6,x+10+(i+1)*12,y+20,65535);   
				i++;
			}
			else
			{
				//draw_toast();
				//put_hz24(400,300,"长度超过二十！",0xF800,"HZK\\Hzk24h");
				//delay(2000);
				//clear_toast();  
			}
			
			
		}
		//按下退格键
		else if (key==8)
		{
			if(content[0]!='\0')
			{
				content[i-1]='\0';
				line(x+10+i*12,y+6,x+10+i*12,y+20,0);
				bar(x+10+(i-1)*12,y+6,x+10+12+(i-1)*12,y+25,0);  
				line(x+10+(i-1)*12,y+6,x+10+(i-1)*12,y+20,65535);   
				i--;
			}
		}
		
		else if (key==13)
		{ 
			line(x+10+i*12,y+6,x+10+i*12,y+20,0);
			break;
		}
		/*
		{
			draw_toast();
			//put_hz24(400,300,"请输入数字和字母",0xF800,"HZK\\Hzk24h");
			delay(2000);
			clear_toast();
		}
        line(x+10+i*12,y+6,x+10+i*12,y+20,0);	*/			
	}
	//delay(100);		
}


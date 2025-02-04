#include "common.h"
#include "draw.h"
#include "input.h"

void input_vis(int x ,int y ,char *content )   
{
	int i=0;
	char str[5];
	int temp;
	char key;
	
	for (i=0;content[i]!='\0';i++);
	 
	line(x+10+i*12,y+6,x+10+i*12,y+20,0x7C00);

	clrmous(MouseX,MouseY);
	
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
				str[0]=key;
				
				//光标后移
				 
				line(x+10+i*12,y+6,x+10+i*12,y+20,0xffff);
				//setcolor(BLUE);
				//outtextxy(x+10+i*12,y,str);
				put_asc16_ch(x+10+i*12,y,str[0],0x7C00);
				//setcolor(RED);   
				line(x+10+(i+1)*12,y+6,x+10+(i+1)*12,y+20,0x7C00);   
				
				i++;
			}
			else
			{
				draw_toast();
				delay(2000);
				clear_toast();
			}
			
			
		}
		else if (key==8)
		{
			if(content[0]!='\0')
			{
				content[i-1]='\0';
				//setcolor(WHITE); 
				line(x+10+i*12,y+6,x+10+i*12,y+20,0xffff);
				//setfillstyle(SOLID_FILL,WHITE);
				bar(x+10+(i-1)*12,y,x+10+12+(i-1)*12,y+25,0xffff);
				//setcolor(RED);   
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
			delay(2000);
			clear_toast();
		}			
			
		
	}
	delay(100);
				
}

//oid input_invis(int x ,int y ,char *content )   
//
//	int i=0;
//	char str[5];
//	int temp;
//	char key;
//	
//	for (i=0;content[i]!='\0';i++);
//	setcolor(RED); 
//	line(x+10+i*12,y+6,x+10+i*12,y+20);
//	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
//	clrmous(MouseX,MouseY);
//	
//	while (1)
//	{
//		while (bioskey(1))
//		{
//			temp=bioskey(0);
//		}	
//		
//		key=bioskey(0);
//		if ((key>='A' && key<='Z') || (key>='a' && key<='z') || (key>='0' && key<='9'))
//		{
//			if (i<=19)
//			{
//				content[i]=key;
//				content[i+1]='\0';
//				str[0]=key;
//				
//				//光标后移
//				setcolor(WHITE); 
//				line(x+10+i*12,y+6,x+10+i*12,y+20);
//				setcolor(BLUE);
//				outtextxy(x+10+i*12,y,str);
//				setcolor(RED);   
//				line(x+10+(i+1)*12,y+6,x+10+(i+1)*12,y+20);   
//				
//				i++;
//			}
//			else
//			{
//				draw_toast();
//				delay(2000);
//				clear_toast();
//			}
//			
//			
//		}
//		else if (key==8)
//		{
//			if(content[0]!='\0')
//			{
//				content[i-1]='\0';
//				setcolor(WHITE); 
//				line(x+10+i*12,y+6,x+10+i*12,y+20);
//				setfillstyle(SOLID_FILL,WHITE);
//				bar(x+10+(i-1)*12,y,x+10+12+(i-1)*12,y+25);
//				setcolor(RED);   
//				line(x+10+(i-1)*12,y+6,x+10+(i-1)*12,y+20);   
//				i--;
//			}
//		}
//		
//		else if (key==13)
//		{
//			setcolor(WHITE); 
//			line(190+i*12,176,190+i*12,190);
//			break;
//		}
//		else
//		{
//			draw_toast();
//			delay(2000);
//			clear_toast();
//		}			
//			
//		
//	}
//	delay(100);
//				
//
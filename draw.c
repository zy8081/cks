#include "common.h"
#include "draw.h"
void *buffer;
void *dialog_buffer;

void draw_closebutton(void)
{
	bar(1024-40, 0, 1024, 0+40,0x7C00);
	line(1024-40,0, 768, 0+40,1);
	line(1024-40,0+40,1024,0,1);
}


void draw_button_fill(int x1,int y1,int x2,int y2,unsigned int color)
{
	bar(x1,y1,x2,y2,color);
}

void draw_button_frame(int x1,int y1,int x2,int y2,unsigned int color)
{
	bar_frame(x1,y1,x2,y2,color);
}

void draw_toast(void)
{
	//int i,j;
	//for (i = 0; i < 168; i++)
	//{
	//	for (j = 0; j < 224; j++)
	//	{
	//		
	//		background[i][j] = Getpixel64k(j + 400, i + 300);  
	//	}
	//}
	SaveBMP(400,300,624,468,0);
	bar(400,300,624,468,0xFFE0);
	bar_frame(400,300,624,468,0xffff);
}

void clear_toast(void)
{
	LoadBMP(400,300,624,468,0);
}

//void draw_dialog(int flag)
//{
//	int size;
//	if (flag)
//	{
//		size=imagesize(150,140,490,340);
//		dialog_buffer=malloc(size);
//		getimage(150,140,490,340,dialog_buffer);
//	}
//	
//	setfillstyle(SOLID_FILL,YELLOW);
//	bar(150,140,490,340);
//	setcolor(WHITE);
//	rectangle(150,140,490,340);
//	
//	setfillstyle(SOLID_FILL,RED);
//	bar(430,300,480,330);
//	puthz(430,300,"ак╫Б",16,16,WHITE);
//}
//
//void dialog_last(void)
//{
//	setfillstyle(SOLID_FILL,LIGHTRED);
//	bar(160,300,200,330);
//	outtextxy(160,300,"<--");
//}
//void dialog_next(void)
//{
//	setfillstyle(SOLID_FILL,LIGHTRED);
//	bar(210,300,250,330);
//	outtextxy(210,300,"-->");
//}
//
//
//
//void clear_dialog(void)
//{
//	putimage(150,140,dialog_buffer,COPY_PUT);
//	free(dialog_buffer);
//}
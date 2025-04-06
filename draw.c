#include "common.h"
#include "game.h"
#include "fun3_2.h"
#include "fun3.h"
#include "WRKMNG.h"
#include "fun5.h"
#include "fun4.h"
//本文件功能：一些较为基础的画图函数

//方便程序退出的按钮（调试用）
void draw_closebutton(void)
{
	bar(1024-40, 0, 1024, 0+40,0x7C00);
	line(1024-40,0, 1024, 0+40,1);
	line(1024-40,0+40,1024,0,1);
}

//替代用的函数，可用可不用
void draw_button_fill(int x1,int y1,int x2,int y2,unsigned int color)
{
	bar(x1,y1,x2,y2,color);
}

void draw_button_frame(int x1,int y1,int x2,int y2,unsigned int color)
{
	bar_frame(x1,y1,x2,y2,color);
}

//把背景保存在本地saves文件夹，然后画出一个固定大小的小弹窗
void draw_toast(void)
{
	SaveBMP(400,300,624,468,0);
	bar(400,300,624,468,0xFFE0);
	bar_frame(400,300,624,468,0xffff);
}

//用原背景覆盖弹窗
void clear_toast(void)
{ 
	LoadBMP(400,300,624,468,0);
}


void draw_dialog(int x1,int y1,int x2,int y2,unsigned int color_fill,unsigned int color_frame)
{
	SaveBMP(x1,y1,x2,y2,0);
	bar(x1,y1,x2,y2,color_fill);
	bar_frame(x1,y1,x2,y2,color_frame);
}


void clear_dialog(int x1,int y1,int x2,int y2)
{
	LoadBMP(x1,y1,x2,y2,0);
}

void draw_left_toolbotton(int y,int length,char*s)
{
	bar(0,y+1,232,y+length-1,0xFFFFBB);
	line_thick(0,y,33,y, 1, 0xBD32 );
	line_thick(0,y+length,33,y+length, 1, 0xBD32 );
	line_thick(43,y,60,y, 1, 0xBD32 );
	line_thick(43,y+length,60,y+length, 1, 0xBD32 );
	line_thick(70,y,220,y, 1, 0xBD32 );
	line_thick(70,y+length,220,y+length, 1, 0xBD32 );
	puthz(43,y+length/2-15,s, 32,50, 0x000000);
}

void draw_main_toolbotton(int x,int color,char*s1,char*s2)
{
	bar(x,0,x+158,90,0xFFFFFF);
	line_thick(x,91,x+158,91, 1, 0x000000 );
	line_thick(x, 0,x,89, 1, 0xBD32 );
	line_thick(x+158,0,x+158,89, 1, 0xBD32 );
	line_thick(x+8,95,x+150,95, 2, color );

	puthz(x+41,7,s1, 32,40, 0x000000);
	puthz(x+41,9,s1, 32,40, 0x000000); 
	puthz(x+43,7,s1, 32,40, 0x000000); 
	puthz(x+43,9,s1, 32,40, 0x000000); 
	puthz(x+42,8,s1, 32,40, color); 

	puthz(x+41,48,s2, 32,40, 0x000000);
	puthz(x+41,50,s2, 32,40, 0x000000);
	puthz(x+43,48,s2, 32,40, 0x000000);
	puthz(x+43,50,s2, 32,40, 0x000000);
	puthz(x+42,49,s2, 32,40, color);
}

void puthz2(int x,int y,int flag,int part,int color,char*s1)
{
	puthz(x,y,s1, flag,part, 0x000000);
	puthz(x,y+2,s1, flag,part, 0x000000); 
	puthz(x+2,y,s1, flag,part, 0x000000); 
	puthz(x+2,y+2,s1, flag,part, 0x000000); 
	puthz(x+1,y+1,s1, flag,part, color); 
}


void draw_button1(int x1,int y1,int x2,int y2,int colorf,int colorb)
{
	line_thick(x1,y1,x2,y1,3,colorf);
    line_thick(x2,y1,x2,y2,3,colorf);
    line_thick(x2,y2,x1,y2,3,colorf);
    line_thick(x1,y2,x1,y1,3,colorf);
    bar(x1+2,y1+2,x2-2,y2-2,colorb);
}

void draw_main_toolbotton_activate(int x,int color,char*s1,char*s2)
{
	bar(x+1,0,x+157,93,color);
	line_thick(x, 0,x,87, 1, 0x000000 );
	line_thick(x+158,0,x+158,87, 1, 0x000000 );
	line_thick(x+8,95,x+150,95, 2, color );

	puthz(x+41,7,s1, 32,40, 0xFFFFFF);
	puthz(x+41,9,s1, 32,40, 0xFFFFFF);
	puthz(x+43,7,s1, 32,40, 0xFFFFFF); 
	puthz(x+43,9,s1, 32,40, 0xFFFFFF); 
	puthz(x+42,8,s1, 32,40, 0x000000); 

	puthz(x+41,48,s2, 32,40, 0xFFFFFF);
	puthz(x+41,50,s2, 32,40, 0xFFFFFF);
	puthz(x+43,48,s2, 32,40, 0xFFFFFF);
	puthz(x+43,50,s2, 32,40, 0xFFFFFF);
	puthz(x+42,49,s2, 32,40, 0x000000);
}


void draw_left_toolbotton_activate(int y,int length,char*s)
{
	bar(0,y+1,232,y+length-1,0xBDBD);
	line_thick(70,y,103,y, 1, 0xFF00 );
	line_thick(70,y+length,103,y+length, 1,0xFF00 );
	line_thick(113,y,130,y, 1, 0xFF00 );
	line_thick(113,y+length,130,y+length, 1,0xFF00 );
	line_thick(140,y,220,y, 1, 0xFF00 );
	line_thick(140,y+length,220,y+length, 1,0xFF00 );
	puthz(43,y+length/2-15,s, 32,50, 0x000000);

}

//画pro界面
void draw_pro_origin(void)
{
	bar(0,0,1024,768,0xFFFFFF);
    //clear_right_all();
    //Readbmp64k(0,0,"bmp\\logo.bmp"); 
    draw_main_toolbotton(234,0xBD32,"地图","显示");
    draw_main_toolbotton(392,0xFFAA,"全局","资源");
    draw_main_toolbotton(550,0xBBBB,"建造","显示");
    draw_main_toolbotton(708,0xFF19,"科技","研究");
    draw_main_toolbotton(866,0xBDBD,"时间","显示");
	line_thick(234, 0,234,768, 2, 0x000000 );
	line_thick(0,91,234,91, 1, 0x000000 );

	puthz2(250,100,24,26,0xffff,"尊敬的火星开拓者，欢迎来到火星家园建设系统！");
	puthz2(250,130,24,26,0xffff,"在这个系统中，你将作为一名决策者，来指导火星家园的建设。");
	puthz2(250,160,24,26,0xBBBB,"为了提供建设火星的基础设备，我们已经发射了一颗巨型火箭，");
	puthz2(250,190,24,26,0xBBBB,"其中包括大量资源和地球最先进的设备：");
	puthz2(250,220,24,26,0xffff,"一：火箭核心舱：提供开拓者们第一个住处。");
	puthz2(250,250,24,26,0xffff,"二：机器人中枢：地球研发的最先进的人工智能，");
	puthz2(250,280,24,26,0xffff,"拥有一些火星建筑的建设算法，若你需要建设新建筑，直接给");
	puthz2(250,310,24,26,0xffff,"他们指派任务即可，在建设基础设施后，你可以进行科技研发，");
	puthz2(250,340,24,26,0xffff,"以解锁更多建筑建设算法！当然，这些家伙耗电可不少。");
	puthz2(250,370,24,26,0xffff,"三：自动化仓库：与机器人中枢适配的资源自动化存储仓库。");
}


//画左端工具按钮
void draw_all_leftbuttons(int num,int len,char *s[])
{
	int i;
	for (i=0;i<num;i++)
	{
		draw_left_toolbotton(95+ i * len, len, s[i]);
	}
}



//上方主按钮按键
int main_toolbotton_mouse_press(int x)
{
    int start = 233 + (x - 1) * 158;
    return mouse_press(start, 0, start + 158, 90);
}

//左操作栏矩形按钮鼠标确认函数
int left_toolbotton_mouse_press(int x)
{
    int y = 95 + (x - 1)*65;
    return mouse_press(0, y, 234, y + 65);
}

//建造键返回函数
int build_press(int x)
{
	return mouse_press(920,130+(x-1)*130,1000,240+(x-1)*130);
}

//清除左端工具栏1
void clear_main_all(void)
{
    bar(0,95,232,768,0xFFFFFF);
}

//清除左端工具栏2
void clear_main_all2(int x)
{
    bar(0,95+65*x,232,768,0xFFFFFF);
}

//清除工作区
void clear_right_all(void)
{
	bar(238,99,1024,768,0xFFFFFF);
}

//擦除时间
void clear_time(void)
{
	bar(0,0,230,85,0xFFFFFF);
}

//画时间
void draw_time(struct GameInfo *gameinfop)
{
	int year=gameinfop->year;
	int month=gameinfop->month;
	char str[10];
	sprintf(str,"%d.%d",year,month);
	put_asc16_size(30,20,3,3,str,0xBDBD);
}
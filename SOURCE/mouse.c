#include<mouse.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <SVGA.h>
#define  H 15
#define  W 12


union REGS regs;
int mouse_shape1[H][W] =    //鼠标形状二维数组
{
    {1,1,0,0,0,0,0,0,0,0,0,0},
	{1,2,1,0,0,0,0,0,0,0,0,0},
	{1,2,2,1,0,0,0,0,0,0,0,0},
	{1,2,2,2,1,0,0,0,0,0,0,0},
	{1,2,2,2,2,1,0,0,0,0,0,0},
	{1,2,2,2,2,2,1,0,0,0,0,0},
	{1,2,2,2,2,2,2,1,0,0,0,0},
	{1,2,2,2,2,2,2,2,1,0,0,0},
	{1,2,2,2,2,2,2,2,2,1,0,0},
	{1,2,2,2,2,2,2,2,2,2,1,0},
	{1,2,2,2,2,2,2,1,1,1,1,1},
	{1,2,2,1,2,2,2,1,0,0,0,0},
	{1,2,1,0,1,2,2,2,1,0,0,0},	
	{1,1,0,0,0,1,2,2,2,1,0,0},	
	{1,0,0,0,0,0,1,1,1,1,0,0}
		    			
};

int mouse_shape2[H][W] =    //鼠标形状二维数组
{
    {1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,0,0,0,0,0},
	{0,0,0,0,0,1,1,0,0,0,0,0},	
	{0,0,0,0,0,1,1,0,0,0,0,0},	
	{1,1,1,1,1,1,1,1,1,1,1,1}
		    			
};
unsigned int mouse_bk[20][20];           //存放被鼠标覆盖的区域
int MouseX;
int MouseY;
int MouseS;
int press;         
int flag=0;



/***鼠标初始化***/
void mouseinit(void)
{
	//鼠标复位，检测是否安装鼠标
	union REGS regs;
	regs.x.ax=0;
	int86(0x33,&regs,&regs);
	if(regs.x.ax==0)
	{
		printf("mouse error");
		delay(5000);
		exit(1);
	}  
	/*设置横坐标范围*/
	regs.x.ax = 7;
	regs.x.cx = 0;
	regs.x.dx = 1012;
	int86(0x33, &regs, &regs);
	/*设置纵坐标范围*/
	regs.x.ax = 8;
	regs.x.cx = 0;
	regs.x.dx = 752;
	int86(0x33, &regs, &regs);
	//得到鼠标状态   
	MouseS=0;
	MouseX=320,MouseY=240;
	save_bk_mou(MouseX,MouseY);
	drawmous(MouseX,MouseY);	
	
	//MouseGet(&mouse);                  
	//MouseSpeed(6,4);
	//mouse_on(mouse);                 //显示鼠标
}




/********************************
	功能说明：设置鼠标计数与像素比,值越大鼠标移动速度越慢 
	参数说明：int   vx,	鼠标横向的；int   vy	鼠标纵向的
**
********************************/
void MouseSpeed(int x, int y)
{
	
	regs.x.ax=0x0f;
	regs.x.cx=x;
    regs.x.dx=y;
	int86(0x33,&regs,&regs);
}


void mread(int *mx,int *my,int*mbuttons)//读取鼠标位置并更新
{
	regs.x.ax=3;
	int86(51,&regs,&regs);
	*mx=regs.x.cx;
	*my=regs.x.dx;
	*mbuttons=regs.x.bx;
}

void mouse_renew(int *mx,int *my,int*mbuttons)//更改鼠标位置
{
	int x,y,buttons;          //用于接收新位置的变量
	int x0=*mx,y0=*my,buttons0=*mbuttons;   //接收旧位置的变量
	mread(&x,&y,&buttons);
	*mx = x;
	*my = y;
	*mbuttons = buttons;
	if(buttons0 == *mbuttons)
		*mbuttons = 0;    //使得能连续按键
	if(x == x0 && y == y0 && buttons == buttons0)
		return;            //鼠标状态不变则直接返回S
	clrmous(x0,y0);        //清除原位置鼠标并覆盖
	save_bk_mou(*mx,*my);
	drawmous(*mx,*my);
}

void save_bk_mou(int mx,int my)//存鼠标背景
{
	int i,j;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			
			mouse_bk[i][j] = Getpixel64k(j + mx, i + my);  //存储鼠标覆盖区
		}
	}
}
//清除鼠标 覆盖背景图
void clrmous(int mx,int my)
{
	if(flag==1)
	{
		int i,j;
		for (i = 0; i <H; i++)
		{
			for (j = 0; j < W; j++)
			{
				
				Putpixel64k(mx + j, my + i, mouse_bk[i][j]);   //画出原鼠标覆盖区
			}
		}
		flag=0;
	}
}
void drawmous(int mx,int my)
{
	if(flag==0)
	{
		if (MouseS==1)
		{
			int i, j;
			for (i = 0; i < H; i++)
			{
				for (j = 0; j < W; j++)
				{
					/***画鼠标***/
					if (mouse_shape1[i][j] == 1)
						Putpixel64k(mx + j, my + i, 1);
					else if (mouse_shape1[i][j] == 2)
						Putpixel64k(mx + j, my + i, 0xffff);
				}
			}
			flag=1;
		}
		
		else if (MouseS==2)
		{
			int i, j;
			for (i = 0; i < H; i++)
			{
				for (j = 0; j < W; j++)
				{
					/***画鼠标***/
					if (mouse_shape2[i][j] == 1)
						Putpixel64k(mx + j, my + i, 1);
					else if (mouse_shape2[i][j] == 2)
						Putpixel64k(mx + j, my + i, 0xffff);
				}
			}
			flag=1;
		}
		
	}
}

int mouse_press(int x1, int y1, int x2, int y2)
{
	//在框中点击，则返回1
	if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 1)
	{
		return 1;
	}
	
	//在框中未点击，则返回2
	else if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 0)
	{
		return 2;
	}
	
	//在框中点击右键，则返回3
	else if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 2)
	{
		return 3;
	}
	
	else
	{
		return 0;
	}
}

/***得到鼠标按键状态(不传递鼠标坐标)***/
//int mouse_press(MOUSE * mouse)
//{ 
//	union REGS regs;
//	regs.x.ax = 3;
//	int86(0x33, &regs, &regs);
//	mouse->key = regs.x.bx;
//	return mouse->key;     
//}


/***得到鼠标位置，按键状态***/
int MouseGet()
{ 
	union REGS regs;
	regs.x.ax = 3;
	int86(0x33, &regs, &regs);
	//mouse->x = regs.x.cx;
	//mouse->y = regs.x.dx;
	press = regs.x.bx;
	return press;
}
//
///***设置鼠标显示位置***/
//void MouseSet(int x,int y)
//{
//	union REGS regs;
//    regs.x.ax=4;
//	regs.x.cx=x;
//    regs.x.dx=y;
//	int86(0x33,&regs,&regs);      //设置鼠标当前坐标	
//	mouse_on(mouse);               //画鼠标	
//}
//
//
//
///***判断鼠标左键是否在指定区域内按下***/
//int mouse_press(int x1, int y1, int x2, int y2)
//{ 
//	MOUSE mouse = {0,0,0};                       
//	MouseGet(&mouse);       
//	if ((mouse.x >= x1)
//		&& (mouse.x <= x2)
//		&& (mouse.y >= y1)
//		&& (mouse.y <= y2)
//		&& ((mouse.key & 1) == 1))
//	{
//		return 1;
//	}
//	else if ((mouse.x >= x1)
//		&& (mouse.x <= x2)
//		&& (mouse.y >= y1)
//		&& (mouse.y <= y2))
//	{
//		return 2;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
///***鼠标显示***/
//void mouse_on(MOUSE mouse)
//{
//	int i, j;
//	for (i = 0; i < H; i++)
//	{
//		for (j = 0; j < W; j++)
//		{
//			
//			mouse_bk[i][j] = Getpixel64k(j + mouse.x, i + mouse.y);  //存储鼠标覆盖区
//			/***画鼠标***/
//			if (mouse_shape[i][j] == 1)
//				Putpixel64k(mouse.x + j, mouse.y + i, 0);
//			else if (mouse_shape[i][j] == 2)
//				Putpixel64k(mouse.x + j, mouse.y + i, 0xffff);
//		}
//	}
//
//}
//
//
///***鼠标每次移动重新显示***/
//void mouse_show(MOUSE *mouse)
//{  
//	int i,j;       //循环变量
//	int color;     //鼠标某点颜色
//	int x,y;
//	x=mouse->x;             //鼠标原位置坐标
//	y=mouse->y;         
//	MouseGet(mouse);    //得到新鼠标状态
//	if(mouse->x!=x||mouse->y!=y)         //鼠标移动就重新画鼠标
//	{
//		for (i = 0; i < H; i++)           	
//		{
//			for (j = 0; j < W; j++)
//			{
//				if (mouse_shape[i][j] == 0)
//					continue;
//				Putpixel64k(x + j, y + i, mouse_bk[i][j]);   //画出原鼠标覆盖区
//			}
//		}
//		mouse_on(*mouse);                            //在新位置显示鼠标
//	}
//}
//
///***鼠标隐藏***/
//void mouse_off(MOUSE *mouse)
//{
//	int i,j;
//	int x,y;
//	x=mouse->x;
//	y=mouse->y;
//	for (i = 0; i <H; i++)
//		for (j = 0; j < W; j++)
//		{
//			if (mouse_shape[i][j] == 0)
//				continue;
//			Putpixel64k(x + j, y + i, mouse_bk[i][j]);   //画出原鼠标覆盖区
//		}
//}
//
///*初始化鼠标，设置水平垂直方向像素比相等*/
//void Curinit()
//{
//	_AX=0;
//	geninterrupt(0x33);
//	if(_AX==0)
//		puts("mouse init fail!");
//	_AX=7;
//	_CX=10;
//	_DX=1000;
//	geninterrupt(0x33);
//	_AX=8;
//	_CX=10;
//	_DX=750;
//	geninterrupt(0x33);
//}
//
//void draw_mouse(int mx,int my)
//{
//	int i, j;
//	for (i = 0; i < H; i++)
//	{
//		for (j = 0; j < W; j++)
//		{
//			/***画鼠标***/
//			if (mouse_shape[i][j] == 1)
//				Putpixel64k(mx + j, my + i, 0);
//			else if (mouse_shape[i][j] == 2)
//				Putpixel64k(mx + j, my + i, 0xffff);
//		}
//	}
//}
//
//void CurShow()
//{
//	Cursor(500,500,2);
//}
//
//void Curhide()
//{
//	Cursor(500,500,1);
//}
//
//void Cursor(int x,int y,int flag)
//{
//	static unsigned int far *tempgraph;
//	static int mx,my;
//    if(tempgraph==NULL)
//	{
//		tempgraph=malloc(1000);
//	}
//	if(1<=x&&x<=1000&&1<=y&&y<=750)
//	{
//		switch(flag)
//		{			
//		case 1:	//hidemouse
//			Put_image(mx,my,mx+16,my+15,tempgraph);
//			//delay(20);
//			break;
//		case 2:	//showmouse
//			do
//			{
//				_AX=3;
//				geninterrupt(0x33);
//				mx=_CX;
//				my=_DX;
//			}
//			while(1>=mx||mx>=1000||1>=my||my>=750);
//			Get_image(mx,my,mx+16,my+15,tempgraph);
//			draw_mouse(mx,my);
//			break;
//		}
//	}
//}
//
//void getmouse(int *button,int *x,int *y)
//{
//	static int mx,my,mbutton;
//	_AX=3;
//	geninterrupt(0x33);
//	mbutton=_BL;
//	mx=_CX;
//	my=_DX;
//	Cursor(mx,my,0);
//	if(button!=NULL)
//		*button=mbutton;
//	if(x!=NULL&&y!=NULL)
//	{
//		*x=mx;
//		*y=my;
//	}
//}

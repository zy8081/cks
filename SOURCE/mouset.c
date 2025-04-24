#include<mouset.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <SVGA.h>
#define  H 15
#define  W 12


union REGS regs;
int mouse_shape1[H][W] =    //�����״���?����
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

int mouse_shape2[H][W] =    //�����״���?����
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
unsigned int mouse_bk[20][20];           //��ű���긲�ǵ�����
int MouseX;
int MouseY;
int MouseS;
int press;         
int flag=0;



/***����ʼ��***/
void mouseinit(void)
{
	//��긴λ������Ƿ�װ���?
	union REGS regs;
	regs.x.ax=0;
	int86(0x33,&regs,&regs);
	if(regs.x.ax==0)
	{
		printf("mouse error");
		delay(5000);
		exit(1);
	}  
	/*���ú����귶Χ*/
	regs.x.ax = 7;
	regs.x.cx = 0;
	regs.x.dx = 1012;
	int86(0x33, &regs, &regs);
	/*���������귶Χ*/
	regs.x.ax = 8;
	regs.x.cx = 0;
	regs.x.dx = 752;
	int86(0x33, &regs, &regs);
	//�õ����״�?   
	MouseS=0;
	MouseX=320,MouseY=240;
	save_bk_mou(MouseX,MouseY);
	drawmous(MouseX,MouseY);	
	
	//MouseGet(&mouse);                  
	//MouseSpeed(6,4);
	//mouse_on(mouse);                 //��ʾ���?
}




/********************************
	����˵�������������������ر�,ֵԽ������ƶ��ٶ�Խ��? 
	����˵����int   vx,	������ģ�int   vy	��������
**
********************************/
void MouseSpeed(int x, int y)
{
	
	regs.x.ax=0x0f;
	regs.x.cx=x;
    regs.x.dx=y;
	int86(0x33,&regs,&regs);
}


void mread(int *mx,int *my,int*mbuttons)//��ȡ���λ�ò�����?
{
	regs.x.ax=3;
	int86(51,&regs,&regs);
	*mx=regs.x.cx;
	*my=regs.x.dx;
	*mbuttons=regs.x.bx;
}

void mouse_renew(int *mx,int *my,int*mbuttons)//�������λ��?
{
	int x,y,buttons;          //���ڽ�����λ�õı���
	int x0=*mx,y0=*my,buttons0=*mbuttons;   //���վ�λ�õı���
	mread(&x,&y,&buttons);
	*mx = x;
	*my = y;
	*mbuttons = buttons;
	if(buttons0 == *mbuttons)
		*mbuttons = 0;    //ʹ������������
	if(x == x0 && y == y0 && buttons == buttons0)
		return;            //���״�?������ֱ�ӷ���S
	clrmous(x0,y0);        //����?λ�����?����
	save_bk_mou(*mx,*my);
	drawmous(*mx,*my);
}

void save_bk_mou(int mx,int my)//����걳��?
{
	int i,j;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			
			mouse_bk[i][j] = Getpixel64k(j + mx, i + my);  //�洢��긲����?
		}
	}
}
void clrmous(int mx,int my)//������ ���Ǳ���ͼ
{
	if(flag==1)
	{
		int i,j;
		for (i = 0; i <H; i++)
		{
			for (j = 0; j < W; j++)
			{
				Putpixel64k(mx + j, my + i, mouse_bk[i][j]);   //����ԭ��긲����?
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
					/***�����?***/
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
					/***�����?***/
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
	//�ڿ��е�����򷵻�?1
	if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 1)
	{
		return 1;
	}
	
	//�ڿ���δ������򷵻�?2
	else if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 0)
	{
		return 2;
	}
	
	//�ڿ��е���Ҽ����򷵻�?3
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

/***�õ���갴��״�?(�������������?)***/
//int mouse_press(MOUSE * mouse)
//{ 
//	union REGS regs;
//	regs.x.ax = 3;
//	int86(0x33, &regs, &regs);
//	mouse->key = regs.x.bx;
//	return mouse->key;     
//}


/***�õ����λ�ã�����״�?***/
//int MouseGet(MOUSE * mouse)
//{ 
//	union REGS regs;
//	regs.x.ax = 3;
//	int86(0x33, &regs, &regs);
//	mouse->x = regs.x.cx;
//	mouse->y = regs.x.dx;
//	mouse->key = regs.x.bx;
//	return mouse->key;
//}
//
///***���������ʾλ��?***/
//void MouseSet(int x,int y)
//{
//	union REGS regs;
//    regs.x.ax=4;
//	regs.x.cx=x;
//    regs.x.dx=y;
//	int86(0x33,&regs,&regs);      //������굱ǰ����?	
//	mouse_on(mouse);               //�����?	
//}
//
//
//
///***�ж��������Ƿ���ָ�������ڰ���***/
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
///***������?***/
//void mouse_on(MOUSE mouse)
//{
//	int i, j;
//	for (i = 0; i < H; i++)
//	{
//		for (j = 0; j < W; j++)
//		{
//			
//			mouse_bk[i][j] = Getpixel64k(j + mouse.x, i + mouse.y);  //�洢��긲����?
//			/***�����?***/
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
///***���ÿ���ƶ��������?***/
//void mouse_show(MOUSE *mouse)
//{  
//	int i,j;       //ѭ������
//	int color;     //���ĳ�����?
//	int x,y;
//	x=mouse->x;             //����?λ������
//	y=mouse->y;         
//	MouseGet(mouse);    //�õ������״�?
//	if(mouse->x!=x||mouse->y!=y)         //����ƶ������»����
//	{
//		for (i = 0; i < H; i++)           	
//		{
//			for (j = 0; j < W; j++)
//			{
//				if (mouse_shape[i][j] == 0)
//					continue;
//				Putpixel64k(x + j, y + i, mouse_bk[i][j]);   //����ԭ��긲����?
//			}
//		}
//		mouse_on(*mouse);                            //����λ����ʾ���?
//	}
//}
//
///***�������?***/
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
//			Putpixel64k(x + j, y + i, mouse_bk[i][j]);   //����ԭ��긲����?
//		}
//}
//
///*��ʼ�����?����ˮƽ��ֱ�������ر����?*/
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
//			/***�����?***/
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

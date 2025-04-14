#include <SVGA.h>
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
//#include <ghz.h>
//#include "mouse.h"
/**************************************
   SVGA�Ĺ��ܺ�ax˵��
   0x4f00  ��SVGA����Ϣ
   0x4f01  ����ʾģʽ��Ϣ
   0x4f02  ������ʾģʽ
   0x4f03  ����ǰ��ʾģʽ
   0x4f04  �洢��ָ�SVGA����Ƶ״̬
   0x4f05  �����ڴ�ҳ�����л�
   0x4f06  ���û��ȡ�߼��?���߿���
   0x4f07  ���û��ȡ��Ƶ�ڴ�����Ļ�ĳ�ʼ��Ӧλ��?
   0x4f08  ���û���?DAC��ԭɫ��Чλ��
   SVGA��ʾģʽ��bx��
		ģʽ��		�ֱ���		��ɫ��		��ɫλ����
		0x101		640*480		256				-
		0x103		800*600		256				-
		0x104		1024*768	16				-
		0x105		1024*768	256				-
		0x110		640*480		32K			1:5:5:5
		0x111		640*480		64K			5:6:5
		0x112		640*480		16.8M		8:8:8
		0x113		800*600		32K			1:5:5:5
		0x114		800*600		64K			5:6:5
		0x115		800*600		16.8M		8:8:8
		0x116		1024*768	32K			1:5:5:5
		0x117		1024*768	64K			5:6:5
		0x118		1024*768	16.8M		8:8:8
**************************************************/


/**********************************************************
Function��		SetSVGA64k

Description��	SVGA��ʾģʽ���ú�������Ϊ0x117

Calls��			int86
				delay
				printf
				exit

Called By��		AutoSimulate
				HandOperate
				
Input��			None

Output��		������Ϣ

Return��		None				
Others��		None
**********************************************************/
void SetSVGA64k(void)
{
	/*REGS���������?*/
	union REGS graph_regs;
	
	/*����VESA VBEģʽ�Ĺ��ܺ�*/
	graph_regs.x.ax = 0x4f02;
	graph_regs.x.bx = 0x117;
	int86(0x10, &graph_regs, &graph_regs);
	
	/*ax != 0x004f��ζ�ų�ʼ��ʧ�ܣ�����������?����,��ͬ*/
	if (graph_regs.x.ax != 0x004f)
	{
		printf("Error in setting SVGA mode!\nError code:0x%x\n", graph_regs.x.ax);
		delay(5000);
		exit(1);
	}
}


/**********************************************************
Function��		Selectpage

Description��	���жϹ��ܵĻ�ҳ�����������д�Դ�ʱ���Ѱַ����

Calls��			int86

Called By��		Putpixel256
				Putpixel64k
				Xorpixel
				Horizline
				Getpixel64k
				
Input��			register char page		��Ҫ������ҳ���?

Output��		None
Return��		None
Others��		None
**********************************************************/
void Selectpage(register char page)
{
	/*REGS����ͬ��*/
	union REGS graph_regs;
	
	/*��һ�ε�ҳ���?,���ڼ����л�����,��ʹ�ô����ܶ�����?����*/
	static unsigned char old_page = 0;
	
	/*��־���������ж��Ƿ��ǵ�һ�λ�ҳ*/
	static int flag = 0;
	
	/*����ҳ����ƹ��ܺ�?*/
	graph_regs.x.ax = 0x4f05;
	graph_regs.x.bx = 0;
	
	/*����ǵ�һ�λ��?*/
	if (flag == 0)
	{
		old_page = page;
		graph_regs.x.dx = page;
		int86(0x10, &graph_regs, &graph_regs);
		flag++;
	}
	
	/*������ϴ�ҳ��Ų�ͬ������л��?*/
	else if (page != old_page)
	{
		old_page = page;
		graph_regs.x.dx = page;
		int86(0x10, &graph_regs, &graph_regs);
	}
}



/**********************************************************
Function��		Putpixel64k

Description��	���㺯����������ͼ�����Ļ�������������0x117ģʽ��

Calls��			Selectpage

Called By��		Putbmp64k
				MousePutBk
				MouseDraw
				
Input��			int x					���غ����꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				int y					���������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
				unsigned int color		��ɫ��������64k��

Output��		����Ļ�ϻ�ָ����ɫ�ĵ�

Return��		None
Others��		None
**********************************************************/
void Putpixel64k(int x, int y, unsigned int color)
{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾���������޸�*/
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;
	
	/*Ҫ�л���ҳ���?*/
	unsigned char new_page;
	
	/*��Ӧ�Դ��ַ�?����*/
	unsigned long int page;
	
	/*�жϵ��Ƿ�����Ļ��Χ�ڣ����ھ��˳�*/
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))
	{
		return;
	}
	
	/*�����Դ��ַ�?�����Ͷ�Ӧ��ҳ��ţ�����ҳ����?*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 15;	/*32k����һ��ҳ������32k�������?*/
	Selectpage(new_page);
	
	/*���Դ�д����ɫ����Ӧ�㻭��*/
	video_buffer[page] = color;	
}

/***�õ�ĳһ������?ֵ***/
unsigned int Getpixel64k(int x, int y)
{
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;
	unsigned char page;                                                  //Ҫ�л���ҳ���?
	unsigned long int page_dev;                                           //��Ӧ�Դ��ַ�?����                       
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))           //�жϵ��Ƿ�����Ļ��Χ�ڣ����ھ��˳� 
	{
		printf("out of range");
	}
	page_dev = ((unsigned long int)y << 10) + x;                              //�����Դ��ַ�?�����Ͷ�Ӧ��ҳ��ţ�����ҳ����?
	page = page_dev >> 15;	//32k����һ��ҳ������32k�������?
	Selectpage(page);
	return video_buffer[page_dev];	 //������ɫ
}

/*********************************************************
Function��		Readbmp64k

Description��	24λ��ѹ��bmpͼ��λ��ʾ������
				ֻ֧��24λ��ѹ��bmpͼ������������������?1024��
				����bmp���;���֧�֣�
				����0x117ģʽ��ʹ�ã�
				Ϊ�˼򻯣�û�������ļ����ͼ�⹦�ܼ�⹦�ܣ�������벻���?����ļ���?

Calls��			Putpixel64k

				fseek
				fread
				fclose
				outportb
				malloc
				free

Called By��		AutoSimulate
				HandOperate
				Menu
				
Input��			int x		ͼƬ���Ͻǵĺ����꣨��Ļ�ο�ϵ��
				int y		ͼƬ���Ͻǵ������꣨��Ļ�ο�ϵ��
				const char * path	bmpͼƬ·��

Output��		��Ļ����ʾͼƬ

Return��		0	��ʾ�ɹ�
				-1	��ʾʧ��
				
Others��		None
**********************************************************/
int Readbmp64k(int x, int y, const char * path)
{
	/*ָ��ͼƬ�ļ����ļ�ָ��*/
	FILE * fpbmp;
	
	/*�����ػ���ָ��*/
	COLORS24 * buffer;
	
	/*ͼƬ�Ŀ��ȡ��߶ȡ�һ��������ռ�ֽ�������������ֽڣ�?*/
	long int width, height, linebytes;
	
	/*ѭ������*/
	int i, j;
	
	/*ͼƬλ��*/
	unsigned int bit;
	
	/*ѹ��������*/
	unsigned long int compression;
	
	/*���ļ�*/
	if ((fpbmp = fopen(path, "rb")) == NULL)
	{
		return -1;
	}
	
	/*��ȡλ��*/
	fseek(fpbmp, 28L, 0);
	fread(&bit, 2, 1, fpbmp);
	
	/*��24λͼ���˳�*/
	if (bit != 24U)
	{
		return -1;
	}
	
	/*��ȡѹ������*/
	fseek(fpbmp, 30L, 0);
	fread(&compression, 4, 1, fpbmp);
	
	/*����ѹ���㷨���˳�*/
	if (compression != 0UL)
	{
		return -1;
	}
	
	/*��ȡ���ȡ��߶�*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);
	
	/*���ȳ������˳�*/
	if (width > SCR_WIDTH)
	{
		return -1;
	}

	/*����һ������ռ�ֽ�������������Ŀ��ֽ�?*/
	linebytes = (3 * width) % 4;
	
	if(!linebytes)
	{
		linebytes = 3 * width;
	}
	else
	{
		linebytes = 3 * width + 4 - linebytes;
	}

	/*�������������ݶ�̬����ռ�?*/
	if ((buffer = (COLORS24 *)malloc(linebytes)) == 0)
	{
		return -1;
	}
	
	/*��ɨ����ʽ��ȡͼƬ���ݲ���ʾ*/
	fseek(fpbmp, 54L, 0);
	for (i = height - 1; i > -1; i--)
	{
		fread(buffer, linebytes, 1, fpbmp);	/*��ȡһ����������*/
		
		/*һ�����ص����ݴ����ͻ���*/
		for (j = 0; j < width; j++)
		{
			/*0x117ģʽ�£�ԭͼ��������8λ�ֱ�����?5λ��6λ��5λ*/
			buffer[j].R >>= 3;
			buffer[j].G >>= 2;
			buffer[j].B >>= 3;
			Putpixel64k(j + x, i + y,
			((((unsigned int)buffer[j].R) << 11)
			| (((unsigned int)buffer[j].G) << 5)
			| ((unsigned int)buffer[j].B)));	/*����������ɫ���������Ӹ�λ����λ����*/
		}
	}
	
	free(buffer);	
	fclose(fpbmp);
	
	return 0;	
}


/***24λ��ʾģʽ�»���***/
void line_hor_ver(int x1, int y1, int x2, int y2, unsigned int color)
{
	int i;
	if(x1==x2)                   //��ֱֱ��
	{
		for(i=y1;i<=y2;i++)
			Putpixel64k(x1,i,color);
	}
	if(y1==y2)                   //ˮƽֱ��
	{
		for(i=x1;i<=x2;i++)
			Putpixel64k(i,y1,color);
	}
}

/***����ֱ��***/
void line(int x1, int y1, int x2, int y2, unsigned int color)
{
	int	dx, dy;			/*ֱ��x��y������?*/
	int dx2, dy2;		/*�ӿ������ٶȵ��м�ֵ*/
	int xinc, yinc;		/*�ж��롢y���ӷ���ķ����?*/
	int d, dxy;			/*���߱���*/
	/*���������ֵ���м����*/
	dx = abs(x2 - x1);
	dx2 = dx << 1;
	dy = abs(y2 - y1);
	dy2 = dy << 1;
	
	/*�ж�ֱ��x�������ӷ���*/
	if (x2 > x1)
	{
		xinc = 1;
	}
	
	/*�������ֱ��?*/
	else if (x2 == x1)
	{
		/*y��������*/
		if (y1 > y2)
		{
			dx = y1;
			y1 = y2;
			y2 = dx;
		}
		/*����ֱ��*/
		for (dx = y1; dx <= y2; dx++)
		{
			Putpixel64k(x1, dx, color);
		}
		
		return;
	}
	
	else
	{
		xinc = -1;
	}
	
	/*�ж�ֱ��y�������ӷ���*/
	if (y2 > y1)
	{
		yinc = 1;
	}
	
	/*������?ƽ��*/
	else if (y2 == y1)
	{
		line_hor_ver(x1, y1, x2, y1, color);		
		return;
	}
	
	else
	{
		yinc = -1;
	}
	
	/*******************************
	��������Bresenham�㷨����ֱ�ߡ�
	���㷨�ǵõ����ϵĳ���Ŀ�����?��
	����ϸ����ȥ��
	*******************************/
	Putpixel64k(x1, y1, color);
	
	if (dx >= dy)
	{
		d = dy2 - dx;
		dxy = dy2 - dx2;
		
		while (dx--)
		{
			if (d <= 0)
			{
				d += dy2;
			}
			
			else
			{
				d += dxy;
				y1 += yinc;
			}
			
			x1 += xinc;
			Putpixel64k(x1, y1, color);
		}
	}
	
	else
	{
		d = dx2 - dy;
		dxy = dx2 - dy2;
		
		while (dy--)
		{
			if (d <= 0)
			{
				d += dx2;
			}
			
			else
			{
				d += dxy;
				x1 += xinc;
			}
			
			y1 += yinc;
			Putpixel64k(x1, y1, color);
		}
	}
}

/***24λ��ʾģʽ�»���ֱ��***/
void line_hor_ver_thick(int x1, int y1, int x2, int y2, int radius,unsigned int color)
{
	int i;
	int dx,dy;
	if(x1>x2)    //���x,y��С˳������
	{
		dx=x1;
		x1=x2;
		x2=dx;
	}
	if(y1>y2)
	{
		dy=y1;
		y1=y2;
		y2=dy;
	}
	if(x1==x2)                   //��ֱֱ��
	{
		for(i=y1;i<=y2;i++)
			circle_fill(x1, i, radius, color);
	}
	if(y1==y1)                   //ˮƽֱ��
	{
		for(i=x1;i<=x2;i++)
			circle_fill(i, y1, radius, color);
	}
}

void line_thick(int x1, int y1, int x2, int y2, int radius,unsigned int color)
{
	int	dx, dy;			/*ֱ��x��y������?*/
	int dx2, dy2;		/*�ӿ������ٶȵ��м�ֵ*/
	int xinc, yinc;		/*�ж�x��y���ӷ���ķ����?*/
	int d, dxy;			/*���߱���*/
	
	/*���������ֵ���м����*/
	dx = abs(x2 - x1);
	dx2 = dx << 1;
	dy = abs(y2 - y1);
	dy2 = dy << 1;
	
	/*�ж�ֱ��x�������ӷ���*/
	if (x2 > x1)
	{
		xinc = 1;
	}
	
	/*�������ֱ��?*/
	else if (x2 == x1)
	{
		/*y��������*/
		if (y1 > y2)
		{
			dx = y1;
			y1 = y2;
			y2 = dx;
		}
		
		/*����ֱ��*/
		for (dx = y1; dx <= y2; dx++)
		{
			circle_fill(x1, dx, radius, color);
		}
		
		return;
	}
	
	else
	{
		xinc = -1;
	}
	
	/*�ж�ֱ��y�������ӷ���*/
	if (y2 > y1)
	{
		yinc = 1;
	}
	
	/*������?ƽ��*/
	else if (y2 == y1)
	{
		line_hor_ver_thick(x1, y1, x2, y1,radius, color);		
		return;
	}
	
	else
	{
		yinc = -1;
	}
	
	/*******************************
	��������Bresenham�㷨����ֱ�ߡ�
	���㷨�ǵõ����ϵĳ���Ŀ�����?��
	����ϸ����ȥ��
	*******************************/
	circle_fill(x1, y1, radius, color);
	
	if (dx >= dy)
	{
		d = dy2 - dx;
		dxy = dy2 - dx2;
		
		while (dx--)
		{
			if (d <= 0)
			{
				d += dy2;
			}
			
			else
			{
				d += dxy;
				y1 += yinc;
			}
			
			x1 += xinc;
			circle_fill(x1, y1, radius, color);
		}
	}
	
	else
	{
		d = dx2 - dy;
		dxy = dx2 - dy2;
		
		while (dy--)
		{
			if (d <= 0)
			{
				d += dx2;
			}
			
			else
			{
				d += dxy;
				x1 += xinc;
			}
			
			y1 += yinc;
			circle_fill(x1, y1, radius, color);
		}
	}
}


/***24λ��ʾģʽ�»�����***/
void bar(int x1, int y1, int x2, int y2, unsigned int color)
{
	int i,j;
	for(j=y1;j<=y2;j++)
	{
		line(x1,j,x2,j,color);
	}
}


/***24λ��ʾģʽ�»�����(����ɫ)***/
void bar_frame(int x1,int y1,int x2,int y2,unsigned int color)
{
	line_hor_ver(x1,y1,x2,y1,color);
    line_hor_ver(x2,y1,x2,y2,color);
	line_hor_ver(x1,y1,x1,y2,color);
	line_hor_ver(x1,y2,x2,y2,color);
}

void circle_frame(int xc, int yc, int radius, unsigned int color)
{
	/*��ԲȦ�Ķ�λ�����;��߱���*/
	int x, y, d;
	
	/*�뾶����Ϊ���������˳�*/
	if (radius <= 0)
	{
		return;
	}
	
	/************************************
	��������Bresenham�㷨����ԲȦ��
	���㷨�ǵõ����ϵĳ���Ŀ�����?��
	����ϸ����ȥ��
	************************************/
	y = radius;
	d = 3 - radius << 1;
	
	for (x = 0; x <= y; x++)
	{
		Putpixel64k(xc + x, yc + y, color);
		Putpixel64k(xc + x, yc - y, color);
		Putpixel64k(xc - x, yc - y, color);
		Putpixel64k(xc - x, yc + y, color);
		Putpixel64k(xc + y, yc + x, color);
		Putpixel64k(xc + y, yc - x, color);
		Putpixel64k(xc - y, yc - x, color);
		Putpixel64k(xc - y, yc + x, color);
		
		if (d < 0)
		{
			d += x * 4 + 6;
		}
		
		else
		{
			d += (x - y) * 4 + 10;
			y--;
		}
	}
}

void circle_fill(int xc, int yc, int radius, unsigned int color)
{
	/*��ԲȦ�Ķ�λ�����;��߱���*/
	int x = 0,
		y = radius,
		dx = 3,
		dy = 2 - radius - radius,
		d = 1 - radius;
	
	/*�뾶����Ϊ���������˳�*/
	if (radius <= 0)
	{
		return;
	}
	
	/************************************
	��������Bresenham�㷨����ʵ��Բ��
	���㷨�ǵõ����ϵĳ���Ŀ�����?��
	����ϸ����ȥ��
	************************************/
	while (x <= y)
	{
		line_hor_ver(xc - x, yc - y, xc + x, yc-y, color);
        line_hor_ver(xc - y, yc - x, xc + y, yc-x, color);
        line_hor_ver(xc - y, yc + x, xc + y, yc+x, color);
        line_hor_ver(xc - x, yc + y, xc + x, yc+y, color);
        
        if (d < 0)
        {
            d += dx;
            dx += 2;
        }
        
        else
        {
            d += (dx + dy);
            dx += 2;
            dy += 2;
            y--;
		}

        x++;
	}
}

void CloseSVGA(void)        //�ر�ͼ�ν���
{
    union REGS regs;
    regs.h.ah=0;
    regs.h.al=0x03;
    int86(0x10,&regs,&regs);     
}



int SaveBMP(int x1, int y1, int x2, int y2,int n)     //����ͼ��
{
	int i = 0, j = 0;
	int height = y2 - y1, width = x2 - x1;
	int color = 0;
	char f[100];
	FILE *fp = NULL;
	
	//��ȡ·��
	sprintf(f,"saves\\save%d.dat",n);     
	
	fp = fopen(f, "wb");
	if (fp == NULL)
	{
		exit(1);
	}
	for (i = 0; i<=height; i++)
	{
		for (j = 0; j<=width; j++)
		{
			color = Getpixel64k(x1 + j, y1 + i);
			fwrite(&color, sizeof(int), 1, fp);
		}
	}
	fclose(fp);
	return n;
}

void LoadBMP(int x1, int y1, int x2, int y2, int n)     //����ͼ��
{
	int i = 0, j = 0;
	int height = y2 - y1, width = x2 - x1;
	int color = 0;
	char path[50];
	FILE *fp = NULL;

	sprintf(path,"saves\\save%d.dat",n);

	if((fp=fopen(path,"rb"))==NULL)
	{
		fclose(fp);
		//puthz_coverd2(400,400,"��ǰλ�ò�û�д���·����",12,32,34,0x000000,0xBDBD);
		exit(1);
	}
	else
	{
		for (i = 0; i<=height; i++)
		{
			for (j = 0; j<=width; j++)
			{
				fread(&color, sizeof(int), 1, fp);
				Putpixel64k(x1 + j, y1 + i, color);
			}
		}
		fclose(fp);
	}
}


/*******************
����˵������ȡ��������ͼ����Ϣ��������
����˵������������������Ϻ����¶�������?������ָ��
*******************/
void Get_image(int x0,int y0,int x1,int y1,unsigned int far *save)
{
	int i=0;                                   /*ѭ������*/
	int j=0;
	int wide=x1-x0;
    int high=y1-y0;
	for(i=0;i<high;i++)
	{
		for(j=0;j<wide;j++)
		{
			save[i*wide+j]=Getpixel64k(x0+j, y0+i);
		}
	}
}

/*******************
����˵�����ӻ���������ͼ����Ϣ����������
����˵������������������Ϻ����¶�������?������ָ��
*******************/
void Put_image(int x0,int y0,int x1,int y1,unsigned int far *save)
{

	int i=0;                                   /*ѭ������*/
	int j=0;
	int wide=x1-x0;
	int high=y1-y0;
	unsigned   int far *VideoBuffer=(unsigned int far *)0xa0000000L ;
	long int newpage=0;
	long int  oldpage=0;
	unsigned long pos;
	for(i=0;i<high;i++)
	{
		if((i+y0)>768)
		{
			continue;
		}
		Selectpage(newpage);
		for(j=0;j<x1-x0;j++)
		{   
            if((j+x0)>1024)
			{
				continue;
			}  
			pos=((unsigned long)(y0+i)<<10)+x0+j;
			newpage=pos>>15 ;                         /*����32k�������?*/
			if (newpage != oldpage)            //���û�ҳ����
			{
				Selectpage(newpage);
				oldpage = newpage;
			}
			VideoBuffer[pos]=save[i*wide+j];
		}
	}
}

/***����ť***/
//void Cirbar(int x1, int y1, int x2, int y2, unsigned int color)
//{
//	int y3=(y1+y2)/2;
//	int r=(y2-y1)/2;
//	Circlefill(x1,y3,r,color);
//	Circlefill(x2,y3,r,color);
//	bar(x1,y1,x2,y2,color); 
//}


int GenerateBMP(int x1, int y1, int x2, int y2)
{
    static int p = 1;
	int i = 0, j = 0;
	int height = y2 - y1, width = x2 - x1;
	int color = 0;
	char f[50];
	FILE* fp = NULL;

	char* bmpFilePath;
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	unsigned short pixelData;


	// BMP�ļ�ͷ
	uint8_t bmpFileHeader[14] = {
		0x42, 0x4D,       // �ļ����ͱ�ʶ "BM"
		0, 0, 0, 0,       // �ļ���С�������?
		0, 0,             // �����ֶ�
		0, 0,             // �����ֶ�
		54, 0, 0, 0       // ����ƫ����
	};

	// BMP��Ϣͷ
	uint8_t bmpInfoHeader[40] = {
		40, 0, 0, 0,      // ��Ϣͷ��С
		0, 0, 0, 0,       // ���ȣ������?
		0, 0, 0, 0,       // �߶ȣ������?
		1, 0,             // ��ɫƽ����
		24, 0,            // λ���?
		0, 0, 0, 0,       // ѹ������
		0, 0, 0, 0,       // ͼ�����ݴ�С�������?
		0, 0, 0, 0,       // ˮƽ�ֱ���
		0, 0, 0, 0,       // ��ֱ�ֱ���
		0, 0, 0, 0,       // ʹ�õ���ɫ��
		0, 0, 0, 0        // ��Ҫ��ɫ��
	};

	// �����ļ���С��ͼ�����ݴ�С
	int fileSize = 54 + width * height * 3;
	int imageDataSize = width * height * 3;

    if (p <= 10)
    {
        sprintf(f, "picture\\generated%d.bmp", p);
        p++;
    }
	bmpFilePath=f;
	// ���ļ�
	fp = fopen(bmpFilePath, "wb");
	if (fp == NULL)
	{
		exit(1);
	}

	// ����ļ�ͷ����Ϣͷ�����ݴ�С�ֶ�?
	bmpFileHeader[2] = (uint8_t)(fileSize);
	bmpFileHeader[3] = (uint8_t)(fileSize >> 8);
	bmpFileHeader[4] = (uint8_t)(fileSize >> 16);
	bmpFileHeader[5] = (uint8_t)(fileSize >> 24);

	bmpInfoHeader[4] = (uint8_t)(width);
	bmpInfoHeader[5] = (uint8_t)(width >> 8);
	bmpInfoHeader[6] = (uint8_t)(width >> 16);
	bmpInfoHeader[7] = (uint8_t)(width >> 24);
	bmpInfoHeader[8] = (uint8_t)(height);
	bmpInfoHeader[9] = (uint8_t)(height >> 8);
	bmpInfoHeader[10] = (uint8_t)(height >> 16);
	bmpInfoHeader[11] = (uint8_t)(height >> 24);
	bmpInfoHeader[20] = (uint8_t)(imageDataSize);
	bmpInfoHeader[21] = (uint8_t)(imageDataSize >> 8);
	bmpInfoHeader[22] = (uint8_t)(imageDataSize >> 16);
	bmpInfoHeader[23] = (uint8_t)(imageDataSize >> 24);

	// д���ļ�ͷ����Ϣͷ
	fwrite(bmpFileHeader, sizeof(uint8_t), sizeof(bmpFileHeader), fp);
	fwrite(bmpInfoHeader, sizeof(uint8_t), sizeof(bmpInfoHeader), fp);

	// д����������
	for (i = height - 1; i > -1; i--)
	{
		for (j = 0; j < width; j++)
		{
			// ��ȡ��Ļ��ָ��λ�õ�������ɫ
			color = Getpixel64k(x1 + j, y1 + i);


			// ����ɫ����д���ļ�
            fputc((((color) & (2*2*2*2*2-1)))<<3, fp); // ��ɫ����
        	fputc((((color >> 5) & (2*2*2*2*2*2-1)))<<2, fp);  // ��ɫ����
        	fputc((((color >>11) & (2*2*2*2*2-1)))<<3, fp);         // ��ɫ����
		}
	}

	// �ر��ļ�
	fclose(fp);

	// �������ɵ�BMP�ļ�·��
    if (p == 11)
    {
        p = 1;
        return 10;
    }
    return p-1;
}

void cleardevice(void)
{
	bar(0,0,1024,768,0xffff);
}
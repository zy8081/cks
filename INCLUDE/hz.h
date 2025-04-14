#ifndef	HZ_H
#define	HZ_H

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<fcntl.h>
#include<io.h>
#include<string.h>
#include "SVGA.h"

/*����16���ֿ����16*16������*/
void put_hz16(int x, int y, char *s, unsigned int color, char * name,int flag);

/*����24���ֿ����24*24��������*/
void put_hz24(int x, int y,char * s, unsigned int color, char * name,int flag);
void put_hz32(int x, int y, char *s, unsigned int color, char * name,int flag);
void put_hz48(int x, int y, char *s, unsigned int color, char * name,int flag);
/*����24���ֿ����24*24�������֣����ӳ٣�*/
//void prt_hz24d(int x, int y,char * s, unsigned int color, char * name);

/*����16���ֿ����16*xsize*16*ysize�����֣�x,y��ʾ�������λ�ã�xsize,ysizeΪ�Ŵ�����
sΪ���ִ���color��ʾ������ɫ��name Ϊ���ֿ��ļ�·������������Ϣ*/
void put_hz16_size(int x, int y, int xsize,int ysize,char *s, unsigned int color, char * name);


/*����asc16����ַ�*/
void put_asc16( int x,int y,char  *s,unsigned int color);

/*����asc16����ַ�*/
void put_asc16_ch( int x,int y,char  s,unsigned int color);	

/*��ȡASCII��ģ*/
void Read_Asc16(char key,unsigned char *buf);

/*����asc16����ַ�*/
void Put_Asc16(int cx,int cy,char key,unsigned int color);

/*����asc16����Ŵ��ַ�*/
void Put_Asc16_Size(int cx,int cy,int xsize,int ysize,char key,unsigned int color);

/*��ʾ�Ŵ�������*/
void put_asc16_number_size(int x,int y,int xsize,int ysize,int n,unsigned int color );

/*��ʾ�Ŵ�������,lΪ���ǳ���*/
void put_asc16_number_size_coverd(int x,int y,int xsize,int ysize,int l,int n,unsigned int color );

/*����asc16����Ŵ��ַ���*/   //��ǣ��᳣��
void put_asc16_size(int cx,int cy,int xsize,int ysize,char *s,unsigned int color );

/*�������16*xsize*16*ysize��������16*xsize*16*ysize asc�ַ����ַ���������x,y��ʾ�������λ�ã�
xsize,ysizeΪ�Ŵ�����sΪ����ַ�����color��ʾ������ɫ��name Ϊ���ֿ��ļ�·������������Ϣ*/
void put_hz16_asc16_size(int x, int y, int xsize,int ysize,char *s, unsigned int color, char * name);

/*�������24*24��������32*32 asc�ַ����ַ���������x,y��ʾ�������λ��
��sΪ����ַ�����color��ʾ������ɫ��name Ϊ���ֿ��ļ�·������������Ϣ*/
void put_hz24_asc32(int x, int y,char *s, unsigned int color, char * name);

/*��������12*24����ҷ��ţ�����*/
void RMB(int x,int y,int xsize,int ysize,unsigned color);
void puthz(int x, int y,char *s,int flag,int part,int color);

#endif

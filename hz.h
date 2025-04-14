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

/*调用16汉字库输出16*16点阵汉字*/
void put_hz16(int x, int y, char *s, unsigned int color, char * name,int flag);

/*调用24汉字库输出24*24点阵文字*/
void put_hz24(int x, int y,char * s, unsigned int color, char * name,int flag);
void put_hz32(int x, int y, char *s, unsigned int color, char * name,int flag);
void put_hz48(int x, int y, char *s, unsigned int color, char * name,int flag);
/*调用24汉字库输出24*24点阵文字（无延迟）*/
//void prt_hz24d(int x, int y,char * s, unsigned int color, char * name);

/*调用16汉字库输出16*xsize*16*ysize点阵汉字，x,y表示汉字输出位置，xsize,ysize为放大倍数，
s为汉字串，color表示汉字颜色，name 为汉字库文件路径，即字体信息*/
void put_hz16_size(int x, int y, int xsize,int ysize,char *s, unsigned int color, char * name);


/*调用asc16输出字符*/
void put_asc16( int x,int y,char  *s,unsigned int color);

/*调用asc16输出字符*/
void put_asc16_ch( int x,int y,char  s,unsigned int color);	

/*读取ASCII字模*/
void Read_Asc16(char key,unsigned char *buf);

/*调用asc16输出字符*/
void Put_Asc16(int cx,int cy,char key,unsigned int color);

/*调用asc16输出放大字符*/
void Put_Asc16_Size(int cx,int cy,int xsize,int ysize,char key,unsigned int color);

/*显示放大后的数字*/
void put_asc16_number_size(int x,int y,int xsize,int ysize,int n,unsigned int color );

/*显示放大后的数字,l为覆盖长度*/
void put_asc16_number_size_coverd(int x,int y,int xsize,int ysize,int l,int n,unsigned int color );

/*调用asc16输出放大字符串*/   //标记，会常用
void put_asc16_size(int cx,int cy,int xsize,int ysize,char *s,unsigned int color );

/*输出既有16*xsize*16*ysize汉字又有16*xsize*16*ysize asc字符的字符串函数，x,y表示汉字输出位置，
xsize,ysize为放大倍数，s为混合字符串，color表示汉字颜色，name 为汉字库文件路径，即字体信息*/
void put_hz16_asc16_size(int x, int y, int xsize,int ysize,char *s, unsigned int color, char * name);

/*输出既有24*24汉字又有32*32 asc字符的字符串函数，x,y表示汉字输出位置
，s为混合字符串，color表示汉字颜色，name 为汉字库文件路径，即字体信息*/
void put_hz24_asc32(int x, int y,char *s, unsigned int color, char * name);

/*画整数倍12*24人民币符号￥函数*/
void RMB(int x,int y,int xsize,int ysize,unsigned color);
void puthz(int x, int y,char *s,int flag,int part,int color);

#endif

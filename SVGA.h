#ifndef	SVGA_H
#define	SVGA_H

#define	SCR_WIDTH	1024	 //屏幕宽度像素 
#define	SCR_HEIGHT	768		 //屏幕高度像素 

/***bmp文件信息区***/
/*typedef struct BMP_file
{
	unsigned int bfType;           //文件类型，“BM”，bmp文件标识
	unsigned long bfSize;            //bmp文件长度，以字节为单位
	unsigned int Reserved1;
	unsigned int reserved2;
	unsigned long bfOffset;               //文件描述区长度，从文件头开始到实际的图象数据之间的字节的偏移量
}bitmapfile;*/


/***bmp图像信息区***/
/*typedef struct BMP_info
{
	unsigned long biSize;           //图像尺寸（以像素为单位）
	unsigned long biWidth;              //图形宽度（以像素为单位）
	unsigned long biHeight;             //图形高度（以像素为单位）
	unsigned int biPlanes; 
	unsigned int biBitCount;        //每个像素占二进制位数
	unsigned long biCompression;           //是否是压缩格式
	unsigned long biSizeImage;
	unsigned long biXpolsPerMeter;
	unsigned long biYpelsPerMeter;
	unsigned long biClrUsed;          //所用颜色数
	unsigned long biClrImportant;
}bitmapinfo; */

/***8位bmp调色板区***/
typedef struct RGB_BMP_typ
{
	unsigned char b;	//蓝色分量，BLUE缩写
	unsigned char g;	//绿色分量，GREEN缩写
	unsigned char r;	//红色分量， RED缩写
	unsigned char reserved;		//保留字
}RGBQUAD;

/***一个完整的bmp文件结构***/
/*typedef struct bmp_picture_type
{
	bitmapfile file;
	bitmapinfo info;
	RGB_BMP palette[256];
	char far *buffer;
}*/
/*24位bmp图颜色结构*/
typedef struct
{
	unsigned char B;	/*蓝色分量，BLUE缩写*/
	unsigned char G;	/*绿色分量，GREEN缩写*/
	unsigned char R;	/*红色分量，RED缩写*/
} COLORS24;

typedef unsigned char uint8_t;



/***设置SVGA显示模式为0x117,为1024*768*64k***/

void SetSVGA64k(void);
/***换页函数***/
extern void Selectpage(register char page);

/***显示24位非压缩bmp图***/
int Readbmp64k(int x, int y, const char * path);

/***0x117模式下画点函数***/
void Putpixel64k(int x, int y, unsigned int color);


/***24位显示模式下划水平、竖直线***/
void line_hor_ver(int x1, int y1, int x2, int y2, unsigned int color);

/***24位显示模式下划任意线***/
void line(int x1, int y1, int x2, int y2, unsigned int color);

/***24位显示模式下划粗直线***/
void line_hor_ver_thick(int x1, int y1, int x2, int y2, int radius,unsigned int color);

/***画粗实线***/
void line_thick(int x1, int y1, int x2, int y2, int radius,unsigned int color);


/***画矩形块函数(24位）***/
void bar(int x1, int y1, int x2, int y2, unsigned int color);

/***24位显示模式下画矩形(不填色)***/
void bar_frame(int x1,int y1,int x2,int y2,unsigned int color);

/***画圆函数（24位）***/
void circle_frame(int xc, int yc, int radius, unsigned int color);

/***画实心圆函数（24位）***/
void circle_fill(int xc, int yc, int radius, unsigned int color);

/***画按钮***/
//void Cirbar(int x1, int y1, int x2, int y2, unsigned int color);

/***关闭图形显示模式***/
void CloseSVGA(void);

int SaveBMP(int x1, int y1, int x2, int y2,int n);    //储存图像

void LoadBMP(int x1, int y1, int x2, int y2,int n);     //加载图像

void Get_image(int x0,int y0,int x1,int y1,unsigned int far *save);

void Put_image(int x0,int y0,int x1,int y1,unsigned int far *save);

int GenerateBMP(int x1, int y1, int x2, int y2);
void cleardevice(void);
#endif


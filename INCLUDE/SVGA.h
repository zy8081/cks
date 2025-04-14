#ifndef	SVGA_H
#define	SVGA_H

#define	SCR_WIDTH	1024	 //��Ļ������� 
#define	SCR_HEIGHT	768		 //��Ļ�߶����� 

/***bmp�ļ���Ϣ��***/
/*typedef struct BMP_file
{
	unsigned int bfType;           //�ļ����ͣ���BM����bmp�ļ���ʶ
	unsigned long bfSize;            //bmp�ļ����ȣ����ֽ�Ϊ��λ
	unsigned int Reserved1;
	unsigned int reserved2;
	unsigned long bfOffset;               //�ļ����������ȣ����ļ�ͷ��ʼ��ʵ�ʵ�ͼ������֮����ֽڵ�ƫ����
}bitmapfile;*/


/***bmpͼ����Ϣ��***/
/*typedef struct BMP_info
{
	unsigned long biSize;           //ͼ��ߴ磨������Ϊ��λ��
	unsigned long biWidth;              //ͼ�ο�ȣ�������Ϊ��λ��
	unsigned long biHeight;             //ͼ�θ߶ȣ�������Ϊ��λ��
	unsigned int biPlanes; 
	unsigned int biBitCount;        //ÿ������ռ������λ��
	unsigned long biCompression;           //�Ƿ���ѹ����ʽ
	unsigned long biSizeImage;
	unsigned long biXpolsPerMeter;
	unsigned long biYpelsPerMeter;
	unsigned long biClrUsed;          //������ɫ��
	unsigned long biClrImportant;
}bitmapinfo; */

/***8λbmp��ɫ����***/
typedef struct RGB_BMP_typ
{
	unsigned char b;	//��ɫ������BLUE��д
	unsigned char g;	//��ɫ������GREEN��д
	unsigned char r;	//��ɫ������ RED��д
	unsigned char reserved;		//������
}RGBQUAD;

/***һ��������bmp�ļ��ṹ***/
/*typedef struct bmp_picture_type
{
	bitmapfile file;
	bitmapinfo info;
	RGB_BMP palette[256];
	char far *buffer;
}*/
/*24λbmpͼ��ɫ�ṹ*/
typedef struct
{
	unsigned char B;	/*��ɫ������BLUE��д*/
	unsigned char G;	/*��ɫ������GREEN��д*/
	unsigned char R;	/*��ɫ������RED��д*/
} COLORS24;

typedef unsigned char uint8_t;



/***����SVGA��ʾģʽΪ0x117,Ϊ1024*768*64k***/

void SetSVGA64k(void);
/***��ҳ����***/
extern void Selectpage(register char page);

/***��ʾ24λ��ѹ��bmpͼ***/
int Readbmp64k(int x, int y, const char * path);

/***0x117ģʽ�»��㺯��***/
void Putpixel64k(int x, int y, unsigned int color);


/***24λ��ʾģʽ�»�ˮƽ����ֱ��***/
void line_hor_ver(int x1, int y1, int x2, int y2, unsigned int color);

/***24λ��ʾģʽ�»�������***/
void line(int x1, int y1, int x2, int y2, unsigned int color);

/***24λ��ʾģʽ�»���ֱ��***/
void line_hor_ver_thick(int x1, int y1, int x2, int y2, int radius,unsigned int color);

/***����ʵ��***/
void line_thick(int x1, int y1, int x2, int y2, int radius,unsigned int color);


/***�����ο麯��(24λ��***/
void bar(int x1, int y1, int x2, int y2, unsigned int color);

/***24λ��ʾģʽ�»�����(����ɫ)***/
void bar_frame(int x1,int y1,int x2,int y2,unsigned int color);

/***��Բ������24λ��***/
void circle_frame(int xc, int yc, int radius, unsigned int color);

/***��ʵ��Բ������24λ��***/
void circle_fill(int xc, int yc, int radius, unsigned int color);

/***����ť***/
//void Cirbar(int x1, int y1, int x2, int y2, unsigned int color);

/***�ر�ͼ����ʾģʽ***/
void CloseSVGA(void);

int SaveBMP(int x1, int y1, int x2, int y2,int n);    //����ͼ��

void LoadBMP(int x1, int y1, int x2, int y2,int n);     //����ͼ��

void Get_image(int x0,int y0,int x1,int y1,unsigned int far *save);

void Put_image(int x0,int y0,int x1,int y1,unsigned int far *save);

int GenerateBMP(int x1, int y1, int x2, int y2);
void cleardevice(void);
#endif


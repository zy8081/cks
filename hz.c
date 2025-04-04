#include "hz.h"


/*16位点阵汉字输出，x,y表示汉字输出位置，s为汉字串，color表示汉字颜色，flag为1时延时打字，0时不延时
name 为汉字库文件路径，即字体信息*/

void put_hz16(int x, int y, char *s, unsigned int color, char * name ,int flag) 
{
	FILE *fp;
	char buffer[32]={0};                                          //用来读取16汉字的32位字模
	int i=0;
	int j=0;
	unsigned char qh =0;     
    unsigned char wh =0; 	     //汉字区位号
	unsigned long offset=0;     //汉字内码
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //用来屏蔽出每一位的信息
						  0x02,0x01};
	fp=NULL;
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
	while(*s)                                         //若汉字串未读完，则继续
    {
		qh=* s-160;                                       //得到汉字内码
        wh=*(s+1) -160;
        offset=(94*(qh-1)+(wh-1))*32L;                     //计算位移量
        fseek(fp,offset, SEEK_SET);                        //汉字库文件中查找内码位置
        fread(buffer, 32, 1, fp);                          //读取相应位置的字模
        for(i=0;i<16;i++)                                  //在指定点输出一个汉字
		{
			for(j=0;j<16;j++)
			{
				if((mask[j%8] & buffer[i*2+j/8])!=0)
				{
					Putpixel64k(x+j,y+i,color);
				}
			}
		}
		x+=16;                                          //横向输出，间距为16
		s+=2;                                           //读取下一个汉字
		if (flag)
		{
			delay(50);
		}
	}
    fclose(fp);
}


/*24位点阵汉字输出，x,y表示汉字输出位置，s为汉字串，color表示汉字颜色，
name 为汉字库文件路径，即字体信息*/
void put_hz24(int x, int y,char * s, unsigned int color, char * name, int flag)    
{
	FILE * fp=NULL;
	char buffer[72]={0};                                            //用来读取24汉字的72位字模
	int i=0;
	int j=0;
	unsigned char qh=0;
	unsigned char wh=0;
	unsigned long offset=0;
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //用来屏蔽出每一位的信息
						  0x02,0x01};
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk24!");
        getch();
        exit(0);
    }
    while(*s)
    {
        qh=* s-160;
        wh=*(s+1)-160;
        offset=(94*(qh-1)+(wh-1))*72L;             
        fseek(fp,offset, SEEK_SET);
		fread(buffer, 72, 1, fp);
        for(i=0; i<24; i++)                                 //输出一个汉字
		{  
		   for(j=0;j<24;j++)
			{
				if((mask[j%8] & buffer[i*3+j/8])!=0)
				{
					Putpixel64k(x+j,y+i,color);
				}					
			}
		}
        s+=2;
        x+=24;                                         //行输出，间距24
		if (flag)
		{
			delay(50);
		}                                  //使每个汉字输出过程可见，起到美化效果的作用
    }
    fclose(fp);
}

/*32位点阵汉字输出，x,y表示汉字输出位置，s为汉字串，color表示汉字颜色，
name 为汉字库文件路径，即字体信息*/
void put_hz32(int x, int y, char *s, unsigned int color, char * name ,int flag) 
{
	FILE *fp;
	char buffer[128]={0};                                          //用来读取32汉字的128位字模
	int i=0;
	int j=0;
	unsigned char qh =0;     
    unsigned char wh =0; 	     //汉字区位号
	unsigned long offset=0;     //汉字内码
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //用来屏蔽出每一位的信息
						  0x02,0x01};
	fp=NULL;
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
	while(*s)                                         //若汉字串未读完，则继续
    {
		qh=* s-160;                                       //得到汉字内码
        wh=*(s+1) -160;
        offset=(94*(qh-1)+(wh-1))*128L;                     //计算位移量
        fseek(fp,offset, SEEK_SET);                        //汉字库文件中查找内码位置
        fread(buffer, 128, 1, fp);                          //读取相应位置的字模
        for(i=0;i<32;i++)                                  //在指定点输出一个汉字
		{
			for(j=0;j<32;j++)
			{
				if((mask[j%8] & buffer[i*4+j/8])!=0)
				{
					Putpixel64k(x+j,y+i,color);
				}
			}
		}
		x+=32;                                          //横向输出，间距为32
		s+=2; 			//读取下一个汉字
		if (flag)
		{
			delay(50);
		}        
	}
    fclose(fp);
}
/*48位点阵汉字输出，x,y表示汉字输出位置，s为汉字串，color表示汉字颜色，
name 为汉字库文件路径，即字体信息*/
void put_hz48(int x, int y, char *s, unsigned int color, char * name ,int flag) 
{
	FILE *fp;
	char buffer[288]={0};                                          //用来读取48汉字的288位字模
	int i=0;
	int j=0;
	unsigned char qh =0;     
    unsigned char wh =0; 	     //汉字区位号
	unsigned long offset=0;     //汉字内码
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //用来屏蔽出每一位的信息
						  0x02,0x01};
	fp=NULL;
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
	while(*s)                                         //若汉字串未读完，则继续
    {
		qh=* s-160;                                       //得到汉字内码
        wh=*(s+1) -160;
        offset=(94*(qh-1)+(wh-1))*288L;                     //计算位移量
        fseek(fp,offset, SEEK_SET);                        //汉字库文件中查找内码位置
        fread(buffer, 288, 1, fp);                          //读取相应位置的字模
        for(i=0;i<48;i++)                                  //在指定点输出一个汉字
		{
			for(j=0;j<48;j++)
			{
				if((mask[j%8] & buffer[i*6+j/8])!=0)
				{
					Putpixel64k(x+j,y+i,color);
				}
			}
		}
		x+=48;                                          //横向输出，间距为48
		s+=2; 			//读取下一个汉字
		if (flag)
		{
			delay(50);
		}  
	}
    fclose(fp);
}



void put_asc16( int x,int y,char * s,unsigned int color)		//输出一串英文函数
{

	FILE *  fp=NULL;
	int i=0;
	int j=0;
	unsigned long offset=0;
	char buffer[16]={0};
	if ((fp=fopen("hzk\\ASC16","rb"))==NULL)
	{
            printf("asc16 wrong!");		
            exit(1);
	}
	while(*s)
    { 
		offset=*s * 16L;                         	//计算位移量
		fseek(fp,offset,0);
		fread(buffer,16,1,fp);                        	//读出字模信息
		
		for(i=0;i<16;i++)
		{
			for(j=0;j<8;j++)
			{
				if((buffer[i]>>(7-j))&0x1)    	//为1的位显示
				{
					Putpixel64k(x+j,y+i,color);
				}
			}
		}
		s++;
		x+=10;
   }
	fclose(fp);
}

void put_asc16_ch( int x,int y,char s,unsigned int color)		//输出一个英文函数
{

	FILE *  fp=NULL;
	int i=0;
	int j=0;
	unsigned long offset=0;
	char buffer[16]={0};
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //用来屏蔽出每一位的信息
						  0x02,0x01};
	if ((fp=fopen("hzk\\ASC16","rb"))==NULL)
	{
                  printf("asc16 wrong!");
				  getch();		
                     exit(1);
	}
	offset=s * 16L;                         	//计算位移量
	fseek(fp,offset,0);
	fread(buffer,16,1,fp);                        	//读出字模信息	
	for(i=0;i<16;i++)
	{
		for(j=0;j<8;j++)
		{
			if((mask[j] & buffer[i])!=0)    	
			{
				Putpixel64k(x+j,y+i,color);
			}
		}
	}
	fclose(fp);
}

//读取英文字符并保存于buffer中
void Read_Asc16(char key,unsigned char *buffer)
{
    unsigned long offset=0;
	FILE*fp=NULL;
	if ((fp=fopen("hzk\\ASC16","rb"))==NULL)
	{
                  printf("asc16 wrong!");
				  getch();		
                     exit(1);
	}
	offset=key* 16L;                         	//计算位移量
	fseek(fp,offset,0);
	fread(buffer,16,1,fp);                    //读出字模信息	
	fclose(fp);
}

//利用内存显示英文字符
void Put_Asc16(int x,int y,char key,unsigned int color)
{
    int i=0;
	int j=0;
    unsigned char buffer[16];
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //用来屏蔽出每一位的信息
						  0x02,0x01};
    Read_Asc16(key,buffer);
    for(i=0;i<16;i++)
        for(j=0;j<8;j++)
            if((mask[j] & buffer[i])!=0)
                Putpixel64k(x+i,y+j,color);
}

/*显示放大后的英文字符*/  
void Put_Asc16_Size(int x,int y,int xsize,int ysize,char key,unsigned int color)
{
	int i=0;
	int j=0;
	int m=0;
	int n=0;
	unsigned char buffer[16]={0};
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //用来屏蔽出每一位的信息
						  0x02,0x01};
	Read_Asc16(key,buffer);
	for(i=0;i<16;i++)
		for(j=0;j<8;j++)
	        for(m=1;m<=ysize;m++)
				for(n=1;n<=xsize;n++)
					if((mask[j] & buffer[i])!=0)
				        Putpixel64k(x+j*xsize+n,y+m+i*ysize,color);
}

/*显示放大后的英文和数字字符串*/
void put_asc16_size(int x,int y,int xsize,int ysize,char *s,unsigned int color )
{
    int i=0;
    for(i=0;s[i]!=0;i++)
    {
		Put_Asc16_Size(x+i*xsize*8,y,xsize,ysize,s[i],color);
    }
}

/*显示放大后的数字*/
void put_asc16_number_size(int x,int y,int xsize,int ysize,int n,unsigned int color )
{
	char *s=0;
	int i=0;
	itoa(n,s,10);
    for(i=0;s[i]!=0;i++)
    {
		Put_Asc16_Size(x+i*xsize*8,y,xsize,ysize,s[i],color);
    }
}

/*显示放大后的数字,l为覆盖长度*/
void put_asc16_number_size_coverd(int x,int y,int xsize,int ysize,int l,int n,unsigned int color )
{
	char *s=0;
	int i=0;
	itoa(n,s,10);
	for(i=0;i<l;i++)
	{
		line_thick(x+i,y,x+i,y+16*ysize,1,Getpixel64k(x+i,y-1));
	}
    for(i=0;s[i]!=0;i++)
    {
		Put_Asc16_Size(x+i*xsize*8,y,xsize,ysize,s[i],color);
    }
}

/*x,y表示汉字输出位置，xsize,ysize为放大倍数，s为汉字串，color表示汉字颜色，name 为汉字库文件路径，即字体信息*/
void put_hz16_size(int x, int y, int xsize,int ysize,char *s, unsigned int color, char * name)  
{
	FILE * fp;
	char buffer[32];                                          //用来读取16汉字的32位字模
	int i=0;
	int j=0;
	int m=0;
	int n=0;
	unsigned char qh=0;          	//用来计算汉字位号和区号
	unsigned char wh=0;    
	unsigned long offset=0;                                     //记录位移量
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //用来屏蔽出每一位的信息
						  0x02,0x01};
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
	while(*s!=0)                                         //若汉字串未读完，则继续
    {
		qh=* s-160;                                       //计算区号和位号
        wh=*(s+1) -160;
        offset=(94L*(qh-1)+(wh-1))*32;                     //计算汉字的地址码
        fseek(fp,offset, 0);                        //汉字库文件中查找内码位置
        fread(buffer, 32, 1, fp);                          //读取相应位置的字模
        for(i=0;i<16;i++)                                  //在指定点输出一个汉字
		{
			for(j=0;j<16;j++)
			{
				if((mask[j%8] & buffer[i*2+j/8])!=0)
				{
					for(m=0;m<xsize;m++)
					{
						for(n=0;n<ysize;n++)
					    {
							Putpixel64k(x+j*xsize+m,y+i*ysize+n,color);
        				}
					}
				}
			}
		}
	    x+=16*xsize;                                          //横向输出，间距为16*xsize
		s+=2;                                           //读取下一个汉字
    }
    fclose(fp);
}

/*输出既有16*16汉字又有16*16asc字符的字符串函数，x,y表示汉字输出位置，xsize,ysize为放大倍数，s为混合字符串，
color表示字符颜色，name 为汉字库文件路径，即字体信息*/
void put_hz16_asc16_size(int x, int y, int xsize,int ysize,char *s, unsigned int color, char * name)
{
	FILE * fp1=NULL;
	FILE * fp2=NULL;
	char buffer1[16]={0};                                          //用来读取16ascll字符的16位字模
	char buffer2[32]={0};                                          //用来读取16汉字的32位字模
	int i=0;
	int j=0;
	int m=0;
	int n=0;                                                             //循环变量
	unsigned char qh=0;
    unsigned char wh=0;                                    //用来计算汉字区位号
	unsigned long offset=0;                               //记录位移量
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //用来屏蔽出字模每一位的信息
						  0x02,0x01};
	if ((fp1=fopen("hzk\\ASC16","rb"))==NULL)
	{
        CloseSVGA();
		printf("asc16 wrong!");		
        getch();            
		exit(1);
	}
	if((fp2=fopen(name,"rb"))==NULL)
	{
		CloseSVGA();
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
 
	while(*s!=0)                                         //若混合字符串未读完，则继续
    {
        if((*s&0x80)==0)                               //若该字符字节最高位为0，表明该字节ASCII码，输出字符
		{
			offset=*s * 16L;                         	//计算位移量
	        fseek(fp1,offset,0);
	        fread(buffer1,16,1,fp1);                //读出字模信息
		    for(i=0;i<16;i++)                         //在指定点输出一个放大后的字符
			{
				for(j=0;j<8;j++)
				{
					if(mask[j]&buffer1[i])
					{
						for(m=0;m<xsize;m++)
						{
							for(n=0;n<ysize;n++)
						    {
	                            Putpixel64k(x+j*xsize+m,y+2*ysize+i*ysize+n,color); //y+2*ysize是为了平衡汉字与英文字符的高度
							}
						}
					}
				}
			}
			x+=8*xsize;           //横向输出，间距为8*xsize
			s++;		                //读取下一个字符
		}		
		else if((*s&0x80)!=0)                                     //若该字符字节最高位为1，表明该字节为汉字内码一部分，输出汉字  
		{
			qh=* s-160;                                       //计算区号和位号
    	    wh=*(s+1) -160;
     	    offset=(94L*(qh-1)+(wh-1))*32;  //计算汉字的地址码
   	   	    fseek(fp2,offset, 0);                        //汉字库文件中查找内码位置
  	        fread(buffer2, 32, 1, fp2);                  //读取相应位置的字模
  	        for(i=0;i<16;i++)                               //在指定点输出一个放大后的汉字
			{
				for(j=0;j<16;j++)
				{
					if((mask[j%8] & buffer2[i*2+j/8])!=0)
					{
						for(m=0;m<xsize;m++)
						{
							for(n=0;n<ysize;n++)
						    {
								Putpixel64k(x+j*xsize+m,y+i*ysize+n,color);
							}
						}
					}					
				}
			}
			x+=16*xsize;              //横向输出，间距为16*xsize
			s+=2;   			             //读取下一个字符
        }
	}
    fclose(fp1);
	fclose(fp2);
}	

/*输出既有24*24汉字又有32*32 asc字符的字符串函数，x,y表示汉字输出位置，s为混合字符串，
color表示字符颜色，name 为汉字库文件路径，即字体信息*/
void put_hz24_asc32(int x, int y,char *s, unsigned int color, char * name)
{
	FILE * fp1=NULL;
	FILE * fp2=NULL;
	char buffer1[16]={0};                                          //用来读取12ascll字符的12位字模
	char buffer2[72]={0};                                          //用来读取24汉字的72位字模
	int i=0;
	int j=0;
	int m=0;
	int n=0;                                                             //循环变量
	unsigned char qh=0;
    unsigned char wh=0;                                    //用来计算汉字区位号
	unsigned long offset=0;                               //记录位移量
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //用来屏蔽出字模每一位的信息
						  0x02,0x01};
	if ((fp1=fopen("hzk\\ASC16","rb"))==NULL)
	{
        CloseSVGA();
		printf("asc16 wrong!");		
        getch();            
		exit(1);
	}
	if((fp2=fopen(name,"rb"))==NULL)
	{
		CloseSVGA();
		printf("Can't open hzk24!");
		getch();
		exit(0);
	}
	while(*s!=0)                                         //若混合字符串未读完，则继续
    {
        if((*s&0x80)==0)                               //若该字符字节最高位为0，表明该字节ASCII码，输出字符
		{
			offset=*s * 16L;                         	//计算位移量
	        fseek(fp1,offset,0);
	        fread(buffer1,16,1,fp1);                //读出字模信息
		    for(i=0;i<16;i++)                              //在指定点输出一个32*32字符
			{
				for(j=0;j<8;j++)
				{
					if(mask[j]&buffer1[i])
					{
						for(m=0;m<2;m++)
						{
							for(n=0;n<2;n++)
						    {
	                            Putpixel64k(x+j*2+m,y-2+i*2+n,color); //y-2是为了平衡汉字与英文字符的高度
							}
						}
					}
				}
			}
			x+=8*2;           //横向输出，间距为16
			s++;		                //读取下一个字符
		}		
		else if((*s&0x80)!=0)                                     //若该字符字节最高位为1，表明该字节为汉字内码一部分，输出汉字  
		{
			qh=* s-160;                                       //计算区号和位号
    	    wh=*(s+1) -160;
     	    offset=(94L*(qh-1)+(wh-1))*72;  //计算汉字的地址码
   	   	    fseek(fp2,offset, 0);                        //汉字库文件中查找内码位置
  	        fread(buffer2, 72, 1, fp2);                  //读取相应位置的字模
  	        for(i=0;i<24;i++)                               //在指定点输出一个放大后的汉字
			{
				for(j=0;j<24;j++)
				{
					if((mask[j%8] & buffer2[i*3+j/8])!=0)
					{
						Putpixel64k(x+j,y+i,color);
					}					
				}
			}
			x+=24;              //横向输出，间距为24
			s+=2;   			             //读取下一个字符
        }
	}
    fclose(fp1);
	fclose(fp2);
}	
	
/*画整数倍12*24人民币符号￥函数*/
void RMB(int x,int y,int xsize,int ysize,unsigned color)
{
	int i=0;
	int j=0;
	int m=0;
	int n=0;  //循环变量
	int RMB[24][12]={
	    {0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,0,0,0,1,1,1,1},
		{0,1,1,0,0,0,0,0,0,1,1,0},
		{0,1,1,0,0,0,0,0,0,1,0,0},
		{0,0,1,1,0,0,0,0,1,1,0,0},
		{0,0,0,1,0,0,0,0,1,0,0,0},
	    {0,0,0,1,1,0,0,1,1,0,0,0},
		{0,0,0,0,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
	    {1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0},
	    {0,0,0,1,1,1,1,1,1,0,0,0}}; //储存人民币图标的数组
		
	for(i=0;i<24;i++)
	{
		for(j=0;j<12;j++)
		{
			if(RMB[i][j]!=0)
			    for(m=0;m<xsize;m++)
			    {
				    for(n=0;n<ysize;n++)
				    {
					    Putpixel64k(x+j*xsize+m,y+i*ysize+n,color);
				    }
			    } 
		}
	}
}

void puthz(int x, int y,char *s,int flag,int part,int color)
{
	FILE *hzk_p=NULL;                                       //定义汉字库文件指针
	unsigned char quma,weima;                 //定义汉字的区码和位码
	unsigned long offset;                          //定义汉字在字库中的偏移量
	unsigned char mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};  //功能数组，用于显示汉字点阵中的亮点
	int i,j,pos;

	switch(flag)    //不同的flag对应不同的汉字库，实现了汉字的大小可根据需要改变
	{
		case 16 :
				  {
					 char mat[32];   //16*16的汉字需要32个字节的数组来存储
					int y0=y;
					int x0=x;
					 hzk_p = fopen("HZK\\HZ16","rb");            //使用相对路径
					 if(hzk_p==NULL)
					 {
						CloseSVGA();
						printf("cant open HZ16");
						 getch();
						 exit(1);

					}
					while(*s!=NULL)
					{
						while (x<1024-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                      //求出区码
							weima=s[1]-0xa0;                     //求出位码
							offset=(94*(quma-1)+(weima-1))*32L;   //求出要显示的汉字在字库文件中的偏移
							fseek(hzk_p,offset,SEEK_SET);         //重定位文件指针
							fread (mat,32,1,hzk_p);            //读出该汉字的具体点阵数据,1为要读入的项数

							for(i=0;i<16;i++)
							{
								pos=2*i;       //16*16矩阵中有每一行有两外字节
								for(j=0;j<16;j++)    //一行一行地扫描，将位上为了1的点显示出来
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8只能在0—8之间循环，j/8在0，1之间循环
									{
										Putpixel64k(x+j,y,color);

									}

								}
								y++;


							}
							/*====================================================
								以上是一个汉字显示完
							====================================================*/
							x+=part;        //给x 一个偏移量part
							s+=2;           //汉字里存放的是内码，2个字节，所以要加2

						}
						x=x0;y0+=flag+10; //一行汉字显示完后,重新从左侧开始输出汉字，给y一个偏移量
					}

					break;

				 }


		case 24 :
				  {
					char mat[72];   //24*24矩阵要72个字节来存储
					 int y0=y;
					 int x0=x;
					hzk_p = fopen("HZK\\Hzk24k","rb");
					if (hzk_p==NULL)
					{
						CloseSVGA();
						printf("cant open HZ24");
						getch();
						exit(1);

					}
					while(*s!=NULL)
					{
						while(x<1024-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                      //求出区码
							weima=s[1]-0xa0;                     //求出位码
							offset=(94*(quma-1)+(weima-1))*72L;
							fseek(hzk_p,offset,SEEK_SET);
							fread (mat,72,1,hzk_p);
							for (i=0;i<24;i++)
							{
								pos=3*i;   //矩阵中每一行有三个字节
								for (j=0;j<24;j++)   // 每一行有24位
								{
									if ((mask[j%8]&mat[pos+j/8])!=NULL)
										Putpixel64k(x+j,y,color);

								}
								y++;

							}
							x+=part;
							s+=2;
						}
						x=x0;y0+=flag+10;
					}
						break;
				}

		case 32 :
				  {
					 char mat[128];   //32*32的汉字需要128个字节的数组来存储
					int y0=y;
					int x0=x;
					 hzk_p = fopen("HZK\\HZK32S","rb");
					 if(hzk_p==NULL)
					 {
						CloseSVGA();
						printf("cant open HZ32");
						 getch();
						 exit(1);

					}
					while(*s!=NULL)
					{
						while (x<1024-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                      //求出区码
							weima=s[1]-0xa0;                     //求出位码
							offset=(94*(quma-1)+(weima-1))*128L;
							fseek(hzk_p,offset,SEEK_SET);
							fread (mat,128,1,hzk_p);
							for(i=0;i<32;i++)
							{
								pos=4*i;       //32*32矩阵中有每一行有两外字节
								for(j=0;j<32;j++)
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)
									{
										Putpixel64k(x+j,y,color);

									}

								}
								y++;


							}
								//以上是一个汉字显示完
							x+=part;    //给x 一个偏移量part
							s+=2;          //汉字里存放的是内码，2个字节，所以要加2

						}
						x=x0;y0+=flag+10;   //一行汉字显示完后，给y一个偏移量
					}
						break;

				 }


		case 48:
				  {
					char mat[288];   //48*48的汉字需要288个字节的数组来存储
					int y0=y;
					int x0=x;
					 hzk_p = fopen("HZK\\Hzk48k","rb");
					 if(hzk_p==NULL)
					 {
						CloseSVGA();
						printf("cant open HZ48");
						 getch();
						 exit(1);

					}
					while(*s!=NULL)
					{
						while (x<1024-flag && (*s!=NULL))
						{
							y=y0;
							quma=s[0]-0xa0;                      //求出区码
							weima=s[1]-0xa0;                     //求出位码
							offset=(94*(quma-1)+(weima-1))*288L;   //求出要显示的汉字在字库文件中的偏移
							fseek(hzk_p,offset,SEEK_SET);         //重定位文件指针
							fread (mat,288,1,hzk_p);            //读出该汉字的具体点阵数据,1为要读入的项数

							for(i=0;i<48;i++)
							{
								pos=6*i;
								for(j=0;j<48;j++)    //一行一行地扫描，将位上为了1的点显示出来
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8只能在0—8之间循环，j/8在0，1之间循环
									{
										Putpixel64k(x+j,y,color);

									}

								}
								y++;
							}
								//以上是一个汉字显示完
							x+=part;    //给x 一个偏移量part
							s+=2;          //汉字里存放的是内码，2个字节，所以要加2

						}
						x=x0;y0+=flag+10;   //一行汉字显示完后，给y一个偏移量
					}
						break;

				}

		default:
				  break;

	}

	fclose(hzk_p);
}

//void puthz_coverd(int x, int y,char *s,int n,int flag,int part,int color)
//{
//	int i=0;
//	for(i=0;i<part*n;i++)
//	{
//		Line_Thick(x+i,y,x+i,y+flag+1,1,Getpixel64k(x+i,y-1));
//	}
//	puthz( x,  y, s, flag, part, color);
//
//}
//void puthz_coverd2(int x, int y,char *s,int n,int flag,int part,int color,int backcolor)
//{
//	int i=0;
//	for(i=0;i<part*n;i++)
//	{
//		Line_Thick(x+i,y,x+i,y+flag+1,1,backcolor);
//	}
//	puthz( x,  y, s, flag, part, color);
//
//}
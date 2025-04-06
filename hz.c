#include "hz.h"


/*16λ�����������x,y��ʾ�������λ�ã�sΪ���ִ���color��ʾ������ɫ��flagΪ1ʱ��ʱ���֣�0ʱ����ʱ
name Ϊ���ֿ��ļ�·������������Ϣ*/

void put_hz16(int x, int y, char *s, unsigned int color, char * name ,int flag) 
{
	FILE *fp;
	char buffer[32]={0};                                          //������ȡ16���ֵ�32λ��ģ
	int i=0;
	int j=0;
	unsigned char qh =0;     
    unsigned char wh =0; 	     //������λ��
	unsigned long offset=0;     //��������
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
	fp=NULL;
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
	while(*s)                                         //�����ִ�δ���꣬�����
    {
		qh=* s-160;                                       //�õ���������
        wh=*(s+1) -160;
        offset=(94*(qh-1)+(wh-1))*32L;                     //����λ����
        fseek(fp,offset, SEEK_SET);                        //���ֿ��ļ��в�������λ��
        fread(buffer, 32, 1, fp);                          //��ȡ��Ӧλ�õ���ģ
        for(i=0;i<16;i++)                                  //��ָ�������һ������
		{
			for(j=0;j<16;j++)
			{
				if((mask[j%8] & buffer[i*2+j/8])!=0)
				{
					Putpixel64k(x+j,y+i,color);
				}
			}
		}
		x+=16;                                          //������������Ϊ16
		s+=2;                                           //��ȡ��һ������
		if (flag)
		{
			delay(50);
		}
	}
    fclose(fp);
}


/*24λ�����������x,y��ʾ�������λ�ã�sΪ���ִ���color��ʾ������ɫ��
name Ϊ���ֿ��ļ�·������������Ϣ*/
void put_hz24(int x, int y,char * s, unsigned int color, char * name, int flag)    
{
	FILE * fp=NULL;
	char buffer[72]={0};                                            //������ȡ24���ֵ�72λ��ģ
	int i=0;
	int j=0;
	unsigned char qh=0;
	unsigned char wh=0;
	unsigned long offset=0;
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
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
        for(i=0; i<24; i++)                                 //���һ������
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
        x+=24;                                         //����������24
		if (flag)
		{
			delay(50);
		}                                  //ʹÿ������������̿ɼ���������Ч��������
    }
    fclose(fp);
}

/*32λ�����������x,y��ʾ�������λ�ã�sΪ���ִ���color��ʾ������ɫ��
name Ϊ���ֿ��ļ�·������������Ϣ*/
void put_hz32(int x, int y, char *s, unsigned int color, char * name ,int flag) 
{
	FILE *fp;
	char buffer[128]={0};                                          //������ȡ32���ֵ�128λ��ģ
	int i=0;
	int j=0;
	unsigned char qh =0;     
    unsigned char wh =0; 	     //������λ��
	unsigned long offset=0;     //��������
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
	fp=NULL;
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
	while(*s)                                         //�����ִ�δ���꣬�����
    {
		qh=* s-160;                                       //�õ���������
        wh=*(s+1) -160;
        offset=(94*(qh-1)+(wh-1))*128L;                     //����λ����
        fseek(fp,offset, SEEK_SET);                        //���ֿ��ļ��в�������λ��
        fread(buffer, 128, 1, fp);                          //��ȡ��Ӧλ�õ���ģ
        for(i=0;i<32;i++)                                  //��ָ�������һ������
		{
			for(j=0;j<32;j++)
			{
				if((mask[j%8] & buffer[i*4+j/8])!=0)
				{
					Putpixel64k(x+j,y+i,color);
				}
			}
		}
		x+=32;                                          //������������Ϊ32
		s+=2; 			//��ȡ��һ������
		if (flag)
		{
			delay(50);
		}        
	}
    fclose(fp);
}
/*48λ�����������x,y��ʾ�������λ�ã�sΪ���ִ���color��ʾ������ɫ��
name Ϊ���ֿ��ļ�·������������Ϣ*/
void put_hz48(int x, int y, char *s, unsigned int color, char * name ,int flag) 
{
	FILE *fp;
	char buffer[288]={0};                                          //������ȡ48���ֵ�288λ��ģ
	int i=0;
	int j=0;
	unsigned char qh =0;     
    unsigned char wh =0; 	     //������λ��
	unsigned long offset=0;     //��������
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
	fp=NULL;
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
	while(*s)                                         //�����ִ�δ���꣬�����
    {
		qh=* s-160;                                       //�õ���������
        wh=*(s+1) -160;
        offset=(94*(qh-1)+(wh-1))*288L;                     //����λ����
        fseek(fp,offset, SEEK_SET);                        //���ֿ��ļ��в�������λ��
        fread(buffer, 288, 1, fp);                          //��ȡ��Ӧλ�õ���ģ
        for(i=0;i<48;i++)                                  //��ָ�������һ������
		{
			for(j=0;j<48;j++)
			{
				if((mask[j%8] & buffer[i*6+j/8])!=0)
				{
					Putpixel64k(x+j,y+i,color);
				}
			}
		}
		x+=48;                                          //������������Ϊ48
		s+=2; 			//��ȡ��һ������
		if (flag)
		{
			delay(50);
		}  
	}
    fclose(fp);
}



void put_asc16( int x,int y,char * s,unsigned int color)		//���һ��Ӣ�ĺ���
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
		offset=*s * 16L;                         	//����λ����
		fseek(fp,offset,0);
		fread(buffer,16,1,fp);                        	//������ģ��Ϣ
		
		for(i=0;i<16;i++)
		{
			for(j=0;j<8;j++)
			{
				if((buffer[i]>>(7-j))&0x1)    	//Ϊ1��λ��ʾ
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

void put_asc16_ch( int x,int y,char s,unsigned int color)		//���һ��Ӣ�ĺ���
{

	FILE *  fp=NULL;
	int i=0;
	int j=0;
	unsigned long offset=0;
	char buffer[16]={0};
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
	if ((fp=fopen("hzk\\ASC16","rb"))==NULL)
	{
                  printf("asc16 wrong!");
				  getch();		
                     exit(1);
	}
	offset=s * 16L;                         	//����λ����
	fseek(fp,offset,0);
	fread(buffer,16,1,fp);                        	//������ģ��Ϣ	
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

//��ȡӢ���ַ���������buffer��
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
	offset=key* 16L;                         	//����λ����
	fseek(fp,offset,0);
	fread(buffer,16,1,fp);                    //������ģ��Ϣ	
	fclose(fp);
}

//�����ڴ���ʾӢ���ַ�
void Put_Asc16(int x,int y,char key,unsigned int color)
{
    int i=0;
	int j=0;
    unsigned char buffer[16];
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
    Read_Asc16(key,buffer);
    for(i=0;i<16;i++)
        for(j=0;j<8;j++)
            if((mask[j] & buffer[i])!=0)
                Putpixel64k(x+i,y+j,color);
}

/*��ʾ�Ŵ���Ӣ���ַ�*/  
void Put_Asc16_Size(int x,int y,int xsize,int ysize,char key,unsigned int color)
{
	int i=0;
	int j=0;
	int m=0;
	int n=0;
	unsigned char buffer[16]={0};
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
	Read_Asc16(key,buffer);
	for(i=0;i<16;i++)
		for(j=0;j<8;j++)
	        for(m=1;m<=ysize;m++)
				for(n=1;n<=xsize;n++)
					if((mask[j] & buffer[i])!=0)
				        Putpixel64k(x+j*xsize+n,y+m+i*ysize,color);
}

/*��ʾ�Ŵ���Ӣ�ĺ������ַ���*/
void put_asc16_size(int x,int y,int xsize,int ysize,char *s,unsigned int color )
{
    int i=0;
    for(i=0;s[i]!=0;i++)
    {
		Put_Asc16_Size(x+i*xsize*8,y,xsize,ysize,s[i],color);
    }
}

/*��ʾ�Ŵ�������*/
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

/*��ʾ�Ŵ�������,lΪ���ǳ���*/
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

/*x,y��ʾ�������λ�ã�xsize,ysizeΪ�Ŵ�����sΪ���ִ���color��ʾ������ɫ��name Ϊ���ֿ��ļ�·������������Ϣ*/
void put_hz16_size(int x, int y, int xsize,int ysize,char *s, unsigned int color, char * name)  
{
	FILE * fp;
	char buffer[32];                                          //������ȡ16���ֵ�32λ��ģ
	int i=0;
	int j=0;
	int m=0;
	int n=0;
	unsigned char qh=0;          	//�������㺺��λ�ź�����
	unsigned char wh=0;    
	unsigned long offset=0;                                     //��¼λ����
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ�ÿһλ����Ϣ
						  0x02,0x01};
	if((fp=fopen(name,"rb"))==NULL)
	{
		printf("Can't open hzk16!");
		getch();
		exit(0);
	}
	while(*s!=0)                                         //�����ִ�δ���꣬�����
    {
		qh=* s-160;                                       //�������ź�λ��
        wh=*(s+1) -160;
        offset=(94L*(qh-1)+(wh-1))*32;                     //���㺺�ֵĵ�ַ��
        fseek(fp,offset, 0);                        //���ֿ��ļ��в�������λ��
        fread(buffer, 32, 1, fp);                          //��ȡ��Ӧλ�õ���ģ
        for(i=0;i<16;i++)                                  //��ָ�������һ������
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
	    x+=16*xsize;                                          //������������Ϊ16*xsize
		s+=2;                                           //��ȡ��һ������
    }
    fclose(fp);
}

/*�������16*16��������16*16asc�ַ����ַ���������x,y��ʾ�������λ�ã�xsize,ysizeΪ�Ŵ�����sΪ����ַ�����
color��ʾ�ַ���ɫ��name Ϊ���ֿ��ļ�·������������Ϣ*/
void put_hz16_asc16_size(int x, int y, int xsize,int ysize,char *s, unsigned int color, char * name)
{
	FILE * fp1=NULL;
	FILE * fp2=NULL;
	char buffer1[16]={0};                                          //������ȡ16ascll�ַ���16λ��ģ
	char buffer2[32]={0};                                          //������ȡ16���ֵ�32λ��ģ
	int i=0;
	int j=0;
	int m=0;
	int n=0;                                                             //ѭ������
	unsigned char qh=0;
    unsigned char wh=0;                                    //�������㺺����λ��
	unsigned long offset=0;                               //��¼λ����
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ���ģÿһλ����Ϣ
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
 
	while(*s!=0)                                         //������ַ���δ���꣬�����
    {
        if((*s&0x80)==0)                               //�����ַ��ֽ����λΪ0���������ֽ�ASCII�룬����ַ�
		{
			offset=*s * 16L;                         	//����λ����
	        fseek(fp1,offset,0);
	        fread(buffer1,16,1,fp1);                //������ģ��Ϣ
		    for(i=0;i<16;i++)                         //��ָ�������һ���Ŵ����ַ�
			{
				for(j=0;j<8;j++)
				{
					if(mask[j]&buffer1[i])
					{
						for(m=0;m<xsize;m++)
						{
							for(n=0;n<ysize;n++)
						    {
	                            Putpixel64k(x+j*xsize+m,y+2*ysize+i*ysize+n,color); //y+2*ysize��Ϊ��ƽ�⺺����Ӣ���ַ��ĸ߶�
							}
						}
					}
				}
			}
			x+=8*xsize;           //������������Ϊ8*xsize
			s++;		                //��ȡ��һ���ַ�
		}		
		else if((*s&0x80)!=0)                                     //�����ַ��ֽ����λΪ1���������ֽ�Ϊ��������һ���֣��������  
		{
			qh=* s-160;                                       //�������ź�λ��
    	    wh=*(s+1) -160;
     	    offset=(94L*(qh-1)+(wh-1))*32;  //���㺺�ֵĵ�ַ��
   	   	    fseek(fp2,offset, 0);                        //���ֿ��ļ��в�������λ��
  	        fread(buffer2, 32, 1, fp2);                  //��ȡ��Ӧλ�õ���ģ
  	        for(i=0;i<16;i++)                               //��ָ�������һ���Ŵ��ĺ���
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
			x+=16*xsize;              //������������Ϊ16*xsize
			s+=2;   			             //��ȡ��һ���ַ�
        }
	}
    fclose(fp1);
	fclose(fp2);
}	

/*�������24*24��������32*32 asc�ַ����ַ���������x,y��ʾ�������λ�ã�sΪ����ַ�����
color��ʾ�ַ���ɫ��name Ϊ���ֿ��ļ�·������������Ϣ*/
void put_hz24_asc32(int x, int y,char *s, unsigned int color, char * name)
{
	FILE * fp1=NULL;
	FILE * fp2=NULL;
	char buffer1[16]={0};                                          //������ȡ12ascll�ַ���12λ��ģ
	char buffer2[72]={0};                                          //������ȡ24���ֵ�72λ��ģ
	int i=0;
	int j=0;
	int m=0;
	int n=0;                                                             //ѭ������
	unsigned char qh=0;
    unsigned char wh=0;                                    //�������㺺����λ��
	unsigned long offset=0;                               //��¼λ����
	unsigned char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,       //�������γ���ģÿһλ����Ϣ
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
	while(*s!=0)                                         //������ַ���δ���꣬�����
    {
        if((*s&0x80)==0)                               //�����ַ��ֽ����λΪ0���������ֽ�ASCII�룬����ַ�
		{
			offset=*s * 16L;                         	//����λ����
	        fseek(fp1,offset,0);
	        fread(buffer1,16,1,fp1);                //������ģ��Ϣ
		    for(i=0;i<16;i++)                              //��ָ�������һ��32*32�ַ�
			{
				for(j=0;j<8;j++)
				{
					if(mask[j]&buffer1[i])
					{
						for(m=0;m<2;m++)
						{
							for(n=0;n<2;n++)
						    {
	                            Putpixel64k(x+j*2+m,y-2+i*2+n,color); //y-2��Ϊ��ƽ�⺺����Ӣ���ַ��ĸ߶�
							}
						}
					}
				}
			}
			x+=8*2;           //������������Ϊ16
			s++;		                //��ȡ��һ���ַ�
		}		
		else if((*s&0x80)!=0)                                     //�����ַ��ֽ����λΪ1���������ֽ�Ϊ��������һ���֣��������  
		{
			qh=* s-160;                                       //�������ź�λ��
    	    wh=*(s+1) -160;
     	    offset=(94L*(qh-1)+(wh-1))*72;  //���㺺�ֵĵ�ַ��
   	   	    fseek(fp2,offset, 0);                        //���ֿ��ļ��в�������λ��
  	        fread(buffer2, 72, 1, fp2);                  //��ȡ��Ӧλ�õ���ģ
  	        for(i=0;i<24;i++)                               //��ָ�������һ���Ŵ��ĺ���
			{
				for(j=0;j<24;j++)
				{
					if((mask[j%8] & buffer2[i*3+j/8])!=0)
					{
						Putpixel64k(x+j,y+i,color);
					}					
				}
			}
			x+=24;              //������������Ϊ24
			s+=2;   			             //��ȡ��һ���ַ�
        }
	}
    fclose(fp1);
	fclose(fp2);
}	
	
/*��������12*24����ҷ��ţ�����*/
void RMB(int x,int y,int xsize,int ysize,unsigned color)
{
	int i=0;
	int j=0;
	int m=0;
	int n=0;  //ѭ������
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
	    {0,0,0,1,1,1,1,1,1,0,0,0}}; //���������ͼ�������
		
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
	FILE *hzk_p=NULL;                                       //���庺�ֿ��ļ�ָ��
	unsigned char quma,weima;                 //���庺�ֵ������λ��
	unsigned long offset;                          //���庺�����ֿ��е�ƫ����
	unsigned char mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};  //�������飬������ʾ���ֵ����е�����
	int i,j,pos;

	switch(flag)    //��ͬ��flag��Ӧ��ͬ�ĺ��ֿ⣬ʵ���˺��ֵĴ�С�ɸ�����Ҫ�ı�
	{
		case 16 :
				  {
					 char mat[32];   //16*16�ĺ�����Ҫ32���ֽڵ��������洢
					int y0=y;
					int x0=x;
					 hzk_p = fopen("HZK\\HZ16","rb");            //ʹ�����·��
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
							quma=s[0]-0xa0;                      //�������
							weima=s[1]-0xa0;                     //���λ��
							offset=(94*(quma-1)+(weima-1))*32L;   //���Ҫ��ʾ�ĺ������ֿ��ļ��е�ƫ��
							fseek(hzk_p,offset,SEEK_SET);         //�ض�λ�ļ�ָ��
							fread (mat,32,1,hzk_p);            //�����ú��ֵľ����������,1ΪҪ���������

							for(i=0;i<16;i++)
							{
								pos=2*i;       //16*16��������ÿһ���������ֽ�
								for(j=0;j<16;j++)    //һ��һ�е�ɨ�裬��λ��Ϊ��1�ĵ���ʾ����
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8ֻ����0��8֮��ѭ����j/8��0��1֮��ѭ��
									{
										Putpixel64k(x+j,y,color);

									}

								}
								y++;


							}
							/*====================================================
								������һ��������ʾ��
							====================================================*/
							x+=part;        //��x һ��ƫ����part
							s+=2;           //�������ŵ������룬2���ֽڣ�����Ҫ��2

						}
						x=x0;y0+=flag+10; //һ�к�����ʾ���,���´���࿪ʼ������֣���yһ��ƫ����
					}

					break;

				 }


		case 24 :
				  {
					char mat[72];   //24*24����Ҫ72���ֽ����洢
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
							quma=s[0]-0xa0;                      //�������
							weima=s[1]-0xa0;                     //���λ��
							offset=(94*(quma-1)+(weima-1))*72L;
							fseek(hzk_p,offset,SEEK_SET);
							fread (mat,72,1,hzk_p);
							for (i=0;i<24;i++)
							{
								pos=3*i;   //������ÿһ���������ֽ�
								for (j=0;j<24;j++)   // ÿһ����24λ
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
					 char mat[128];   //32*32�ĺ�����Ҫ128���ֽڵ��������洢
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
							quma=s[0]-0xa0;                      //�������
							weima=s[1]-0xa0;                     //���λ��
							offset=(94*(quma-1)+(weima-1))*128L;
							fseek(hzk_p,offset,SEEK_SET);
							fread (mat,128,1,hzk_p);
							for(i=0;i<32;i++)
							{
								pos=4*i;       //32*32��������ÿһ���������ֽ�
								for(j=0;j<32;j++)
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)
									{
										Putpixel64k(x+j,y,color);

									}

								}
								y++;


							}
								//������һ��������ʾ��
							x+=part;    //��x һ��ƫ����part
							s+=2;          //�������ŵ������룬2���ֽڣ�����Ҫ��2

						}
						x=x0;y0+=flag+10;   //һ�к�����ʾ��󣬸�yһ��ƫ����
					}
						break;

				 }


		case 48:
				  {
					char mat[288];   //48*48�ĺ�����Ҫ288���ֽڵ��������洢
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
							quma=s[0]-0xa0;                      //�������
							weima=s[1]-0xa0;                     //���λ��
							offset=(94*(quma-1)+(weima-1))*288L;   //���Ҫ��ʾ�ĺ������ֿ��ļ��е�ƫ��
							fseek(hzk_p,offset,SEEK_SET);         //�ض�λ�ļ�ָ��
							fread (mat,288,1,hzk_p);            //�����ú��ֵľ����������,1ΪҪ���������

							for(i=0;i<48;i++)
							{
								pos=6*i;
								for(j=0;j<48;j++)    //һ��һ�е�ɨ�裬��λ��Ϊ��1�ĵ���ʾ����
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8ֻ����0��8֮��ѭ����j/8��0��1֮��ѭ��
									{
										Putpixel64k(x+j,y,color);

									}

								}
								y++;
							}
								//������һ��������ʾ��
							x+=part;    //��x һ��ƫ����part
							s+=2;          //�������ŵ������룬2���ֽڣ�����Ҫ��2

						}
						x=x0;y0+=flag+10;   //һ�к�����ʾ��󣬸�yһ��ƫ����
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
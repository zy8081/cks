#include<SVGA.h>
#include<hz.h>
#include<mouse.h>
#include<stdlib.h>
#include<string.h>
#include<bios.h>
#include<ORDFUNS.h>

/******************************************************
仿照MC的按钮设计的按钮，为了省事直接写成一个函数
*****************************************************/
void btn_bar_Draw(BTN_BAR b)//
{
    int x1=b.x1;
    int x2=b.x2;
    int y1=b.y1;
    int y2=b.y2;

    line_thick(x1,y1,x2,y1,3,0);
    line_thick(x2,y1,x2,y2,3,0);
    line_thick(x2,y2,x1,y2,3,0);
    line_thick(x1,y2,x1,y1,3,0);
    line_thick(x1+3,y1+3,x2-3,y1+3,2,57083);
    line_thick(x2-3,y1+3,x2-3,y2-3,2,57083);
    line_thick(x2-3,y2-3,x1+3,y2-3,2,33808);
    line_thick(x1+3,y2-3,x1+3,y1+3,2,33808);
    bar(x1+5,y1+4,x2-5,y2-5,44373);

}

/********************
     选中状态的按钮
***********************/
void btn_bar_Draw0(BTN_BAR b)
{
    int x1=b.x1;
    int x2=b.x2;
    int y1=b.y1;
    int y2=b.y2;

    line_thick(x1,y1,x2,y1,3,65535);
    line_thick(x2,y1,x2,y2,3,65535);
    line_thick(x2,y2,x1,y2,3,65535);
    line_thick(x1,y2,x1,y1,3,65535);
    line_thick(x1+3,y1+3,x2-3,y1+3,2,57083);
    line_thick(x2-3,y1+3,x2-3,y2-3,2,57083);
    line_thick(x2-3,y2-3,x1+3,y2-3,2,33808);
    line_thick(x1+3,y2-3,x1+3,y1+3,2,33808);
    bar(x1+5,y1+4,x2-5,y2-5,44373);
}


/********************
     选中状态的按钮
***********************/
void btn_bar_Draw1(BTN_BAR b)
{
    int x1=b.x1;
    int x2=b.x2;
    int y1=b.y1;
    int y2=b.y2;

    line_thick(x1,y1,x2,y1,3,0);
    line_thick(x2,y1,x2,y2,3,0);
    line_thick(x2,y2,x1,y2,3,0);
    line_thick(x1,y2,x1,y1,3,0);
    bar(x1+2,y1+2,x2-2,y2-2,27469);
}

/****************************************
     计算文字在按钮中居中放置位置的函数
	 实际使用时不知为何还是会有偏移，
	 只能加上偏移值勉强使用
**************************************/
void hzplace(BTN_BAR *pb,int nx,int ny)
{
    int lengthx=0;
    int lengthy;
    char*st=pb->inf;
    int xhz,xasc;
    if(nx%16==0)
    {
        xhz=nx;
        xasc=nx;
        lengthy=ny;
    }
    else if(nx==24)
    {
        xhz=24;
        xasc=32;
        lengthy=24;
    }
    while(*st!=0)
    {
        if(*st&0x80==0)lengthx+=xasc;
        else if(*st&0x80!=0)lengthx+=xhz;
        st++;
    }
    pb->xinf=(pb->x2-pb->x1-lengthx)/2+pb->x1;
    pb->yinf=(pb->y2-pb->y1-lengthy)/2+pb->y1;
    
}

/*画菜单栏的函数，意图同上，但暂时未设计*/
void menuprt(int x1,int y1,int x2,int y2)
{
    bar(x1,y1,x2,y2,27469);
}

//祖传代码，后期得改
void show_gb(int x,int y)
{
	line(x,y,x,y+16,65535);
}

void Getinfo(int x1,int y1,char *name,int num,int a1,int b1,int c1,int d1)
{
	char showtemp[2]= {0,0};
	int key;    			//?????
	int i=0,k,temp;
	int border=x1+4;
    //MOUSE mouse;	    //border??????????????
	x1=x1+4;
	y1=y1+5;
	for(i=strlen(name)-1;i>=0;i--)
	{
		*showtemp=name[i];
		put_asc16_ch(x1+i*8,y1-2,showtemp[0],0);
	}
	i=strlen(name);
	while(bioskey(1))					//???????????
	{
		bioskey(0);
	}
	border+=8*i;
	while(1)     													//?????????????????????????????13??
    {
	    show_gb(border,y1);//?????? 
		if(bioskey(1)==0||!MouseGet())			//????????????????????????????????????
		{
			for(k=0;k<100;k++)				//????????????????
			{
				delay(2);
				if(bioskey(1)||MouseGet())
				{
					break;
				}
			}
		}
		if(bioskey(1))
		{
			temp=bioskey(0)&0x00ff;
			if(temp!='\r'&&temp!='\n')	//?????????????????????????????????
			{
				if(('0'<=temp&&temp<='9'||('a'<=temp&&temp<='z')/*||temp=='_'*/)&&i<num)	//????????????????????????
				{
					bar(border,y1,border+8, y1+16, 0);
					name[i]=temp;				//???????????????			
					*showtemp=temp;
					put_asc16(border,y1-2,showtemp,65535); //??????????????????????????????
					i++;
					name[i]='\0';		//??????????β
					border+=8;
					show_gb(border,y1);
				}
				else if('A'<=temp&&temp<='Z'&&i<num)	//????????????????Сд??????????????????????????????? 
				{						             	//????????????????Сд?? 
					bar(border,y1,border+8, y1+16, 0);
					temp+=32;
					name[i]=temp;				//???????????????			
					*showtemp=temp;             //??????????????????????????????
					put_asc16(border,y1-2,showtemp,65535);
					i++;
					name[i]='\0';		//??????????β
					border+=8;
					show_gb(border,y1);
				}
				else if(temp=='\b'&&i>0)			//????????????????????????????
				{
					border-=8;
					bar(border,y1,border+8, y1+16, 0);
					i--;
					name[i]='\0';
					bar(border,y1,border+8, y1+16, 0);
					show_gb(border,y1);
				}
			}
			else
			{
				break;
			}
		}
		//if(!mouse_press(a1,b1,c1,d1)&&MouseGet(&mouse))		//???????????????????????
		//{
		//	break;
		//}
		bar(border,y1,border+8, y1+16, 0);
		//if(bioskey(1)==0||!MouseGet(&mouse))			//????????????????????????????????????
		//{
		//	for(k=0;k<100;k++)				//????????????????
		//	{
		//		delay(2);
		//		if(bioskey(1)||MouseGet(&mouse))
		//		{
		//			break;
		//		}
		//	}
		//}
	}
	bar(border,y1,border+8, y1+16, 0);
}
#include "common.h"
#include "main.h"


void main()
{
	int page=1;
	SetSVGA64k();
	
	mouseinit();
	while(1)
	{
		switch(page)
		{
			case 0:
				clrmous(MouseX,MouseY);
				delay(200);
				cleardevice();
				exit(1);
			case 1:			//0:登录界面
				MouseS=1;
				page=login();
				break;
			case 2:              //1:登录界面
				MouseS=1;
				page=regist();
				break;
			//case 3:              //2:注册界面
			//	MouseS=0;
			//	page=regist();
			//	break;
	    }
	}
}
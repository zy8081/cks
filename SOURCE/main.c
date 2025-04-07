#include <common.h>
#include <main.h>
void createDirectory(const char* dirname);
//bar(0,0,1024,768,0xffff);
//login()和regist()都出自于login.c文件
void main()
{
	int page=1;
	char user[21];
	
	WORKFILE workfile;
	SetSVGA64k();
	mouseinit();
	//mkdir("./users/20");
	while(1)
	{
		switch(page)
		{
			case 0:
				clrmous(MouseX,MouseY);
				delay(200);
				exit(1);
			case 1:	        //1:登录界面
				MouseS=1;   //初始化鼠标形状
				page=login(user);
				break;
			case 2:              //2:注册界面
				MouseS=1;
				page=regist();
				break;
			case 3:
				MouseS=1;
				start(&page);
				break;
			case 4:
				MouseS=1;
				wrkmng_main(&page,user,&workfile);
				break;
			case 5:
				MouseS=1;
				page=project(workfile,&page);
				break;
	    }
	}
}


void createDirectory(const char* dirname) 
{
    union REGS regs;
    struct SREGS sregs;

    // 设置DS:SI指向目录名
    sregs.ds = FP_SEG(dirname);
    regs.x.dx = FP_OFF(dirname);

    // 调用DOS中断21h，功能号39h（创建目录）
    regs.x.ax = 0x3900;  // 功能号39h
    int86x(0x21, &regs, &regs, &sregs);

    // 检查返回值
    if (regs.x.flags & 1) {  // 如果进位标志被设置，表示出错
        printf("Error creating directory. Error code: %X\n", regs.x.ax);
        switch (regs.x.ax) {
            case 0x03: printf("Path not found.\n"); break;  // 路径不存在
            case 0x05: printf("Access denied.\n"); break;  // 权限不足
            case 0x0A: printf("Directory already exists.\n"); break;  // 文件夹已存在
            default: printf("Unknown error.\n"); break;
        }
    } else {
        printf("Directory created successfully.\n");
    }
}

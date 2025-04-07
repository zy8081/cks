#include <common.h>
#include <main.h>
void createDirectory(const char* dirname);
//bar(0,0,1024,768,0xffff);
//login()��regist()��������login.c�ļ�
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
			case 1:	        //1:��¼����
				MouseS=1;   //��ʼ�������״
				page=login(user);
				break;
			case 2:              //2:ע�����
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

    // ����DS:SIָ��Ŀ¼��
    sregs.ds = FP_SEG(dirname);
    regs.x.dx = FP_OFF(dirname);

    // ����DOS�ж�21h�����ܺ�39h������Ŀ¼��
    regs.x.ax = 0x3900;  // ���ܺ�39h
    int86x(0x21, &regs, &regs, &sregs);

    // ��鷵��ֵ
    if (regs.x.flags & 1) {  // �����λ��־�����ã���ʾ����
        printf("Error creating directory. Error code: %X\n", regs.x.ax);
        switch (regs.x.ax) {
            case 0x03: printf("Path not found.\n"); break;  // ·��������
            case 0x05: printf("Access denied.\n"); break;  // Ȩ�޲���
            case 0x0A: printf("Directory already exists.\n"); break;  // �ļ����Ѵ���
            default: printf("Unknown error.\n"); break;
        }
    } else {
        printf("Directory created successfully.\n");
    }
}

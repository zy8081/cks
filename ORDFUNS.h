#ifndef ORDFUNS_H
#define ORDFUNS_H

typedef struct btnbar//���ΰ�ť����
{
    char* inf;  //��ť��ʾ����������
    int xinf;   //�������������
    int yinf;

    int x1;     //���ϼ����½�λ�õ������
    int y1;
    int x2;
    int y2; 
}BTN_BAR;

void btn_bar_Draw(BTN_BAR b);
void btn_bar_Draw0(BTN_BAR b);//����ť��������Ϊ��ͨ��0Ϊѡ�У�1Ϊ�޷�ѡ��
void hzplace(BTN_BAR *pb,int nx,int ny);//ȷ�����־��з���λ��

void show_gb(int x,int y);
void Getinfo(int x1,int y1,char *name,int num,int a1,int b1,int c1,int d1);

#endif
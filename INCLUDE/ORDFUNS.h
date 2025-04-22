#ifndef ORDFUNS_H
#define ORDFUNS_H

/*typedef struct btnbar//���ΰ�ť����
{
    char* inf;  //��ť��ʾ����������
    int xinf;   //�������������?
    int yinf;

    int x1;     //���ϼ����½�λ�õ������?
    int y1;
    int x2;
    int y2; 
}BTN_BAR;*/

void btn_bar_Draw(int x1,int y1,int x2,int y2);
void btn_bar_Draw0(int x1,int y1,int x2,int y2);
void btn_bar_Draw1(int x1,int y1,int x2,int y2);
void menuprt(int x1,int y1,int x2,int y2);
//void hzplace(BTN_BAR *pb,int nx,int ny);//ȷ�����־��з���λ��
void inputs(int x ,int y ,char *content,int n);
void draw_toast(void);
void clear_toast(void);

#endif
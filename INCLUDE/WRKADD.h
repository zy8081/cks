//�½���Ŀ����
#ifndef WRKADD_H
#define WRKADD_H

void wrkmng_add(int *fpage1,int* pplacenum,char**pname0,char*user);//���庯��

void placeprt(int placenum);//����ѡ��ص�İ�ť

void nameprt(char*);//�����������֣�����ȱ�ݣ��ٴε���޷�����㿪ʼ

void compprt();//������ɰ�ť

void title2prt();//���Ʊ���

void wrkmng_add_place(int* page1,int* placetemp);//����ѡ��ص㲿��

void sureprt(int i);//ѡ��ص��ȷ����ť

void gameinit(char* datpath);//��ʼ��dat�ļ�

void datacreate(char*filen);

#endif
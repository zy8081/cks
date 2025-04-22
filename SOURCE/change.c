#include <ALLFUNS.h>

void activate_research_effect(int type,int id,struct GameInfo *gameinfop,nodebq *p1,char *path)
{
	switch (type)
	{
		case 1:
			switch (id)
			{
				case 1:
					research_1_1();
					break;
				case 2:
					research_1_2();
					break;
				case 3:
					research_1_3();
					break;
				case 4:
					research_1_4();
					break;
				case 5:
					research_1_5();
					break;
				case 6:
					research_1_6();
					break;
				case 7:
					research_1_7();
					break;
				case 8:
					research_1_8();
					break;
				case 9:
					research_1_9();
					break;
				case 10:
					research_1_10();
					break;
				
			}
			break;
		case 2:
			switch (id)
			{
				case 1:
					research_2_1();
					break;
				case 2:
					research_2_2(gameinfop,p1);
					break;
				case 3:
					research_2_3(gameinfop,p1);
					break;
				case 4:
					research_2_4(gameinfop,path);
					break;
				case 5:
					research_2_5(gameinfop,path);
					break;
				case 6:
					research_2_6(path);
					break;
				case 7:
					research_2_7(path);
					break;
				case 8:
					research_2_8(path);
					break;
				case 9:
					research_2_9(path);
					break;
				case 10:
					research_2_10(path);
					break;
				case 11:
					research_2_11(path);
					break;
				case 12:
					research_2_12(path);
					break;
				case 13:
					research_2_13(gameinfop,path);
					break;
				case 14:
					research_2_14(gameinfop,path);
					break;
				
			}
			break;
		case 3:
			switch (id)
			{
				case 1:
					research_3_1();
					break;
				case 2:
					research_3_2(gameinfop,path);
					break;
				case 3:
					research_3_3(gameinfop,path);
					break;
				case 4:
					research_3_4(gameinfop,path);
					break;
				case 5:
					research_3_5(gameinfop,path);
					break;
				case 6:
					research_3_6(gameinfop,path);
					break;
				case 7:
					research_3_7(gameinfop,path);
					break;
				case 8:
					research_3_8(gameinfop,path);
					break;
				case 9:
					research_3_9(gameinfop,path);
					break;
				case 10:
					research_3_10(gameinfop,path);
					break;
			}
			break;
	}
}

/*
根据id解锁建筑，高安全性
*/
void unlock_building(int id,char *path)
{
	FILE *file1;
	FILE *file2;
	int total;
	int i,j;
	char c;
	char str[30]={'\0'};
	char path1[35];
	char path2[35];
	sprintf(path1,"%s\\buildt.TXT",path);
	file1=fopen(path1,"r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	sprintf(path2,"%s\\buildtt.TXT",path);
	file2=fopen(path2,"w");
	if (file2==NULL)
	{
		printf("open error\n");
		return;
	}
	
	i=0;
	while ((c=fgetc(file1))!='\n')
	{
		str[i++]=c;
	}
	str[i]='\0';
	itoa(atoi(str)+1,str,10);
	fputs(str,file2);
	fputc('\n',file2);
	
	while ((c=fgetc(file1))!='\n')
	{
		fputc(c,file2);
	}
	fputc('\n',file2);
	
	for (i=0;i<id-1;i++)
	{
		while ((c=fgetc(file1))!='\n')
		{
			fputc(c,file2);
		}
		fputc('\n',file2);
	}
	
	while ((c=fgetc(file1))!='#')
	{
		if (c==EOF)
		{
			break;
		}
		if (c=='\n')
		{
			fputc(c,file2);
			break;
		}
		fputc(c,file2);
	}
	
	while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	
	remove(path1);
	rename(path2,path1);
}


/*
1.res_cost:nanomaterial   2.res_cost:rarematerial  3.res_add:nanomaterial
4.res_add:rarematerial 5.res_add:oxygen 6.res_add:water
7.res_add:food 8.res_add:energy 9.res_add:fuel
10.res_add:mineal  11.bui_time
根据id修改建筑文件，适用于修改一切建筑的数据(包括地图上的)
*/
void change_building_info_onfilemap(struct GameInfo *gameinfop,int id,int funcflag,int change,char *path)
{
	FILE *file1;
	FILE *file2;
	int i,j;
	char c;
	char str[30]={'\0'};
	char path1[35];
	char path2[35];
	int *resadd[8];
	
	sprintf(path1,"%s\\buildt.TXT",path);
	file1=fopen(path1,"r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	sprintf(path2,"%s\\buildtt.TXT",path);
	file2=fopen(path2,"w");
	if (file2==NULL)
	{
		printf("open error\n");
		return;
	}
	
	for (i=0;i<2;i++)
	{
		while((c=fgetc(file1))!='\n')
		{
			fputc(c,file2);
		}
		fputc('\n',file2);
	}
	
	for (i=0;i<id-1;i++)
	{
		while((c=fgetc(file1))!='\n')
		{
			fputc(c,file2);
		}
		fputc('\n',file2);
	}
	

	for (i=0;i<funcflag+2;i++)
	{
		while((c=fgetc(file1))!=' ')
		{
			fputc(c,file2);
		}
		fputc(' ',file2);
	}
	
	i=0;
	while ((c=fgetc(file1))!=' ' && c!='\n')
	{
		str[i++]=c;
	}
	str[i]='\0';
	itoa(atoi(str)+change,str,10);
	fputs(str,file2);
	fputc(c,file2);
	
	while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	
	remove(path1);
	rename(path2,path1);
	for (i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
		{
			if (gameinfop->m_info[i][j].building.id==id)
			{
				if (funcflag>=3 && funcflag<=10)
				{
					resadd[0]=&(gameinfop->m_info[i][j].building.res_add.nanomaterial);
					resadd[1]=&(gameinfop->m_info[i][j].building.res_add.rarematerial);
					resadd[2]=&(gameinfop->m_info[i][j].building.res_add.oxygen);
					resadd[3]=&(gameinfop->m_info[i][j].building.res_add.water);
					resadd[4]=&(gameinfop->m_info[i][j].building.res_add.food);
					resadd[5]=&(gameinfop->m_info[i][j].building.res_add.energy);
					resadd[6]=&(gameinfop->m_info[i][j].building.res_add.fuel);
					resadd[7]=&(gameinfop->m_info[i][j].building.res_add.mineral);
					(*resadd[funcflag-3]) += change;
				}
			}
		}
	}
}

//科研点+10%
void research_1_1(void)
{
	return;
}

//家园建设值+10%，人民幸福度+10%
void research_1_2(void)
{
	return;
}

//家园建设值+20%，人民幸福度+20%
void research_1_3(void)
{
	return;
}

//家园建设值+20%，人民幸福度+20%
void research_1_4(void)
{
	return;
}

//家园建设值+20%
void research_1_5(void)
{
	return;
}

//人民幸福度+10%，住宅区人口+100
void research_1_6(void)
{
	return;
}

//家园建设值+10%，人民幸福度+20%
void research_1_7(void)
{
	return;
}

//人民幸福度+20%
void research_1_8(void)
{
	return;
}

//人民幸福度+20%
void research_1_9(void)
{
	return;
}

//家园建设值+1000
void research_1_10(void)
{
	return;
}

//科研点+10%
void research_2_1(void)
{
	return;
}

//机器人中枢能量维护+25，建造队列+1
void research_2_2(struct GameInfo *gameinfop,nodebq *p1)
{
	gameinfop->m_info[2][3].building.res_add.energy-=25;
	p1->i++;
}

//机器人中枢能量维护+25，建造队列+1
void research_2_3(struct GameInfo *gameinfop,nodebq *p1)
{
	gameinfop->m_info[2][3].building.res_add.energy-=25;
	p1->i++;
}

//机器人中枢能量维护+25，建造时长-2月
void research_2_4(struct GameInfo *gameinfop,char *path)
{
	int i;
	gameinfop->m_info[2][3].building.res_add.energy-=25;
	for (i=0;i<18;i++)
	{
		change_building_info_onfilemap(gameinfop,i+1,11,-2,path);
	}
}

//建造时长-1月，住宅区人口+50
void research_2_5(struct GameInfo *gameinfop,char *path)
{
	int i;
	for (i=0;i<18;i++)
	{
		change_building_info_onfilemap(gameinfop,i+1,11,-1,path);
	}
}

//解锁建筑：娱乐设施
void research_2_6(char *path)
{
	unlock_building(3,path);
	unlock_building(4,path);
}

//解锁建筑：火星之眼
void research_2_7(char *path)
{
	unlock_building(15,path);
}

//解锁建筑：许多生产设施
void research_2_8(char *path)
{
	unlock_building(8,path);
	unlock_building(10,path);
	unlock_building(11,path);
	unlock_building(13,path);
	unlock_building(14,path);
}

//解锁建筑：综合性工厂
void research_2_9(char *path)
{
	unlock_building(16,path);
}
//解锁建筑：室外公园
void research_2_10(char *path)
{
	unlock_building(2,path);
}
//解锁建筑：未来式公园
void research_2_11(char *path)
{
	unlock_building(17,path);
}
//解锁建筑：火星之傲
void research_2_12(char *path)
{
	unlock_building(18,path);
}
//建造花费纳米材料-30
void research_2_13(struct GameInfo *gameinfop,char *path)
{
	int i;
	for (i=0;i<18;i++)
	{
		change_building_info_onfilemap(gameinfop,i+1,1,-30,path);
	}
}
//建造时长-1月
void research_2_14(struct GameInfo *gameinfop,char *path)
{
	int i;
	for (i=0;i<18;i++)
	{
		change_building_info_onfilemap(gameinfop,i+1,11,-1,path);
	}
}

//科研点+10%
void research_3_1(void)
{
	return;
}

//开采站产出+50，能量维护+10
void research_3_2(struct GameInfo *gameinfop,char *path)
{
	change_building_info_onfilemap(gameinfop,8,8,-10,path);
	change_building_info_onfilemap(gameinfop,8,10,50,path);
}

//开采站产出+70，能量维护+10
void research_3_3(struct GameInfo *gameinfop,char *path)
{
	change_building_info_onfilemap(gameinfop,8,8,-10,path);
	change_building_info_onfilemap(gameinfop,8,10,70,path);
}

//开采站产出+80，能量维护+10
void research_3_4(struct GameInfo *gameinfop,char *path)
{
	change_building_info_onfilemap(gameinfop,8,8,-10,path);
	change_building_info_onfilemap(gameinfop,8,8,80,path);
}

//所有工厂型建筑产出+40%，消耗+40%
void research_3_5(struct GameInfo *gameinfop,char *path)
{
	//5水培
	change_building_info_onfilemap(gameinfop,5,7,20,path);
	change_building_info_onfilemap(gameinfop,5,6,-8,path);
	change_building_info_onfilemap(gameinfop,5,8,-2,path);
	//6淡水
	change_building_info_onfilemap(gameinfop,6,6,20,path);
	change_building_info_onfilemap(gameinfop,6,8,-2,path);
	//7氧气
	change_building_info_onfilemap(gameinfop,7,5,20,path);
	change_building_info_onfilemap(gameinfop,7,8,-2,path);
	//9火电
	change_building_info_onfilemap(gameinfop,9,9,-10,path);
	change_building_info_onfilemap(gameinfop,9,8,40,path);
	//11燃料合成堆
	change_building_info_onfilemap(gameinfop,11,9,8,path);
	change_building_info_onfilemap(gameinfop,11,8,-40,path);
	//13基础材料厂
	change_building_info_onfilemap(gameinfop,13,3,20,path);
	change_building_info_onfilemap(gameinfop,13,10,-30,path);
	//14食物合成堆
}

//所有工厂型建筑产出+50%，消耗+30%
void research_3_6(struct GameInfo *gameinfop,char *path)
{
	//5水培
	change_building_info_onfilemap(gameinfop,5,7,20,path);
	change_building_info_onfilemap(gameinfop,5,6,-8,path);
	change_building_info_onfilemap(gameinfop,5,8,-2,path);
	//6淡水
	change_building_info_onfilemap(gameinfop,6,6,20,path);
	change_building_info_onfilemap(gameinfop,6,8,-2,path);
	//7氧气
	change_building_info_onfilemap(gameinfop,7,5,20,path);
	change_building_info_onfilemap(gameinfop,7,8,-2,path);
	//9火电
	change_building_info_onfilemap(gameinfop,9,9,-10,path);
	change_building_info_onfilemap(gameinfop,9,8,40,path);
	//11燃料合成堆
	change_building_info_onfilemap(gameinfop,11,9,8,path);
	change_building_info_onfilemap(gameinfop,11,8,-40,path);
	//13基础材料厂
	change_building_info_onfilemap(gameinfop,13,3,20,path);
	change_building_info_onfilemap(gameinfop,13,10,-30,path);
	//14食物合成堆
}
//所有工厂型建筑产出+60%，消耗+30%
void research_3_7(struct GameInfo *gameinfop,char *path)
{
	//5水培
	change_building_info_onfilemap(gameinfop,5,7,20,path);
	change_building_info_onfilemap(gameinfop,5,6,-8,path);
	change_building_info_onfilemap(gameinfop,5,8,-2,path);
	//6淡水
	change_building_info_onfilemap(gameinfop,6,6,20,path);
	change_building_info_onfilemap(gameinfop,6,8,-2,path);
	//7氧气
	change_building_info_onfilemap(gameinfop,7,5,20,path);
	change_building_info_onfilemap(gameinfop,7,8,-2,path);
	//9火电
	change_building_info_onfilemap(gameinfop,9,9,-10,path);
	change_building_info_onfilemap(gameinfop,9,8,40,path);
	//11燃料合成堆
	change_building_info_onfilemap(gameinfop,11,9,8,path);
	change_building_info_onfilemap(gameinfop,11,8,-40,path);
	//13基础材料厂
	change_building_info_onfilemap(gameinfop,13,3,20,path);
	change_building_info_onfilemap(gameinfop,13,10,-30,path);
	//14食物合成堆
}
//太阳能电池板产出+50
void research_3_8(struct GameInfo *gameinfop,char *path)
{
	change_building_info_onfilemap(gameinfop,10,8,50,path);
}
//太阳能电池板产出+50
void research_3_9(struct GameInfo *gameinfop,char *path)
{
	change_building_info_onfilemap(gameinfop,10,8,50,path);
}
//太阳能电池板产出+50
void research_3_10(struct GameInfo *gameinfop,char *path)
{
	change_building_info_onfilemap(gameinfop,10,8,50,path);
}

void file_copy(char *path)
{
	FILE *file1;
	FILE *file2;
	char c;
	char path1[35];
	char path2[35];
	sprintf(path1,"%s\\USERBLD.TXT",path);
	file1=fopen(path1,"r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	sprintf(path2,"%s\\buildt.TXT",path);
	file2=fopen(path2,"w");
	if (file2==NULL)
	{
		printf("open error\n");
		return;
	}
	
	while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	sprintf(path1,"%s\\USERTEC.TXT",path);
	file1=fopen(path1,"r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	sprintf(path2,"%s\\techt.TXT",path);
	file2=fopen(path2,"w");
	if (file2==NULL)
	{
		printf("open error\n");
		return;
	}
	while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	fclose(file1);
	fclose(file2);
}

//保存文件
void file_save(char *path)
{
	FILE *file1;
	FILE *file2;
	char path1[35];
	char path2[35];
	sprintf(path1,"%s\\USERBLD.TXT",path);
	sprintf(path2,"%s\\buildt.TXT",path);
	remove(path1);
	rename(path2,path1);

	sprintf(path1,"%s\\USERTEC.TXT",path);
	sprintf(path2,"%s\\techt.TXT",path);
	remove(path1);
	rename(path2,path1);

	sprintf(path1,"%s\\log.TXT",path);
	sprintf(path2,"%s\\logt.TXT",path);
	remove(path1);
	rename(path2,path1);
}

int cal_one_house_population(char *path)
{
	int num=100;
	if (check_techflag_infile(path,1,6))
	{
		num+=50;
	}
	if (check_techflag_infile(path,2,5))
	{
		num+=50;
	}
	return num;
}
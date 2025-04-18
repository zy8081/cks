#include <ALLFUNS.h>

void activate_research_effect(int type,int id,struct GameInfo *gameinfop,nodebq *p1)
{
	switch (type)
	{
		case 1:
			switch (id)
			{
				case 1:
					research_1_1(gameinfop);
					break;
				case 2:
					research_1_2(gameinfop);
					break;
				case 3:
					research_1_3(p1);
					break;
				case 4:
					research_1_4(gameinfop);
					break;
				case 5:
					research_1_5(gameinfop);
					break;
				case 6:
					research_1_6(gameinfop);
					break;
				case 7:
					research_1_7(gameinfop);
					break;
				case 8:
					research_1_8(gameinfop);
					break;
				case 9:
					research_1_9(gameinfop);
					break;
				case 10:
					research_1_10(gameinfop);
					break;
				
			}
			break;
		case 2:
			switch (id)
			{
				case 1:
					research_2_1(gameinfop);
					break;
				case 2:
					research_2_2(gameinfop);
					break;
				case 3:
					research_2_3(gameinfop);
					break;
				case 4:
					research_2_4(gameinfop);
					break;
				case 5:
					research_2_5(gameinfop);
					break;
				case 6:
					research_2_6(gameinfop);
					break;
				case 7:
					research_2_7(gameinfop);
					break;
				case 8:
					research_2_8(gameinfop);
					break;
				case 9:
					research_2_9(gameinfop);
					break;
				
			}
			break;
		case 3:
			switch (id)
			{
				case 1:
					research_3_1(gameinfop);
					break;
				case 2:
					research_3_2(gameinfop);
					break;
				case 3:
					research_3_3(gameinfop);
					break;
				case 4:
					research_3_4(gameinfop);
					break;
				case 5:
					research_3_5(gameinfop);
					break;
			}
			break;
	}
}

/*
根据id解锁建筑，高安全性
*/
void unlock_building(int id)
{
	FILE *file1;
	FILE *file2;
	int total;
	int i,j;
	char c;
	char str[30]={'\0'};
	
	file1=fopen("./data/building.txt","r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	
	file2=fopen("./data/buildt.txt","w");
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
	
	
	
	remove("./data/building.txt");
	rename("./data/buildt.txt","./data/building.txt");
}

void change_namo_add(struct GameInfo *gameinfop,int addnano,int addenergy)
{
	FILE *file1;
	FILE *file2;
	int i,j;
	char c;
	char str[30]={'\0'};
	
	file1=fopen("./data/building.txt","r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	
	file2=fopen("./data/buildt.txt","w");
	if (file2==NULL)
	{
		printf("open error\n");
		return;
	}
	
	for (i=0;i<3;i++)
	{
		while((c=fgetc(file1))!='\n')
		{
			fputc(c,file2);
		}
		fputc('\n',file2);
	}
	
	for (i=0;i<5;i++)
	{
		while((c=fgetc(file1))!=' ')
		{
			fputc(c,file2);
		}
		fputc(' ',file2);
	}
	
	i=0;
	while ((c=fgetc(file1))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	itoa(atoi(str)+addnano,str,10);
	fputs(str,file2);
	fputc(' ',file2);
	
	for (i=0;i<4;i++)
	{
		while((c=fgetc(file1))!=' ')
		{
			fputc(c,file2);
		}
		fputc(' ',file2);
	}
	
	i=0;
	while ((c=fgetc(file1))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	itoa(atoi(str)+addenergy,str,10);
	fputs(str,file2);
	fputc(' ',file2);
	
	while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	
	remove("./data/building.txt");
	rename("./data/buildt.txt","./data/building.txt");
	
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id==2)
			{
				gameinfop->m_info[i][j].building.res_add.nanomaterial +=addnano;
				gameinfop->m_info[i][j].building.res_add.energy +=addenergy;
			}
		}
	}
}

void change_building_add_nano(struct GameInfo *gameinfop,int id,int add_nano)
{
	FILE *file1;
	FILE *file2;
	int i,j;
	char c;
	char str[30]={'\0'};
	
	file1=fopen("./data/building.txt","r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	
	file2=fopen("./data/buildt.txt","w");
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
	
	for (i=0;i<5;i++)
	{
		while((c=fgetc(file1))!=' ')
		{
			fputc(c,file2);
		}
		fputc(' ',file2);
	}
	
	i=0;
	while ((c=fgetc(file1))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	itoa(atoi(str)+add_nano,str,10);
	fputs(str,file2);
	fputc(' ',file2);
	
	
	
	while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	
	remove("./data/building.txt");
	rename("./data/buildt.txt","./data/building.txt");
	
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id==id)
			{
				gameinfop->m_info[i][j].building.res_add.nanomaterial +=add_nano;
			}
		}
	}
}

void change_building_add_energy(struct GameInfo *gameinfop,int id,int add_energy)
{
	FILE *file1;
	FILE *file2;
	int i,j;
	char c;
	char str[30]={'\0'};
	
	file1=fopen("./data/building.txt","r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	
	file2=fopen("./data/buildt.txt","w");
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
	
	for (i=0;i<10;i++)
	{
		while((c=fgetc(file1))!=' ')
		{
			fputc(c,file2);
		}
		fputc(' ',file2);
	}
	
	i=0;
	while ((c=fgetc(file1))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	itoa(atoi(str)+add_energy,str,10);
	fputs(str,file2);
	fputc(' ',file2);
	
	
	
	while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	
	remove("./data/building.txt");
	rename("./data/buildt.txt","./data/building.txt");
	
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id==id)
			{
				gameinfop->m_info[i][j].building.res_add.energy +=add_energy;
			}
		}
	}
}


void change_building_add_rare(struct GameInfo *gameinfop,int id,int add_rare)
{
	FILE *file1;
	FILE *file2;
	int i,j;
	char c;
	char str[30]={'\0'};
	
	file1=fopen("./data/building.txt","r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	
	file2=fopen("./data/buildt.txt","w");
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
	
	for (i=0;i<6;i++)
	{
		while((c=fgetc(file1))!=' ')
		{
			fputc(c,file2);
		}
		fputc(' ',file2);
	}
	
	i=0;
	while ((c=fgetc(file1))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	itoa(atoi(str)+add_rare,str,10);
	fputs(str,file2);
	fputc(' ',file2);
	
	
	
	while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	
	remove("./data/building.txt");
	rename("./data/buildt.txt","./data/building.txt");
	
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id==id)
			{
				gameinfop->m_info[i][j].building.res_add.rarematerial +=add_rare;
			}
		}
	}
}

void change_building_add_fuel(struct GameInfo *gameinfop,int id,int add_fuel)
{
	FILE *file1;
	FILE *file2;
	int i,j;
	char c;
	char str[30]={'\0'};
	
	file1=fopen("./data/building.txt","r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	
	file2=fopen("./data/buildt.txt","w");
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
	
	for (i=0;i<11;i++)
	{
		while((c=fgetc(file1))!=' ')
		{
			fputc(c,file2);
		}
		fputc(' ',file2);
	}
	
	i=0;
	while ((c=fgetc(file1))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	itoa(atoi(str)+add_fuel,str,10);
	fputs(str,file2);
	fputc(' ',file2);
	
	
	
	while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	
	remove("./data/building.txt");
	rename("./data/buildt.txt","./data/building.txt");
	
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id==id)
			{
				gameinfop->m_info[i][j].building.res_add.rarematerial +=add_fuel;
			}
		}
	}
}

void change_building_add_food(struct GameInfo *gameinfop,int id,int add_food)
{
	FILE *file1;
	FILE *file2;
	int i,j;
	char c;
	char str[30]={'\0'};
	
	file1=fopen("./data/building.txt","r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	
	file2=fopen("./data/buildt.txt","w");
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
	
	for (i=0;i<9;i++)
	{
		while((c=fgetc(file1))!=' ')
		{
			fputc(c,file2);
		}
		fputc(' ',file2);
	}
	
	i=0;
	while ((c=fgetc(file1))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	itoa(atoi(str)+add_food,str,10);
	fputs(str,file2);
	fputc(' ',file2);
	
	
	
	while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	
	remove("./data/building.txt");
	rename("./data/buildt.txt","./data/building.txt");
	
	for (i=0;i<7;i++)
	{
		for (j=0;j<7;j++)
		{
			if (gameinfop->m_info[i][j].building.id==id)
			{
				gameinfop->m_info[i][j].building.res_add.rarematerial +=add_food;
			}
		}
	}
}


/*
1.res_cost:nanomaterial   2.res_cost:rarematerial  3.res_add:nanomaterial
4.res_add:rarematerial 5.res_add:oxygen 6.res_add:water
7.res_add:food 8.res_add:energy 9.res_add:fuel
10.res_add:mineal  11.bui_time
根据id修改建筑文件，适用于修改一切建筑的数据(包括地图上的)
*/
void change_building_add_res(struct GameInfo *gameinfop,int id,int funcflag,int change)
{
	FILE *file1;
	FILE *file2;
	int i,j;
	char c;
	char str[30]={'\0'};
	
	file1=fopen("./data/building.txt","r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	
	file2=fopen("./data/buildt.txt","w");
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
	while ((c=fgetc(file1))!=' ')
	{
		str[i++]=c;
	}
	str[i]='\0';
	itoa(atoi(str)+change,str,10);
	fputs(str,file2);
	fputc(' ',file2);
	
	while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	
	remove("./data/building.txt");
	rename("./data/buildt.txt","./data/building.txt");

}

//科研点+10
void research_1_1(struct GameInfo *gameinfop)
{
	gameinfop->techpoint+=20;
}

//
void research_1_2(struct GameInfo *gameinfop)
{
	FILE *file1;
	FILE *file2;
	int total;
	int i,j;
	char c;
	char str[30]={'\0'};
	
	file1=fopen("./data/building.txt","r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	
	file2=fopen("./data/buildt.txt","w");
	if (file2==NULL)
	{
		printf("open error\n");
		return;
	}
	
	
	while ((c=fgetc(file1))!='\n')
	{
		fputc(c,file2);
	}
	fputc('\n',file2);
	
	i=0;
	while ((c=fgetc(file1))!='\n')
	{
		fputc(c,file2);
		str[i++]=c;
	}
	str[i]='\0';
	fputc('\n',file2);
	total= atoi(str);
	
	for (i=0;i<total;i++)
	{
		j=0;
		while (j<13)
		{
			c=fgetc(file1);
			if (c== ' ')
			{
				j++;
			}
			fputc(c,file2);
		}
		
		i=0;
		while ((c=fgetc(file1))!=' '&&c!='\n'&&c!=EOF)
		{
			str[i++]=c;
		}
		str[i]='\0';
		itoa(atoi(str)-1,str,10);
		fputs(str,file2);
		fputc('\n',file2);
	}
	
	while ((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	
	remove("./data/building.txt");
	rename("./data/buildt.txt","./data/building.txt");
}

//建造队列+1
void research_1_3(nodebq *p1)
{
	p1->i++;
}

//所有建筑纳米材料-30
void research_1_4(struct GameInfo *gameinfop)
{
	FILE *file1;
	FILE *file2;
	int total;
	int i,j,k;
	char c;
	char str[30]={'\0'};
	
	file1=fopen("./data/building.txt","r");
	if (file1==NULL)
	{
		printf("open error\n");
		return;
	}
	
	file2=fopen("./data/buildt.txt","w");
	if (file2==NULL)
	{
		printf("open error\n");
		return;
	}
	
	i=0;
	while ((c=fgetc(file1))!='\n')
	{
		fputc(c,file2);
	}
	fputc('\n',file2);
	
	i=0;
	while ((c=fgetc(file1))!='\n')
	{
		str[i++]=c;
		fputc(c,file2);
	}
	str[i]='\0';
	total=atoi(str);
	fputc('\n',file2);
	
	
	
	for (i=0;i<total;i++)
	{
		j=0;
		while(1)
		{
			while((c=fgetc(file1))!=' ')
			{
				fputc(c,file2);
			}
			fputc(' ',file2);
			j++;
			if (j==3)
			{
				k=0;
				while((c=fgetc(file1))!=' ')
				{
					str[k++]=c;
				}
				str[k]='\0';
				itoa(atoi(str)-30,str,10);
				fputs(str,file2);
				fputc(' ',file2);
				break;
			}
		}
		while((c=fgetc(file1))!='\n')
		{
			fputc(c,file2);
		}
		fputc('\n',file2);
	}
	
	while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
	
	remove("./data/building.txt");
	rename("./data/buildt.txt","./data/building.txt");
}

//解锁建筑：火箭发射台
void research_1_5(struct GameInfo *gameinfop)
{
	unlock_building(7);
}

//解锁大型工程项目：发射卫星
void research_1_6(struct GameInfo *gameinfop)
{
	gameinfop->huge_engineering[0].lock=1;
	gameinfop->huge_engineering[0].time=24;
}

//解锁大型工程项目：载人航天
void research_1_7(struct GameInfo *gameinfop)
{
	gameinfop->huge_engineering[1].lock=1;
	gameinfop->huge_engineering[1].time=36;
}

//每月科研点+50
void research_1_8(struct GameInfo *gameinfop)
{
	gameinfop->techpoint+=50;
}

//解锁大型工程项目：太空聚光镜
void research_1_9(struct GameInfo *gameinfop)
{
	gameinfop->huge_engineering[2].lock=1;
	gameinfop->huge_engineering[2].time=120;
}

void research_1_10(struct GameInfo *gameinfop)
{
	gameinfop->huge_engineering[2].lock=1;
	gameinfop->huge_engineering[2].time=120;
}

//每月科研点+20
void research_2_1(struct GameInfo *gameinfop)
{
	gameinfop->techpoint +=20;
}

//纳米材料厂产出+10,能量维护+5
void research_2_2(struct GameInfo *gameinfop)
{
	change_building_add_res(gameinfop,2,1,-10);
	change_building_add_res(gameinfop,2,6,-5);
}

//解锁建筑：稀有材料厂
void research_2_3(struct GameInfo *gameinfop)
{
	unlock_building(9);
}

//稀有材料厂产出+5，纳米材料厂产出+10，能量维护各+5
void research_2_4(struct GameInfo *gameinfop)
{
	change_building_add_energy(gameinfop,2,-5);
	change_building_add_energy(gameinfop,9,-5);
	
	change_building_add_nano(gameinfop,2,10);
	change_building_add_rare(gameinfop,9,5);
}

//燃料合成+10
void research_2_5(struct GameInfo *gameinfop)
{
	change_building_add_fuel(gameinfop,7,10);
}

//燃料合成+20,能量维护+5
void research_2_6(struct GameInfo *gameinfop)
{
	change_building_add_fuel(gameinfop,7,20);
	change_building_add_energy(gameinfop,7,-5);
}

void research_2_7(struct GameInfo *gameinfop)
{

}

void research_2_8(struct GameInfo *gameinfop)
{

}

void research_2_9(struct GameInfo *gameinfop)
{


}


//水培农场食物+10，水维护+10
void research_3_1(struct GameInfo *gameinfop)
{
	change_building_add_res(gameinfop,5,5,10);
	change_building_add_res(gameinfop,5,4,-10);
}

//解锁建筑：食物合成堆
void research_3_2(struct GameInfo *gameinfop)
{
	unlock_building(8);
}

//食物合成堆食物+5
void research_3_3(struct GameInfo *gameinfop)
{
	change_building_add_res(gameinfop,8,5,5);
}

//水培农场食物产出+10，水维护+5
void research_3_4(struct GameInfo *gameinfop)
{
	change_building_add_res(gameinfop,5,5,10);
	change_building_add_res(gameinfop,5,4,-5);
}

//水培农场食物产出+10
void research_3_5(struct GameInfo *gameinfop)
{
	change_building_add_res(gameinfop,5,5,10);
}
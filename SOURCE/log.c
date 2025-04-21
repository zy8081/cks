#include <ALLFUNS.h>

void logfile_copy(char *path)
{
    char path1[40];
    char path2[40];
    FILE *file1;
    FILE *file2;
    char c;

    sprintf(path1,"%s\\log.txt",path);
    file1=fopen(path1,"r");
    if (file1==NULL)
    {
        file1=fopen(path1,"w");
        fclose(file1);
        sprintf(path2,"%s\\logt.txt",path);
        file2=fopen(path2,"w");
        fclose(file2);
        return;
    }

    sprintf(path2,"%s\\logt.txt",path);
    file2=fopen(path2,"w");
    while((c=fgetc(file1))!=EOF)
	{
		fputc(c,file2);
	}
	
	fclose(file1);
	fclose(file2);
}
void generate_building_log(struct GameInfo *gameinfop,nodebq *p,int funcflag,char *path)
{
    char path1[40];
    char str[40];
    FILE *file;
    nodebq *temp=p->next;
    struct Building *buildp;
    int id;
    int i;
    int count=0;
    
    if (funcflag==0)
    {
        return;
    }
    sprintf(path1,"%s\\logt.txt",path);
    file=fopen(path1,"a");
    if (file==NULL)
    {
        return;
    }
    for (i=0;i<p->i;i++)
    {
        if (temp==NULL)
        {
            break;
        }
        if (gameinfop->m_info[temp->i][temp->j].building.bui_time==1)
        {
            count++;
        }
        temp=temp->next;
    }
    if (count==0)
    {
        fclose(file);
        return;
    }
    buildp=(struct Building *)malloc(sizeof(struct Building)*count);
    temp=p->next;
    for (i=0;i<count;i++)
    {
        id=gameinfop->m_info[temp->i][temp->j].building.id;
        get_building_info(id,buildp+i,path);
        sprintf(str,"%d年%d月：",gameinfop->year,gameinfop->month);
        fputs(str,file);
        fputs((buildp+i)->name,file);
        sprintf(str,"在（%d，%d）处建成",temp->i,temp->j);
        fputs(str,file);
        fputc('\n',file);
        temp=temp->next;
    }
    free(buildp);
    fclose(file);
    
}

void generate_tech_log(struct GameInfo *gameinfop,int funcflag,char *path)
{
    char path1[40];
    char str[40];
    char techname[30];
    FILE *file;
    int resflag[3];
    int i;
    int points;
    if (funcflag==0)
    {
        return;
    }
    sprintf(path1,"%s\\logt.txt",path);
    file=fopen(path1,"a");
    if (file==NULL)
    {
        return;
    }
    for (i=0;i<3;i++)
    {
        points=gameinfop->gametech[i].havepoints;
        if (((points+(gameinfop->techpoint))>=gameinfop->gametech[i].totalpoints) &&gameinfop->gametech[i].research_flag==1)
        {
            resflag[i]=1;
        }
        else
        {
            resflag[i]=0;
        }
    }
    
    for (i=0;i<3;i++)
    {
        if (resflag[i])
        {
            sprintf(str,"%d年%d月：",gameinfop->year,gameinfop->month);
            fputs(str,file);
            type_id_find_name(i+1,gameinfop->gametech[i].id,techname);
            fputs(techname,file);
            fputs("研究成功！",file);
            fputc('\n',file);
        }
    }
    fclose(file);   
}

int calculate_fileline(char *totalpath)
{
    FILE *file;
    char c;
    int line=0;
    file=fopen(totalpath,"r");
    while((c=fgetc(file))!=EOF)
    {
        if (c=='\n')
        {
            line++;
        }
    }
    fclose(file);
    return line;
}

int log_display(char *path)
{
    int page=5;
    char str[50];
    int totalpage;
    int newpage=1,oldpage=1;
    sprintf(str,"%s\\logt.txt",path);
    clrmous(MouseX,MouseY);
    draw_log_one_page(newpage,path);
    totalpage=calculate_fileline(str);
    
    while(1)
	{
		mouse_renew(&MouseX,&MouseY,&press);
        if (judge_press_mainbutton(5,&page))
		{
			return page;
		}
        if (newpage!=oldpage)
        {
            clrmous(MouseX,MouseY);
            draw_log_one_page(newpage,path);
            oldpage=newpage;
        }
        if (mouse_press(50,300,150,350)==1)
        {
            if (newpage>1)
            {
                newpage--;
            }
        }
        if (mouse_press(50,400,150,450)==1)
        {
            if (newpage<totalpage)
            {
                newpage++;
            }
        }
    }
}

void draw_log_one_page(int newpage,char *path)
{
    FILE *file;
    int i,j;
    char content[50];
    char totalpath[50];
    char *errorflag;
    btn_bar_Draw(270,160,1000,740);
    btn_bar_Draw(75,400,175,450);
    btn_bar_Draw(75,550,175,600);

    sprintf(totalpath,"%s\\logt.txt",path);
    file=fopen(totalpath,"r");
    if (file==NULL)
    {
        debug_file_printf(totalpath);
    }
    for (i=0;i<newpage-1;i++)
    {
        for (j=0;j<15;j++)
        {
            errorflag=fgets(content,50,file);
            if(errorflag==NULL)
            {
                fclose(file);
                return;
            }
        }
    }
    for (i=0;i<15;i++)
    {
        errorflag=fgets(content,50,file);
        if(errorflag==NULL)
        {
            fclose(file);
            return;
        }
        content[strlen(content)-1]='\0';
        put_hz16_asc16_size(270,160+i*30,2,2,content,1,"HZK\\HZ16");
    }
    fclose(file);
}
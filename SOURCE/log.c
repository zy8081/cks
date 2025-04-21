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
void generate_building_log(struct GameInfo *gameinfop,int funcflag,char *path)
{
    if (funcflag==0)
    {
        return;
    }

}
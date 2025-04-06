#include "common.h"
#include "game.h"
#include "debug.h"
void debug_file_printf(char *str)
{
	CloseSVGA();
	printf("can not open file:%s",str);
	getch();
	exit(0);
}

void debug_map_id(struct GameInfo gameinfo)
{
	int i,j;
	CloseSVGA();
	
	for (i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
        {
            printf("%d ",gameinfo.m_info[i][j].building.id);
        }
        printf("\n");
	}
	getch();
	exit(0);
}
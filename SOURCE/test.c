/*#include<mouse.h>
#include<SVGA.h>
#include<hz.h>
#include<mouse.h>
#include<stdlib.h>
#include<ALLFUNS.h>
#include<ORDFUNS.h>
#include<WRKMNG.h>
void drawworkbar(char*path,int n);

void drawwork_main()
{
    char path[5][100];
    char temp;
    int bk=0;
    int i=0;
    int j;
    int k=0;
    FILE* f =fopen("C:\\TEST\\WORKS\\CONTENT.TXT","rb+");
    SetSVGA64k();
	mouseinit();
    MouseS=1;
    bar(100,100,200,200,65535);
    k=0;
    while(1)
    {
        temp=fgetc(f);
        fseek(f,0,1); 
        if((temp>='0'&&temp<='9')||(temp>='a'&&temp<='z')||(temp>='A'&&temp<='Z')||temp=='\\'||temp==':')
        {
            bk=0;
            path[k][i]=temp;
            i++;
        }
        else if(temp=='.')
        {
            bk=0;
            path[k][i]=temp;
            i++;
            for(j=0;j<3;j++,i++)
            {
                temp=fgetc(f);
                fseek(f,0,1);
                path[k][i]=temp;
            }  
            //i++;
            //path[k][i]=='\0'; 
            k++;  
            i=0;
            //break;   
        }
        else
        {
            bk++;
        }
        if(bk>2)break;
        
    }
    //path[0]=temp;
    //put_hz16_asc16_size(0,0,1,1,path[1],65535,"C:\\TEST\\HZK\\hzk16");
    //for(k=0;k<5;k++)
    {
        //path[k][i]='\0';
        //put_hz16_asc16_size(0,0+k*100,1,1,path[k],65535,"C:\\TEST\\HZK\\hzk16");
        //drawworkbar(path[k],k+1);
    }
    //fgets(temp,(size_t)30+1,f);
    //put_hz16_asc16_size(410,172,1,1,temp,0,"C:\\TEST\\HZK\\hzk16");
    path[k][i]='\0';
    //drawworkbar("C:\\TEST\\WORKS\\abc\\abc.bas");
    drawworkbar(path[0],1);
    //drawworkbar("C:\\TEST\\WORKS\\a\\a.bas");
    drawworkbar(path[1],2);
    drawworkbar(path[2],3);
    fclose(f);
    return;
}*/


/*void main()
{
    char path[5][100];
    char temp;
    int bk=0;
    int i=0;
    int j;
    int k=0;
    FILE* f =fopen("C:\\TEST\\WORKS\\CONTENT.TXT","rb+");
    SetSVGA64k();
	mouseinit();
    MouseS=1;
    bar(100,100,200,200,65535);
    //clrmous(MouseX,MouseY);
    //fseek(f,0,1);
    /*while(1)
    {
        temp=fgetc(f);
        
        if(temp=='\n')
            fseek(f,1,1);
        
        else if(temp='.')
        {
            for(j=0;j<3;j++,i++)
            {
                path[K][i]=temp;
                fseek(f,1,1);
            }
            break;
        }
        else if(temp=='\0')
        {
            path[K][i]=temp;
            break;
        }
        else
        {
            path[L][i]=temp;
            fseek(f,1,1);
            i++;
        }
    }
    path[i]='\0';*/
    /*k=0;
    while(1)
    {
        temp=fgetc(f);
        fseek(f,0,1); 
        if((temp>='0'&&temp<='9')||(temp>='a'&&temp<='z')||(temp>='A'&&temp<='Z')||temp=='\\'||temp==':')
        {
            bk=0;
            path[k][i]=temp;
            i++;
        }
        else if(temp=='.')
        {
            bk=0;
            path[k][i]=temp;
            i++;
            for(j=0;j<3;j++,i++)
            {
                temp=fgetc(f);
                fseek(f,0,1);
                path[k][i]=temp;
            }  
            //i++;
            //path[k][i]=='\0'; 
            k++;  
            i=0;
            //break;   
        }
        else
        {
            bk++;
        }
        if(bk>2)break;
        
    }
    //path[0]=temp;
    //put_hz16_asc16_size(0,0,1,1,path[1],65535,"C:\\TEST\\HZK\\hzk16");
    //for(k=0;k<5;k++)
    {
        //path[k][i]='\0';
        //put_hz16_asc16_size(0,0+k*100,1,1,path[k],65535,"C:\\TEST\\HZK\\hzk16");
        //drawworkbar(path[k],k+1);
    }
    //fgets(temp,(size_t)30+1,f);
    //put_hz16_asc16_size(410,172,1,1,temp,0,"C:\\TEST\\HZK\\hzk16");
    path[k][i]='\0';
    //drawworkbar("C:\\TEST\\WORKS\\abc\\abc.bas");
    drawworkbar(path[0],1);
    //drawworkbar("C:\\TEST\\WORKS\\a\\a.bas");
    drawworkbar(path[1],2);
    drawworkbar(path[2],3);
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(100,100,200,200)==1)break;
    }
    fclose(f);
    delay(1000);
    CloseSVGA();
    return;
}*/

/*void main()
{
    SetSVGA64k();
	mouseinit();
    MouseS=1;
    bar(100,100,200,200,65535);
    drawwork_main();
    while(1)
    {
        mouse_renew(&MouseX,&MouseY,&press);
        if(mouse_press(100,100,200,200)==1)break;
    }
    delay(1000);
    CloseSVGA();
    return;
}

/*void drawworkbar(char*path,int n)
{
    FILE* ptemp=fopen(path,"rb+");
    WORKFILE* wp=malloc(sizeof(WORKFILE));
    fread(wp,sizeof(WORKFILE),1,ptemp);
    bar(222,130+(n-1)*120,782,220+(n-1)*120,0);
    put_hz24_asc32(230, 160+(n-1)*120,wp->name,65535, "C:\\TEST\\HZK\\HZK24");
    switch(wp->place)
    {
        case OlymMon:
            put_hz24(420,160+(n-1)*120,"奥林匹斯山",65535,"C:\\TEST\\HZK\\HZK24");
            break;
        case MariVal:
            put_hz24(420,160+(n-1)*120,"水手大峡谷",65535,"C:\\TEST\\HZK\\HZK24");
            break;
        case ArabTer:
            put_hz24(420,160+(n-1)*120,"阿拉伯高地",65535,"C:\\TEST\\HZK\\HZK24");
            break;
        case UtopPla:
            put_hz24(420,160+(n-1)*120,"乌托邦平原",65535,"C:\\TEST\\HZK\\HZK24");
            break;
        case ElysPla:
            put_hz24(420,160+(n-1)*120,"埃律西昂平原",65535,"C:\\TEST\\HZK\\HZK24",0);
            break;
    }
    fclose(ptemp);
    free(wp);
}
*/
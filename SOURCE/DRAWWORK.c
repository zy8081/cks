#include<common.h>
#include <game.h>
#include<ORDFUNS.h>

#include<WRKMNG.h>
#include<WRKPLC.h>
#include<DRAWWORK.h>
int workcount(char *user)
{
    char temp;
    int i=0;
    int j=0;
    int k=0;
    char*patht=malloc((size_t)60);
    FILE* f;
    sprintf(patht,"WORKS\\%s\\CONTENT.TXT",user);
    f=fopen(patht,"rt+");
    if (f==NULL)
    {
        CloseSVGA();
        printf("can not open!user:%s",user);
        getch();
        exit(0);
    }
    //put_asc16_size(0,20,1,1,patht,10);
    while(temp!='#')
    {
        char* path=malloc((size_t)40);
        if(path==NULL)
        {
            fclose(f);
            put_asc16_size(0,20,1,1,"No enough memory",10);
            getch();
            return 0;
        }
        while(1)
        {
            
            temp=fgetc(f);
            fseek(f,0,1); 
            
            if((temp>='0'&&temp<='9')||(temp>='a'&&temp<='z')||(temp>='A'&&temp<='Z')||temp=='\\'||temp==':')
            {   
                
                path[i]=temp;
                i++;
            }
            else if(temp=='.')
            {
                
                path[i]=temp;
                i++;
                for(j=0;j<3;j++,i++)
                {
                    temp=fgetc(f);
                    fseek(f,0,1);
                    path[i]=temp;
                }  
                k++; 
                i=0;
                //put_asc16_size(100,300+k*20,1,1,path,10);
                //getch();
                free(path);
                break;  
            }
            else if(temp=='#')
            {
                
                free(path);
                break;
            }
            
        }

    }
    //put_asc16_size(0,1,1,1,"opened",10);
    rewind(f);
    //put_asc16_size(0,30,1,1,"break1",10);
    fclose(f);
    //put_asc16_size(0,60,1,1,"break2",10);
    //put_asc16_size(0,90,1,1,"break3",10);
    free(patht);
    //put_asc16_size(0,120,1,1,"break4",10);
    return k;
}


void drawworkbar(char*path,int n,int form)
{
    FILE* ptemp=fopen(path,"rb+");
    WORKFILE wp={"error",0,"\0","\0",0};
    fread(&wp,sizeof(WORKFILE),1,ptemp);
    //bar(0,360,100,400,65535);
    //put_asc16_size(0,360,1,1,wp.name,25545);
    //getch();
    if(form==1)
    {
        //put_asc16_size(0,360,1,1,path,25545);
        btn_bar_Draw0(222,130+(n-1)*120,782,220+(n-1)*120);
    }
    else if(form==0)
        //put_asc16_size(0,400,1,1,path,25545);
        btn_bar_Draw(222,130+(n-1)*120,782,220+(n-1)*120);
    
    put_hz24_asc32(230, 160+(n-1)*120,wp.name,65535, "HZK\\HZK24");
    switch(wp.place)
    {
        case OlymMon:
            put_hz24(420,160+(n-1)*120,"奥林匹斯山",65535,"HZK\\HZK24",0);
            break;
        case MariVal:
            put_hz24(420,160+(n-1)*120,"水手大峡谷",65535,"HZK\\HZK24",0);
            break;
        case ArabTer:
            put_hz24(420,160+(n-1)*120,"阿拉伯高地",65535,"HZK\\HZK24",0);
            break;
        case UtopPla:
            put_hz24(420,160+(n-1)*120,"乌托邦平原",65535,"HZK\\HZK24",0);
            break;
        case ElysPla:
            put_hz24(420,160+(n-1)*120,"埃律西昂平原",65535,"HZK\\HZK24",0);
            break;
    }
    fclose(ptemp);
}

void drawworkmain(int workpage,int n,char* user)
{
    char temp;
    char*patht=malloc((size_t)60);
    int i=0;
    int j=0;
    int k=0;
    FILE* f;
    sprintf(patht,"WORKS\\%s\\CONTENT.TXT",user);
    f=fopen(patht,"rt+");
    while(k<n)
    {
        char* path=malloc((size_t)50);
        while(1)
        {
            temp=fgetc(f);
            fseek(f,0,1); 
            if((temp>='0'&&temp<='9')||(temp>='a'&&temp<='z')||(temp>='A'&&temp<='Z')||temp=='\\'||temp==':')
            {   
                path[i]=temp;
                i++;
            }
            else if(temp=='.')
            {
                path[i]=temp;
                i++;
                for(j=0;j<3;j++,i++)
                {
                    temp=fgetc(f);
                    fseek(f,0,1);
                    path[i]=temp;
                } 
                path[i]='\0'; 
                if((k/4+1)==workpage)
                {
                    //put_asc16_size(0,30,1,1,path,10);
                    drawworkbar(path,k%4+1,0);
                }

                
                k++; 
                i=0;
                free(path);
                break;  
            }
            else if(temp=='#')break;
        }
        if(temp=='#')
            break;
    }
    rewind(f);
    fclose(f);
    free(patht);
    return;
}

//void read


void worksearch(int page,int n,char*(path[]),char*user)
{
    char temp=0;
    char*patht=malloc((size_t)60);
    int k=0;
    int g=(page-1)*4+n;
    int i=0;
    FILE* f;
    char c;
    sprintf(patht,"WORKS\\%s\\CONTENT.TXT",user);
    f=fopen(patht,"rt+");
    if (f==NULL)
    {
        debug_file_printf(patht);
    }
    while(k!=g)
    {
        c=fgetc(f);
        if(c=='\n')k++;
    }
    while(1)
    {
        temp=fgetc(f);
        if(temp!='\n'&&temp!='#')
        {
            (*path)[i]=temp;
            i++;
        }
        else break;
        
    }
    (*path)[i]='\0';
    fclose(f);
    free(patht);
    return;
}
#include<ALLFUNS.h>

int main()
{
    int page=4;
    char*user=malloc((size_t)21);
    char*path=malloc((size_t)60);
    WORKFILE workfile;
    strcpy(path,"\0");
    SetSVGA64k();
    mouseinit();
    
    MouseS=1;
    delay(1000);
    press=0;
    
    while(1)
    {
        //clrmous(MouseX,MouseY);
        switch(page)
        {
            case 0:
                start(&page);
                break;
            case 1:
                wrkmng_main(&page,user,&workfile);
                break;
            case 3:
                break;
            case 4:
                login(&page,&user);
                break;
            case 5:
                regist(&page);
                break;
            case 6:
                project(workfile,&page);
                break;

        }
        if(page==3)break;
    }
    delay(1000);
    free(user);
    free(path);
    CloseSVGA();
    return 0;
}


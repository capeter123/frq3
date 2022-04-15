#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#define _USE_MATH_DEFINES

//#include "rounder.c"

void gainSorter(char CrFile[10], char LmFile[20])
{
    FILE *LM, *CR, *img;
    LM=fopen(LmFile,"r+"); CR=fopen(CrFile,"r+");
    float quality=0, Cr=0, Lr=0, Lm=0,CrOG;
    int m=0;
    char name[FILENAME_MAX];
    char nameFile[200];




    for(int i=1;i<=20; i++)
    {
        while(fscanf(CR,"%e\n",&CrOG)!=EOF)
        {
            sprintf(nameFile,"./outputDat/Cap %e M %d.dat",CrOG,i); 
            img=fopen(nameFile,"wb");

            while(fscanf(LM,"%d\t%e\t%e\t%e\t%e\n",&m,&quality,&Cr,&Lr,&Lm)!=EOF)
            { 
                if(CrOG==Cr && m==i)
                {   
                    fprintf(img,"%d\t%e\t%e\t%e\n",m,Cr,rounder(Lr),rounder(Lm));         
                }

            }
            fseek(LM,0L,SEEK_SET);

            int len=ftell(img);
            fclose(img);
            if(len==0) remove(nameFile);

        }
        fseek(CR,0L,SEEK_SET);   
    }

    fclose(CR);fclose(LM);//fclose(img);
}
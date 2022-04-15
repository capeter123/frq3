#include <stdio.h>
#include <stdlib.h>
#include "Re.c"

void LrVal(char lrFile[20], char qFile[20],char CrFile[20],int uIn,int uOut,int Pwr, float biggestLr)
{
    FILE *LR, *QL,*CP;
    LR=fopen(lrFile,"w+"); QL=fopen(qFile,"r+"); CP=fopen(CrFile,"r+");

    float quality=0;
    float Res=Re(Pwr,uIn, uOut);
    float Lr=0,Cr=0;

    while(fscanf(QL,"%e",&quality)!= EOF)
    {
        while (fscanf(CP,"%e",&Cr)!=EOF)
        {
            Lr=pow(quality,2)*Cr*pow(Res,2);
            if (Lr<biggestLr)
            {     
                fprintf(LR,"%e\t%e\t%e\n",quality,Cr,Lr);
            }
                //printf("%e\t%e\t%f\n",Lr,Cr,quality);}
        }
        fseek(CP,0L,SEEK_SET);
    }




    fclose(LR);fclose(CP);fclose(QL);
}
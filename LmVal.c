#include <stdio.h>
#include <stdlib.h>

void LmVal(char LmFile[20],char LrFile[20],float biggestLm)
{   
    FILE *LR,*LM;
    LR=fopen(LrFile,"r+");LM=fopen(LmFile,"w+");

    float quality=0,Cr=0,Lr=0,Lm=0;

    //fprintf(LR,"%e\t%e\t%e\n",quality,Cr,Lr);
    for(int m=0;m<=20;m+=5)
    {
        while(fscanf(LR,"%e\t%e\t%e\n",&quality,&Cr,&Lr)!=EOF)
        {
            Lm=(m-1)*Lr;
            if(Lm<=biggestLm && Lm>0) 
            {
                fprintf(LM,"%d\t%e\t%e\t%e\t%e\n",m,quality,Cr,Lr,Lm);

            }
        }
        fseek(LR,0L,SEEK_SET);
    }

    fclose(LR);fclose(LM);
}
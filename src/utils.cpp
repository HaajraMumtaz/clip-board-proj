#include "utils.h"



char* inputUnlimited()
{

    int mySize=100;
    char*input=new char[mySize];
    int thisptr=0;
    char alph='p';
    while (alph!='\n')
    {

        cin.get(alph);
        input[thisptr++]=alph;
        if(thisptr==mySize)
        {
            
            char*temp=new char[mySize+100];
            for(int i=0;i<mySize;i++)
            {
                temp[i]=input[i];
            }
            mySize+=100;
            delete[]input;
            input = temp;
        }
    }

    if (thisptr < mySize )
    {
        char *temp = new char[thisptr];
        for (int i = 0; i < thisptr; i++)
        {
            temp[i] = input[i];
        }
         delete[] input;
        input = temp;
    }
    input[thisptr-1] = '\0';
   
    mySize = thisptr ;
    return input;
}
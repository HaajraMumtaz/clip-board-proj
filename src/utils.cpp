#include "utils.h"



char* inputUnlimited()
{

    int mySize=100;
    char*input=new char[mySize];
    int thisptr=0;
    cout<<"1"<<endl;
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
            input=temp;
        }
    }
    if (thisptr<mySize-1)
    {
        char*temp=new char[thisptr+1];
        for(int i=0;i<=thisptr;i++)
        {
            temp[i]=input[i];
        }
        delete[]input;
        input=temp;
        mySize=thisptr+1;
    }
    return input;
}
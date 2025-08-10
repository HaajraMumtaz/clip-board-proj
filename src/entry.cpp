#include "entry.h"
#include "utils.h"
#include <cstring>
char*entry:: getData()
{
    return this->data;
}
char*entry:: getLabel()
{
    return this->label;
}
bool entry:: isPinned()
{
    return (pinned);
}
void entry::pin(bool action)
{
    this->pinned=action;
}
void entry::setData(const char*&dataVar)
{
    strcpy(this->data,dataVar);
}
void entry::setLabel(const char*&labelVar)
{
    strcpy(this->label,labelVar);
}

entry::entry(char*dataVar,char*labelVar)
{
    data=new char[strlen(dataVar)];
    labelVar=new char[strlen(labelVar)];
    strcpy(data,dataVar);
    strcpy(label,labelVar);
    pinned=false;
}
entry::entry()
{
    data=new char[1];
    label=new char[1];
    data[0]=label[0]='\0';

}
void entry::printEntry()
{
    cout<<"----"<<label<<"----\n"<<data<<endl;
}
void entry::input()
{
   
   char lab[100];
   bool input = false;
   while (!input)
   {
        cout<<"enter label:";
       try
       {
           cin >> lab;
           input=true;
       }
       catch (const std::exception &e)
       {
           std::cerr << e.what() << '\n';
       }
   }


   cout<<"enter details:";
   char*det;
   cin.ignore();
   det=inputUnlimited();
   delete[]label;
   label=new char[strlen(lab)+1];
   strcpy(label,lab);
    delete[]data;
   data=new char[strlen(det)+1];
   strcpy(this->data,det);
   delete[]det;
}
entry::~entry()
{
    delete[] data;
    delete[] label;
}
bool entry::matchLabel(char*lab)//havent used strstr to improve personal logic
{
    bool matched=false;
    int labIx=0;;
    for(int i=0;i<(strlen(label)-strlen(lab)+1)&&!matched;i++)
    {
        if(lab[labIx]==label[i])
        {
            matched=true;
            int j=i;
            while(matched&&labIx!=strlen(lab))
            {
                if(lab[labIx++]!=label[j++])
                {
                    matched=false;
                }
            }
            labIx=0;
        }
    }
    return matched;
}
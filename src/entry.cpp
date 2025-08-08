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
void entry::input()
{
    char*temp;
    
}
entry::entry(char*dataVar,char*labelVar)
{
    data=new char(strlen(dataVar));
    labelVar=new char(strlen(labelVar));
    strcpy(data,dataVar);
    strcpy(label,labelVar);
    pinned=false;
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
           cin >> label;
           input=true;
       }
       catch (const std::exception &e)
       {
           std::cerr << e.what() << '\n';
       }
   }
   cout<<"enter details:";
   char*det;
   det=inputUnlimited();

   strcpy(label,lab);
   strcpy(this->data,det);
   delete[]det;
}
entry::~entry()
{
    delete[] data;
    delete[] label;
}
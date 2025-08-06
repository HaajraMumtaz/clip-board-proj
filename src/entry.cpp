#include "entry.h"
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
entry::~entry()
{
    delete[] data;
    delete[] label;
}
#include <iostream>
#include "clipboard.h"

clipboard::clipboard()
{
    allEntries=nullptr;
    currentSize=0;
    
}
void clipboard::pinEntry(int ix)
{
    allEntries[ix]->pin(true);
}

void clipboard::printEntry(int ix)
{
    if (ix<currentSize&&ix>=0)
    allEntries[ix]->printEntry();
    else
    cout<<"invalid index"<<endl;
}
void clipboard::addEntry()
{

    entry** temp;
    if (currentSize+1<=maxsize)
    {
        temp=new entry*[currentSize+1];

        for(int i=0;i<currentSize;i++)
        {
            temp[i]=allEntries[i];
        }
        temp[currentSize]=new entry();
        temp[currentSize]->input();
        delete[]allEntries;
        allEntries=temp;
        currentSize++;
        cout<<"successfully input. total entries are now:"<<currentSize<<"label:"<<allEntries[currentSize-1]->getLabel()<<endl;
    }
}
void clipboard::deleteEntry()
{
    bool deleted=false;
    int currentix=currentSize-1;

    while(!deleted&&currentix>=0)
    {
        if(!allEntries[currentix]->isPinned())
        {
            delete allEntries[currentix];
            allEntries[currentix]=nullptr;
            currentSize--;
            entry**temp=new entry*[currentSize];
            int j=currentSize-1;
            for(int i=currentSize;i>=0;i--)
            {
                if(i!=currentix)
                    temp[j--]=allEntries[i];
            }
            deleted=true;
            delete[]allEntries;
            allEntries=temp;
        }
        else
        currentix--;
    }
}
void clipboard::deleteEntry(int ix)
{
  
    if (ix>=0&&ix<currentSize)
    {
        entry**temp=new entry*[currentSize-1];
        delete allEntries[ix];
        allEntries[ix] = nullptr;
        int j=0;
        for(int i=0;i<currentSize;i++)
        {
            if(i!=ix)
            {
                temp[j++]=allEntries[i];
            }
        }
        delete[]allEntries;
        allEntries=temp;
        currentSize--;
    }
}
clipboard::~clipboard()
{
    for (int i=0;i<currentSize;i++)
    {
        delete[]allEntries[i];
    }
    delete[]allEntries;
}
int clipboard::matchlabel(char*lab)
{
    int ix=-1;
    for(int i=0;i<currentSize&&ix==-1;i++)
    {
        if(allEntries[i]->matchLabel(lab))
        ix=i;
    }
    return ix;
}
void clipboard::pin(int ix, bool action)
{
    allEntries[ix]->pin(action);
}
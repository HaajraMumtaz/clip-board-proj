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
    if (ix<=currentSize&&ix>0)
    allEntries[ix]->printEntry();
}
void clipboard::addEntry()
{
    entry** temp;
    if (currentSize+1<=maxsize)
    {
        temp=new entry*[currentSize++];

        for(int i=0;i<currentSize;i++)
        {
            temp[i]=allEntries[i];
        }
        temp[currentSize]=new entry();
        delete[]allEntries;
        allEntries=temp;
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

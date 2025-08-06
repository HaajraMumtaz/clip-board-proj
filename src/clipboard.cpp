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
void deleteEntry();
~clipboard();

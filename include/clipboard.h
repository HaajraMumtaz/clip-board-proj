#include <iostream>
#include "entry.h"

class clipboard
{
private:
entry**allEntries;
const int maxsize=5;
int currentSize;
public:
clipboard();
void pinEntry(int ix);
void printEntry(int ix);
inline int Getmaxsize()
{
    return maxsize;
}
inline int Getcurrsize()
{
    return currentSize;
}
int matchlabel(char* lab);
void addEntry();
void deleteEntry();
void deleteEntry(int ix);
void pin(int ix, bool action);
~clipboard();
};
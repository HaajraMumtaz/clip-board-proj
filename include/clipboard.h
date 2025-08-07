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
void addEntry();
void deleteEntry();
void deleteEntry(int ix);
~clipboard();
};
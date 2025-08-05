#include <iostream>
#include "entry.h"

class clipboard
{
private:
entry**allEntries;

public:
clipboard();
void pinEntry(int ix);
void printEntry(int ix);
void addEntry();
void deleteEntry();
~clipboard();
};
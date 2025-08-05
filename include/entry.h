#include <iostream>
#include <cstring>
using namespace std;

class entry
{
private:
char* data;
char* label;
bool pinned;
public:
entry();
char* getData();
char* getLabel();
void pin(bool action);
bool isPinned();
void setData(const char*&dataVar);
void setLabel(const char*&labelVar);
~entry();
};



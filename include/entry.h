#pragma once
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
entry(char*vardata,char*labelvar);
entry();
char* getData();
char* getLabel();
bool matchLabel(char*lab);
void pin(bool action);
bool isPinned();
void setData(const char*&dataVar);
void setLabel(const char*&labelVar);
void printEntry();
void input();
~entry();
};



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
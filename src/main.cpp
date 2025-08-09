#include <iostream>
#include "entry.h"
#include "clipboard.h"
using namespace std;

int main()
{
    clipboard*mainBoard=new clipboard();
    int choice=-1;

    while (choice!=8)
    {
        cout<<"Enter 1 to add entry\nEnter 2 to delete the last unpinned entry\nEnter 3 to delete an entry by it's index\nEnter 4 to delete an entry by label\nEnter 5 to pin\nunpin an entry\nEnter 6 to print an entry\nEnter 7 to restart\nEnter 8 to exit";
        cin>>choice;

        if(choice >0&&choice<9)
        {

        }
        else
        cout<<"invalid choice, enter again.";
    }

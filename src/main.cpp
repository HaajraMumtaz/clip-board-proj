#include <iostream>
#include "entry.h"
#include "clipboard.h"
#include"utils.h"
using namespace std;

int main()
{
    clipboard*mainBoard=new clipboard();
    int choice=-1;

    while (choice!=8)
    {
        cout<<"Enter 1 to add entry\nEnter 2 to delete the last unpinned entry\nEnter 3 to delete an entry by it's index\nEnter 4 to delete an entry by label\nEnter 5 to pin an entry\nEnter 6 to unpin an entry\nEnter 7 to print an entry\nEnter 8 to exit"<<endl<<"choice:";
        cin>>choice;
        cout<<"your choice:"<<choice<<endl;
        if(choice >0&&choice<9)
        {
            if(choice==1)
            mainBoard->addEntry();
            else if (choice ==2)
            mainBoard->deleteEntry();
            else if (choice == 3||choice==5||choice==6||choice==7)
            {
                cout<<"enter index:";
                int ix;
                cin>>ix;
                if(ix>-1&&ix<mainBoard->Getcurrsize())
                {
                    if(choice==3)
                    mainBoard->deleteEntry(ix);
                    else if(choice==5)
                    mainBoard->pin(ix,true);
                    else if(choice==6)
                    mainBoard->pin(ix,false);
                    else if(choice==7)
                    mainBoard->printEntry(ix);


                }
                else
                cout<<"invalid index."<<endl;
            }
            else if(choice==4)
            {
                char*label;
                cout<<"which label?"<<endl;
                label=inputUnlimited();
                
                int ix=mainBoard->matchlabel(label);
                if(ix!=-1)
                {
                    mainBoard->deleteEntry(ix);
                }
                else
                cout<<"no entry with similar label"<<endl;
            }
        }
        else
        cout<<"invalid choice, enter again."<<endl;
    }
}

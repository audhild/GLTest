
#include <iostream>
#include <string>
#include "SearchFile.h"

using namespace FileManager;


int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        printf("\nYou need to enter file name!\n");
        return 1;
    }
    else if (argc > 2) 
    {
        printf("\nToo much arguments! You need to enter only one file name.\n");
        return 1;
    }
    else
    {
        printf("\nStarting to search file: %s\n\n ...", argv[1]);
    }
    
    std::string fileName = argv[1];
    
    //searching for names with extensions not implemented

    size_t lastindex = fileName.find_last_of(".");
    std::string fName = fileName.substr(0, lastindex);

    SearchFile* A = new SearchFile();
    A->runSearching(fName);
    delete A;
    
    return 0;
}

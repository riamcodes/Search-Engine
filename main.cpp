#include <iostream>

using namespace std;
 #include "UserInterface.h"

int main()
{
    cout << "Usage:\n"
         << "\tIndex all files in <directory> and store the index in one or several files:\n"
         << "\tsupersearch index <directory>\n\n"
         << "\tLoad the existing index and perform the following query:\n"
         << "\tsupersearch query \"social network PERSON:cramer\"\n\n"
         << "\tStart a simple text-based user interface that lets the user create an index,\n\tsave/load the index and perform multiple queries:\n"
         << "\tsupersearch  ui\n\n";

    cout << "supersearch not implemented yet." << endl; //edits
}

//     #include "UserInterface.h"

// userinterface ui;
// String mode; 
// mode = argv[1];

// if (mode =="index"){
//     string directory = argv[2];
//     uicreateIndex(directory);
// }

// if(mode == "query"){
//     string queryCommand = argv[2];
//     ui.enterQuery(queryCommand);
// }
    
   
//     return 0;
// }
#include "DocumentParser.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <filesystem>
#include <dirent.h>
#include <algorithm>
#include "porter2_stemmer.h" // Include the Porter Stemmer header
//str tok in the remove  or use the existing sentiment analyzer
using namespace rapidjson;
using namespace std;

void DocumentParser::parseDocument(const string& jsonContent) {
    string docId;
    ifstream ifs(jsonContent);
    if (!ifs.is_open()) {
        cerr << "Could not open file for reading: " << jsonContent << endl;
        return;
    }

    IStreamWrapper isw(ifs);
    Document d;
    d.ParseStream(isw);

    if (d.HasParseError()) {
        cerr << "JSON parse error: " << d.GetParseError() << endl;
        return;
    }

   d.ParseStream(isw);
  

    // // Now that the document is parsed, we can access different elements the JSON using
    // // familiar subscript notation.

    // // This accesses the -title- element in the JSON. Since the value
    // //  associated with title is a string (rather than
    // //  an array or something else), we call the GetString()
    // //  function to return the actual title of the article
    // //  as a c-string.
    // auto val = d["title"].GetString();
    // cout << "Title: " << val << "\n";

    // // The Persons entity for which you're building a specific
    // //  inverted index is contained in top level -entities- element.
    // //  So that's why we subscript with ["entities"]["persons"].
    // //  The value associated with entities>persons is an array.
    // //  So we call GetArray() to get an iterable collection of elements
    // auto persons = d["entities"]["persons"].GetArray();

    // // We iterate over the Array returned from the line above.
    // //  Each element kind of operates like a little JSON document
    // //  object in that you can use the same subscript notation
    // //  to access particular values.
    // cout << "  Person Entities + sentiment:"
    //      << "\n";
    // for (auto &p : persons)
    // {
    //     cout << "    > " << setw(30) << left << p["name"].GetString()
    //          << setw(10) << left << p["sentiment"].GetString() << "\n";
    // }
if(d.HasMember("uuid") && d["uuid"].IsString()){
    docId = d["uuid"].GetString();
}
else {
    cerr << "The JSON does not contain a uuid attribute";
}

     if (d.HasMember("text") && d["text"].IsString()) {
        //cout << "Text: " << d["text"].GetString() << "\n";
        //THIS PRINTS OUT EACH WORD ON A NEW LINE
       string text = d["text"].GetString();

        // Use a string stream to tokenize the text
        istringstream iss(text);
        string word;
        while (iss >> word) {
            // the transform function comes from tha algorithm include
            //processes word from beginning to end and then goes back to the beginning and makes everyting lowercase 
            transform(word.begin(), word.end(), word.begin(), ::tolower); 
            Porter2Stemmer::stem(word);

            cout << docId << endl;
            cout << word << endl;  // Print each word on a new line

        }
    } else {
        cerr << "The JSON does not contain a 'text' attribute or it is not a string." << endl;
    }

    cout << endl;
}

// // make a directroy set it to to the big file then dirent read directory of the big file  as long as it doesnt equal nullptr
// //Open directoryin folder with open dir
// struct dirent diread; sub fulder files
// goal is to get the name of the folders sub folders and the name of the subfile  
// diread = readir(dir) to get sub folders
// diread todname to get file names
// vectorMstring> folders
// folders.pushback*diread- name 
// then do it again


void DocumentParser::traverseSubdirectory(const string& directoryPath){
// Open the directory
    DIR* dir = opendir(directoryPath.c_str()); //c_str so it can be passed to opendir
    if (dir == nullptr) {
        cerr << "Could not open directory: " << directoryPath << endl;
        return;
    }

    struct dirent* entry;
    vector<string> subdirectories;

    // Read the directory entries 
    while ((entry = readdir(dir)) != nullptr) {
          // Exclude the current (.) and parent (..) directories
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                subdirectories.push_back(entry->d_name);
            }
     
    }
// cout << subdirectories.at(0);
// cout << subdirectories.at(1);
// cout << subdirectories.at(2);
    // Close the directory
    closedir(dir);

    // Iterate over the subdirectories to read their contents
    for (const auto& subdir : subdirectories) {
        string subdirPath = directoryPath + "/" + subdir;
        DIR* subDir = opendir(subdirPath.c_str());
        if (subDir == nullptr) {
            cerr << "Could not open subdirectory: " << subdirPath << endl;
            continue;
        }
    

     cout << "Contents of subdirectory: " << subdir << endl;
        // Read the subdirectory entries
        while ((entry = readdir(subDir)) != nullptr) {
        
        //    cout << "  File: " << entry->d_name << endl; dont print file name anymore now call parse Document 
            string filePath = subdirPath + "/" + entry->d_name;
         parseDocument(filePath); 
        
        }

        // Close the subdirectory
        closedir(subDir);
    }
}




            //handler.addWords(word, id);
            //handler.addPerson(person, id);
            //handler.addOrgs(org, id);




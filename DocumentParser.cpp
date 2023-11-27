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
#include "IndexHandler.h"
#include "porter2_stemmer.h" // Include the Porter Stemmer header
//str tok in the remove  or use the existing sentiment analyzer
using namespace rapidjson;
using namespace std;

//list of stopwords found from https://gist.github.com/sebleier/554280 NLTK list of english stopwords
// set<string> stopWords = { "i", "me", "my", "myself", "we", "our", "ours", "ourselves", "you", "your",
//     "yours", "yourself", "yourselves", "he", "him", "his", "himself", "she", "her",
//     "hers", "herself", "it", "its", "itself", "they", "them", "their", "theirs",
//     "themselves", "what", "which", "who", "whom", "this", "that", "these", "those",
//     "am", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had",
//     "having", "do", "does", "did", "doing", "a", "an", "the", "and", "but", "if", "or",
//     "because", "as", "until", "while", "of", "at", "by", "for", "with", "about", "against",
//     "between", "into", "through", "during", "before", "after", "above", "below", "to", "from",
//     "up", "down", "in", "out", "on", "off", "over", "under", "again", "further", "then", "once",
//     "here", "there", "when", "where", "why", "how", "all", "any", "both", "each", "few", "more",
//     "most", "other", "some", "such", "no", "nor", "not", "only", "own", "same", "so", "than", "too",
//     "very", "s", "t", "can", "will", "just", "don", "should", "now"};

DocumentParser::DocumentParser(){
    string filename = "sample_data/stopWords.txt"; // go two back in the directory and get stopwords out of the assignment folder
    string temp;
    ifstream input(filename);               // declare ifstream and open stopwords file
    if (!input.is_open())                   // make sure it is open
    {
        cerr << "Opening the stopwords file failed!";
        exit(1);
    }
    while(getline(cin, temp)) // while there are more comma separated values
    {
        stopwords.insert(temp); // push back the values to stopwords vector
    }
    input.close();
}

void DocumentParser::parseDocument(const string& jsonContent) {
    IndexHandler index;
    int wordCount = 0;
    string docID;
    string docPersons;
    string org;
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
  

   
if (d.HasMember("uuid") && d["uuid"].IsString()) {
     docID = d["uuid"].GetString();
  //   index.addDocument(int, DSDocument); ask anekah how this works 
}

if (d.HasMember("persons") && d["persons"].IsString()) {
     docPersons = d["persons"].GetString();
  //   index.addPeople(std::string, int) ask anekah how this works 
}
if (d.HasMember("organizations") && d["organizations"].IsString()) {
     org = d["organizations"].GetString();
  //   void addOrgs(int, DSDocument); ask anekah how this works WARNING THIS IS USUALLY BLANK
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
            //cout << docID<< endl; 
             if (stopwords.find(word) == stopwords.end()) {
            cout << word << endl;  // Print each word on a new line
            wordCount++;
          //  index.addWords(word, docID); ASK ANEKAH HOW THIS WORKS 

             }
        }
    } else {
        cerr << "The JSON does not contain a 'text' attribute or it is not a string." << endl;
    }

    cout << endl;
    cout << "Document ID: " << docID << " Word Count: " << wordCount++ << endl;
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
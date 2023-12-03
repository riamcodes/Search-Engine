/**
 * Example code related to final project
 */
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <iomanip>
#include <filesystem>
#include <dirent.h>

// RapidJSON headers we need for our parsing.
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/document.h"
#include "DocumentParser.h"
using namespace rapidjson;
using namespace std;

// // Function Prototypes
// void testReadJsonFile(const string &fileName);
// void testFileSystem(const string &path);

int main()
{

//cout << "hello world";

 DocumentParser parser;
 //parser.printDocument("/users7/cse/rmukherji/assignment-4-search-engine-exit-code-0/kaggleSample6000/2018_03_112b52537b67659ad3609a234388c50a/news_0022791.json");
   //parser.parseDocument("/users7/cse/rmukherji/assignment-4-search-engine-exit-code-0/kaggleSample6000/2018_03_112b52537b67659ad3609a234388c50a/news_0022791.json");
   parser.printInfo("/users7/cse/rmukherji/assignment-4-search-engine-exit-code-0/sample_data/coll_1/news_0064567.json");


//Uncomment the following lines to do every single document. The lines above this test docParser on only one json file to see whats going on
//string bigFilePath = "/users7/cse/rmukherji/assignment-4-search-engine-exit-code-0/kaggleSample6000"; // Replace with the path to your directory
// parser.traverseSubdirectory(bigFilePath);
//
}
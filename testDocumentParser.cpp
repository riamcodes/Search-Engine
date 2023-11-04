/**
 * Example code related to final project
 */
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <iomanip>

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
    parser.parseDocument("/users7/cse/rmukherji/assignment-4-search-engine-exit-code-0/kaggleSample6000/2018_03_112b52537b67659ad3609a234388c50a/news_0022791.json");
    return 0;

}
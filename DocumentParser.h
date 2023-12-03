#ifndef DOCUMENT_PARSER_H
#define DOCUMENT_PARSER_H
#include "IndexHandler.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/document.h"
#include "IndexHandler.h"
#include "porter2_stemmer.h" // Include the Porter Stemmer header
#include <string>
#include <vector>
#include <map>
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
#include <set>

class DocumentParser
{
private:
    IndexHandler ih;
    std::vector<std::string> titles;

public:
    void parseDocument(const std::string &jsonContent);
    void printDocument(const std::string &jsonContent);
    void setIndex(IndexHandler ih);
    IndexHandler getIndex();
    void traverseSubdirectory(const std::string &directoryPath);
    void printInfo(const std::string &jsonContent);
    std::string getTitle(int num) { return titles[num]; };
};
#endif
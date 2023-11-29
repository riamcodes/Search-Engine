#ifndef QUERY_PROCESSOR_H
#define QUERY_PROCESSOR_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include "IndexHandler.h"
#include "DSDocument.h"

class QueryProcessor
{
private:
    // int totalDocs
    // int tf; // tf = nWordDoc/nDoc
    // int idf; // idf = log2(n/nWord)
    // tf - idf = (tf)(idf)
    std::vector<std::string> storage;
    std::vector<std::pair<std::string, int>> relevantDocuments; 
    std::vector<std::string> printVector;
    IndexHandler *indexObject;

public:
    QueryProcessor(); 
    void parsingAnswer(std::string); 
    void disectAnswer();
    void relevancy(); 
    std::vector<std::pair<std::string, int>> intersection(std::vector<std::pair<std::string, int>>, std::map<std::string, int>); 
    std::vector<std::pair<std::string, int>> complement(std::vector<std::pair<std::string, int>>, std::map<std::string, int>); 
    void setIndexHandler(IndexHandler* i);
    std::vector<std::string> Relevency(std::vector<std::pair<std::string, int>>);
    void quickSort(std::vector<std::pair<std::string, int>>&, int, int);
    int partition(std::vector<std::pair<std::string, int>>, int, int);
};
#endif
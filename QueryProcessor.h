#ifndef QUERY_PROCESSOR_H
#define QUERY_PROCESSOR_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include "IndexHandler.h"
#include "porter2_stemmer.h"

class QueryProcessor
{
private:
    // int totalDocs
    // int tf; // tf = nWordDoc/nDoc
    // int idf; // idf = log2(n/nWord)
    // tf - idf = (tf)(idf)
    std::vector<std::string> storage;
    //std::vector<std::pair<std::string, int>> relevantDocuments; 
    std::map<std::string, int> relevantDocuments;
    std::vector<std::string> relDocs;
    std::vector<std::string> printVector;
    IndexHandler *indexObject = new IndexHandler();

public:
    QueryProcessor(); 
    std::vector<std::string> parsingAnswer(std::string); 
    std::vector<std::string> disectAnswer();
    std::vector<std::string> relevancy(); 
    std::vector<std::string> intersection(std::map<std::string, int>, std::map<std::string, int>); 
    std::vector<std::string> complement(std::map<std::string, int>, std::map<std::string, int>); 
    void setIndexHandler(IndexHandler* i);
    std::vector<std::string> Relevency(std::map<std::string, int>);
    void quickSort(std::map<std::string, int>&, int, int);
    int partition(std::map<std::string, int>, int, int);
};
#endif
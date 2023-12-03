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
    std::map<std::string, int> relDocs;
    std::map<std::string, int> sendTo;
   
    IndexHandler indexObject;
    //  = new IndexHandler()

public:
    QueryProcessor(); 
    ///moved just to see if works
     std::vector<std::string> printVector;
//////
    std::map<std::string, int> parsingAnswer(std::string); 
    std::map<std::string, int> disectAnswer();
    std::map<std::string, int> intersection(std::map<std::string, int>, std::map<std::string, int>); 
    std::map<std::string, int> complement(std::map<std::string, int>, std::map<std::string, int>); 
    void setIndexHandler(IndexHandler i);
    std::vector<std::string> Relevancy(std::map<std::string, int>);
    void quickSort(std::map<std::string, int>&, int, int);
    int partition(std::map<std::string, int>, int, int);
};
#endif
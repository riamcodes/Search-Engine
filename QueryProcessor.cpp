#include "QueryProcessor.h"

std::vector<std::string> QueryProcessor::parsingAnswer(std::string answer) // processes the answer
{
    size_t start = 0;
    std::vector<std::string> storage;
    for (size_t i = 0; i < answer.size(); i++) 
    {
        if(!isalpha(answer[i])) {
            if (i > start) {
                tolower(answer[i]);
                std::string newStorage = answer.substr(start, i - start);
                storage.push_back(newStorage);
            }
            start = i + 1;
        }
    }
    if (start < answer.size()) {
        tolower(answer[0]);
        std::string newStorage = answer.substr(start, answer.size() - start);
        storage.push_back(newStorage);
    }
    // if (std::find(answer.begin(), answer.end(), "ORG") != answer.end())
    // {
    //     for (int i = 0; i < answer.size(); i++)
    //     {
    //     }
    // }
    // else if (std::find(answer.begin(), answer.end(), "PERSON") != answer.end())
    // {
    //     // person was found, process accordingly
    // }
    // else
    // {
    //     // no key word was found, process accordingly
    // }
}

void QueryProcessor::relevancy() // possibly just call another function implementing tfidf
{
}

void QueryProcessor::print() // prints out the relevant documents
{
}
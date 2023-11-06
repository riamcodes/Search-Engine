#include "QueryProcessor.h"

void QueryProcessor::processingQuery(std::string answer) // processes the answer
{
    if (answer == "3")
    {
       if(std::find(answer.begin(), answer.end(), "ORG" != answer.end()))
       {
            // org was found, process accordiningly
       }
       else if (std::find(answer.begin(), answer.end(), ))
    }
    else
    {
        throw std::runtime_error("Invalid answer directed to the query processor");
    }
}

void QueryProcessor::relevancy() // possibly just call another function implementing tfidf
{

}

void QueryProcessor::print() // prints out the relevant documents
{

}
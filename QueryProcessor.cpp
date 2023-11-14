#include "QueryProcessor.h"

QueryProcessor::QueryProcessor() // Default Constructor
{
    tf = 0;
    idf = 0;
}

void QueryProcessor::parsingAnswer(std::string answer) // Parses the answer
{
    size_t start = 0;
    for (size_t i = 0; i < answer.size(); i++)
    {
        if (!isalpha(answer[i]))
        {
            if (i > start)
            {
                tolower(answer[i]);
                std::string newStorage = answer.substr(start, i - start);
                storage.push_back(newStorage);
            }
            start = i + 1;
        }
    }
    if (start < answer.size())
    {
        tolower(answer[0]);
        std::string newStorage = answer.substr(start, answer.size() - start);
        storage.push_back(newStorage);
    }
}

void QueryProcessor::disectAnswer() // This function disects the parsed answer
{
    std::vector<std::string> relevantDocuments;
    int totalDocs = 0;
    for (int i = 0; i < storage.size(); i++)
    {
        if (storage[i].substr(0,4) == "ORG:") 
        {
            std::string term = storage[i].substr(4, storage[i].length() - 4);
            // relevantDocuments.push_back(get this term from the index handler);
            totalDocs += relevantDocuments.size();
        }
        else if (storage[i].substr(0, 7) == "PERSON:")
        {
            std::string term = storage[i].substr(7, storage[i].length() - 7);
            // relevantDocuments.push_back(get this term from the index handler);
            totalDocs += relevantDocuments.size();
        }
        else if (storage[i].substr(0, 1) == "-")
        {
            std::string term = storage[i].substr(1, storage[i].length() - 1);
            // relevantDocuments.push_back(get this term from the index handler);
            totalDocs += relevantDocuments.size();
        }
        else
        {
            std::string term = storage[i];
            // relevantDocuments.push_back(get this term from the index handler);
            totalDocs += relevantDocuments.size();
            if (i == 0)
            {
                
            }
        }
    }
}

void QueryProcessor::ifNot()
{

}

void QueryProcessor::elseThis()
{

}
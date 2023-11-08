#include "QueryProcessor.h"

void QueryProcessor::parsingAnswer(std::string answer) // parses the answer
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
    // if (std::find(answer.begin(), answer.end(), "ORG") != answer.end() || std::find(answer.begin(), answer.end(), "PERSON") != answer.end())
    // {
    // }
    // else
    // {
    // }
}

void QueryProcessor::directAnswer()
{
    for (int i = 0; i < storage.size(); i++)
    {
        while (storage[i] != "-")
        if (storage[i] == "ORG")
        {
        }
        else if (storage[i] == "PERSON")
        {
        }
        else
        {
        }
    }
}

// void QueryProcessor::print() // prints out the relevant documents
// {
// }
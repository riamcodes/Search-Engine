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
}

void QueryProcessor::directAnswer()
{
    std::vector<std::string> orgStorage;
    std::vector<std::string> personStorage;
    std::vector<std::string> wordStorage;
    std::vector<std::string> notStorage;
    for (int i = 0; i < storage.size(); i++)
    {
        if (std::find(storage[i].begin(), storage[i].end(), "ORG") != storage[i].end())
        {
            for (int j = 0; j < storage[i].length(); j++)
            {
                if (storage[j] == ":")
                {
                    for (int k = j + 1; k < storage[i].length(); k++)
                    {
                        orgStorage.push_back(storage[k]);
                    }
                    orgStorage.push_back(",");
                }
            }
        }
        else if (std::find(storage[i].begin(), storage[i].end(), "PERSON") != storage[i].end())
        {
            for (int j = 0; j < storage[i].length(); j++) 
            {
                if (storage[j] == ":")
                {
                    for (int k = j + 1; k < storage[i].length(); k++)
                    {
                        personStorage.push_back(storage[k]);
                    }
                    personStorage.push_back(",");
                }
            }
        }
        else if (std::find(storage[i].begin(), storage[i].end(), "-") != storage[i].end())
        {
            // can not a person or organization be a case or does this just effect words
        }
        else
        {
            for (int j = 0; j < storage[i].length(); j++) 
            {
                wordStorage.push_back(storage[j]);
            }
            wordStorage.push_back(",");
        }
    }
}

// void QueryProcessor::print() // prints out the relevant documents
// {
// }
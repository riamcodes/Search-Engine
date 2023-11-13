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

void QueryProcessor::disectAnswer() // This function disects the parsed answer and divides it based on what it contains
{
    
    for (int i = 0; i < storage.size(); i++)
    {
        if (std::find(storage[i].begin(), storage[i].end(), "ORG") != storage[i].end()) // ORG Instance
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
        else if (std::find(storage[i].begin(), storage[i].end(), "PERSON") != storage[i].end()) // PERSON Instance
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
        else if (std::find(storage[i].begin(), storage[i].end(), "-") != storage[i].end()) // Not Instance
        {
            for (int j = 0; j < storage[i].length(); j++)
            {
                notStorage.push_back(storage[j]);
            }
            notStorage.push_back(",");
        }
        else // Word Instance
        {
            for (int j = 0; j < storage[i].length(); j++) 
            {
                wordStorage.push_back(storage[j]);
            }
            wordStorage.push_back(",");
        }
    }
}

void QueryProcessor::directAnswer() // This function will take the disected vectors and direct them to where they need to go
{
    for (int i = 0; i < wordStorage.size(); i++)
    {
        if (storage[i] == ",")
        {
            // new word
        }
        else
        {
            // process a word
        }
    }
    for (int i = 0; i < personStorage.size(); i++)
    {
        if (storage[i] == ",")
        {
            // new person
        }
        else
        {
            // process a person
        }
    }
    for (int i = 0; i < orgStorage.size(); i++)
    {
        if (storage[i] == ",")
        {
            // new org
        }
        else
        {
            // process a org
        }
    }
    for (int i = 0; i < notStorage.size(); i++)
    {
        if (storage[i] == ",")
        {
            // new not instance
        }
        else
        {
            // process a not instance
        }
    }
}

void QueryProcessor::print() // prints out the relevant documents
{
}
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
    for (int i = 0; i < storage.size(); i++) 
    {
        while (storage[i] != "-")
        {
            if (storage[i] == "PERSON")
            {

            }
            else if (storage[i] == "ORG")
            {

            }
            else 
            {
                
            }
        }
    }
    // if (std::find(storage.begin(), storage.end(), "ORG") != storage.end() && std::find(storage.begin(), storage.end(), "PERSON") != storage.end())
    // {
    //     for (int i = 0; i < storage.size(); i++)
    //     {
    //         while (storage[i] != "-")
    //         {
    //             if (storage[i] == "ORG")
    //             {
    //             }
    //             else if (storage[i] == "PERSON")
    //             {
    //             }
    //             else
    //             {
    //                 // find the word in the map and print out the relevant documents
    //             }
    //         }
    //     }
    // }
    // else if (std::find(storage.begin(), storage.end(), "ORG") != storage.end()) 
    // {
    //     for (int j = 0; j < storage.size(); j++)
    //     {
    //         while (storage[j] != "-")
    //         {
    //             if (storage[j] == "ORG")
    //             {

    //             }
    //             else
    //             {
    //                 // find the word in the map and print out the relevant documents
    //             }
    //         }
    //     }
    // }
    // else if (std::find(storage.begin(), storage.end(), "PERSON") != storage.end())
    // {
    //     for (int k = 0; k < storage.size(); k++)
    //     {
    //         while (storage[k] != "-")
    //         {
    //             if (storage[k] == "PERSON")
    //             {

    //             }
    //             else
    //             {
    //                 // find the word in the map and print out the relevant documents
    //             }
    //         }
    //     }
    // }
}

// void QueryProcessor::print() // prints out the relevant documents
// {
// }
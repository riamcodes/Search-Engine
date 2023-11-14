#include "QueryProcessor.h"

QueryProcessor::QueryProcessor() // Default Constructor
{
    tf = 0;
    idf = 0;
    totalDocs = 0;
}

void QueryProcessor::setIndexHandler(*indexObject)
{

}

std::vector<document> QueryProcessor::parsingAnswer(std::string answer) // Parses the answer
{
    size_t start = 0;
    storage.clear();
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
    for (int i = 0; i < storage.size(); i++)
    {
        if (storage[i].substr(0,4) == "ORG:") 
        {
            std::string term = storage[i].substr(4, storage[i].length() - 4);
            std::vector<pair<char, int>> docs = indexObject->getOrg(term);
            relevantDocs = intersection(relevantDocs, docs);
        }
        else if (storage[i].substr(0, 7) == "PERSON:")
        {
            std::string term = storage[i].substr(7, storage[i].length() - 7);
            std::vector<pair<char, int>> docs = indexObject->gePerson(term);
            relevantDocs = intersection(relevantDocs, docs);
        }
        else if (storage[i].substr(0, 1) == "-")
        {
            std::string term = storage[i].substr(1, storage[i].length() - 1);
            std::vector<pair<char, int>> docs = indexObject->getWord(term);
            relevantDocs = complement(relevantDocs, docs);
        }
        else
        {
            std::string term = storage[i];
            if (i == 0)
            {
                relevantDocs = indexObject->getWord(term);
            } 
            else 
            {
                std::vector<pair<char, int>> docs = indexObject->getWord(term);
                relevantDocs = intersection(relevantDocs, docs);
            }
        }
    }
}

std::vector<pair<document, int>> QueryProcessor::intersection() // documents in "A" and "B"
{
    std::vector<pair<document, int>> docs1;
    std::vector<pair<document, int>> docs2;
    std::vector<pair<document, int>> finalVector;
    for (int i = 0; i < docs1.size(); i++)
    {
        for (int j = 0; j < docs2.size(); j++)
        {
            if (docs1[i].first == docs2[j].first) // eventually need to add a unique identifier from doc parser
            {
                finalVector.push_back(docs1[i]);
                finalVector[(finalVector.size() - 1).second += docs2[j].second];
                break;
            }
        }
    }
    return finalVector;
}

std::vector<pair<document, int>> QueryProcessor::complement() // documents in "A" and not "B"
{
    std::vector<pair<document, int>> docs1;
    std::vector<pair<document, int>> docs2;
    std::vector<pair<document, int>> finalVector; 
    for (int i = 0; i < docs1.size() i++)
    {
        bool found = false;
        for (int j = 0; j < docs2.size(); j++)
        {
            if (docs1[i].first == docs2[j].first) // eventually need to add a unique identifier from doc parser
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            finalVector.push_back(docs1[i]);
        }
    }
    return finalVector;
}

void QueryProcessor::relevency(std::vector<document> storage)
{

}
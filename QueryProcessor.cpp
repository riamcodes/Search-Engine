#include "QueryProcessor.h"

QueryProcessor::QueryProcessor() // Default Constructor
{
    // tf = 0;
    // idf = 0;
    // totalDocs = 0;
}

void QueryProcessor::setIndexHandler(IndexHandler* i) // Sets the Index Handler Object
{

}

std::vector<std::string> QueryProcessor::parsingAnswer(std::string answer) // Parses the answer from the UI
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
        if (storage[i].substr(0, 4) == "ORG:")
        {
            std::string term = storage[i].substr(4, storage[i].length() - 4);
            std::vector<std::pair<char, int>> docs = indexObject->getOrgs(term);
            relevantDocuments = intersection(relevantDocuments, docs);
        }
        else if (storage[i].substr(0, 7) == "PERSON:")
        {
            std::string term = storage[i].substr(7, storage[i].length() - 7);
            std::vector<std::pair<char, int>> docs = indexObject->getPerson(term);
            relevantDocuments = intersection(relevantDocuments, docs);
        }
        else if (storage[i].substr(0, 1) == "-")
        {
            std::string term = storage[i].substr(1, storage[i].length() - 1);
            std::vector<std::pair<char, int>> docs = indexObject->getWords(term);
            relevantDocuments = complement(relevantDocuments, docs);
        }
        else
        {
            std::string term = storage[i];
            if (i == 0)
            {
                relevantDocuments = indexObject->getWords(term);
            }
            else
            {
                std::vector<std::pair<char, int>> docs = indexObject->getWords(term);
                relevantDocuments = intersection(relevantDocuments, docs);
            }
        }
    }
}

std::vector<std::pair<document, int>> QueryProcessor::intersection(std::vector<std::pair<char, int>> relevantDocuments, std::vector<std::pair<char, int>> docs) // documents in "A" and "B"
{
    std::vector<std::pair<document, int>> docs1;
    std::vector<std::pair<document, int>> docs2;
    std::vector<std::pair<document, int>> finalVector;
    for (int i = 0; i < docs1.size(); i++)
    {
        for (int j = 0; j < docs2.size(); j++)
        {
            if (docs1[i].first.uuid == docs2[j].first.uuid) // eventually need to add a unique identifier from doc parser
            {
                finalVector.push_back(docs1[i]);
                finalVector[finalVector.size() - 1].second += docs2[j].second;
                break;
            }
        }
    }
    return finalVector;
}

std::vector<std::pair<document, int>> QueryProcessor::complement(std::vector<std::pair<char, int>> relevantDocuments, std::vector<std::pair<char, int>> docs) // documents in "A" and not "B"
{
    std::vector<std::pair<document, int>> docs1;
    std::vector<std::pair<document, int>> docs2;
    std::vector<std::pair<document, int>> finalVector;
    for (int i = 0; i < docs1.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < docs2.size(); j++)
        {
            if (docs1[i].first.uuid == docs2[j].first.uuid) // eventually need to add a unique identifier from doc parser
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

std::vector<std::pair<document, int>> QueryProcessor::Relevency(std::vector<std::pair<document, int>> finalVector) // This finds the relevency of the document
{
    // n = index handler docs.size()
    // nword = search document size
    for (int i = 0; i < finalVector.size(); i++)
    {
        double tf = (double)(finalVector[i].second / finalVector[i].first.totalWordCount); 
        double idf = log2((double)(indexObject->getNumDocs() / finalVector.size())); // function from index handler
        finalVector[i].first.relevancy = tf * idf;
    }
    // sort docs by docs[i].first.relevancy
    // quick sort
    return finalVector;
}
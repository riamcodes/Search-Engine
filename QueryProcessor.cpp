#include "QueryProcessor.h"

QueryProcessor::QueryProcessor() // Default Constructor
{
    // tf = 0;
    // idf = 0;
    // totalDocs = 0;
}

void QueryProcessor::setIndexHandler(IndexHandler *i) // Sets the Index Handler Object
{
    indexObject = i;
}

void QueryProcessor::parsingAnswer(std::string answer) // Parses the answer from the UI
{
    size_t start = 0;
    storage.clear();
    std::string temp;
    std::stringstream ss(answer);
    while (getline(ss, temp, ' ')) {
        storage.push_back(temp);
    }
}

void QueryProcessor::disectAnswer() // This function disects the parsed answer
{
    for (int i = 0; i < storage.size(); i++)
    {
        if (storage[i].length() > 4 && storage[i].substr(0, 4) == "ORG:")
        {
            std::string term = storage[i].substr(4, storage[i].length() - 4);
            std::map<std::string, int> docs = indexObject->getOrgs(term);
            // std::vector<std::pair<std::string, int>> docs = indexObject->getOrgs(term); // was DSDocument
            relevantDocuments = intersection(relevantDocuments, docs);
        }
        else if (storage[i].length() > 7 && storage[i].substr(0, 7) == "PERSON:")
        {
            std::string term = storage[i].substr(7, storage[i].length() - 7);
            std::map<std::string, int> docs = indexObject->getPeople(term);
            // std::vector<std::pair<std::string, int>> docs = indexObject->getPeople(term); // was DSDocument
            relevantDocuments = intersection(relevantDocuments, docs);
        }
        else if (storage[i].substr(0, 1) == "-")
        {
            std::string term = storage[i].substr(1, storage[i].length() - 1);
            std::map<std::string, int> docs = indexObject->getWords(term);
            // std::vector<std::pair<std::string, int>> docs = indexObject->getWords(term); // was DSDocument
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
                std::map<std::string, int> docs = indexObject->getWords(term);
                //std::vector<std::pair<std::string, int>> docs = indexObject->getWords(term);
                relevantDocuments = intersection(relevantDocuments, docs);
            }
        }
    }
}

std::vector<std::pair<std::string, int>> QueryProcessor::intersection(std::vector<std::pair<std::string, int>> relevantDocuments, std::map<std::string, int> docs) // documents in "A" and "B"
{
    std::vector<std::pair<std::string, int>> docs1;
    std::vector<std::pair<std::string, int>> docs2;
    std::vector<std::pair<std::string, int>> finalVector;
    for (int i = 0; i < docs1.size(); i++)
    {
        for (int j = 0; j < docs2.size(); j++)
        {
            if (docs1[i].first == docs2[j].first) 
            {
                finalVector.push_back(docs1[i]);
                finalVector[finalVector.size() - 1].second += docs2[j].second;
                break;
            }
        }
    }
    return finalVector;
}

std::vector<std::pair<std::string, int>> QueryProcessor::complement(std::vector<std::pair<std::string, int>> relevantDocuments, std::map<std::string, int> docs) // documents in "A" and not "B"
{
    std::vector<std::pair<std::string, int>> docs1;
    std::vector<std::pair<std::string, int>> docs2;
    std::vector<std::pair<std::string, int>> finalVector;
    for (int i = 0; i < docs1.size(); i++)
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

std::vector<std::string> QueryProcessor::Relevency(std::vector<std::pair<std::string, int>> finalVector) // This finds the relevency of the document
{
    int n = indexObject->getDocSize();
    // int nword = search document size
    for (int i = 0; i < finalVector.size(); i++)
    {
        double tf = (double)(finalVector[i].second / finalVector[i].first.totalWordCount);
        double idf = log2((double)(indexObject->returnNumArticles() / finalVector.size())); 
        finalVector[i].second = tf * idf;
    }
    int size = finalVector.size();
    quickSort(finalVector, 0, size);
    if (finalVector.size() <= 15) 
    {
        for (int j = 0; j <= finalVector.size(); j++)
        {
            printVector.push_back(finalVector[j].first);
        }
    }
    else 
    {
        for (int i = 0; i <= 15; i++)
        {
            printVector.push_back(finalVector[i].first);
        }
    }
    return printVector;
}

void QueryProcessor::quickSort(std::vector<std::pair<std::string, int>> &vec, int low, int high)
{
    if (low < high)
    {
        int p = partition(vec, low, high);
        quickSort(vec, low, p - 1);
        quickSort(vec, p + 1, high);
    }
}

int QueryProcessor::partition(std::vector<std::pair<std::string, int>> vec, int low, int high)
{
    double pivot = vec[high].second;
    int i = (low - 1);
    for (int j = low; j <= high; j++)
    {
        if (vec[j].second < pivot)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return (i + 1);
}
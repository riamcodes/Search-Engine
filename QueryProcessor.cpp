#include "QueryProcessor.h"

QueryProcessor::QueryProcessor()
{
}

void QueryProcessor::setIndexHandler(IndexHandler i)
{
    indexObject = i;
}

std::map<std::string, int> QueryProcessor::parsingAnswer(std::string answer) // Parses the answer from the UI
{
    storage.clear();
    std::string temp;
    std::stringstream ss(answer);
    while (getline(ss, temp, ' '))
    {
        storage.push_back(temp);
    }
    return disectAnswer();
}

std::map<std::string, int> QueryProcessor::disectAnswer() 
{
    for (size_t i = 0; i < storage.size(); i++)
    {
        if (storage[i].length() > 4 && storage[i].substr(0, 4) == "ORG:")
        {
            std::string term = storage[i].substr(4, storage[i].length() - 4);
            std::map<std::string, int> docs = indexObject.getOrgs(term);
            relDocs = intersection(relevantDocuments, docs);
        }
        else if (storage[i].length() > 7 && storage[i].substr(0, 7) == "PERSON:")
        {
            std::string term = storage[i].substr(7, storage[i].length() - 7);
            std::map<std::string, int> docs = indexObject.getPeople(term);
            relDocs = intersection(relevantDocuments, docs);
        }
        else if (storage[i].substr(0, 1) == "-")
        {
            std::string term = storage[i].substr(1, storage[i].length() - 1);
            Porter2Stemmer::trim(term);
            Porter2Stemmer::stem(term);
            std::map<std::string, int> docs = indexObject.getWords(term);
            relDocs = complement(relevantDocuments, docs);
        }
        else
        {
            std::string term = storage[i];
            Porter2Stemmer::trim(term);
            Porter2Stemmer::stem(term);
            if (i == 0)
            {
                relevantDocuments = indexObject.getWords(term);
                sendTo = relevantDocuments;
            }
            else
            {
                std::map<std::string, int> docs = indexObject.getWords(term);
                relDocs = intersection(relevantDocuments, docs);
            }
        }
    }
    Relevancy(sendTo);
    return relDocs;
}

std::map<std::string, int> QueryProcessor::intersection(std::map<std::string, int> relevantDocuments, std::map<std::string, int> docs) // documents in "A" and "B"
{
    std::map<std::string, int> finalVector;
    for (const auto &itr : relevantDocuments)
    {
        if (docs.find(itr.first) != docs.end())
        {
            finalVector[itr.first] = itr.second;
        }
    }
    sendTo = finalVector;
    return finalVector;
}

std::map<std::string, int> QueryProcessor::complement(std::map<std::string, int> relevantDocuments, std::map<std::string, int> docs) // documents in "A" and not "B"
{
    std::map<std::string, int> finalVector;
    for (const auto &itr : relevantDocuments)
    {
        if (docs.find(itr.first) == docs.end())
        {
            finalVector[itr.first] = itr.second;
        }
    }
    sendTo = finalVector;
    return finalVector;
}

std::vector<std::string> QueryProcessor::Relevancy(std::map<std::string, int> sendTo) 
{
    for (auto &itr : sendTo)
    {
        double wordCount = indexObject.getWordCount(itr.first);
        double tf = (double)(itr.second / wordCount);
        double idf = log2((double)(indexObject.getDocSize() / sendTo.size()));
        itr.second = tf * idf;
    }
    if (sendTo.size() <= 15)
    {
        for (const auto &itr : sendTo)
        {
            printVector.push_back(itr.first);
        }
    }
    else
    {
        int index = 0;
        for (const auto &itr : sendTo)
        {
            if (index < 15)
            {
                printVector.push_back(itr.first);
                ++index;
            }
            else
                break;
        }
    }
    return printVector;
}
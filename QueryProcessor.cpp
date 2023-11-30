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

std::vector<std::string> QueryProcessor::parsingAnswer(std::string answer) // Parses the answer from the UI
{
    //size_t start = 0;
    storage.clear();
    std::string temp;
    std::stringstream ss(answer);
    while (getline(ss, temp, ' ')) {
        storage.push_back(temp);
    }
    return disectAnswer();
}

std::vector<std::string> QueryProcessor::disectAnswer() // This function disects the parsed answer
{
    for (size_t i = 0; i < storage.size(); i++)
    {
        if (storage[i].length() > 4 && storage[i].substr(0, 4) == "ORG:")
        {
            std::string term = storage[i].substr(4, storage[i].length() - 4);
            std::map<std::string, int> docs = indexObject->getOrgs(term);
            // std::vector<std::pair<std::string, int>> docs = indexObject->getOrgs(term); // was DSDocument
            relDocs = intersection(relevantDocuments, docs);
        }
        else if (storage[i].length() > 7 && storage[i].substr(0, 7) == "PERSON:")
        {
            std::string term = storage[i].substr(7, storage[i].length() - 7);
            std::map<std::string, int> docs = indexObject->getPeople(term);
            // std::vector<std::pair<std::string, int>> docs = indexObject->getPeople(term); // was DSDocument
            relDocs = intersection(relevantDocuments, docs);
        }
        else if (storage[i].substr(0, 1) == "-")
        {
            std::string term = storage[i].substr(1, storage[i].length() - 1);
            std::map<std::string, int> docs = indexObject->getWords(term);
            // std::vector<std::pair<std::string, int>> docs = indexObject->getWords(term); // was DSDocument
            relDocs = complement(relevantDocuments, docs);
        }
        else
        {
            std::string term = storage[i];
            if (i == 0)
            {
                relevantDocuments = indexObject->getWords(term); 
                //relevantDocuments = indexObject->getWords(term);////////////////
            }
            else
            {
                std::map<std::string, int> docs = indexObject->getWords(term);
                //std::vector<std::pair<std::string, int>> docs = indexObject->getWords(term);
                relDocs = intersection(relevantDocuments, docs);
            }
        }
    }
    return relDocs;
}

std::vector<std::string> QueryProcessor::intersection(std::map<std::string, int> relevantDocuments, std::map<std::string, int> docs) // documents in "A" and "B"
{
    // std::map<std::string, int> docs1;
    // std::map<std::string, int> docs2;
    std::map<std::string, int> finalVector;
    for (const auto &itr : relevantDocuments) 
    {
        if(docs.find(itr.first) != docs.end()){
            finalVector[itr.first] = itr.second;
        }
    }
    // for (int i = 0; i < docs1.size(); i++)
    // {
    //     for (int j = 0; j < docs2.size(); j++)
    //     {
    //         if (docs1[i] == docs2[j]) 
    //         {
    //             finalVector.push_back(docs1[i]);
    //             finalVector[finalVector.size() - 1].second += docs2[j].second;
    //             break;
    //         }
    //     }
    // }
    return Relevency(finalVector);
}

std::vector<std::string> QueryProcessor::complement(std::map<std::string, int> relevantDocuments, std::map<std::string, int> docs) // documents in "A" and not "B"
{
    // std::map<std::string, int> docs1;
    // std::map<std::string, int> docs2;
    std::map<std::string, int> finalVector;
    for (const auto &itr : relevantDocuments) 
    {
        if(docs.find(itr.first) == docs.end()){
            finalVector[itr.first] = itr.second;
        }
    }
    // for (int i = 0; i < docs1.size(); i++)
    // {
    //     bool found = false;
    //     for (int j = 0; j < docs2.size(); j++)
    //     {
    //         if (docs1[i].first == docs2[j].first) // eventually need to add a unique identifier from doc parser
    //         {
    //             found = true;
    //             break;
    //         }
    //     }
    //     if (!found)
    //     {
    //         finalVector.push_back(docs1[i]);
    //     }
    // }
    return Relevency(finalVector);
}

std::vector<std::string> QueryProcessor::Relevency(std::map<std::string, int> finalVector) // This finds the relevency of the document
{
    //int n = indexObject->getDocSize();
    for (auto &itr : finalVector)
    {
        double wordCount = indexObject->getWordCount(itr.first);
        double tf = (double)(itr.second / wordCount);
        double idf = log2((double)(indexObject->getDocSize() / finalVector.size()));
        itr.second = tf * idf;
    }
    // for (int i = 0; i < finalVector.size(); i++)
    // {
    //     double tf = (double)(finalVector[i].second / finalVector[i].first.totalWordCount);//////////////
    //     double idf = log2((double)(indexObject->getDocSize() / finalVector.size())); /////////////////
    //     finalVector[i].second = tf * idf;
    // }
    //int size = finalVector.size();
    //quickSort(finalVector, 0, size);
    if (finalVector.size() <= 15) 
    {
        for (const auto &itr : finalVector) 
        {
            printVector.push_back(itr.first);
        }
        // for (int j = 0; j <= finalVector.size(); j++)
        // {
        //     printVector.push_back(finalVector[j].first);
        // }
    }
    else 
    {
        int index = 0;
        for (const auto &itr : finalVector)
        {
            if(index < 15){
                printVector.push_back(itr.first);
                ++index;
            }
            else
                break;
        }
    }
    return printVector;
}

// void QueryProcessor::quickSort(std::map<std::string, int> &vec, int low, int high)
// {
//     if (low < high)
//     {
//         int p = partition(vec, low, high);
//         quickSort(vec, low, p - 1);
//         quickSort(vec, p + 1, high);
//     }
// }

// int QueryProcessor::partition(std::map<std::string, int> vec, int low, int high)
// {
//     double pivot = vec[high];
//     int i = (low - 1);
//     for (int j = low; j <= high; j++)
//     {
//         if (vec[j].second < pivot)
//         {
//             i++;
//             swap(vec[i], vec[j]);
//         }
//     }
//     swap(vec[i + 1], vec[high]);
//     return (i + 1);
// }
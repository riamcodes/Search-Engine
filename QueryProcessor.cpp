#include "QueryProcessor.h"

QueryProcessor::QueryProcessor() // Default Constructor
{
  
}

void QueryProcessor::setIndexHandler(IndexHandler i) // Sets the Index Handler Object
{
    indexObject = i;
}
//
std::map<std::string, int> QueryProcessor::parsingAnswer(std::string answer) // Parses the answer from the UI
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


   


std::map<std::string, int> QueryProcessor::disectAnswer() // This function disects the parsed answer
{
    for (size_t i = 0; i < storage.size(); i++)
    {
        if (storage[i].length() > 4 && storage[i].substr(0, 4) == "ORG:")
        {
            std::string term = storage[i].substr(4, storage[i].length() - 4);
            //Porter2Stemmer::stem(term);
            std::map<std::string, int> docs = indexObject.getOrgs(term);
            // std::vector<std::pair<std::string, int>> docs = indexObject->getOrgs(term); // was DSDocument
            relDocs = intersection(relevantDocuments, docs);
        }
        else if (storage[i].length() > 7 && storage[i].substr(0, 7) == "PERSON:")
        {
            std::string term = storage[i].substr(7, storage[i].length() - 7);
           // cstem(term);
          //
           
           // std::cout << term << std::endl;
            //relevantDocuments = indexObject->getPeople(term);
            std::map<std::string, int> docs = indexObject.getPeople(term);
           
            // std::vector<std::pair<std::string, int>> docs = indexObject->getPeople(term); // was DSDocument
          
            relDocs = intersection(relevantDocuments, docs);
        }
        else if (storage[i].substr(0, 1) == "-")
        {
            std::string term = storage[i].substr(1, storage[i].length() - 1);
            Porter2Stemmer::trim(term);
            Porter2Stemmer::stem(term);
            std::map<std::string, int> docs = indexObject.getWords(term);
            // std::vector<std::pair<std::string, int>> docs = indexObject->getWords(term); // was DSDocument
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
                //relevantDocuments = indexObject->getWords(term);////////////////
               
            }
            else
            {
                std::map<std::string, int> docs = indexObject.getWords(term);
                //std::vector<std::pair<std::string, int>> docs = indexObject->getWords(term);
                relDocs = intersection(relevantDocuments, docs);
               
            }
        }
    }
    

// //-------------------------------------------Ria added this 
//     std::cout << "Relevant Documents:" << std::endl;
//     for (const auto& doc : relDocs) {
//         std::cout << doc << std::endl;}
//         //-------------------------------------------
    Relevancy(sendTo);
    return relDocs;
    
}

std::map<std::string, int> QueryProcessor::intersection(std::map<std::string, int> relevantDocuments, std::map<std::string, int> docs) // documents in "A" and "B"
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
    sendTo = finalVector;
    return finalVector;
}

std::map<std::string, int> QueryProcessor::complement(std::map<std::string, int> relevantDocuments, std::map<std::string, int> docs) // documents in "A" and not "B"
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
   
    sendTo = finalVector;
    return finalVector;
}

std::vector<std::string> QueryProcessor::Relevancy(std::map<std::string, int> sendTo) // This finds the relevency of the document
{
    //int n = indexObject->getDocSize();
    for (auto &itr : sendTo)
    {
        double wordCount = indexObject.getWordCount(itr.first);
        double tf = (double)(itr.second / wordCount);
        double idf = log2((double)(indexObject.getDocSize() / sendTo.size()));
        itr.second = tf * idf;
    }
    // for (int i = 0; i < finalVector.size(); i++)/
    // {
    //     double tf = (double)(finalVector[i].second / finalVector[i].first.totalWordCount);//////////////
    //     double idf = log2((double)(indexObject->getDocSize() / finalVector.size())); /////////////////
    //     finalVector[i].second = tf * idf;
    // }
    //int size = finalVector.size();
    //quickSort(finalVector, 0, size);
    //finalVector.push_back("hello");
    if (sendTo.size() <= 15) 
    {
        for (const auto &itr : sendTo) 
        {
            //std::string vectorContent = indexObject->getTitle(itr.first);
           // printVector.push_back(vectorContent);
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
        for (const auto &itr : sendTo)
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
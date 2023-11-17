#include "IndexHandler.h"

std::vector<std::pair<document, int>> IndexHandler::getWords(std::string word){
    std::map<int, int> idAndFreq;
    std::map<document, int> temp;
    std::vector<std::pair<document, int>> returnDocs;
    idAndFreq = words.contains(word);
    for(const auto &itr : idAndFreq){
        document d = docs[itr.first];
        returnDocs.push_back(std::make_pair(d, itr.first));
        }
    return returnDocs;
}
std::vector<std::pair<document, int>> IndexHandler::getPeople(std::string person){
    std::map<int, int> idAndFreq;
    std::map<document, int> temp;
    std::vector<std::pair<document, int>> returnDocs;
    idAndFreq = people.find(person);
    for(const auto &itr : idAndFreq){
        document d = docs[itr.first];
        returnDocs.push_back(std::make_pair(d, itr.first));
        }
    return returnDocs;
}
std::vector<std::pair<document, int>> IndexHandler::getOrgs(std::string org){
    std::map<int, int> idAndFreq;
    std::map<document, int> temp;
    std::vector<std::pair<document, int>> returnDocs;
    idAndFreq = orgs.find(org);
    for(const auto &itr : idAndFreq){
        document d = docs[itr.first];
        returnDocs.push_back(std::make_pair(d, itr.first));
        }
    return returnDocs;
}
void IndexHandler::addWords(std::string word, int id){
    words.insert(word, id);
}
void IndexHandler::addPeople(std::string person, int id){
    people.insert(person, id);
}
void IndexHandler::addOrgs(std::string org, int id){
    orgs.insert(org, id);
}
void IndexHandler::addDocument(int id, document doc){
    docs[id] = doc;
}
void IndexHandler::createPersistence(std::string filename){
    //talking to lab today
}
void IndexHandler::readPersistence(std::string){
    
}
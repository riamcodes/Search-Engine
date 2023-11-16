#include "IndexHandler.h"

std::vector<std::pair<rapidjson::Document, int>> IndexHandler::getWords(std::string word){
    std::map<int, int> idAndFreq;
    std::vector<std::pair<rapidjson::Document, int>> returnDocs;
    int i = 0;
    rapidjson::Document doc;
    idAndFreq = words.contains(word);
    for(const auto &itr : idAndFreq){
        for(const auto &itr2 : docs){
            if(itr.first == itr2.first)
            returnDocs[i].first = itr2.second;
            returnDocs[i].second = itr.second;
        }
    }
    return returnDocs;
}
std::vector<std::pair<rapidjson::Document, int>> IndexHandler::getPeople(std::string person){
    return people.find(person);
}
std::vector<std::pair<rapidjson::Document, int>> IndexHandler::getOrgs(std::string org){
    return orgs.find(org);
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
void IndexHandler::addDocument(int id, rapidjson::Document doc){
    docs[id] == doc;
}
void IndexHandler::createPersistence(std::string filename){
    //talking to lab today
}
void IndexHandler::readPersistence(std::string){
    
}
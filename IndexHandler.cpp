#include "IndexHandler.h"

std::map<std::string, int> IndexHandler::getWords(std::string word){
    return words.contains(word);
}
std::map<std::string, int> IndexHandler::getPeople(std::string person){
    return people.find(person);
}
std::map<std::string, int> IndexHandler::getOrgs(std::string org){
    return orgs.find(org);
}
void IndexHandler::addWords(std::string word, std::string id){
    words.insert(word, id);
}
void IndexHandler::addPeople(std::string person, std::string id){
    people.insert(person, id);
}
void IndexHandler::addOrgs(std::string org, std::string id){
    orgs.insert(org, id);
}
void IndexHandler::createPersistence(std::string filename){
    //talking to lab today
}
void IndexHandler::readPersistence(std::string){
    
}
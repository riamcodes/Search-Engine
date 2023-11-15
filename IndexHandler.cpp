#include "IndexHandler.h"

std::vector<std::pair<document, int>> IndexHandler::getWords(std::string word){
    words.contains(word);
}
std::vector<std::pair<document, int>> IndexHandler::getPeople(std::string person){

}
std::vector<std::pair<document, int>> IndexHandler::getOrgs(std::string org){

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
void IndexHandler::createPersistence(std::string){

}
void IndexHandler::readPersistence(std::string){
    
}
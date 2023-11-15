#include "IndexHandler.h"

vector<pair<document, int>> IndexHandler::getWords(std::string word){

}
vector<pair<document, int>> IndexHandler::getPeople(std::string person){

}
vector<pair<document, int>> IndexHandler::getOrgs(std::string org){

}
void IndexHandler::addWords(std::string word, int id, int freq){
    words.insert(word, id, freq);
}
void IndexHandler::addPeople(std::string person, int id, int freq){
    people.insert(person, id, freq);
}
void IndexHandler::addOrgs(std::string org, int id, int freq){
    orgs.insert(org, id, freq);
}
void IndexHandler::addDocument(document){

}
void IndexHandler::createPersistence(std::string){

}
void IndexHandler::readPersistence(std::string){

}
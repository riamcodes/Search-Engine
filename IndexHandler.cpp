#include "IndexHandler.h"
std::map<std::string, int> IndexHandler::getWords(std::string word){
    return words.contains(word);
}
// std::map<int,int> IndexHandler ::getWordCount(int wordCount){
// words.insert(wordCount,id);
// }
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
void IndexHandler::addDocument(std::string id){
    docs.push_back(id);
}
int IndexHandler::getDocSize(){
    return docs.size();
}
void IndexHandler::createPersistence(std::string filename, std::string tree){
    std::ofstream output(filename);
    if(!output.is_open()){
        std::cerr << "Error! File could not be opened!" << std::endl;
        exit(-1);
    }
    if(tree == "words"){
        words.printTree(output);
    }
    else if(tree == "people"){
        people.printHash(output);
    }
    else if(tree == "orgs"){
        orgs.printHash(output);
    }
    output.close();
}
void IndexHandler::readPersistence(std::string filename, std::string tree){
    std::ifstream input(filename);
    std::string temp;
    std::string node;
    std::string id;
    std::string freq;
    std::map<std::string, int> temporary;
    if(!input.is_open()){
        std::cerr << "Error! File could not be opened!" << std::endl;
        exit(-1);
    }
    while(getline(input, temp)){
        int index = 0;
        for(int i = 0; i < temp.length(); i++){
            if(temp[i] == ':'){
                node = temp.substr(index, i-1);
                index = i+1;
            }
            else if(temp[i] == ','){
                id = temp.substr(index, i-1);
                index = i+1;
            }
            else if(temp[i] == ';'){
                freq = temp.substr(index, i-1);
                index = i+1;
                temporary[id] = stoi(freq);
            }
        }
        if(tree == "words"){
            words.insert(node, id);
        }
        if(tree == "people"){
            people.insert(node, id);
        }
        if(tree == "orgs"){
            orgs.insert(node, id);
        }
    }
    input.close();
}

int IndexHandler::returnNumArticles(std::string index, std::string tree){
    std::map<std::string, int> temp;
    if(tree == "words"){
        temp = words.contains(index);
        return temp.size();
    }
    else if(tree == "orgs"){
        temp = orgs.find(index);
        return temp.size();
    }
    else if(tree == "people"){
        temp = people.find(index);
        return temp.size();
    }
    return -1;
}
int IndexHandler::returnSize(std::string tree){
    if(tree == "words"){
        return words.getSize();
    }
    else if(tree == "orgs"){
        return orgs.getSize();
    }
    else if(tree == "people"){
        return people.getSize();
    }
    return -1;
}
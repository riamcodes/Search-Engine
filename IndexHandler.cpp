#include "IndexHandler.h"
std::map<std::string, int> IndexHandler::getWords(std::string word){
    return words.contains(word);
}
int IndexHandler ::getWordCount(std::string title){
    return wordCount[title];
}
std::map<std::string, int> IndexHandler::getPeople(std::string person){
    return people.find(person);
}
std::map<std::string, int> IndexHandler::getOrgs(std::string org){
    return orgs.find(org);
}
std::string IndexHandler::getFilePath(std::string title){
    return docs[title];
}
void IndexHandler::addWordCount(std::string title, int count){
    wordCount[title] = count;
}
void IndexHandler::addWords(std::string word, std::string filepath){
    words.insert(word, filepath);
}
void IndexHandler::addPeople(std::string person, std::string filepath){
    people.insert(person, filepath);
}
void IndexHandler::addOrgs(std::string org, std::string filepath){
    orgs.insert(org, filepath);
}
void IndexHandler::addDocument(std::string filepath, std::string title){
    docs[title] = filepath;
}
int IndexHandler::getDocSize(){
    return docs.size();
}
void IndexHandler::createPersistence(std::string tree){
    std::ofstream output("persistence.txt");
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
void IndexHandler::readPersistence(std::string tree){
    std::ifstream input("persistence.txt");
    std::string temp;
    std::string node;
    std::string id;
    std::string freq;
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
            }
        }
        if(tree == "words"){
            words.insert(node, id, stoi(freq));
        }
        if(tree == "people"){
            people.insert(node, id, stoi(freq));
        }
        if(tree == "orgs"){
            orgs.insert(node, id, stoi(freq));
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
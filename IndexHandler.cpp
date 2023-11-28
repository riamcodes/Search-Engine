#include "IndexHandler.h"

std::vector<std::pair<DSDocument, int>> IndexHandler::getWords(std::string word){
    std::map<int, int> idAndFreq;
    std::map<DSDocument, int> temp;
    std::vector<std::pair<DSDocument, int>> returnDocs;
    idAndFreq = words.contains(word);
    for(const auto &itr : idAndFreq){
        DSDocument d = docs[itr.first];
        returnDocs.push_back(std::make_pair(d, itr.first));
        }
    return returnDocs;
}
std::vector<std::pair<DSDocument, int>> IndexHandler::getPeople(std::string person){
    std::map<int, int> idAndFreq;
    std::map<DSDocument, int> temp;
    std::vector<std::pair<DSDocument, int>> returnDocs;
    idAndFreq = people.find(person);
    for(const auto &itr : idAndFreq){
        DSDocument d = docs[itr.first];
        returnDocs.push_back(std::make_pair(d, itr.first));
        }
    return returnDocs;
}
std::vector<std::pair<DSDocument, int>> IndexHandler::getOrgs(std::string org){
    std::map<int, int> idAndFreq;
    std::map<DSDocument, int> temp;
    std::vector<std::pair<DSDocument, int>> returnDocs;
    idAndFreq = orgs.find(org);
    for(const auto &itr : idAndFreq){
        DSDocument d = docs[itr.first];
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
void IndexHandler::addDocument(int id, DSDocument doc){
    docs[id] = doc;
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
    std::string key;
    std::string val1;
    std::string val2;
    if(!input.is_open()){
        std::cerr << "Error! File could not be opened!" << std::endl;
        exit(-1);
    }
    while(getline(input, temp)){
        int index = 0;
        for(int i = 0; i < temp.length(); i++){
            if(temp[i] == ':'){
                key = temp.substr(index, i-1);
                index = i+1;
            }
            else if(temp[i] == ','){
                val1 = temp.substr(index, i-1);
                index = i+1;
            }
            else if(temp[i] == ';'){
                val2 = temp.substr(index, i-1);
                index = i+1;
            }
        }
        if(tree == "words"){
            words.insert(key, stoi(val1));
        }
        if(tree == "people"){
            people.insert(key, stoi(val1));
        }
        if(tree == "orgs"){
            orgs.insert(key, stoi(val1));
        }
    }
}
#ifndef INDEX_HANDLER_H
#define INDEX_HANDLER_H
#include "Hash.h"
#include "DSAvlTree.h"
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

class IndexHandler
{
private:
    DSAvlTree<std::string, std::string> words;
    Hash<std::string, std::string> people;
    Hash<std::string, std::string> orgs;
    std::vector<std::string> docs;
    std::map<std::string, int> wordCount;

public:
    std::map<std::string, int> getWords(std::string);
    std::map<std::string, int> getPeople(std::string);
    std::map<std::string, int> getOrgs(std::string);
    int getWordCount(std::string);
    void addWords(std::string, std::string);
    void addPeople(std::string, std::string);
    void addOrgs(std::string, std::string);
    void addDocument(std::string);
    void addWordCount(std::string, int);
    int getDocSize();
    void createPersistence();
    void readPersistence();
    int returnSize();
};
#endif
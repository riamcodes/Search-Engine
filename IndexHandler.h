#ifndef INDEX_HANDLER_H
#define INDEX_HANDLER_H
#include "Hash.h"
#include "DSAvlTree.h"
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include "DSDocument.h"
#include <algorithm>

// This class should contain a lot of setter/getter functions for the avl and hash index
// When we want to add or get a query then we will call these functions
// We also need to store all of the documents
// Two ways to do this
// These two options also depend on the document parser, so communicate on this
// 1.) Store all needed data in a vector for quick and easy access (def an easier option to code)(internal storage)
// 2.) Store file path to save storage (external storage)
// This class needs to implement persistence (very difficult but recommended to save until end)
// Should also store the statistics (timing, word count, etc) -> (see instructions)
// Print function is implemented in the AVLTree (printTree())
class IndexHandler
{
private:
//int tf
//int idf
DSAvlTree<std::string, std::string> words;
Hash<std::string, std::string> people;
Hash<std::string, std::string> orgs;
std::vector<std::string> docs;
public:
std::map<std::string, int> getWords(std::string);
std::map<std::string, int> getPeople(std::string);
std::map<std::string, int> getOrgs(std::string);
// std::map<int, int> getWordCount(int);
void addWords(std::string, std::string);
void addPeople(std::string, std::string);
void addOrgs(std::string, std::string);
void addDocument(std::string);
// void addWordCount(int);
int getDocSize();
void createPersistence(std::string, std::string);
void readPersistence(std::string, std::string);
int returnNumArticles(std::string, std::string);
int returnSize(std::string);
};
#endif
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
DSAvlTree<std::string, int> words;
Hash<std::string, int> people;
Hash<std::string, int> orgs;
std::map<int, DSDocument> docs;
public:
std::vector<std::pair<DSDocument, int>> getWords(std::string);
std::vector<std::pair<DSDocument, int>> getPeople(std::string);
std::vector<std::pair<DSDocument, int>> getOrgs(std::string);
void addWords(std::string, int);
void addPeople(std::string, int);
void addOrgs(std::string, int);
void addDocument(int, DSDocument);
void createPersistence(std::string);
void readPersistence(std::string);
};
#endif
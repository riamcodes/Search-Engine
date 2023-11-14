#ifndef INDEX_HANDLER_H
#define INDEX_HANDLER_H

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
DSAvlTree<std::string, int> words;
Hash<std::string, int> people;
Hash<std::string, int> orgs;
std::vector<document> docs;
public:
vector<pair<document, int>> getWords(std::string);
vector<pair<document, int>> getPeople(std::string);
vector<pair<document, int>> getOrgs(std::string);
void addWords(std::string, int, int);
void addPeople(std::string, int, int);
void addOrgs(std::string, int, int);
void addDocument(document);
void createPersistence(std::string);
void readPersistence(std::string);
};
#endif
#ifndef DOCUMENT_PARSER_H
#define DOCUMENT_PARSER_H


#include <string>
#include <vector>
#include <map>

class DocumentParser
{
private:

//Might need to change this but currently declared as a nested map
//the first part is a string which represents the keyword we are looking for in a document or query - For example if we were trying to find the word apple and all related documents the string would be apple
//the second part is the nested map, but basically the key is an int. The int represents the ID of the document since there are many documents. For example if it was document 100 the key would be 100
// The vector of ints should represent the location of where the matching words are in the specific document. If the word apple is mentioned in the first 5th and 7th word it would store a vector of {1,5,7}
std::map<std::string, std::map<int, std::vector<int>>> index;
public:
void buildIndex(const std::string& document);
};
#endif
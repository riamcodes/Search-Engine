#include "DocumentParser.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>



void DocumentParser::buildIndex(const std::string& document) {
    std::ifstream file(document);
    if (!file.good()) {
        throw std::invalid_argument("File could not be opened: " + document);
    }
}
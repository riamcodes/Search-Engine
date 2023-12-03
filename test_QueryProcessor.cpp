#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream>
#include <cassert>
#include <iomanip>
#include "QueryProcessor.h"
#include "IndexHandler.h"
#include "DocumentParser.h"
#include "porter2_stemmer.h"

TEST_CASE("query processor", "[QueryProcessor.h]")
{
    QueryProcessor qp;
    IndexHandler ih;
    DocumentParser dp;

    dp.parseDocument("/users7/cse/gschultz/assignment-4-search-engine-exit-code-0/sample_data/coll_1/news_0064567.json");
    ih = dp.getIndex();
    ih.createPersistence();
    ih.readPersistence();
    ih = dp.getIndex();
    qp.setIndexHandler(ih);

    std::map<std::string, int> relevantDocs = qp.parsingAnswer("common PERSON:schweitzer");

    std::cout << "Is printVector empty 1 means yes 0 means no " << std::endl;
    std::cout << qp.printVector.empty();
}

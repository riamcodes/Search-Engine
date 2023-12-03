#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file/
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
    DocumentParser dp;
    IndexHandler ih;
    QueryProcessor qp;

    dp.parseDocument("../sample_data/coll_1/news_0064567.json");
    dp.parseDocument("../sample_data/coll_1/news_0064568.json");
    dp.parseDocument("../sample_data/coll_1/news_0064569.json");
    dp.parseDocument("../sample_data/coll_2/news_0064571.json");

    ih = dp.getIndex();
    ih.createPersistence();
    ih.readPersistence();
    ih = dp.getIndex();
    qp.setIndexHandler(ih);

    std::map<std::string, int> relevantDocs = qp.parsingAnswer("common PERSON:schweitzer");
    REQUIRE(relevantDocs.size() == 1);
    relevantDocs.clear();
    relevantDocs = qp.parsingAnswer("PERIOD PERSON:strax PERSON:ab");
    REQUIRE(relevantDocs.size() == 1);
    relevantDocs.clear();
    relevantDocs = qp.parsingAnswer("stocks ORGS:carrefour PERSON:jerome powell");
    REQUIRE(relevantDocs.size() == 1);
    relevantDocs.clear();
    relevantDocs = qp.parsingAnswer("ajnlknewojfn");
    REQUIRE(relevantDocs.size() == 0);
}
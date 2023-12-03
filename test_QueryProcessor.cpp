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
    IndexHandler indexObject;
    DocumentParser documentObject;
   // documentObject.setIndex(indexObject);
    //documentObject.();//
    QueryProcessor queryObject;
    queryObject.setIndexHandler(indexObject);
    std::map<std::string, int> results;
    results = queryObject.parsingAnswer("ago");
    REQUIRE(results.size() == 1);
    //REQUIRE(results[0] == "");
    results = queryObject.parsingAnswer("common ORG:reuters");
    REQUIRE(results.size() == 1);
    //REQUIRE(results[0] == "");
    results = queryObject.parsingAnswer("common PERSON:schweitzer");
    REQUIRE(results.size() == 1);
    //REQUIRE(results[0] == "");
    results = queryObject.parsingAnswer("compani - compar");
    REQUIRE(results.size() == 2);
    //REQUIRE(results[0] == "");
    //REQUIRE(results[0] == "");
    results = queryObject.parsingAnswer("hahalolol");
    REQUIRE(results.size() == 0);

}
    // std::cout << "hello";
//     // IndexHandler ih;
//     QueryProcessor qp;
//     DocumentParser dp;

//     dp.parseDocument("./sample_data");
//     // dp.parseDocument("../sample_data/coll_1/news_0064569.json");
//     // dp.parseDocument("../sample_data/coll_2/news_0064571.json");
//     IndexHandler ih = dp.getIndex();
//     qp.setIndexHandler(&ih);
//     std::cout << "made it to here" << std::endl;

// //     // addDocument() needs the filepath and the title
// //     ih->addDocument("../sample_data/coll_1/news_0064567.json", "German firms doing business in UK gloomy about Brexit - survey");
// //     ih->addDocument("../sample_data/coll_1/news_0064569.json", "European stocks open lower on Powell’s comments; Solvay, Carrefour to report");
// //     ih->addDocument("../sample_data/coll_2/news_0064571.json", "BRIEF-Kewaunee Scientific Q3 Earnings Per Share $0.31");

//     // std::cout << ih.getWordCount("German firms doing business in UK gloomy about Brexit - survey") << std::endl;
//     // std::cout << ih.getWordCount("European stocks open lower on Powell’s comments; Solvay, Carrefour to report") << std::endl;
//     // std::cout << ih.getWordCount("BRIEF-Kewaunee Scientific Q3 Earnings Per Share $0.31") << std::endl;

//   std::string query1 = "prospects PERSON:eric ORG:bdi";
//   qp.parsingAnswer(query1);
//   std::string query2 = "JANUARY PERSON:strax PERSON:ab";
//   qp.parsingAnswer(query2);
//   std::cout << "Contents of printVector:" << std::endl;
//             for (const auto& item : qp.printVector) {
//                 std::cout << item << std::endl;
//             }
//   //std::string query = "businesses hi hello";
//   // Porter2Stemmer::stem(query1);
//   // std::cout << query1 << std::endl;
//   // qp.parsingAnswer(query1);


//     // std::string query = "";
//     // std::vector<std::string> result = qp->parsingAnswer(query);

//     // for (const auto &document : result)
//     // {
//     //     std::cout << document << std::endl;
//     // }
//     return 0;
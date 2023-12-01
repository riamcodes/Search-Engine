#include "test_QueryProcessor.h"



// void test_QueryProcessor::test()
// {
//     IndexHandler* ih;
//     QueryProcessor* qp;
//     qp->setIndexHandler(&ih);

//     // addDocument() needs the filepath and the title
//     ih->addDocument("../sample_data/coll_1/news_0064567.json", "German firms doing business in UK gloomy about Brexit - survey");
//     ih->addDocument("../sample_data/coll_1/news_0064569.json", "European stocks open lower on Powell’s comments; Solvay, Carrefour to report");
//     ih->addDocument("../sample_data/coll_2/news_0064571.json", "BRIEF-Kewaunee Scientific Q3 Earnings Per Share $0.31");

//     std::string query = "";
//     std::vector<std::string> result = qp->parsingAnswer(query);

//     for (const auto &document : result)
//     {
//         std::cout << document << std::endl;
//     }
// }
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "QueryProcessor.h"

TEST_CASE("contains", "[DSAvlTree]")
{
    IndexHandler ih;
    QueryProcessor qp;
    qp.setIndexHandler(&ih);

    ih.addDocument();
    ih.addDocument();
    ih.addDocument();

    std::string query = "";
    std::vector<std::string> result = qp.parsingAnswer(query);

    for(const auto& document : result){
        std::cout << document << std::endl;
    }

}
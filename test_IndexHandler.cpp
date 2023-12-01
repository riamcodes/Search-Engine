#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "IndexHandler.h"
#include "DocumentParser.h"
using namespace std;

TEST_CASE("IndexHandler Test", "[IndexHandler]")
{
    // Create an instance of IndexHandler
    DocumentParser dp;

    // Add test data
    dp.parseDocument("../sample_data/coll_1/news_0064567.json");
    IndexHandler ih = dp.getIndex();

    SECTION("getWords Test")
    {
        map<string, int> result = ih.getWords("plan");
        REQUIRE(result.size() == 1);
        REQUIRE(result["../sample_data/coll_1/news_0064567.json"] == 3);

        map<string, int> result1 = ih.getWords("Brexit");
        REQUIRE(result1.size() == 1);
        REQUIRE(result1["../sample_data/coll_1/news_0064567.json"] == 6);

        map<string, int> result2 = ih.getWords("interests");
        REQUIRE(result2.size() == 1);
        REQUIRE(result2["../sample_data/coll_1/news_0064567.json"] == 1);

        map<string, int> result3 = ih.getWords("prospect");
        REQUIRE(result3.size() == 1);
        REQUIRE(result3["../sample_data/coll_1/news_0064567.json"] == 1);

        map<string, int> result4 = ih.getWords("prospects");
        REQUIRE(result4.size() == 1);
        REQUIRE(result4["../sample_data/coll_1/news_0064567.json"] == 2);

        map<string, int> result5 = ih.getWords("potato");
        REQUIRE(result5.size() == 0);

        map<string, int> result6 = ih.getWords("orange");
        REQUIRE(result6.size() == 0);
    }

    SECTION("getPeople Test")
    {
        map<string, int> result = ih.getPeople("eric schweitzer"); ////////////make parser able to connect two names
        REQUIRE(result.size() == 1);
        map<string, int> result2 = ih.getPeople("carolyn julie fairbairn");
        REQUIRE(result2.size() == 1);
        map<string, int> result3 = ih.getPeople("joachim lang");
        REQUIRE(result2.size() == 1);
        map<string, int> result4 = ih.getPeople("schweitzer");
        REQUIRE(result4.size() == 1);
        map<string, int> result5 = ih.getPeople("adam");
        REQUIRE(result5.size() == 0);
        map<string, int> result6 = ih.getPeople("george");
        REQUIRE(result6.size() == 0);
        map<string, int> result7 = ih.getPeople("sarah");
        REQUIRE(result7.size() == 0);
    }

    SECTION("getWordCount Test")
    {
        REQUIRE(ih.getWordCount("German firms doing business in UK gloomy about Brexit - survey") == 251);
    }

    SECTION("getOrgs Test")
    {
        map<string, int> result = ih.getOrgs("cnn");
        REQUIRE(result.size() == 0);
        map<string, int> result1 = ih.getOrgs("nbc");
        REQUIRE(result.size() == 0);
        map<string, int> result2 = ih.getOrgs("abc");
        REQUIRE(result.size() == 0);
        map<string, int> result3 = ih.getOrgs("Reuters");
        REQUIRE(result.size() == 0);
    }

    // Add more test cases based on your specific methods and requirements
}
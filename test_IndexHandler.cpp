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
        REQUIRE(result["../sample_data/coll_1/news_0064567.json"] == 2); // should be 2

        map<string, int> result1 = ih.getWords("german");
        REQUIRE(result1.size() == 1);
        REQUIRE(result1["../sample_data/coll_1/news_0064567.json"] == 4);

        map<string, int> result2 = ih.getWords("interest");
        REQUIRE(result2.size() == 1);
        REQUIRE(result2["../sample_data/coll_1/news_0064567.json"] == 1);

        map<string, int> result3 = ih.getWords("prospect");
        REQUIRE(result3.size() == 1);
        REQUIRE(result3["../sample_data/coll_1/news_0064567.json"] == 3);

        map<string, int> result5 = ih.getWords("potato");
        REQUIRE(result5.size() == 0);

        map<string, int> result6 = ih.getWords("orange");
        REQUIRE(result6.size() == 0);
    }

    SECTION("getPeople Test")
    {
        // map<string, int> result = ih.getPeople("eric schweitzer"); ////////////make parser able to connect two names
        // REQUIRE(result.size() == 1);
        // map<string, int> result2 = ih.getPeople("carolyn julie fairbairn");
        // REQUIRE(result2.size() == 1);
        // map<string, int> result3 = ih.getPeople("joachim lang");
        // REQUIRE(result2.size() == 1);
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
        REQUIRE(result1.size() == 0);
        map<string, int> result2 = ih.getOrgs("abc");
        REQUIRE(result2.size() == 0);
        map<string, int> result3 = ih.getOrgs("Reuters");
        REQUIRE(result3.size() == 0);
    }

    SECTION("Persistance tests")
    {
        ih.createPersistence();

        IndexHandler index;

        index.readPersistence();

        map<string, int> result = index.getWords("plan");
        REQUIRE(result.size() == 1);
        REQUIRE(result["../sample_data/coll_1/news_0064567.json"] == 2); // should be 2
        map<string, int> result1 = index.getWords("german");
        REQUIRE(result1.size() == 1);
        REQUIRE(result1["../sample_data/coll_1/news_0064567.json"] == 4);
        map<string, int> result2 = index.getWords("interest");
        REQUIRE(result2.size() == 1);
        REQUIRE(result2["../sample_data/coll_1/news_0064567.json"] == 1);
        map<string, int> result3 = index.getWords("prospect");
        REQUIRE(result3.size() == 1);
        REQUIRE(result3["../sample_data/coll_1/news_0064567.json"] == 3);
        map<string, int> result5 = index.getWords("potato");
        REQUIRE(result5.size() == 0);
        map<string, int> result6 = index.getWords("orange");
        REQUIRE(result6.size() == 0);

        // map<string, int> result7 = index.getPeople("eric schweitzer"); ////////////make parser able to connect two names
        // REQUIRE(result7.size() == 1);
        // map<string, int> result8 = index.getPeople("carolyn julie fairbairn");
        // REQUIRE(result8.size() == 1);
        // map<string, int> result9 = index.getPeople("joachim lang");
        // REQUIRE(result9.size() == 1);
        map<string, int> result10 = index.getPeople("schweitzer");
        REQUIRE(result10.size() == 1);
        map<string, int> result11 = index.getPeople("adam");
        REQUIRE(result11.size() == 0);
        map<string, int> result12 = index.getPeople("george");
        REQUIRE(result12.size() == 0);
        map<string, int> result13 = index.getPeople("sarah");
        REQUIRE(result13.size() == 0);

        REQUIRE(index.getWordCount("German firms doing business in UK gloomy about Brexit - survey") == 251);

        map<string, int> result14 = index.getOrgs("cnn");
        REQUIRE(result14.size() == 0);
        map<string, int> result15 = index.getOrgs("nbc");
        REQUIRE(result15.size() == 0);
        map<string, int> result16 = index.getOrgs("abc");
        REQUIRE(result16.size() == 0);
        map<string, int> result17 = index.getOrgs("Reuters");
        REQUIRE(result17.size() == 0);

        REQUIRE(index.getDocSize() == 1);
        REQUIRE(index.getFilePath("German firms doing business in UK gloomy about Brexit - survey") == "../sample_data/coll_1/news_0064567.json");
    }

    SECTION("Multiple Doc Testing")
    {
        dp.parseDocument("../sample_data/coll_1/news_0064568.json");
        IndexHandler ih = dp.getIndex();

        map<string, int> result1 = ih.getWords("german");
        REQUIRE(result1.size() == 1);
        REQUIRE(result1["../sample_data/coll_1/news_0064567.json"] == 4);

        map<string, int> result2 = ih.getWords("group");
        REQUIRE(result2.size() == 2);
        REQUIRE(result2["../sample_data/coll_1/news_0064567.json"] == 1);
        REQUIRE(result2["../sample_data/coll_1/news_0064568.json"] == 2);

        ih.createPersistence();

        IndexHandler index2;

        index2.readPersistence();

        map<string, int> result = ih.getWords("german");
        REQUIRE(result.size() == 1);
        REQUIRE(result["../sample_data/coll_1/news_0064567.json"] == 4);

        map<string, int> result3 = ih.getWords("group");
        REQUIRE(result3.size() == 2);
        REQUIRE(result3["../sample_data/coll_1/news_0064567.json"] == 1);
        REQUIRE(result3["../sample_data/coll_1/news_0064568.json"] == 2);
    }

    // Add more test cases based on your specific methods and requirements//
}
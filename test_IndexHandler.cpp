#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "IndexHandler.h"
#include "DocumentParser.h"

TEST_CASE("IndexHandler Test", "[IndexHandler]") {
    // Create an instance of IndexHandler
    IndexHandler ih;
    DocumentParser dp;

    // Add test data
    ih.addDocument("filepath1", "Document1");
    ih.addWords("Word1", "filepath1");
    ih.addPeople("John", "filepath1");

    SECTION("getWords Test") {
        std::map<std::string, int> result = ih.getWords("Word1");
        REQUIRE(result.size() == 1);
        REQUIRE(result["filepath1"] == 0); // Adjust the expected value based on your actual implementation
    }

    SECTION("getPeople Test") {
        std::map<std::string, int> result = ih.getPeople("John");
        REQUIRE(result.size() == 1);
        REQUIRE(result["filepath1"] == 0); // Adjust the expected value based on your actual implementation
    }

    SECTION("getWordCount Test") {
        ih.addWordCount("Document1", 50);
        int result = ih.getWordCount("Document1");
        REQUIRE(result == 50);
    }

    // Add more test cases based on your specific methods and requirements
}
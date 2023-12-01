#ifndef TEST_QUERYPROCESSOR_H
#define TEST_QUERYPROCESSOR_H
#include <iostream>
#include <cassert>
#include "QueryProcessor.h"
#include "IndexHandler.h"
#include "DocumentParser.h"

class test_QueryProcessor{
void testParsingAnswer() {
    QueryProcessor queryProcessor;
    //MockIndexHandler mockIndexHandler;
    DocumentParser dp;
    IndexHandler mockIndexHandler = dp.getIndex();

    dp.parseDocument("/users7/cse/gschultz/assignment-4-search-engine-exit-code-0/sample_data/coll_1/news_0064567.json");
    dp.parseDocument("/users7/cse/gschultz/assignment-4-search-engine-exit-code-0/sample_data/coll_1/news_0064568.json");
    dp.parseDocument("/users7/cse/gschultz/assignment-4-search-engine-exit-code-0/sample_data/coll_1/news_0064569.json");
    queryProcessor.setIndexHandler(&mockIndexHandler);

    std::string answer = "ORG:Organization PERSON:Person -ExcludeWord Word1 Word2";
    std::vector<std::string> parsedAnswer = queryProcessor.parsingAnswer(answer);

    // Add appropriate checks based on the expected parsing result
    assert(parsedAnswer.size() == 7);
    assert(parsedAnswer[0] == "Organization");
    // Add more checks as needed
}

void testDissectAnswer() {
    // Implement test cases for dissectAnswer function
    // ...


    // Add appropriate checks based on the expected result
    // assert(...);
}

void testIntersection() {
    // Implement test cases for the intersection function
    // ...

    // Add appropriate checks based on the expected result
    // assert(...);
}

void testComplement() {
    // Implement test cases for the complement function
    // ...

    // Add appropriate checks based on the expected result
    // assert(...);
}

void testRelevancy() {
    // Implement test cases for the Relevancy function
    // ...

    // Add appropriate checks based on the expected result
    // assert(...);
}
};
#endif



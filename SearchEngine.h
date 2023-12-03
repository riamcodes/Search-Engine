#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H
#include "IndexHandler.h"
#include "DocumentParser.h"
#include "UserInterface.h"
#include "QueryProcessor.h"


class SearchEngine{
    private:
    IndexHandler ih;
    DocumentParser dp;
    UserInterface ui;
    QueryProcessor qp;
    public:
    void input(int, char**);
};
#endif
////
#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H
#include "IndexHandler.h"
#include "DocumentParser.h"
#include "UserInterface.h"
#include "QueryProcessor.h"

class SearchEngine{
    private:
    IndexHandler *ih = new IndexHandler();
    DocumentParser *dp = new DocumentParser();
    UserInterface *ui = new UserInterface();
    QueryProcessor *qp = new QueryProcessor();
    public:
    void input(char**);
};
#endif
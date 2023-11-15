#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>

class document
{
    private:
    public:
    std::string uuid;
    std::string title;
    std::string publication;
    int date;
    int totalWordCount;
    std::string rawText;
    double relevancy;
    document(std::string u, std::string t, std::string p, int d, int w, std::string r, double re);
};
#endif

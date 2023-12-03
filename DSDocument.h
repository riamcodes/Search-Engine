#ifndef DSDOCUMENT_H
#define DSDOCUMENT_H
#include <iostream>

class DSDocument
{
    private:
    public:
    // Both
    int totalWordCount;
    double relevancy;
    // Internal
    std::string uuid;
    std::string title;
    std::string publication;
    int date;
    std::string rawText;
    DSDocument(std::string u, std::string t, std::string p, int d, int w, std::string r, double re);
    // External
    std::string path;
    DSDocument(std::string, int);
};
#endif
////
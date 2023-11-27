#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>

class document
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
    document(std::string u, std::string t, std::string p, int d, int w, std::string r, double re);
    // External
    std::string path;
    document(std::string, int);
};
#endif

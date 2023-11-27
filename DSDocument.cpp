#include "DSDocument.h"

DSDocument::DSDocument(std::string u, std::string t, std::string p, int d, int w, std::string r, double re)
{
    uuid = u;
    title = t;
    publication = p;
    date = d;
    totalWordCount = w;
    rawText = r;
    relevancy = 0;
}
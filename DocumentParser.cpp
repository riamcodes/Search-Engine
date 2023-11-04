#include "DocumentParser.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>

using namespace rapidjson;
using namespace std;

void DocumentParser::parseDocument(const string& jsonContent) {
    ifstream ifs(jsonContent);
    if (!ifs.is_open()) {
        cerr << "Could not open file for reading: " << jsonContent << endl;
        return;
    }

    IStreamWrapper isw(ifs);
    Document d;
    d.ParseStream(isw);

    if (d.HasParseError()) {
        cerr << "JSON parse error: " << d.GetParseError() << endl;
        return;
    }

   d.ParseStream(isw);

    // Now that the document is parsed, we can access different elements the JSON using
    // familiar subscript notation.

    // This accesses the -title- element in the JSON. Since the value
    //  associated with title is a string (rather than
    //  an array or something else), we call the GetString()
    //  function to return the actual title of the article
    //  as a c-string.
    auto val = d["title"].GetString();
    cout << "Title: " << val << "\n";

    // The Persons entity for which you're building a specific
    //  inverted index is contained in top level -entities- element.
    //  So that's why we subscript with ["entities"]["persons"].
    //  The value associated with entities>persons is an array.
    //  So we call GetArray() to get an iterable collection of elements
    auto persons = d["entities"]["persons"].GetArray();

    // We iterate over the Array returned from the line above.
    //  Each element kind of operates like a little JSON document
    //  object in that you can use the same subscript notation
    //  to access particular values.
    cout << "  Person Entities + sentiment:"
         << "\n";
    for (auto &p : persons)
    {
        cout << "    > " << setw(30) << left << p["name"].GetString()
             << setw(10) << left << p["sentiment"].GetString() << "\n";
    }

    cout << endl;
}


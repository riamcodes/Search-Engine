#include <iostream>

using namespace std;
#include "IndexHandler.h"
#include "QueryProcessor.h"
#include "UserInterface.h"
#include "DocumentParser.h"
#include "DSAvlTree.h"
#include "SearchEngine.h"

int main(int argc, char **argv)
{
    SearchEngine se;
    se.input(argv);
}
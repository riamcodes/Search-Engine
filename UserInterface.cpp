#include "UserInterface.h"

UserInterface::UserInterface() // default constructor
{
    numberOfArticles = 0;
    totalNodes = 0;
    indexObject = nullptr;
}

UserInterface::~UserInterface() // destructor
{
    delete[] indexObject;
}

UserInterface::UserInterface(const UserInterface &rhs) // copy constructor
{
    numberOfArticles = 0;
    totalNodes = 0;
    indexObject = nullptr;
    numberOfArticles = rhs.numberOfArticles;
    totalNodes = rhs.totalNodes;
    indexObject = rhs.indexObject;
}

UserInterface &UserInterface::operator=(const UserInterface &rhs) // assignment operator
{
    if (this != &rhs)
    {
        delete indexObject;
        indexObject = rhs.indexObject;
    }
    return *this;
}

void UserInterface::initialQuestion()
{
    while (!(answer == "1" || answer == "2" || answer == "3"))
    {
        std::cout << "Hello! Welcome to our search engine" << std::endl;
        std::cout << "Please enter a number 1-3 of the choices below to continue" << std::endl;
        std::cout << std::endl;
        std::cout << "1) Create an index from a directory with documents" << std::endl;
        std::cout << "2) Write and read the index to a file (make it persistant)" << std::endl;
        std::cout << "3) Enter a query" << std::endl;
        std::getline(std::cin, answer);
        if (!(answer == "1" || answer == "2" || answer == "3"))
        {
            std::cout << "Error! This is an invalid answer. Please select numbers 1 through 3." << std::endl;
        }
    }
}
void UserInterface::secondQuestion()
{
    QueryProcessor queryObject;
    if (answer == "1")
    {
        std::cout << "Please enter an index to create." << std::endl;
        std::getline(std::cin, answer1);
        // send to index handler
    }
    else if (answer == "2")
    {
        std::cout << "Write and read from the index." << std::endl;
        std::getline(std::cin, answer2);
        // send to index handler
    }
    else if (answer == "3")
    {
        std::cout << "Please enter a query" << std::endl;
        std::getline(std::cin, answer3);
        // send to query processor
        queryObject.parsingAnswer(answer3);
    }
}
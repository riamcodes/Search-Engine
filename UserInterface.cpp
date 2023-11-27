#include "UserInterface.h"

UserInterface::UserInterface() // default constructor
{
    numberOfArticles = 0;
    totalNodes = 0;
}

UserInterface::~UserInterface() // destructor
{
}

UserInterface::UserInterface(const UserInterface &rhs) // copy constructor
{
    numberOfArticles = 0;
    totalNodes = 0;
    numberOfArticles = rhs.numberOfArticles;
    totalNodes = rhs.totalNodes;
}

UserInterface &UserInterface::operator=(const UserInterface &rhs) // assignment operator
{
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
    IndexHandler indexObject;
    if (answer == "1")
    {
        std::cout << "Would you like to create a person, organization, or word index?" << std::endl;
        std::getline(std::cin, answer1);
        if (answer1 == "person")
        {
            std::cout << "Please enter the person and id that you would like to add." << std::endl;
            std::string answerPerson;
            int answerId;
            std::cin >> answerPerson;
            std::cin >> answerId;
            auto startTrain = std::chrono::high_resolution_clock::now();
            indexObject.addPeople(answerPerson, answerId);
            auto finishTrain = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsedTrain = finishTrain - startTrain;
        }
        else if (answer1 == "organization")
        {
            std::cout << "Please enter the organization and id that you would like to add." << std::endl;
            std::string answerOrganization;
            int answerId;
            std::cin >> answerOrganization;
            std::cin >> answerId;
            auto startTrain = std::chrono::high_resolution_clock::now();
            indexObject.addOrganization(answerOrganization, answerId);
            auto finishTrain = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsedTrain = finishTrain - startTrain;
        }
        else if (answer1 == "word")
        {
            std::cout << "Please enter the word and id that you would like to add." << std::endl;
            std::string answerWord;
            int answerId;
            std::cin >> answerWord;
            std::cin >> answerId;
            auto startTrain = std::chrono::high_resolution_clock::now();
            indexObject.addWord(answerWord, answerId);
            auto finishTrain = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsedTrain = finishTrain - startTrain;
        }
    }
    else if (answer == "2")
    {
        std::cout << "Would you like to write or read from the index?" << std::endl;
        std::getline(std::cin, answer2);
        if (answer2 == "write")
        {
            auto startTrain = std::chrono::high_resolution_clock::now();
            indexObject.createPersistence();
            auto finishTrain = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsedTrain = finishTrain - startTrain;
        }
        else if (answer2 == "read")
        {
            auto startTrain = std::chrono::high_resolution_clock::now();
            indexObject.readPersistence();
            auto finishTrain = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsedTrain = finishTrain - startTrain;
        }
    }
    else if (answer == "3")
    {
        std::cout << "Please enter a query" << std::endl;
        std::getline(std::cin, answer3);
        auto startTrain = std::chrono::high_resolution_clock::now();
        queryObject.parsingAnswer(answer3);
        std::string yesOrNo;
        std::string fileName;
        std::cout << "Would you like to see the contents of a file?" << std::endl;
        std::cin >> yesOrNo;
        for (int i = 0; i < yesOrNo.length(); i++)
        {
            tolower(yesOrNo.at(i));
        }
        if (yesOrNo == "yes")
        {
            std::cout << "Please enter in the title of the file that you would like to see." << std::endl;
            std::cin >> fileName;
            // print out the contents of the file
        }
        auto finishTrain = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedTrain = finishTrain - startTrain;
    }
    std::cout << "Thank you for using our search engine." << std::endl;
    std::cout << "Here are some of our runtime statistics:" << std::endl;
    std::cout << "Runtime: " << elapsedTrain.count() << " seconds." << std::endl;
    // std::cout << "Total number of individual articles in the current index: " << # << std::endl;
    // std::cout << "Total number of unique words indexed: " << (number of nodes in AVLTree) << std::endl;
}
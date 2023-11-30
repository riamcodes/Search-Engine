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
    ih = new IndexHandler();
    qp = new QueryProcessor();
    dp = new DocumentParser();
    while (true)
    {
        std::cout << "Hello! Welcome to our search engine" << std::endl;
        std::cout << "Please enter a number 1-5 of the options below to continue" << std::endl;
        std::cout << "-----------------------------------------------------------" << std::endl;
        std::cout << "1) Create an index from a directory with documents" << std::endl;
        std::cout << "2) Write an index to the file" << std::endl;
        std::cout << "3) Read an index from the file" << std::endl;
        std::cout << "4) Enter a query" << std::endl;
        std::cout << "5) Quit" << std::endl;
        std::getline(std::cin, answer);
        if (!(answer == "1" || answer == "2" || answer == "3" || answer == "4" || answer == "5"))
        {
            std::cout << "Error! This is an invalid answer. Please select numbers 1 through 5." << std::endl;
            std::cin >> answer;
        }
        if (answer == "1")
        {
            std::cout << "Would you like to create a person, organization, or word index?" << std::endl;
            std::getline(std::cin, answer1);
            if (answer1 == "person")
            {
                std::cout << "Please enter the person and id that you would like to add." << std::endl;
                std::string answerPerson;
                std::string answerId;
                std::cin >> answerPerson;
                std::cin >> answerId;
                auto startTrain = std::chrono::high_resolution_clock::now();
                ih->addPeople(answerPerson, answerId);
                auto finishTrain = std::chrono::high_resolution_clock::now();
                elapsedTrain = finishTrain - startTrain;
            }
            else if (answer1 == "organization")
            {
                std::cout << "Please enter the organization and id that you would like to add." << std::endl;
                std::string answerOrganization;
                std::string answerId;
                std::cin >> answerOrganization;
                std::cin >> answerId;
                auto startTrain = std::chrono::high_resolution_clock::now();
                ih->addOrgs(answerOrganization, answerId);
                auto finishTrain = std::chrono::high_resolution_clock::now();
                elapsedTrain = finishTrain - startTrain;
            }
            else if (answer1 == "word")
            {
                std::cout << "Please enter the word and id that you would like to add." << std::endl;
                std::string answerWord;
                std::string answerId;
                std::cin >> answerWord;
                std::cin >> answerId;
                auto startTrain = std::chrono::high_resolution_clock::now();
                ih->addWords(answerWord, answerId);
                auto finishTrain = std::chrono::high_resolution_clock::now();
                elapsedTrain = finishTrain - startTrain;
            }
        }
        else if (answer == "2")
        {
            std::cout << "Would you like to create a word, person, or organization?" << std::endl;
            std::string answerCreate;
            std::cin >> answerCreate;
            auto startTrain = std::chrono::high_resolution_clock::now();
        //    ih->createPersistence(answerCreate);
            auto finishTrain = std::chrono::high_resolution_clock::now();
            elapsedTrain = finishTrain - startTrain;
        }
        else if (answer == "3")
        {
            std::cout << "Would you like to read a word, person, or organization?" << std::endl;
            std::string answerRead;
            std::cin >> answerRead;
            auto startTrain = std::chrono::high_resolution_clock::now();
            // ih->readPersistence(answerRead);
            auto finishTrain = std::chrono::high_resolution_clock::now();
            elapsedTrain = finishTrain - startTrain;
        }
        else if (answer == "4")
        {
            std::cout << "Please enter a query" << std::endl;
            std::getline(std::cin, answer3);
            auto startTrain = std::chrono::high_resolution_clock::now();
            qp->parsingAnswer(answer3);
            std::string yesOrNo;
            std::string fileName;
            std::cout << "Would you like to see the contents of a file?" << std::endl;
            std::cin >> yesOrNo;
            //have the user enter in the title that they would like to print
            // find the matching uuid and send to the function
            for (int i = 0; i < yesOrNo.length(); i++)
            {
                tolower(yesOrNo.at(i));
            }
            if (yesOrNo == "yes")
            {
            //   dp->parseDocument();
            }
            auto finishTrain = std::chrono::high_resolution_clock::now();
            elapsedTrain = finishTrain - startTrain;
        }
        else if (answer == "5")
        {
            std::cout << "Thank you for using our search engine." << std::endl;
            std::cout << "Here are some of our runtime statistics:" << std::endl;
            std::cout << "Runtime: " << elapsedTrain.count() << " seconds." << std::endl;
            // std::cout << "Total number of individual articles in the current index: " << # << std::endl;
            // std::cout << "Total number of unique words indexed: " << (number of nodes in AVLTree) << std::endl;
            false;
        }
    }
}
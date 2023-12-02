#include "UserInterface.h"

void UserInterface::initialQuestion()
{
    // do we actually need these?
    // ih = new IndexHandler();
    // qp = new QueryProcessor();
    // dp = new DocumentParser();
    while (true)
    {
        std::cout << "Hello! Welcome to our search engine" << std::endl;
        std::cout << "Please enter a number 1-6 of the options below to continue" << std::endl;
        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "1) Create an index from a directory with documents" << std::endl;
        std::cout << "2) Write an index to the file" << std::endl;
        std::cout << "3) Read an index from the file" << std::endl;
        std::cout << "4) Enter a query" << std::endl;
        std::cout << "5) See statistics" << std::endl;
        std::cout << "6) Quit" << std::endl;
        std::string answer;
        std::getline(std::cin, answer);

        if (!(answer == "1" || answer == "2" || answer == "3" || answer == "4" || answer == "5" || answer == "6"))
        {
            std::cout << "Error! This is an invalid answer. Please select numbers 1 through 6." << std::endl;
            std::cin >> answer;
        }
        else if (answer == "1") // Populates with documents
        {
            std::cout << "Please enter a directory filepath" << std::endl;
            std::string answer2;
            std::getline(std::cin, answer2);
            auto startTrain = std::chrono::high_resolution_clock::now();
            dp->traverseSubdirectory(answer2);
            auto finishTrain = std::chrono::high_resolution_clock::now();
            elapsedTrain = finishTrain - startTrain;
        }
        else if (answer == "2") // Create Persistence
        {
            auto startTrain = std::chrono::high_resolution_clock::now();
            //  ih = dp.getIndex();
            ih->createPersistence();
            auto finishTrain = std::chrono::high_resolution_clock::now();
            elapsedTrain = finishTrain - startTrain;
        }
        else if (answer == "3") // Read Persistence
        {
            auto startTrain = std::chrono::high_resolution_clock::now();
            ih->readPersistence();
            auto finishTrain = std::chrono::high_resolution_clock::now();
            elapsedTrain = finishTrain - startTrain;
        }
        else if (answer == "4") // Enter a query
        {
            std::cout << "Please enter a query" << std::endl;
            std::string answer3;
            std::getline(std::cin, answer3);
            auto startTrain = std::chrono::high_resolution_clock::now();
            std::vector<std::string> final = qp->parsingAnswer(answer3);
            std::string yesOrNo;
            std::string fileName;
            std::cout << "Would you like to see the contents of a file?" << std::endl;
            std::cin >> yesOrNo;
            for (size_t i = 0; i < yesOrNo.length(); i++)
            {
                tolower(yesOrNo.at(i));
            }
            if (yesOrNo == "yes")
            {
                std::cout << "Please enter in the title of the document that you would like to see." << std::endl;
                std::string titleDocument;
                std::getline(std::cin, titleDocument);
                dp->parseDocument(ih->getFilePath(titleDocument));
            }
            auto finishTrain = std::chrono::high_resolution_clock::now();
            elapsedTrain = finishTrain - startTrain;
        }
        else if (answer == "5") // Statistics
        {
            std::cout << "Here are some of our runtime statistics:" << std::endl;
            std::cout << "Runtime: " << elapsedTrain.count() << " seconds." << std::endl;
            // std::cout << "Total number of individual articles in the current index: " << # << std::endl;
            std::cout << "Total articles: " << ih->getDocSize();
            // std::cout << "Total number of unique words indexed: " << (number of nodes in AVLTree) << std::endl;

        }
        else if (answer == "6")
        {
            std::cout << "Thank you for using our search engine." << std::endl;
            break;
        }
    }
}

// UserInterface::UserInterface() // default constructor
// {
//     numberOfArticles = 0;
//     totalNodes = 0;
// }

// UserInterface::~UserInterface() // destructor
// {
//     delete ih;
//     delete qp;
//     delete dp;
// }

// UserInterface::UserInterface(const UserInterface &rhs) // copy constructor
// {
//     numberOfArticles = 0;
//     totalNodes = 0;
//     numberOfArticles = rhs.numberOfArticles;
//     totalNodes = rhs.totalNodes;
// }

// UserInterface &UserInterface::operator=(const UserInterface &rhs) // assignment operator
// {
// }

#include "UserInterface.h"

void UserInterface::initialQuestion()
{
    std::cout << "Hello! Welcome to our search engine" << std::endl;
    while (true)
    {
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
            std::getline(std::cin, answer);
             
        }
        else if (answer == "1")
        {
            std::cout << "Please enter a directory filepath" << std::endl;
            std::string answer2;
            std::getline(std::cin, answer2);
             
            auto startTrain = std::chrono::high_resolution_clock::now();
            std::cout << "Reading files..." << std::endl;
            dp.traverseSubdirectory(answer2);
            ih = dp.getIndex();
            std::cout << "Done!" << std::endl;
            auto finishTrain = std::chrono::high_resolution_clock::now();
            elapsedTrain = finishTrain - startTrain;
        }
        else if (answer == "2")
        {
            std::cout << "Generating persistence, this may take a moment..." << std::endl;
            auto startTrain = std::chrono::high_resolution_clock::now();
            ih = dp.getIndex();
            ih.createPersistence();
            std::cout << "Persistence was created!" << std::endl;
            auto finishTrain = std::chrono::high_resolution_clock::now();
            elapsedTrain = finishTrain - startTrain;
        }
        else if (answer == "3")
        {
            std::cout << "Reading persistence..." << std::endl;
            auto startTrain = std::chrono::high_resolution_clock::now();
            ih.readPersistence();
            dp.setIndex(ih);
            std::cout << "Persistence has been read!" << std::endl;
            auto finishTrain = std::chrono::high_resolution_clock::now();
            elapsedTrain = finishTrain - startTrain;
        }
        else if (answer == "4")
        {
            qp.setIndexHandler(ih);
            std::cout << "Please enter a query" << std::endl;
            std::string answer3;
            std::getline(std::cin, answer3);
             

            auto startTrain = std::chrono::high_resolution_clock::now();
            std::map<std::string, int> relevantDocs = qp.parsingAnswer(answer3);
            if (qp.printVector.size() > 1)
            {
                int count = 1;
                std::cout << "Here are the most relevant documents" << std::endl;
                for (const auto &item : qp.printVector)
                {
                    std::cout << count << ". ";
                    dp.printInfo(item);
                    std::cout << std::endl;
                    ++count;
                }
                std::string yesOrNo;
                std::cout << "Would you like to see the contents of a file listed above?" << std::endl;
                std::getline(std::cin, yesOrNo);
                 
                for (size_t i = 0; i < yesOrNo.length(); i++)
                {
                    tolower(yesOrNo.at(i));
                }
                if (yesOrNo == "yes")
                {
                    std::cout << "Please enter in the number of the corresponding document that you would like to see." << std::endl;
                    std::string number;
                    std::getline(std::cin, number);
                     
                    int num = stoi(number);
                    dp.printDocument(qp.printVector[num - 1]);
                }
                qp.printVector.clear();
                auto finishTrain = std::chrono::high_resolution_clock::now();
                elapsedTrain = finishTrain - startTrain;
            }
        }
        else if (answer == "5")
        {
            std::cout << "Here are some of our runtime statistics:" << std::endl;
            std::cout << "Runtime: " << elapsedTrain.count() << " seconds." << std::endl;
            // std::cout << "Total number of individual articles in the current index: " << ih.returnNumArticles() << std::endl;/
            std::cout << "Total articles: " << ih.getDocSize() << std::endl;
            std::cout << "Total number of unique words indexed: " << ih.returnSize() << std::endl;
        }
        else if (answer == "6")
        {
            std::cout << "Thank you for using our search engine." << std::endl;
            break;
        }
         
    }
}
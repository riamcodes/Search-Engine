#include "UserInterface.h"

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
        getline(answer);
        if (!(answer == "1" || answer == "2" || answer == "3"))
        {
            std::cout << "Error! This is an invalid answer. Please select numbers 1 through 3." << std::endl;
        }
    }
}
void UserInterface::secondQuestion() {
    if (answer == "1")
    {
        std::cout << "Please enter an index to create." << std::endl;
        getline(answer1);
    }
    else if (answer == "2")
    {
        std::cout << "Something that makes sense for this." << std::endl;
        getline(answer2);
    }
    else if (answer == "3")
    {
        std::cout << "Please enter a query" << std::endl;
        getline(answer3);
        parsingAnswer(answer3);
    }
}

// void UserInterface::directAnswer()
// {
//     if (answer1 == "1")
//     {
//         std::chrono::time_point<std::chrono::system_clock> start, end;
//         start = std::chrono::system_clock::now();
//         // send to create an index
//         end = std::chrono::system_clock::now();
//         std::chrono::duration<double> elapsed_seconds = end - start;
//         std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;
//     }
//     else if (answer1 == "2")
//     {
//         std::chrono::time_point<std::chrono::system_clock> start, end;
//         start = std::chrono::system_clock::now();
//         // send to persistantance
//         end = std::chrono::system_clock::now();
//         std::chrono::duration<double> elapsed_seconds = end - start;
//         std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;
//     }
//     else if (answer1 == "3")
//     {
//         std::chrono::time_point<std::chrono::system_clock> start, end;
//         start = std::chrono::system_clock::now();
//         // send to enter a query
//         end = std::chrono::system_clock::now();
//         std::chrono::duration<double> elapsed_seconds = end - start;
//         std::cout << "Elapsed Time: " << elapsed_seconds.count() << std::endl;
//     }
//     else
//     {
//         throw std::runtime_error("Invalid Answer received!");
//     }
// }